#include <iostream>
#include<string.h>
using namespace std;


void reverseStr(string &str){
    int size= str.length();
    string temp;
    for (int i=size-1; i>=0; i--){
        temp.push_back(str[i]);
    }
    str= temp;
}

bool isPalindrome(string &str){
    string temp= str;
    reverseStr(str);
    if(str == temp){
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: palindrome.cpp" << " Date: 09/29/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    if(argc>1){
        string str2= argv[1];
        cout<<"The inputted string is a palindrome: "<<boolalpha<<isPalindrome(str2);
    }
    else
        cout<<"There is no inputted string in command line to check if it is a palindrome.";
    
    return 0;
}

/***Results
PS C:\Users\srita\Desktop\C++> g++ palindrome.cpp -o palindrome
PS C:\Users\srita\Desktop\C++> .\palindrome madam
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: palindrome.cpp Date: 09/29/2021
Student Name: Sri
----------------------------------------------
The inputted string is a palindrome: true
*/