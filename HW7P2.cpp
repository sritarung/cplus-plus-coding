#include<iostream>
#include<vector>
using namespace std;


class Dog
{
    public:
        int id;
        static int cnt;

        Dog():id(++cnt){cout<<"dog #Id:"<< id<<endl;}

        Dog(const Dog& rhs): id(++cnt){cout<<"Copy constructor id= "
        <<id<<endl;}

        ~Dog(){
            cnt--;
            cout<<"destructor: id= "<<id<<endl;
        }

};

int Dog::cnt=0;

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW7P2.cpp" << " Date: 12/2/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/
    
    //rest of the code
    
    vector<Dog>X(8);
    vector<Dog>::iterator iter;
    cout<<endl;

    for(int i=0; i<8;++i){
        cout<<"X.id["<<i<<"] ="<<X[i].id<<endl;
    }

    Dog D2;
    
    iter= X.begin();
    X.insert((iter+5),D2);

    cout<<endl;

    return 0;
}

//1) Dog type vector is created and default constructor for all objects
// is called and their ids are created
//2) Ids of all dogs are printed until 8
//3) New dog object is created calling in the copy constructor for the capacity 
//of the vector which is double of original size(8)= 16. A dog object is inserted in that
//capacity.
//4) The destructor for Dog vector is called
//It starts from beginning and goes all the way till end from 1 to 16.

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW7P2.cpp Date: 12/2/2021
Student Name: Sri
----------------------------------------------
dog #Id:1
dog #Id:2
dog #Id:3
dog #Id:4
dog #Id:5
dog #Id:6
dog #Id:7
dog #Id:8

X.id[0] =1
X.id[1] =2
X.id[2] =3
X.id[3] =4
X.id[4] =5
X.id[5] =6
X.id[6] =7
X.id[7] =8
dog #Id:9
Copy constructor id= 10
Copy constructor id= 11
Copy constructor id= 12
Copy constructor id= 13
Copy constructor id= 14
Copy constructor id= 15
Copy constructor id= 16
Copy constructor id= 17
Copy constructor id= 18
destructor: id= 1
destructor: id= 2
destructor: id= 3
destructor: id= 4
destructor: id= 5
destructor: id= 6
destructor: id= 7
destructor: id= 8

destructor: id= 9
destructor: id= 11
destructor: id= 12
destructor: id= 13
destructor: id= 14
destructor: id= 15
destructor: id= 10
destructor: id= 16
destructor: id= 17
destructor: id= 18
*/