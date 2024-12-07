void swap(int nums[], int i, int j)
{
    int temp;
    temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(int nums[], int n)
{
    int i, j, low = 0, low1 = 0, high = 0, high1 = n - 1, k = n / 2, flag = 1, s1, s2;
    while(flag)
    {
        while(i < j)
        {
            while(i < j && nums[j] >= nums[low])
            {
                j -= 1;
            }
            while(i < j && nums[i] <= nums[low])
            {
                i += 1;
            }
            swap(nums, i, j);
        }
        swap(nums, i, low);

        if(low == k)
        {
            flag = 0;
        }
        else
        {
            if(low < k - 1)
            {
                low1 = low + 1;
                high = high1;
            }
            else
            {
                high1 = high - 1;
                low = low1;
            }
        }
    }
    for(int i = 0; i < k; i++) s1 += nums[i];
    for(int i = k; i < n; i++) s2 += nums[i];
    return s2 - s1;
}

