#include <iostream>
using namespace std;


int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW4P2.cpp" << " Date: 10/30/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    string Getty[8] = {
        "Four score and seven years ago our fathers brought forth upon this continent,",
        "a new nation, conceived in Liberty, and dedicated to the proposition that all",
        "men are created equal.",
        "Now we are engaged in a great civil war, testing whether that nation, or any",
        "nation so conceived and so dedicated, can long endure. We are met on a great",
        "battle-field of that war. We have come to dedicate a portion of that field,",
        "as a final resting place for those who here gave their lives that that nation",
        "might live. It is altogether fitting and proper that we should do this."
    };

    int hist[11]={};
    int counter=0;
 
    for(int i=0; i<8; i++){
        for(int j=0; j<(Getty[i]).size(); j++){
            if(Getty[i][j]==' '|Getty[i][j]==','|Getty[i][j]=='.'|Getty[i][j]=='-'){
                if (counter>10){
                    counter=0;
                }
                hist[counter]++;
                counter=0;    
            }
            else{
                counter++;
            }
        }
        hist[counter]++;
        counter=0;
    }    
    
    for(int i=1; i<11; i++){
        cout<<"The "<<i<<" letter word:";
        for(int j=0; j<=hist[i]; j++){
            cout<<"*";
        }
        cout<<hist[i]<<endl;
    }
    return 0;
}
/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW4P2.cpp Date: 10/30/2021
Student Name: Sri
----------------------------------------------
The 1 letter word:******5
The 2 letter word:*******************18
The 3 letter word:**********************21
The 4 letter word:******************17
The 5 letter word:*****************16
The 6 letter word:*********8
The 7 letter word:***********10
The 8 letter word:**1
The 9 letter word:******5
The 10 letter word:**1
*/