/*Friend Function:
-A friend function can access both the private
and protected members of the class by declaring
the friend function within the body of the class.

-Operating with the objects of two different classes
is more meaningful use of friend functions.

-When a class becomes the friend class, all members
of friend class becomes friend functions. Also all
members of friend class are accessed by the function.
However, the function that does not have friend declared
can't access the other class even if it is a friend to 
other class and the other class is using it.

*/

#include <iostream>
using namespace std;

class ClassB;

class ClassA
{
    public:
        ClassA(): numA(12) {}
        friend int add(ClassA,ClassB);

    private:
        int numA;

        
};

class ClassB
{
    private:
        int numB;   

    public:
        ClassB(): numB(1) {}
        friend int add(ClassA,ClassB);
};

int add(ClassA objectA,ClassB objectB)
{
    return (objectA.numA+objectB.numB);
}

int main()
{
    ClassA objectA;
    ClassB objectB;
    cout<<"Sum: "<<add(objectA,objectB);
    return 0;
}