#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
  public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
  public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        unordered_map<Node *, Node *> clones;
        Node *clone = clone_graph_recursive(node, clones);
        return clone;
    }

    // this does dfs
    Node *clone_graph_recursive(Node *node, unordered_map<Node *, Node *> &clones)
    {

        // base case: this node is already in the map
        if (clones.find(node) != clones.end())
            return clones[node];

        // recursive case: this node is not in the map
        Node *clone = new Node(node->val);
        clones[node] = clone;
        for (Node *neighbor : node->neighbors)
        {
            Node *neighbor_clone = clone_graph_recursive(neighbor, clones);

            // TODO: why don't we need to make the connection from the neighbor
            // to the clone?
            clone->neighbors.push_back(neighbor_clone);
            // neighbor_clone->neighbors.push_back(clone);
        }
        return clone;
    }
};