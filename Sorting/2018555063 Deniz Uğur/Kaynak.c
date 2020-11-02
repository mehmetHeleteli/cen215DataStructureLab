#include <stdio.h>
#include<time.h>
#include<conio.h>
clock_t start_t, end_t, total_t;
void bubblesort(int arr[], int size) {


	start_t = clock();
	int counter, counter2;
	int a;

	for (counter = 0; counter < size - 1; counter++) {
		for (counter2 = 0; counter2 < size - counter - 1; counter2++) {

			if (arr[counter2] > arr[counter2 + 1]) {


				a = arr[counter2];
				arr[counter2] = arr[counter2 + 1];
				arr[counter2 + 1] = a;





			}




		}



	}
	printf("your array sorted with bubblesorting method:  ");
	for (counter = 0; counter < size; counter++)
		printf("%d", arr[counter]);

	end_t = clock();
	printf("     sort time: %f\n", ((double)end_t - start_t) / CLOCKS_PER_SEC);



}
void bubblesortstr(char arr[], int size) {
	start_t = clock();
	int counter, counter2;
	int a;

	for (counter = 0; counter < size - 1; counter++) {
		for (counter2 = 0; counter2 < size - counter - 1; counter2++) {

			if (arr[counter2] > arr[counter2 + 1]) {


				a = arr[counter2];
				arr[counter2] = arr[counter2 + 1];
				arr[counter2 + 1] = a;





			}




		}



	}

	printf("your string bubblesorting with selection method:  ");
	for (counter = 0; counter < size; counter++)
		printf("%c", arr[counter]);
	end_t = clock();
	printf("     sort time: %f\n", ((double)end_t - start_t) / CLOCKS_PER_SEC);


}
void selectionsort(int arr[], int size) {
	start_t = clock();

	int pivot, counter, counter2;
	int a;


	for (counter = 0; counter < size - 1; counter++) {
		pivot = counter;
		for (counter2 = counter + 1; counter2 < size; counter2++) {
			if (arr[pivot] < arr[counter2])
				pivot = counter2;

		}

		if (pivot != counter) {
			a = arr[counter];
			arr[counter] = arr[pivot];
			arr[pivot] = a;



		}

	}
	printf("your array sorted with selection method:  ");
	for (counter = 0; counter < size; counter++)
		printf("%d", arr[counter]);
	end_t = clock();
	printf("     sort time: %f\n", ((double)end_t - start_t) / CLOCKS_PER_SEC);
}
void selectionsortstr(char arr[], int size) {
	start_t = clock();

	int pivot, counter, counter2;
	int a;


	for (counter = 0; counter < size - 1; counter++) {
		pivot = counter;
		for (counter2 = counter + 1; counter2 < size; counter2++) {
			if (arr[pivot] > arr[counter2])
				pivot = counter2;

		}

		if (pivot != counter) {
			a = arr[counter];
			arr[counter] = arr[pivot];
			arr[pivot] = a;



		}

	}
	printf("your string sorted with selection method:  ");
	for (counter = 0; counter < size; counter++)
		printf("%c", arr[counter]);

	end_t = clock();


	printf("     sort time: %f\n", ((double)end_t - start_t) / CLOCKS_PER_SEC);






}
void insertionsort(int arr[], int size) {
	start_t = clock();
	int counter, counter2, a;

	for (counter = 1; counter < size; counter++) {
		a = arr[counter];


		for (counter2 = counter - 1; counter2 >= 0 && a <= arr[counter2]; counter2--) {
			arr[counter2 + 1] = arr[counter2];


		}

		arr[counter2 + 1] = a;
	}

	printf("your array sorted with insertion method:  ");
	for (counter = 0; counter < size; counter++)
		printf("%d", arr[counter]);
	end_t = clock();
	printf("     sort time: %f\n", ((double)end_t - start_t) / CLOCKS_PER_SEC);
}
void insertionsortstr(char arr[], int size) {
	start_t = clock();
	int counter, counter2, a;
	for (counter = 1; counter < size; counter++) {
		a = arr[counter];
		for (counter2 = counter - 1; counter2 >= 0 && a <= arr[counter2]; counter2--) {

			arr[counter2 + 1] = arr[counter2];
		}

		arr[counter2 + 1] = a;

	}

	printf("your string sorted with selection method:  ");
	for (counter = 0; counter < size; counter++)
		printf("%c", arr[counter]);
	end_t = clock();
	printf("     sort time: %f\n", ((double)end_t - start_t) / CLOCKS_PER_SEC);


}

void merging(int a[], int low, int mid, int high) {
	int l1, l2, i;
	int b[100];

	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
		if (a[l1] <= a[l2])
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	}

	while (l1 <= mid)
		b[i++] = a[l1++];

	while (l2 <= high)
		b[i++] = a[l2++];

	for (i = low; i <= high; i++)
		a[i] = b[i];

}
void mergesort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);

		merging(arr, left, mid, right);
	}




}
void mergeChar(char arr[], int left, int mid, int right)
{
	int i, j, k, n1, n2;
	n1 = mid - left + 1;
	n2 = right - mid;

	char L[100], R[100];

	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

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

void mergeSortChar(char arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortChar(arr, l, m);
		mergeSortChar(arr, m + 1, r);

		mergeChar(arr, l, m, r);
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main() {
	int size; int arr[10] = { 2,0,1,8,5,5,5,0,6,3 };
	int i;
	int size3;



	printf("my number is 2018555063 \n");
	printf("my name is Deniz Ugur \n");

	char str[100] = "denizugur";
	int size2 = 9;
	int a;


	bubblesort(arr, 10);
	selectionsort(arr, 10);
	bubblesortstr(str, size2);
	selectionsortstr(str, size2);
	insertionsort(arr, 10);
	insertionsortstr(str, size2);
	start_t = clock();
	mergesort(arr, 0, 9);
	printf("your array sorted with mergesort:");
	for (int i = 0; i < 10; i++) {
		printf("%d", arr[i]);
	}
	end_t = clock();
	printf("     sort time: %f\n", ((double)end_t - start_t) / CLOCKS_PER_SEC);
	mergeSortChar(str, 0, size2);
	start_t = clock();
	printf("your  string sorted with mergesort:");
	for (int i = 0; i < 10; i++) {
		printf("%c", str[i]);
	}
	end_t = clock();
	printf("     sort time: %f\n", ((double)end_t - start_t) / CLOCKS_PER_SEC);







	return 0;



}