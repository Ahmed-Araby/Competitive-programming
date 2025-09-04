import java.util.Scanner;


public class Main {

    private static void connectFirstNodesToAllNodes(boolean[][] graph, int nodesCnt) {
        for (int i = 0; i < nodesCnt; i++) {
            for (int j = i + 1; j < graph.length; j++) {
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }

    private static void connectRemainingNodesWithBusTopologyIfPossible(boolean[][] graph, int nodesCnt) {
        if(nodesCnt <= 3) {
            // if connected with a bus topology, they wont be connected in the complement graph.
            return;
        }
        // 2, 3-2 = 1
        for(int i=graph.length - 1; i> graph.length-nodesCnt; i--) {
            final int prevNode = i-1;
            graph[i][prevNode] = true;
            graph[prevNode][i] = true;
        }
    }

    private static void connectRemainingNodesWithBusTopology(boolean[][] graph, int nodesCnt) {
        for(int i=graph.length - 1; i> graph.length-nodesCnt; i--) {
            final int prevNode = i-1;
            graph[i][prevNode] = true;
            graph[prevNode][i] = true;
        }
    }


    private static void printGraph(boolean[][] graph) {
        System.out.print("YES");
        for(int i=0; i<graph.length; i++) {
            System.out.println();
            for(int j=0; j<graph.length; j++) {
                System.out.print(graph[i][j] == true ? 1 : 0);
            }
        }
    }

    public static void main(String[] argv) {
        final Scanner scanner = new Scanner(System.in);
        final int nodeCnt = scanner.nextInt();
        final int orgGCompCnt = scanner.nextInt();
        final int complGCompCnt = scanner.nextInt();

        // checking for the constraints on the number of compnents in the graph
        // and its complement graph
        if(
                ((nodeCnt == 2 || nodeCnt == 3) && (orgGCompCnt == complGCompCnt)) ||
                (orgGCompCnt > 1 && complGCompCnt != 1)
        ) {
            System.out.println("NO");
            return;
        }

        final boolean[][] graph = new boolean[nodeCnt][nodeCnt];
        // handle orgGCompCnt == 1 and complGCompCnt is [1, n];
        if(orgGCompCnt == 1) {
            connectFirstNodesToAllNodes(graph, complGCompCnt - 1);
            connectRemainingNodesWithBusTopologyIfPossible(graph, nodeCnt - (complGCompCnt - 1));
        } else {
            connectRemainingNodesWithBusTopology(graph, nodeCnt - (orgGCompCnt - 1));
        }

        printGraph(graph);

    }
}
