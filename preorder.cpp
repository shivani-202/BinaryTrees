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

vector<int> preorder(node* root, vector<int>& ans) {
    stack<node*> st;
    if (root == NULL) return ans;
    st.push(root);
    while (!st.empty()) {
        node* temp = st.top();
        ans.push_back(temp->data);
        st.pop();
        if (temp->right != NULL) st.push(temp->right);
        if (temp->left != NULL) st.push(temp->left);
    }
    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree();
    vector<int> ans;
    ans = preorder(root, ans);
    cout << "Preorder Traversal: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
