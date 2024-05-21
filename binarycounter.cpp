#include<iostream>
using namespace std;
void counterx(int *p,int n)
{
    int i=0;
    while(i<n && p[i]==1)
    {
        p[i]=0;
        i++;
    }
    if(i<n)
    {
        p[i]=1;
    }
}
void display(int *p,int n)
{
    for(int i=n-1;i>=0;i--)
    cout<<p[i]<<" ";
    cout<<endl;

}
int main()
{
    int k,*a;
    cout<<"enter no of bits";
    cin>>k;
    a=(int *)malloc(k*sizeof(int));
    for(int i=0;i<k;i++)
    {
        a[i]=0;
    }
    for(int i=0;i<(1<<k);i++)
    {
        display(a,k);
        counterx(a,k);
    }
    return 0;

}