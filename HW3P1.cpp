#include<iostream>
using namespace std;

class Animal{
    private:
        double weight;
        int age;
    public:
        Animal():weight(130.0),age(18){
            cout<<"Default constructor for animal"<<endl;
        }

        Animal(double weight, int age):weight(weight), age(age){
            cout<<"Parametrized constructor for animal"<<endl;
        }

        const Animal & operator=(const Animal &rhs);

        void eat(){
            cout<<"I can eat"<<endl;
        }

        void sleep(){
            cout<<"I can sleep"<<endl;
        }

        void showData(){
            cout<<"Weight: "<<weight;
            cout<<" Age: "<<age<<endl;
        }

        ~Animal(){
            cout<<"Destructor for animal"<<endl;
        }
};

class Dog: public Animal{
    private:
        string species;
    public:
        Dog():Animal(), species("Golden Retriever"){
            cout<<"Default constructor for dog"<<endl;
        }

        Dog(double weight, int age, string species):Animal(weight, age), species(species){
            cout<<"Parameterized constructor for dog"<<endl;
        }

        void showData(){
            cout<<"I am a dog of species: "<<species<<endl;
        }

        ~Dog(){
            cout<<"Destructor for dog"<<endl;
        }

};

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW3P1.cpp" << " Date: 10/10/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    Animal a1(40, 5);
    cout<<"Animal a1:"<<endl;
    a1.showData();
    cout<<endl;
    Animal a2;
    cout<<"Animal a2:"<<endl;
    a2.showData();
    cout<<endl;
    cout<<"Making Animal a2= a1"<<endl;
    a2=a1;
    cout<<endl;
    cout<<"Animal a2:"<<endl;
    a2.showData();
    cout<<endl;
    Dog d1(50, 10, "Pug");
    cout<<"Dog d1:"<<endl;
    d1.eat();
    d1.sleep();
    d1.showData();
    cout<<endl;
    return 0;
}

const Animal & Animal::operator=(const Animal &rhs){
    cout<<"Entering an Assigment operator"<<endl;
    if(this!= &rhs){
        weight = rhs.weight;
        age = rhs.age;
    }
    return *this;
}

/***Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: HW3P1.cpp Date: 10/10/2021
Student Name: Sri
----------------------------------------------
Parametrized constructor for animal
Animal a1:
Weight: 40 Age: 5

Default constructor for animal
Animal a2:
Weight: 130 Age: 18

Making Animal a2= a1
Entering an Assigment operator

Animal a2:
Weight: 40 Age: 5

Parametrized constructor for animal
Parameterized constructor for dog
Dog d1:
I can eat
I can sleep
I am a dog of species: Pug

Destructor for dog
Destructor for animal
Destructor for animal
Destructor for animal
*/