#include <iostream>
#include <math.h>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date():day(1), month(6), year(2021){}
        Date(int day, int month, int year):day(day), month(month), year(year){}
        const Date & operator=(const Date&rhs);
        int getDay() const{return day;}
        int getMonth() const{return month;}
        int getYear() const{return year;}

        void display(){
            cout<<"Day:"<<day<<endl;
            cout<<"Month:"<<month<<endl;
            cout<<"Year:"<<year<<endl;
        }

        ~Date(){}
};

class Bond{
    private:
        string name;
        float principal;
        float rate;
        Date issue;
        Date maturity;
    public:
        Bond(string n, float princ, float r, Date i, Date m):name(n), principal(princ), rate(r), issue(i), maturity(m){}
        const Bond& operator=(const Bond &rhs);
        ~Bond(){}

        int diff(){
             return maturity.getYear()-issue.getYear();}

        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Principal: "<<principal<<endl;
            cout<<"Rate: "<<rate<<endl;
        }

        void calculate(int n){
            float m_amount= principal*(pow(1+(rate/100),n));
            cout<<"The principal at maturity date is: "<<m_amount<<endl;
        }
};


int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW3P2.cpp" << " Date: 10/10/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    Date d1(06,01,2021);
    cout<<"This is the date of issue."<<endl;
    d1.display();
    cout<<endl;
    Date d2(06,01,2031);
    cout<<"This is the date of maturity."<<endl;
    d2.display();
    cout<<endl;
    Bond b("GW Bridge",1000,0.05,d1,d2);
    cout<<"This is the name, rate and principal of the bond."<<endl;
    b.display();
    int n=b.diff();
    cout<<endl;
    b.calculate(n);
    return 0;
}

const Date & Date::operator=(const Date &rhs){
    if(this!= &rhs){
        day= rhs.day;
        month= rhs.month;
        year= rhs.year;
    }
    return *this;
}

const Bond & Bond::operator=(const Bond &rhs){
    if(this!= &rhs){
        name= rhs.name;
        principal= rhs.principal;
        rate= rhs.rate;
        issue= rhs.issue;
        maturity= rhs.maturity;
    }
    return *this;
}

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW3P2.cpp Date: 10/10/2021
Student Name: Sri
----------------------------------------------
This is the date of issue.
Day:6
Month:1
Year:2021

This is the date of maturity.
Day:6
Month:1
Year:2031

This is the name, rate and principal of the bond.
Name: GW Bridge
Principal: 1000
Rate: 0.05

The principal at maturity date is: 1005.01
*/