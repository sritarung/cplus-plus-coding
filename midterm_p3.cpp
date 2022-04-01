#include<iostream>
using namespace std;
#define __FILE__ "midterm_p3.cpp"
#define __DATE__ "11/09/2021"
#define NAME "Sri Tarun Gulumuru"

template<class T>

class Array
{
    private:
        T * pType;
        int  itsSize;
    public:
     //constructors
        Array(int itssize = 5){
            itsSize= itssize;
            pType= new T[itsSize];
        };

        Array(const Array &rhs){
            itsSize= rhs.itsSize;
            pType= new T[itsSize];

            for(int i=0; i<itsSize; i++)
                pType[i]= rhs.pType[i];
        }

     //destructor
        ~Array( ) {delete [] pType;}  

     //operators
        Array& operator=(const Array&rhs){
            if(this!= &rhs){
                this->itsSize= rhs.itsSize;
                delete[] pType;
                this->pType= new T[itsSize];
                for(int i=0; i<itsSize; i++)
                    pType[i]= rhs.pType[i];
            }
            return *this;
        }

        T & operator[](int offSet){
            if( 0<=offSet && offSet< itsSize){
                return pType[offSet];
            }
        }

        const T& operator[](int offSet) const{
            if( 0<=offSet && offSet< itsSize){
                return pType[offSet];
            }
            return pType[0];
        }

     // accessors
        int GetitsSize() const{ 
            return itsSize; 
        }
     
     // friend function
        friend ostream& operator<< (ostream& out, const Array<T>& rhs){
            for(int i=0; i<rhs.GetitsSize(); i++){
                out<< rhs[i]<<", ";
            }
            return out;
        }
     
        void operator++(){
            for (int i = 0; i < itsSize; i++)
                pType[i] = pType[i]++;
        }               

};

int main()
{
    cout<<"------------------------------------------------------------------------------\n";
    cout<<"Name: "<<NAME<<endl;
    cout<<"FILE: "<< __FILE__<<" DATE: "<<__DATE__<<endl;
    cout<<"------------------------------------------------------------------------------\n";

    int N=10;
    Array<int> X (N); 
    Array<float> Y(N);
    Array<char> C(N);

    for (int i = 0; i < N; i++)
    {
        X[i] = i * 2;
        Y[i] = i * 2.0;
        C[i] = 97 + i;
    }

    cout<<"Here are the arrays of the various t types:int, float, char :: "<<endl;
    cout<<"Array<int> X (N): "<<X<<endl;
    cout<<"Array<float> Y(N): "<<Y<<endl;
    cout<<"Array<char> C(N): "<<C<<endl;

    int value= X[4];
    cout<<"Value of X at position 4: "<<value<<endl;

    Y[5]= Y[6]+Y[7];
    cout<<"Y[5]: Y[6]+Y[7] = "<<Y[5]<<endl;

    for(int i=0; i<N-1; i++){
        Y[i]= 3.1*Y[i];
    }
    cout<<"The new Y[i] after each element of the array is multiplied by scalar of 3.1: "<<endl;
    cout<<"Y[i]: "<<Y<<endl;

    return 0;
}

/***Results
------------------------------------------------------------------------------
Name: Sri Tarun Gulumuru
FILE: midterm_p3.cpp DATE: 11/09/2021
------------------------------------------------------------------------------
Here are the arrays of the various t types:int, float, char ::
Array<int> X (N): 0, 2, 4, 6, 8, 10, 12, 14, 16, 18,
Array<float> Y(N): 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 
Array<char> C(N): a, b, c, d, e, f, g, h, i, j,
Value of X at position 4: 8
Y[5]: Y[6]+Y[7] = 26
The new Y[i] after each element of the array is multiplied by scalar of 3.1:
Y[i]: 0, 6.2, 12.4, 18.6, 24.8, 80.6, 37.2, 43.4, 49.6, 18,
 * /