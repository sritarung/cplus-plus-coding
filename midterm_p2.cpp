#include <iostream>
using namespace std;
#define __FILE__ "midterm_p2.cpp"
#define __DATE__ "11/09/2021"
#define NAME "Sri Tarun Gulumuru"

class Node 
{
    public:
        string data;
        struct Node* next;
        Node(){
            data =" ";
            next = NULL;
        }
        Node(string data){
            this->data = data;
            this->next = NULL;
        }
};

class Linkedlist {
    private:
    Node* head;
    public:
        Linkedlist() { head = NULL; }
        
        void insertNode(int n=0){
            string data;
            Node *temp = head;
            int b = n;
            if(n==0)
            {
                if(head==NULL)
                {
                    cout<<"Enter node name: ";
                    cin>>data;
                    Node *node = new Node(data);
                    head = node;
                }
                else
                {
                    while(temp->next!=NULL)
                    {
                        temp = temp->next;
                    }

                    cout<<"Enter node name: ";
                    cin>>data;
                    Node *node = new Node(data);
                    temp->next = node;
                }
            }
            else
            {
                if(head==NULL)
                {
                    cout<<"Enter node name: ";
                    cin>>data;
                    Node *node = new Node(data);
                    head = node;
                }
                else if(n==1)
                {
                    cout<<"Enter node name: ";
                    cin>>data;
                    Node *node = new Node(data);
                    node->next = head;
                    head = node;
                    cout<<"Node inserted at "<<b<<"!"<<endl;
                }
                else
                {
                    while(--n)
                    {
                        temp = temp->next;
                    }
                    cout<<"Enter node name: ";
                    cin>>data;
                    Node *node = new Node(data);
                    node->next = temp->next;
                    temp->next = node;
                    cout<<"Node inserted at "<<b<<"!"<<endl;
                }
            }
        }

        void printList(){
            Node *temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"null"<<endl;
            cout<<endl;
        }

        void printList(char t){
            Node *temp = head;
            while(temp!=NULL)
            {
                if(temp->data.find(t)!=string::npos)
                {
                    cout<<temp->data<<"->";
                }
                temp=temp->next;
            }
                cout<<"null"<<endl;
                cout<<endl;
        }
        
        void deleteNode(int n){
            Node *temp = head;
            Node *prev = head;
            if(n==1)
            {
                head = temp->next;
                delete temp;
            }
            else
            {
                while(n--)
                {
                    temp = temp->next;
                    if(n-1==0)
                    {
                        prev->next = temp->next;
                        delete temp;
                        break;
                    }
                    prev = prev->next;
                }
            }
        }
        void deleteNode(char u){
            Node *temp = head;
            while (head->data.find(u)!=string::npos)
            {
                head = head->next;
            }
            while (temp->next != NULL)
            {
                if (temp->next->data.find(u)!=string::npos)
                {
                    temp->next = temp->next->next;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
};

int main()
{
    cout<<"------------------------------------------------------------------------------\n";
    cout<<"Name: "<<NAME<<endl;
    cout<<"FILE: "<< __FILE__<<" DATE: "<<__DATE__<<endl;
    cout<<"------------------------------------------------------------------------------\n";

    Linkedlist l;

    for(int i=0; i<20; i++)
    {
        l.insertNode();
    }
    cout<<endl;
    cout<<"Printing all the nodes with the above words:\n";
    l.printList();

    cout<<"Printing all nodes that contain the letter (r):\n";
    l.printList('r');

    cout<<"Printing List after removal of a node at a specific position (12) and of all nodes that contain the letter (o):\n";
    l.deleteNode(12);
    l.deleteNode('o');
    l.printList();

    cout<<"Inserting a node containing the word 'whale' into the the 6 th node\n";
    l.insertNode(6);
    l.printList();

    return 0;
}

/***Results
------------------------------------------------------------------------------
Name: Sri Tarun Gulumuru
FILE: midterm_p2.cpp DATE: 11/09/2021
------------------------------------------------------------------------------
Enter node name: dog 
Enter node name: cat   
Enter node name: mammal
Enter node name: rat
Enter node name: lion
Enter node name: frog
Enter node name: monkey
Enter node name: tiger
Enter node name: snake
Enter node name: horse
Enter node name: mouse
Enter node name: hog
Enter node name: bat
Enter node name: deer
Enter node name: cow
Enter node name: giraffe
Enter node name: gorilla
Enter node name: shark
Enter node name: moose
Enter node name: penguin

Printing all the nodes with the above words:
dog->cat->mammal->rat->lion->frog->monkey->tiger->snake->horse->mouse->hog->bat->deer->cow->giraffe->gorilla->shark->moose->penguin->null

Printing all nodes that contain the letter (r):
rat->frog->tiger->horse->deer->giraffe->gorilla->shark->null

Printing List after removal of a node at a specific position (12) and of all nodes that contain the letter (o):
cat->mammal->rat->tiger->snake->bat->deer->giraffe->shark->penguin->null

Inserting a node containing the word 'whale' into the the 6 th node
Enter node name: whale
Node inserted at 6!
cat->mammal->rat->tiger->snake->bat->whale->deer->giraffe->shark->penguin->null
* /