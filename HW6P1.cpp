#include <iostream>
using namespace std;

template<typename T>

void Swap(T &t1, T &t2)
{
    T temp=t1;
    t1=t2;
    t2=temp;

}

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW6P1.cpp" << " Date: 11/30/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    int i1=1, i2=2;
    cout<<"Before swap: integer1= "<<i1<<", integer2= "<<i2<<endl;
    Swap(i1,i2);
    cout<<"After swap: integer1= "<<i1<<", integer2= "<<i2<<endl;
    cout<<endl;

    float f1=1.2, f2=2.3;
    cout<<"Before swap: float1= "<<f1<<", float2= "<<f2<<endl;
    Swap(f1,f2);
    cout<<"After swap: float1= "<<f1<<", float2= "<<f2<<endl;
    cout<<endl;

    char c1='a',c2='b';
    cout<<"Before swap: char1= "<<c1<<", char2= "<<c2<<endl;
    Swap(c1, c2);
    cout<<"After swap: char1= "<<c1<<", char2= "<<c2<<endl;
    cout<<endl;

    string str1="Apple", str2= "Banana";
    cout<<"Before swap: string1= "<<str1<<", string2= "<<str2<<endl;
    Swap(str1, str2);
    cout<<"After swap: string1= "<<str1<<", string2= "<<str2<<endl;
    cout<<endl;
    return 0;
}
/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW6P1.cpp Date: 11/30/2021
Student Name: Sri
----------------------------------------------
Before swap: integer1= 1, integer2= 2
After swap: integer1= 2, integer2= 1

Before swap: float1= 1.2, float2= 2.3
After swap: float1= 2.3, float2= 1.2

Before swap: char1= a, char2= b
After swap: char1= b, char2= a

Before swap: string1= Apple, string2= Banana
After swap: string1= Banana, string2= Apple
*/