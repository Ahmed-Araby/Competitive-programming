class Solution {
    private void initArr(int[] arr, int initVal) {
        for(int index=0; index<arr.length; index++) {
            arr[index] = initVal;
        }
    }

    private void computeRowWiseAndColWiseSum(int[][] mat, int rowSum[], int colSum[]) {
        int rowCnt = mat.length, colCnt = mat[0].length;
        for(int rowIndex = 0; rowIndex < rowCnt; rowIndex++) {
            for(int colIndex = 0; colIndex < colCnt; colIndex++) {
                rowSum[rowIndex] += mat[rowIndex][colIndex];
                colSum[colIndex] += mat[rowIndex][colIndex];
            }
        }
    }

    private boolean isSpecialCell(int mat[][], int rowSum[], int colSum[], int rowIndex, int colIndex) {
        return mat[rowIndex][colIndex] == 1 && rowSum[rowIndex] == 1 && colSum[colIndex] == 1;
    }

    public int numSpecial(int[][] mat) {
        int rowSum[] = new int[mat.length];
        int colSum[] = new int[mat[0].length];
        initArr(rowSum, 0);
        initArr(colSum, 0);
        computeRowWiseAndColWiseSum(mat, rowSum, colSum);

        int specialCellsCnt = 0;
        for(int rowIndex = 0; rowIndex < mat.length; rowIndex++) {
            for(int colIndex = 0; colIndex < mat[0].length; colIndex++) {
                if(isSpecialCell(mat, rowSum, colSum, rowIndex, colIndex)) {
                    specialCellsCnt +=1;
                }
            }
        }

        return specialCellsCnt;
    }
}
