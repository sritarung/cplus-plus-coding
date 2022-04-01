#include <iostream>
#include <math.h>
using namespace std;
#define __FILE__ "midterm_p1.cpp"
#define __DATE__ "11/09/2021"
#define NAME "Sri Tarun Gulumuru"


class Poly{
    private:
        int order;
        int *coeff;
    public:
        Poly(){
            order=0;
            coeff= new int[1];
            coeff[0]=1;
        }

        Poly(int Order , int Default = 1){
            this->order= Order;
            coeff = new int[Order+1]{Default};
        }

        Poly(int Order, int *Coeff){
            this->order= Order;
            this->coeff= new int[Order+1];
            for(int i=0; i<Order+1; i++){
                this->coeff[i]= Coeff[i];
            }
        }

        ~Poly(){ 
            delete []coeff; 
        }

        Poly(const Poly &rhs){
            this->order= rhs.order;
            this->coeff= new int[order+1];
            for(int i=0; i<order+1; i++){
                coeff[i]= rhs.coeff[i];
            }
        }

        void set(){
            for(int i=0; i<=order; i++){
                cout<<"Please give coefficient of X^"<<i<<": ";
                cin>>coeff[i];
            }
        }

        void set(int coeff[], int size){
            for(int i=0; i<size; i++){
                this->coeff[i]= coeff[i];
            }
        }

        int getOrder( )const{
            return order;
        }

        int * get( )const{
            return coeff;
        }

        Poly operator+(const Poly &rhs){
            int max;
            if(order>rhs.order){
                max= order;
            }
            else{
                max= rhs.order;
            }
            Poly x(max);
            int i;
            for(i=0;i<= order&& i<=rhs.order; i++){
                x.coeff[i] = this->coeff[i] + rhs.coeff[i];
            }
            while(i<=order){
                x.coeff[i] = this->coeff[i];
                i++;
            }
            while(i<=rhs.order){
                x.coeff[i] = rhs.coeff[i];
                i++;
            }
            return x;
        }

        Poly operator-(const Poly &rhs){
            int max;
            if(order>rhs.order){
                max= order;
            }
            else{
                max= rhs.order;
            }
            Poly x(max);
            int i;
            for(i=0;i<= order&& i<=rhs.order; i++){
                x.coeff[i] = this->coeff[i] - rhs.coeff[i];
            }
            while(i<=order){
                x.coeff[i] = this->coeff[i];
                i++;
            }
            while(i<=rhs.order){
                x.coeff[i] = -rhs.coeff[i];
                i++;
            }
            return x;
        }

        Poly operator*(const Poly &rhs){
            Poly x(order+rhs.order, 0);
            for(int i=0; i<=order; i++){
                for(int j=0; j<=rhs.order; j++){
                    x.coeff[i+j]+= coeff[i]*rhs.coeff[j];
                }
            }
            return x;
        }

        Poly operator*( const int scale){
            Poly x(order);
            for(int i=0; i<=order; i++)
                x.coeff[i] = scale*coeff[i];
            return x;
        }

        friend Poly operator*(const int scale,const Poly &rhs){
            Poly x(rhs.order);
            for(int i=0; i<=rhs.order; i++){
                x.coeff[i] = scale*rhs.coeff[i];
            }
            return x;
        }

        bool operator==(const Poly &rhs){
            if(order != rhs.order) return false;
            for(int i=0;i<order+1; i++){
                if(this->coeff[i] != rhs.coeff[i]) return false;
            }
            return true;
        }

        const int & operator[](int I)const{
            return coeff[I];
        }

        int & operator[](int n){
            return coeff[n];
        }

        int operator()(int X){
            int temp=0;
            for(int i=0; i<= order; i++){
                temp+= pow(X,i)*coeff[i];
            }
            return temp;
        }

        friend ostream & operator<<(ostream & Out, const Poly &rhs){
            for(int i=rhs.order; i>=0; i--)
            {
                if(rhs.coeff[i]==0) continue;
                if(i==1)
                {
                    if(rhs.coeff[i]<0)
                        Out<<rhs.coeff[i]<<"X ";
                    else
                        Out<<"+ "<<rhs.coeff[i]<<"X ";
                }
                else if(i==0){
                    if(rhs.coeff[i]<0)
                        Out<<rhs.coeff[i];
                    else
                        Out<<"+ "<<rhs.coeff[i];
                }
                else if(i==rhs.order || rhs.coeff[i]<0)
                {
                    Out<<rhs.coeff[i]<<"X^"<<i<<" ";
                }
                else{
                    Out<<"+ "<<rhs.coeff[i]<<"X^"<<i<<" ";
                }  
            }
            Out<<endl;
            return Out;
        }

        Poly& operator=(const Poly & rhs){
            
            this->order = rhs.order;
            this->coeff = new int[order+1];
            for(int i=0; i<order+1; i++)
            coeff[i]=rhs.coeff[i];
            return *this;
        }
};

int main()
{
    cout<<"------------------------------------------------------------------------------\n";
    cout<<"Name: "<<NAME<<endl;
    cout<<"FILE: "<< __FILE__<<" DATE: "<<__DATE__<<endl;
    cout<<"------------------------------------------------------------------------------\n";


    int f[] = {-19, 1, -12, 3, 2};
    Poly P1(4);
    P1.set(f, 5);
    cout<<"P1: \n";
    cout<<P1<<endl;

    int g[] = {-19, 1, -6, 0, 0, 7, 0, 2};
    Poly P2(7);
    P2.set(g, 8);
    cout<<"P2: \n";
    cout<<P2<<endl;

    Poly P3;
    P3 = P1 + P2;
    cout<<"P3: P1+P2: \n";
    cout<<P3<<endl;
    cout<<"P3: P2-P1: \n";
    P3 = P2 - P1;
    cout<<P3<<endl;
    P3 = P1*P2;
    cout<<"P3: P1*P2: \n";
    cout<<P3<<endl;
    P3 = P1*10;
    cout<<"P3: P1*10: \n";
    cout<<P3<<endl;
    P3 = 10*P1;
    cout<<"P3: 10*P1: \n";
    cout<<P3<<endl;
    bool flag = (P1==P2);
    cout<<"bool flag = (P1==P2): \n";
    cout<<boolalpha<<flag<<endl;
    cout<<endl;

    P1[3] = P2[5];
    cout<<"assign the 5 th coefficient of P2 to 3 rd coefficient of P1: \n";
    cout<<P1<<endl;

    int X = 5;
    int Z = P1(X); 
    cout<<"Evaluate the polynomial for input X=5: \n";
    cout<<Z<<endl;
    cout<<endl;

    cout<<"The displayed polynomial for P2 should be printed as follows: \n";
    cout<<P2<<endl;

    return 0;
}

/***Results
------------------------------------------------------------------------------
Name: Sri Tarun Gulumuru
FILE: midterm_p1.cpp DATE: 11/09/2021
------------------------------------------------------------------------------
P1:
2X^4 + 3X^3 -12X^2 + 1X -19

P2:
2X^7 + 7X^5 -6X^2 + 1X -19

P3: P1+P2:
2X^7 + 7X^5 + 2X^4 + 3X^3 -18X^2 + 2X -38

P3: P2-P1:
2X^7 + 7X^5 -2X^4 -3X^3 + 6X^2

P3: P1*P2:
4X^11 + 6X^10 -10X^9 + 23X^8 -122X^7 -5X^6 -149X^5 + 37X^4 -75X^3 + 343X^2 -38X + 361

P3: P1*10:
20X^4 + 30X^3 -120X^2 + 10X -190

P3: 10*P1:
20X^4 + 30X^3 -120X^2 + 10X -190

bool flag = (P1==P2):
false

assign the 5 th coefficient of P2 to 3 rd coefficient of P1:
2X^4 + 7X^3 -12X^2 + 1X -19

Evaluate the polynomial for input X=5:
1810

The displayed polynomial for P2 should be printed as follows:
2X^7 + 7X^5 -6X^2 + 1X -19
*/