// https://codeforces.com/contest/292/problem/B
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static class NodeConnStat {
        int oneConnNodeCnt = 0;
        int twoConnNodeCnt = 0;
        int higherConnNodeCnt = 0;
    }
    
    private static void countNodeConn(List<List<Integer>> graph, boolean[] visited, int node, NodeConnStat nodeConnStat) {
        visited[node] = true;
        
        final int nodeConnCnt = graph.get(node).size();
        switch(nodeConnCnt) {
            case 1:
                nodeConnStat.oneConnNodeCnt++;
                break;
            case 2: 
                nodeConnStat.twoConnNodeCnt++;
                break;
            default:
                nodeConnStat.higherConnNodeCnt++;
        }
        
        for(int i=0; i<nodeConnCnt; i++) {
            final int nigNode = graph.get(node).get(i);
            if(visited[nigNode]) {
                continue;
            }
            countNodeConn(graph, visited, nigNode, nodeConnStat);
        }
    }
    
    private static NodeConnStat countNodeConn(List<List<Integer>> graph) {
        final boolean[] visited = new boolean[graph.size()];
        for(int i=0; i<visited.length; i++) {
            visited[i] = false;
        }
        final NodeConnStat nodeConnStat = new NodeConnStat();
        countNodeConn(graph, visited, 1, nodeConnStat);
        return nodeConnStat;
    }
    public static void main(String[] argv) {
        final Scanner scanner = new Scanner(System.in);
        final int nodeCnt = scanner.nextInt();
        final int connCnt = scanner.nextInt();
        
        final List<List<Integer>> graph = new ArrayList<List<Integer>>();
        for(int i=0; i<=nodeCnt; i++) {
            graph.add(new ArrayList());
        }
        
        for(int i=0; i<connCnt; i++) {
            final int nodeA = scanner.nextInt();
            final int nodeB = scanner.nextInt();
            graph.get(nodeA).add(nodeB);
            graph.get(nodeB).add(nodeA);
        }
        
        final NodeConnStat nodeConnStat = countNodeConn(graph);
        if(nodeConnStat.oneConnNodeCnt == 2 && nodeConnStat.twoConnNodeCnt == nodeCnt - 2) {
            System.out.println("bus topology");
        } else if (nodeConnStat.twoConnNodeCnt == nodeCnt) {
            System.out.println("ring topology");
        } else if (nodeConnStat.oneConnNodeCnt == nodeCnt - 1 && nodeConnStat.higherConnNodeCnt == 1) {
            System.out.println("star topology");
        } else {
            System.out.println("unknown topology");
        }
    }
}
