#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void swapChar(char *xp, char *yp) { 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

// Insertion Sort

void insertionSort(int *arr, int n) { 
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

void insertionSortChar(char *arr, int n) {
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

// Selection Sort

void selectionSort (int *arr, int n) {
    int i, j, currMin;

    for(i = 0; i < n-1; i++) {
        currMin = i;

        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[currMin]) {
                currMin = j;
            }
        }
        swap(&arr[currMin], &arr[i]);
    }
}

void selectionSortChar(char *arr, int n) { 
    int i, j;
    char currMin;

    for (i = 0; i < n-1; i++) 
    { 
        currMin = i; 

        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[currMin]) 
            currMin = j; 
        swapChar(&arr[currMin], &arr[i]); 
    } 
} 

// Bubble Sort

void bubbleSort(int *arr, int n) { 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void bubbleSortChar(char *arr, int n) { 
   int i, j; 

   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapChar(&arr[j], &arr[j+1]); 
} 

// Merge Sort

void merge(int arr[], int left, int mid, int right) {
    int i, j, l = 0;
    int array[15];

    for (i = left, j = mid + 1; (i <= mid) && (j <= right);)
    {
        if (arr[i] < arr[j]) {
            array[l] = arr[i];
            i++;
            l++;
        } else {
            array[l] = arr[j];
            j++;
            l++;
        }
    }

    while (i <= mid) {
        array[l] = arr[i];
        i++;
        l++;
    }

    while (j <= right) {
        array[l] = arr[j];
        j++;
        l++;
    }

    for (i = left, l = 0; i <= right; i++, l++) {
        arr[i] = array[l];
    }
}

void mergeChar(char arr[], int left, int mid, int right) {
    int i, j, l = 0;
    char array[20];

    for (i = left, j = mid + 1; (i <= mid) && (j <= right);)
    {
        if (arr[i] < arr[j]) {
            array[l] = arr[i];
            i++;
            l++;
        } else {
            array[l] = arr[j];
            j++;
            l++;
        }
    }

    while (i <= mid) {
        array[l] = arr[i];
        i++;
        l++;
    }

    while (j <= right) {
        array[l] = arr[j];
        j++;
        l++;
    }

    for (i = left, l = 0; i <= right; i++, l++) {
        arr[i] = array[l];
    }
}

void  mergeSort(int arr[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSortChar(char arr[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;

        mergeSortChar(arr, left, mid);
        mergeSortChar(arr, mid + 1, right);
        mergeChar(arr, left, mid, right);
    }
}

void print(int arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printChar(char arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// Quick Sort

int partition (int arr[], int low, int high) { 
    int pivot = arr[high];   
    int i = (low - 1);  
    int j;

    for (j = low; j <= high- 1; j++) { 
        if (arr[j] < pivot) { 
            i++;   
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

int partitionChar (char arr[], int low, int high) { 
    int pivot = arr[high];    
    int i = (low - 1);   
    int j;

    for (j = low; j <= high- 1; j++) { 

        if (arr[j] < pivot) { 
            i++;    
            swapChar(&arr[i], &arr[j]); 
        } 
    } 

    swapChar(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSortChar (char arr[], int low, int high) { 
    if (low < high) { 
        int pi = partitionChar(arr, low, high); 

        quickSortChar(arr, low, pi - 1); 
        quickSortChar(arr, pi + 1, high); 
    } 
}

// Heap Sort

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, k;

    for (i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    for (k = n - 1; k >= 0; k--) {
      swap(&arr[0], &arr[k]);

      heapify(arr, k, 0);
    }
}

void heapifyChar(char arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    if (largest != i) {
      swapChar(&arr[i], &arr[largest]);
      heapifyChar(arr, n, largest);
    }
}

void heapSortChar(char arr[], int n) {
    int i, k;

    for (i = n / 2 - 1; i >= 0; i--)
      heapifyChar(arr, n, i);

    for (k = n - 1; k >= 0; k--) {
      swapChar(&arr[0], &arr[k]);

      heapifyChar(arr, k, 0);
    }
}

int main()
{
    int Id[] = { 2, 0, 1, 8, 5, 5, 6, 4, 5, 4};
    char Name[] = "berkay kose";

    int size1 = sizeof(Id) / sizeof(Id[2]);
    int size2 = strlen(Name);

    clock_t t;
    t = clock();

    //Selection Sort
    selectionSort(Id, size1);
    t = clock() - t;
    print(Id, size1);
    printf("Time of selection sort: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    selectionSortChar(Name, size2);
    t = clock() - t;
    printChar(Name, size2);
    printf("Time of selection sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);
    
    //Insertion Sort
    insertionSort(Id, size1);
    t = clock() - t;
    print(Id, size1);
    printf("Time of insertion sort: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    insertionSortChar(Name, size2);
    t = clock() - t;
    printChar(Name, size2);
    printf("Time of insertion sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);
    
    //Bubble Sort
    bubbleSort(Id, size1);
    t = clock() - t;
    print(Id, size1);
    printf("Time of bubble sort: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    bubbleSortChar(Name, size2);
    t = clock() - t;
    printChar(Name, size2);
    printf("Time of bubble sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);
    
    //Merge Sort
    mergeSort(Id, 0, size1 - 1);
    t = clock() - t;
    print(Id, size1);
    printf("Time of merge sort: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    mergeSortChar(Name, 0, size2 - 1);
    t = clock() - t;
    printChar(Name, size2);
    printf("Time of merge sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);

    //Quick Sort
	quickSort(Id, 0, size1 - 1);
	t = clock() - t;
	print(Id, size1);
	printf("Time of quick sort: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    quickSortChar(Name, 0, size2 - 1);
	t = clock() - t;
	printChar(Name, size2);
	printf("Time of quick sort Name: %f\n\n\n", ((double)(t)) / CLOCKS_PER_SEC);

    //Heap Sort
	heapSort(Id, size1);
	t = clock() - t;
	print(Id, size1);
	printf("Time of heap sort: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    heapSortChar(Name, size1);
	t = clock() - t;
	printChar(Name, size1);
	printf("Time of heap sort Name: %f\n", ((double)(t)) / CLOCKS_PER_SEC);

    return 0;
}
