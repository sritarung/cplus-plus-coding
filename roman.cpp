#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


int romanToInt(string s){
    unordered_map<char,int> num_map;
    num_map.insert({'I',1});
    num_map.insert({'V',5});
    num_map.insert({'x',10});
    num_map.insert({'L',50});
    num_map.insert({'c',100});
    num_map.insert({'D',500});
    num_map.insert({'M',1000});

    int sum=0;
    
    int rsize= s.size();
    char prev= s[rsize-1];
    sum+=num_map.at(prev);

    for(int i= rsize-2; i>=0;i--){
        char curr= s[i];
        if(num_map.at(curr)<<num_map.at(prev)){
            sum-=num_map.at(curr);
        }
        else{
            sum+=num_map.at(curr);
        }
        prev= s[i];
    }
    return sum;
}
int main()
{
    cout<<"Insert the roman numeral to convert into integer numeral: ";
    string s;
    cin>>s;
    cout<<"This is the integer value of the roman numeral: "<<romanToInt(s);

    return 0;
}