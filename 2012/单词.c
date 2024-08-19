//设置一个查找函数用来查找str1和str2的链表长度，并分别设置为m和n
//若m大于n则将指向str1的头结点的指针p往下一个位置移动m-n位
//若m小于n则将指向str1的头结点的指针q往下一个位置移动n-m位
//此时p和q指针指向两链表长度相同的位置，对比当前结点是否重合，若是则返回指针指向的当前共同后缀起始位置，若不是则将两指针同时移向下一个位置
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

int listlen(LNode *list)
{
    LNode *p = list->next;
    int count = 1;
    while(p != NULL)
    {
        p = p->next;
        count++;
    }

    return count;
}

LNode* find_list(Linklist str1, Linklist str2)
{
    int m, n;
    LNode *p = str1->next, *q = str2->next;
    m = listlen(str1);
    n = listlen(str2);
    if(m > n)
    {
        for(int i = 0; i < m - n; i++)
        {
            p = p->next;
        }
    }
    else if(m < n)
    {
        for(int i = 0; i < n - m; i++)
        {
            q = q->next;
        }
    }

    while(p != NULL && p != q)
    {
        p = p->next;
        q = q->next;
    }

    return p;
}
//时间复杂度O(max(m, n)), 空间复杂度O(1)