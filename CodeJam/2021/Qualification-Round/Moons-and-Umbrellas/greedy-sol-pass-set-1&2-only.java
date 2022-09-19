// greedy solution for the first 2 test sets

import java.util.Scanner;

class Solution{

    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int testCasesCnt = sc.nextInt();
        for(int tc = 1; tc<=testCasesCnt; tc++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            String art = sc.nextLine().trim();
            int cost = getMinimumCostForFillingArt(x, y, art);
            System.out.println(String.format("Case #%d: %d", tc, cost));
        }
    }
    
    public static boolean charEqual(char a, char b){
        return Character.compare(a, b) == 0;
    }
    
    public static int calcCostByFillingSubArt(
        int x, int y, int l, int r, String art
    )
    {
        if(
            !charEqual(art.charAt(l), art.charAt(r)) &&
            !charEqual(art.charAt(l), '?') && 
            !charEqual(art.charAt(r) , '?')
        ){
            if(charEqual(art.charAt(l), 'C')) // cj
                return x;
            else // jc
                return y;
        }
        return 0;
    }
    
    public static int getMinimumCostForFillingArt(
        int x, int y, String art
    )
    {
        int l = 0, r=0;
        int cost = 0;
        
        while(r < art.length()){
            if(!charEqual(art.charAt(r), '?') && l!=r){
                cost += calcCostByFillingSubArt(x, y, l, r, art);
                l = r;
                r +=1;
            }
            else 
                r+=1;
        }
        
        return cost;
    }
}
