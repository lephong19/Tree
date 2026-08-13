#include <iostream>
#include <stack>
using namespace std ;
struct Node{
    Node *left , *right;
    int data;
    int height;
};
bool isEmpty(Node *root)
{
    return root==NULL;
}
void init(Node *&root)
{
    root=NULL;
}
Node *createNode(const int &x) 
{
    Node *p=new Node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->height=1;
    return p;
}
int getHeight(Node *root)
{
    if(isEmpty(root))
    return 0;

    return root->height;
}
void updateHeight(Node *&root)
{
    if(root!=NULL)
    {
        root->height=1+max(getHeight(root->left),getHeight(root->right));
    }
}
void xoayPhai(Node *&root)
{
    Node *x=root->left;
    root->left=x->right;
    x->right=root;

    updateHeight(root);
    updateHeight(x);
    root=x;
}
void xoayTrai(Node *&root)
{
    Node *x=root->right;
    root->right=x->left;
    x->left=root;
    updateHeight(root);
    updateHeight(x);
    root=x;
}
int getBalance(Node *root)
{
    if(isEmpty(root))return 0;
    return getHeight(root->left)-getHeight(root->right);
}
void addTree(Node *&root, const int &x ) 
{
    if(isEmpty(root))
    {
        root=createNode(x);
        return ;
    }

    if(x>root->data)
    addTree(root->right,x) ;
    else if(x<root->data)
    addTree(root->left,x);
    else 
    return;

    updateHeight(root);
    int BFTaiNutMatCB=getBalance(root);
    int BFTaiNutConTrai=getBalance(root->left);
    int BFTaiNutConPhai=getBalance(root->right);
    if(BFTaiNutMatCB>1 && (BFTaiNutConTrai>0||BFTaiNutConTrai==0) )
    {
        xoayPhai(root);
    }else 
    if(BFTaiNutMatCB>1 && (BFTaiNutConTrai<0))
    {
        xoayTrai(root->left);
        xoayPhai(root);
    }else 
    if(BFTaiNutMatCB<-1 &&  (BFTaiNutConPhai<0||BFTaiNutConPhai==0) )
    {
        xoayTrai(root);
    }else 
    if(BFTaiNutMatCB<-1 &&(BFTaiNutConPhai>0)){
        xoayPhai(root->right);
        xoayTrai(root);
    }
}
void duyetLNR(Node *root)
{
    stack<Node*>s ;
    Node *p=root;
    while(p!=NULL || !s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }

        p=s.top();
        s.pop();
        cout << p->data << " " ;
        p=p->right;
    }
}
int main()
{
    Node *root;
    init(root);
    addTree(root,10);
    addTree(root,30);
    addTree(root,120);
    addTree(root,100);
    duyetLNR(root);
    addTree()
    return 0;
}