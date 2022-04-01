#include <iostream>
#include <string.h>
#include <limits>//defines max number of characters limit
using namespace std;

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW4P1.cpp" << " Date: 10/30/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );// cin ignores max number of characters until new line(\n)
    string Getty[8];
    for(int i=0; i<8; i++){
        getline(cin, Getty[i]);
    }

    int sum=0;
    int cnt[32];
   for(int i=0; i<8; i++)
    {   
       for(int j=0; j<(Getty[i]).length(); j++){
           sum+= (int)Getty[i][j];
       }
       cnt[i]= sum;
       sum=0;
    }

    for(int i=0; i<8; i++){
        cout<<"The phrase "<<i+1<<": "<<cnt[i]<<endl;
    }
 
    return 0;
}
/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW4P1.cpp Date: 10/30/2021
Student Name: Sri
----------------------------------------------
Four score and seven years ago our fathers brought forth upon this continent,
a new nation, conceived in Liberty, and dedicated to the proposition that all
men are created equal.
Now we are engaged in a great civil war, testing whether that nation, or any
nation so conceived and so dedicated, can long endure. We are met on a great
battle-field of that war. We have come to dedicate a portion of that field,
as a final resting place for those who here gave their lives that that nation
might live. It is altogether fitting and proper that we should do this.
The phrase 1: 7360
The phrase 2: 7180
The phrase 3: 2038
The phrase 4: 6959
The phrase 5: 6865
The phrase 6: 6791
The phrase 7: 7209
The phrase 8: 6612
*/
