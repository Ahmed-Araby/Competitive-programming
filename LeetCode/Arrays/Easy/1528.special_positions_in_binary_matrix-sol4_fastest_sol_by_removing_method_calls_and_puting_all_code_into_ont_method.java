class Solution {
    public int numSpecial(int[][] mat) {
        int rowSum[] = new int[mat.length];
        int colSum[] = new int[mat[0].length];
        int rowCnt = mat.length, colCnt = mat[0].length;
        for(int rowIndex = 0; rowIndex < rowCnt; rowIndex++) {
            for(int colIndex = 0; colIndex < colCnt; colIndex++) {
                rowSum[rowIndex] += mat[rowIndex][colIndex];
                colSum[colIndex] += mat[rowIndex][colIndex];
            }
        }
        int specialCellsCnt = 0;
        for(int rowIndex = 0; rowIndex < mat.length; rowIndex++) {
            for(int colIndex = 0; colIndex < mat[0].length; colIndex++) {
                if(mat[rowIndex][colIndex] == 1 && rowSum[rowIndex] == 1 && colSum[colIndex] == 1) {
                    specialCellsCnt +=1;
                }
            }
        }

        return specialCellsCnt;
    }
}
