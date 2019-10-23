class Solution {
public:
    bool g[8][8];
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int> > ans;
        int kx=king[0];
        int ky=king[1];
        
        for(int i=0; i<queens.size(); i++)
        {
            int x=queens[i][0];
            int y=queens[i][1];
            g[x][y]=1;
        }
        
        // row right 
        int xd[]={1 , -1 , 0 , 0 , 1 , -1 , -1 , 1};  // row
        int yd[]={0 , 0 , 1 , -1 , 1 , -1 , 1 , -1}; // col
        
        for(int i=0; i<8; i++)
        {
            vector<int> tmp=moveTheKing(kx , ky , xd[i] , yd[i]);
            if(tmp[0]!=-1)
                ans.push_back(tmp);
        }
        return ans;
    }
    
    bool valid(int x, int y)
    {
        if(x>=0 && x<8 && y>=0 && y<8)
            return 1;
        return 0;
    }
    
    vector<int>  moveTheKing(int x , int y , int incx , int incy)
    {
        vector<int>tmp(2);
        tmp[0]=-1;
        tmp[1]=-1;
        
        while(1)
        {
            if(!valid(x , y))
                break;
            if(g[x][y]){
                tmp[0]=x;
                tmp[1]=y;
                break;
            }
            
            x+=incx;
            y+=incy;
        }
        return tmp;
    }
};
