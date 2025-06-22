#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    Node* links[26];
    bool flag = false;

public:
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string str) {
        int n = str.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(str[i])) {
                return 0;
            }
            node = node->get(str[i]);
            if (!node->isEnd()) {
                return 0;
            }
        }
        return 1;
    }

};

string completeString(vector<string> strings) {
    Trie t;
    for (string str : strings) {
        t.insert(str);
    }

    string longest = "";
    for (string str : strings) {
        if (t.search(str)) {
            if (str.size() > longest.size()) {
                longest = str;
            }
            else if (str.size() == longest.size() && str < longest) {
                longest = str;
            }
        }
    }

    return longest;
}

int main() {
    vector<string> words = {"apple", "app", "apply", "apple"};
    cout << completeString(words) << endl;  // Sample usage
    return 0;
}
