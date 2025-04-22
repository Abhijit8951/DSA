// Implement a phone directory
// You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

TrieNode* root = new TrieNode('\0');

void insertWord(string word) {
    TrieNode* current = root;

    for (char ch : word) {
        int index = ch - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = new TrieNode(ch);
        }

        current = current->children[index];
    }

    current->isTerminal = true;
}

void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
    if (curr->isTerminal) {
        temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        TrieNode* next = curr->children[ch - 'a'];
        if (next != NULL) {
            prefix.push_back(ch);
            printSuggestions(next, temp, prefix);
            prefix.pop_back(); // backtrack
        }
    }
}

vector<vector<string>> getSuggestions(string queryStr) {
    TrieNode* current = root;
    vector<vector<string>> output;
    string prefix = "";

    for (char ch : queryStr) {
        prefix.push_back(ch);
        current = current->children[ch - 'a'];

        if (current == NULL) {
            break;
        }

        vector<string> temp;
        printSuggestions(current, temp, prefix);
        output.push_back(temp);
    }

    return output;
}

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    for (string contact : contactList) {
        insertWord(contact);
    }

    return getSuggestions(queryStr);
}

int main() {
    vector<string> contacts = {"code", "coder", "coding", "codex", "colt"};
    string query = "cod";

    vector<vector<string>> results = phoneDirectory(contacts, query);

    for (int i = 0; i < results.size(); i++) {
        cout << "Suggestions for \"" << query.substr(0, i + 1) << "\": ";
        for (string s : results[i]) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}