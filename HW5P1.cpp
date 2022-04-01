#include<iostream>
using namespace std;

struct Node{
    int data;
    string car;
    struct Node* next;
};

struct Node* top;
void push(int data){
    struct Node* temp;
    temp = new Node();
    if(!temp){
        exit(1);
    }
    temp->data=data;
    temp->next=top;
    top=temp;
}
void push(string car){
    struct Node* temp;
    temp = new Node();
    if(!temp){
        exit(1);
    }
    temp->car=car;
    temp->next=top;
    top=temp;
}
int Empty(){
    return top==NULL;
}


void pop(int data){
    struct Node* temp;
    if(top==NULL){
        exit(1);
    }
    else{
        temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
}
void pop(string car){
    struct Node* temp;
    if(top==NULL){
        exit(1);
    }
    else{
        temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
}

void display(){
    struct Node* temp;
    if(top == NULL){
        exit(1);
    }
    else{
        temp =top;
        while(temp!=NULL){
            if(temp->data){
                cout<<temp->data<<"|";
                temp=temp->next;
                
            }
            else{
                cout<<temp->car<<"|";
                temp=temp->next;
            }

        }
    }
}

int main(){
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW5P1.cpp" << " Date: 11/30/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    string model, owner, answer;
    float price;
    cout<<"Enter Car Model (BMW,Cadillac,Toyota): "<<endl;
    cin>>model;
    cout<<"Enter Car Price ($2500 - $12,500): "<<endl;
    cin>>price;
    cout<<"Enter Car Owner's name: "<<endl;
    cin>>owner;
    push(model);
    push(price);
    push(owner);
    display();
    cout<<endl;
    cout<<endl;
    cout<<"Another list?(Y/N): "<<endl;
    cin>>answer;
    while(answer =="Y"){
        cout<<"Enter Car Model (BMW,Cadillac,Toyota): "<<endl;
        cin>>model;
        cout<<"Enter Car Price ($2500 - $12,500): "<<endl;
        cin>>price;
        cout<<"Enter Car Owner's name: "<<endl;
        cin>>owner;
        push(model);
        push(price);
        push(owner);
        cout<<endl;       
        display();
        cout<<endl;
        cout<<"Another list?(Y/N): "<<endl;
        cin>>answer;
        if(answer=="N"){break;}   
    }
    if(answer=="N"){
        if(price<2500||price>12500){
            pop(price);
            pop(owner);
            pop(model);
        }
        cout<<"Updated List: "<<endl;
        display();
    }
    
    return 0;
}

/***Results
Student Enter Name
Sri
----------------------------------------------
FIle: HW5P1.cpp Date: 11/30/2021
Student Name: Sri
----------------------------------------------
Enter Car Model (BMW,Cadillac,Toyota): 
BMW
Enter Car Price ($2500 - $12,500): 
2750
Enter Car Owner's name: 
Saroja
Saroja|2750|BMW|

Another list?(Y/N):
Y
Enter Car Model (BMW,Cadillac,Toyota): 
Cadillac
Enter Car Price ($2500 - $12,500): 
5750
Enter Car Owner's name: 
Tarun

Tarun|5750|Cadillac|Saroja|2750|BMW|
Another list?(Y/N):
Y
Enter Car Model (BMW,Cadillac,Toyota): 
Toyota
Enter Car Price ($2500 - $12,500): 
12000
Enter Car Owner's name: 
Rose 

Rose|12000|Toyota|Tarun|5750|Cadillac|Saroja|2750|BMW|
Another list?(Y/N):
N
Updated List: 
Rose|12000|Toyota|Tarun|5750|Cadillac|Saroja|2750|BMW|
*/