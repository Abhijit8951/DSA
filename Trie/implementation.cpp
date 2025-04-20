// Trie Implementation
#include<iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root -> children[index] != NULL) {
                child = root->children[index];
            } else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root -> children[index] != NULL) {
                child = root->children[index];
            } else {
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word) {
            return searchUtil(root, word);
        }

        bool deleteUtil(TrieNode* root, string word) {
            // Base case: if the word is empty
            if (word.length() == 0) {
                // If the word exists, mark the current node as non-terminal
                if (root->isTerminal) {
                    root->isTerminal = false;
                    // If the node has no children, return true to indicate it can be deleted
                    for (int i = 0; i < 26; i++) {
                        if (root->children[i] != NULL) {
                            return false; // Node cannot be deleted
                        }
                    }
                    return true; // Node can be deleted
                }
                return false; // Word does not exist
            }

            int index = word[0] - 'A';
            TrieNode* child = root->children[index];

            // If the child node does not exist, the word is not present
            if (child == NULL) {
                return false;
            }

            // Recursive call for the next character in the word
            bool shouldDeleteChild = deleteUtil(child, word.substr(1));

            // If the child node can be deleted, delete it
            if (shouldDeleteChild) {
                delete child;
                root->children[index] = NULL;

                // Check if the current node can also be deleted
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Node cannot be deleted
                    }
                }
                return !root->isTerminal; // Delete if not terminal
            }

            return false; // Node cannot be deleted
        }

        void deleteWord(string word) {
            deleteUtil(root, word);
        }
};

int main() {
    Trie *t = new Trie();

    t->insertWord("TRIE");
    t->insertWord("ARM");
    t->insertWord("TIMER");
    t->insertWord("DO");

    cout << "Present or not: " << t->searchWord("TIMER") << endl;

    t->deleteWord("TIMER");
    cout << "Present or not after deletion: " << t->searchWord("TIMER") << endl;

    return 0;
}