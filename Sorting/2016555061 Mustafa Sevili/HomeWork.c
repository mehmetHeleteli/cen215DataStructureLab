#include <stdio.h>
#include <string.h>
#include <time.h>

//Swap func
void swap(int* ap, int* bp)
{
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}
void swapName(char* ap, char* bp)
{
	char temp = *ap;
	*ap = *bp;
	*bp = temp;
}
//Insertion_Sort algorithm
void insertionChar(char name[], int lenght) {

	int i, key, j;
	for (i = 1; i < lenght; i++) {
		key = name[i];
		j = i - 1;

		while (j >= 0 && name[j] > key) {
			name[j + 1] = name[j];
			j = j - 1;
		}

		name[j + 1] = key;
	}

}

void insertionNum(int number[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = number[i];
		j = i - 1;


		while (j >= 0 && number[j] > key) {
			number[j + 1] = number[j];
			j = j - 1;
		}
		number[j + 1] = key;
	}
}
//Selection_Sort Algorithm
void selectionNum(int num[], int n)
{
	int i, j, minIndex;

	for (i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < n; j++)
			if (num[j] < num[minIndex])
				minIndex = j;

		swap(&num[minIndex], &num[i]);
	}
}
void selectionName(char name[], int lenght) {
	int i, j, mnmIndex;

	for (i = 0; i < lenght - 1; i++)
	{
		mnmIndex = i;
		for (j = i + 1; j < lenght; j++)
			if (name[j] < name[mnmIndex])
				mnmIndex = j;

		swapName(&name[mnmIndex], &name[i]);
	}

}
//Bubble_Sort Algorithm
void bubbleNum(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void bubbleName(char name[], int lenght)
{
	int i, j;
	for (i = 0; i < lenght - 1; i++)

		for (j = 0; j < lenght - i - 1; j++)
			if (name[j] > name[j + 1])
				swapName(&name[j], &name[j + 1]);
}
//MERGE SORT ALGORITHM
void mergeNumber(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

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
void mergeSortNumber(int arr[], int l, int r)
{
	if (l < r) {

		int m = l + (r - l) / 2;


		mergeSortNumber(arr, l, m);
		mergeSortNumber(arr, m + 1, r);

		mergeNumber(arr, l, m, r);
	}
}

void mergeName(char arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

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

		mergeName(arr, l, m, r);
	}
}


//Print Funcs
void printArrayName(char name[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%c ", name[i]);
	printf("\n");
}
void printArrayNumber(int number[], int n)
{
	int i;
	printf("  ");
	for (i = 0; i < n; i++)
		printf("%d ", number[i]);
	printf("\n");
}


int main()
{
	clock_t t;

	char name[] = "Mustafa Sevili";
	int number[] = { 2,0,1,6,5,5,5,0,6,1 };

	int len = strlen(name);
	int n = sizeof(number) / sizeof(number[0]);

	
	printf("My name is: Mustafa Sevili\nMy school number is: 2016555061\n\n");
	printf("Insertion Sort\n");
	t = clock();
	insertionChar(name, len);
	t = clock() - t;
	printArrayName(name, len);
	printf("Insertion Sort Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	insertionNum(number, n);
	t = clock() - t;
	printArrayNumber(number, n);
	printf("Insertion Sort Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	printf("Selection Sort\n");
	t = clock();
	selectionName(name, len);
	t = clock() - t;
	printArrayName(name, len);
	printf("Selection Sort Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	selectionNum(number, n);
	t = clock() - t;
	printArrayNumber(number, n);
	printf("Selection Sort Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	printf("Bubble Sort\n");
	t = clock();
	bubbleName(name, len);
	t = clock() - t;
	printArrayName(name, len);
	printf("Bubble Sort Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	bubbleNum(number, n);
	t = clock() - t;
	printArrayNumber(number, n);
	printf("Bubble Sort Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	printf("Merge sort\n");
	t = clock();
	mergeSortName(name, 0, len - 1);
	t = clock() - t;
	printArrayName(name, len);
	printf("Merge Sort Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	mergeSortNumber(number, 0, n - 1);
	t = clock() - t;
	printArrayNumber(number, n);
	printf("Merge Sort Time: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

	return 0;

}

