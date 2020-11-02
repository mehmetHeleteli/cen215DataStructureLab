#include<stdio.h>
#include <time.h>

#define MERGENAMECONST 13
#define MERGENOCONST 10


void printList(int* d, int n,int isCharArray);
void insertionSort(int* d, int n);
void selectionSort(int* d, int n);
void bubbleSort(int* d, int n);
void mergeSort(int* d, int left, int right, int isName);
void mergeName(int* d, int left, int k, int right);
void mergeNum(int* d, int left, int k, int right);

void quickSort(int* d, int left,int right);
void heapify(int* d, int n, int i);
void heapSort(int* d, int n);

void swap(int* x, int* y);
void makeCharLower(int* d, int n);

int main() {
	clock_t start, end;

	char name[] = "RamazanSENGUL";
	int const nameLength = sizeof(name)-1;
	int nameArray[nameLength];
	for (int i = 0; i < nameLength; i++)
		nameArray[i] = name[i];
	
	int no[] = { 2,0,1,8,5,5,5,0,6,0 };
	int const noLength= sizeof(no) / sizeof(no[0]);
	
	//bubble Sort
	makeCharLower(nameArray, nameLength);
	start = clock();
	bubbleSort(no,noLength);
	end = clock();
	printList(no, noLength, 0);
	printf("working time bubble-no:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	bubbleSort(nameArray, nameLength);
	end = clock();
	printList(nameArray, nameLength, 1);
	printf("working time bubble-name:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	printf("\n\n\n");

	//insertion Sort
	for (int i = 0; i < nameLength; i++)
		nameArray[i] = name[i];
	int no1[] = { 2,0,1,8,5,5,5,0,6,0 };


	makeCharLower(nameArray, nameLength);
	start = clock();
	insertionSort(no1, noLength);
	end = clock();
	printList(no1, noLength, 0);
	printf("working time insertion-no:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	insertionSort(nameArray, nameLength);
	end = clock();
	printList(nameArray, nameLength, 1);
	printf("working time insertion-name:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	printf("\n\n\n");

	//selectionSort Sort
	for (int i = 0; i < nameLength; i++)
		nameArray[i] = name[i];
	int no2[] = { 2,0,1,8,5,5,5,0,6,0 };


	makeCharLower(nameArray, nameLength);
	start = clock();
	selectionSort(no2, noLength);
	end = clock();
	printList(no2, noLength, 0);
	printf("working time selection-no:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	selectionSort(nameArray, nameLength);
	end = clock();
	printList(nameArray, nameLength, 1);
	printf("working time selection-name:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	printf("\n\n\n");

	

	//mergeSort Sort
	for (int i = 0; i < nameLength; i++)
		nameArray[i] = name[i];
	int no3[] = { 2,0,1,8,5,5,5,0,6,0 };


	makeCharLower(nameArray, nameLength);
	start = clock();
	mergeSort(no3,0, noLength-1,0);
	end = clock();
	printList(no3, noLength, 0);
	printf("working time merge-no:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	
	start = clock();
	mergeSort(nameArray,0, nameLength - 1,1);
	end = clock();
	printList(nameArray, nameLength, 1);
	printf("working time merge-name:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	printf("\n\n\n");


	//quickSort Sort
	for (int i = 0; i < nameLength; i++)
		nameArray[i] = name[i];
	int no4[] = { 2,0,1,8,5,5,5,0,6,0 };


	makeCharLower(nameArray, nameLength);
	start = clock();
	quickSort(no4, 0, noLength - 1);
	end = clock();
	printList(no4, noLength, 0);
	printf("working time quick-no:%f\n", (double)(end - start) / CLOCKS_PER_SEC);


	start = clock();
	quickSort(nameArray, 0, nameLength - 1);
	end = clock();
	printList(nameArray, nameLength, 1);
	printf("working time quick-name:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	printf("\n\n\n");


	//heapSort Sort
	for (int i = 0; i < nameLength; i++)
		nameArray[i] = name[i];
	int no5[] = { 2,0,1,8,5,5,5,0,6,0 };

	makeCharLower(nameArray, nameLength);
	start = clock();
	heapSort(no5, noLength);
	end = clock();
	printList(no5, noLength, 0);
	printf("working time heap-no:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	heapSort(nameArray, nameLength);
	end = clock();
	printList(nameArray, nameLength, 1);
	printf("working time heap-name:%f\n", (double)(end - start) / CLOCKS_PER_SEC);

	printf("\n\n\n");

	


}

void heapSort(int* d, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(d, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(&d[0], &d[i]);
		heapify(d, i, 0);
	}
	
}

void heapify(int *d, int n, int i)
{
	int largest = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2;

	if (left < n && d[left] > d[largest])
		largest = left;

	if (right < n && d[right] > d[largest])
		largest = right;

	if (largest != i)
	{
		swap(&d[i], &d[largest]);
		heapify(d, n, largest);
	}
}
void quickSort(int* d, int first, int last) {
	int j, k, q;
	j = first;
	k = last;
	q = d[(first + last) / 2];
	
	while (1) {
		while (d[j] < q && j < last)
			j++;
		while (d[k] > q && k > first)
			k--;
		if (j <= k) {
			swap(&d[j], &d[k]);
			j++;
			k--;
		}
		else
			break;
	}
	if (first < k)
		quickSort(d, first, k);
	if (last > j)
		quickSort(d, j, last);
	
}
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void mergeSort(int* d, int left, int right, int isName) {
	int k;
	if (left < right) {
		k = (left + right) / 2;
		mergeSort(d, left, k, isName);
		mergeSort(d, k + 1, right, isName);
		if (isName == 1)
			mergeName(d, left, k, right);
		else
			mergeNum(d, left, k, right);
	}


}
void mergeName(int* d, int left, int k, int right) {
	int i, j, l = 0;
	int liss[MERGENAMECONST];
	for (i = left, j = k + 1; i <= k && j <= right;) {
		if (d[i] < d[j]) {
			liss[l] = d[i];
			i++;
		}
		else {
			liss[l] = d[j];
			j++;
		}
		l++;
	}

	while (i <= k) {
		liss[l] = d[i];
		i++; l++;
	}
	while (j <= right) {
		liss[l] = d[j];
		j++; l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		d[i] = liss[l];
	}




}

void mergeNum(int* d, int left, int k, int right) {
	int i, j, l = 0;
	//int liss[mergeNoConst];

	int liss[MERGENOCONST];
	for (i = left, j = k + 1; i <= k && j <= right;) {
		if (d[i] < d[j]) {
			liss[l] = d[i];
			i++;
		}
		else {
			liss[l] = d[j];
			j++;
		}
		l++;
	}

	while (i <= k) {
		liss[l] = d[i];
		i++; l++;
	}
	while (j <= right) {
		liss[l] = d[j];
		j++; l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		d[i] = liss[l];
	}

}


void bubbleSort(int* d, int n) {
	int i, j, temp;
	for (i = 0; i < (n - 1); i++) {
		for (j = 0; j < (n - 1 - i); j++) {
			if (d[j] > d[j + 1]) {
				temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
			}
		}
	}
}

void insertionSort(int* d, int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = d[i];
		for (j = i - 1; j>=0 && key<=d[j]; j--) {
			d[j + 1] = d[j];
		}
		d[j + 1] = key;
	}
}

void selectionSort(int* d, int n) {
	int i, j, index,min;
	for (i = 0; i < n; i++) {
		min = d[n - 1];
		index = n - 1;

		for (j = i; j < n; j++) {
			if (d[j] < min) {
				min = d[j];
				index = j;
			}
		}
		if (i != index) {
			d[index] = d[i];
			d[i] = min;
		}

	}
}



void makeCharLower(int* d, int n) {
	for (int i = 0; i < n; i++) {
		if (d[i] < 97) {
			d[i] += 32;
		}
	}
}

void printList(int* d, int n, int isCharArray) {
	for (int i = 0; i < n; i++) {
		if (isCharArray == 1)
			printf("%c ", d[i]);
		else
			printf("%d ", d[i]);
	}
	printf("\n");
}
