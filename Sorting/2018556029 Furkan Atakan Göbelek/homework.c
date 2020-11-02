#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>
void insertionSort(int arr[], int n) 
{ 
    int i, x, j; 
    for (i = 1; i < n; i++) { 
        x = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > x) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = x; 
    } 
} 
void insertionSortCh(char arr[], int n) 
{
    int i, j;
    char x;
    for(i = 1; i < n; i++) {
        x = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void swapCh(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void selectionSort(int arr[], int n) 
{ 
    int i, j, min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 

void selectionSortCh(char arr[], int n) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapCh(&arr[min], &arr[i]); 
    } 
}
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void bubbleSortCh(char arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapCh(&arr[j], &arr[j+1]); 
}
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k, x1, x2; 
    x1 = m - l + 1; 
    x2 = r - m; 

    int L[x1], R[x2]; 

    for (i = 0; i < x1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < x2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0; 
    j = 0; 
    k = l; 

    while (i < x1 && j < x2) { 
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

    while (i < x1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < x2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 

        merge(arr, l, m, r); 
    } 
} 

void mergeCh(char arr[], int l, int m, int r) 
{ 
    int i, j, k, x1, x2; 
    x1 = m - l + 1; 
    x2 = r - m; 

    int L[x1], R[x2]; 

    for (i = 0; i < x1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < x2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0; 
    j = 0; 
    k = l; 

    while (i < x1 && j < x2) { 
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

    while (i < x1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < x2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSortCh(char arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 

        mergeSortCh(arr, l, m); 
        mergeSortCh(arr, m + 1, r); 

        mergeCh(arr, l, m, r); 
    } 
}

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); } 


int main(){
	printf("Student number = 2018556029\n");
	printf("Name = Furkan Atakan Gobelek\n");
	clock_t a;
	int student_number[]= {2,0,1,8,5,5,6,0,2,9};
	char name[]= {"FURKAN ATAKAN GOBELEK"};
	int s = sizeof(student_number) / sizeof(student_number[0]);
	int charSize = strlen(name);
	int student_number2[]= {2,0,1,8,5,5,6,0,2,9}; /* for selectionsort */
	char name2[]= {"FURKAN ATAKAN GOBELEK"}; /* for selectionsort */
	int x = sizeof(student_number2) / sizeof(student_number2[0]); /* for selectionsort */
	int charSize2 = strlen(name2); /* for selectionsort */
	int student_number3[]= {2,0,1,8,5,5,6,0,2,9}; /*for bubbleSort*/
	char name3[]= {"FURKAN ATAKAN GOBELEK"}; /*for bubbleSort*/
	int c = sizeof(student_number3) / sizeof(student_number3[0]); /*for bubbleSort*/
	int charSize3 = strlen(name3); /*for bubbleSort*/
	int student_number4[]= {2,0,1,8,5,5,6,0,2,9}; /*for mergeSort*/
	char name4[]= {"FURKAN ATAKAN GOBELEK"}; /*for mergeSort*/
	int b = sizeof(student_number4) / sizeof(student_number4[0]); /*for mergeSort*/
	int charSize4 = strlen(name4); /*for mergeSort*/
	 
	a = clock();
    insertionSort((student_number), s);
    a = clock() - a;
    printArray(student_number, s); 
    printf("insertion sort time: %lf\n", ((double)a) / CLOCKS_PER_SEC);
    insertionSortCh(name, charSize);
    a = clock() - a;
    printf("%s\n", name);
    printf("insertion char sort time: %lf\n", ((double)a) / CLOCKS_PER_SEC);
    
    
    a = clock();
    selectionSort(student_number2, x);
    a = clock() - a;
    printArray(student_number2, x); 
    printf("selection sort time: %lf\n", ((double)a) / CLOCKS_PER_SEC);

    selectionSortCh(name2, charSize2);
    a = clock() - a;
    printf("%s\n", name2);
    printf("selection char sort time: %lf\n", ((double)a) / CLOCKS_PER_SEC);
    
    
    bubbleSort(student_number3, c);
    a = clock() - a;
    printArray(student_number3, c); 
    printf("bubble sort time: %lf\n", ((double)a) / CLOCKS_PER_SEC);

    bubbleSortCh(name3, charSize3);
    a = clock() - a;
    printf("%s\n", name3);
    printf("bubble char sort time: %lf\n", ((double)a) / CLOCKS_PER_SEC);
    
    
    mergeSort(student_number3, 0, b - 1);
    a = clock() - a;
    printArray(student_number, b); 
    printf("merge sort time: %lf\n", ((double)a) / CLOCKS_PER_SEC);
    mergeSortCh(name4, 0, charSize4 - 1);
    a = clock() - a;
    printf("%s\n", name4);
    printf("merge char sort time: %lf\n", ((double)a) / CLOCKS_PER_SEC);
    
    

    return 0;

	

}
