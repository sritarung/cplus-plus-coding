#include<iostream>
#include<list>
#include<vector>
using namespace std;

bool isDiv_3(const int& num) { return num%3==0;}

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: FinalP3.cpp" << " Date: 12/20/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    list<int> L;
    list<int>:: iterator iter; 

    int random;
    srand(17);

    for(int i=0; i<16;i++){
        random= rand()%100;
        L.push_back(random);
    }

    cout<<"Printing List: "<<endl;
    for(iter= L.begin(); iter!=L.end(); iter++){
        cout<<" "<<*iter;
    }

    int count=0;
    for(iter=L.begin(); iter!=L.end(); iter++){
        if((*iter)>50) count++;
    }
    cout<<endl;

    cout<<"The number of values exceeding 50 in the list are: "<<count<<endl;

    L.remove_if(isDiv_3);
    cout<<"Printing List after removing values divisible by 3: "<<endl;
    for(iter= L.begin(); iter!=L.end(); iter++){
        cout<<" "<<*iter;
    }

    vector<char> C;
    vector<char>:: iterator it;

    for(iter= L.begin(); iter!=L.end(); iter++){
        if(*iter>32){
            C.push_back(*iter);
        }
    }
    cout<<endl;

    cout<<"Printing values from Char vector: "<<endl;
    for(it= C.begin(); it!=C.end(); it++){
        cout<<" "<<*it;
    }
    return 0;
}

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: FinalP3.cpp Date: 12/20/2021
Student Name: Sri
----------------------------------------------
Printing List:
 94 2 17 97 63 15 9 90 3 99 39 49 55 24 88 56
The number of values exceeding 50 in the list are: 8
Printing List after removing values divisible by 3:
 94 2 17 97 49 55 88 56
Printing values from Char vector:
 ^ a 1 7 X 8
*/