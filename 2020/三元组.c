//解法一：暴力求解，对比S1, S2, S3，每个元素的距离D,得到结果。
#define INT_MAX 0x7fffffff
int f(int S1[], int S2[], int S3[])
{
    int D = 0, mincount = INT_MAX;
    int n1 = sizeof(S1) / sizeof(S1[0]);
    int n2 = sizeof(S2) / sizeof(S2[0]);
    int n3 = sizeof(S3) / sizeof(S3[0]);
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            for(int k = 0; k < n3; k++)
            {
                D = abs(S1[i] - S2[j]) + abs(S2[j] - S3[k]) + abs(S3[k] - S1[i]);
                mincount = min(mincount, D);
            }
        }
    }

    return mincount;
}
//时间复杂度O(n^3), 空间复杂度O(1)

//解法二：设置数组下标都指向数组首元素,将三个数组中的最小值下标加1，找到更小值D
bool is_min(int a, int b, int c)
{
    if(a <= b && a <= c) return  true;
    return false;
}

int f(int S1[], int S2[], int S3[])
{
    int n1 = sizeof(S1) / sizeof(S1[0]);
    int n2 = sizeof(S2) / sizeof(S2[0]);
    int n3 = sizeof(S3) / sizeof(S3[0]);
    int i = 0, j = 0, k = 0, min_D = INT_MAX, D;
    while(i < n1 && j < n2 && k < n3 && min_D > 0)
    {
        D = abs(S1[i] - S2[j]) + abs(S2[j] - S3[k]) + abs(S3[k] - S1[i]);
        if(D < min_D) min_D = D;
        if(is_min(S1[i], S2[j], S3[k])) i++;
        else if (is_min(S2[i], S3[j], S1[k])) j++;
        else k++;
    }

    return min_D;
}
//时间复杂度O(n),空间复杂度O(1)