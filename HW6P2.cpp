#include<iostream>
#include <limits>//defines max number of characters limit
using namespace std;

template<class T>

class Array{
    public:
        T* arr; 
        int length;

        //default and parametrized constructors
        Array(int n=5){
            length = n;
            arr = new T[n];
        }

        //copy constructor
        Array(const Array &rhs){
            length= rhs.length;
            arr= new T[length];
            for(int i=0; i<length; i++){
                arr[i]=rhs.arr[i];
            }
        }

        //destructor
        ~Array() {delete [] arr;}
        
        //assignment operator
        Array &operator=(const Array&rhs){
            if(this!=&rhs){
                this->length= rhs.length;
                delete[] arr;
                this->arr= new T[length];
                for(int i=0; i<length; i++){
                    arr[i]= rhs.arr[i];
                }
            }
            return *this;
        } 

        // overload the index operator
        T& operator[](int i)const{
            if(0<=i && i<length)
             return arr[i];
        }

        // overload the insertion operator
        friend istream& operator>>(istream& in , Array& a){
             for(int i = 0 ; i < a.length;i++){
                 in>>a[i];
             }
             return in;
        }

        // overload extraction operator
        friend ostream& operator<<(ostream &out,Array &a){
             out<<"Elements in this object : ";
             for(int i = 0 ; i < a.length ; i++){
                 out<<a[i]<<" ";
             }
             out<<"\n";
             return out;
        }
};

int main(){

    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW6P2.cpp" << " Date: 11/30/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );// cin ignores max number of characters until new line(\n)
    Array<int> a(4);
    cout<<"Enter four integers into the array: ";
    cin>>a;
    cout<<a;

    Array<double> b(4);
    cout<<"Enter four doubles into the array: ";
    cin>>b;
    cout<<b;

    Array<char> c(4);
    cout<<"Enter four chars into the array: ";
    cin>>c;
    cout<<c;

    cout<<"Printing third element in Integer type array using overloaded index operator : "<<a[2];
    return 0;
}

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW6P2.cpp Date: 11/30/2021
Student Name: Sri
----------------------------------------------
Enter four integers into the array: 1 2 3 4
Elements in this object : 1 2 3 4 
Enter four doubles into the array: 2.3 4.3 5.4 6.5
Elements in this object : 2.3 4.3 5.4 6.5 
Enter four chars into the array: a s d f
Elements in this object : a s d f 
Printing third element in Integer type array using overloaded index operator : 3
*/