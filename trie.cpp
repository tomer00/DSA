#include <iostream>
using namespace std;

class Trie {
    Trie* children[26];
    bool isEnding;
    char myChar;
public:
    Trie(char c) {
        myChar = c;
        for (int i = 0;i < 26;i++) children[i] = NULL;
        isEnding = false;
    }

    bool search(string word) {
        Trie* temp = this;
        int n = word.length();
        for (int i = 0;i < n;i++) {
            temp = temp->children[word[i] - 'a'];
            if (temp == NULL) return false;
        }
        return temp->isEnding;
    }
    void insert(string word) {
        Trie* temp = this;
        int n = word.length();
        for (int i = 0;i < n;i++) {
            if (temp->children[word[i] - 'a'] == NULL) {
                temp->children[word[i] - 'a'] = new Trie(word[i]);
                temp = temp->children[word[i] - 'a'];
            }
        }
        temp->isEnding = true;
    }

};

int main() {

    Trie root('l');

    int c;
    printf("1 : Insert \n");
    printf("2 : Search \n");
    printf("5 : Exit \n");
    string word;
    do {
        cout << "Select option : ";
        cin >> c;
        if (c == 1) {
            cout << "Enter Word to Insert (lowerCase) : ";
            cin >> word;
            root.insert(word);
            cout << "Word : " << word << " inserted" << endl;
        }
        else if (c == 2) {
            cout << "Enter Word to Search (lowerCase) : ";
            cin >> word;
            cout << "Word : " << word << (root.search(word) ? " - found" : " - notFound") << endl;
        }
    } while (c != 5);

    return 0;
}