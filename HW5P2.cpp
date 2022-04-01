#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
        string name;
        float price;
        Node* left;
        Node* right;
        Node* parent;
        double key;

        Node(string n, double p){
            name= n;
            price= p;
            left= NULL;
            right= NULL;
            parent= NULL;
            key= price;
        }
};

Node * Insert(Node* node, Node* temp){
    int key= temp->key;
    if(node == NULL){
        node= temp;
    }
    else if(node->key <key){
        node-> right = Insert(node->right, temp);
        node->right->parent= node;
    }
    else{
        node->left= Insert(node->left, temp);
        node->left->parent = node;
    }
    return temp;
}

void print(Node* root){
    if(root){
        cout<<"Name: "<<root->name<<" "<<"Price: "
        <<root->price<<endl;
    }
    else{
        return;
    }
    if(root->left){
        print(root->left);
    }
    if(root->right){
        print(root->right);
    }
    return;
}

int main()
{
    string Name;
	/*****************************************/
	cout << "Student Enter Name" << endl;
	cin >>ws>> Name;
    cout << "----------------------------------------------" << endl;
	cout << "FIle: HW5P2.cpp" << " Date: 11/30/2021" << endl;
	cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
	/*****************************************/

    //rest of the code
    string name;
    float price;

    Node* root= new Node("Lemon", 3.00);

    vector<string> names;
    vector<float> prices;
    names.push_back("Lemon");
    prices.push_back(3.00);

    for(int i=0; i<15; i++){
        if(i==0){
            cout<<"Please enter the name of the "<<i+1<<"st fruit: "<<endl;
            cin>>name;
            cout<<"Please enter the price of the "<<i+1<<"st fruit: "<<endl;
            cin>>price;
        }
        else if(i==1){
            cout<<"Please enter the name of the "<<i+1<<"nd fruit: "<<endl;
            cin>>name;
            cout<<"Please enter the price of the "<<i+1<<"nd fruit: "<<endl;
            cin>>price;
        }
        else if(i==2){
            cout<<"Please enter the name of the "<<i+1<<"rd fruit: "<<endl;
            cin>>name;
            cout<<"Please enter the price of the "<<i+1<<"rd fruit: "<<endl;
            cin>>price;
        }
        else{
            cout<<"Please enter the name of the "<<i+1<<"th fruit: "<<endl;
            cin>>name;
            cout<<"Please enter the price of the "<<i+1<<"th fruit: "<<endl;
            cin>>price;
        }

        names.push_back(name);
        prices.push_back(price);

        Node* node= new Node(name, price);

        Insert(root, node);
    }

    print(root);

    float sum=0.0;
    for(float i: prices){
        sum+=i;
    }

    cout<<"The average price is: "<<sum/(double)16<<endl;
    return 0;
}

/***Results
Student Enter Name
Sri
----------------------------------------------
FIle: HW5P2.cpp Date: 11/30/2021
Student Name: Sri
----------------------------------------------
Please enter the name of the 1st fruit:
Watermelon
Please enter the price of the 1st fruit: 
3
Please enter the name of the 2nd fruit: 
Banana
Please enter the price of the 2nd fruit: 
3
Please enter the name of the 3rd fruit: 
Apple
Please enter the price of the 3rd fruit: 
3
Please enter the name of the 4th fruit: 
Cherry
Please enter the price of the 4th fruit: 
3
Please enter the name of the 5th fruit: 
Mango
Please enter the price of the 5th fruit: 
5
Please enter the name of the 6th fruit: 
Pineapple
Please enter the price of the 6th fruit: 
7
Please enter the name of the 7th fruit: 
Strawberry
Please enter the price of the 7th fruit: 
6
Please enter the name of the 8th fruit: 
Guava
Please enter the price of the 8th fruit: 
2
Please enter the name of the 9th fruit: 
Blueberry
Please enter the price of the 9th fruit: 
1.5
Please enter the name of the 10th fruit: 
Avocado
Please enter the price of the 10th fruit: 
7
Please enter the name of the 11th fruit: 
Pear
Please enter the price of the 11th fruit: 
4.3
Please enter the name of the 12th fruit: 
Orange
Please enter the price of the 12th fruit: 
2.4 
Please enter the name of the 13th fruit: 
Dragonfruit
Please enter the price of the 13th fruit: 
4.5
Please enter the name of the 14th fruit: 
Muskmelon
Please enter the price of the 14th fruit: 
5.6
Please enter the name of the 15th fruit: 
Blackberry
Please enter the price of the 15th fruit: 
5
Name: Lemon Price: 3
Name: Orange Price: 2.4
Name: Blackberry Price: 5
The average price is: 4.08125
*/