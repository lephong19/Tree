#include <iostream>
#include <stack>
#include <algorithm>

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
void delNode(Node *&root, const int &x)
{
    if(isEmpty(root))
    return ;

    Node *temp=root;
    Node *parent=NULL;
    // Tim x 
    while(temp!=NULL && temp->data!=x)
    {
        parent=temp;
        if(x>temp->data)
        {
            temp=temp->right;
        }else if(x<temp->data)
        {
            temp=temp->left;
        }
    }
    // Khong Tim Thay x
    if(temp==NULL)
    {
        cout << "TIM KHONG THAY " << x << endl;
        return;
    }
    

    // Da Tim Thay x 
    // TH1: x la nut bac 0 (nut la)
    if(temp->left==NULL && temp->right==NULL)
    {
        if(parent==NULL)
        {
            root=NULL;
        }
        else if(parent->right==temp)
        {
            parent->right=NULL;
        }else 
        parent->left=NULL;
        delete temp;
        return;
    }
    // TH2: x la nut bac 1 co con phai
    if(temp->left==NULL&&temp->right!=NULL)
    {
        // Kiem tra neu x == root 
        // temp==root khi do parent == NULL giống với phần khởi tạo ở trên
        if(parent==NULL)
        {
            root=temp->right;
        }   
        else if(parent->left==temp)
        {
            parent->left=temp->right;
        }else
        parent->right=temp->right;

        delete  temp;
        return;
    }else{
        // x la nut bac 1 co con trai
        if(temp->left!=NULL&&temp->right==NULL)
        {
            if(parent==NULL)
            {
                root=temp->left;
            }
            else if(parent->left==temp)
            {
                parent->left=temp->left;
            }else
            parent->right=temp->left;

            delete temp;
            return;
        }
    }
    // TH3: Node bậc 2 có 2 con
    if(temp->left!=NULL && temp->right!=NULL)
    {
       Node *thayThe=temp->right;
       Node *parentThayThe=temp;
       while(thayThe->left!=NULL)
       {
        parentThayThe=thayThe;
        thayThe=thayThe->left;
       }
       temp->data=thayThe->data;
       if(parentThayThe->left==thayThe)
       {
        parentThayThe->left=thayThe->right;
       }else
       parentThayThe->right=thayThe->right;
        delete thayThe;
        return;
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
    cout << endl ;
    cout << "Chieu Cao: " << getHeight(root);
    cout << endl ;
    delNode(root,10);
    duyetLNR(root);
    cout << endl;
    return 0;
}
