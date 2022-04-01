1)
int main
{
  int x;
  int count=1;
  cin >> x;
  for(int i=0; i<x; i++)
  {
    for(int j=0; j<count; j++)
    {
      cout<<"*";
    }
    cout<<"\n";
    count*=2;
  }
  return 0;
}

2)
void vowelShift(string& s)
{
  char first;
  int firstIndex=-1;
  
  for(int i=0; i<s.length(); i++)
  {
    if(s[i]=='a' || s[i]== 'e' || s[i]== 'i' || s[i]== 'o' || s[i]== 'u')
    {
      first= s[i];
      firstIndex= i;
      break;
    }
  }

  if(firstIndex== -1) return;

  int last= firstIndex;
  int next;
  for(int i= firstIndex+1; i<s.length(); i++)
  {
    if(s[i]=='a' || s[i]== 'e' || s[i]== 'i' || s[i]== 'o' || s[i]== 'u')
    {
      next=i;
      s[last]= s[next];
      last= next;
    }
  }
  s[last]= first;
}

3)
bool interval(const vector<int> & V, const vector<int> & I)
{
  bool check=false;

  for(int i=0; i<V.size()-I.size(); i++)
  {
    check= false;
    for(int j=0; j<I.size(); j++)
    {
      if(V[i+j+1]-V[i+j]==I[j])
      {
        check=true;
      }
      else
      {
        check=false;
        break;
      }
    }
    if (check) return true;
  }
  return false;
}

4)
int main() 
{
  vector<int> V{0,2,4,5,7,9,10};
  vector<int> I{2,1,2};
  bool check= interval(V, I);
  cout<<check<< "\n";
  return 0;
}