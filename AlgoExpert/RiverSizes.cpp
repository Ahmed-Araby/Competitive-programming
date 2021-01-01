#include <vector>
using namespace std;

bool valid(int x, int y, int r, int c, vector<vector<int>>& mat)
{
	if(x>=0 && x<r && y>=0 && y<c && mat[x][y]==1)
			return true;
	return false;
}

void flood_fill(int x, int y,
									int r, int c, 
								  vector<vector<int> >& mat,
									bool**vis, int& sz)
{
	if(!valid(x, y, r, c, mat) || vis[x][y])
		return ;
	//cout<<x<<" "<<y<< endl;
	vis[x][y] = 1;
	sz+=1;
	
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		flood_fill(nx, ny, r, c, mat, vis, sz);
	}
	
	return;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
	int r = matrix.size();
	int c = r>0? matrix[0].size() : 0;
	
	bool ** vis = new bool* [r];
	for(int i=0; i<r; i++){
		vis[i] = new bool[c];
		
		for(int j=0; j<c; j++)
			vis[i][j] = 0;
	}

	vector<int> szs;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++){
			if(!vis[i][j] && matrix[i][j]==1){
				int sz = 0;
				flood_fill(i, j, r, c, matrix, vis, sz);
				szs.push_back(sz);
			}	
		}
  return szs;
}
