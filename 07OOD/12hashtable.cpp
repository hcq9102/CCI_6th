//https://godbolt.org/z/PTrM3abzW


/*
Designing and implementing a hash table using linked lists to handle collisions involves creating a hash table where each bucket is a linked list. When two keys hash to the same bucket, their values are stored in the linked list at that bucket. Here's how you can design and implement such a hash table in C++.

-----Components of the Hash Table
Hash Table: The primary data structure containing an array of buckets (linked lists).

Bucket: A linked list to handle collisions within a bucket.

Hash Function: Determines the index of the bucket where a key-value pair should be stored.

Node: Represents each entry in the linked list within a bucket.

----Design
Node Class: Represents an element in the linked list.
Bucket Class: Manages a linked list of nodes.
HashTable Class: Manages an array of buckets and provides methods for inserting, searching, and deleting key-value pairs.
*/
#include <iostream>
#include <list>
#include <vector>
#include <string>

// Node representing a key-value pair
template<typename K, typename V>
class Node {
public:
    K key;
    V value;

    Node(K key, V value) : key(key), value(value) {}
};

// Bucket class managing a linked list of nodes
template<typename K, typename V>
class Bucket {
public:
    std::list<Node<K, V>> nodes;

    // Insert or update a key-value pair
    void insert(K key, V value) {
        for (auto& node : nodes) {
            if (node.key == key) {
                node.value = value; // Update existing value
                return;
            }
        }
        nodes.emplace_back(key, value); // Insert new node
    }

    // Find the value associated with a key
    bool find(K key, V& value) {
        for (const auto& node : nodes) {
            if (node.key == key) {
                value = node.value;
                return true;
            }
        }
        return false;
    }

    // Remove a key-value pair
    bool remove(K key) {
        auto it = nodes.begin();
        while (it != nodes.end()) {
            if (it->key == key) {
                nodes.erase(it);
                return true;
            }
            ++it;
        }
        return false;
    }
};

// Hash Table class
template<typename K, typename V>
class HashTable {
public:
    HashTable(size_t size) : table(size) {}

    // Hash function to determine the bucket index
    size_t hash(K key) const {
        return std::hash<K>{}(key) % table.size();
    }

    // Insert or update a key-value pair
    void insert(K key, V value) {
        size_t index = hash(key);
        table[index].insert(key, value);
    }

    // Find the value associated with a key
    bool find(K key, V& value) {
        size_t index = hash(key);
        return table[index].find(key, value);
    }

    // Remove a key-value pair
    bool remove(K key) {
        size_t index = hash(key);
        return table[index].remove(key);
    }

private:
    std::vector<Bucket<K, V>> table;
};

int main() {
    HashTable<std::string, int> hashTable(10);

    hashTable.insert("Alice", 30);
    hashTable.insert("Bob", 25);
    hashTable.insert("Charlie", 35);

    int value;
    if (hashTable.find("Alice", value)) {
        std::cout << "Alice's age: " << value << std::endl;
    }

    hashTable.remove("Bob");

    if (!hashTable.find("Bob", value)) {
        std::cout << "Bob not found" << std::endl;
    }

    return 0;
}

