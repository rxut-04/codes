#include <iostream> 
using namespace std; 
class node { 
public: 
int data; 
node *left, *right; 
node(int val) {  // Constructor to initialize the node 
data = val; 
left = right = NULL; 
} 
}; 
class bst { 
public: 
node *root;     
bst() { root = NULL; } 
void create(); 
void insert(); 
void postorder(node *); 
void inorder(node *); 
void preorder(node *); 
void search(int key); 
void minimum(); 
int height(node *); 
}; 
void bst::minimum() { 
    if (root == NULL) { 
        cout << "Tree is empty!\n"; 
        return; 
    } 
    node *temp = root; 
    while (temp->left != NULL) { 
        temp = temp->left; 
    } 
    cout << "Minimum value in the tree: " << temp->data << endl; 
} 
int bst::height(node *root) { 
    if (root == NULL) 
        return -1; // Height of empty tree is -1 
 
    int leftHeight = height(root->left); 
    int rightHeight = height(root->right); 
    return 1 + max(leftHeight, rightHeight); 
} 
void bst::create() { 
    int ans = 1, val; 
    cout << "Enter data: "; 
    do { 
        cin >> val; 
        node *curr = new node(val); 
        if (root == NULL) { 
            root = curr; 
        } else { 
            node *temp = root; 
            while (true) { 
                if (curr->data <= temp->data) { 
                    if (temp->left == NULL) { 
                        temp->left = curr; 
                        break; 
                    } 
                    temp = temp->left; 
                } else { 
                    if (temp->right == NULL) { 
                        temp->right = curr; 
                        break; 
                    } 
                    temp = temp->right; 
                } 
            } 
        } 
        cout << "Want to continue? (1 for yes, 0 for no): "; 
        cin >> ans; 
    } while (ans == 1); 
} 
void bst::inorder(node *root) { 
    if (root != NULL) { 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    } 
} 
void bst::preorder(node *root) { 
    if (root != NULL) { 
        cout << root->data << " "; 
        preorder(root->left); 
        preorder(root->right); 
    }} 
 
void bst::postorder(node *root) { 
    if (root != NULL) { 
        postorder(root->left); 
        postorder(root->right); 
        cout << root->data << " "; 
    } 
} 
void bst::insert() { 
    int val; 
    cout << "Enter data: "; 
    cin >> val; 
    node *curr = new node(val); 
    if (root == NULL) { 
        root = curr; 
    } else { 
        node *temp = root; 
        while (true) { 
            if (curr->data <= temp->data) { 
                if (temp->left == NULL) { 
                    temp->left = curr; 
                    break; 
                } 
                temp = temp->left; 
            } else { 
                if (temp->right == NULL) { 
                    temp->right = curr; 
                    break; 
                } 
                temp = temp->right; 
            } 
        } 
    } 
} 
void bst::search(int key) { 
    node *curr = root; 
    while (curr != NULL) { 
        if (curr->data == key) { 
            cout << "Found\n"; 
            return; 
        } else if (key < curr->data) { 
            curr = curr->left; 
        } else { 
            curr = curr->right; 
        } 
    } 
    cout << "Not found\n"; 
} 
 
int main() { 
    bst b; 
    int key, ch; 
    do { 
        cout << "\n1. Create\n2. Insert\n3. Inorder\n4. Preorder\n5. Postorder\n" 
             << "6. Search\n7. Minimum\n8. Height\nPress 0 to Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> ch; 
        switch (ch) { 
            case 1: b.create(); break; 
            case 2: b.insert(); break; 
            case 3: cout << "Inorder Traversal: "; b.inorder(b.root); cout << endl; break; 
            case 4: cout << "Preorder Traversal: "; b.preorder(b.root); cout << endl; break; 
case 5: cout << "Postorder Traversal: "; b.postorder(b.root); cout << endl; break; 
case 6: cout << "Enter key: "; cin >> key; b.search(key); break; 
case 7: b.minimum(); break; 
case 8: cout << "Height of tree: " << b.height(b.root) << endl; break; 
case 0: cout << "\n// END OF CODE\n"; break; 
default: cout << "Choose a valid option (0-8).\n"; break; 
} 
} while (ch != 0); 
return 0; 
} 