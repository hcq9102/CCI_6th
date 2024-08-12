//https://godbolt.org/z/Wes9ehGTr

/*
方法一：哈希表 + 双向链表
我们可以用“哈希表”和“双向链表”实现一个 LRU 缓存。

哈希表：用于存储 key 和对应的节点位置。
双向链表：用于存储节点数据，按照访问时间排序。
当访问一个节点时，如果节点存在，我们将其从原来的位置删除，并重新插入到链表头部。这样就能保证链表尾部存储的就是最近最久未使用的节点，当节点数量大于缓存最大空间时就淘汰链表尾部的节点。

当插入一个节点时，如果节点存在，我们将其从原来的位置删除，并重新插入到链表头部。如果不存在，我们首先检查缓存是否已满，如果已满，则删除链表尾部的节点，将新的节点插入链表头部。

*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int k;
    int v;

    Node* prev;
    Node* next;

    Node()
        : k(0)
        , v(0)
        , prev(nullptr)
        , next(nullptr) {}
    Node(int key, int val)
        : k(key)
        , v(val)
        , prev(nullptr)
        , next(nullptr) {}
};

class LRUCache{
    private:
        unordered_map<int, Node*> cache;
        Node* head;
        Node* tail;

        int capacity;
        int size;

        void moveToHead(Node *node){
            removeNode(node);
            addToHead(node);
        }

        void removeNode(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void addToHead(Node* node){
            node->next = head->next;
            node->prev = head;
            head->next = node;
            node->next->prev = node;
        }

        Node* removeTail(){
            Node* node = tail->prev;
            removeNode(node);
            return node;
        }

    public:
        LRUCache(int capacity)
        : capacity(capacity)
        , size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;   
        }    

        int get(int key){
            if(!cache.count(key)) return -1;
            Node* node = cache[key];
            moveToHead(node);
            return node->v;
        }

        void put(int key, int value) {
            if(cache.count(key)){// exist, update value
                Node* node = cache[key];
                node->v = value; 
                moveToHead(node);
            }else{
                Node* node = new Node(key,value);
                cache[key] = node;

                addToHead(node);
                ++size;
                if(size>capacity){
                    node = removeTail();
                    cache.erase(node->k);
                    --size;
                }
            }
        }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 返回 1
    cache.put(3, 3); // 该操作会使得键 2 作废
    cout << cache.get(2) << endl; // 返回 -1 (未找到)
    cache.put(4, 4); // 该操作会使得键 1 作废
    cout << cache.get(1) << endl; // 返回 -1 (未找到)
    cout << cache.get(3) << endl; // 返回 3
    cout << cache.get(4) << endl; // 返回 4

    return 0;
}
