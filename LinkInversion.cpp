#include <iostream> 
using namespace std; 
#define MAX 100 
class BST; 
class node  
{ 
    int data; 
    unsigned tag:1; 
    node *left; 
    node *right; 
    node(int item); 
    friend class BST; 
}; 
node::node(int item) 
{ 
    data=item; 
    left=nullptr; 
    right=nullptr; 
    tag=0; 
} 
class BST 
{ 
    private: 
    node *root; 
    void insert(node **ptr,int item); 
    public: 
    BST(); 
    void insert(int item); 
    void intraversal(); 
    void pretraversal(); 
    void posttraversal(); 
}; 
BST::BST() 
{ 
    root=nullptr; 
} 
void BST::insert(int data) 
{ 
    insert (&root,data); 
} 
void BST::insert(node **ptr,int data) 
{ 
    if(*ptr==NULL) 
    { 
        *ptr=new node (data); 
    } 
    else if(data<(*ptr)->data) 
    { 
        this->insert(&(*ptr)->left,data); 
    } 
    else if(data>(*ptr)->data) 
    { 
        this->insert(&(*ptr)->right,data); 
    } 
}  
void BST::intraversal() 
{ 
    node *pres,*prev,*tmp; 
    int flag=0; 
    pres=root; 
    prev=nullptr; 
    while(prev!=nullptr || flag!=2) 
    { 
        if(pres->left!=nullptr && flag==0) 
        { 
            pres->tag=0; 
            tmp=pres->left; 
            pres->left=prev; 
            prev=pres; 
            pres=tmp; 
            flag=0; 
        } 
        else 
        { 
            if(flag!=2) 
            { 
                cout<<pres->data<<" "; 
                if(prev==nullptr && pres->right==nullptr) 
                { 
                    flag=2; 
                } 
            } 
            if(pres->right!=nullptr && flag!=2) 
            { 
                pres->tag=1; 
                tmp=pres->right; 
                pres->right=prev; 
                prev=pres; 
                pres=tmp; 
                flag=0; 
            } 
            else if(prev!=nullptr && prev->tag==0) 
            { 
                tmp=prev->left; 
                prev->left=pres; 
                pres=prev; 
                prev=tmp; 
                flag=1; 
            } 
            else if(prev!=nullptr && prev->tag==1) 
            { 
                tmp=prev->right; 
                prev->right=pres; 
                pres=prev; 
                prev=tmp; 
                flag=2; 
            } 
        } 
    } 
} 
void BST::pretraversal() 
{ 
    node *pres,*prev,*tmp; 
    int flag=0; 
    pres=root; 
    prev=nullptr; 
    while(prev!=nullptr || flag!=2) 
    { 
        if(flag==0) 
        { 
            cout<<pres->data<<" "; 
            if(prev==nullptr && pres->right==nullptr &&pres->left==nullptr) 
            { 
                flag=2; 
            } 
        } 
        if(pres->left!=nullptr && flag==0) 
        { 
            pres->tag=0; 
            tmp=pres->left; 
            pres->left=prev; 
            prev=pres; 
            pres=tmp; 
            flag=0; 
        } 
        else 
        { 
            if(pres->right!=nullptr && flag!=2) 
            { 
                pres->tag=1; 
                tmp=pres->right; 
                pres->right=prev; 
                prev=pres; 
                pres=tmp; 
                flag=0; 
            } 
            else if(prev!=nullptr && prev->tag==0) 
            { 
                tmp=prev->left; 
                prev->left=pres; 
                pres=prev; 
                prev=tmp; 
                if(prev==nullptr && pres->right==nullptr) 
                { 
                    flag=2; 
                } 
                else 
                { 
                    flag=1; 
                } 
            } 
            else if(prev!=nullptr && prev->tag==1) 
            { 
                tmp=prev->right; 
                prev->right=pres; 
                pres=prev; 
                prev=tmp; 
                flag=2; 
            } 
        } 
    } 
} 
void BST::posttraversal() 
{ 
    node *pres,*prev,*tmp; 
    int flag=0; 
    pres=root; 
    prev=nullptr; 
    while(prev!=nullptr || flag!=2) 
    { 
        if(pres->left!=nullptr && flag==0) 
        { 
            pres->tag=0; 
            tmp=pres->left; 
            pres->left=prev; 
            prev=pres; 
            pres=tmp; 
            flag=0; 
        } 
        else 
        { 
            if(pres->right!=nullptr && flag!=2) 
            { 
                pres->tag=1; 
                tmp=pres->right; 
                pres->right=prev; 
                prev=pres; 
                pres=tmp; 
                flag=0; 
            } 
            else if(prev!=nullptr && prev->tag==0) 
            { 
                tmp=prev->left; 
                prev->left=pres; 
                pres=prev; 
                prev=tmp; 
                flag=1; 
            } 
            else if(prev!=nullptr && prev->tag==1) 
            { 
                pres->tag=0; 
                tmp=prev->right; 
                prev->right=pres; 
                pres=prev; 
                prev=tmp; 
                flag=2; 
            } 
        } 
        if(flag==2 || (pres->left == nullptr && pres->right==nullptr)||(pres->right==nullptr && 
flag==1)) 
        { 
            cout<<pres->data<<" "; 
            flag=2; 
        } 
    } 
} 
int main() 
{ 
    BST p; 
    int ch,x; 
    while(1) 
    { 
        cout<<"\nEnter 1 to insert // Enter 2 to print inorder traversal // Enter 3 to preorder traversal // Enter 4 to postorder traversal // Enter 5 to exit:"; 
        cin>>ch; 
        switch(ch) 
        { 
            case 1: 
            int item; 
            cout<<"Enter item to insert:"; 
            cin>>item; 
            p.insert(item); 
            break; 
            case 2: 
            p.intraversal(); 
            cout<<"\n"; 
            break; 
            case 3: 
            p.pretraversal(); 
            break; 
            case 4: 
            p.posttraversal(); 
            break; 
            case 5: 
            x=-1; 
            break; 
            default:cout<<"Wrong Input"; 
        } 
        if(x==-1) 
        { 
            break; 
        } 
    } 
     
}