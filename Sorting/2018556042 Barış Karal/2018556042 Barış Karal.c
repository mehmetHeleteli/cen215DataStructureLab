#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Baris Karal 2018556042 */

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

void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
}

int main() {
	printf("School Number: 2018556042\n");
	printf("Name: baris karal\n");
	clock_t t;

	//InsertionSort
	int arr[] = { 2,0,1,8,5,5,6,0,4,2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	char name[] = "baris karal";
	int charS = strlen(name);

	t = (double)clock();
	insertionSort(arr, n);
	t = (double)clock() - t;
	printf("\nNumbers in Insertion Sort:");
	printArray(arr, n);
	printf("\nRunning time of Insertion Sort for number: %f\n", ((double)t) / CLOCKS_PER_SEC);
	insertionSortChar(name, charS);
	t = (double)clock() - t;
	printf("Name in Insertion Sort : %s\n", name);
	printf("Running time of Insertion Sort for char: %f\n", ((double)t) / CLOCKS_PER_SEC);

	//SelectionSort
	int arr1[] = { 2,0,1,8,5,5,6,0,4,2 };
	int n1 = sizeof(arr) / sizeof(arr1[0]);
	char name1[] = "baris karal";
	int charS1 = strlen(name1);

	selectionSort(arr1, n1);
	t = (double)clock() - t;
	printf("\nNumbers in Selection Sort:");
	printArray(arr1, n1);
	printf("\nRunning time of Selection Sort for number: %f\n", ((double)t) / CLOCKS_PER_SEC);
	selectionSortChar(name1, charS1);
	t = (double)clock() - t;
	printf("Name in Selection Sort : %s\n", name1);
	printf("Running time of Selection Sort for char: %f\n", ((double)t) / CLOCKS_PER_SEC);

	//MergeSort
	int arr2[] = { 2,0,1,8,5,5,6,0,4,2 };
	int n2 = sizeof(arr) / sizeof(arr2[0]);
	char name2[] = "baris karal";
	int charS2 = strlen(name2);

	mergeSort(arr2, 0, n2 - 1);
	t = (double)clock() - t;
	printf("\nNumbers in Merge Sort:");
	printArray(arr2, n2);
	printf("\nRunning time of Merge Sort for number: %f\n", ((double)t) / CLOCKS_PER_SEC);
	mergesortchar(name2, 0, charS2 - 1);
	t = (double)clock() - t;
	printf("Name in Merge Sort : %s\n", name2);
	printf("Running time of Merge Sort for char: %f\n", ((double)t) / CLOCKS_PER_SEC);

	//BubbleSort
	int arr3[] = { 2,0,1,8,5,5,6,0,4,2 };
	int n3 = sizeof(arr) / sizeof(arr3[0]);
	char name3[] = "baris karal";
	int charS3 = strlen(name3);

	bubbleSort(arr3, n3);
	t = clock() - t;
	printf("\nNumbers in Bubble Sort:");
	printArray(arr3, n3);
	printf("\nRunning time of Bubble Sort for number: %f\n", ((double)t) / CLOCKS_PER_SEC);
	bubbleSortChar(name3, charS3);
	t = clock() - t;
	printf("Name in Bubble Sort : %s\n", name3);
	printf("Running time of Bubble Sort for char: %f\n", ((double)t) / CLOCKS_PER_SEC);
	return 0;
}
