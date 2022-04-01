/*Name: Sri Tarun Gulumuru */
/* ID:24059435 */

#include<iotream>
#include<vector>
#include<string>
using namespace std;

/* 1st Answer */
int main() 
{ 
    int n;
    cout << "\n\n";
    cout << "Enter the number of rows you want in your triangle." << endl;
    cin >> n;
    cout << "\n";
    printPattern(n); 
}
void printPattern(int n) 
{ 
    int i, j; 
    for (i = 1; i <= n; i++) { 

        for (j = 1; j < i; j++) { 
            cout << " "; 
        } 
        if(i==1)
        {
          for(int k=1; k<n; k++)
          {
            cout<<"* ";
          }
        }
        for (j = 1; j <= (n * 2 - (2 * i - 1)); j++) { 
          
            if (j == 1 || j == (n * 2 - (2 * i ))){ 
                cout << "*"; 
            }
            if(i==1)
            {
             break;
            }
            else if(i==i+1){
                cout<<"";
            }
             else { 
                cout << " "; 
            } 
        } 
        cout << endl; 
    } 
} 


/* 2nd Answer */
void program()
{
 vector<int> v;
 int n;
 int l=1;
 vector<int> k{};
 while(cin>> n)
 {
   v.push_back(n);
 }
 for(int i=0; i<v.size(); i++)
 {
   l=l*2;
   for(int b=0; b<v.size(); b++)
   {
     if(v[b]%l==0)
     {
       k.clear();
     }
   }
   for(int j=0; j<v.size(); j++)
   {
     if(v[j]%l==0)
     {
       k.push_back(v[j]);
     }
   }
  }
  if(k.empty())
  {
    for (int c=0; c<v.size(); c++) 
        k.push_back(v[c]); 
  }
  for(int a=0; a<k.size(); a++)
  {
    cout<<k[a]<<" ";
  }
}


/* 3rd Answer */

struct node
{
  int data;
  node* next;
};

node* divisibleby(node* L, int d)
{
    if(d==1)
    {
      node *current = L;
      node *copy = new node;
      copy->next = NULL;
      while (current != NULL) 
      {
       copy->data = current->data;
       copy->next = current->next;
       copy = copy->next;
       current = current->next;
      }
      return copy;
    }
    node* c= new node;
    c->next= NULL;
    while(L != NULL)
    {
      if(L->data%d==0)
      {
        c->data=L->data;
        c=c->next; 
      }
      L=L->next;
    }
    if(d!=1)
    {
      return c;
    }
    
}


/* 4th Answer */
/* a) */
int max (int * A, size_t n) 
{
    if(n == 1) 
    {
      return A[0];
    }
    int highestValue = max(A, n - 1);
    if(A[n-1] > highestValue)
    {
      return A[n-1];
    } 
    else return highestValue;
}

/* b) */
bool search(int * A, size_t n, int x) 
{
    if (n == 0) 
    {
      return false;
    }
    if (A[n-1] == x)
    {
      return true;
    }
    return search(A, n-1, x);
}

/* c) */
void smallest2(int * A, size_t n, int& min, int& second) {
    if(n == 0) return;
    if (A[n-1] < min) 
    {
        second = min;
        min = A[n-1];
    }
    else if (A[n-1] < second && A[n-1] != min)
    second = A[n-1];
    smallest2(A, n-1, min, second);
}

