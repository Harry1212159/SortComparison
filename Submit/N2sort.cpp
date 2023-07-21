#include "DataGenerator.cpp"

//shaker sort
void shakerSortVerComp(int arr[], int size, long long &count)
{
    bool done = false;
    int left = 0;
    int right = size - 1;
    while (++count && !done)
    {
        done = true;
        for (int i = left; ++count && i < right; ++i)
        {
            if (++count && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                done = false;
            }
        }
        if (++count && done)
            break;
        done = false;
        --right;
        for (int i = right - 1; ++count && i >= left; --i)
        {
            if (++count && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                done = false;
            }
        }
        ++left;
    }
}

void shakerSortVerTime(int arr[], int size, double &duration)
{
    clock_t start, end;
    start = double(clock());

    bool done = false;
    int left = 0;
    int right = size - 1;
    while (!done)
    {
        done = true;
        for (int i = left; i < right; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                done = false;
            }
        }
        if (done)
            break;
        done = false;
        --right;
        for (int i = right - 1; i >= left; --i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                done = false;
            }
        }
        ++left;
    }
    end = double(clock());
    duration = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

//insertion sort
void insertionSortVerComp(int array[], int size, long long &count)
{
    for (int i = 1; ++count && i < size; i++)
    {
        int value = array[i];
        int j = i - 1;
        while (++count && j >= 0 && ++count && array[j] > value)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = value;
    }
}

void insertionSortVerTime(int array[], int size, double &duration)
{
    clock_t start, end;
    start = double(clock());
    for (int i = 1; i < size; i++)
    {
        int value = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > value)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = value;
    }
    end = double(clock());
    duration = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

//selection sort 
void selectionSortVerComp(int arr[], int n, long long &comp)
{
    for (int i = 0; ++comp && i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; ++comp && j < n; j++)
        {
            if (++comp && arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (++comp && minIndex != i)
            swap(arr[minIndex], arr[i]);
    }
}

void selectionSortVerTime(int arr[], int n, double &time)
{
    clock_t start, end;
    start = double(clock());
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(arr[minIndex], arr[i]);
    }
    end = double(clock());
    time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

//bubble sort
void bubbleSort(int a[], int n){
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = n - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
                flag = false;
            }
        }
        if(flag)
            break;
    }
}

void bubbleSortVerComp(int a[], int n, long long &comp){
    for(int i = 0; ++comp && i < n; i++){
        bool flag = true;
        for(int j = n - 1; ++comp && j > i; j--){
            if(++comp && a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
                flag = false;
            }
        }
        if(++comp && flag)
            break;
    }
}

void bubbleSortVerTime(int a[], int n, double &time){
    clock_t start, end;
    start = double(clock());
    
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = n - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
                flag = false;
            }
        }
        if(flag)
            break;
    }

    end = double(clock());
    time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}

//shell sort
void shellSort(int a[], int n)
{
    int interval, i, j, temp;
    for(interval = n / 2; interval > 0; interval /= 2){
        for(i = interval; i < n; i++){
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}

void shellSortVerComp(int a[], int n, long long &comp)
{
    int interval, i, j, temp;
    for(interval = n / 2; ++comp && interval > 0; interval /= 2){
        for(i = interval; ++comp && i < n; i++){
			temp = a[i];
			for(j = i; ++comp && j >= interval && ++comp && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}

void shellSortVerTime(int a[], int n, double &time)
{
    clock_t start, end;
    start = double(clock());
    shellSort(a, n);
    end = double(clock());
    time = (double(end) - double(start)) / double(CLOCKS_PER_SEC);
}