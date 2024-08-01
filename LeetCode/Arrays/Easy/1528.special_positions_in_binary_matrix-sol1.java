class Solution {
    private boolean isSpecialCellRowWise(int[][] mat, int row, int col) {
        for(int index = 0; index <mat[0].length; index++) {
            if (index != col && mat[row][index] == 1) {
                return false;
            } 
        }
        return true;
    }

    private boolean isSpecialCellColWise(int[][] mat, int row, int col) {
        for(int index = 0; index < mat.length; index++) {
            if(index != row && mat[index][col] == 1) {
                return false;
            }
        }
        return true;
    }
    private boolean isSpecialCell(int[][] mat, int row, int col) {
        return mat[row][col] == 1 
        && this.isSpecialCellRowWise(mat, row, col) 
        && this.isSpecialCellColWise(mat, row, col);
    }

    public int numSpecial(int[][] mat) {
        int specialCellCount = 0;
        for (int rIndex = 0; rIndex < mat.length; rIndex++) {
            for (int cIndex = 0; cIndex < mat[0].length; cIndex++) {
                if (this.isSpecialCell(mat, rIndex, cIndex)) {
                    specialCellCount++;
                }
            }
        }
        return specialCellCount;
    }
}
