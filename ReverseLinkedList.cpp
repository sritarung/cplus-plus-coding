#include<bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0),next(nullptr){};
    ListNode(int x): val(x),next(nullptr){};
    ListNode(int x,ListNode *next):val(x),next(next){};
};

ListNode* reverseList(ListNode* head){
    ListNode* prev=nullptr;
    while(head!=nullptr){
        ListNode* next_node= head->next;
        head->next= prev;
        prev=head;
        head= next_node;
    }
    return prev;
}

void printList(ListNode* n)
{
    while(n!=NULL){
        cout<<n->val<<" ";
        n=n->next;
    }
}

// void push(ListNode* n, int val){
//     ListNode* p;
//     p= (struct ListNode*) malloc(sizeof(struct ListNode));
//     p->val= val;
//     p->next=n->next;
//     n->next=p;
// }

void front(ListNode* head,int n)
{
    ListNode* l= new ListNode;
    l= head;
    ListNode *tmp = new ListNode;
    tmp -> val = n;
    tmp -> next = l;
    head = tmp;
}

void after(ListNode *a, int value)
{
    ListNode* p = new ListNode;
    p->val = value;
    p->next = a->next;
    a->next = p;
}

int main()
{
    ListNode* temp= new ListNode(0);
    ListNode* head= temp;

    // for(int i=1; i<5; i++){
    //     after(temp,i);
    //     temp=temp->next;
    // }

    for(int i=1; i<5; i++){
        ListNode* n= new ListNode();
        n->val= i;
        n->next= temp->next;
        temp->next=n;
        temp=temp->next;
    }

    printList(head);
    cout<<endl;
    printList(reverseList(head));
    return 0;
}
