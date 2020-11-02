#include <stdio.h>
#include <time.h>
#include <string.h>


/*cigdem cinar 2017556504 */

void selectionSort(int* p, int size)
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

void selectionSortChar(char array[], int n)
{
	int  i, j, min;
	char temp;


	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (array[min] > array[j])
				min = j;
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
}
void insertionSort(int array[], int n)
{
	int i, element, j;
	for (i = 1; i < n; i++) {
		element = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > element) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = element;
	}
}

void insertionSortChar(char array[], int n)
{
	int x, y;
	char element;
	for (x = 1; x < n; x++) {
		element = array[x];
		y = x - 1;
		while (y >= 0 && array[y] > element) {
			array[y + 1] = array[y];
			y = y - 1;
		}
		array[y + 1] = element;
	}
}

void bubbleSort(int array[], int size) {
	int temp;
	int i, j;
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void bubbleSortChar(char array[], int size) {
	char temp;
	int i, j;
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


void merge(int* array, int start, int mid, int end) {

	int temp[end - start + 1];
	int i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = array[j];
			k += 1; j += 1;
		}
	}
	while (i <= mid) {
		temp[k] = array[i];
		k += 1; i += 1;
	}

	while (j <= end) {
		temp[k] = array[j];
		k += 1; j += 1;
	}

	for (i = start; i <= end; i += 1) {
		array[i] = temp[i - start];
	}
}
void mergeSort(int* array, int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);
		merge(array, start, mid, end);
	}
}

void mergesort(char* array, int start, int mid, int end) {

	int temp[end - start + 1];
	int i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = array[j];
			k += 1; j += 1;
		}
	}
	while (i <= mid) {
		temp[k] = array[i];
		k += 1; i += 1;
	}

	while (j <= end) {
		temp[k] = array[j];
		k += 1; j += 1;
	}

	for (i = start; i <= end; i += 1) {
		array[i] = temp[i - start];
	}
}
void mergesortchar(char* array, int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;
		mergesortchar(array, start, mid);
		mergesortchar(array, mid + 1, end);
		mergesort(array, start, mid, end);
	}
}


void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
}

int main()
 {
	  printf("School Number:2017556504\n");
	  printf("Name         :cigdem\n");
    	clock_t t;

	/////////////////////////////////////////*InsertionSort*/////////////////////////////////////
	
	int arr[] = { 2,0,1,7,5,5,6,5,0,4 };
	int num = sizeof(arr) / sizeof(arr[0]);
	char name[] = "cigdem";
	int charS = strlen(name);

	t = (double)clock();
	insertionSort(arr, num);
	t = (double)clock() - t;
	printf("\n\n ************Insertion Sort****************                \n ");
	printf("\nSchool Number  :");
	printArray(arr, num);
	printf("\nRunning Time   : %f\n", ((double)t) / CLOCKS_PER_SEC);
	insertionSortChar(name, charS);
	t = (double)clock() - t;
	printf("Name           : %s\n", name);
	printf("Running Time   : %f\n", ((double)t) / CLOCKS_PER_SEC);

	/////////////////////////////////////*SelectionSort*/////////////////////////////////////////
	
	int arr1[] = { 2,0,1,7,5,5,6,5,0,4 };
	int num1 = sizeof(arr) / sizeof(arr1[0]);
	char name1[] = "cigdem";
	int charS1 = strlen(name1);

	selectionSort(arr1, num1);
	t = (double)clock() - t;
	printf("\n\n **************Selection Sort**************                \n");
	printf("\nSchool Number :");
	printArray(arr1, num1);
	printf("\nRunning Time  : %f\n", ((double)t) / CLOCKS_PER_SEC);
	selectionSortChar(name1, charS1);
	t = (double)clock() - t;
	printf("Name          : %s\n", name1);
	printf("Running Time  : %f\n", ((double)t) / CLOCKS_PER_SEC);
	
	//////////////////////////////////////////*BubbleSort*////////////////////////////////////////
	
	int arr2[] = { 2,0,1,7,5,5,6,5,0,4 };
	int num2 = sizeof(arr) / sizeof(arr2[0]);
	char name2[] = "cigdem";
	int charS2 = strlen(name2);

	bubbleSort(arr2, num2);
	t = clock() - t;
	printf("\n\n ***************Bubble Short***************\n ");
	printf("\nSchool Number :");
	printArray(arr2, num2);
	printf("\nRunning Time  : %f\n", ((double)t) / CLOCKS_PER_SEC);
	bubbleSortChar(name2, charS2);
	t = clock() - t;
	printf("Name          : %s\n", name2);
	printf("Running Time  : %f\n", ((double)t) / CLOCKS_PER_SEC);
	
	/////////////////////////////////////////*MergeSort*////////////////////////////////////////
	
	int arr3[] = { 2,0,1,7,5,5,6,5,0,4 };
	int num3 = sizeof(arr) / sizeof(arr3[0]);
	char name3[] = "cigdem";
	int charS3 = strlen(name3);

	mergeSort(arr3, 0, num3 - 1);
	t = (double)clock() - t;
	printf("\n\n ****************Merge Short***************\n ");
	printf("\nSchool Number :");
	printArray(arr2, num2);
	printf("\nRunning Time  : %f\n", ((double)t) / CLOCKS_PER_SEC);
	mergesortchar(name3, 0, charS3- 1);
	t = (double)clock() - t;
	printf("Name          : %s\n", name3);
	printf("Running Time  : %f\n", ((double)t) / CLOCKS_PER_SEC);

return 0;
}
