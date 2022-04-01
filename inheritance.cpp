#include <iostream>
#include <cstring>
using namespace std;

class example 
{
 private:
    string name;        
 public:
     example(){strcpy(Name, "no_name_yet");}
     example(char n[100]){strcpy(Name, n);}
};

int main() 
{
    example ex;
    char a[100];
    cout<<"Give name ";
    cin>>a;
    example();
    example(a);
    return 0;
}