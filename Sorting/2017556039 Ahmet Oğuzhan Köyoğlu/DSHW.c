#include<stdio.h>
#include<string.h>
#include<time.h>

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void resArray(int num[], char name[]) {
    int numberCopy[] = { 2,0,1,7,5,5,6,0,3,9 };
    for (int i = 0; i < 10; i++) {
        num[i] = numberCopy[i];

    }
    char nameCopy[] = "oguzhan koyoglu";

    for (int i = 0; i < 15; i++) {
        name[i] = nameCopy[i];
    }
}

void insertionNumber(int num[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = num[i];
        j = i - 1;
        while (j >= 0 && num[j] > key)
        {
            num[j + 1] = num[j];
            j -= 1;
        }
        num[j + 1] = key;
    }
}

void insertionName(char name[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = name[i];
        j = i - 1;
        while (j >= 0 && name[j] > key)
        {
            name[j + 1] = name[j];
            j -= 1;
        }
        name[j + 1] = key;
    }
}

void swapInt(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swapChar(char* char1, char* char2)
{
    char temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}


void selectionNumber(int num[], int n)
{
    int i, j, key;
    for (i = 0; i < n - 1; i++)
    {
        key = i;
        for (j = i + 1; j < n; j++)
        {
            if (num[j] < num[key])
                key = j;
        }
        swapInt(&num[key], &num[i]);
    }
}

void selectionName(char name[], int n)
{
    int i, j, key;
    for (i = 0; i < n - 1; i++)
    {
        key = i;
        for (j = i + 1; j < n; j++)
        {
            if (name[j] < name[key])
                key = j;
        }
        swapChar(&name[key], &name[i]);

    }
}


void mergeSortNum(int num[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = num[left + i];
    for (j = 0; j < n2; j++)
        R[j] = num[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            num[k] = L[i];
            i++;
        }
        else {
            num[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        num[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        num[k] = R[j];
        j++;
        k++;
    }
}

void mergeNum(int num[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeNum(num, left, mid);
        mergeNum(num, mid + 1, right);
        mergeSortNum(num, left, mid, right);
    }
}
void mergeSortName(char name[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = name[left + i];
    for (j = 0; j < n2; j++)
        R[j] = name[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            name[k] = L[i];
            i++;
        }
        else {
            name[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        name[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        name[k] = R[j];
        j++;
        k++;
    }
}

void mergeName(char name[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeName(name, left, mid);
        mergeName(name, mid + 1, right);
        mergeSortName(name, left, mid, right);
    }
}


void bubbleNumber(int num[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                swapInt(&num[j], &num[j + 1]);
            }
        }
    }
}

void bubbleName(char name[], int n)
{

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if ((int)name[j] >= (int)name[j + 1])
            {
                swapChar(&name[j], &name[j + 1]);


            }
        }
    }
}

int main()
{
    int num[] = { 2,0,1,7,5,5,6,0,3,9 };
    char name[] = "oguzhan koyoglu";
    int sizeofName = strlen(name);

    clock_t timer;
    printf("2017556039 / oguzhan koyoglu\n");

    timer = clock();
    bubbleNumber(num, 10);
    timer = clock() - timer;


    printf("Bubble Sort\nint array:\t");
    printArray(num, 10);
    printf("time :\t %f \n", ((double)timer) / CLOCKS_PER_SEC);

    timer = clock();
    bubbleName(name, sizeofName);
    timer = clock() - timer;

    printf("char array:\t %s\n", name);
    printf("time:\t %f\n\n", ((double)timer) / CLOCKS_PER_SEC);
    resArray(num, name);


    timer = clock();
    insertionNumber(num, 10);
    timer = clock() - timer;


    printf("Insertion Sort \nint array:\t");
    printArray(num, 10);
    printf("time:%f\n", ((double)timer) / CLOCKS_PER_SEC);

    timer = clock();
    insertionName(name, sizeofName);
    timer = clock() - timer;

    printf("char array: %s\n", name);
    printf("time:%f\n\n", ((double)timer) / CLOCKS_PER_SEC);
    resArray(num, name);


    timer = clock();
    selectionNumber(num, 10);
    timer = clock() - timer;

    printf("Selection Sort \nint array:\t");
    printArray(num, 10);
    printf("time:%f\n", ((double)timer) / CLOCKS_PER_SEC);

    timer = clock();
    selectionName(name, sizeofName);
    timer = clock() - timer;

    printf("char array: %s\n", name);
    printf("time:%f\n\n", ((double)timer) / CLOCKS_PER_SEC);
    resArray(num, name);



    timer = clock();
    mergeNum(num, 0, 10 - 1);
    timer = clock() - timer;

    printf("Merge Sort\nint array:\t");
    printArray(num, 10);
    printf("time:\t %f\n", ((double)timer) / CLOCKS_PER_SEC);

    timer = clock();
    mergeName(name, 0, sizeofName - 1);
    timer = clock() - timer;

    printf("char array: %s\n", name);
    printf("time:\t %f", ((double)timer) / CLOCKS_PER_SEC);


    return 0;
}