#include<iostream>
using namespace std;
class search
{
    int a[10],cnt=0;
    int n,i,target;
    public:
    void accept()
    {
        cout<<"Enter the size of array:";
        cin>>n;
        cout<<"Enter the elements of array:";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    void searche()
    {
        cout<<"Enter Search Element";
        cin>>target;
        for(i=0;i<n;i++)
        {
            if(a[i]==target)
            {
                cout<<"Elements Found at Position "<<i;
                cnt++;
            }
        }
        if(cnt==0)
        {
            cout<<"Element not found";
        }

    }
     void display()
    {
      cout<<"Elements are:\n";
      for(i=0;i<n;i++)
      {
        cout<<a[i]<<"\t";
      }
    }
}s;
int main()
{
    int ch;
    do{
        cout<<"\n1.Accept\n2.Search\n3.Display \n4.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
        s.accept();
        break;

        case 2:
        s.searche();
        break;

        case 3:
        s.display();
        break;

        case 4:
        exit(0);

        }
    }while(ch!=0);
    return 0;
}
