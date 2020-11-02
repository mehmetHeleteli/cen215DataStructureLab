#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include <time.h>


void displayIntArray(int *intArr);
void displayStringArray(char stringArr[]);

void bubbleSortint(int Id[]);
void bubbleSortString( char name[]);

int mergeSortInt(int Arr[]);
int merge(int left[], int right[]);

char mergeSortString(char Arr[]);
char mergeString(char left[], char right[]);

void inseriton(int Arr[]);
void inseritonString(char Arr[]);	

int selectionSort(int Arr[]);
char selectionSortString(char Arr[]);

void quickSortInt(int Arr[], int first, int last);
void quickSortString(char Arr[], int first, int last);

void swap(int* a, int* b);

void heapSortInt(int Arr[],int size);
void heapSortString(char Arr[], int size);

void heapify(int Arr[], int size, int i);
void heapifyString(char Arr[], int size, int i);


int main() {
	int i = 0, Id[] = { 2,0,1,8,5,5,5,0,2,8 }, Id2[] = { 2,0,1,8,5,5,5,0,2,8 };
	char name[] = { "mustafagulsoy" }, name2[] = { "mustafagulsoy" };
	int size = sizeof(Id) / sizeof(Id[0]);
	int sizeString = sizeof(name)/sizeof(name[0]);
	clock_t timer;
	
	timer = clock();
	bubbleSortint(Id);
	bubbleSortString(name);
	printf("\nthe bubble Sort work in %f\n\n", (float)(clock() - timer));

	while (i < 10) {
		Id[i] = Id2[i];
		i++;
	}
	i = 0;
	while (i < 12) {
		name[i] = name2[i];
		i++;
	}
	i = 0;


	//timer = clock();
	//mergeSortInt(Id);
	//mergeSortString(name);
 	//printf("the marge Sort work in %d", timer);
	while (i < 10) {
		Id[i] = Id2[i];
		i++;
	}
	i = 0;
	while (i < 12) {
		name[i] = name2[i]; 
		i++;
	}
	i = 0;

	timer = clock();
	selectionSort(Id);
	selectionSortString(name);

	printf("\nthe selection Sort work in %f\n\n", (float)(clock() - timer));
	while (i < 10) {
		Id[i] = Id2[i];
		i++;
	}
	i = 0;
	while (i < 12) {
		name[i] = name2[i];
		i++;
	}
	i = 0;

	timer = clock();
	inseriton(Id);
	inseritonString(name);

	printf("\nthe inseriton Sort work in %f\n\n", (float)((float)clock() - timer));
	while (i < 10) {
		Id[i] = Id2[i];
		i++;
	}
	i = 0;
	while (i < 12) {
		name[i] = name2[i];
		i++;
	}
	i = 1;

	timer = clock();
	quickSortInt(Id, 0, size-1);
	displayIntArray(Id);

	quickSortString(name, 0, sizeString - 1);

	while (i < 14) {
		printf("%c ",name[i]);
		i++;
	}
	i = 1;
	printf("\nthe Quick Sort work in %f\n\n", (float)(clock() - timer));


	timer = clock();
	heapSortInt(Id, size);
	displayIntArray(Id);

	heapSortString(name, sizeString);
	while (i < 14) {
		printf("%c ", name[i]);
		i++;
	}
	printf("\nthe HeapSort work in %f\n\n", (float)(clock() - timer));

	while (1)
		printf("   ");
	return 0;



}

void bubbleSortint(int Id[]	)
{


	int permI;
	int i;
	for (i = 0; i<9 ; i++) {
		if (Id[i] > Id[i + 1])
		{
			permI = Id[i];
			Id[i] = Id[i + 1];
			Id[i + 1] = permI;
			i = 0;

		}



	}
	

	displayIntArray(Id);


}
void bubbleSortString(char name[])
{
	char perm;
	int j;
	for (int j = 0; j < strlen(name)-1; j++) {
		
		if (name[j] > name[j + 1]) {
			perm = name[j];
			name[j] = name[j + 1];
			name[j + 1] = perm;
			j = 0;
		}
	}
	displayStringArray(name);

}
//inseriton merge bubble ve selection sortlarý ile sýralýcaksýn

void displayIntArray(int *intArr) {
	int i = 0;

	while (i < 10) {
		printf("%d      ", intArr[i]);
		i++;
	}





}
void displayStringArray(char stringArr[]) {
	int j = 0;

	
	while (j < strlen(stringArr)) {
		printf("%c ", stringArr[j]);
		j++;
	}
}

int mergeSortInt(int Arr[]) {

	int n, i, *left, * right;

	if (sizeof(Arr) / sizeof(int) == 1)
		return Arr[0];

	n = (sizeof(Arr) / sizeof(int)) / 2;
	left = (int*)malloc(n);
	right = (int*)malloc((sizeof(Arr) / sizeof(int))-n);

	for (i = 0; i < 2 * n; i++) {
		if (i < n) {
			left[i] = Arr[i];
		}
		else
			right[i - n] = Arr[i];
	}
	*left = mergeSortInt(left);
	*right = mergeSortInt(right);

	return merge(left, right);



}
int merge(int left[], int right[]) {
	int i = 0, j = 0,t = 0;
	int left_len = sizeof(left) / sizeof(int);
	int right_len = sizeof(right) / sizeof(int);
	int* totalArr = (int*)malloc(sizeof(left_len + right_len) / sizeof(int));
	while (i < left_len && j < right_len)
	{
		if (left[i] > right[j]) {
			totalArr[t] = right[j];
			j++;
			t++;
		}
		else
			
				totalArr[t] = left[j];
				i++;
				t++;
	}
;
	while (i < left_len)
		totalArr[t] = left[i];
	while (j < right_len)
		totalArr[t] = right[j];
	displayIntArray(totalArr);
	return *totalArr;
}

/*char mergeSortString(char Arr[]) {

	int n, i;
	char *left, * right;

	if (strlen(Arr) == 1)
		return Arr[0];

	n = strlen(Arr) / 2;
	//right = (char*)malloc(sizeof(char)*(strlen(Arr) - n));
	//left = (char*)malloc(n);
	

	for (i = 0; i < 2 * n; i++) {
		if (i < n) {
			left[i] = Arr[i];
		}
		else
			right[i - n] = Arr[i];
	}	
	*left = mergeSortString(left);
	*right = mergeSortString(right);

	return mergeString(left, right);






}

char mergeString(char left[], char right[]) {



	int i = 0, j = 0, t = 0;
	int left_len = strlen(left);
	int right_len = strlen(right);
	char* totalArr = (char*)malloc(sizeof(left_len + right_len) / sizeof(char));
	while (i < left_len && j < right_len)
	{
		if (left[i] > right[j]) {
			totalArr[t] = right[j];
			j++;
			t++;
		}
		else

			totalArr[t] = left[j];
		i++;
		t++;
	}
	;
	while (i < left_len)
		totalArr[t] = left[i];
	while (j < right_len)
		totalArr[t] = right[j];

	return *totalArr;
}
*/
int selectionSort(int Arr[]) {
	int i, j, t =0 ,min= Arr[0];
	
	int perm = 0;
	for (i = 0; i < 10; i++,t++)
	{
		
		for (j = i +1; j < 10; j++) {
		
			if (Arr[i] > Arr[j])
			{	
				perm = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = perm;
				
			}
		}
		
		
		
	}
	displayIntArray(Arr);
	return 0;
}

char selectionSortString(char Arr[]) {
	int i, j, t = 0;
	char perm;
	char* permenentArr = (char*)malloc(strlen(Arr));
	for (i = 0; i < strlen(Arr); i++)
	{
		for (j = i + 1; j < strlen(Arr); j++) {
			
			if (Arr[i] > Arr[j]) {
				perm = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = perm;
			}
		}
		
	}
	displayStringArray(Arr);
	return *permenentArr;
}


void inseriton(int Arr[]) 
	{
		int i, key, j;
		for (i = 1; i < 10; i++) {
			key = Arr[i];
			j = i - 1;

			while (j >= 0 && Arr[j] > key) {
				Arr[j + 1] = Arr[j];
				j = j - 1;
			}
			Arr[j + 1] = key;
		}
		displayIntArray(Arr);
	}

	void inseritonString(char Arr[]) {
		
			int i, j;
			char key;
			for (i = 1; i < 10; i++) {
				key = Arr[i];
				j = i - 1;

				while (j >= 0 && Arr[j] > key) {
					Arr[j + 1] = Arr[j];
					j = j - 1;
				}
				Arr[j + 1] = key;
			}
			displayStringArray(Arr);
	}
		

	void swap(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	
	void swapString(char* a, char* b) {
	
		char temp = *a;
		*a = *b;
		*b = temp;
	}
	void quickSortInt(int Arr[], int first, int last) {
		

		if (first < last) {

			int pivot = last;
			int lo = first;
			int hi = last -1;
			
			while (1) {

				while (Arr[lo] < Arr[pivot])
					lo++;


				while (Arr[hi] > Arr[pivot])
					hi--;

				if (lo < hi)
				{		swap(&Arr[lo], &Arr[hi]);
				
				
				if (hi == 6) {
					hi--;
				}
			}
				else
					break;
			

			}
				
			swap(&Arr[lo], &Arr[pivot]);
			quickSortInt(Arr, first, lo-1);  //left
			quickSortInt(Arr, lo+1, last);  // right

		}
		

	}

	void quickSortString(char Arr[], int first, int last)
	{
	
		if (first < last) {
			
			int pivot = last;
			int lo = first;
			int hi = last - 1;
		
			while (1) {
				
				while (Arr[lo] < Arr[pivot]) {
					lo++;
			

				}

				while (Arr[hi] > Arr[pivot]) {
					hi--;
					

				}
				if (lo < hi)
				{
					

					swapString(&Arr[lo], &Arr[hi]);
				
				
				}
				else
					break;
			

			}

			swapString(&Arr[lo], &Arr[pivot]);
			quickSortString(Arr, first, lo - 1);  //left
			quickSortString(Arr, lo + 1, last);  // right
		
		}
		

	}
	
	void heapSortInt(int Arr[], int size) {
		for (int i = size/2 - 1; i >= 0; i--)
			heapify(Arr, size, i);
		for (int i = size-1; i > 0 ; i--) {
			
			swap(&Arr[0],&Arr[i]);
			heapify(Arr, i, 0);
		}

		

		
	}
	void heapify(int Arr[], int size, int i) {
	
		int largest = i;
		int left_child = i * 2 + 1;
		int right_child = i * 2 + 2;

		if (Arr[left_child] > Arr[largest] && left_child < size) 
			largest = left_child;

		if (Arr[right_child] > Arr[largest] && right_child < size) 
			largest = right_child;

		if (i != largest) {
			swap(&Arr[i], &Arr[largest]);
			heapify(Arr, size, largest);
		}

		

	}


	void heapSortString(char Arr[], int size)
	{
		for (int i = size / 2 - 1; i >= 0; i--)
			heapifyString(Arr, size, i);
		for (int i = size - 1; i > 0; i--) {

			swapString(&Arr[0], &Arr[i]);
			heapifyString(Arr, i, 0);
		}
		displayStringArray(Arr);
	}

	void heapifyString(char Arr[], int size, int i)
{
	int largest = i;
	int left_child = i * 2 + 1;
	int right_child = i * 2 + 2;

	if (Arr[left_child] > Arr[largest] && left_child < size)
		largest = left_child;

	if (Arr[right_child] > Arr[largest] && right_child < size)
		largest = right_child;

	if (i != largest) {
		swapString(&Arr[i], &Arr[largest]);
		heapifyString(Arr, size, largest);
	}
	}
