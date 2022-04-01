#include <iostream>
using namespace std;
/* 
- a class is abstract if it does have at least one pure function
- we can have pointers and references to abstract classes
- if we do not override the pure virtual function in the derived class
 then, the derived class also becomes an abstract class
- an abstract class can have constructors

*/

class Base
{
    private:
        int x;
    public:
        virtual void func()=0;
        int getx(){return x;}
};

class Derived: public Base
{
    private:
        int y;
    public:
        void func() override{
            cout<<"func() called!";
        }
};

int main()
{
    Derived d;
    d.func();    
    return 0;
}