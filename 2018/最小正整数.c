//设置一个辅助数组长度为n，并将该辅助数组的元素依次从1设置为n
//对原数组进行快速排序，排序后设置两个索引指针分别指向原数组和辅助数组的首元素
//如果原数组的索引指针所指向的元素小于等于0则向后移动，如果为正整数则与辅助数组的元素进行对比
//若等于则两指针分别向后移动，若辅助数组元素小于原数组元素则返回辅助数组的元素，
//如果两数组都遍历到末尾，则返回n的值加1
void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int arr[], int low, int high)
{
    int i = low, j = high;
    while(i < j)
    {
        while(i < j && arr[i] <= arr[low])
        {
            i++;
        }
        while(i < j && arr[j] >= arr[low])
        {
            j--;
        }
        swap(arr, i, j);
    }
    swap(arr, i, low);
    return i;
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int f(int arr[], int n)
{
    int temp[n], low = 0, high = n - 1, j = 0, k = 0;
    for(int i = 1; i <= n; i++)
    {
        temp[i - 1] = i;
    }

    quicksort(arr, low, high);

    while(j != n)
    {
        if(arr[j] <= 0)
        {
            j++;
        }
        else if(temp[k] == arr[j])
        {
            k++;
            j++;
        }
        else if(temp[k] < arr[j])
        {
            return arr[k];
        }
    }

    return n + 1;
}
//时间复杂度O(nlogn), 空间复杂度O(n)