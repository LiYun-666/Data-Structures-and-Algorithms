enum RBTColor
{
    RED,
    BLACK
};

struct RBTNode
{
    RBTColor color;  // 颜色
    int val;         // 关键字(键值)
    RBTNode *left;   // 左孩子
    RBTNode *right;  // 右孩子
    RBTNode *parent; // 父结点

    RBTNode(int x, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r) : val(x), color(c), parent(p), left(l), right(r) {}
};

class RBTree
{
private:
    RBTNode *root;

public:
    RBTree(/* args */);
    ~RBTree();

    // 插入结点
    void insert(int val);

    // 删除结点
    void remove(int val);
};

RBTree::RBTree(/* args */)
{
}

RBTree::~RBTree()
{
}
