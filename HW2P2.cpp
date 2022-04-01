#include <iostream>
using namespace std;

void twoMultiples(int *arr, int size){
    for(int i=0; i<size; i++){
        arr[i]= i * 2;
    }
}

int main(int argc, char *argv[] )
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW2P2.cpp" << " Date: 09/30/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    int Row = atoi(argv[1]);
    int *heap_ptr = new int[Row];

    twoMultiples(heap_ptr, Row);
    cout<<"(";
    for(int i=0; i<Row; i++){
        cout<<*heap_ptr;
        heap_ptr++;
        if(i!=Row-1)
            cout<<",";
        else
            cout<<")";
    }
    return 0;
}

/***Results
PS C:\Users\srita\Desktop\C++> g++ HW2P2.cpp -o HW2P2
PS C:\Users\srita\Desktop\C++> .\HW2P2 16
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW2P2.cpp Date: 09/30/2021
Student Name: Sri
----------------------------------------------
(0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30)
*/

const Date operator-(const Date &d1, const Date &d2){
    int day= d1.getDay()- d2.getDay();
    int month= d1.getMonth()- d2.getMonth();
    int year= d1.getYear()- d2.getYear();
    return Date(day, month, year)
}

const int days(const Date&d1){
    int temp= d1.getDay();
    if(d1.get)
}