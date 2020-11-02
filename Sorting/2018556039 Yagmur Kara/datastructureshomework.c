#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*yagmur kara
 2018556039 */
 
 void printArray(int arr[], int size){
      int x;
      for(x = 0; x < size ; x++)
      printf("%d ",arr[x]);
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
   int   x, y, temp, min;
 
   for (x = 0; x < size - 1; x++) {
      min = x;
      for (y = x + 1; y < size; y++)
         if (p[min] > p[y])
            min = y;
      temp = p[min];
      p[min] = p[x];
      p[x] = temp;
   }
}

void Selectionchar(char arr[], int n) 
{
      int  x, y, min;
      char temp;
 
 
   for (x = 0; x < n - 1; x++) {
      min = x;
      for (y = x+ 1; y < n; y++)
         if (arr[min] > arr[y])
            min = y;
      temp = arr[min];
      arr[min] = arr[x];
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

 int main(){
 	printf("\n CEN 215-DATA STRUCTURES LAB PROJECT 1 \n ");
     printf("\n Unsorted number:2018556039");
     printf(" \n Unsorted name: yagmur kara\n");
     clock_t t;
     
 	  //InsertionSort
 	  int arr[] = {2,0,1,8,5,5,6,0,3,9};
      int n = sizeof(arr)/sizeof(arr[0]);
      char name[] = "yagmur kara";
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
 	  int arr1[] = {2,0,1,8,5,5,6,0,3,9};
      int n1 = sizeof(arr)/sizeof(arr1[0]);
      char name1[] = "yagmur kara";
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
      int arr2[] ={2,0,1,8,5,5,6,0,3,9} ;
      int n2 = sizeof(arr)/sizeof(arr2[0]);
      char name2[] = "yagmur kara";
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
      int arr3[] ={2,0,1,8,5,5,6,0,3,9} ;
      int n3 = sizeof(arr)/sizeof(arr3[0]);
      char name3[] = "yagmur kara";
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
      return 0;
 }
