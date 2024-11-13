#include<iostream>
using namespace std;
int n,i;
class student{
    int arr[10];
    public:
    void accept();
    void display();
    void linear();
    void binary();
}s;

void student::accept()
{
    cout<<"\nEnter roll no. of"<<n<<"students:";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void student::display()
{
    cout<<"\nRoll no. of students:";
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<arr[i];
    }
  }


void student::linear(){
    int key;
    cout<<"\nEnter roll no. u want to check:";
    cin>>key;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
        break;
        }
    }
    if(i==n)
    {
        cout<<"\nnot present";
    }
    else{
        cout<<"\npresent";
    }
}

void student::binary()
{
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
    int key,low=0,high=n-1,mid;
    cout<<"\nEnter roll no. u want to check:";
    cin>>key;
    while(high>=low)
    {
        mid=(high+low)/2;
        if(arr[mid]>key)
        {
            high=mid-1;
        }
        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else{
            cout<<"\npresent";
            break;
        }
    }
    if(low>high)
    {
        cout<<"\nnot present";
    }
}

int main()
{
    int ch;
    cout<<"\nEnter no. of students:";
    cin>>n;
    do{
    cout<<"\n1.accept\n2.display\n3.linear\n4.binary";
    cout<<"\nEnter ur choice:";
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
    s.linear();
    break;
    
    case 4:
    s.binary();
    break;
   }
 }while(ch!=0);
 
  return 0;
 }
    _