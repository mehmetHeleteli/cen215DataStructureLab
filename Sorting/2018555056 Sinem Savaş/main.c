#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

    /*Insertion sort*/
void insertionSort(int arr[], int size) 

{ 

    int i, m, j; 
    for (i = 1; i < size; i++)
	 { 
        m = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > m) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        
        arr[j + 1] = m; 
        
    } 
} 
void insertionSortChar(char arr[], int size) 

{
    int i, j;
    
    char m;
    
    for(i = 1; i < size; i++)
	 {
        m = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > m) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = m;
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

    /*Selection Sort*/
void selectionSort(int arr[], int size2) 
{ 
    int i, m, j;  
    for (i = 0; i < size2-1; i++) 
    { 
    
        m = i; 
        for (j = i+1; j < size2; j++) 
          if (arr[j] < arr[m]) 
            m = j; 
        swap(&arr[m], &arr[i]); 
        
    } 
    
} 

void selectionSortChar(char arr[], int size2) 
{ 
    int i, j;
    char m;  
    for (i = 0; i < size2-1; i++) 
    { 
        m = i; 
        for (j = i+1; j < size2; j++) 
          if (arr[j] < arr[m]) 
            m = j; 
        swapChar(&arr[m], &arr[i]); 
    } 
} 


   /*Bubble sort*/
   
void bubbleSort(int arr[], int size3) 
{ 

   int i, j; 
   for (i = 0; i < size3-1; i++)          
       for (j = 0; j < size3-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]);
			  
			   
} 

void bubbleSortChar(char arr[], int size3) 
{ 
   int i, j; 
   for (i = 0; i < size3-1; i++)          
       for (j = 0; j < size3-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapChar(&arr[j], &arr[j+1]); 
} 


  /* Merge sort*/
void merge(int arr[], int a, int b, int c) 

{ 
    int i, j, k, p, z; 
    p = b - a + 1; 
    z = c - b; 

    int A[p], B[z]; 

    for (i = 0; i < p; i++) 
        A[i] = arr[a + i]; 
    for (j = 0; j < z; j++) 
        B[j] = arr[b + 1 + j]; 

    i = 0; 
    j = 0; 
    k = a; 

    while (i < p && j < z) { 
        if (A[i] <= B[j]) { 
            arr[k] = A[i]; 
            i++; 
        } 
        else { 
            arr[k] = B[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < p) { 
        arr[k] = A[i]; 
        
        i++; 
        
        k++; 
    } 

    while (j < z) { 
        arr[k] = B[j]; 
        
        j++; 
        
        k++; 
    } 
} 

void mergeSort(int arr[], int a, int c) 
{ 
    if (a < c) { 
        int x = a + (c - a) / 2; 

        mergeSort(arr, a, x); 
        
        mergeSort(arr, x + 1, c); 

        merge(arr, a, x, c); 
    } 
} 

void mergeChar(char arr[], int a, int b, int c) 
{ 
    int i, j, k, p, z; 
    
    p = b - a + 1; 
    
    z = c - b; 

    int A[p], B[z]; 

    for (i = 0; i < p; i++) 
    
        A[i] = arr[a + i]; 
    for (j = 0; j < z; j++) 
    
    
        B[j] = arr[b + 1 + j]; 
          i = 0; 
          j = 0; 
          k = a; 

    while (i < p && j < z) 
	{ 
        if (A[i] <= B[j])
		 { 
            arr[k] = A[i]; 
            i++; 
        } 
        else { 
            arr[k] = B[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < p) 
	{ 
        arr[k] = A[i]; 
        i++; 
        k++; 
    } 

    while (j < z) { 
        arr[k] = B[j]; 
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

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  int j;
  for ( j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi - 1);
      quick_sort(arr, pi + 1, high);
  }
}
char partitionChar(char arr[], int low, int high)
{
  int pivot = arr[high];

  int i = (low - 1);
  int j;
  for ( j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swapChar(&arr[i], &arr[j]);
    }
  }
    swapChar(&arr[i + 1], &arr[high]);
  return (i + 1);
}
void quick_sort_char(char arr[], int low, int high)
{
  if (low < high)
  {
    int pIndex = partitionChar(arr, low, high);

    quick_sort_char(arr, low, pIndex - 1);
    quick_sort_char(arr, pIndex + 1, high);
  }
}

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

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

void heap_sort(int arr[], int n)
{
  int i, j;
  for (i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (j = n - 1; j > 0; j--)
  {
    swap(&arr[0], &arr[j]);
    heapify(arr, j, 0);
  }
}

void heapify_char(char arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i)
  {
      swapChar(&arr[i], &arr[largest]);
      heapify_char(arr, n, largest);
  }
}

void heapSortChar(char arr[], int n)
{
  int i, j;
  for (i = n / 2 - 1; i >= 0; i--)
  {
      heapify_char(arr, n, i);
  }

  for (j = n - 1; j > 0; j--)
  {
      swapChar(&arr[0], &arr[j]);
      heapify_char(arr, j, 0);
  }
}

int main() {

    
      
    int num[] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 6 }; 
    
    char name[] = "sinem savas"; 
    
     clock_t start;/*clock*/
     
    int size = sizeof(num) / sizeof(num[0]);
	 
    int charSize = strlen(name);

    start = clock();
    insertionSort(num, size);
    start = clock() - start;
    printArray(num, size); 
    printf("Time of Insertion Sort: %f\n", ((double)start) / CLOCKS_PER_SEC);
    
    insertionSortChar(name, charSize);
    
    start = clock() - start;
    
    printf("%s\n", name);
    
    printf("Time of char Insertion  Sort:  %f\n\n", ((double)start) / CLOCKS_PER_SEC);

    
	    /*Selection sort*/
    int num1[] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 6 }; 
    
    char name1[] = "sinem savas"; 
    
    int size1 = sizeof(num1) / sizeof(num1[0]); 
    int charSize1 = strlen(name1);
    selectionSort(num1, size1);
    
    start = clock() - start;
    
    
    printArray(num1, size1); 
    
    printf("Time of Selection Sort: %f\n", ((double)start) / CLOCKS_PER_SEC);

    selectionSortChar(name1, charSize1);
    start = clock() - start;
    printf("%s \n", name1);
    printf("Time of char Selection Sort: %f\n\n", ((double)start) / CLOCKS_PER_SEC);


       /*Bubble Sort*/

    int num2[] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 6 }; 
    
    char name2[] = "sinem savas"; 
    
    int size2 = sizeof(num2) / sizeof(num2[0]); 
    int charSize2 = strlen(name2);

    bubbleSort(num2, size2);
    start = clock() - start;
    printArray(num2, size2); 
    printf("Time of Bubble Sort: %f\n", ((double)start) / CLOCKS_PER_SEC);

    bubbleSortChar(name2, charSize2);
    
    start = clock() - start;
    
    printf("%s\n", name2);
    
    printf("Time of char Bubble Sort: %f\n\n", ((double)start) / CLOCKS_PER_SEC);


        /*Merge Sort*/
    
    int num3[] = { 2, 0, 1, 8, 5, 5, 5, 0, 5, 6 }; 
    char name3[] = "sinem savas"; 
    int size3 = sizeof(num3) / sizeof(num3[0]); 
    int charSize3 = strlen(name3);

    mergeSort(num3, 0, size3 - 1);
    
    start = clock() - start;
    
    printArray(num3, size3); 
    printf("Time of Merge Sort: %f\n", ((double)start) / CLOCKS_PER_SEC);
    
    mergeSortChar(name3, 0, charSize3 - 1);
    start = clock() - start;
    printf("%s\n", name3);
    printf("Time of char Merge Sort: %f\n\n", ((double)start) / CLOCKS_PER_SEC);
    
     /*Quick Sort*/
     
    quick_sort(num3, 0, size3 - 1);
    start = clock()-start;
    printArray(num3, size3);
    printf("Time of quick sort: %f\n", (double)start / CLOCKS_PER_SEC);
    quick_sort_char(name3, 0, size3-1 );
   start = clock() - start;
    printf("%s\n", name3);
    printf("Time of quick char sort: %f\n\n", (double)start / CLOCKS_PER_SEC);
     

         /* Heap Sort*/
    
    heap_sort(num3, size3);
    start = clock()-start;
    printArray(num3, size3);
    printf("Time of heap sort: %f\n", (double)start / CLOCKS_PER_SEC);
    heapSortChar(name3, size3);
    start = clock()-start;
    printf("%s\n", name3);
    printf("Time of quick char: %f\n", (double)start / CLOCKS_PER_SEC);

    return 0;
} 
