#include <iostream>
#include <stack>
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
void duyetLNR(Node* root)
{
    // Tang Dan
  stack <Node*> s;
  Node *p=root;
  while(p!=NULL || !s.empty())
  {
    while(p!=NULL)
  {
    s.push(p);
    p=p->l;
  }

  p=s.top();
  s.pop() ;
  cout << p->data << " ";

  p=p->r;
  }
}
Node *searchDeQuy(Node *root, const int &x)
{
    if(isEmpty(root))
    return NULL;
    if(x==root->data) return root;

    if(x>root->data)
    return searchDeQuy(root->r,x) ;

    if(x<root->data)
    return searchDeQuy(root->l,x);

    return NULL;
}
int main() 
{
    Node *root;
    init(root);
    themNode(root,110);
    themNode(root,12);
    themNode(root,10);
    themNode(root,140);

    duyetLNR(root);
    Node *res=searchDeQuy(root,140);
    if(res!=NULL)
    cout << "Tim Thay: " << res->data;
    else
    cout << "Tim Khong Thay";
    return 0;
}