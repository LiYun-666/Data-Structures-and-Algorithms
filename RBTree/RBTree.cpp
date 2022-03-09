#include "RBTree.h"

RBTree::RBTree()
{
}
RBTree::~RBTree()
{
}

// 左旋
void RBTree::left_rotate(RBTNode *root, RBTNode *x)
{
    RBTNode *y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// 右旋
void RBTree::right_rotate(RBTNode *root, RBTNode *y)
{

    RBTNode *x = y->left;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}

// 插入结点
void RBTree::insert(int key)
{
    RBTNode *z = nullptr;

    // 如果新建结点失败，则返回。
    if ((z = new RBTNode(key, BLACK, nullptr, nullptr, nullptr)) == nullptr)
        return;

    insert(root, z);
}

// 插入函数
void RBTree::insert(RBTNode *root, RBTNode *z)
{
    RBTNode *y = nullptr;
    RBTNode *x = root;
    while (x != nullptr)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == nullptr)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    z->left = nullptr;
    z->right = nullptr;
    z->color = RED;
    insert_fixup(root, z);
}

// 插入修正函数
void RBTree::insert_fixup(RBTNode *root, RBTNode *z)
{
    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            RBTNode *y = z->parent->parent->right;
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else if (z == z->parent->right)
            {
                z = z->parent;
                right_rotate(root, z);
            }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            right_rotate(root, z->parent->parent);
        }
        else
        {
            RBTNode *x = z->parent->parent->left;
            if (x->color == RED)
            {
                z->parent->color = BLACK;
                x->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else if (z == z->parent->left)
            {
                z = z->parent;
                left_rotate(root, z);
            }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            left_rotate(root, z->parent->parent);
        }
    }
    root->color = BLACK;
}
// 删除结点
void RBTree::remove(int key)
{
}