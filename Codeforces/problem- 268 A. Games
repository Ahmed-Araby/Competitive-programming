#include <iostream>
using namespace std;
int main()
{   
  int number , array[30][2] , times=0;
  // taking the information
  cin>>number;
  for(int i=0; i<number; i++)
  {
    for(int j=0; j<2; j++)
    {
      cin>>array[i][j];
    }
  }
  for(int i=0; i<number; i++)
  {
    for(int j=0; j<number; j++)
    {
      if(array[i][0]==array[j][1]) // for the same teme the home and gest colors
      // can`t be the same
      times++;
    }
  }
  cout<<times<< endl;
  return 0;
}
