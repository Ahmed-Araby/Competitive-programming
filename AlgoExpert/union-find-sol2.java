import java.util.*;

// Do not edit the class below except for
// the constructor and the createSet, find,
// and union methods. Feel free to add new
// properties and methods to the class.
class Program {
  static class Node {
    public int value;
    public int rank;
    public Node parent;
    public Node(int value, int rank){
      this.value = value;
      this.rank = rank;
      this.parent = null;
    }
  }
  
  static class UnionFind {
    Node[] parent;
    UnionFind(){
      parent = new Node[100];
    }

    private void enlarge(int minSize){
      Node[] newParent = new Node[2*minSize];
      
      for(int i=0; i<parent.length; i++){
        newParent[i] = this.parent[i];
      }
      
      this.parent = newParent;
    }
    
    public void createSet(int value) {
      if(this.parent.length <= value)
        this.enlarge(value);
      if(this.find(value) != null)
        return;
      this.parent[value] = new Node(value, 0);
    }

    public Node findNode(Node node){
      if(node.parent == null)
        return node;
      return node.parent = findNode(node.parent); // path compression
    }
    
    public Node findNode(int value) {
      // Write your code here.
      if(this.parent[value] == null)
        return null;
      return findNode(parent[value]);
    }

    public Integer find(int value){
      final Node parent = findNode(value);
      if(parent == null) 
        return null;
      return parent.value;
    }

    public void union(int valueOne, int valueTwo) {
      // Write your code here.
      Node pOne = this.findNode(valueOne);
      Node pTwo = this.findNode(valueTwo);
      if(pOne == null || pTwo == null || pOne == pTwo){
        return;
      }

      // pOne should always hold the tree with the bigger height / depth
      if(pOne.rank < pTwo.rank){
        Node temp = pTwo;
        pTwo = pOne;
        pOne = temp;
      }
      
      pTwo.parent = pOne;
      if(pOne.rank == pTwo.rank){
        pOne.rank +=1;
      }
    }
  }
}
