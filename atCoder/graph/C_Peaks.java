// https://atcoder.jp/contests/abc166/tasks/abc166_c
// topic: graph, BFS like.
import java.util.Scanner;

import java.util.List;
import java.util.ArrayList;

public class Main {

    public static boolean isGoodNode(List<List<Integer>> graph, int node, int[] elevation) {
        for(int i=0; i<graph.get(node).size(); i++) {
            int nig = graph.get(node).get(i);
            if(elevation[nig] >= elevation[node]) {
                return false;
            }
        }
        return true;
    }

    public static int countGoodNodes(List<List<Integer>> graph, int nodesCnt, int[] elevation) {
        int goodNodesCnt = 0;
        for(int node=1; node<=nodesCnt; node++) {
            if(isGoodNode(graph, node, elevation)) {
                goodNodesCnt++;
            }
        }
        return goodNodesCnt;
    }
    public static void main(String[] argv) {
        final Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        final int[] elevation = new int[n+1];
        for(int i=1; i<=n; i++){
            elevation[i] = scanner.nextInt();
        }

        final List<List<Integer>> graph = new ArrayList<List<Integer>>();
        for(int i=0; i<=n; i++) {
            graph.add(new ArrayList<Integer>());
        }

        for(int i=0; i<m; i++) {
            int nodeA = scanner.nextInt();
            int nodeB = scanner.nextInt();
            graph.get(nodeA).add(nodeB);
            graph.get(nodeB).add(nodeA);
        }

        final int goodNodesCnt = countGoodNodes(graph, n, elevation);
        System.out.println(goodNodesCnt);
    }
}
