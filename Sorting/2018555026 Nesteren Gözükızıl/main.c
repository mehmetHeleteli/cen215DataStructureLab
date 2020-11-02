#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
const int MAX_SIZEI = 12;
const char MAX_SIZEC = 20;

//swap type int
void swapId(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}
//swap type char
void swapName(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
//SELECTION SORT
void selectionSortId(int arr[], int size) {
	int i, j, curMin;
	for (i = 0; i < size - 1; ++i) {
		curMin = i;
		for (j = i + 1; j < size; ++j) {
			if (arr[j] < arr[curMin])
				curMin = j;
		}
		swapId(&arr[curMin], &arr[i]);
	}

}
void selectionSortName(char arr[], int size) {
	int i, j, curMin;
	for (i = 0; i < size - 1; ++i) {
		curMin = i;
		for (j = i + 1; j < size; ++j) {
			if (arr[j] < arr[curMin])
				curMin = j;
		}
		swapName(&arr[curMin], &arr[i]);
	}

}
//INSERTION SORT
void insertionSortId(int arr[], int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] >= key; j--) {
			arr[j + 1] = arr[j];
		}
		key = arr[j + 1];
	}

}

void insertionSortName(char arr[], int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] >= key; j--) {
			arr[j + 1] = arr[j];
		}
		key = arr[j + 1];

	}
}

//BUBBLE SORT
void bubbleSortId(int arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swapId(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void bubbleSortName(char arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swapName(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//MERGE SORT
void mergeId(int arr[], int left, int midpoint, int right)
{
	int i, j, l = 0;
	int M[MAX_SIZEI];

	for (i = left, j = midpoint + 1; (i <= midpoint) && (j <= right);)
	{
		if (arr[i] < arr[j]) {
			M[l] = arr[i];
			i++;
			l++;
		}
		else {
			M[l] = arr[j];
			j++;
			l++;
		}
	}

	while (i <= midpoint) {
		M[l] = arr[i];
		i++;
		l++;
	}
	while (j <= right) {
		M[l] = arr[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		arr[i] = M[l];
	}

}

void mergeName(char arr[], int left, int midpoint, int right)
{
	int i, j, l = 0;
	char M[MAX_SIZEC];

	for (i = left, j = midpoint + 1; (i <= midpoint) && (j <= right);)
	{
		if (arr[i] < arr[j]) {
			M[l] = arr[i];
			i++;
			l++;
		}
		else {
			M[l] = arr[j];
			j++;
			l++;
		}
	}

	while (i <= midpoint) {
		M[l] = arr[i];
		i++;
		l++;
	}
	while (j <= right) {
		M[l] = arr[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		arr[i] = M[l];
	}

}
void  mergeSortId(int arr[], int left, int right) {
	int midpoint;
	if (left < right)
	{
		midpoint = (left + right) / 2;

		mergeSortId(arr, left, midpoint);
		mergeSortId(arr, midpoint + 1, right);

		mergeId(arr, left, midpoint, right);

	}
}
void mergeSortName(char arr[], int left, int right) {
	int midpoint;
	if (left < right)
	{
		midpoint = (left + right) / 2;

		mergeSortName(arr, left, midpoint);
		mergeSortName(arr, midpoint + 1, right);
		mergeName(arr, left, midpoint, right);

	}
}

//QUICK SORT

int partitionId(int arr[], int left, int right)
{
    int pivot = arr[right];
    int low = (left - 1);
    int high;
    
    for ( high = left; high <= right- 1; high++)
    {
        if (arr[high] <= pivot)
        {
            low++;
            swapId(&arr[low], &arr[high]);
        }
    }
    swapId(&arr[low + 1], &arr[right]);
    return (low + 1);
}

void quickSortId(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partitionId(arr, left, right);
        quickSortId(arr, left, pivot - 1);
        quickSortId(arr, pivot + 1, right);
    }
}

char partitionName(char arr[],int left,int right){
    int pivot = arr[right];
    int low = (left - 1);
    int high;
    
    for ( high = left; high <= right- 1; high++)
    {
        if (arr[high] <= pivot)
        {
            low++;
            swapName(&arr[low], &arr[high]);
        }
    }
    swapName(&arr[low + 1], &arr[right]);
    return (low + 1);
}

void quickSortName(char arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partitionName(arr, left, right);
        quickSortName(arr, left, pivot - 1);
        quickSortName(arr, pivot + 1, right);
    }
}

//HEAP SORT
void heapifyId(int arr[],int size,int i) {
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	
	if (arr[leftChild] > arr[largest] && leftChild<size) 
		largest = leftChild;

		if (arr[rightChild] > arr[largest] && rightChild<size) 
			largest = rightChild;
		if (largest != i) {
			swapId(&arr[i], &arr[largest]);
			heapifyId(arr, size, largest);
		}

}
void heapSortId(int arr[],int size) {
	int i;
	for (i = size / 2 - 1; i >= 0;i-- ) {
		heapifyId(arr, size, i);
	}

	for (i = size - 1; i > 0; i--) {
		swapId(&arr[0],&arr[i]);
		heapifyId(arr , i , 0);
	}

}



void heapifyName(char arr[],int size,int i) {
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	
	if (arr[leftChild] > arr[largest] && leftChild<size) 
		largest = leftChild;

		if (arr[rightChild] > arr[largest] && rightChild<size) 
			largest = rightChild;
		if (largest != i) {
			swapName(&arr[i], &arr[largest]);
			heapifyName(arr, size, largest);
		}

}
void heapSortName(char arr[],int size) {
	int i;
	for (i = size / 2 - 1; i >= 0;i-- ) {
		heapifyName(arr, size, i);
	}

	for (i = size - 1; i > 0; i--) {
		swapName(&arr[0],&arr[i]);
		heapifyName(arr , i , 0);
	}

}


//PRINT SORTS
void printSortId(int arr[], int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void printSortName(char arr[], int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arrId[] = { 2,0,1,8,5,5,5,0,2,6 };
	char arrName[] = "NESTEREN GOZUKIZIL";

	int size1 = sizeof(arrId) / sizeof(arrId[2]);
	int size2 = strlen(arrName);

	clock_t time;
	time = clock();


	//SELECTION SORT FUNCTIONS
	printf("SELECTION SORT\n");
	selectionSortId(arrId, size1);
	time = clock() - time;
	printSortId(arrId, size1);
	printf("The total time for selection sort id: %f\n", ((double)(time)) / CLOCKS_PER_SEC);

	selectionSortName(arrName, size2);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for selection sort name: %f\n\n", ((double)(time)) / CLOCKS_PER_SEC);

	//INSERTION SORT FUNCTIONS
	printf("INSERTION SORT \n");
	insertionSortId(arrId, size1);
	time = clock() - time;
	printSortId(arrId, size1);
	printf("The total time for insertion sort id: %f\n", ((double)(time)) / CLOCKS_PER_SEC);

	insertionSortName(arrName, size2);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for insertion sort name: %f\n\n", ((double)(time)) / CLOCKS_PER_SEC);

	//BUBBLE SORT
	printf("BUBBLE SORT\n");
	bubbleSortId(arrId, size1);
	time = clock() - time;
	printSortId(arrId, size1);
	printf("The total time for bubble sort id: %f\n", ((double)(time)) / CLOCKS_PER_SEC);

	bubbleSortName(arrName, size2);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for bubble sort name: %f\n\n", ((double)(time)) / CLOCKS_PER_SEC);

	//MERGE SORT
	printf("MERGE SORT \n");
	mergeSortId(arrId, 0, size1 - 1);
	time = clock() - time;
	printSortId(arrId, size1);
	printf("The total time for merge sort id: %f\n", ((double)(time)) / CLOCKS_PER_SEC);

	mergeSortName(arrName, 0, size2 - 1);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for merge sort name: %f\\n", ((double)(time)) / CLOCKS_PER_SEC);


    //QUICK SORT
	printf("QUICK SORT\n");
	quickSortId(arrId , 0 , size1-1);
	time = clock() - time;
	printSortId(arrId,size1);
	printf("The total time for quick sort id: %f\n", ((double)(time)) / CLOCKS_PER_SEC);
	
	quickSortName(arrName, 0, size2 - 1);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for quick sort name: %f\n\n", ((double)(time)) / CLOCKS_PER_SEC);
	
	
    //HEAP SORT
    printf("HEAP SORT\n");
	heapSortId(arrId , size1);
	time = clock() - time;
	printSortId(arrId,size1);
	printf("The total time for heap sort id: %f\n", ((double)(time)) / CLOCKS_PER_SEC);
	
	heapSortName(arrName, size2 );
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for heap sort name: %f\n\n", ((double)(time)) / CLOCKS_PER_SEC);

	return 0;
}
