//从数组中构造的二叉树开始，从底向上检查每个节点是否符合BST的性质。
//每个子树的最大值和最小值通过 pmin 和 pmax 数组来维护，逐步递归检查并更新父节点。
//如果发现有节点不符合BST的性质，代码立即返回 false，否则最终返回 true，并通过主函数输出判断结果。
typedef struct SqBiTNode
{    //MAX_SIZE为已定义常量
    int SqBiTNode(MAX_SIZE); //保存二叉树节点值的数组
    int ElemNum; //实际占用的数组元素的个数
}SqBiTNode;

bool judgeisBST(SqBiTNode bt) //初试时k的值为0
{
    int k, m, *pmin, *pmax;
    // 分配最小值和最大值数组的空间
    pmin = (int *)malloc(sizeof(int) * bt.ElemNum);
    pmax = (int *)malloc(sizeof(int) * bt.ElemNum);

    // 初始化pmin和pmax数组
    for(k = 0; k < bt.ElemNum; k++)
    {
        pmin = pmax = bt.SqBiTNode[k];// 初始时min和max都是节点本身的值
    }

    // 从下至上遍历数组，检查是否满足BST条件
    for(k = bt.ElemNum - 1; k > 0; k--)
    {
        // 找到父节点
        m = (k - 1) / 2;

        // 如果是左子节点
        if(k % 2 == 1 && bt.SqBiTNode[m] > pmax[k])
        {
            pmin[m] = pmin[k];// 更新父节点的最小值
        }
        // 如果是右子节点
        else if(k % 2 == 0 && bt.SqBiTNode[m] < pmin[k])
        {
            pmax[m] = pmax[k];// 更新父节点的最大值
        }
        else return false; // 如果不满足BST性质
    }

    return true;// 满足BST条件
}