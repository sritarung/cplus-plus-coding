#include<bits/stdc++.h>//used for NULL
using namespace std;

/*
struct Node{
    int data;
    struct Node* next;
}
*/

class Node{
public:
    int data;
    Node* next; 
};

void printList(Node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}

int main()
{
    Node* head= NULL;
    Node* second= NULL;
    Node* third=NULL;

    //allocate 3 nodes in the heap
    head= new Node();
    second= new Node();
    third= new Node();

    // three blocks have been allocated dynamically. 
    //head, second and third are pointers to these blocks
    head->data=1;
    head->next= second;

    second->data=2;
    second->next= third;

    third->data=3;
    third->next= NULL;

    printList(head);

    return 0;
}