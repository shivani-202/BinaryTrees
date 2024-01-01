#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;

    node(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1) return NULL;

    cout<<"Enter data for insertion in left node of "<< data << endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for insertion in right node of "<< data << endl;
    root->right = buildTree(root->right);
}
int main()
{
    node* root = NULL;
    root = buildTree(root);
    return 0;
}