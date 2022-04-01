#include<iostream>
#include<map>
using namespace std;

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: FinalP4.cpp" << " Date: 12/20/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    map<string, float> mp;
    map<string, float>:: iterator it;

    string S[12]= {"Apple", "Banana", "Cherry", "Date", "Fig",
    "Grape","Lemon","Lime","Kiwi","Watermelon","Rasberry","Blueberry"};


    float random;
    float ra[]={};
    srand(19);
    for(int i=0; i<12;i++){
        random=float(rand()%26);
        ra[i]= random;
        mp.insert({S[i],random});
    }

    for(it=mp.begin(); it!=mp.end(); it++){
        cout<<"Fruit:"<<it->first<<"\t"<<"Weight:"<<it->second<<endl;
    }

    for(it= mp.begin(); it!=mp.end(); it++){
        if(it->second > 10){
            it->second *=0.75;
        }
    }

    cout<<endl;
    cout<<"Printing the map after reducing the weight of each fruit by 0.75 if in excess of 10 lb: "<<endl;
    for(it=mp.begin(); it!=mp.end(); it++){
        cout<<"Fruit:"<<it->first<<"\t"<<"Weight:"<<it->second<<endl;
    }    
    
    int count=0;
    for(it=mp.begin(); it!= mp.end(); it++){
        if(it->second>10){
            count++;
        }
    }
    cout<<endl;
    cout<<"The number of fruits having weight>10 lbs are: "<<count;
    return 0;
}

/****Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: FinalP4.cpp Date: 12/20/2021
Student Name: Sri
----------------------------------------------
Fruit:Apple     Weight:22
Fruit:Banana    Weight:17
Fruit:Blueberry Weight:25
Fruit:Cherry    Weight:1
Fruit:Date      Weight:4
Fruit:Fig       Weight:8
Fruit:Grape     Weight:17
Fruit:Kiwi      Weight:8
Fruit:Lemon     Weight:16
Fruit:Lime      Weight:23
Fruit:Rasberry  Weight:1
Fruit:Watermelon        Weight:13

Printing the map after reducing the weight of each fruit by 0.75 if in excess of 10 lb:
Fruit:Apple     Weight:16.5
Fruit:Banana    Weight:12.75
Fruit:Blueberry Weight:18.75
Fruit:Cherry    Weight:1
Fruit:Date      Weight:4
Fruit:Fig       Weight:8
Fruit:Grape     Weight:12.75
Fruit:Kiwi      Weight:8
Fruit:Lemon     Weight:12
Fruit:Lime      Weight:17.25
Fruit:Rasberry  Weight:1
Fruit:Watermelon        Weight:9.75

The number of fruits having weight>10 lbs are: 6
*/