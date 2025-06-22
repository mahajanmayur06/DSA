#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[2];
    
    bool containsNode(int bit) {
        return links[bit] != NULL;
    }

    void putNode(int bit, Node* node) {
        links[bit] = node;
    }

    Node* getNode(int bit) {
        return links[bit];
    }
};

class Trie {
    Node* root = new Node();

    void insert(int num) {
        Node* node = root;
        for (int x = 31; x >= 0; x--) {
            int bit = (num >> x) & 1;
            if (!node->containsNode(bit)) {
                node->putNode(bit, new Node());
            }
            node = node->getNode(bit);
        }
    }

    int findMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int x = 31; x >= 0; x--) {
            int bit = (num >> x) & 1;
            int opp = 1 - bit;
            if (node->containsNode(opp)) {
                maxNum |= (1 << x);
                node = node->getNode(opp);
            } else {
                node = node->getNode(bit);
            }
        }
        return maxNum;
    }
    
    // If given a number x, return  findMax(x);
    public:
    int maxXor(vector<int> &arr) {
        int maxVal = 0;
        for (int num : arr) {
            insert(num);
        }
        for (int num : arr) {
            maxVal = max(maxVal, findMax(num));
        }
        return maxVal;
    }
};

int main() {
    
    return 0;
}