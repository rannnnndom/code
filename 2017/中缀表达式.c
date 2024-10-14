//对该二叉树采用中序遍历，设置一开始的深度为1，用递归的方法先访问左子树并且深度加1
//若左子树的节点无孩子则输出该节点字符，返回输出双亲节点字符继续访问右子树。若深度大于1则加左括号，若访问完右子树且深度大于1则输出右括号。
//持续该步骤直到每个节点都被访问
typedef struct node
{
    char data[10];  //存储操作数或操作符
    struct node *left, *right;
}BTree;

void BTreetoE(BTree *root, int d)
{
    inorder(root, 1);
}

void inorder(BTree *root, int depth)
{
    if(root->left == NULL && root->right == NULL)
    {
        printf("%s", root->data);
        return;
    }
    else
    {
        if(depth > 1) printf("(");
        inorder(root->left, depth + 1);
        printf("%s", root->data);
        inorder(root->right, depth + 1);
        if(depth > 1) printf(")");
    }
}