#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};



Node* insertIntoBST(Node* &root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    }

    else{
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}
void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        insertIntoBST(root, data);
        cin>>data;
    }
    // preorder(root);
}

// int minValue(Node* root, int val){
//     if(!root) return -1;

//     while(root->left != nullptr){
//         root = root->left;
//     }
//     return root->data;
// }

// Node* deleteFromBST(Node* &root, int val){
//     if(root == NULL){
//         return root;
//     }
//     if(root->data == val){
//         //zero children
//         if(root->left == nullptr && root->right == nullptr){
//             delete root;
//             return nullptr;
//         }

//         //1 child->left

//         if(root->left != nullptr || root->right == nullptr){
//             Node* temp = root;
//             delete root;
//             return temp;
//         }
//         //right child only
//         if(root->right != nullptr || root->left == nullptr){
//             Node* temp = root;
//             delete root;
//             return temp;
//         }

//         //2 children

//         if(root->left != nullptr && root->right != nullptr){
//             int min = minValue(root->right, val);
//             root->data = min;
//             root->right = deleteFromBST(root->right, min);
//             return root;
//         }
        

//     }
//     else if(root->data > val){
//         root->left = deleteFromBST(root->left, val);
//         return root;
//     }
//     else{
//         root->right = deleteFromBST(root->right, val);
//         return root;
//     }
// }

int minValue(Node* root) {
    if (!root) return -1;

    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

Node* deleteFromBST(Node* &root, int val) {
    if (root == NULL) {
        return root;
    }

    if (root->data == val) {
        // Zero children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // One child - left or right
        if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }

        if (root->left == nullptr && root->right != nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        }

        // Two children
        if (root->left != nullptr && root->right != nullptr) {
            int min = minValue(root->right);
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }
    } else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}


int main()
{
    Node* root = NULL;
    takeInput(root);
    preorder(root);
    deleteFromBST(root, 10);
    preorder(root);
    return 0;
}