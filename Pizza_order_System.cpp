#include<iostream>
using namespace std;
int n,i,r=-1,f=-1,price;
class pizza{
    int q,cost;
    string name,add;
    public:
    void accept_order();
    void serve_order();
    void display_order();
    void current_order();
    
}p[100];

//accept order
void pizza::accept_order()
{
    //queue is full
    if((f==0 && r==n-1)||f==r+1)
    {
        cout<<"\nAll orders are booked:";
    }
    //accept first order
    else if(f==-1 && r==-1)
    {
        f=0,r=0;
        cout<<"\nCongratulation!!!";
        cout<<"This is our todays first order";
        cout<<"\n-you win Rs.20 discount-";
        cout<<"\nEnter name,address and quantity:";
        cin>>p[r].name>>p[r].add>>p[r].q;
        cost=(p[r].q*price)-20;
        cout<<"\nquantity="<<p[r].q<<"\n!..Bill..!";
        cout<<"\n"<<p[r].q<<"*"<<price<<"-"<<"20"<<"="<<"Rs."<<cost;
        cout<<"\nyour order is on "<<r+1<<" position";
     }
    else{
        r=(r+1)%n;
        cout<<"\nEnter name,address and quantity:";
        cin>>p[r].name>>p[r].add>>p[r].q;
        cost=(p[r].q*price);
        cout<<"\nquantity="<<p[r].q<<"\n!..Bill..!";
        cout<<"\n"<<p[r].q<<"*"<<price<<"="<<"Rs."<<cost;
        cout<<"\nyour order is on "<<r+1<<" position";
     }
    }

//serve order
void pizza::serve_order()
{
   
if (f == -1 && r == -1)
    {
        cout << "No orders to serve!" << endl;
        return;
    }

    // Serve the current order
    cout << "Serving Order:" << endl;
    cout << "Name: " << p[f].name << endl;
    cout << "Address: " << p[f].add << endl;
    cout << "Quantity: " << p[f].q << endl;

    // display last order
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % n;
    }
}

//display order
void pizza::display_order()
{
if (f == -1 && r == -1)//queue empty
    {
        cout << "No orders!" << endl;
        return;
    }

    cout << "All Orders in the Queue:" << endl;
    int i = f;
    while (i != r)
    {
        cout << "Name: " << p[i].name << ", Address: " << p[i].add << ", Quantity: " << p[i].q << endl;
        i = (i + 1) % n;
    }
    // Display the last order (f==r)
    cout << "Name: " << p[r].name << ", Address: " << p[r].add << ", Quantity: " << p[r].q << endl;
}

//display current order
void pizza::current_order()
{  
    //display peak order
    if(f==-1 && r==-1)
    {
        cout<<"\n--Order is not recived yet--";
    }
    else{
        cout << "Name: " << p[f].name << ", Address: " << p[f].add << ", Quantity: " << p[f].q << endl;
    }
}



int main()
{   int ch;
    cout<<"enter total no. of orders:";
    cin>>n;
    cout<<"\nEnter price of each pizza==";
    cin>>price;
    do{
    cout<<"\n1.Accept Order\n2.Serve Order\n3.Display Order\n4.Current Order\n";
    cout<<"\nEnter Ur Choice:\n";
    cin>>ch;
    switch(ch)
    {
        case 1:
        p[i].accept_order();
        break;
        
        case 2:
        p[i].serve_order();
        break;
        
        case 3:
        p[i].display_order();
        break;
        
        case 4:
        p[i].current_order();
        break;
    }
    }while(ch!=0);
return 0;
}