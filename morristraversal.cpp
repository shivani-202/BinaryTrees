#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree() {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1) return NULL;

    Node* root = new Node(data);

    cout << "Enter data for insertion in the left node of " << data << endl;
    root->left = buildTree();
    
    cout << "Enter data for insertion in the right node of " << data << endl;
    root->right = buildTree();

    return root;
}

vector<int> morrisTraversal(vector <int>& inorder, Node* root){
    Node* current = root;
    while(current != nullptr){
        if(current->left == nullptr){
            inorder.push_back(current->data);
            current = current->right;
        }
        else{
            Node* temp = current->left;
            while(temp->right != nullptr && temp->right != current){
                temp = temp->right;
            }
                if(temp->right == nullptr){
                    temp->right = current;
                    current = current->left;
                }
                else{
                    temp->right = nullptr;
                    inorder.push_back(current->data);
                    current = current->right;
                }
        }
    }
    return inorder;
}
int main()
{
    Node* root = nullptr;
    root = buildTree();
    vector<int> inorder = {};
    morrisTraversal(inorder, root);
    for(auto i : inorder){
        cout<<  i <<" ";
    }
    return 0;
}