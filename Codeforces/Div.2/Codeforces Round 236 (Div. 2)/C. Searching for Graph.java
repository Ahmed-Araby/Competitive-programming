import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {
    private final static int BIG_ENOUGH_NUM = 24 * 23 / 2; // N * (N-1) / 2, using the max possible N(24)

    public static void main(String[] argv) {
        final Scanner scanner = new Scanner(System.in);
        int testCnt = scanner.nextInt();
        while(testCnt>0) {
            testCnt--;
            solveCase(scanner);
        }
    }


    private static int findNodeWithLestConn(List<Integer>[] graph) {
        int nodeWithMinConn = -1;
        int minConn = BIG_ENOUGH_NUM;
        for(int i=1; i<graph.length; i++) {
            final int connCnt = graph[i].size();
            if(connCnt < minConn) {
                minConn = connCnt;
                nodeWithMinConn = i;
            }
        }
        return nodeWithMinConn;
    }

    private static boolean areConnected(List<Integer>[] graph, int nodeA, int nodeB) {
        for(int i=0; i<graph[nodeA].size(); i++) {
            final int nigNode = graph[nodeA].get(i);
            if(nigNode == nodeB) {
                return true;
            }
        }
        return false;
    }

    private static int findNotConnNodeWithLestConn(List<Integer>[] graph, int currNode) {
        int pottNigNode = -1;
        int pottNigNodeConnCnt = BIG_ENOUGH_NUM;

        for(int node=1; node<graph.length; node++) {
            if(currNode != node && !areConnected(graph, currNode, node)) {
                final int connCnt = graph[node].size();
                if(connCnt < pottNigNodeConnCnt) {
                    pottNigNodeConnCnt = connCnt;
                    pottNigNode = node;
                }
            }
        }

        return pottNigNode;
    }


    private static void buildRingTopology(List<Integer>[] graph) {
        // for the first n connections to be placed,
        // make a ring topology out of them
        for(int i=1; i <graph.length; i++) {
            int nigNode = i+1 == graph.length ? 1: i+1;
            graph[i].add(nigNode);
            graph[nigNode].add(i);
            System.out.println(i + " " + nigNode);
        }
    }
    private static void putConnIntoGraph(List<Integer>[] graph, int connCnt) {
        while(connCnt > 0) {
            final int nodeA = findNodeWithLestConn(graph);
            final int nodeB = findNotConnNodeWithLestConn(graph, nodeA);
            graph[nodeA].add(nodeB);
            graph[nodeB].add(nodeA);
            System.out.println(nodeA + " " + nodeB);
            connCnt--;
        }
    }

    private static void printConn(List<Integer> graph, boolean[] visited) {

    }
    private static void solveCase(final Scanner scanner) {
        final int nodeCnt = scanner.nextInt();
        final int p = scanner.nextInt();

        final List<Integer>[] graph = new ArrayList[nodeCnt + 1];
        for(int i=0; i<=nodeCnt; i++) {
            graph[i] = new ArrayList<Integer>();
        }

        buildRingTopology(graph);
        putConnIntoGraph(graph, nodeCnt + p);
    }
}
