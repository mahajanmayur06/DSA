#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    Node* links[26];
    int cWord = 0;
    int cPrefix = 0;

public:
    bool containsKey (char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put (char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get (char ch) {
        return links[ch - 'a'];
    }

    void incrementPrefix () {
        cPrefix++;
    }

    void incrementWord () {
        cWord++;
    }

    void decrementPrefix () {
        cPrefix--;
    }

    void decrementWord () {
        cWord--;
    }

    int getPrefixCount () {
        return cPrefix;
    }

    int getWordCount () {
        return cWord;
    }
};

class Trie {
private: Node* root;

public:
    Trie () {
        root = new Node();
    }

    void insert (string word) {
        int n = word.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incrementPrefix();
        }
        node->incrementWord();
    }

    int countWordsEqualTo (string word) {
        int n = word.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {   
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getWordCount();
    }

    int countWordsStartingWith (string word) {
        int n = word.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefixCount();
    }
    
    void erase (string word) {
        int n = word.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (!node->containsKey(word[i])) {
                return;
            }
            node = node->get(word[i]);
            node->decrementPrefix();
        }
        node->decrementWord();
    }
};

int main() {
    
    return 0;
}