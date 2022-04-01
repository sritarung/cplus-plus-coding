#include<iostream>
#include<ctime>//to access time function
#include<iterator>// iterators
#include <list>
using namespace std;

bool is_div_3(const int& num) { return num%3==0;}

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW10P1.cpp" << " Date: 12/15/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    list<int> ilist;
    
    int ra;
    srand (time(NULL));

    for(int i=0;i<24;i++){
        ra=-3 +(rand() % 33); //generates numbers -3 to 29
        ilist.push_back(ra);
    }
    
    cout<<"Before: "<<endl;
    for (auto it = ilist.begin(); it != ilist.end(); ++it){
        cout << ' ' << *it;
    }
    
    ilist.remove_if(is_div_3);
    cout<<endl<<"After:"<<endl;

    for (auto it = ilist.begin(); it != ilist.end(); ++it){
        cout << ' ' << *it;
    }
    return 0;
}

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW10P1.cpp Date: 12/15/2021
Student Name: Sri
----------------------------------------------
Before:
 21 10 23 24 -3 13 20 24 29 10 12 -1 4 10 -1 15 11 12 12 3 14 11 0 -2
After:
 10 23 13 20 29 10 -1 4 10 -1 11 14 11 -2
*/