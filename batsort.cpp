#include<iostream>
using namespace std;
class sort{
    int *arr;
    int size;
    void append();
    int *batchers(int start,int n);
    int *batcher(int *u,int *v,int m,int n);
    void display(int *s,int size);
    public:
    sort(int size){
        this->size=size;
        arr= new int[size];
        append();
        int *s=batchers(0,size);
        display(s,size);
    }
};
int * sort :: batchers(int start,int n)
{   int *s;
    if(n>1)
    {   
        int *u=batchers(start,n/2);
        int *v=batchers(start+n/2,n-n/2);
        s=batcher(u,v,n/2,n-n/2);
        delete []u;
        delete []v;
    }
    else{
        s=new int[1];
        s[0]=arr[start];
    }
    return s;
   
}
int* sort::batcher(int *u,int*v,int m,int n)
{
    int  *s;
    if(m==0&&n==0)
    return NULL;
    else if(m==0){
        s=new int[n];
    for(int i=0;i<n;i++)
        {
            s[i]=v[i];
        }
    }
     else if(n==0){
        s=new int[m];
    for(int i=0;i<m;i++)
        {
            s[i]=u[i];
        }
    }
    else if(m==1 && n==1){
        s=new int[2];
        s[0]=min(u[0],v[0]);
        s[1]=max(u[0],v[0]);
    }
    else
    {
        int *ou=new int[(m+1)/2];
        int k=0;
        for(int i=0;i<m;i=i+2)
        {
            ou[k++]=u[i];
        }
        int *ov=new int[(n+1)/2];
         k=0;
        for(int i=0;i<n;i=i+2)
        {
            ov[k++]=v[i];
        }
        int *a=batcher(ou,ov,(m+1)/2,(n+1)/2);
        delete []ou;
        delete []ov;
        int *eu=new int[m/2];
         k=0;
        for(int i=1;i<m;i=i+2)
        {
            eu[k++]=u[i];
        }
        int *ev=new int[(n)/2];
         k=0;
        for(int i=1;i<n;i=i+2)
        {
            ev[k++]=v[i];
        }
        int *b=batcher(eu,ev,m/2,n/2);
        delete []eu;
        delete []ev;
        int c;
        if(m%2==0&&n%2==0)
        {
            c=(m/2)+(n/2)-1;

        }
        else{
            c=(m/2)+(n/2);
        }
        k=0;
        s=new int[m+n];
        s[k++]=a[0];
        for(int i=1;i<=c;i++)
        {
            s[k++]=min(a[i],b[i-1]);
            s[k++]=max(a[i],b[i-1]);
        }
        if(m%2==0 && n%2==0)
        {
            s[k++]=b[(m/2)+(n/2)-1];
        }
        else if(m%2!=0 && n%2!=0)
        {
            s[k++]=a[(m/2)+(n/2)+1];
        }
        delete []a;
        delete []b;
    }
    return s;
}
void sort::display(int *s,int size)
{
    for(int i=0;i<size;i++)
    cout<<s[i]<<" ";
}
void sort :: append(){
    for(int i=0;i<size;i++)
    {
        cout<<"Input: "<<i+1<<" ";
        cin>>arr[i];
    }
}
int main()
{
    int size;
    cout<<"Enter the size ";
    cin>>size;
    sort obj(size);
    return 0;
}