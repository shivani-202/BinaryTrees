//iterative algoritm for inorder traversal
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        this->data = val;
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

vector<int> inorder(node* root, vector<int>& ans){
    stack<node*> st;
    while(true){
        if(root!=NULL){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty()) break;

            root = st.top();
            ans.push_back(root->data);
            st.pop();
            root = root->right;
        }
    }
    return ans;
}

int main()
{   
    node* root = NULL;
    root = buildTree(root);
    vector<int> ans;
    ans = inorder(root, ans);
    cout << "Inorder Traversal: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}