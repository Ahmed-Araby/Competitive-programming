import java.util.*;

// Do not edit the class below except for
// the constructor and the createSet, find,
// and union methods. Feel free to add new
// properties and methods to the class.
class Program {
  static class UnionFind {
    Integer[] parent;
    int[] depth;
    UnionFind(){
      parent = new Integer[100];
      depth = new int[100];
    }

    private void enlarge(int minSize){
      Integer[] newParent = new Integer[2*minSize];
      int[] newDepth = new int[2*minSize];
      
      for(int i=0; i<parent.length; i++){
        newParent[i] = this.parent[i];
        newDepth[i] = this.depth[i];
      }
      
      this.parent = newParent;
      this.depth = newDepth;
    }
    
    public void createSet(int value) {
      if(this.parent.length <= value)
        this.enlarge(value);
      if(this.find(value) != null)
        return;
      this.parent[value] = value;
      this.depth[value] = 0;
    }

    public Integer find(int value) {
      // Write your code here.
      if(this.parent[value] == null)
        return null;
      if(parent[value] == value) // representative of a set
        return value;
      return parent[value] = this.find(parent[value]); // with path compression
    }

    public void union(int valueOne, int valueTwo) {
      // Write your code here.
      Integer pOne = this.find(valueOne);
      Integer pTwo = this.find(valueTwo);
      if(pOne == null || pTwo == null || pOne == pTwo){
        return;
      }

      // pOne should always hold the tree with the bigger height / depth
      if(depth[pOne] < depth[pTwo]){
        int temp = pTwo;
        pTwo = pOne;
        pOne = temp;
      }
      parent[pTwo] = pOne;
      if(depth[pOne] == depth[pTwo]){
        depth[pOne] +=1;
      }
    }
  }
}
