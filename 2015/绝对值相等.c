//1，初始化一个大小为n+1的数组用来保存不同结点的不同绝对值的数。设置两个指针分别指向链表的第一和第二的位置。
//2，遍历数组和第二个位置的指针的绝对值是否相等，若相等则将标志位置1，并将第二个指针后移，并将标志置为0
//3，遍历完数组后若标志位为0说明没有相同的绝对值，将第二个指针的绝对值放入辅助数组中。
//4，若p指针的下一个位不为q指针，则将第一个指针的下一位指向q，若是，则将两指针分别后移，
//5，循环执行第二步到第五步操作直到q为空。
typedef struct LNode
{
    int data;
    struct LNode *link;
}LNode *Linklist;

int abs(int n)//绝对值函数
{
    if(n < 0) return -n;
    return n;
}

void f(Linklist head, int n)
{
    int nums[n + 1] = {0}; // 初始化一个数组，用于存储已访问节点的绝对值
    LNode *p = head->link; // 指向链表的第一个有效节点
    LNode *q = p->link;    // 指向链表的第二个节点
    int flag = 0, count = 0;
    nums[count] = abs(p->data); // 将第一个节点的绝对值存入 nums 数组

    while(q != NULL)
    {
        int len = sizeof(nums) / sizeof(nums[0]); // 计算 nums 数组的长度
        for(int i = 0; i < len; i++) // 检查当前节点的绝对值是否已在 nums 数组中
        {
            if(abs(q->data) == nums[i])
            {
                flag = 1; // 如果找到相同的绝对值，设置标志位为 1
                break;
            }
        }

        if(flag == 1) // 如果标志位为 1，跳过当前节点
        {
            q = q->link;
            flag = 0;
        }
        else if(flag == 0) // 如果没有找到相同的绝对值
        {
            count++;
            nums[count] = abs(q->data); // 将当前节点的绝对值添加到 nums 数组中
            if(p->link != q) p->link = q; // 跳过重复节点，将前一个节点的 link 指向下一个非重复节点
            p = p->link; // p 移动到下一个节点
            q = q->link; // q 移动到下一个节点
        }
    }
}
//时间复杂度O(m*n),空间复杂度O(n)