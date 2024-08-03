class Solution {
    private boolean aboutToRott(int[][] grid, int rIndex, int cIndex, int curMinuteId) {
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, 1, -1};
        for(int mov = 0; mov < 4; mov++) { // we have 4 movements {up, down, right, left}
            int nRIndex = rIndex + dRow[mov];
            int nCIndex = cIndex + dCol[mov];
            if(nRIndex >=0 && nRIndex < grid.length && nCIndex >= 0 && nCIndex < grid[0].length) {
              if (grid[nRIndex][nCIndex] > 1 && grid[nRIndex][nCIndex]  < curMinuteId) {
                return true;
              }  
            }
        }
        return false;
    }

    private boolean rott(int[][] grid, int curMinuteId) {
        int rLen = grid.length, cLen = grid[0].length;
        boolean rottOpHappened = false;
        for(int rIndex = 0; rIndex < rLen; rIndex++) {
            for(int cIndex = 0; cIndex < cLen; cIndex++) {
                if(grid[rIndex][cIndex] == 1 && this.aboutToRott(grid, rIndex, cIndex, curMinuteId)) {
                    rottOpHappened = true;
                    grid[rIndex][cIndex] = curMinuteId;
                }
            }
        }
        return rottOpHappened;
    }
    private boolean hasFreshOranges(int[][] grid) {
        int rLen = grid.length, cLen = grid[0].length;
        for(int rIndex = 0; rIndex < rLen; rIndex++) {
            for(int cIndex = 0; cIndex < cLen; cIndex++) {
                if(grid[rIndex][cIndex] == 1) {
                    return true;
                }
            }
        }
        return false;
    }

    public int orangesRotting(int[][] grid) {
        int minutesElapsed = 0;
        int curMinuteId = 3;
        while(rott(grid, curMinuteId)) {
            minutesElapsed++;
            curMinuteId++;
        }

        if(this.hasFreshOranges(grid)) {
            return -1;
        }
        return minutesElapsed;
    }
}
