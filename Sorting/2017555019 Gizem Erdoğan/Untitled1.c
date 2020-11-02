#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void swapName(char* xp, char* yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void swapNumber(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

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
	printf("    ");
	for (i = 0; i < n; i++)
		printf("%d ", number[i]);
	printf("\n");
}
/*Ýnsertion Sort*/
void insertionName(char name[], int len) {

	int i, key, j;
	for (i = 1; i < len; i++) {
		key = name[i];
		j = i - 1;

		while (j >= 0 && name[j] > key) {
			name[j + 1] = name[j];
			j = j - 1;
		}

		name[j + 1] = key;
	}

}
void insertionNumber(int number[], int n)
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

/*Selection Sort*/
void selectionSortNumber(int arr[], int n)
{
	int i, j, min_idx;


	for (i = 0; i < n - 1; i++)
	{
	
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

	
		swapNumber(&arr[min_idx], &arr[i]);
	}
}

void selectionSortName(char arr[], int len)
{
	int i, j, min_idx;


	for (i = 0; i < len - 1; i++)
	{
		 
		min_idx = i;
		for (j = i + 1; j < len; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		 
		swapName(&arr[min_idx], &arr[i]);
	}
}
 /*Merge Sort*/
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
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSortNumber(int arr[], int l, int r)
{
	if (l < r)
	{
	
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
	if (l < r)
	{
	 
		int m = l + (r - l) / 2;

	
		mergeSortName(arr, l, m);
		mergeSortName(arr, m + 1, r);

		mergeName(arr, l, m, r);
	}
}


/*Bubble Sort */
void bubbleSortNumber(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		   
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swapNumber(&arr[j], &arr[j + 1]);
}

void bubbleSortName(char arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		   
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swapName(&arr[j], &arr[j + 1]);
}
int main()
{

	char name[] = "Gizem Erdogan";
	int number[] = {2,0,1,7,5,5,5,0,1,9};
	clock_t time;

	int len = strlen(name);
	int n = sizeof(number) / sizeof(number[0]);

	time = clock();
	printf("-INSERTION SORT\n\n");
	insertionName(name, len);
	time = clock() - time;
	printArrayName(name, len);
	printf("Insertion sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	insertionNumber(number, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Insertion sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	printf("\n-SELECTION SORT\n\n");
	selectionSortName(name, len);
	time = clock() - time;
	printArrayName(name, len);
	printf("Selection sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);


	selectionSortNumber(number, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Selection sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	printf("\n-MERGE SORT\n\n");
	mergeSortName(name, 0, len-2);
	time = clock() - time;
	printArrayName(name, len);
	printf("Merge sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	mergeSortNumber(number, 0, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Merge sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	printf("\n-BUBBLE SORT\n\n");
	bubbleSortName(name, len);
	time = clock() - time;
	printArrayName(name, len);
	printf("Bubble sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	bubbleSortNumber(number, n);
	time = clock() - time;
	printArrayNumber(number, n);
	printf("Bubble sort time: %f\n", ((double)time) / CLOCKS_PER_SEC);

	return 0;
}
