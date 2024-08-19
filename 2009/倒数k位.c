//设置两个指针p和q分别指向链表的首元素，循环移动指针p到链表的下一个位置，并且计数加1
//若计数小于k并且指针p移到链表末尾，则该链表没有第k个位置查找失败，返回0
//若计数等于k时每次移动指针p和q到下一个位置，直到p指向空，此时q所指向元素的数据为倒数第k个位置的结点。
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode;

int search_k(LNode *list, int k)
{
    LNode *p = list->next, *q = list->next;
    int count = 0;
    while(p != NULL)
    {
        if(count < k) count++;
        else q = q->next;
        p = p->next;
    }

    if(count < k) return 0;
    else
    {
        printf("%d", q->data);
        return 1;
    }
}
//时间复杂度O(n)，空间复杂度O(1)