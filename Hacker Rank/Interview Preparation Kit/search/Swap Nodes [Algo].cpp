#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
 
void in_order_traversal(int root, int level,  int k,
                     vector<vector<int> > &indexes, 
                     bool *swaped, 
                     vector<int> &order)
{
    cout<<root<< endl;
    if(root<0)
        return ;
    
    if(swaped[level]){
        in_order_traversal(indexes[root][1]-1, level + 1, k, indexes, swaped, order);
        order.push_back(root+1);
        in_order_traversal(indexes[root][0]-1, level + 1, k, indexes, swaped, order);
    }
    else {
        in_order_traversal(indexes[root][0]-1, level + 1, k, indexes, swaped, order);
        order.push_back(root+1);
        in_order_traversal(indexes[root][1]-1, level + 1, k, indexes, swaped, order);
    }
    return ;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
    * Write your code here.
    */
    
    int n = indexes.size();
    int q = queries.size();
    bool *swaped = new bool[n+1]; // levles
    
    for(int i=0; i<=n; i++)
        swaped[i] = 0; 
        
    vector<vector<int> > in_order(q+1);
    for(int i=0; i<q; i++){
        int k = queries[i];
        
        for(int j=0; j<=n; j++){
            if(j%k==0)
                swaped[j] = !swaped[j];
        }
        
        in_order_traversal(0, 1, k, indexes, swaped, in_order[i]);        
    }
//    cout<<in_order[0].size()<< endl;
    return in_order;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
