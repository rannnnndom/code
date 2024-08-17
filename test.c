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