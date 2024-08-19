/*1. 寻找链表的中点
首先，使用快慢指针的方法找到链表的中间节点。slow 指针每次走一步，而 fast 指针每次走两步。当 fast 到达链表末尾时，slow 指针指向的节点就是链表的中间节点。
2. 反转链表的后半部分
在找到中点之后，将链表从中间断开，并反转链表的后半部分。反转后，后半部分的节点顺序就变成了从最后一个节点到中点的顺序。
3. 合并前半部分和反转后的后半部分
最后，将前半部分和反转后的后半部分交替连接。通过依次选择前半部分的第一个节点和后半部分的第一个节点来进行交替连接，直到后半部分的节点全部合并到前半部分中。*/
typedef struct node
{
    int data;
    struct node*next;
}NODE;

void fun(NODE *L, int n)
{
    NODE *slow = L->next, *fast = L->next->next, *p, *q, *f = L->next, *prev = NULL;
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    p = slow->next;
    slow->next = NULL;

    while(p->next != NULL)
    {
        q = p->next;
        p->next = prev;
        prev = p;
        p = q;
    }

    while(f != NULL)
    {
        NODE *tmp1 = f->next;
        NODE *tmp2 = p->next;
        f->next = p;
        p->next = tmp1;
        f = tmp1;
        p = tmp2;
    }
}
//时间复杂度: O(n)，空间复杂度: O(1)