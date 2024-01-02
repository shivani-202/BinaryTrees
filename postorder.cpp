//iterative algoritm for postorder traversal
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree() {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1) return NULL;

    node* root = new node(data);

    cout << "Enter data for insertion in the left node of " << data << endl;
    root->left = buildTree();
    
    cout << "Enter data for insertion in the right node of " << data << endl;
    root->right = buildTree();

    return root;
}

vector<int> postorder(node* root, vector<int>& ans) {
    stack <node*> st;
    node* temp = root;
    if(temp == NULL) return ans;
    
    if(temp->left != NULL) st.push(temp->left);
    if(temp->right != NULL) st.push(temp->right);

}

int main() {
    node* root = NULL;
    root = buildTree();
    vector<int> ans;
    ans = postorder(root, ans);
    cout << "Postorder Traversal: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
