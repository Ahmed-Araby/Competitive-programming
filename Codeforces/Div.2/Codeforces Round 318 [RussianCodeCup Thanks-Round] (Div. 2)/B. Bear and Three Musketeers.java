// https://codeforces.com/problemset/problem/574/B
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static final int BIG_ENOUGH_NUM = 1_000_000;

    private static boolean areConnected(List<Integer>[] graph, int wA, int wB) {
        for(int i=0; i<graph[wA].size(); i++) {
            final int nigW = graph[wA].get(i);
            if(nigW == wB) {
                return true;
            }
        }

        return false;
    }

    private static int getMinGroupReco(List<Integer>[] graph, int[] wReco,
    int nodeA, int nodeB) {
        // first we need to get the 3rd node in the group cyle.
        int minReco = BIG_ENOUGH_NUM;
        for(int i=0; i<graph[nodeA].size(); i++) {
            int nodeC = graph[nodeA].get(i);
            if(areConnected(graph, nodeB, nodeC)) {
                final int reco = wReco[nodeA] + wReco[nodeB] + wReco[nodeC] - 6;
                minReco = Math.min(minReco, reco);
            }
        }
        return minReco;
    }
    
    private static int getMinGlobalReco(List<Integer>[] graph, int[] wReco) {
        int minGlobalReco = BIG_ENOUGH_NUM;
        // N + M for traversing the graph in order to consider every edge
        // (N + M) * (N + M) = N^2 + NM + NM + M^2 -> N^2 + M^2 + NM
        for(int nodeA=1; nodeA<graph.length; nodeA++) {
            for(int i=0; i<graph[nodeA].size(); i++) {
                final int nodeB = graph[nodeA].get(i);
                final int minGroupReco = getMinGroupReco(graph, wReco, nodeA, nodeB);
                minGlobalReco = Math.min(minGlobalReco, minGroupReco);
            }
        }
        
        return minGlobalReco == BIG_ENOUGH_NUM ? -1 : minGlobalReco;
    }

    public static void main(String[] argv) {
        final Scanner scanner = new Scanner(System.in);
        final int wCnt = scanner.nextInt();
        final int relCnt = scanner.nextInt();

        final List<Integer>[] graph = new ArrayList[wCnt + 1];
        for(int i=1; i<=wCnt; i++) {
            graph[i] = new ArrayList();
        }
        final int[] wReco = new int[wCnt + 1];

        for(int i=0; i<relCnt; i++) {
            int warriorA = scanner.nextInt();
            int warriorB = scanner.nextInt();

            graph[warriorA].add(warriorB);
            graph[warriorB].add(warriorA);

            wReco[warriorA]++;
            wReco[warriorB]++;
        }

        int minReco = getMinGlobalReco(graph, wReco);
        
        System.out.println(minReco);
    }
}
