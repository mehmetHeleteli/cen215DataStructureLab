#include <stdio.h>
#include<string.h>
#include<time.h>
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swapName(char* xp, char* yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int array[], int size) {
	int currentMin;
	int i, j;
	for (i = 0; i < size - 1; ++i) {
		currentMin = i;
		for (j = i + 1; j < size; ++j) {
			if (array[j] < array[currentMin]) {
				currentMin = j;
			}
		}
		swap(&array[currentMin], &array[i]);
	}
}
void selectionSortName(char array[], int size) {
	char currentMin;
	int i, j;
	for (i = 0; i < size - 1; ++i) {
		currentMin = i;
		for (j = i + 1; j < size; ++j) {
			if (array[j] < array[currentMin]) {
				currentMin = j;
			}
		}
		swapName(&array[currentMin], &array[i]);
	}
}


void bubblesort(int array[], int size) {
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}
void bubblesortName(char array[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swapName(&array[j], &array[j + 1]);
			}
		}
	}
}


void merge(int array[], int left, int middle, int right) {
	int lsize;
	int rsize;
	lsize = middle - left + 1;
	rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i = 0;
	int j = 0;

	for (i = 0; i < lsize; ++i) {
		Left[i] = array[left + i];
	}
	for (j = 0; j < rsize; ++j) {
		Right[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; int org = left;
	while (i < lsize && j < rsize) {
		if (Left[i] <= Right[j]) {
			array[org] = Left[i];
			i++;
		}
		else {
			array[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize) {
		array[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize) {
		array[org] = Right[j];
		org++;
		j++;
	}
}


void mergesort(int array[], int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergesort(array, left, middle); //left
		mergesort(array, middle + 1, right); //right  //tekrar bak middle+1 olbilir

		merge(array, left, middle, right);
	}
}

void mergename(char array[], int left, int middle, int right) {
	int lsize;
	int rsize;
	lsize = middle - left + 1;
	rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i = 0;
	int j = 0;

	for (i = 0; i < lsize; ++i) {
		Left[i] = array[left + i];
	}
	for (j = 0; j < rsize; ++j) {
		Right[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; int org = left;
	while (i < lsize && j < rsize) {
		if (Left[i] <= Right[j]) {
			array[org] = Left[i];
			i++;
		}
		else {
			array[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize) {
		array[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize) {
		array[org] = Right[j];
		org++;
		j++;
	}
}


void mergesortname(char array[], int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergesortname(array, left, middle); //left
		mergesortname(array, middle + 1, right); //right  //tekrar bak middle+1 olbilir

		mergename(array, left, middle, right);
	}
}

void insertionsort(int array[], int size) {
	int i, j;
	int key;
	for (i = 1; i < size; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}
void insertionsortname(char array[], int size) {
	int i, j;
	char key;
	for (i = 1; i < size; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}




void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}


int main() {
	clock_t t;
	
	printf("My name is Ibrahim Dogu KOCACIFTCI.\My number is 2019556043.\n");
	int selectionnum[] = { 2,0,1,9,5,5,6,0,4,3 };
	char selectionname[] = "Ibrahim Dogu KOCACIFTCI";
	int selectionsize = sizeof(selectionnum) / sizeof(selectionnum[0]);
	int selectionnamesize = strlen(selectionname);

	t = (double)clock();
	selectionSort(selectionnum, selectionsize);
	t = (double)clock()-t;
	printf("Selection Sort for Number\n");
	printArray(selectionnum, selectionsize);
	printf("Selection Sort Performance for Number: %f\n\n", ((double)t) / CLOCKS_PER_SEC);

	t = (double)clock();
	selectionSortName(selectionname, selectionnamesize);
	t = (double)clock()-t;

	printf("Selection Sort for Name \n %s\nSelection Sort Performance for Name: %f\n\n\n", selectionname,((double)t) / CLOCKS_PER_SEC);

	int bubblenum[] = { 2,0,1,9,5,5,6,0,4,3 };
	char bubblename[] = "Ibrahim Dogu KOCACIFTCI";
	int bubblesize = sizeof(bubblenum) / sizeof(bubblenum[0]);
	int bubblenamesize = strlen(bubblename);
	t = (double)clock();
	bubblesort(bubblenum, bubblesize);
	t = (double)clock()-t;
	printf("Bubble Sort for Number\n");
	printArray(bubblenum, bubblesize);
	printf("Bubble Sort Performance for Number: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	
	t = (double)clock();
	bubblesortName(bubblename, bubblenamesize);
	t = (double)clock()-t;
	printf("Bubble Sort for Name \n %s\nBubble Sort Performance for Name: %f\n\n\n", bubblename,((double)t) / CLOCKS_PER_SEC);

	int mergenum[] = { 2,0,1,9,5,5,6,0,4,3 };
	char mergename[] = "Ibrahim Dogu KOCACIFTCI";
	int mergesize = sizeof(mergenum) / sizeof(mergenum[0]);
	int mergenamesize = strlen(mergename);
	
	t = (double)clock();
	mergesort(mergenum, 0, mergesize - 1);
	t = (double)clock()-t;
	printf("Merge Sort for Number\n");
	printArray(mergenum, mergesize);
	printf("Merge Sort Performance for Number: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	
	t = (double)clock();
	mergesortname(mergename, 0, mergenamesize - 1);
	t = (double)clock()-t;
	printf("Merge Sort for Name \n %s\nMerge Sort Performance for Name: %f\n\n\n", mergename,((double)t) / CLOCKS_PER_SEC);

	int insertionnum[] = { 2,0,1,9,5,5,6,0,4,3 };
	char insertionname[] = "Ibrahim Dogu KOCACIFTCI";
	int insertionsize = sizeof(insertionnum) / sizeof(insertionnum[0]);
	int insertionnamesize = strlen(insertionname);
	
	t = (double)clock();
	insertionsort(insertionnum, insertionsize);
	t = (double)clock()-t;
	printf("Insertion Sort for Number\n");
	printArray(insertionnum, insertionsize);
	printf("Insertion Sort Performance for Number: %f\n\n", ((double)t) / CLOCKS_PER_SEC);
	t = (double)clock();
	insertionsortname(insertionname, insertionnamesize);
	t = (double)clock()-t;
	printf("Insertion Sort for Name \n %s\nInsertion Sort Performance for Name: %f\n\n\n", insertionname,((double)t) / CLOCKS_PER_SEC);



	return 0;
}