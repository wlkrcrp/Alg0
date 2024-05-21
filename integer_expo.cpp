#include<iostream>
using namespace std;
int int_expo(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n%2==0)
    {
        int y=int_expo(x,n/2);
        return y*y;
    }
    else{
        return x*int_expo(x,n-1);
    }
}
int main()
{
    int x,n;
    cout<<"Enter the base val:";
    cin>>x;
    cout<<"Enter the exponent number";
    cin>>n;
    int ans= int_expo(x,n);
    cout<<"The value is"<<ans;

}