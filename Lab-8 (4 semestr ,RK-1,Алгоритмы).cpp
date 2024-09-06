#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename K, typename V>
class Map {
private:
    class Node {
    public:
        K key;
        V value;
        int hash;
        Node* next;

        Node(K key, V value, int hash, Node* next) : key(key), value(value), hash(hash), next(next) {}
    };
    int size;
    int init_size;
    vector<Node*> table;

public:
    Map() : size(0), init_size(16) {
        table.resize(init_size, nullptr);
    }

    int getIndex(K key) {
        return key.hashCode() % init_size;
    }

    void put(K key, V value) {
        int index = getIndex(key);
        Node* cur = table[index];

        if (cur == nullptr) {
            table[index] = new Node(key, value, key.hashCode(), nullptr);
            size++;
            return;
        }

        while (cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = new Node(key, value, key.hashCode(), nullptr);
        size++;
    }

    V get(K key) {
        int index = getIndex(key);
        Node* cur = table[index];

        while (cur != nullptr) {
            if (cur->hash == key.hashCode() && cur->key == key) {
                return cur->value;
            }
            cur = cur->next;
        }

        return {};
    }

    void remove(K key) {
        int index = getIndex(key);
        Node* cur = table[index];
        Node* prev = nullptr;

        while (cur != nullptr) {
            if (cur->hash == key.hashCode() && cur->key == key) {
                if (prev == nullptr) {
                    table[index] = cur->next;
                }
                else {
                    prev->next = cur->next;
                }
                delete cur;
                size--;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
    }

    void print() {
        cout << "[";
        for (int i = 0; i < init_size; i++) {
            Node* cur = table[i];
            while (cur != nullptr) {
                cout << "{" << cur->key << ":" << cur->value << "}";
                if (cur->next != nullptr) {
                    cout << ", ";
                }
                cur = cur->next;
            }
        }
        cout << "]" << endl;
    }
};

template <typename K>
class Set {
private:
    Map<K, bool> table; 

public:
    Set() {}

    void add(K key) {
        table.put(key, true);
    }

    bool contains(K key) {
        return table.get(key) != nullptr;
    }

    void remove(K key) {
        table.remove(key);
    }

    void print() {
        table.print();
    }
};

int main() {
    Map<string, int> map;
    map.put("Karakat", 100);
    map.put("Assau", 49);
    map.put("Dias", 100);
    map.put("Karakat", 90);

    cout << map.get("Assau") << endl;
    cout << map.get("Karakat") << endl;
    map.print();

    return 0;
}