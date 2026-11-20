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
    // Positive means left-heavy; negative means right-heavy.
    return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(Node* root){
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if(leftHeight > rightHeight){
        root->height = 1 + leftHeight;
    } else {
        root->height = 1 + rightHeight;
    }
}

Node* rightRotate(Node* root){
    Node* newRoot = root->left;
    Node* middleSubtree = newRoot->right;
    root->left = middleSubtree;
    newRoot->right = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

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

    if(balance > 1 && value < root->left->data){
        return rightRotate(root);
    }
    if(balance < -1 && value > root->right->data){
        return leftRotate(root);
    }
    if(balance > 1 && value > root->left->data){
        return leftRightRotate(root);
    }
    if(balance < -1 && value < root->right->data){
        return rightLeftRotate(root);
    }

    return root;
}

Node* deleteAVL(Node* root, int value){
    if(root == nullptr){
        return nullptr;
    }

    // Find the key using the BST ordering.
    if(value < root->data){
        root->left = deleteAVL(root->left, value);
    } else if(value > root->data){
        root->right = deleteAVL(root->right, value);
    } else {
        // Delete a leaf directly, or link its parent to its only child.
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        if(root->left == nullptr){
            Node* child = root->right;
            delete root;
            return child;
        }
        if(root->right == nullptr){
            Node* child = root->left;
            delete root;
            return child;
        }

        // For two children, use the smallest key from the right subtree.
        Node* successor = root->right;
        while(successor->left != nullptr){
            successor = successor->left;
        }
        root->data = successor->data;
        root->right = deleteAVL(root->right, successor->data);
    }

    // Refresh this ancestor's height and rebalance it after deletion.
    updateHeight(root);
    int balance = getBalance(root);

    // A balanced or left-heavy child needs only a right rotation.
    if(balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }
    // A right-heavy left child needs a left-right double rotation.
    if(balance > 1 && getBalance(root->left) < 0){
        return leftRightRotate(root);
    }
    // A balanced or right-heavy child needs only a left rotation.
    if(balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }
    // A left-heavy right child needs a right-left double rotation.
    if(balance < -1 && getBalance(root->right) > 0){
        return rightLeftRotate(root);
    }

    return root;
}

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

void destroyTree(Node* root){
    if(root == nullptr){
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main(){
    // Insert 30, 20, 40, 10, 25, 50, 5 to build the starting AVL tree.
    Node* root = nullptr;
    root = insertAVL(root,30);
    root = insertAVL(root,20);
    root = insertAVL(root,40);
    root = insertAVL(root,10);
    root = insertAVL(root,25);
    root = insertAVL(root,50);
    root = insertAVL(root,5);
    cout << "After insertion:" << endl;
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

    // Deleting 50 makes node 30 left-heavy (balance factor 2); one right rotation fixes it.
    root = deleteAVL(root,50);
    cout << "\nAfter deleting 50:" << endl;
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

    // Deleting 40 leaves node 30 balanced (balance factor 1), so no rotation is needed.
    root = deleteAVL(root,40);
    cout << "\nAfter deleting 40:" << endl;
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

    // Key 99 is not in the tree, so deleting it should leave the tree and its heights unchanged.
    root = deleteAVL(root,99);
    cout << "\nAfter trying to delete missing key 99:" << endl;
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

    // There is nothing to delete from an empty tree, so the result should still be nullptr.
    Node* emptyRoot = nullptr;
    emptyRoot = deleteAVL(emptyRoot,10);
    cout << "\nAfter deleting from the empty tree:" << endl;
    cout << "Preorder: ";
    printPreorder(emptyRoot);
    cout << "\nInorder: ";
    printInorder(emptyRoot);
    cout << "\nAll nodes balanced: ";
    if(isBalanced(emptyRoot)){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;
    cout << "Returned nullptr: ";
    if(emptyRoot == nullptr){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;

    // Deleting the only node (42) should leave the tree empty and return nullptr.
    Node* root2 = insertAVL(nullptr,42);
    root2 = deleteAVL(root2,42);
    cout << "\nAfter deleting the only node:" << endl;
    cout << "Preorder: ";
    printPreorder(root2);
    cout << "\nInorder: ";
    printInorder(root2);
    cout << "\nAll nodes balanced: ";
    if(isBalanced(root2)){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;
    cout << "Returned nullptr: ";
    if(root2 == nullptr){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;

    // In a separate tree (4, 2, 5, 1, 3), deleting 5 leaves node 4 left-heavy
    // and its left child balanced. A single right rotation is enough here.
    Node* root3 = nullptr;
    root3 = insertAVL(root3,4);
    root3 = insertAVL(root3,2);
    root3 = insertAVL(root3,5);
    root3 = insertAVL(root3,1);
    root3 = insertAVL(root3,3);
    root3 = deleteAVL(root3,5);
    cout << "\nAfter deleting 5 when the heavy child has balance 0:" << endl;
    cout << "Preorder: ";
    printPreorder(root3);
    cout << "\nInorder: ";
    printInorder(root3);
    cout << "\nAll nodes balanced: ";
    if(isBalanced(root3)){
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;
    destroyTree(root3);
}
