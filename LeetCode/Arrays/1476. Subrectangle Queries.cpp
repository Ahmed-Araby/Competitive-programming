class updateQ
{
    public:
        int r1, c1, r2, c2, val;
        updateQ(int r1, int c1, int r2, int c2, int val){
            this->r1 = r1;
            this->c1 = c1;
            this->r2 = r2;
            this->c2 = c2;
            this->val = val;
        }
    
        bool cellInside(int r, int c)
        {
            if(r>=r1 && r<=r2 && 
              c>=c1 && c<=c2)
                return true;
            return false;
        }
};

class SubrectangleQueries {
public:
    vector<updateQ> uq;
    vector<vector<int> > *rect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = &rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        uq.push_back(updateQ(row1, col1, row2, col2, newValue));
    }
    
    int getValue(int row, int col) {
        for(int i=uq.size()-1; i>=0; i--){
            if(uq[i].cellInside(row, col))
                return uq[i].val;
        }
        return (*rect)[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
