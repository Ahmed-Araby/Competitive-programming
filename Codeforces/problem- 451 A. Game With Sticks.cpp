#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n , m;
  cin>>n>>m;
  int result=n*m , x=1 , sticks=n+m; // the number of intersections I have  and a checker
  string winner="ahmed";
  while(result>0)
  {
    if(x==1) // akshat begin first
    {
      result=(result-((sticks)-1)); // the intersections left
      winner="Akshat"; // winner name
      sticks-=2; // every single move I delete 2 sticks from the grade
    }
    else if (x==-1)
    {
      result=(result-((sticks)-1)); // the intersections left
      winner="Malvika"; // winner name
      sticks-=2; // every single move I delete 2 sticks from the grade
    }
    x=x*(-1); // change the value to take terns
  }
  cout<<winner<< endl;
  return 0;
}
