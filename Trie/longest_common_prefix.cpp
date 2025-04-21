// Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// Example:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
};

// Function to create a new TrieNode
TrieNode* createNode(char ch) {
    TrieNode* node = new TrieNode;
    node->data = ch;
    node->childCount = 0;
    node->isTerminal = false;
    for(int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Recursive utility function to insert word into Trie
void insertUtil(TrieNode* root, string word) {
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        child = root->children[index];
    } else {
        child = createNode(word[0]);
        root->children[index] = child;
        root->childCount++;
    }

    insertUtil(child, word.substr(1));
}

// Function to insert a word into Trie
void insertWord(TrieNode* root, string word) {
    insertUtil(root, word);
}

// Function to find longest common prefix
void longestCommonPrefix(TrieNode* root, string str, string &ans) {
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if(root->childCount == 1) {
            ans.push_back(ch);
            int index = ch - 'a';
            root = root->children[index];
        } else {
            break;
        }

        if(root->isTerminal) {
            break;
        }
    }
}

// Main function equivalent to Solution::longestCommonPrefix
string getLongestCommonPrefix(vector<string>& arr) {
    TrieNode* root = createNode('\0');

    for(int i = 0; i < arr.size(); i++) {
        insertWord(root, arr[i]);
    }

    string first = arr[0];
    string ans = "";
    longestCommonPrefix(root, first, ans);
    return ans;
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << getLongestCommonPrefix(words) << endl;
    return 0;
}