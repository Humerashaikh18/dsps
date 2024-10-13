#include <iostream>
using namespace std;
int i,n;
class search
{
    public:
    int a[10];
    int ps=0;
    void accept()
    {   
      cout<<"Enter how many elements youy want to insert:";
      cin>>n;
      for(i=0;i<n;i++)
      {
        cout<<"\n Enter "<<i+1<<" element:";
        cin>>a[i];
      }
    }
    int check(int target)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]==target)
            {
                cout<<"target found at index "<<i;	
                 ps=1;
            } 
        }
        if(ps==0)
        { 
             cout<<"\ntarget not found";
        }

    
    }

};

int main()
{
  search s;
  int target;
   s.accept();
   cout<<"\nEnter the target you want to find: ";
   cin>>target;
   s.check(target);
   return 0;
} 
