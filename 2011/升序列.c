//解法一：定义两个索引变量，分别指向两数组的首个元素，对比两索引变量所指向的元素的大小
//若A > B则将小的元素B放入辅助数组中，并移动该索引到下一个位置
//当遍历完一个数组时，将剩下数组的元素加入到辅助数组中。
//最后找出辅助数组中的中位数。
int f(int A[], int B[])
{
    int sizeA = sizeof(A) / sizeof(A[0]);//定义数组A的大小
    int sizeB = sizeof(B) / sizeof(B[0]);//定义数组B的大小
    int i = 0, j = 0, temp = 0, m = sizeA + sizeB + 1 / 2;//定义索引变量i, j,循环变量temp, m为中位数
    int arr[sizeA + sizeB];//定义辅助数组

    while(i != sizeA - 1 && j != sizeB - 1)//遍历两数组
    {
        if(A[i] > B[i])//将较小的元素放入辅助数组中
        {
            arr[temp] = B[j];
            temp++;
            j++;
        }
        else
        {
            arr[temp] = A[i];
            temp++;
            i++;
        }
    }

    while(i != sizeA - 1)//遍历剩下的数组
    {
        arr[temp] = A[i];
        temp++;
        i++;
    }

    while(j != sizeB - 1)//遍历剩下的数组
    {
        arr[temp] = B[j];
        temp++;
        j++;
    }

    return arr[m];//返回中位数
}
//时间复杂度为O(n),空间复杂度为O(n)。


//解法二：将两数组中的元素加入到一个辅助数组中并用快速排序得到升序的序列，最后得到中位数
void swap(int arr[], int i, int j)//交换两个元素
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
        swap(arr, i ,j);// 交换这两个元素
    }

    swap(arr, i, low);// 将基准数交换至两子数组的分界线
    return i;// 返回基准数的索引
}

void quicksort(int arr[], int low, int high)//快速排序
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);//快速排序左子数组
        quicksort(arr, pi + 1, high);//快速排序右子数组
    }
}

int f(int A[], int B[])
{
    int sizeA = sizeof(A) / sizeof(A[0]);//定义数组A的大小
    int sizeB = sizeof(B) / sizeof(B[0]);//定义数组B的大小
    int arr[sizeA + sizeB], m = sizeA + sizeB + 1 / 2;//定义辅助数组,m为中位数。

    for(int i = 0; i < sizeA; i++)//将两数组的元素放入辅助数组中
    {
        arr[i] = A[i];
    }
    for(int j = sizeA - 1; j < sizeA + sizeB; j++)
    {
        arr[j] = B[j];
    }

    quicksort(arr, 0, sizeA + sizeB - 1);//快速排序

    return arr[m];//返回中位数
}
//时间复杂度为O(n),空间复杂度为O(n)。


//解法三：使用二分查找的方式在两个等长升序数组中高效地找到中位数，通过比较并调整分割点来缩小搜索范围，直到找到合适的中位数值。

int fc(int A[], int B[], int n)
{
    int low = 0, high = n - 1;//定义索引指向数组的首元素和末尾元素。

    while(low <= high)
    {
        int i = (low + high) / 2;//找到数组的中位数
        int j = high - i;//找到另一个数组的中位数

        int Aleft = (i >= 0) ? A[i] : INT_MIN;//判断中位数是否在数组中
        int Aright = (i + 1 < n) ? A[i + 1] : INT_MAX;//判断中位数的右元素是否在数组中
        int Bleft = (j >= 0) ? B[j] : INT_MIN;//判断中位数是否在数组中
        int Bright = (j + 1 < n) ? B[j + 1] : INT_MAX;//判断中位数的右元素是否在数组中

        if (Aleft <= Bright && Bleft <= Aright) {
            // 找到了合适的分割点
            return (fmax(Aleft, Bleft) + fmin(Aright, Bright)) / 2;
        } else if (Aleft > Bright) {
            // A左边的值太大，缩小右边界
            high = i - 1;
        } else {
            // B左边的值太大，缩小左边界
            low = i + 1;
        }
    }
}
//由于算法每次都将查找范围减半，所以时间复杂度为对数级别O(log2 n),该算法只使用了常量级的额外空间，包括变量和常量。因此，空间复杂度为 O(1)。