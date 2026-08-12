#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *l,*r;
};
void init(Node *&root)
{
    root=NULL;
}
Node *createNode(const int &x)
{
    Node *p=new Node;
    p->data=x;
    p->l=NULL;
    p->r=NULL;

    return p;
}
bool isEmpty(Node *root)
{
    return root==NULL;
}
void themNodeDeQuy(Node *&root, const int &x)
{
    if(isEmpty(root))
    {
        root=createNode(x);
        return;
    }
        
            if(root->data>x)
            themNodeDeQuy(root->l,x);
            else if(root->data<x)
            themNodeDeQuy(root->r,x) ;
            else
            return;
}
void themNode(Node *&root , const int &x) 
{
    if(isEmpty(root))
    {
        root=createNode(x);
        return;
    }
    Node *temp=root;
    Node *p=NULL;
    while(temp!=NULL)
    {
        p=temp;
        if(temp->data>x)
        {
            temp=temp->l;
        }else if(temp->data<x)
        {
            temp=temp->r;
        }else{
            return;
        }
    }
      Node *N=createNode(x);

   if(p->data>x)
   {
    p->l=N;
   }else{
    p->r=N;
   }
}