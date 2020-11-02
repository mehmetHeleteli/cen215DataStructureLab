#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Ceyda Vural
 2019556455 */
 
 void printArray(int arr[], int size){
      int i;
      for(i = 0; i < size ; i++)
      printf("%d ",arr[i]);
}
 
//Insertion Sort 
void InsertionSort(int arr[], int n) 
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

void Insertionchar(char arr[], int n
){
	int a,b;
	char key;
	for (a=1; a<n; a++){
		key = arr[a];
		b = a-1;
		while(b >= 0 && arr[b] > key){
			arr[b+1] = arr[b];
			b = b-1;
		}
		arr[b+1] = key;
	}
}

//Selection Sort
void SelectionSort(int *p, int size)
{
   int   i, j, temp, min;
 
   for (i = 0; i < size - 1; i++) {
      min = i;
      for (j = i + 1; j < size; j++)
         if (p[min] > p[j])
            min = j;
      temp = p[min];
      p[min] = p[i];
      p[i] = temp;
   }
}

void Selectionchar(char arr[], int n) 
{
      int  i, j, min;
      char temp;
 
 
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
         if (arr[min] > arr[j])
            min = j;
      temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
}
}

//Merge Sort
void merge(int *Arr, int start, int mid, int end) {
	
	int temp[end - start + 1];
	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}
void mergeSort(int *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}

 void mergesort(char *Arr, int start, int mid, int end) {
	
	int temp[end - start + 1];
	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}
void mergesortchar(char *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergesortchar(Arr, start, mid);
		mergesortchar(Arr, mid+1, end);
		mergesort(Arr, start, mid, end);
	}
}

//Bubble sort
void bubbleSort(int arr[], int size){
     int temp;
     int i, j;
     for (i=1; i<size; i++)
     {
        for (j=0; j<size-i; j++)
         {
            if(arr[j] > arr[j+1])
             {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
             }
         }
    }
}

void bubblechar(char arr[], int size){
     char temp;
     int i, j;
     for (i=1; i<size; i++)
     {
       for (j=0; j<size-i; j++)
       {
          if(arr[j] > arr[j+1])
           {
            temp = arr[j];
            arr[j] = arr[j+1];
             arr[j+1] = temp;
             }
         }
    }
}

//Quick Sort

void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}
 int QuickSort(int arr[], int low, int high)
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
int pi = QuickSort(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
void swapChar(char* a, char* b)
{
char t = *a;
*a = *b;
*b = t;
}
 int QuickSortChar(char arr[], int low, int high)
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
int pi = QuickSortChar(arr, low, high);
quickSortChar(arr, low, pi - 1);
quickSortChar(arr, pi + 1, high);
}
}

//Heap Sort

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

void heap_sort(int arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
      
      void heapifychar(char arr[], int n, int i)
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
        heapifychar(arr, n, largest); 
    }
}

void heap_sortchar(char arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifychar(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swapChar(&arr[0], &arr[i]);
        heapifychar(arr, i, 0);
    }
}

 int main(){
     printf("Unsorted number:2019556455\n");
     printf("Unsorted name:ceyda vural\n");
     clock_t t;
     
 	  //InsertionSort
 	  int arr[] = {2,0,1,9,5,5,6,4,5,5};
      int n = sizeof(arr)/sizeof(arr[0]);
      char name[] = "ceyda vural";
      int charS = strlen(name);
      
      t = (double)clock();
      InsertionSort(arr, n);
      t = (double)clock()-t;
      printf("\nSorted numbers in InsertionSort:");
      printArray(arr,n);
      printf("\nRunning time of Insertion Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      Insertionchar(name,charS);
      t = (double)clock()-t;
      printf("Sorted name in Insertion Sort : %s\n",name);
      printf("Running time of Insertion Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //SelectionSort
 	  int arr1[] = {2,0,1,9,5,5,6,4,5,5};
      int n1 = sizeof(arr)/sizeof(arr1[0]);
      char name1[] = "ceyda vural";
      int charS1 = strlen(name1);
      
      SelectionSort(arr1, n1);
      t =(double)clock()-t;
      printf("\nSorted numbers in Selection Sort:");
      printArray(arr1,n1);
      printf("\nRunning time of Selection Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      Selectionchar(name1,charS1);
      t =(double)clock()-t;
      printf("Sorted name in Selection Sort : %s\n",name1);
      printf("Running time of Selection Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //MergeSort
      int arr2[] = {2,0,1,9,5,5,6,4,5,5};
      int n2 = sizeof(arr)/sizeof(arr2[0]);
      char name2[] = "ceyda vural";
      int charS2 = strlen(name2);
    
      mergeSort(arr2,0, n2-1);
      t = (double)clock()-t;
      printf("\nSorted numbers in Merge Sort:");
      printArray(arr2,n2);
      printf("\nRunning time of Merge Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      mergesortchar(name2,0,charS2-1);
      t = (double)clock()-t;
      printf("Sorted name in Merge Sort : %s\n",name2);
      printf("Running time of Merge Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //BubbleSort
      int arr3[] = {2,0,1,9,5,5,6,4,5,5};
      int n3 = sizeof(arr)/sizeof(arr3[0]);
      char name3[] = "ceyda vural";
      int charS3 = strlen(name3);
    
      bubbleSort(arr3, n3);
      t = clock()-t;
      printf("\nSorted numbers in Bubble Sort:");
      printArray(arr3,n3);
      printf("\nRunning time of Bubble Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      bubblechar(name3,charS3);
      t = clock()-t;
      printf("Sorted name in Bubble Sort : %s\n",name3);
      printf("Running time of Bubble Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //QuickSort
      int arr4[] = {2,0,1,9,5,5,6,4,5,5};
      int n4 = sizeof(arr)/sizeof(arr4[0]);
      char name4[] = "ceyda vural";
      int charS4 = strlen(name4);
      
      t = (double)clock();
      quickSort(arr4, 0, n4-1);
      t = (double)clock()-t;
      printf("\nSorted numbers in Quick Sort:");
      printArray(arr4,n4);
      printf("\nRunning time of Quick Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      quickSortChar(name4,0,charS4-1);
      t = (double)clock()-t;
      printf("Sorted name in Quick Sort : %s\n",name4);
      printf("Running time of Quick Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);
      
      //HeapSort
      int arr5[] = {2,0,1,9,5,5,6,4,5,5};
      int n5 = sizeof(arr)/sizeof(arr5[0]);
      char name5[] = "ceyda vural";
      int charS5 = strlen(name5);
      
      t = (double)clock();
      heap_sort(arr5, n5);
      printf("\nSorted numbers in Heap Sort:");
      printArray(arr5,n5);
      printf("\nRunning time of Heap Sort for number: %f\n",((double)t) / CLOCKS_PER_SEC);
      heap_sortchar(name5,charS5);
      t = (double)clock()-t;
      printf("Sorted name in Heap Sort : %s\n",name5);
      printf("Running time of Heap Sort for char: %f\n",((double)t) / CLOCKS_PER_SEC);

      return 0;
 }
