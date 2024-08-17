//将给定数组进行快速排序，将排序后的数组从前往后依次遍历，遍历相同的元素计数加1，直到遇到不同元素时计算计数是否大于n/2，
//若大于则输出该元素，否则将计数记为1继续遍历，直到数组末尾，若没有主元素返回-1
void swap(arr[], int i, int j)//交换两个元素
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)//哨兵划分
{
    int i = low, j = high;//初始化两指针指向数组两端
    while(i < j)
    {
        while(i < j && arr[j] >= arr[low])// 从右向左找首个小于基准数的元素
        {
            j--;
        }
        while(i < j && arr[i] <= arr[low])// 从左向右找首个大于基准数的元素
        {
            i++;
        }
        swap(arr, i, j);// 交换这两个元素
    }
    swap(arr, i, low);// 将基准数交换至两子数组的分界线
    return i;// 返回基准数的索引
}

void quicksort(int arr[], int low, int high)//快速排序
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, pi + 1, high);//快速排序右子数组
        quicksort(arr, low, pi - 1);//快速排序左子数组
    }
}

int f(int A[], int n)
{
    int i = 0, low = 0, high = n - 1, count = 1;//设置相关变量
    quicksort(A, low, high);//快速排序

    while(i != n)//遍历数组，计算数组元素出现的次数
    {
        if(A[i] == A[i + 1])
        {
            count++;
            i++;
        }
        else
        {
            if(count > n / 2)
            {
                return A[i];
            }
            else
            {
                count = 1;
                i++;
            }
        }
    }

    return -1;
}
//时间复杂度为O(nlog2n)，空间复杂度为O(1)