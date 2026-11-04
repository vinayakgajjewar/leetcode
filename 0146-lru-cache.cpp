#include <cassert>
#include <unordered_map>

using namespace std;

// intuition: keep the most recently used nodes at the end of the linked list
// and the least recently used nodes at the beginning (use dummy start/end nodes
// to clean up linked list logic). upon get, move that node to the rightmost
// spot upon put, if that key exists already, move it to the rightmost spot, but
// if it is new and we are at capacity, remove the leftmost real node first

// this is a real quick linked list implementation note that we need to store
// both the key and the value in the node
class Node
{
  public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr)
    {
    }
};

// remove the given node from the linked list. remember we always have dummy
// start and end nodes.

class LRUCache
{
  private:
    void remove(Node *n)
    {
        // assert(n->prev != nullptr);
        // assert(n->next != nullptr);
        Node *prev = n->prev;
        Node *next = n->next;
        prev->next = next;
        next->prev = prev;
    }

    // insert the given node at the end (right before the end dummy)
    void insert_end(Node *n)
    {
        n->prev = end->prev;
        n->next = end;
        end->prev->next = n;
        end->prev = n;
    }

  public:
    // note the organization: get() need to be able to find a key's node in O(1)
    // time so that it can move it to the end
    std::unordered_map<int, Node *> cache;
    int cap;

    // dummy nodes make life easier
    Node *start;
    Node *end;
    LRUCache(int capacity)
    {
        cap = capacity;
        start = new Node(-1, -1);
        end = new Node(-1, -1);
        start->next = end;
        end->prev = start;
        cache.clear();
    }

    int get(int key)
    {
        // trivial case
        // note how to check for existence in unordered_map
        if (cache.find(key) == cache.end())
            return -1;
        assert(cache[key] != nullptr);
        Node *n = cache[key];
        remove(n);
        insert_end(n);

        return n->val;
    }

    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            // new element
            Node *n = new Node(key, value);
            cache[key] = n;
            insert_end(n);

            // check if we have to evict something. note that we have to use
            // erase() so that we don't find() it later.
            if (cache.size() > cap)
            {

                // note that you need to keep a pointer to the lru because
                // start->next will be different after you call remove() on it.
                // This tripped me up!!! Lesson: always grab pointers to the
                // nodes you care about!!!!
                Node *lru = start->next;
                cache.erase(lru->key);
                remove(lru);
                delete lru;
            }
        }
        else
        {
            // update existing element
            Node *n = cache[key];
            n->val = value;
            remove(n);
            insert_end(n);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// this is my solution from 2026-11-04 just to drill this pattern into my head.
// the tricky thing is realizing that the value for the hash table should be a
// Node pointer and that the Node class needs to contain both the key and the
// value. the intuition is that we'll pair a hash table (unordered map) with a
// linked list for O(1) eviction. we'll design it such that the start of the
// linked list is the least recently used entry and the end is the most recently
// used.
class Node
{
  public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr)
    {
    }
};

class LRUCache
{
  public:
    // dummy nodes
    Node *start;
    Node *end;

    void llInsertEnd(Node *n)
    {
        n->prev = end->prev;
        n->next = end;
        end->prev->next = n;
        end->prev = n;
    }

    void llRemove(Node *n)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    // having the value be the node pointer itself makes it easy to find a key's
    // node in the linked list.
    unordered_map<int, Node *> cache;
    int cap;
    LRUCache(int capacity) : cap(capacity)
    {
        start = new Node(-1, -1);
        end = new Node(-1, -1);
        start->next = end;
        end->prev = start;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        // move to most recently used
        llRemove(cache[key]);
        llInsertEnd(cache[key]);
        return cache[key]->val;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            // key exists; this is an update
            cache[key]->val = value;
            llRemove(cache[key]);
            llInsertEnd(cache[key]);
        }
        else
        {
            // put new key; might have to evict
            Node *n = new Node(key, value);
            cache[key] = n;
            llInsertEnd(cache[key]);
            if (cache.size() > cap)
            {
                // have to evict leftmost node
                Node *lru = start->next;
                llRemove(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */