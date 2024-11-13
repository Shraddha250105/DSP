#include<iostream>
using namespace std;
int n;
class target{
    int arr[10];
    int i;
    public:
    void accept();
    void display();
    void sort();
    void search();
}s;

void target::accept()
{
    cout<<"Enter elements in array:";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void target::display()
{
    cout<<"\narray elements:\n";
    for(i=0;i<n;i++)
    {
        cout<<"\t"<<arr[i];
    }
}

void target::sort(){
    int j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"\nsorted array elements:";
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<arr[i];
    }
}


void target::search()
{
    int target;
    cout<<"\nEnter target:";
    cin>>target;
    for(i=0;i<n;i++)
    {
    if(arr[i]==target)
    {
        break;
    }
     }
    if(i==n)
    {
        cout<<"\nnot present";
    }
    else
    {
        cout<<"\npresent";
    }
}
    


int main()
{
    int ch;
    cout<<"\nEnter n value:";
    cin>>n;
    do{
    cout<<"\n1.accept\n2.display\n3.sort\n4.search";
    cout<<"\n"<<"Enter ur choice:";
    cin>>ch;
    switch(ch)
    {
        case 1:
        s.accept();
        break;
        
        case 2:
        s.display();
        break;
        
        case 3:
        s.sort();
        break;
        
        case 4:
        s.search();
        break;
        
    }
  }while(ch!=0);
  return 0;
}

