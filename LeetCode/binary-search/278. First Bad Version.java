// using long data type
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        Long lIndex = 1L, rIndex = Long.valueOf(n);
        while(lIndex < rIndex){
            Long mid = ((lIndex + rIndex) / 2);
            if(isBadVersion(mid.intValue()))
                rIndex = mid;
            else 
                lIndex = mid + 1;
        }
        
        return rIndex.intValue();
        
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
// using int data type
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lIndex = 1, rIndex = n;
        while(lIndex < rIndex){
            int mid = lIndex + (rIndex - lIndex) / 2;
            if(isBadVersion(mid))
                rIndex = mid;
            else 
                lIndex = mid + 1;
        }
        
        return rIndex;
        
    }
}
