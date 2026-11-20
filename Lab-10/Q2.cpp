/*  Lab 10
    Muhammad Saad
    BSCS-15-D
    20/11/2026*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
    Node *left, *right;

    Node(int value){
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

int getHeight(Node* root){
    if(root == nullptr){
        return 0;
    }
    return root->height;
}

int getBalance(Node* root){
    if(root == nullptr){
        return 0;
    }
    // Positive means left-heavy negative means right-heavy.
    return getHeight(root->left) - getHeight(root->right);
}

// Function to update height of tree
void updateHeight(Node* root){
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if(leftHeight > rightHeight){
        root->height = 1 + leftHeight;
    }
    else{
        root->height = 1 + rightHeight;
    }
}

// Right rotation
Node* rightRotate(Node* root){
    Node* newRoot = root->left;
    Node* middleSubtree = newRoot->right;
    root->left = middleSubtree;
    newRoot->right = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

// Left rotation
Node* leftRotate(Node* root){
    Node* newRoot = root->right;
    Node* middleSubtree = newRoot->left;
    root->right = middleSubtree;
    newRoot->left = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node* leftRightRotate(Node* root){
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

Node* rightLeftRotate(Node* root){
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

Node* insertAVL(Node* root, int value){
    if(root == nullptr){
        return new Node(value);
    }

    // Insert by BST order and ignore duplicate keys.
    if(value < root->data){
        root->left = insertAVL(root->left, value);
    } else if(value > root->data){
        root->right = insertAVL(root->right, value);
    } else {
        return root;
    }

    // Update this node's height before checking its balance.
    updateHeight(root);
    int balance = getBalance(root);

    // LL imbalance: the new key went into the left child's left subtree.
    if(balance > 1 && value < root->left->data){
        return rightRotate(root);
    }
    // RR imbalance: the new key went into the right child's right subtree.
    if(balance < -1 && value > root->right->data){
        return leftRotate(root);
    }
    // LR imbalance: rotate the left child, then this node.
    if(balance > 1 && value > root->left->data){
        return leftRightRotate(root);
    }
    // RL imbalance: rotate the right child, then this node.
    if(balance < -1 && value < root->right->data){
        return rightLeftRotate(root);
    }

    return root;
}

// Inorder travesal print
void printInorder(Node* root){
    if(root == nullptr){
        cout << "(empty)";
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

// Preorder travesal print
void printPreorder(Node* root){
    if(root == nullptr){
        cout << "(empty)";
        return;
    }
    cout << root->data << " ";
    if(root->left != nullptr){
        printPreorder(root->left);
    }
    if(root->right != nullptr){
        printPreorder(root->right);
    }
}

bool isBalanced(Node* root){
    if(root == nullptr){
        return true;
    }
    // Check this node and both of its subtrees.
    int balance = getBalance(root);
    return balance >= -1 && balance <= 1
           && isBalanced(root->left) && isBalanced(root->right);
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
    // Inserting 30, 20, 10 makes the tree lean left at 30, so a right rotation is expected.
    Node* root = nullptr;
    root = insertAVL(root,30);
    root = insertAVL(root,20);
    root = insertAVL(root,10);
    cout << "Sequence (a):" << endl;
    cout << "Preorder: ";
    printPreorder(root);
    cout << "\nInorder: ";
    printInorder(root);
    cout << "\nAll nodes balanced: ";
    if(isBalanced(root)){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;
    destroyTree(root);

    // 10, 20, 30 creates an RR imbalance at 10
    root = nullptr;
    root = insertAVL(root,10);
    root = insertAVL(root,20);
    root = insertAVL(root,30);
    cout << "\nSequence (b):" << endl;
    cout << "Preorder: ";
    printPreorder(root);
    cout << "\nInorder: ";
    printInorder(root);
    cout << "\nAll nodes balanced: ";
    if(isBalanced(root)){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;
    destroyTree(root);

    // 30, 10, 20 creates an LR imbalance at 30
    root = nullptr;
    root = insertAVL(root,30);
    root = insertAVL(root,10);
    root = insertAVL(root,20);
    cout << "\nSequence (c):" << endl;
    cout << "Preorder: ";
    printPreorder(root);
    cout << "\nInorder: ";
    printInorder(root);
    cout << "\nAll nodes balanced: ";
    if(isBalanced(root)){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;
    destroyTree(root);

    // 10, 30, 20 creates an RL imbalance at 10
    root = nullptr;
    root = insertAVL(root,10);
    root = insertAVL(root,30);
    root = insertAVL(root,20);
    cout << "\nSequence (d):" << endl;
    cout << "Preorder: ";
    printPreorder(root);
    cout << "\nInorder: ";
    printInorder(root);
    cout << "\nAll nodes balanced: ";
    if(isBalanced(root)){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;
    destroyTree(root);
}
