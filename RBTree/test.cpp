struct Node
{
    int val;
    Node *left, *right, *parent;
    Node *pre, *next;
    Node() : val(0), left(nullptr), right(nullptr), parent(nullptr), pre(nullptr), next(nullptr) {}
    Node(int x): val(x), left(nullptr), right(nullptr), parent(nullptr), pre(nullptr), next(nullptr) {}
    Node(int x, Node *left): val(x), left(left), right(nullptr), parent(nullptr), pre(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right): val(x), left(left), right(right), parent(nullptr), pre(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *parent): val(x), left(left), right(right), parent(parent), pre(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *parent, Node *pre): val(x), left(left), right(right), parent(parent), pre(pre), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *parent, Node *pre, Node *next): val(x), left(left), right(right), parent(parent), pre(pre), next(next) {}
};

void max_heapify(Node *root, Node *tail)
{
    if (root == nullptr || tail == nullptr) return;

    Node *tmp = tail->parent;
    while (tmp != nullptr)
    {
        Node *max_node;
        if (tmp->left == nullptr) max_node = tmp->right;
        else max_node = tmp->left;
        if (tmp->val < max_node->val) swap(tmp->val, max_node->val);
        tmp = tmp->pre;
    }

}
void heap_sort(Node *root, Node *tail, int n)
{
    max_heapify(root, tail);
    for (int i = 0; i < n - 1; i++)
    {
        swap(root->val, tail->val);
        max_heapify(root, tail->pre);
    }
}