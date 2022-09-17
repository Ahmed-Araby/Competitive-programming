import java.util.Scanner;  // Import the Scanner class

class Solution{

    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int j=0; j < t; j++){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0; i<n; i++)
                arr[i] = sc.nextInt();
            int cost = calcCost(arr);
            System.out.println(String.format("Case #%d: %d", j+1, cost));
        }
    }


    public static int findMinPos(int[] arr, int s){
        int minIndex = s;
        for(; s< arr.length; s++){
            if(arr[minIndex] > arr[s])
                minIndex = s;
        }
        return minIndex;
    }

    public static void reverse(int []arr, int l, int r){
        int tmp;
        while(l < r){
            tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }

    public static int calcCost(int[] arr){
        int cost = 0;
        for(int i=0; i < arr.length-1; i++){
            int minIndex = findMinPos(arr, i);
            cost += minIndex - i + 1;
            reverse(arr, i, minIndex);
        }
        return  cost;
    }
}
