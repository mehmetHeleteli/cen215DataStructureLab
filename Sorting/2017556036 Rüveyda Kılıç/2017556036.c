#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void insertionLetter(char letter[], int len);
void insertionNumber(int number[], int n);

void selectionLetter(char letter[], int len);
void selectionNumber(int number[], int lenN);

void bubbleLetter(char letter[], int len);
void bubbleNumber(int arr[], int lenN);

void mergeLetter(char arr[], int l, int m, int r);
void mergeSortLetter(char arr[], int l, int r);
void mergeNumber(int arr[], int l, int m, int r);
void mergeSortNumber(int arr[], int l, int r);

void printLetter(char let[], int len);
void printNumber(int num[], int n);

void swapLetter(char* xp, char* yp);
void swapNumber(int* xp, int* yp);

int main() {

	clock_t t;

	printf("Name:Ruveyda KILIC \nId  :2017556036  \n");
	char letters[] = "Ruveyda KILIC";
	int number[] = { 2,0,1,7,5,5,6,0,3,6 };
	
	int len = strlen(letters);
	int lenN = sizeof(number) / sizeof(number[0]);



	printf("\n \t Insertion sort \t \n");//insertionSort
	t = clock();
    insertionLetter(letters, len);
    t = clock() - t;
    printLetter(letters, len); 
    printf("time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	insertionNumber(number, lenN);	
	t = clock() - t;
	printNumber(number, lenN);
    printf("time: %f\n", ((double)t) / CLOCKS_PER_SEC);




	printf("\n \t Selection sort \t \n");//selectionSort
	t = clock();
	selectionLetter(letters, len);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	selectionNumber(number, lenN);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %f\n", ((double)t) / CLOCKS_PER_SEC);



	printf("\n \t Bubble sort \t \n");//bubbleSort
	t = clock();
	bubbleLetter(letters, len);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	bubbleNumber(number, lenN);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	


	printf("\n \t Merge sort \t \n");//mergeSort
	t = clock();
	mergeSortLetter(letters, 0, len - 1);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	mergeSortNumber(number, 0, lenN - 1);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	return 0;
}


//SWAP FUNCTIONS
void swapNumber(int* fn, int* ln){
	int temp = *fn;
	*fn = *ln;
	*ln = temp;}
void swapLetter(char* fl, char* ll){
	char temp = *fl;
	*fl = *ll;
	*ll = temp;}


//INSERTION SORT PART	
void insertionLetter(char letter[], int len) {
	int i, key, j;
	for (i = 1; i < len; i++) {
		key = letter[i];
		j = i - 1;
		while (j >= 0 && letter[j] > key) {
			letter[j + 1] = letter[j];
			j = j - 1;
		}
		letter[j + 1] = key;
	}
}
void insertionNumber(int number[], int lenN){
	int i, key, j;
	for (i = 1; i < lenN; i++) {
		key = number[i];
		j = i - 1;
		while (j >= 0 && number[j] > key) {
			number[j + 1] = number[j];
			j = j - 1;
		}
		number[j + 1] = key;
	}
}


//SELECTION SORT PART
void selectionLetter(char letter[], int len) {
	int i, j, minIndex;
	for (i = 0; i < len - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < len; j++) {
			if (letter[j] < letter[minIndex])
				minIndex = j;
		}
		swapLetter(&letter[minIndex], &letter[i]);
	}
}
void selectionNumber(int number[], int lenN){
	int i, j, minIndex;
	for (i = 0; i < lenN - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < lenN; j++) {
			if (number[j] < number[minIndex])
				minIndex = j;
		}
		swapNumber(&number[minIndex], &number[i]);
	}
}


//BUBBLE SORT PART
void bubbleNumber(int arr[], int lenN) {
	int i, j;
	for (i = 0; i < lenN - 1; i++) {
		for (j = 0; j < lenN - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swapNumber(&arr[j], &arr[j + 1]);
		}
	}
}
void bubbleLetter(char letter[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (letter[j] > letter[j + 1])
				swapLetter(&letter[j], &letter[j + 1]);
		}
	}
}


//MERGE SORT PART  

void mergeNumber(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int*L = (int *)malloc(n1 * sizeof(int));
	int*R = (int *)malloc(n2 * sizeof(int));

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
void mergeSortNumber(int arr[], int l, int r){
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortNumber(arr, l, m);
		mergeSortNumber(arr, m + 1, r);

		mergeNumber(arr, l, m, r);
	}
}
void mergeLetter(char arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int*L = (int *)malloc(n1 * sizeof(int));
	int*R = (int *)malloc(n2 * sizeof(int));

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
void mergeSortLetter(char arr[], int l, int r){
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortLetter(arr, l, m);
		mergeSortLetter(arr, m + 1, r);

		mergeLetter(arr, l, m, r);
	}
}    



//PRINT FUNCTIONS
void printLetter(char let[], int len){
	int i;
	printf("sorted letters:");
	for (i = 0; i < len; i++)
		printf("%c ", let[i]);
	printf("\n");
}
void printNumber(int num[], int lenN){
	int i;
	printf("sorted numbers:  ");
	for (i = 0; i < lenN; i++)
		printf("%d ", num[i]);
	printf("\n");
}
