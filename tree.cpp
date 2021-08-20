#include <bits/stdc++.h>
using namespace std;

class tre
{
public:
    int val;
    tre *left = NULL, *right = NULL;

    tre(int x)
    {
        val = x;
        left = right = NULL;
    }
};
void inorder(tre *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }
}

void preorder(tre *node)
{
    if(node!=NULL)
    {
        cout<<node->val<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(tre *node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout<<node->val<<" ";
    }

}

int total(tre *root)
{
    if(root==NULL)
        return 0;
    return 1+total(root->left)+total(root->right);
}

int maxele(tre *root)
{
    if(root==NULL)
        return 0;
    return max(root->val,max(maxele(root->left),maxele(root->right)));
}

int h(tre *root)
{
    if(root==NULL)
        return 0;
    return max(h(root->left),h(root->right))+1;
}

void itin(tre *root)
{
    stack<tre*>st;
    tre *curr=root;
    while(curr!=NULL || st.empty()==false)
    {
    
        while(curr!=NULL )
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->val<<" ";
        curr=curr->right;   
    }
}

void itpre(tre *root)
{
    stack<tre*>st;
    tre *curr=root;
    while(curr!=NULL || st.empty()==false)
    {
    
        while(curr!=NULL )
        {
            st.push(curr);
            cout<<curr->val<<" ";
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        curr=curr->right;   
    }
}

void itpost(tre *root)
{
    stack<tre*>st;
    tre *curr=root;
    for(int i=0;i<8;i++)
    {
    
        while(curr!=NULL )
        {
            st.push(curr);
            curr=curr->left;
        }
        cout<<curr->val<<" ";

        curr=curr->right;   
    }
}

int main()
{
    tre *node = new tre(10);
    node->left = new tre(20);
    node->right = new tre(30);
    node->left->left=new tre(40);
    node->left->right=new tre(50);
    node->left->right->left=new tre(70);
    node->left->right->right=new tre(80);
    node->right->right = new tre(60);

    cout<<"inorder: ";
    inorder(node);
    cout<<endl;
    cout<<"preorder: ";
    preorder(node);
    cout<<endl;
    cout<<"postorder: ";
    postorder(node);
    cout<<endl;
    cout<<"No of node :"<<total(node)<<endl;
    cout<<"max element :"<<maxele(node)<<endl;
    cout<<"Height of tree :"<<h(node)<<endl;
    cout<<"inorder using iterator: ";
    itin(node);
    cout<<endl<<"preorder using iterator: ";
    itpre(node);
    cout<<endl<<"postorder using iterator: ";
    itpost(node);
    return 0;
}