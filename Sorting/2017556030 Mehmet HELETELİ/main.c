#include<stdio.h>
#include<string.h>
#include<time.h>

//Selection sort function
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}
//Insertion sort function
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
//MergeSort
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
    k = l;     while (i < n1 && j < n2) {
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
//BubbleSort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place    
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//SelectionSortChar
void swapChar(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

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
//InsertionSortChar 
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
void mergeChar(char arr[], int l, int m, int r)
{
    int i, j, k, n1, n2;
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
//MergeSortChar
void mergeSortChar(char arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortChar(arr, l, m);
        mergeSortChar(arr, m + 1, r);

        mergeChar(arr, l, m, r);
    }
}
//BubbleSortChar
void bubbleSortChar(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapChar(&arr[j], &arr[j + 1]);
}
int main(int argc, char const* argv[]) {
    
    //SelectionSort
    clock_t t;

    int num[] = { 2,0,1,7,5,5,6,0,3,0 };
    char name[] = "mehmet heleteli";
    int numSize = sizeof(num) / sizeof(num[0]);
    int charSize = strlen(name);
    t = clock();
    selectionSort(num, numSize);
    t = clock() - t;
    printf("Selection sorted array is:\n");
    printArray(num, numSize);
    printf("Selection sort time:%f\n", ((double)t) / CLOCKS_PER_SEC);
    selectionSortChar(name, charSize);
    t = clock() - t;
    printf("%s\n", name);
    printf("Selection character sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    //InsertionSort
    int num1[] = { 2,0,1,7,5,5,6,0,3,0 };
    char name1[] = "mehmet heleteli";
    int numSize1 = sizeof(num1) / sizeof(num1[0]);
    int charSize1 = strlen(name1);
    t = clock();
    insertionSort(num1, numSize1);
    t = clock() - t;
    printf("\nInsertion sorted array is:\n");
    printArray(num1, numSize1);
    printf("Insertion sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    insertionSortChar(name1, charSize1);
    t = clock() - t;
    printf("%s\n", name1);
    printf("Insertion character sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    //MergeSort
    int num2[] = {2,0,1,7,5,5,6,0,3,0 };
    char name2[] =  "mehmet heleteli" ;
    int numSize2 = sizeof(num2) / sizeof(num2[0]);
    int charSize2 = strlen(name2);

    mergeSort(num2, 0, numSize2 - 1);
    t = clock() - t;
    printf("\nMerge sorted array is \n");
    printArray(num2, numSize2);
    printf("Merge sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    mergeSortChar(name2, 0, charSize2 - 1);
    t = clock() - t;
    printf("%s\n", name2);
    printf("Merge character sort time:%f\n", ((double)t) / CLOCKS_PER_SEC);

    //BubbleSort
    int num3[] = { 2,0,1,7,5,5,6,0,3,0 };
    char name3[] =  "mehmet heleteli" ;
    int numSize3 = sizeof(num3) / sizeof(num3[0]);
    int charSize3 = strlen(name3);
    bubbleSort(num3, numSize3);
    t = clock() - t;
    printf("\nBubble sorted array is:\n");
    printArray(num3, numSize3);
    printf("Bubble sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    bubbleSortChar(name3, charSize3);
    t = clock() - t;
    printf("%s", name3);
    printf("Bubble char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
}

