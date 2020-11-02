#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


//array print function
void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
} 

//swap function
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

//insertion sort 
void insertionsortNum(int arr[], int size) 
{ 
    int i, j;
	int element;

    for (i = 1; i < size; i++) { 
        element = arr[i]; 
        j = i - 1;

        while (j >= 0 && arr[j] > element) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = element; 
    } 
} 

void insertionsortName(char arr[], int size) 
{
    int i, j;
    char temp;

    for (i = 0; i < size -1; i++) {
      for (j = i+1; j < size; j++) {
         if (arr[i] > arr[j]) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }
}


//selection sort
void selectionsortNum(int arr[], int size2) 
{ 
    int i, j, min;  
    for (i = 0; i < size2 - 1; i++) 
    { 
        min = i; 
        for (j = i+1; j < size2; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 

void selectionsortName(char arr[], int size2) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < size2-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < size2; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapChar(&arr[min], &arr[i]); 
    } 
} 

//bubble sort
void bubblesortNum(int arr[], int size3) 
{ 
   int i, j; 

   for (i = 0; i < size3-1; i++)          
       for (j = 0; j < size3-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void bubblesortName(char arr[], int size3) 
{ 
   int i, j; 
   for (i = 0; i < size3-1; i++)          
       for (j = 0; j < size3-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapChar(&arr[j], &arr[j+1]); 
} 

//merge sort 
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

void mergeSortName(char arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 

        mergeSortName(arr, l, m); 
        mergeSortName(arr, m + 1, r); 

        mergeChar(arr, l, m, r); 
    } 
}

//quick sort
int partitionNum (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  	int j;
  	
    for (j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSortNum(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partitionNum(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSortNum(arr, low, pi - 1); 
        quickSortNum(arr, pi + 1, high); 
    } 
} 

char partitionName(char arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swapChar(&arr[i], &arr[j]);
        }
    }
    swapChar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortName(char arr[], int low, int high) {
    if (low < high) {
        int part = partitionName(arr, low, high);

        quickSortName(arr, low, part - 1);
        quickSortName(arr, part + 1, high);
    }
}
 
 
//heap sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSortNum(int arr[], int n) {
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (j = n - 1; j > 0; j--) {
        swap(&arr[0], &arr[j]);
        heapify(arr, j, 0);
    }
}

void heapifyName(char arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swapChar(&arr[i], &arr[largest]);
        heapifyName(arr, n, largest);
    }
}

void heapSortName(char arr[], int n) {
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapifyName(arr, n, i);

    for (j = n - 1; j > 0; j--) {
        swapChar(&arr[0], &arr[j]);
        heapifyName(arr, j, 0);
    }
} 
 

int main() {

	clock_t time;

	//insertion sort

    int num[] = {2, 0, 1, 8, 5, 5, 5, 0, 4, 0}; 
	char name[] = "ismet elyasa kazan"; 
	int size = sizeof(num) / sizeof(num[0]); 
    int charlen = strlen(name);

    time = clock();
	insertionsortNum(num, size);
	time = clock() - time;

    printf("Insertion Sort\n");
	printArr(num, size); 
	printf("\nTime for number: %f\n", ((double)time) / CLOCKS_PER_SEC);

  	time = clock();
    insertionsortName(name, charlen);
	time = clock() - time;

    printf("%s\n", name);
   	printf("Time for name: %f\n", ((double)time) / CLOCKS_PER_SEC);


    //selection sort

    int num2[] = {2, 0, 1, 8, 5, 5, 5, 0, 4, 0}; 
	char name2[] = "ismet elyasa kazan"; 
   	int size2 = sizeof(num2) / sizeof(num2[0]); 
	int charlen2 = strlen(name2);

  	time = clock();	
    selectionsortNum(num2, size2);
 	time = clock() - time;

	printf("\nSelection Sort\n");
	printArr(num2, size2); 
	printf("\nTime for number: %f", ((double)time) / CLOCKS_PER_SEC);

  	time = clock();	    
	selectionsortName(name2, charlen2);
 	time = clock() - time;

	printf("\n%s\n", name2);
    printf("Time for name: %f\n", ((double)time) / CLOCKS_PER_SEC);


	//bubble sort

	int num3[] = {2, 0, 1, 8, 5, 5, 5, 0, 4, 0}; 
	char name3[] = "ismet elyasa kazan"; 
   	int size3 = sizeof(num3) / sizeof(num3[0]); 
	int charlen3 = strlen(name3);

  	time = clock();	
    bubblesortNum(num3, size3);
    time = clock() - time;

	printf("\nBubble Sort\n");
    printArr(num3, size3);
   	printf("\nTime for number: %f", ((double)time) / CLOCKS_PER_SEC);

  	time = clock();	
    bubblesortName(name3, charlen3);
    time = clock() - time;

    printf("\n%s\n", name3);
    printf("Time for name: %f\n", ((double)time) / CLOCKS_PER_SEC);

    //merge sort

	int num4[] = {2, 0, 1, 8, 5, 5, 5, 0, 4, 0}; 
	char name4[] = "ismet elyasa kazan"; 
   	int size4 = sizeof(num4) / sizeof(num4[0]); 
	int charlen4 = strlen(name4);

	time = clock();	
	mergeSort(num4, 0, size4-1);
    time = clock() - time;

	printf("\nMerge Sort\n");
	printArr(num4,size4);
   	printf("\nTime for number: %f", ((double)time) / CLOCKS_PER_SEC);

  	time = clock();		   	
	mergeSortName(name4,0,charlen4-1);
    time = clock() - time;

	printf("\n%s\n",name4);
    printf("Time for name: %f\n", ((double)time) / CLOCKS_PER_SEC);

	//quick sort
	
	int num5[] = {2, 0, 1, 8, 5, 5, 5, 0, 4, 0}; 
	char name5[] = "ismet elyasa kazan"; 
   	int size5 = sizeof(num5) / sizeof(num5[0]); 
	int charlen5 = strlen(name5);

	time = clock();	
	quickSortNum(num5, 0, size5-1);
    time = clock() - time;

	printf("\nQuick Sort\n");
    printArr(num5, size5);
   	printf("\nTime for number: %f", ((double)time) / CLOCKS_PER_SEC);
   	
   	time = clock();		   	
	quickSortName(name5,0,charlen5-1);
    time = clock() - time;

	printf("\n%s\n",name5);
    printf("Time for name: %f\n", ((double)time) / CLOCKS_PER_SEC);
		
	//heap sort
	int num6[] = {2, 0, 1, 8, 5, 5, 5, 0, 4, 0}; 
	char name6[] = "ismet elyasa kazan"; 
   	int size6 = sizeof(num6) / sizeof(num6[0]); 
	int charlen6 = strlen(name6);

	time = clock();	
	heapSortNum(num6, size6);
    time = clock() - time;

	printf("\nHeap Sort\n");
    printArr(num6, size6);
   	printf("\nTime for number: %f", ((double)time) / CLOCKS_PER_SEC);
   	
   	time = clock();		   	
	heapSortName(name6,charlen6);
    time = clock() - time;

	printf("\n%s\n",name6);
    printf("Time for name: %f\n", ((double)time) / CLOCKS_PER_SEC);

    return 0;
} 