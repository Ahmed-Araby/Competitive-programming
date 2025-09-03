// https://codeforces.com/contest/22/problem/C
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class Main {
    
    private static boolean canGraphBeConnected(int nodesCnt, int connCnt) {
        return connCnt >= nodesCnt -1;
    }
    
    private static boolean canGraphBeDisconnectedWith1NodeFailure(int nodesCnt, int connCnt) {
        return connCnt <= (nodesCnt - 3) * (nodesCnt - 2) / 2 + (nodesCnt -1);
    }
    
    private static void printStarTopology(int nodeCnt, int starNode) {
        for(int node=1; node<=nodeCnt; node++) {
            if(node == starNode) {
                continue;
            }
            System.out.println(starNode + " " + node);
        }
    }
    
    private static LinkedList<Integer> getNodesFromRightGroup(int nodesCnt, int starNode, int connCnt) {
        final LinkedList<Integer> subRightGroupNodes = new LinkedList<Integer>();
        for(int i=1; i<=nodesCnt; i++) {
            if(i == starNode) {
                continue;
            } else if(starNode > 1 && starNode - 1 == i) { // left group
                continue;
            } else if(starNode == 1 && starNode + 1 == i) { // left group
                continue;
            }
            
            subRightGroupNodes.add(i);
            final int subRightGroupSize = subRightGroupNodes.size();
            
            // summation of arithematic series from 1 to (subRightGroupSize-1)
            if (subRightGroupSize * (subRightGroupSize - 1) / 2 >= connCnt) {
                break;
            }
        }
        
        return subRightGroupNodes;
    }
    
    private static void printRightGroupConnections(int nodesCnt, int starNode, int connCnt) {
        final LinkedList<Integer> subRightGroupNodes = getNodesFromRightGroup(nodesCnt, starNode, connCnt);
        
        while(connCnt > 0) {
            final int nodeA = subRightGroupNodes.remove();
            final ListIterator<Integer> iter = subRightGroupNodes.listIterator(0);
            while(connCnt > 0 && iter.hasNext()) {
                final int nodeB = iter.next();
                System.out.println(nodeA + " " + nodeB);
                connCnt--;
            }
        }
    }
    
    public static void main(String[] argv) {
        final Scanner scanner = new Scanner(System.in);
        final int nodesCnt = scanner.nextInt();
        final int connCnt = scanner.nextInt();
        final int starNode = scanner.nextInt();
        
        if(!canGraphBeConnected(nodesCnt, connCnt) || !canGraphBeDisconnectedWith1NodeFailure(nodesCnt, connCnt)) {
            System.out.println(-1);
            return;
        }
        
        printStarTopology(nodesCnt, starNode);
        final int remConnCnt = connCnt - (nodesCnt - 1);
        printRightGroupConnections(nodesCnt, starNode, remConnCnt);
    }
}
