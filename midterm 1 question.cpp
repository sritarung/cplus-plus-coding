#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
/*function for the third answer
*/
string isVector(vector <int>&v, vector<int>&u)
{
    string str;
    for(int j=0; j<u.size(); j++)
    {
	int i=0;
	for(int k=0; k<v.size()-1; k++)
	{
	  if(u[j]==(v[k+1]-v[k]))
	  {
		i++;
          }
	}
 	if(i==0)
	{
	  str="false";
	}
     }
     str="true";
     return str;
}  

/*answer for the first question
*/
int main()
{
	for(int i=1; i<=16;i=i*2)
	{
	  for(int j=0; j<i; j++)
	  {		
		cout<<"*";
	  }
	  cout<<"\n";
	}
	return 0;
}