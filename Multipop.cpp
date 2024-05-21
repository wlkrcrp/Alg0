#include<iostream>
using namespace std;
typedef struct stack{
    int *a;
    int top;
    int size;
}stack;
void init(stack * s,int n)
{
    s->size=n;
    s->top=-1;
    s->a=new int[s->size];
}
bool isempty(stack * s)
{
        return (s->top==-1);
}
bool isfull(stack *s)
{
    return (s->top==s->size-1);
}
void push(stack * p,int item)
{
    if(isfull(p)==1)
    {
        cout<<"overflow";

    }
    else{
        p->a[++p->top]=item;
    }
}
int pop(stack * s1)
{
    if(isempty(s1))
    {
        cout<<"underflow";
    }
    else 
    {
        int item=s1->a[s1->top--];
        return item;
    }
}
void multipop(stack * s1,int t1)
{
    int item;
    while(!isempty(s1)&&t1>0)
    {
        item=pop(s1);
        t1--;
        cout<<"the popped ele is : "<<item<<endl;
    }
}
int main()
{
    stack s1;
    int n,y,t1;
    cout<<"Enter size:";
    cin>>n;
    init(&s1,n);
    cout<<"Push the elements ";
    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<"Element plz:"<<endl;
        cin>>y;
        push(&s1,y);
    }
    cout<<"How many times you want to pop elements";
    cin>>t1;
    multipop(&s1,t1);
    return 0;

    

}