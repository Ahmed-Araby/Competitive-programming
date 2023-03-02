import java.util.*;

class Program {

  public boolean isBipartiteGraph(
    int nodeIndex, boolean curNodeColor, 
    int[][] edges, boolean[]visited, 
    boolean[] nodeColor
  ) {
    if(visited[nodeIndex] == true){
      if(curNodeColor != nodeColor[nodeIndex]){
        return false;
      }
      return true;
    }
    visited[nodeIndex] = true;
    nodeColor[nodeIndex] = curNodeColor;
    for(int i=0; i<edges[nodeIndex].length; i++){
      boolean isBipartite = isBipartiteGraph(
        edges[nodeIndex][i], !curNodeColor,
        edges, visited, 
        nodeColor
      );
      if(isBipartite == false)
        return false;
    }
    return true;
  }
  
  public boolean twoColorable(int[][] edges) {
    // Write your code here.
    boolean[] visited = new boolean[edges.length];
    boolean[] nodesColor = new boolean[edges.length];
    return isBipartiteGraph(0, false, edges, visited, nodesColor);
  }
}
