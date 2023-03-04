import java.util.*;

class Program {
  // This is an input class. Do not edit.
  public static class LinkedList {
    public int value;
    public LinkedList next;

    public LinkedList(int value) {
      this.value = value;
      this.next = null;
    }
  }

  public LinkedList sumOfLinkedLists(LinkedList linkedListOne, LinkedList linkedListTwo) {
    // Write your code here
    
    LinkedList resultLLReference = null;
    LinkedList resultLastDigitNode = null;
    int carry = 0, num1, num2;
   
    while(linkedListOne != null || linkedListTwo != null) {
      if(linkedListOne != null){
        num1 = linkedListOne.value;
        linkedListOne = linkedListOne.next;
      } else {
        num1 = 0;
      }
      
      if(linkedListTwo != null) {
        num2 = linkedListTwo.value;
        linkedListTwo = linkedListTwo.next;
      } else{
        num2 = 0;
      }
      
      int res = num1 + num2 + carry;
      if(res >= 10){
        res = res - 10;
        carry = 1;
      } else {
        carry = 0;
      } 
      
      if(resultLLReference == null){
        resultLLReference = new LinkedList(res);
        resultLastDigitNode = resultLLReference;
      } else{
        resultLastDigitNode.next = new LinkedList(res);
        resultLastDigitNode = resultLastDigitNode.next;
      }
    }
    
    if(carry == 1){
      resultLastDigitNode.next = new LinkedList(1);
      resultLastDigitNode = resultLastDigitNode.next;
    }
    
    return resultLLReference;
  }
}
