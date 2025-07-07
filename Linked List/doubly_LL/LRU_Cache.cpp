#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value;
    Node* next;
    Node* prev;
    Node () {
        key = -1;
        value = -1;
        next = NULL, prev = NULL;
    }
    Node (int k, int v) {
        key = k;
        value = v;
        next = NULL, prev = NULL;
    }
};

class LRUCache {
private:
    Node *head, *tail;
public:
    unordered_map<int, Node*> cache;
    int size = 0;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void adjustPointer (Node* node) {
        node->prev->next = node->next; // detach from head
        node->next->prev = node->prev;
        node->next = head->next; // attach to head
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        Node* node = cache[key];
        adjustPointer(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            adjustPointer(cache[key]);
            return;
        }
        if (size == cap) {
            Node* lru = tail->prev;
            lru->prev->next = tail;
            tail->prev = lru->prev;
            size--;
            cache.erase(lru->key);
            delete lru;
        }
        Node* newNode = new Node(key, value);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode; 
        head->next = newNode;
        cache[key] = newNode;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    
    return 0;
}