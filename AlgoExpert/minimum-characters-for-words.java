import java.util.*;

class Program {
  static int minRequiredCharCount = 0; 
  static int maxCharCount = 128;

  public Program(){
    minRequiredCharCount = 0; 
    // because the judge is using the same 
    // object instance for all the tests
  }
  
  public void mergeCharCounts(int[] requiredCharsCountForWord, int[] minRequiredCharsCountForWordArray){
    minRequiredCharCount = 0;
    for(int i=0; i<maxCharCount; i++){
      minRequiredCharsCountForWordArray[i] = Math.max(
        minRequiredCharsCountForWordArray[i], 
        requiredCharsCountForWord[i]
      );
      minRequiredCharCount += minRequiredCharsCountForWordArray[i];
    }
  }
  
  public int[] getCharsCount(String word){
    int[] requiredCharsCountForWord = new int[maxCharCount];
    for(int i=0; i<word.length(); i++){
      requiredCharsCountForWord[word.charAt(i)]++;
    }
    return requiredCharsCountForWord;
  }

  public void addChar(char c, int count, char[] requiredChars, int index){
    for(int i=0; i<count; i++){
      requiredChars[index] = c;
      index++;
    }
  }
  
  public char[] generateArrayOfMinRequiredChars(int[] codePointCount){
    char [] requiredChars = new char[minRequiredCharCount];
    int index = 0;
    for(int i=0; i<maxCharCount; i++){
      if(codePointCount[i] > 0){
        addChar((char)i, codePointCount[i], requiredChars, index);
        index += codePointCount[i];
      }
    }
    return requiredChars;
  }
  
  public char[] minimumCharactersForWords(String[] words) {
    // Write your code here.
    int [] minRequiredCharsCountForWordArray = new int[128];
    
    for(int i = 0; i<words.length; i++){
      int[] requiredCharCountForWord  = getCharsCount(words[i]);
      mergeCharCounts(requiredCharCountForWord, minRequiredCharsCountForWordArray);
    }
    return generateArrayOfMinRequiredChars(minRequiredCharsCountForWordArray);
  }
}
