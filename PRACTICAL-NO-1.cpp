#include <iostream> 
#include <list> 
#include <string> 
using namespace std; 
#define TABLE_SIZE 10   
struct Client { 
    string name; 
    string phone; 
}; 
class HashTable { 
private: 
    list<Client> table[TABLE_SIZE];   
    int hashFunction(string key) { 
        int sum = 0; 
        for (char ch : key) { 
            sum += ch; 
        } 
        return sum % TABLE_SIZE; 
    } 
public: 
    void insert(string name, string phone) { 
        int index = hashFunction(name); 
        table[index].push_back({name, phone}); 
        cout << "Contact " << name << " added successfully!\n"; 
    } 
    void search(string name) { 
        int index = hashFunction(name); 
        for (auto &client : table[index]) { 
            if (client.name == name) { 
                cout << "Contact Found: " << client.name << " - " << client.phone << "\n"; 
                return; 
            } 
        } 
        cout << "Contact Not Found!\n"; 
    } 
    void remove(string name) { 
        int index = hashFunction(name); 
        for (auto it = table[index].begin(); it != table[index].end(); it++) { 
            if (it->name == name) { 
                table[index].erase(it); 
                cout << "Contact " << name << " deleted successfully!\n"; 
                return; 
            } 
        } 
        cout << "Contact Not Found!\n"; 
    }    void display() { 
        for (int i = 0; i < TABLE_SIZE; i++) { 
            if (!table[i].empty()) { 
                cout << "Index " << i << ": "; 
                for (auto &client : table[i]) { 
                    cout << "[" << client.name << ": " << client.phone << "] -> "; 
                } 
                cout << "NULL\n"; 
            } 
        } 
    } 
}; 
int main() { 
    HashTable phoneBook; 
    int choice; 
    string name, phone; 
    while (true) { 
        cout << "\n***** TELEPHONE BOOK *****\n"; 
        cout << "1. Insert Contact\n"; 
        cout << "2. Search Contact\n"; 
        cout << "3. Delete Contact\n"; 
        cout << "4. Display Contacts\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                cout << "Enter Name: "; 
                cin >> name; 
                cout << "Enter Phone Number: "; 
                cin >> phone; 
                phoneBook.insert(name, phone); 
                break; 
            case 2: 
                cout << "Enter Name to Search: "; 
                cin >> name; 
                phoneBook.search(name); 
                break; 
            case 3: 
                cout << "Enter Name to Delete: "; 
                cin >> name; 
                phoneBook.remove(name);  break; 
            case 4: 
                phoneBook.display(); 
                break; 
            case 5: 
                cout << "Exiting... Thank You!\n"; 
                return 0; 
            default: 
                cout << "Invalid Choice! Try Again.\n"; 
        } 
    } 
    return 0; 
} 