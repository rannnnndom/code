//将该数组的前p个元素保存到一个辅助数组中
//再将后面的元素依次替换，最后再将辅助数组中的元素加入原数组中
void f(int R[], int p)
{
    int arr[p], temp = p, j = 0;//定义辅助数组，将p赋给temp，循环控制变量j。
    int n = sizeof(R) / sizeof(R[0]);//计算数组长度n。

    for(int i = 0; i < p; i++)//将数组中前p个值保存在辅助数组中
    {
        arr[i] = R[i];
    }
    
    while(temp != n)//将原数组中的后面元素左移
    {
        R[j] = R[temp];
        j++;
        temp++;
    }

    for(int i = 0; i < p; i++)//将辅助数组中的元素加在原数组后面
    {
        R[p + i] = arr[i];
    }
}
//时间复杂度为O(n) = O(p) + O(p - n) + O(p),空间复杂度为O(p)