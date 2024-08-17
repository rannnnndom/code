//将该数组的前p个元素保存到一个辅助数组中
//再将后面的元素依次替换，最后再将辅助数组中的元素加入原数组中
void f(int R[], int p)
{
    int arr[p], temp = p, j = 0;
    int n = sizeof(R) / sizeof(R[0]);

    for(int i = 0; i < p; i++)
    {
        arr[i] = R[i];
    }
    
    while(temp != n)
    {
        R[j] = R[temp];
        j++;
        temp++;
    }

    for(int i = 0; i < p; i++)
    {
        R[p + i] = arr[i];
    }
}
//时间复杂度为O(n) = O(p) + O(p - n) + O(p),空间复杂度为O(p)