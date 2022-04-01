#include <iostream>
#include <math.h> 
using namespace std;

template <typename T>
class Polynomial 
{   
    private:

        int order;
        T* coefficients;
        int NumCheck(T* array, int size) const;
    public:

        Polynomial(); 
        Polynomial(int order, T defaultCoeff = 0); 
        Polynomial(int order, T* coefficients); 
        Polynomial(const Polynomial<T>& rhs); 
        Polynomial<T>& operator=(const Polynomial<T>& rhs); 
        ~Polynomial() { delete[] coefficients; } 
        template <typename L> friend ostream& operator<<(ostream& out, const Polynomial<L>& rhs);

        void SetValues(int order, T* coefficients); 
        int GetOrder() const { return this->order; } 
        int* GetCoefficients() const { return this->coefficients; } 

        // Overloaded operators
        template <typename L> friend Polynomial<L> operator+(const Polynomial<L>& lhs, const Polynomial<L>& rhs); 
        template <typename L> friend Polynomial<L> operator-(const Polynomial<L>& lhs, const Polynomial<L>& rhs);
        template <typename L> friend Polynomial<L> operator*(const Polynomial<L>& lhs, const Polynomial<L>& rhs); 
        template <typename L> friend Polynomial<L> operator*(const Polynomial<L>& lhs, const L rhs);
        template <typename L> friend Polynomial<L> operator*(const L lhs, const Polynomial<L>& rhs); 
        template <typename L> friend bool operator==(const Polynomial<L>& lhs, const Polynomial<L>& rhs); 
        T operator[](int i) const; 
        T& operator[](int i); 
        T operator()(T x); 
};

int main() {

    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: FinalP1.cpp" << " Date: 12/19/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    int coeff1[] = {-19, 1, -12, 3, 2};
    int coeff2[] = {-19, 1, -6, 0, 0, 7, 0, 2};

    Polynomial<int> P1(4, coeff1);
    Polynomial<int> P2(7, coeff2);
    Polynomial<int> P3;

    cout << "Integer Polynomials "<< endl;

    cout << "P1: " << P1 << endl;
    cout << "P2: " << P2 << endl;
    cout << "P3: " << P3 << endl;
    cout << endl;

    P3 = P1 + P2;
    cout << "P3 = P1 + P2" << endl;
    cout << "P3: " << P3 << endl;
    cout << endl;

    P3 = P2 * 5;
    cout << "P3 = P2 * 5" << endl;
    cout << "P3: " << P3 << endl;
    cout << endl;

    P3 = 5 * P2;
    cout << "P3 = 5 * P2" << endl;
    cout << "P3: " << P3 << endl;
    cout << endl;

    try {

        P2[4] = P1[2];
        cout << "P2[4] = P1[2]" << endl;
        cout << "P2: " << P2 << endl;
        cout << endl;

    }
    catch(int i) {

        cout << "Coefficient " << i << " is not there" << endl;

    }

    cout << "x = 2" << endl;
    cout << "P1(2): " << P1(2) << endl;

    cout << endl;
  

    //Floats
    float coeff3[] = {-19, 1, -12, 3, 2};
    float coeff4[] = {-19, 1, -6, 0, 0, 7, 0, 2};

    Polynomial<float> P4(4, coeff3);
    Polynomial<float> P5(7, coeff4);
    Polynomial<float> P6;

    cout<< "Float "<< endl;

    cout << "P4: " << P4 << endl;
    cout << "P5: " << P5 << endl;
    cout << "P6: " << P6 << endl;
    cout << endl;

    P6 = P4 + P5;
    cout << "P6= P4 + P5" << endl;
    cout << "P6: " << P6 << endl;
    cout << endl;

    P6 = P5 * float(5);
    cout << "P6= P5 * 5" << endl;
    cout << "P6: " << P6 << endl;
    cout << endl;

    P6 = float(5) * P5;
    cout << "P6= 5 * P5" << endl;
    cout << "P6: " << P6 << endl;
    cout << endl;

    try {

        P5[4] = P4[2];
        cout<< "P5[4] = P4[2]" << endl;
        cout<< "P5: " << P5 << endl;
        cout<< endl;

    }
    catch(int i) {

        cout << "Coefficient " << i << " does not exist!" << endl;

    }

    cout << "x = 2" << endl;
    cout << "P4(2) = " << P4(2) << endl;

    cout<< endl;

    return 0;

}

template <typename T>
int Polynomial<T>::NumCheck(T* numArray, int size) const {

    for(int i = size - 1; i >= 0; i--) {
        
        if(i == 0 && numArray[i] != 0) return 2; 
        if(numArray[i] != 0) return 3; 

    }

    return 1; 

}

template <typename T>
Polynomial<T>::Polynomial() {

    order = 0;
    coefficients = new T[order + 1];
    coefficients[order] = 1;

}

template <typename T>
Polynomial<T>::Polynomial(int order, T defaultCoeff) { 

    this->order = order;
    coefficients = new T[order + 1];
    for(int i = 0; i <= this->order; i++) coefficients[i] = defaultCoeff;

}

template <typename T>
Polynomial<T>::Polynomial(int order, T* coefficients) { 

    this->order = order;
    this->coefficients = new T[order + 1];
    for(int i = 0; i <= this->order; i++) this->coefficients[i] = coefficients[i];

}

template <typename T>
Polynomial<T>::Polynomial(const Polynomial<T>& rhs) { 

    this->order = rhs.order;
    this->coefficients = new T[this->order + 1];
    for(int i = 0; i <= this->order; i++) this->coefficients[i] = rhs.coefficients[i];

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial<T>& rhs) { 

    if(this != &rhs) {

        delete[] this->coefficients;
        this->order = rhs.order;
        this->coefficients = new T[order + 1];
        for(int i = 0; i <= this->order; i++) this->coefficients[i] = rhs.coefficients[i];

    }

    return *this;

}

template <typename L>
ostream& operator<<(ostream& out, const Polynomial<L>& rhs) { 

    switch(rhs.NumCheck(rhs.coefficients, rhs.order + 1)) {

        case 1: 
        out << 0;
        break;

        case 2: 
        out << rhs.coefficients[0];
        break;

        case 3: 
        for(int i = rhs.order; i >= 0; i--) { 

            if(rhs.coefficients[i] == 0) continue; 

            if(i == 0) { 

                if(rhs.coefficients[i] > 0) out << " + ";
                else out << " - ";
                out << abs(rhs.coefficients[i]);

            } else if(i == 1) { 

                if(rhs.coefficients[i] > 0) out << " + ";
                else out << " - ";

                if(abs(rhs.coefficients[i]) != 1) out << abs(rhs.coefficients[i]); 
                out << "x";

            } else if(i == rhs.order) {

                if(abs(rhs.coefficients[i]) != 1) out << rhs.coefficients[i]; 
                if(rhs.coefficients[i] == -1) out << "-";
                out << "x^" << i;

            } else { 

                if(rhs.coefficients[i] > 0) out << " + ";
                else out << " - ";
                    
                if(abs(rhs.coefficients[i]) != 1) out << abs(rhs.coefficients[i]); 
                out << "x^" << i;

            }

        }

        break;

    }

    return out;

}

template <typename T>
void Polynomial<T>::SetValues(int order, T* coefficients) { 

    delete[] this->coefficients;
    this->order = order;
    this->coefficients = new T[order + 1];
    for(int i = 0; i <= this->order; i++) this->coefficients[i] = coefficients[i];

}

template <typename L>
Polynomial<L> operator+(const Polynomial<L>& lhs, const Polynomial<L>& rhs) { 

    int order;
    (lhs.order >= rhs.order) ? order = lhs.order : order = rhs.order; 

    L* temp_coeff1 = new L[order + 1];
    L* temp_coeff2 = new L[order + 1];
    L* temp_coeff3 = new L[order + 1];

    for(int i = 0; i <= order; i++) { 
        temp_coeff1[i] = 0; temp_coeff2[i] = 0; 
    } 
    for(int i = 0; i <= lhs.order; i++) { 
        temp_coeff1[i] = lhs.coefficients[i]; 
    } 
    for(int i = 0; i <= rhs.order; i++) { 
        temp_coeff2[i] = rhs.coefficients[i]; 
    } 
    for(int i = 0; i <= order; i++) { 
        temp_coeff3[i] = temp_coeff1[i] + temp_coeff2[i]; 
    } 

    Polynomial<L> temp(order, temp_coeff3);
    delete[] temp_coeff1;
    delete[] temp_coeff2;
    delete[] temp_coeff3;

    return temp;

}

template <typename L>
Polynomial<L> operator-(const Polynomial<L>& lhs, const Polynomial<L>& rhs) { 

    int order;
    (lhs.order >= rhs.order) ? order = lhs.order : order = rhs.order;

    L* temp_coeff1 = new L[order + 1];
    L* temp_coeff2 = new L[order + 1];
    L* temp_coeff3 = new L[order + 1];

    for(int i = 0; i <= order; i++) { 
        temp_coeff1[i] = 0; temp_coeff2[i] = 0; 
    }
    for(int i = 0; i <= lhs.order; i++) { 
        temp_coeff1[i] = lhs.coefficients[i]; 
    }
    for(int i = 0; i <= rhs.order; i++) { 
        temp_coeff2[i] = rhs.coefficients[i]; 
    }

    for(int i = 0; i <= order; i++) { 
        temp_coeff3[i] = temp_coeff1[i] - temp_coeff2[i]; 
    }

    Polynomial<L> temp(order, temp_coeff3);
    delete[] temp_coeff1;
    delete[] temp_coeff2;
    delete[] temp_coeff3;

    return temp;

}

template <typename L>
Polynomial<L> operator*(const Polynomial<L>& lhs, const Polynomial<L>& rhs) { 

    Polynomial<L> product(lhs.order + rhs.order);

    for(int i = 0; i <= lhs.order; i++) { 

        for(int j = 0; j <= rhs.order; j++) {
            product.coefficients[i + j] += lhs.coefficients[i] * rhs.coefficients[j];

        }

    }
        
    return product; 

}

template <typename L>
Polynomial<L> operator*(const Polynomial<L>& lhs, const L rhs) { 

    int order = lhs.order;
    L* temp_coeff = new L[order + 1];
    for(int i = 0; i <= order; i++) { 
        temp_coeff[i] = lhs.coefficients[i] * rhs; 
    }

    Polynomial<L> temp(order, temp_coeff);
    delete[] temp_coeff;

    return temp;

}

template <typename L>
Polynomial<L> operator*(const L lhs, const Polynomial<L>& rhs) {

    int order = rhs.order;
    L* temp_coeff = new L[order + 1];
    for(int i = 0; i <= order; i++) { 
        temp_coeff[i] = rhs.coefficients[i] * lhs; 
    }

    Polynomial<L> temp(order, temp_coeff);
    delete[] temp_coeff;

    return temp;
  
} 

template <typename L>
bool operator==(const Polynomial<L>& lhs, const Polynomial<L>& rhs) { 

    if(lhs.order != rhs.order) return false;

    int i = 0;

    while(i <= lhs.order || i <= rhs.order) {

        if(lhs.coefficients[i] != rhs.coefficients[i]) return false;
        i++;

    }

    return true;

}

template <typename T>
T Polynomial<T>::operator[](int i) const { 

    if(i <= 0 || i > this->order + 1) throw i; 
    return this->coefficients[(this->order + 1) - i]; 
}

template <typename T>
T& Polynomial<T>::operator[](int i) { 

    if(i <= 0 || i > this->order + 1) throw i; 
    return this->coefficients[(this->order + 1) - i]; 

}

template <typename T>
T Polynomial<T>::operator()(T x) {

    T res = 0;
    for(int i = this->order; i >= 0; i--) 
        res += this->coefficients[i] * pow(x, i);

    return res;

}

/****Results
Student Enter Name
Sri Tarun Gulumuru
----------------------------------------------
FIle: FinalP1.cpp Date: 12/19/2021
Student Name: Sri
----------------------------------------------
Integer Polynomials
P1: 2x^4 + 3x^3 - 12x^2 + x - 19
P2: 2x^7 + 7x^5 - 6x^2 + x - 19
P3: 1

P3 = P1 + P2
P3: 2x^7 + 7x^5 + 2x^4 + 3x^3 - 18x^2 + 2x - 38

P3 = P2 * 5
P3: 10x^7 + 35x^5 - 30x^2 + 5x - 95

P3 = 5 * P2
P3: 10x^7 + 35x^5 - 30x^2 + 5x - 95

P2[4] = P1[2]
P2: 2x^7 + 7x^5 + 3x^4 - 6x^2 + x - 19

x = 2
P1(2): -9

Float
P4: 2x^4 + 3x^3 - 12x^2 + x - 19
P5: 2x^7 + 7x^5 - 6x^2 + x - 19
P6: 1

P6= P4 + P5
P6: 2x^7 + 7x^5 + 2x^4 + 3x^3 - 18x^2 + 2x - 38

P6= P5 * 5
P6: 10x^7 + 35x^5 - 30x^2 + 5x - 95

P6= 5 * P5
P6: 10x^7 + 35x^5 - 30x^2 + 5x - 95

P5[4] = P4[2]
P5: 2x^7 + 7x^5 + 3x^4 - 6x^2 + x - 19

x = 2
P4(2) = -9
*/