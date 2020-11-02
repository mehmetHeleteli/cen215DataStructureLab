#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void PrintArray(int arr[], int _x) {

	int _i;
	for (_i = 0; _i < _x; _i++)
	printf("%d", arr[_i]);
	printf("\n", arr[_i]);
}
void PrintArrayChar(char arr[], int _x) {

	int _i;
	for (_i = 0; _i < _x; _i++)
	printf("%c", arr[_i]);
	printf("\n", arr[_i]);
}

void Swap(int* _x, int* _y)
{
	int _temp = *_x;
	*_x = *_y;
	*_y = _temp;
}
void SwapChar(char *_x, char *_y)
{
	char _temp = *_x;
	*_x = *_y;
	*_y = _temp;
}
/* Insertion Sort */
void InsertionSort(int arr[], int _k) {
	int _i, _key, _j;
	for (_i = 1; _i < _k; _i++)
	{
		_key = arr[_i];
		
		for (_j=_i-1;_j >= 0 && arr[_j] > _key;--_j)
		{
			arr[_j + 1] = arr[_j];
			
		}
		arr[_j + 1] = _key;
	}
}
void InsertionSortChar(char array[], int _k)
{
	int _i, _j;
	char _key;
	for (_i = 1; _i < _k; _i++) {
		_key = array[_i];
		_j = _i - 1;
		while (_j >= 0 && array[_j] > _key) {
			array[_j + 1] = array[_j];
			_j = _j - 1;
		}
		array[_j + 1] = _key;
	}
}


/* Selection Sort */
void SelectionSort(int array[],int _size)
{
	int _i,_j;
	int currentMin;
	for ( _i = 0; _i < _size - 1; _i++)
	{
		currentMin = _i;
		for (_j = _i + 1; _j < _size; _j++)
		{
			if(array[_j]<array[currentMin])
			{
				currentMin = _j;
			}
		}
		Swap(&array[currentMin], &array[_i]);
	}
}

void SelectionSortChar(char array[], int _size)
{
	int _i, _j;
	char _min;
	for (_i = 0; _i < _size - 1; _i++)
	{
		_min = _i;
		for (_j = _i + 1; _j < _size; _j++)
			if (array[_j] < array[_min])
				_min = _j;
		SwapChar(&array[_min], &array[_i]);
	}
}

//Merge Sort 
void Merge(int arr[], int _l, int _m, int _r)
{
	int _i, _a, _b;
	int _p1 = _m - _l + 1;
	int _p2 = _r -_m;

	int L[_p1];
	int R[_p2];

	for (_i = 0; _i < _p1; _i++)
		L[_i] = arr[_l + _i];
	for (_a = 0; _a < _p2; _a++)
		R[_a] = arr[_m + 1 + _a];

	_i = 0;
	_a = 0;
	_b = _l;
	while (_i < _p1 && _a < _p2)
	{
		if (L[_i] <= R[_a])
		{
			arr[_b] = L[_i];
			_i++;
		}
		else
		{
			arr[_b] = R[_a];
			_a++;
		}
		_b++;
	}

	while (_i < _p1)
	{
		arr[_b] = L[_i];
		_i++;
		_b++;
	}

	while (_a < _p2)
	{
		arr[_b] = R[_a];
		_a++;
		_b++;
	}
}


void MergeSort(int arr[], int _l, int _r)
{
	if (_l < _r)
	{

		int _m = _l + (_r - _l) / 2;

		MergeSort(arr, _l, _m);
		MergeSort(arr, _m + 1, _r);

		Merge(arr, _l,_m, _r);
	}
}

/* Bubble Sort */


void BubbleSort(int arr[], int _n)
{
	int _i, _j;
	for (_i = 0; _i < _n - 1; _i++)
		for (_j = 0; _j < _n - _i - 1; _j++)
			if (arr[_j] > arr[_j + 1])
				Swap(&arr[_j], &arr[_j + 1]);
}
void BubbleSortChar(char array[], int _n)
{
	int _i, _j;
	for (_i = 0; _i < _n - 1; _i++)
		for (_j = 0; _j < _n - _i - 1; _j++)
			if (array[_j] > array[_j + 1])
				SwapChar(&array[_j], &array[_j + 1]);
}

void MergeChar(char arr[], int _a, int _b, int _c)
{
    int _j, _i , _m, _k, _n;

    _m = _b - _a + 1;

    _n = _c - _b;

    int A[_m], B[_n];

    for (_i = 0; _i < _m; _i++)

        A[_i] = arr[_a + _i];
    for (_j = 0; _j < _n; _j++)


        B[_j] = arr[_b + 1 + _j];
    _i = 0;
    _j = 0;
    _k = _a;

    while (_i < _m && _j < _n)
    {
        if (A[_i] <= B[_j])
        {
            arr[_k] = A[_i];
            _i++;
        }
        else {
            arr[_k] = B[_j];
            _j++;
        }
       _k++;
    }

    while (_i < _m)
    {
        arr[_k] = A[_i];
        _i++;
        _k++;
    }

    while (_j < _n) {
        arr[_k] = B[_j];
        _j++;
        _k++;
    }
}

void MergeSortChar(char arr[], int _r, int _l)
{
    if (_l < _r) {
        int _m = _l + (_r - _l) / 2;
        MergeSortChar(arr, _l, _m);
        MergeSortChar(arr, _m + 1, _r);
        MergeChar(arr, _l, _m, _r);
    }
}

int main(int argc, char const* argv[])
{
	

	int num[] = {2,0,1,7,5,5,6,0,4,8};
	char name[] = "Veli Kaan Sarikaya";
	int _size = sizeof(num) / sizeof(num[0]);
	int sizeName= strlen(name);
	clock_t c1, c2;
	double timeResult;


	//insertionsort
	
	c1 = clock();
	InsertionSort(num, _size);
	
	PrintArray(num, _size);
	c2 = clock();
	timeResult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n", timeResult);

	c1 = clock();
	InsertionSortChar(name, sizeName);
	
	PrintArrayChar(name, sizeName);
	c2 = clock();
	timeResult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n\n", timeResult);
	//end of insertionsort
	
	//selectionsort
	
	c1 = clock();
	SelectionSort(num, _size);
	
	PrintArray(num, _size);
	c2 = clock();
	timeResult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n\n", timeResult);
	c1 = clock();	
	SelectionSortChar(name, sizeName);

	PrintArrayChar(name, sizeName);
	c2 = clock();
	timeResult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	//print time
	printf("Time = %f\n\n", timeResult);

	
	//bublesort
	
	c1 = clock();
	BubbleSort(num, _size);

	PrintArray(num, _size);
	c2 = clock();
	timeResult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n\n", timeResult);
	c1 = clock();
	BubbleSortChar(name, sizeName);

	PrintArrayChar(name, sizeName);
	c2 = clock();
	timeResult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n\n", timeResult);
	
	
	//merge sort
	
	c1 = clock();
	MergeSort(num,0, _size-1);
	
	PrintArray(num, _size);
	c2 = clock();
	timeResult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n\n", timeResult);
	c1 = clock();
	MergeSortChar(name,0, sizeName-1);

	PrintArrayChar(name, sizeName);
	c2 = clock();
	timeResult = (double)(c2 - c1) / CLOCKS_PER_SEC;
	printf("Time = %f\n\n", timeResult);

	
	printf("2017556048-Veli Kaan Sarikaya");
	return 0;
}
