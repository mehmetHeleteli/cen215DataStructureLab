#include <stdio.h>
#include<string.h>
#include<time.h>

void swapNum(int* x, int* y)
{
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

void selectionSortNum(int array[], int size)
{
	int currentMin;
	int i, j;
	for (i = 0; i < size - 1; ++i)
	{
		currentMin = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[currentMin])
			{
				currentMin = j;
			}
		}
		swapNum(&array[currentMin], &array[i]);
	}
}

void selectionSortName(char array[], int size)
{
	char currentMin;
	int i, j;
	for (i = 0; i < size - 1; ++i)
	{
		currentMin = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[currentMin])
			{
				currentMin = j;
			}
		}
		swapName(&array[currentMin], &array[i]);
	}
}

void bubbleSortNum(int array[], int size)
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swapNum(&array[j], &array[j + 1]);
			}
		}
	}
}

void bubbleSortName(char array[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapName(&array[j], &array[j + 1]);
			}
		}
	}
}

void mergeNum(int array[], int left, int middle, int right)
{
	int lsize;
	int rsize;
	lsize = middle - left + 1;
	rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i = 0;
	int j = 0;
	for (i = 0; i < lsize; ++i) 
	{
		Left[i] = array[left + i];
	}
	for (j = 0; j < rsize; ++j) 
	{
		Right[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; int org = left;
	while (i < lsize && j < rsize) 
	{
		if (Left[i] <= Right[j]) 
		{
			array[org] = Left[i];
			i++;
		}
		else 
		{
			array[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize) 
	{
		array[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize) 
	{
		array[org] = Right[j];
		org++;
		j++;
	}
}

void mergeSortNum(int array[], int left, int right)
{
	if (left < right) 
	{
		int middle = left + (right - left) / 2;
		mergeSortNum(array, left, middle); //left
		mergeSortNum(array, middle + 1, right); //right  //tekrar bak middle+1 olbilir
		mergeNum(array, left, middle, right);
	}
}

void mergeName(char array[], int left, int middle, int right)
{
	int lsize;
	int rsize;
	lsize = middle - left + 1;
	rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i = 0;
	int j = 0;
	for (i = 0; i < lsize; ++i) 
	{
		Left[i] = array[left + i];
	}
	for (j = 0; j < rsize; ++j) 
	{
		Right[j] = array[middle + 1 + j];
	}
	i = 0; j = 0; int org = left;
	while (i < lsize && j < rsize) 
	{
		if (Left[i] <= Right[j]) 
		{
			array[org] = Left[i];
			i++;
		}
		else 
		{
			array[org] = Right[j];
			j++;
		}
		org++;
	}
	while (i < lsize) 
	{
		array[org] = Left[i];
		org++;
		i++;
	}
	while (j < rsize) 
	{
		array[org] = Right[j];
		org++;
		j++;
	}
}

void mergeSortName(char array[], int left, int right)
{
	if (left < right)
    {
		int middle = left + (right - left) / 2;
		mergeSortName(array, left, middle); //left
		mergeSortName(array, middle + 1, right); //right  //tekrar bak middle+1 olbilir
		mergeName(array, left, middle, right);
	}
}

void insertionSortNum(int array[], int size)
{
	int i, j;
	int key;
	for (i = 1; i < size; i++) 
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) 
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void insertionSortName(char array[], int size)
{
	int i, j;
	char key;
	for (i = 1; i < size; i++) 
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) 
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void printArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; ++i) 
	{
		printf("%d ", array[i]);
	}
}

int main(){
    clock_t time;
	int number[] = { 2,0,1,7,5,5,6,0,2,9 };
	char name[] = "Omer Faruk Gunes";
	int sizeOfNumber = sizeof(number) / sizeof(number[0]);
	int sizeOfName = strlen(name);
	int defaultNumber[sizeOfNumber];
	char defaultName[sizeOfName];
	memcpy(defaultNumber,number,sizeOfNumber);
    memcpy(defaultName,name,sizeOfName);
    printf("My name is: %s and my number is: ",name);
    printArray(number, sizeOfNumber);
    
	time = (double)clock();
	selectionSortNum(number, sizeOfNumber);
	time = (double)clock()-time;
	printf("\n\nSelection Sort for Number: ");
	printArray(number, sizeOfNumber);
	printf("\nSelection Sort Performance for Number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	
	time = (double)clock();
	selectionSortName(name, sizeOfName);
	time = (double)clock()-time;
	printf("Selection Sort for Name: %s\nSelection Sort Performance for Name: %f\n\n", name,((double)time) / CLOCKS_PER_SEC);

    memcpy(number, defaultNumber,sizeOfNumber);
    memcpy(name, defaultName,sizeOfName);
    
	time = (double)clock();
	bubbleSortNum(number, sizeOfNumber);
	time = (double)clock()-time;
	printf("Bubble Sort for Number: ");
	printArray(number, sizeOfNumber);
	printf("\nBubble Sort Performance for Number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	
	time = (double)clock();
	bubbleSortName(name, sizeOfName);
	time = (double)clock()-time;
	printf("Bubble Sort for Name: %s\nBubble Sort Performance for Name: %f\n\n", name,((double)time) / CLOCKS_PER_SEC);

	memcpy(number, defaultNumber,sizeOfNumber);
    memcpy(name, defaultName,sizeOfName);
    
	time = (double)clock();
	mergeSortNum(number, 0, sizeOfNumber - 1);
	time = (double)clock()-time;
	printf("Merge Sort for Number: ");
	printArray(number, sizeOfNumber);
	printf("\nMerge Sort Performance for Number: %f\n", ((double)time) / CLOCKS_PER_SEC);
	
	time = (double)clock();
	mergeSortName(name, 0, sizeOfName - 1);
	time = (double)clock()-time;
	printf("Merge Sort for Name: %s\nMerge Sort Performance for Name: %f\n\n", name,((double)time) / CLOCKS_PER_SEC);

    memcpy(number, defaultNumber,sizeOfNumber);
    memcpy(name, defaultName,sizeOfName);
    
	time = (double)clock();
	insertionSortNum(number, sizeOfNumber);
	time = (double)clock()-time;
	printf("Insertion Sort for Number: ");
	printArray(number, sizeOfNumber);
	printf("\nInsertion Sort Performance for Number: %f\n", ((double)time) / CLOCKS_PER_SEC);

	time = (double)clock();
	insertionSortName(name, sizeOfName);
	time = (double)clock()-time;
	printf("Insertion Sort for Name: %s\nInsertion Sort Performance for Name: %f\n", name,((double)time) / CLOCKS_PER_SEC);
	
	return 0;
}
