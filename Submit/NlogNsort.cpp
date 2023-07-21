#include "N2sort.cpp"

//merge sort
void merge(int a[], int left, int right)
{
    int *temp = new int[right - left + 1];
    int mid = left + (right - left) / 2;
    int index = 0, left_id = left, right_id = mid + 1;
    for (int i = left; i <= right; i++)
    {
        if ((right_id > right) || ((left_id <= mid) && (a[left_id] <= a[right_id])))
            temp[index++] = a[left_id++];
        else
            temp[index++] = a[right_id++];
    }
    for (int i = left; i <= right; i++)
        a[i] = temp[i - left];
    delete[] temp;
}

void mergeVerComp(int a[], int left, int right, long long &comp)
{
    int *temp = new int[right - left + 1];
    int mid = left + (right - left) / 2;
    int index = 0, left_id = left, right_id = mid + 1;
    for (int i = left; ++comp && i <= right; i++)
    {
        if ((++comp && right_id > right) || ((++comp && left_id <= mid) && (++comp && a[left_id] <= a[right_id])))
            temp[index++] = a[left_id++];
        else
            temp[index++] = a[right_id++];
    }
    for (int i = left; ++comp && i <= right; i++)
        a[i] = temp[i - left];
    delete[] temp;
}

void mergeSort(int a[], int first, int last){
    int mid = (first + last) / 2;
    if(first < last){
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, last);
    }
}

void mergeSortVerComp(int a[], int left, int right, long long &comp)
{
    if (++comp && left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortVerComp(a, left, mid, comp);
        mergeSortVerComp(a, mid + 1, right, comp);
        mergeVerComp(a, left, right, comp);
    }
}

void mergeSortVerTime(int a[], int left, int right, double &time)
{
    clock_t start, end;
    start = double(clock());
    mergeSort(a, left, right);
    end = double(clock());
    time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

//quick sort
void quickSortVerComp(int array[], int left, int right, long long &count)
{
    int pivot = array[left + (right - left) / 2];
    int i = left, j = right;
    while (++count && i <= j)
    {
        while (++count && array[i] < pivot)
            i++;
        while (++count && array[j] > pivot)
            j--;
        if (++count && i <= j)
            swap(array[i++], array[j--]);
    }
    if (++count && j > left)
        quickSortVerComp(array, left, j, count);
    if (++count && i < right)
        quickSortVerComp(array, i, right, count);
}

void quickSort(int array[], int left, int right)
{
    int pivot = array[left + (right - left) / 2];
    int i = left, j = right;
    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
            swap(array[i++], array[j--]);
    }
    if (j > left)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}

void quickSortVerTime(int array[], int left, int right, double &duration)
{
    clock_t start, end;
    start = double(clock());
    quickSort(array, left, right);
    end = double(clock());
    duration = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

//heap sort
void heapifyVerComp(int a[], int n, int k, long long &comp)
{
    int lc = 2 * k + 1, rc = 2 * k + 2;
    if (++comp && lc >= n)
        return;
    int maxc = lc;
    if ((++comp && rc < n) && (++comp && a[rc] > a[lc]))
        maxc = rc;
    if (++comp && a[maxc] > a[k])
    {
        swap(a[maxc], a[k]);
        heapifyVerComp(a, n, maxc, comp);
    }
}

void heapify(int a[], int n, int k)
{
    int lc = 2 * k + 1, rc = 2 * k + 2;
    if (lc >= n)
        return;
    int maxc = lc;
    if (rc < n && a[rc] > a[lc])
        maxc = rc;
    if (a[maxc] > a[k])
    {
        swap(a[maxc], a[k]);
        heapify(a, n, maxc);
    }
}

void heapSortVerComp(int a[], int n, long long &comp)
{
    for (int i = (n - 1) / 2; ++comp && i >= 0; i--)
        heapifyVerComp(a, n, i, comp);
    int heapSize = n;
    while (++comp && heapSize)
    {
        swap(a[0], a[--heapSize]);
        heapifyVerComp(a, heapSize, 0, comp);
    }
}

void heapSort(int a[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapify(a, n, i);
    int heapSize = n;
    while (heapSize)
    {
        swap(a[0], a[--heapSize]);
        heapify(a, heapSize, 0);
    }
}

void heapSortVerTime(int a[], int n, double &time)
{
    clock_t start, end;
    start = double(clock());
    heapSort(a, n);
    end = double(clock());
    time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}
