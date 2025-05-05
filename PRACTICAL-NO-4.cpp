#include<iostream> 
#include<cstring> 
using namespace std; 
 
struct node{ 
    char data; 
    node *left; 
    node *right; 
}; 
class tree{ 
    public: 
        node *top; 
        tree() { top = nullptr; } 
        void expression(char []); 
        void display(node *); 
        void deletion(node *); 
}; 
class stack1{ 
    public: 
        node *data[30]; 
        int top; 
        stack1(){ 
            top = -1; 
        } 
        int empty(){ 
            return (top == -1); 
        } 
        void push(node *p){ 
            data[++top] = p; 
        } 
        node *pop(){ 
            return (data[top--]); 
        } 
}; 
void tree::expression(char prefix[]){ 
    stack1 s; 
    node *t1, *t2; 
    int len = strlen(prefix); 
    for(int i = len - 1; i >= 0; i--){ 
        node *newNode = new node; 
        newNode->left = newNode->right = nullptr; 
        newNode->data = prefix[i]; 
        if(isalpha(prefix[i])){ 
            s.push(newNode); 
        } else if(prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/'){ 
            t1 = s.pop(); 
            t2 = s.pop(); 
            newNode->left = t1; 
            newNode->right = t2; 
            s.push(newNode); 
        } 
    } 
    top = s.pop(); 
} 
void tree::display(node *top){ 
    if (!top) return; 
    stack1 s1, s2; 
    s1.push(top); 
    while (!s1.empty()){ 
        node *T = s1.pop(); 
        s2.push(T); 
        if (T->left) s1.push(T->left); 
        if (T->right) s1.push(T->right); 
    } 
    while (!s2.empty()){ 
        node *T = s2.pop(); 
        cout << T->data << " "; 
    } 
    cout << endl; 
} 
void tree::deletion(node *node){ 
    if (node == nullptr) return; 
    deletion(node->left); 
    deletion(node->right); 
    cout << "Deleting node: " << node->data << endl; 
    delete node; 
} 
int main(){ 
    tree t; 
    char exp1[50]; 
    int ch; 
    do{ 
        cout << "1 -> Enter prefix expression" << endl; 
        cout << "2 -> Display postfix Expression" << endl; 
        cout << "3 -> Deletion" << endl; 
        cout << "4 -> Exit" << endl; 
        cout << "Choose an option (1-4):\t"; 
        cin >> ch; 
 
        switch(ch){ 
            case 1: 
                cout << "Enter the expression (eg.: +--a*bc/def):\t"; 
                cin >> exp1; 
                t.expression(exp1); 
                break; 
            case 2: 
                t.display(t.top); 
                break; 
            case 3: 
                t.deletion(t.top); 
                t.top = nullptr; 
                break; 
            case 4: 
                cout << "\n// END OF CODE\n" << endl; 
                break; 
            default: 
                cout << "Choose a valid option (1-4)." << endl; 
                break; 
        } 
    } while (ch != 4); 
    return 0; 
} 