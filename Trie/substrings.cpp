#include <bits/stdc++.h>
using namespace std;

class Node {
    Node* links[26];
public:
    bool containsKey (char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put (char ch) {
        links[ch - 'a'] = new Node();
    }

    Node* get (char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    int insertAndCount(string word) {
        int n = word.size(), count = 0;

        for (int i = 0; i < n; i++) {
            Node *node = root;
            for (int j = i; j < n; j++) {
                if (!node->containsKey(word[j])) {
                    node->put(word[j]);
                    count++;
                }
                node = node->get(word[j]);
            }
        }
        return count + 1;
    }
};

int main() {
    Trie t;
    cout << t.insertAndCount("ababa");
    return 0;
}