#include <stdio.h>
#include <string.h>
#include <time.h>
#include<stdlib.h>

void printArray(int array[], int size) {
	
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}

void swapNum(int * num1, int * num2)
 {
    int temp = * num1;
    * num1 = * num2;
    * num2 = temp;
}

void swapChar(char * num1, char * num2
) {
    char temp = * num1;
    
    * num1 = * num2;
    
    * num2 = temp;
}

// Insertion Sort
void insertionSortNum(int num[], int size) {

    int i, j;
    int x;
    for (i = 1; i < size; i++) {
        x = num[i];

        for (j = i - 1; j >= 0 && num[j] > x; j--) {
            num[j + 1] = num[j];
        }
        num[j + 1] = x;
    }
}



void insertionSortName(char name[], int size) {
    int i, j;
    char x;
    for (i = 1; i < size; i++) {
        x = name[i];

        for (j = i - 1; j >= 0 && name[j] > x; j--) {
            name[j + 1] = name[j];
        }
        name[j + 1] = x;
    }
}



//Selection Sort

void selectionSortNum(int num[], int size) {

    int i, j, min, temp;

    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (num[min] > num[j]) {
                min = j;
            }
        }
        swapNum( & num[i], & num[min]);
    }
}




void selectionSortName(char name[], int size) {

    int i, j, min, temp;

    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (name[min] > name[j]) {
                min = j;
            }
        }
        swapChar( & name[i], & name[min]);
    }
}




// Merge Sort 

void mergeNum(int num[], int l, int m, int r) {
    int i, j, k;

    int leftnum = m - l + 1;
    int rightnum = r - m;
    
int*left = (int *)malloc(leftnum * sizeof(int));
	int*right = (int *)malloc(rightnum * sizeof(int));
	
    

    for (i = 0; i < leftnum; i++) {
        left[i] = num[l + i];
    }
    for (j = 0; j < rightnum; j++) {
        right[j] = num[m + 1 + j];
    }

    j = 0, i = 0, k = l;

    while (leftnum > i && rightnum > j) {
        if (left[i] <= right[j]) {
            num[k] = left[i];
            i++;
        } else {
            num[k] = right[j];
            j++;
        }
        k++;
    }

    while (leftnum > i) {
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightnum > j) {
        num[k] = right[j];
        k++;
        j++;
    }
}

void mergeSortNum(int num[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortNum(num, l, m);
        mergeSortNum(num, m + 1, r);
        mergeNum(num, l, m, r);
    }
}



void mergeName(char num[], int l, int m, int r) {
    int i, j, k;

    int leftchar = m - l + 1;
    int rightchar = r - m;

   int*left = (int *)malloc(leftchar * sizeof(int));
	int*right = (int *)malloc(rightchar * sizeof(int));


    for (i = 0; i < leftchar; i++) {
        left[i] = num[l + i];
    }
    for (j = 0; j < rightchar; j++) {
        right[j] = num[m + 1 + j];
    }

    j = 0, i = 0, k = l;

    while (leftchar > i && rightchar > j) {
        if (left[i] <= right[j]) {
            num[k] = left[i];
            i++;
        } else {
            num[k] = right[j];
            j++;
        }
        k++;
    }

    while (leftchar > i) {
        num[k] = left[i];
        k++;
        i++;
    }
    while (rightchar > j) {
        num[k] = right[j];
        k++;
        j++;
    }
}

void mergeSortName(char num[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortName(num, l, m);
        mergeSortName(num, m + 1, r);

        mergeName(num, l, m, r);
    }
}




//Bubble Sort


void bubbleSortNum(int num[], int size) {
    int swapped = 0, i = 0, j;
    do {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                swapNum( & num[j], & num[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}



void bubbleSortName(char name[], int size) {
    int swapped = 0, i = 0, j;
    do {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (name[j] > name[j + 1]) {
                swapChar( & name[j], & name[j + 1]);
                swapped = 1;
            }
        }
        i++;
    } while (swapped);
}





int main(int argc, char
    const * argv[]) {
    int num[] = {
   2, 0, 1, 8, 5, 5, 6, 4, 5, 3,
    };
    char name[] = "EFE INCEFIKIR";
    int sizeofNumber = sizeof(num) / sizeof(num[0]);
    int sizeName = (sizeof(name) / sizeof(name[0])) - 1;
    clock_t start, end;
    double total;

    start = clock();
    insertionSortNum(num, sizeofNumber);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion Sort - Number Array : \n");
    printArray(num, sizeofNumber);
    printf("Time = %f\n", total);
    start = clock();
    insertionSortName(name, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nInsertion sort - Name Array : \n");
    printf("%s\n", name);
    printf("Time = %f\n", total);
    

    int num2[] = {
      2, 0, 1, 8, 5, 5, 6, 4, 5, 3,
    };
    char name2[] = "EFE INCEFIKIR";

    
    start = clock();
    selectionSortNum(num2, sizeofNumber);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSelection Sort - Number Array : \n");
    printArray(num2, sizeofNumber);
    printf("Time = %f\n", total);
    

    
    start = clock();
    selectionSortName(name2, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSelection Sort - Name Array : \n");
    printf("%s\n", name2);
    printf("Time = %f\n\n", total);
    

    int num3[] = {
        2, 0, 1, 8, 5, 5, 6, 4, 5, 3,
    };
    char name3[] = "EFE INCEFIKIR";

    
    start = clock();
    bubbleSortNum(num3, sizeofNumber);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nBubble Sort - Number Array : \n");
    printArray(num3, sizeofNumber);
    printf("Time = %f\n", total);
    

    
    start = clock();
    bubbleSortName(name3, sizeName);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nBubble Sort - Name Array : \n");
    printf("%s\n", name3);
    printf("Time = %f\n\n", total);
    

    int number4[] = {
        2, 0, 1, 8, 5, 5, 6, 4, 5, 3,
    };
    char name4[] = "EFE INCEFIKIR";

    
    start = clock();
    mergeSortNum(number4, 0, sizeofNumber - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMerge sort - Number Array : \n");
    printArray(number4, sizeofNumber);
    printf("Time = %f\n", total);
    

    
    start = clock();
    mergeSortName(name4, 0, sizeName - 1);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMerge Sort - Name array : \n");
    printf("%s\n", name4);
    printf("Time = %f\n\n", total);
    

    return 0;
}
