class Solution {
    private void initArr(int[] arr, int initVal) {
        for(int index=0; index<arr.length; index++) {
            arr[index] = initVal;
        }
    }

    private int[] computeRowWiseSum(int[][] mat) {
        int rowCnt = mat.length, colCnt = mat[0].length;
        int rowSum[] = new int[rowCnt];
        initArr(rowSum, 0);

        for(int rowIndex = 0; rowIndex < rowCnt; rowIndex++) {
            for(int colIndex = 0; colIndex < colCnt; colIndex++) {
                rowSum[rowIndex] += mat[rowIndex][colIndex];
            }
        }
        return rowSum;
    }

    private int[] computeColWiseSum(int[][] mat) {
        int rowCnt = mat.length, colCnt = mat[0].length;
        int colSum[] = new int[colCnt];
        initArr(colSum, 0);

        for(int colIndex = 0; colIndex < colCnt; colIndex++) {
            for(int rowIndex = 0; rowIndex < rowCnt; rowIndex++) {
                colSum[colIndex] += mat[rowIndex][colIndex];
            }
        }
        return colSum;
    }

    private boolean isSpecialCell(int mat[][], int rowSum[], int colSum[], int rowIndex, int colIndex) {
        return mat[rowIndex][colIndex] == 1 && rowSum[rowIndex] == 1 && colSum[colIndex] == 1;
    }

    public int numSpecial(int[][] mat) {
        int rowSum[] = computeRowWiseSum(mat);
        int colSum[] = computeColWiseSum(mat);

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
