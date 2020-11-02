#include <stdio.h>
#include <time.h>
void insertionSort(int arr[],int size);
void insertionSortCh(char arr[],int size);
void printArray(int arr[],int size);
void printArrayCh(char arr[],int size);
void selectionSort(int arr[],int size);
void selectionSortCh(char arr[],int size);
void bubbleSort(int arr[],int size);
void bubbleSortCh(char arr[],int size);
void merge(int arr[], int Left, int Middle, int Right);
void mergeSort(int arr[], int Left, int Right);
void mergeSortCh(char arr[], int Left, int Right);
void mergeCh(char arr[], int Left, int Middle, int Right);
int main()
{
    int num[]={2,0,2,0,5,5,5,4,5,3},size,sizename,i;
    char fullname[]="UMUTTOKGOZ";
    sizename=sizeof(fullname)-1;
    size=sizeof(num)/sizeof(num[0]);
    printf("Unsorted numbers: ");
    for(i=0;i<size;i++)
        printf("%d ",num[i]);
    printf("\n");
    printf("Unsorted name: ");
    printf("%s\n",fullname);
    clock_t t;
	t = clock();
	insertionSort(num,size);
    printArray(num,size);
	t = clock() - t;
	double dTime = ((double)t)/CLOCKS_PER_SEC;
    printf("insertion sort implemented on the student id took %f seconds to execute \n", dTime);

	int num2[]={2,0,2,0,5,5,5,4,5,3}; // To save time, I've created new array with the save elements.
	size=sizeof(num2)/sizeof(num2[0]);

    t = clock();
    insertionSortCh(fullname,size);
    printArrayCh(fullname,size);
    t = clock() - t;
    dTime = ((double)t)/CLOCKS_PER_SEC;
    printf("insertion sort implemented on the student name took %f seconds to execute \n", dTime);

    char fullname2[]="UMUTTOKGOZ";
    sizename=sizeof(fullname2)-1;

    t = clock();
    selectionSort(num2,size);
    printArray(num2,size);
    t = clock() - t;
	dTime = ((double)t)/CLOCKS_PER_SEC;
	printf("Selection sort implemented on the student id took %f seconds to execute \n", dTime);

	int num3[]={2,0,2,0,5,5,5,4,5,3};
	size=sizeof(num3)/sizeof(num3[0]);

	t = clock();
    selectionSortCh(fullname2,sizename);
    printArrayCh(fullname2,sizename);
    t = clock() - t;
	dTime = ((double)t)/CLOCKS_PER_SEC;
	printf("Selection sort implemented on the student name took %f seconds to execute \n", dTime);

	char fullname3[]="UMUTTOKGOZ";
    sizename=sizeof(fullname3)-1;

    t = clock();
    bubbleSort(num3,size);
    printArray(num3,size);
    t = clock() - t;
	dTime = ((double)t)/CLOCKS_PER_SEC;
	printf("Bubble sort implemented on the student id took %f seconds to execute \n", dTime);

	int num4[]={2,0,2,0,5,5,5,4,5,3};
	size=sizeof(num4)/sizeof(num4[0]);

	t = clock();
    bubbleSortCh(fullname3,sizename);
    printArrayCh(fullname3,sizename);
    t = clock() - t;
	dTime = ((double)t)/CLOCKS_PER_SEC;
	printf("Bubble sort implemented on the student name took %f seconds to execute \n", dTime);

	char fullname4[]="UMUTTOKGOZ";
    sizename=sizeof(fullname4)-1;

    t = clock();
    mergeSort(num4,0,size-1);
    printArray(num4,size);
    t = clock() - t;
	dTime = ((double)t)/CLOCKS_PER_SEC;
	printf("Merge sort implemented on the student id took %f seconds to execute \n", dTime);

	t = clock();
    mergeSortCh(fullname4,0,sizename-1);
    printArrayCh(fullname4,sizename);
    t = clock() - t;
	dTime = ((double)t)/CLOCKS_PER_SEC;
	printf("Merge sort implemented on the student name took %f seconds to execute \n", dTime);

    return 0;
}
void insertionSort(int arr[],int size)
{
    int i,backupnum,j;
    for(i=1;i<size;i++)
    {
        backupnum=arr[i];
        j=i-1;
        while(j>-1&&arr[j]>backupnum)
        {
            arr[j+1]=arr[j];
            j--;
        }
        j++;
        arr[j]=backupnum;
    }

}
void printArray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void insertionSortCh(char arr[],int size)
{
    int i,j;
    char backup;
    for(i=1;i<size;i++)
    {
        backup=arr[i];
        j=i-1;
        while(j>-1&&arr[j]>backup)
        {
            arr[j+1]=arr[j];
            j--;
        }
        j++;
        arr[j]=backup;
    }
}
void printArrayCh(char arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%c ",arr[i]);
    printf("\n");
}
void selectionSort(int arr[],int size)
{
    int min,i,j,bup,k,idx;

    for(i=0;i<size-1;i++)
    {
        min=arr[i];
        for(j=i+1;j<size;j++)
            if(arr[j]<min)
            {
                min=arr[j];
                idx=j;
            }

        bup=arr[i];
        arr[i]=min;
        arr[idx]=bup;
    }
}
void selectionSortCh(char arr[],int size)
{
    int i,j,k,idx;
    char min,bup;
    for(i=0;i<size-1;i++)
    {
        min=arr[i];
        for(j=i+1;j<size;j++)
            if(arr[j]<min)
            {
                min=arr[j];
                idx=j;
            }

        bup=arr[i];
        arr[i]=min;
        arr[idx]=bup;
    }
}
void bubbleSort(int arr[],int size)
{
    int swap,i,bup;
    do
    {
        swap=0;
        for(i=0;i<size-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                bup=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=bup;
                swap=1;
            }
        }
    }while(swap);
}
void bubbleSortCh(char arr[],int size)
{
    int swap,i;
    char bup;
    do
    {
        swap=0;
        for(i=0;i<size-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                bup=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=bup;
                swap=1;
            }
        }
    }while(swap);
}
void merge(int arr[], int Left, int Middle, int Right)
{
    int i, j, k;
    int n1 = Middle - Left + 1;
    int n2 = Right - Middle;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[Left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[Middle + 1 + j];


    i = 0;
    j = 0;
    k = Left;
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

void mergeSort(int arr[], int Left, int Right)
{
    if (Left < Right) {

        int Middle = Left + (Right - Left) / 2;
        mergeSort(arr, Left, Middle);
        mergeSort(arr, Middle + 1, Right);
        merge(arr, Left, Middle, Right);
    }
}

void mergeSortCh(char arr[], int Left, int Right)
{
    if (Left < Right) {

        int Middle = Left + (Right - Left) / 2;
        mergeSortCh(arr, Left, Middle);
        mergeSortCh(arr, Middle + 1, Right);
        mergeCh(arr, Left, Middle, Right);
    }
}



void mergeCh(char arr[], int Left, int Middle, int Right)
{

    int i, j, k;
    int n1 = Middle - Left + 1;
    int n2 = Right - Middle;
    char L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[Left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[Middle + 1 + j];
    i = 0;
    j = 0;
    k = Left;
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

