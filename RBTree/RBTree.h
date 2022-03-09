enum RBTColor
{
    RED,
    BLACK
};

struct RBTNode
{
    RBTColor color;  // 颜色
    int key;         // 关键字(键值)
    RBTNode *left;   // 左孩子
    RBTNode *right;  // 右孩子
    RBTNode *parent; // 父结点

    RBTNode(int x, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r) : key(x), color(c), parent(p), left(l), right(r) {}
};

class RBTree
{
public:
    RBTree();
    ~RBTree();

    // 左旋
    void left_rotate(RBTNode* root, RBTNode* x);

    // 右旋
    void right_rotate(RBTNode* root, RBTNode* y);

    // 插入结点
    void insert(int key);

    // 删除结点
    void remove(int key);

// private:
    // 插入函数
    void insert(RBTNode *root, RBTNode *node);

    // 插入修正函数
    void insert_fixup(RBTNode *root, RBTNode *node);

    // 删除函数
    void remove(RBTNode *root, RBTNode *node);

    // 删除修正函数
    void remove_fixup(RBTNode *root, RBTNode *node, RBTNode *parent);

    RBTNode *root;
};