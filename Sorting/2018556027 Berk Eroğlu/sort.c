#include <time.h>
#include <stdio.h>
#include <string.h>

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
	
    printf("\n");
}

void swapNumber(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swapChar(char *num1, char *num2)
{
    char temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Insertion Sort for Number Array
void insertionSortForNumber(int num[], int size)
{

    int i, j;
    int x;
    for (i = 1; i < size; i++)
    {
        x = num[i];

        for (j = i - 1; j >= 0 && num[j] > x; j--)
        {
            num[j + 1] = num[j];
        }
        num[j + 1] = x;
    }
}

// END Insertion Sort for Number Array

// Insertion Sort for Name Array
void insertionSortForName(char name[], int size)
{
    int i, j;
    char x;
    for (i = 1; i < size; i++)
    {
        x = name[i];

        for (j = i - 1; j >= 0 && name[j] > x; j--)
        {
            name[j + 1] = name[j];
        }
        name[j + 1] = x;
    }
}
// END Insertion Sort for Name Array

// Selection Sort for Number Array

void selectionSortForNumber(int num[], int size)
{

    int i, j, min, temp;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (num[min] > num[j])
            {
                min = j;
            }
        }
        swapNumber(&num[i], &num[min]);
    }
}

// END Selection Sort for Number Array

// Selection Sort for Name Array

void selectionSortForName(char name[], int size)
{

    int i, j, min, temp;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (name[min] > name[j])
            {
                min = j;
            }
        }
        swapChar(&name[i], &name[min]);
    }
}

// END Selection Sort for Name Array

// Merge Sort for Number Array

void mergeForNumber(int num[], int l, int m, int r)
{
    int i, j, k;

    int leftSize = m - l + 1;
    int rightSize = r - m;

    int left[leftSize], right[rightSize];

    for (i = 0; i < leftSize; i++)
    {
        left[i] = num[l + i];
    }
    for (j = 0; j < rightSize; j++)
    {
        right[j] = num[m + 1 + j];
    }

    j = 0, i = 0, k = l;

    while (leftSize > i && rightSize > j)
    {
        if (left[i] <= right[j])
        {
            num[k] = left[i];
            i++;
        }
        else
        {
            num[k] = right[j];
            j++;
        }
        k++;
    }

    while (leftSize > i)
    {
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightSize > j)
    {
        num[k] = right[j];
        k++;
        j++;
    }
}

void mergeSortForNumber(int num[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortForNumber(num, l, m);
        mergeSortForNumber(num, m + 1, r);

        mergeForNumber(num, l, m, r);
    }
}

// END Merge Sort for Number Array

// Merge Sort for Name Array

void mergeForName(char num[], int l, int m, int r)
{
    int i, j, k;

    int leftSize = m - l + 1;
    int rightSize = r - m;

    int left[leftSize], right[rightSize];

    for (i = 0; i < leftSize; i++)
    {
        left[i] = num[l + i];
    }
    for (j = 0; j < rightSize; j++)
    {
        right[j] = num[m + 1 + j];
    }

    j = 0, i = 0, k = l;

    while (leftSize > i && rightSize > j)
    {
        if (left[i] <= right[j])
        {
            num[k] = left[i];
            i++;
        }
        else
        {
            num[k] = right[j];
            j++;
        }
        k++;
    }

    while (leftSize > i)
    {
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightSize > j)
    {
        num[k] = right[j];
        k++;
        j++;
    }
}

void mergeSortForName(char num[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortForName(num, l, m);
        mergeSortForName(num, m + 1, r);

        mergeForName(num, l, m, r);
    }
}

// END Merge Sort for Name Array

// Bubble Sort for Number Array

void bubbleSortForNumber(int num[], int size)
{
    int swapped = 0, i = 0, j;
    do
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                swapNumber(&num[j], &num[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}

// END Bubble Sort for Number Array

// Bubble Sort for Name Array

void bubbleSortForName(char name[], int size)
{
    int swapped = 0, i = 0, j;
    do
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (name[j] > name[j + 1])
            {
                swapChar(&name[j], &name[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}

// END Bubble Sort for Name Array

int main()
{
    int num[] = {2,0,1,8,5,5,6,0,2,7};
    char name[] = "BERK EROGLU";
    int sizeNum = sizeof(num) / sizeof(num[0]);
    int sizeName = (sizeof(name) / sizeof(name[0])) - 1;
    clock_t start, end;
    double total;

    //Insertion sort for number array
    start = clock();
    insertionSortForNumber(num, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion sort for number array : \n");
    printArray(num, sizeNum);
    printf("time = %f", total);
    //END Insertion sort for number array

    //Insertion sort for name array
    start = clock();
    insertionSortForName(name, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nInsertion sort for name array : \n");
    printf("%s\n", name);
    printf("time = %f", total);
    //Insertion sort for name array

    int num2[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name2[] = "BERK EROGLU";

    //Selection sort for number array
    start = clock();
    selectionSortForNumber(num2, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nSelection sort for number array : \n");
    printArray(num2, sizeNum);
    printf("time = %f", total);
    //END Selection sort for number array

    //Selection sort for name array
    start = clock();
    selectionSortForName(name2, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nSelection sort for name array : \n");
    printf("%s\n", name2);
    printf("time = %f\n", total);
    //END Selection sort for name array

    int num3[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name3[] = "BERK EROGLU";

    //Merge sort for num array
    start = clock();
    mergeSortForNumber(num3, 0, sizeNum - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nMerge sort for number array : \n");
    printArray(num3, sizeNum);
    printf("time = %f", total);
    //END Merge sort for num array

    //Merge sort for name array
    start = clock();
    mergeSortForName(name3, 0, sizeName - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nMerge sort for name array : \n");
    printf("%s\n", name3);
    printf("time = %f\n", total);
    //END Merge sort for name array

    int num4[] = {2, 0, 1, 8, 5, 5, 5, 0, 1, 6};
    char name4[] = "BERK EROGLU";

    //Bubble sort for num array
    start = clock();
    bubbleSortForNumber(num4, sizeNum);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nBubble sort for number array : \n");
    printArray(num4, sizeNum);
    printf("time = %f", total);
    //END Bubble sort for num array

    //Bubble sort for name array
    start = clock();
    bubbleSortForName(name4, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nBubble sort for name array : \n");
    printf("%s\n", name4);
    printf("time = %f\n", total);
    //END Bubble sort for name array
}
