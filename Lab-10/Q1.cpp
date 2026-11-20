/*  Lab 10
    Muhammad Saad
    BSCS-15-D
    20/11/2026*/

#include <iostream>
using namespace std;

// Node for BST
struct Node {
    int data;
    Node *left, *right;
    
    // Constructor
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert into BST
Node* insert(Node* root, int data, bool& inserted){ // bool inserted is used to check if it was successfully added
    // Inserted is passed as false when the function is first called
    if (root == nullptr) { // If root is null insert the node, Base condition
        inserted = true;
        return new Node(data);
    }

    // Recursive calls
    if (data < root->data) {
        root->left = insert(root->left, data, inserted);
    } else if (data > root->data) {
        root->right = insert(root->right, data, inserted);
    }
    // If neither match, value is equal, inserted is false

    return root;
}

Node* deleteBST(Node* root, int value){
    if (root == nullptr){       
        return nullptr;
    }
    
    // If value is less than value of root go left
    if(value<root->data){
        root->left  = deleteBST(root->left,value);
    }
    // If value is greater than value of root go right
    else if(value>root->data){
        root->right  = deleteBST(root->right,value);
    }

    // Only runs if value is equal
    else{   
        // Case 1: No children    
        if(root->left == nullptr && root->right == nullptr){ // No children
            delete root; 
            return nullptr;       
        }
        
        // Case 2: Only 1 children
        if(root->left == nullptr){ // Only right child
            Node* child = root->right;
            delete root;
            return child;
            
        }
        if(root->right == nullptr){ // Only left child
            Node* child = root->left;
            delete root;
            return child;
            
        }

        // Case 3: Both children exist
        Node* successor = root->right;
        while(successor->left != nullptr){
            successor = successor->left;
        }
        root->data = successor->data; // Replace value of root with value of successor
        root->right = deleteBST(root->right, successor->data);  // Delete the successor from the right subtree 
        return root;
    }

    return root;
}

// Function to print inorder travesal
void printInorder(Node* root){
    if(root == nullptr){
        cout << "nullptr";
        return;
    }
    if(root->left != nullptr){
        printInorder(root->left);
    }
    cout << root->data << " ";
    if(root->right != nullptr){
        printInorder(root->right);
    }
}

// Called at the end of program to free memory
void destroyTree(Node* root){
    if(root == nullptr){
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main(){
    // Insert 50, 30, 70, 20, 40, 60, 80, 65.
    bool inserted;
    Node* root = nullptr;
    root = insert(root,50,inserted);
    insert(root,30,inserted);
    insert(root,70,inserted);
    insert(root,20,inserted);
    insert(root,40,inserted);
    insert(root,60,inserted);
    insert(root,80,inserted);
    insert(root,65,inserted);

    cout << "Initial inorder: ";
    printInorder(root);
    cout << endl;

    // Delete 20: case 1, a leaf
    // Prediction: inorder will be 30 40 50 60 65 70 80.
    root = deleteBST(root,20);
    cout << "After deleting 20: ";
    printInorder(root);
    cout << endl;

    // Delete 60: case 2, one child (65).
    // Prediction: inorder will be 30 40 50 65 70 80.
    root = deleteBST(root,60);
    cout << "After deleting 60: ";
    printInorder(root);
    cout << endl;

    // Delete 50: case 3, two children
    // Prediction: replace 50 with 65; inorder will be 30 40 65 70 80.
    root = deleteBST(root,50);
    cout << "After deleting 50: ";
    printInorder(root);
    cout << endl;

    // Delete missing key 99
    // Prediction: the tree remains unchanged.
    root = deleteBST(root,99);
    cout << "After trying to delete missing key 99: ";
    printInorder(root);
    cout << endl;

    // Delete 10 from an empty tree
    // Prediction: the result is nullptr and inorder is empty.
    Node* emptyRoot = nullptr;
    emptyRoot = deleteBST(emptyRoot,10);
    cout << "After deleting 10 from the empty tree: ";
    printInorder(emptyRoot);
    cout << endl;

    // Delete the only node (42), case 1. Prediction: the result is nullptr and inorder is empty.
    Node* singleNodeRoot = new Node(42);
    singleNodeRoot = deleteBST(singleNodeRoot,42);
    cout << "After deleting the only node: ";
    printInorder(singleNodeRoot);
    cout << endl;

    destroyTree(root);
}

