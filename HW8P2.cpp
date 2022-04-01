#include<iostream>
#include<deque>
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
	cout << "FIle: HW8P2.cpp" << " Date: 12/2/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/
    
    //rest of the code
    deque<Dog> X(8);

    for(int i=0; i<8; i++){
        cout<<X[i].id<<" ";
    }
    cout<<endl;

    Dog d1= X.front();
    X.pop_front();

    Dog d2= X.front();
    X.pop_front();
    
    return 0;
}
//1) Dog type deque is created and default constructor for all objects
// is called and their ids are created
//2) Ids of all dogs are printed until 8
//3) Copy constructor called for the new Dog object and id 9 is created
// Destructor for dog in front is called removing dog with id 1
//4)Copy constructor called again for the new Dog object and id is assigned 9
//Once again desctructor for dog in front is called and dob with id 2 is removed
//5) The destructor for Dog deque is called
//It starts from beginning and goes all the way till end.

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW8P2.cpp Date: 12/2/2021
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
1 2 3 4 5 6 7 8
Copy constructor id= 9
destructor: id= 1
Copy constructor id= 9
destructor: id= 2
destructor: id= 9
destructor: id= 9
destructor: id= 3
destructor: id= 4
destructor: id= 5
destructor: id= 6
destructor: id= 7
destructor: id= 8
*/