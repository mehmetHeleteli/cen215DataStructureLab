#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Integer array with insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// Char array with insertion sort

void insertionSortChar(char arr[], int n)
{
    int i, j;
    char key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//integer type array with selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}

//Char array with selection sort
void selectionSortChar(char arr[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swapChar(&arr[min], &arr[i]);
    }
}

//bubble sort for integers
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

//bubble sort for chars
void bubbleSortChar(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapChar(&arr[j], &arr[j + 1]);
}

// Merge sort algorithm
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void mergeChar(char arr[], int l, int m, int r)
{
    int i, j, k;
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortChar(char arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortChar(arr, l, m);
        mergeSortChar(arr, m + 1, r);

        mergeChar(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for ( j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

    int partitionChar(char arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);
        int j;
        for ( j = low; j <= high- 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swapChar(&arr[i], &arr[j]);
            }
        }
        swapChar(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void quickSortChar(char arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partitionChar(arr, low, high);
            quickSortChar(arr, low, pi - 1);
            quickSortChar(arr, pi + 1, high);
        }
    }


    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n)
    {

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i=n-1; i>=0; i--)
        {
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
    }

    void heapifyChar(char arr[], int n, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swapChar(&arr[i], &arr[largest]);
            heapifyChar(arr, n, largest);
        }
    }

    void heapSortChar(char arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyChar(arr, n, i);

        for (int i=n-1; i>=0; i--)
        {
            swapChar(&arr[0], &arr[i]);
            heapifyChar(arr, i, 0);
        }
    }

int main()
{

    printf("\n\tNAME: ERGİN CETİN - SCHOOL ID: 2019556021\n");
    int schoolid[] = { 2,0,1,9,5,5,6,0,2,1 };
    char name[] = "Ergin Cetin";
    int numSize = sizeof(schoolid) / sizeof(schoolid[0]);
    int nameSize = strlen(name);
    clock_t start, end;
    double totaltime;

    //time computations for insertion sort.

    start = clock();
    insertionSort(schoolid, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tInsertion sort for number array : ");
    printArray(schoolid, numSize);
    printf("\tTime for insertion sort integer array => %f", totaltime);

    start = clock();
    insertionSortChar(name, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tInsertion sort for name array : ");
    printf("%s", name);
    printf("\n\tTime for insertion sort char array => %f\n", totaltime);
    printf("\t............................................");
    //time computations for selection sort

    int schoolid2[] = { 2,0,1,9,5,5,6,0,2,1 };
    char name2[] = "Ergin Cetin";

    start = clock();
    selectionSort(schoolid2, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tSelection sort for number array : ");
    printArray(schoolid2, numSize);
    printf("\tTime for selection sort with int array => %f", totaltime);

    start = clock();
    selectionSortChar(name2, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tSelection sort for name array : ");
    printf("%s", name2);
    printf("\n\tTime for selection sort with char array => %f\n", totaltime);

    printf("\t.........................................");
    //time computations for bubble sort
    int schoolid3[] = { 2,0,1,9,5,5,6,0,2,1 };
    char name3[] = "Ergin Cetin";

    start = clock();
    bubbleSort(schoolid3, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tBubble sort for number array : ");
    printArray(schoolid3, numSize);
    printf("\tTime for bubble sort with int array => %f\n", totaltime);

    start = clock();
    bubbleSortChar(name3, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\tBubble sort for name array : ");
    printf("%s\n", name3);
    printf("\tTime for bubble sort with char array => %f\n", totaltime);
    printf("\t.......................................");
    //time computations for merge sort
    int schoolid4[] = { 2,0,1,9,5,5,6,0,2,1};
    char name4[] = "Ergin Cetin";

    start = clock();
    mergeSort(schoolid4, 0, numSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tMerge sort for int array : ");
    printArray(schoolid4, numSize);
    printf("\tTime for merge sort with int array => %f", totaltime);

    start = clock();
    mergeSortChar(name4, 0, nameSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tMerge sort for name array : ");
    printf("%s", name4);
    printf("\n\tTime for merge sort with char array => %f", totaltime);
    printf("\n\t........................................");
    
    //time computations for quickSort
    
    int schoolid5[] = { 2,0,1,9,5,5,6,0,2,1};
    char name5[] = "Ergin Cetin";

    start = clock();
    quickSort(schoolid5, 0, numSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tQuick sort for int array : ");
    printArray(schoolid5, numSize);
    printf("\tTime for quick sort with int array => %f", totaltime);

    start = clock();
    quickSortChar(name5, 0, nameSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tQuick sort for name array : ");
    printf("%s", name5);
    printf("\n\tTime for quick sort with char array => %f", totaltime);
    printf("\n\t...................................");
    
    //time computations for heap sort
    int schoolid6[] = { 2,0,1,9,5,5,6,0,2,1};
    char name6[] = "Ergin Cetin";

    start = clock();
    heapSort(schoolid6, numSize );
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tHeap sort for int array : ");
    printArray(schoolid6, numSize);
    printf("\tTime for heap sort with int array => %f", totaltime);

    start = clock();
    heapSortChar(name6, nameSize );
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\tHeap sort for name array : ");
    printf("%s", name6);
    printf("\n\tTime for heap sort with char array => %f", totaltime);

    return 0;
}



