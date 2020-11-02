#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



int main() {
	int arrId[] = { 2,0,1,8,5,5,5,0,4,9 };
	char arrName[] = "FURKAN OZDEMIR";

	int size1 = sizeof(arrId) / sizeof(arrId[2]);
	int size2 = strlen(arrName);

	clock_t time;
	time = clock();


	printf("\n");
	printf("OGRENCI ISMI: FURKAN OZDEMIR\n");
	printf("OGRENCI NO:2018555049\n\n\n");


	//SelectionSort

	printf("SelectionSort\n");

	selectionSortId(arrId, size1);
	printSortId(arrId, size1);
	selectionSortName(arrName, size2);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for selection sort : %f\n\n", ((double)(time)) / CLOCKS_PER_SEC);

	//InsertionSort

	printf("InsertionSort\n");

	insertionSortId(arrId, size1);
	printSortId(arrId, size1);
	insertionSortName(arrName, size2);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for insertion sort name: %f\n\n", ((double)(time)) / CLOCKS_PER_SEC);

	//BubbleSort

	printf("BubbleSort\n");

	bubbleSortId(arrId, size1);
	printSortId(arrId, size1);
	bubbleSortName(arrName, size2);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for bubble sort name: %f\n\n", ((double)(time)) / CLOCKS_PER_SEC);

	//MergeSort
	printf("MergeSort\n");

	mergeSortId(arrId, 0, size1 - 1);
	printSortId(arrId, size1);
	mergeSortName(arrName, 0, size2 - 1);
	time = clock() - time;
	printSortName(arrName, size2);
	printf("The total time for merge sort name: %f\n", ((double)(time)) / CLOCKS_PER_SEC);


	return 0;
}

const int MAX_SIZEI = 12;
const char MAX_SIZEC = 20;

//**swap type int**//

void swapId(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}
//**swap type char**//

void swapName(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
//***SELECTION SORT***//

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

//***INSERTION SORT***//

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

//***PRINT SORTS***//
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



