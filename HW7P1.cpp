#include<bits/stdc++.h>
#include<limits>
using namespace std;

template<typename T>

void sum(T v){
    auto sum=0;// auto for the initialization expression of a declared variable
    for(auto x:v){
        sum+=x;
    }
    cout<<"The sum of the values in this vector: "<<sum; 
}

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW7P1.cpp" << " Date: 12/2/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/
    
    //rest of the code
    cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );// cin ignores max number of characters until new line(\n)
    vector<int> vi(8);
    vector<char> vc(8);
    vector<float> vf(8);
    vector<string> vs(8);
    vector<pair<int, int>> vp(8);

    //take inputs for the differe types of vectors
    cout<<"Enter values for integer vector: ";
    for(int i=0; i<8; i++){
        cin>>vi[i];
    }
    cout<<endl;

    cout<<"Enter values for char vector: ";
    for(int i=0; i<8; i++){
        cin>>vc[i];
    }
    cout<<endl;

    cout<<"Enter values for float vector: ";
    for(int i=0; i<8; i++){
        cin>>vf[i];
    }
    cout<<endl;

    cout<<"Enter values for string vector: ";
    for(int i=0; i<8; i++){
        cin>>vs[i];
    }
    cout<<endl;

    cout<<"Enter values for pair<int, int> vector: \n";
    for(int i=0; i<8; i++){
        int a, b;
        cin>>a>>b;
        vp[i].first=a;
        vp[i].second=b;
    }

    //sorts the vectors
    sort(vi.begin(), vi.end());
    sort(vf.begin(), vf.end());
    sort(vc.begin(), vc.end());
    sort(vs.begin(), vs.end());

    //reverses the vectors
    reverse(vi.begin(), vi.end());
    reverse(vf.begin(), vf.end());
    reverse(vc.begin(), vc.end());
    reverse(vs.begin(), vs.end());

    sum(vi);
    cout<<endl;
    sum(vf);

    return 0;
}
/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW7P1.cpp Date: 12/2/2021
Student Name: Sri
----------------------------------------------
Enter values for integer vector: 1 2 3 4 5 67 8 9

Enter values for char vector: a b c d e f g h 

Enter values for float vector: 1.2 3.9 5.5 6.6 2.2 3.3 9.2 8.1

Enter values for string vector: hi hello bye yup yikes lol sup gank

Enter values for pair<int, int> vector: 
1 2
2 3
4 5
5 6
6 7
3 4
7 8
8 9
The sum of the values in this vector: 99
The sum of the values in this vector: 40
*/