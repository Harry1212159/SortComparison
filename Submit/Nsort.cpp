#include "NlogNsort.cpp"

//flash sort
void flashSortVerComp(int a[], int n, long long &comp)
{
    int MAXid = 0, MIN = a[0];
    for (int i = 1; ++comp && i < n; i++)
    {
        if (++comp && a[MAXid] < a[i])
            MAXid = i;
        MIN = min(MIN, a[i]);
    }
    if (++comp && a[MAXid] == MIN)
        return;

    int m = 0.1 * n;
    int *bucket = new int[m]{};
    bucket[0] = -1;
    double coef = (m - 1.0) / (a[MAXid] - MIN);

    // count the number of elements in each bucket
    for (int i = 0; i < n; i++)
    {
        int j = coef * (a[i] - MIN);
        bucket[j]++;
    }
    for (int i = 1; i < m; i++)
        bucket[i] += bucket[i - 1];

    // put elements in their rightful buckets
    swap(a[0], a[MAXid]);
    for (int i = 0, j = 0, k = m - 1; ++comp && i < n;)
    {
        for (; ++comp && j > bucket[k];)
            k = coef * (a[++j] - MIN);
        int temp = a[j];
        for (; ++comp && j <= bucket[k]; i++)
        {
            k = coef * (temp - MIN);
            swap(temp, a[bucket[k]--]);
        }
    }

    // insertion sort
    for (int i = 0; i < n; i++)
        for (int j = i; ++comp && j > 0 && ++comp && a[j - 1] > a[j]; j--)
            swap(a[j], a[j - 1]);

    delete[] bucket;
}

void flashSort(int a[], int n)
{
    int MAXid = 0, MIN = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[MAXid] < a[i])
            MAXid = i;
        MIN = min(MIN, a[i]);
    }
    if (a[MAXid] == MIN)
        return;

    int m = 0.1 * n;
    int *bucket = new int[m]{};
    bucket[0] = -1;
    double coef = (m - 1.0) / (a[MAXid] - MIN);

    // count the number of elements in each bucket
    for (int i = 0; i < n; i++)
    {
        int j = coef * (a[i] - MIN);
        bucket[j]++;
    }
    for (int i = 1; i < m; i++)
        bucket[i] += bucket[i - 1];

    // put elements in their rightful buckets
    swap(a[0], a[MAXid]);
    for (int i = 0, j = 0, k = m - 1; i < n;)
    {
        for (; j > bucket[k];)
            k = coef * (a[++j] - MIN);
        int temp = a[j];
        for (; j <= bucket[k]; i++)
        {
            k = coef * (temp - MIN);
            swap(temp, a[bucket[k]--]);
        }
    }

    // insertion sort
    for (int i = 0; i < n; i++)
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--)
            swap(a[j], a[j - 1]);

    delete[] bucket;
}
void flashSortVerTime(int a[], int n, double &time)
{
    clock_t start, end;
    start = double(clock());
    flashSort(a,n);
    end = double(clock());
    time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

//counting sort
void countingSortVerComp(int a[], int n, long long &comp)
{
    int MAX = a[0];
    for (int i = 1; ++comp && i < n; i++)
        if (++comp && MAX < a[i])
            MAX = a[i];

    int *temp = new int[MAX + 1];
    for (int i = 0; ++comp && i < MAX + 1; i++)
        temp[i] = 0;

    for (int i = 0; ++comp && i < n; i++)
        temp[a[i]]++;
    for (int i = 0, id = 0; ++comp && i <= MAX && ++comp && id < n; i++)
        while (++comp && temp[i]-- > 0)
            a[id++] = i;
    delete[] temp;
}

void countingSortVerTime(int a[], int n, double &time)
{
    clock_t start, end;
    start = double(clock());
    int MAX = a[0];
    for (int i = 1; i < n; i++)
        if (MAX < a[i])
            MAX = a[i];

    int *temp = new int[MAX + 1];
    for (int i = 0; i < MAX + 1; i++)
        temp[i] = 0;
    for (int i = 0; i < n; i++)
        temp[a[i]]++;
    for (int i = 0, id = 0; i <= MAX && id < n; i++)
        while (temp[i]-- > 0)
            a[id++] = i;
    delete[] temp;
    end = double(clock());
    time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

//radix sort 
void radixSortVerComp(int array[], int size, long long &count)
{
    int max = array[0];
    for (int i = 1; ++count && i < size; i++)
        if (max < array[i])
            max = array[i];

    for (int k = 1; ++count && k <= max; k *= 10)
    {
        int freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int *temp = new int[size];
        for (int i = 0; ++count && i < size; i++)
            temp[i] = 0;
        for (int i = 0; ++count && i < size; i++)
            freq[array[i] / k % 10]++;
        for (int i = 1; ++count && i <= 9; i++)
            freq[i] += freq[i - 1];
        for (int i = size - 1; ++count && i >= 0; i--)
        {
            int j = array[i] / k % 10;
            temp[freq[j] - 1] = array[i];
            freq[j]--;
        }
        for (int i = 0; ++count && i < size; i++)
            array[i] = temp[i];
        delete[] temp;
    }
}

void radixSortVerTime(int array[], int size, double &duration)
{
    clock_t start, end;
    start = double(clock());
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (max < array[i])
            max = array[i];

    for (int k = 1; k <= max; k *= 10)
    {
        int freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int *temp = new int[size];
        for (int i = 0; i < size; i++)
            temp[i] = 0;
        for (int i = 0; i < size; i++)
            freq[array[i] / k % 10]++;
        for (int i = 1; i <= 9; i++)
            freq[i] += freq[i - 1];
        for (int i = size - 1; i >= 0; i--)
        {
            int j = array[i] / k % 10;
            temp[freq[j] - 1] = array[i];
            freq[j]--;
        }
        for (int i = 0; i < size; i++)
            array[i] = temp[i];
        delete[] temp;
    }
    end = double(clock());
    duration = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}