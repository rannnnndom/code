//二叉树的WPL值 = 树中全部叶节点的带权路径长度之和
//叶节点的带权路径长度 = 该节点的weight值*该节点的深度
//设设该节点深度为0，某节点的深度为d,孩子节点的深度等于d + 1
//递归遍历该二叉树，若遍历到叶节点则返回该节点的带权路径长度，否则返回左右子树的带权路径长度之和
typedef struct node
{
    int weight;
    struct node *left, *right;
}Btree;

int WPL(Btree *root, int d)
{
    WPL1(root, 0);
}

int WPL1(Btree *root, int d)
{
    if(root->left == NULL && root->right == NULL)
    {
        return(root->weight * d);
    }
    else
    {
        return (WPL(root->left, d + 1) + WPL(root->right, d + 1));
    }
}
