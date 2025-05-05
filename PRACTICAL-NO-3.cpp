#include <iostream> 
#include <string> 
using namespace std; 
 
struct node { 
    string label; 
    int ch_count; 
    node* child[10]; 
}; 
 
class GT { 
private: 
    node* root; 
 
public: 
    GT() { 
        root = nullptr; 
    } 
 
    void create() { 
        root = new node; 
        cout << "Name of the book:\t"; 
        cin >> root->label; 
        cout << "Number of chapters:\t"; 
        cin >> root->ch_count; 
 
        for (int i = 0; i < root->ch_count; i++) { 
            root->child[i] = new node; 
            cout << "Name of chapter " << i + 1 << ":\t"; 
            cin >> root->child[i]->label; 
            cout << "Number of sections:\t"; 
            cin >> root->child[i]->ch_count; 
 
            for (int j = 0; j < root->child[i]->ch_count; j++) { 
                root->child[i]->child[j] = new node; 
                cout << "Name of section " << i + 1 << " - " << j + 1 << ":\t"; 
                cin >> root->child[i]->child[j]->label; 
                cout << "Number of sub-sections:\t"; 
                cin >> root->child[i]->child[j]->ch_count; 
 
                for (int k = 0; k < root->child[i]->child[j]->ch_count; k++) { 
                    root->child[i]->child[j]->child[k] = new node; 
                    cout << "Name of sub-section " << i + 1 << " - " << j + 1 << " - " << k + 1 << ":\t"; 
                    cin >> root->child[i]->child[j]->child[k]->label; 
                } 
            } 
        } 
    } 
 
    void display(node* r) { 
        if (!r) { 
            cout << "No book data available." << endl; 
            return; 
        } 
 
        cout << "\nName of book:\t" << root->label << endl; 
        cout << "\nNumber of chapters:\t" << root->ch_count << endl; 
 
        for (int i = 0; i < root->ch_count; i++) { 
            cout << "\nName of chapter:\t" << root->child[i]->label << endl; 
            cout << "\nNumber of sections:\t" << root->child[i]->ch_count << endl; 
 
            for (int j = 0; j < root->child[i]->ch_count; j++) { 
                cout << "\t" << i + 1 << " - " << j + 1 << " Name of section: " << root->child[i]->child[j]->label << endl; 
                cout << "\tNumber of sub-sections: " << root->child[i]->child[j]->ch_count << endl; 
 
                for (int k = 0; k < root->child[i]->child[j]->ch_count; k++) { 
                    cout << "\t\t" << i + 1 << " - " << j + 1 << " - " << k + 1 << " Name of sub-section: " << root->child[i]->child[j]->child[k]->label << endl; 
                } 
            } 
        } 
    } 
 
    void display() { 
        display(root); 
    } 
}; 
 
int main() { 
    GT g; 
    while (1) { 
        cout << "--- MAIN MENU ---" << endl; 
        cout << "1 -> Add book info" << endl; 
        cout << "2 -> Display info" << endl; 
        cout << "3 -> Exit" << endl; 
        cout << "Choose an option (1-3):\t"; 
        int ch; 
        cin >> ch; 
 
        switch (ch) { 
            case 1: 
                g.create(); 
                break; 
            case 2: 
                g.display(); 
                break; 
            case 3: 
                cout << "\n// END OF CODE\n\n"; 
                return 0; 
            default: 
                cout << "Please choose a valid option (1-3)." << endl; 
                break; 
        } 
    } 
} 