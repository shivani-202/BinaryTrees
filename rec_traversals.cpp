#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
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

    cout<<"Enter data for insertion in left node: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for insertion in right node: "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}
void level_order_traversal(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void inorder(node* root){
    //base case
    if(root == NULL){return;}

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void preorder(node* root){
    //base case
    if(root == NULL){return;}
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    //base case
    if(root == NULL){return;}
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}
void buildfromLevelorder(node* &root) {
    queue<node*> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->data << ": ";
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1) {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter data for right node of " << temp->data << ": ";
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1) {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"inorder traversal: "<<endl;
    inorder(root);
    cout<<"preorder traversal: "<<endl;
    preorder(root);
    cout<<"postorder traversal: "<<endl;
    postorder(root);
    return 0;
}