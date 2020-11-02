#include <stdio.h>
#include <string.h>
#include <time.h>
//insertion Sort Algorithm
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


void insertionSortName(char arr[], int n) 
{
    int i, j;
    char key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void swapChar(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

//Selection Algorithm
void selectionSort(int arr[], int n) 
{ 
    int i, j, min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 

void selectionSortName(char arr[], int n) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapChar(&arr[min], &arr[i]); 
    } 
} 
// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void bubbleSortName(char arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapChar(&arr[j], &arr[j+1]); 
} 
// Merge sort algorithm
void merge(int arr[], int l, int m, int r) 
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

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
 
        merge(arr, l, m, r); 
    } 
} 
 
void mergeName(char arr[], int l, int m, int r) 
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

void mergeSortName(char arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
 
        mergeSortName(arr, l, m); 
        mergeSortName(arr, m + 1, r); 
 
        mergeName(arr, l, m, r); 
    } 
}

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 


int main() {

    //Ýnsertion Sort
    clock_t begin,end;

    int no[] = { 2, 0, 1, 7, 5, 5, 5, 0, 5, 4 }; 
    char name[] = "aslihan sonmez"; 
    int n = sizeof(no) / sizeof(no[0]); 
   
    int t;
    t = clock();
    insertionSort(no, 10);
    t = clock() - t;
    printArray(no, 10); 
    printf("insertion sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    
    insertionSortName(name, 13);
    end = clock();
    t = clock() - t;
    printf("%s\n", name);
    printf("insertion name sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    //Selection Sort
    
    selectionSort(no, n);
    printArray(no, n); 
    printf("selection sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    selectionSortName(name, 13);
    printf("%s\n", name);
    printf("selection name sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    
    //Bubble Sort
    
    bubbleSort(no, n); 
    printArray(no, n); 
    printf("bubble sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    bubbleSortName(name, 13);
    printf("%s\n", name);
    printf("bubble name sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);


    //Merge Sort

    mergeSort(no, 0, n - 1);
    t = clock() - t;
    printArray(no, n); 
    printf("merge sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    mergeSortName(name, 0, 13 - 1);
    t = clock() - t;
    printf("%s\n", name);
    printf("merge name sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
}
