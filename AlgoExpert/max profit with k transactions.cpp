#include <vector>
using namespace std;

int solve(int index ,bool haveS, int trans, 
				 	vector<int> prices, int ***dp)
{
	//cout<<index<<" "<<haveS<<" "<<trans<< endl;
	if(index == prices.size() || trans == 0)
			return 0;	
	int &ret = dp[index][trans][haveS];
	//cout<<ret<< endl;
	if(ret!=-1)
		return ret;
	ret = 0;
	
	if(haveS){
		// sell 
		ret = prices[index] + solve(index+1, false, trans-1, prices, dp);
		// dont sell 
		ret = max(ret, solve(index+1, true, trans, prices, dp) );
		// no need to sell and buy this one at the same time
	}
	else{
		// buy
		ret = max(0, solve(index+1, true, trans, prices, dp) - prices[index]);
		// don't buy 
		ret = max(ret, solve(index+1, false, trans, prices, dp));
	}
	
	return ret;
}

int maxProfitWithKTransactions(vector<int> prices, int k) {
	
	int n = prices.size();
	int ***dp = new int** [n+1];
	for(int i=0; i<n; i++){
		dp[i] = new int*[k+1];
		for(int j=0; j<=k; j++){
				dp[i][j] = new int[2];
				dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
	
	int ans = solve(0, 0, k,
									prices, dp);
  return ans;
}
