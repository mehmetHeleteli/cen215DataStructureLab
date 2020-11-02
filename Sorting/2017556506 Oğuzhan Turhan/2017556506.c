#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void printArray(int arr[], int x) {

	int i;
	for (i = 0; i < x; i++)
		printf("%d", arr[i]);
	printf("\n", arr[i]);
}
void printArraychar(char arr[], int x) {

	int i;
	for (i = 0; i < x; i++)
		printf("%c", arr[i]);
	printf("\n", arr[i]);
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swapchar(char* x, char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}
/* Insertion Sort */
void insertionSort(int arr[], int k) {
	int i, key, j;
	for (i = 1; i < k; i++)
	{
		key = arr[i];

		for (j = i - 1; j >= 0 && arr[j] > key; --j)
		{
			arr[j + 1] = arr[j];

		}
		arr[j + 1] = key;
	}
}
void insertionSortchar(char array[], int k)
{
	int i, j;
	char key;
	for (i = 1; i < k; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}


/* Selection Sort */
void SelectionSort(int array[], int size)
{
	int i, j;
	int currentmin;
	for (i = 0; i < size - 1; i++)
	{
		currentmin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[currentmin])
			{
				currentmin = j;
			}
		}
		swap(&array[currentmin], &array[i]);
	}
}

void SelectionSortchar(char array[], int size)
{
	int i, j;
	char min;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		swapchar(&array[min], &array[i]);
	}
}

//Merge Sort 
void merge(int arr[], int l, int m, int r)
{
	int i, a, b;
	int p1 = m - l + 1;
	int p2 = r - m;

	int L[p1];
	int R[p2];

	for (i = 0; i < p1; i++)
		L[i] = arr[l + i];
	for (a = 0; a < p2; a++)
		R[a] = arr[m + 1 + a];

	i = 0;
	a = 0;
	b = l;
	while (i < p1 && a < p2)
	{
		if (L[i] <= R[a])
		{
			arr[b] = L[i];
			i++;
		}
		else
		{
			arr[b] = R[a];
			a++;
		}
		b++;
	}

	while (i < p1)
	{
		arr[b] = L[i];
		i++;
		b++;
	}

	while (a < p2)
	{
		arr[b] = R[a];
		a++;
		b++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* Bubble Sort */


void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void bubbleSortchar(char array[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (array[j] > array[j + 1])
				swapchar(&array[j], &array[j + 1]);
}

void mergeChar(char arr[], int a, int b, int c)
{
	int j, i, m, k, n;

	m = b - a + 1;

	n = c - b;

	int A[m], B[n];

	for (i = 0; i < m; i++)

		A[i] = arr[a + i];
	for (j = 0; j < n; j++)


		B[j] = arr[b + 1 + j];
	i = 0;
	j = 0;
	k = a;

	while (i < m && j < n)
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

	while (i < m)
	{
		arr[k] = A[i];
		i++;
		k++;
	}

	while (j < n) {
		arr[k] = B[j];
		j++;
		k++;
	}
}

void mergeSortChar(char arr[], int r, int l)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSortChar(arr, l, m);
		mergeSortChar(arr, m + 1, r);
		mergeChar(arr, l, m, r);
	}
}

int main(int argc, char const* argv[])
{


	int num[] = { 2,0,1,7,5,5,6,5,0,6 };
	char name[] = "Oguzhan Turhan";
	int size = sizeof(num) / sizeof(num[0]);
	int sizename = strlen(name);
	clock_t c1, c2;
	double timeresult;


	//insertionsort

	c1 = clock();
	insertionSort(num, size);

	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Elapsed Time = %f\n", timeresult);

	c1 = clock();
	insertionSortchar(name, sizename);

	printArraychar(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Elapsed Time = %f\n\n", timeresult);
	//end of insertionsort

	//selectionsort

	c1 = clock();
	SelectionSort(num, size);

	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Elapsed Time = %f\n\n", timeresult);
	c1 = clock();
	SelectionSortchar(name, sizename);

	printArraychar(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	//print time
	printf("Elapsed Time = %f\n\n", timeresult);


	//bublesort

	c1 = clock();
	bubbleSort(num, size);

	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Elapsed Time = %f\n\n", timeresult);
	c1 = clock();
	bubbleSortchar(name, sizename);

	printArraychar(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Elapsed Time = %f\n\n", timeresult);


	//merge sort

	c1 = clock();
	mergeSort(num, 0, size - 1);

	printArray(num, size);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Elapsed Time = %f\n\n", timeresult);
	c1 = clock();
	mergeSortChar(name, 0, sizename - 1);

	printArraychar(name, sizename);
	c2 = clock();
	timeresult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Elapsed Time = %f\n\n", timeresult);


	printf("2017556506-Oguzhan Turhan");
	return 0;
}
