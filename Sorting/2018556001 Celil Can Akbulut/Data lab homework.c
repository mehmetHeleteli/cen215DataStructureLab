#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Celil Can Akbulut
 2018556001 */
 
 void printArray(int arr[], int size){
      int x;
      for(x = 0; x < size ; x++)
      printf("%d ",arr[x]);
}
 void swap(int* xp, int* yp)
 {
     int temp = *xp;
     *xp = *yp;
     *yp = temp;
 }

 void swapchar(char* xp, char* yp)
 {
     char temp = *xp;
     *xp = *yp;
     *yp = temp;
 }
 
//Insertion Sort 
void InsertionSort(int arr[], int n) 
{ 
	int x, key, y; 
	for (x = 1; x < n; x++) { 
		key = arr[x]; 
		y = x - 1; 
		while (y >= 0 && arr[y] > key) { 
			arr[y + 1] = arr[y]; 
			y = y - 1; 
		} 
		arr[y + 1] = key; 
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
   int   x, y, temp, minimum;
 
   for (x = 0; x < size - 1; x++) {
      minimum = x;
      for (y = x + 1; y < size; y++)
         if (p[minimum] > p[y])
            minimum = y;
      temp = p[minimum];
      p[minimum] = p[x];
      p[x] = temp;
   }
}

void Selectionchar(char arr[], int n) 
{
      int  x, y, minimum;
      char temp;
 
 
   for (x = 0; x < n - 1; x++) {
      minimum = x;
      for (y = x+ 1; y < n; y++)
         if (arr[minimum] > arr[y])
            minimum = y;
      temp = arr[minimum];
      arr[minimum] = arr[x];
      arr[x] = temp;
}
}

//Merge Sort
void merge(int *Arr, int start, int mid, int end) {
	
	int temp[end - start + 1];
	int x = start, y = mid+1, k = 0;

	while(x <= mid && y <= end) {
		if(Arr[x] <= Arr[y]) {
			temp[k] = Arr[x];
			k += 1; x += 1;
		}
		else {
			temp[k] = Arr[y];
			k += 1; y += 1;
		}
	}
	while(x <= mid) {
		temp[k] = Arr[x];
		k += 1; x += 1;
	}

	while(y <= end) {
		temp[k] = Arr[y];
		k += 1; y += 1;
	}

	for(x = start; x <= end; x += 1) {
		Arr[x] = temp[x - start];
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
	int x = start, y = mid+1, k = 0;

	while(x <= mid && y <= end) {
		if(Arr[x] <= Arr[y]) {
			temp[k] = Arr[x];
			k += 1; x+= 1;
		}
		else {
			temp[k] = Arr[y];
			k += 1; y += 1;
		}
	}
	while(x <= mid) {
		temp[k] = Arr[x];
		k += 1; x += 1;
	}

	while(y <= end) {
		temp[k] = Arr[y];
		k += 1; y += 1;
	}

	for(x = start; x <= end; x += 1) {
		Arr[x] = temp[x - start];
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
     int x, y;
     for (x=1; x<size; x++)
     {
        for (y=0; y<size-x; y++)
         {
            if(arr[y] > arr[y+1])
             {
                temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
             }
         }
    }
}

void bubblechar(char arr[], int size){
     char temp;
     int x, y;
     for (x=1; x<size; x++)
     {
       for (y=0; y<size-x; y++)
       {
          if(arr[y] > arr[y+1])
           {
            temp = arr[y];
            arr[y] = arr[y+1];
             arr[y+1] = temp;
             }
         }
    }
}

//Quick Sort
void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void quickchar(char arr[], int left, int right)
{
    int i = left, j = right;
    char tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        quickchar(arr, left, j);
    if (i < right)
        quickchar(arr, i, right);
}


//Heap Sort
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

void heapSort(int arr[], int n) {
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (j = n - 1; j > 0; j--) {
        swap(&arr[0], &arr[j]);
        heapify(arr, j, 0);
    }
}

void heapifychar(char arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swapchar(&arr[i], &arr[largest]);
        heapifychar(arr, n, largest);
    }
}

void heapchar(char arr[], int n) {
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapifychar(arr, n, i);

    for (j = n - 1; j > 0; j--) {
        swapchar(&arr[0], &arr[j]);
        heapifychar(arr, j, 0);
    }
}
 int main(){
 	printf("\n CEN 215-DATA STRUCTURES LAB PROJECT 1 \n ");
     printf("\n Unsorted number:2018556001");
     printf(" \n Unsorted name:Celil Can Akbulut\n");
     clock_t t;
     
 	  //InsertionSort
 	  int arr[] = {2,0,1,8,5,5,6,0,0,1};
      int n = sizeof(arr)/sizeof(arr[0]);
      char name[] = "celil can akbulut";
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
 	  int arr1[] = {2,0,1,8,5,5,6,0,0,1};
      int n1 = sizeof(arr1)/sizeof(arr1[0]);
      char name1[] = "celil can akbulut";
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
      int arr2[] ={2,0,1,8,5,5,6,0,0,1} ;
      int n2 = sizeof(arr2)/sizeof(arr2[0]);
      char name2[] = "celil can akbulut";
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
      int arr3[] ={2,0,1,8,5,5,6,0,0,1} ;
      int n3 = sizeof(arr3)/sizeof(arr3[0]);
      char name3[] = "celil can akbulut";
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
      
      //Quick Sort
      int arr4[] = { 2,0,1,8,5,5,6,0,0,1 };
      int n4 = sizeof(arr4) / sizeof(arr4[0]);
      char name4[] = "celil can akbulut";
      int charS4 = strlen(name4);

      quickSort(arr4, 0, n4 - 1);
      t = clock() - t;
      printf("\nSorted numbers in Quick Sort:");
      printArray(arr4, n4);
      printf("\nRunning time of Quick Sort for number: %f\n", ((double)t) / CLOCKS_PER_SEC);
      quickchar(name4, 0, charS4 - 1);
      t = clock() - t;
      printf("Sorted name in Quick Sort : %s\n", name4);
      printf("Running time of Quick Sort for char: %f\n", ((double)t) / CLOCKS_PER_SEC);

      //Heap Sort
      int arr5[] = { 2,0,1,8,5,5,6,0,0,1 };
      int n5 = sizeof(arr5) / sizeof(arr5[0]);
      char name5[] = "celil can akbulut";
      int charS5 = strlen(name5);

      heapSort(arr5, n5);
      t = clock() - t;
      printf("\nSorted numbers in Heap Sort:");
      printArray(arr5, n5);
      printf("\nRunning time of Heap Sort for number: %f\n", ((double)t) / CLOCKS_PER_SEC);
      heapchar(name5, charS5);
      t = clock() - t;
      printf("Sorted name in Heap Sort : %s\n", name5);
      printf("Running time of Heap Sort for char: %f\n", ((double)t) / CLOCKS_PER_SEC);
      return 0;
 }
