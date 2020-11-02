#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swapnumber(int *x, int *y)
{
    int temp= *x;
    *x= *y;
    *y= temp;
}

void swapname(char *x, char *y)
{
   char temp= *x;
    *x= *y;
    *y= temp;
}
//merge sort number
void merge1(int *arr, int b, int o,int s)
{
    int bsize=o-b+1;
    int ssize=s-o;
    int left[bsize];
    int right[ssize];
    int i,j;
    
    for( i=0; i<bsize; ++i)
    {
        left[i]=arr[b+i];
    }
    for(j=0; j<ssize; ++j)
    {
        right[j]=arr[o+1+j];
    }
    i=0; j=0; 
    int org=b;
    
    while(i<bsize && j<ssize)
    {
        if(left[i]<=right[j])
        {
            arr[org]=left[i];
            i++;
        }
    else
    {
        arr[org]=right[j];
        j++;
    }
        org++;
        
    }
    while(i<bsize)
    {
        arr[org]=left[i];
        org++;
        i++;
    }
    while(j<ssize)
    {
        arr[org]=right[j];
        org++;
        j++;
    }
}

void mergesortnumber(int *arr, int b, int s)
{
    if (b<s)
    {
        int o=(b+s)/2;
        mergesortnumber(arr,b,o);
        mergesortnumber(arr,o+1,s);
        merge1(arr,b, o,s);
    }
}

//merge sort name
void merge2(char *arr, int b, int o,int s)
{
   // printf("%s");
    int bsize=o-b+1;
    int ssize=s-o;
    int left[bsize];
    int right[ssize];
    int i,j;
    
    for(i=0; i<bsize; ++i)
    {
        left[i]=arr[b+i];
    }
    for(j=0; j<ssize; ++j)
    {
        right[j]=arr[o+1+j];
    }
    i=0; j=0; 
    int org=b;
    
    while(i<bsize && j<ssize)
    {
        if(left[i]<=right[j])
        {
            arr[org]=left[i];
            i++;
        }
    else
    {
        arr[org]=right[j];
        j++;
    }
        org++;
        
    }
    while(i<bsize)
    {
        arr[org]=left[i];
        org++;
        i++;
    }
    while(j<ssize)
    {
        arr[org]=right[j];
        org++;
        j++;
    }
}

void mergesortname(char *arr, int b, int s)
{
    if(b<s)
    {
        int o=(b+s)/2;
        mergesortname(arr,b,o);
        mergesortname(arr,o+1,s);
        merge2(arr,b,o,s);
    }
}

//insertion sort number
void insertionsortnumber(int *arr, int a )
{
    int i,j,k;
    for(k=0; k<a; ++k)
    {
        i=arr[k];
        for(j=k-1; arr[j]>i && j>=0; --j)
        {
            arr[j+1]=arr[j];
            
        }
        arr[j+1]=i;
    }
}

//insertion sort name
void insertionsortname(char *arr, int a )
{
    int i,j,k;
    for(k=0; k<a;++k)
    {
        i=arr[k];
        for(j=k-1; arr[j]>i && j>=0; --j)
        {
            arr[j+1]=arr[j];
            
        }
        arr[j+1]=i;
    }
}

//selection sort number
void selectionsortnumber(int *array, int a){
    int min;
    for(int i=0; i<a-1;++i)
    {
        min=i;
        for(int j=i+1; j<a; ++j)
        {
            if(array[j]<array[min])
            min=j;
            
        }
        swapnumber(&array[min],&array[i]);
    }
}

//selection sort name
void selectionsortname(char *array, int a){
    
    for(int i=0; i<a-1;++i)
    {
        char min=i;
        for(int j=i+1; j<a; ++j)
        {
            if(array[j]<array[min])
            min=j;
            
        }
        swapname(&array[min],&array[i]);
    }
}

//bubble sort number
void bubblesortnumber(int *array, int a)
{
   for(int i=0; i<a-1; ++i)
   {
       for (int j=0; j<a-i-1; ++j)
       {
           if(array[j]>array[j+1])
           swapnumber(&array[j],&array[j+1]);
           
       }
   }
   
}

///buble sort name
void bubblesortname(char *array, int a)
{
   for(int i=0; i<a-1; ++i)
   {
       for (int j=0; j<a-i-1; ++j)
       {
           if(array[j]>array[j+1])
           swapname(&array[j],&array[j+1]);
           
       }
   }
   
}

//// heap sort number

void heap1(int *arr, int size1,int i)
{
    int h=i;
    int b=(2*i)+1;
    int s=(2*i)+2;
    
    if(arr[b]>arr[h] && b<size1)
    h=b;
    
    if(arr[s]>arr[h] && s<size1)
    h=s;
    
    if(h!=i)
    {
        swapnumber(&arr[i],&arr[h]);
        heap1(arr,size1,h);
    }
}

void heapsortnumber(int *arr,int size1)
{
    for(int i=(size1/2)-1; i>=0; i--)
    {
        heap1(arr,size1,i);
    }
    for(int i=size1-1; i>0; i--)
    {
        swapnumber(&arr[0],&arr[i]);
        heap1(arr,i,0);
    }
    
}

////////heap sort name
void heap2(char *arr, int size2,int i)
{
    int h=i;
    int b=(2*i)+1;
    int s=(2*i)+2;
    
    if(arr[b]>arr[h] && b<size2)
    h=b;
    
    if(arr[s]>arr[h] && s<size2)
    h=s;
    
    if(h!=i)
    {
        swapname(&arr[i],&arr[h]);
        heap2(arr,size2,h);
    }
}

void heapsortname(char *arr,int size2)
{
    for(int i=(size2/2)-1; i>=0; i--)
    {
        heap2(arr,size2,i);
    }
    for(int i=size2-1; i>0; i--)
    {
        swapname(&arr[0],&arr[i]);
        heap2(arr,i,0);
    }
    
}

/////quick sort number
void quickSortnumber(int *arr, int b, int s)
{
    int ed=b;
    int ey=s-1;
    int d=s;
    
    if(ed<ey)
    {
        while(1)
        {
            if(arr[ed]<arr[d])
            ed++;
            
            else if(arr[ey]>arr[d])
            ey--;
            
            else if(ed<ey)
                swapnumber(&arr[ed],&arr[ey]);
            else
                break;
        }
        swapnumber(&arr[ed],&arr[d]);
        quickSortnumber(arr,b,ed-1);
        quickSortnumber(arr,ed+1,s);
        
    }
}

///////quick sort name
void quickSortname(char *arr, int b, int s)
{
    int ed=b;
    int ey=s-1;
    int d=s;
    
    if(ed<ey)
    {
        while(1)
        {
            if(arr[ed]<arr[d])
            ed++;
            
            else if(arr[ey]>arr[d])
            ey--;
            
            else if(ed<ey)
                swapname(&arr[ed],&arr[ey]);
            else
                break;
        }
        swapname(&arr[ed],&arr[d]);
        quickSortname(arr,b,ed-1);
        quickSortname(arr,ed+1,s);
        
    }
}

///print
void printarraynumber(int *arr, int b)
{
    
    for (int i=0; i<b; ++i){
    printf("%d  ",arr[i]);
    }
    printf("\n");
    
}

void printarrayname(char *arr, int b)
{   
    for (int i=1; i<b; ++i){
    printf("%c  ",arr[i]);
    }
    printf("\n");
    
}


int main()
{   
    clock_t start, finish;
    double tot;
    
    int array1[] = {2,0,1,9,5,5,6,4,0,2};
    int size1=sizeof(array1)/sizeof(array1[0]);
    char array2[]="rozerinzaman";
    int size2=sizeof(array2)/sizeof(array2[0]);
        
    ////mergesort için
    printf("Merge sort(number)\n");
    start = clock();
    mergesortnumber(array1,0,size1-1);
    finish = clock();
    printarraynumber(array1,size1);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of MERGE sort = %f\n\n", tot);

    ///////merge name
    
    printf("Merge sort(name)\n");
    start = clock();
    mergesortname(array2,0,size2-1);
    finish = clock();
    printarrayname(array2,size2);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of MERGE sort = %f\n", tot);
    printf("---------------------------\n" );

     //bubble number 
    printf("Buble sort(number)\n");
    start = clock();
    bubblesortnumber(array1,size1);
    finish = clock();
    printarraynumber(array1,size1);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of BUBBLE sort = %f\n\n", tot);
      
   //bubble name 
    printf("Bubble sort (name)\n");
    start=clock();
    bubblesortname(array2, size2);
    finish = clock();
    printarrayname(array2, size2);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of BUBBLE sort = %f\n", tot);    
    printf("---------------------------\n" );
   
        
   ///selection number 

  
    printf("Selection sort(number)\n");
    start = clock();
    selectionsortnumber(array1,size1);
    finish = clock();
    printarraynumber(array1,size1);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of SELECTION sort = %f\n\n", tot);    
       
    //selection name   
    printf("Selection sort(name)\n");
    start=clock();
    selectionsortname(array2, size2);
    finish = clock();
    printarrayname(array2, size2);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of SELECTION sort = %f\n", tot);  
    printf("---------------------------\n" );

    //insertion number 
    printf("Insertion sort(number)\n");
    start = clock();
    insertionsortnumber(array1,size1);
    finish = clock();
    printarraynumber(array1,size1);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of INSERTION sort = %f\n\n", tot);
    
    ///insertion name 
    printf("Insertion sort(name)\n");
    start = clock();
    insertionsortname(array2,size2);
    finish = clock();
    printarrayname(array2,size2);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of INSERTION sort= %f\n", tot);
    printf("---------------------------\n" );

    //heap sort number
    printf("Heap sorte(number)\n");
    start = clock();
    heapsortnumber(array1,size1);
    finish = clock();
    printarraynumber(array1,size1);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of HEAP sort = %f\n\n", tot);
    
    //////////heap sort name
    printf("Heap sorte(name)\n");
    start = clock();
    heapsortname(array2,size2);
    finish = clock();
    printarrayname(array2,size2);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of HEAP sort = %f\n", tot);
    printf("---------------------------\n" );

    ////quickk sort number için
    
    printf("Quick sort(number)\n");
    start = clock();
    quickSortnumber(array1,0,size1-1);
    finish = clock();
    printarraynumber(array1,size1);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of QUICK sort = %f\n\n", tot);
    
    //////////quick sort name için
    printf("Quick sort(name) \n");
    start = clock();
    quickSortname(array2,0,size2-1);
    finish = clock();
    printarrayname(array2,size2);
    tot = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time of QUICK sort = %f\n", tot); 
    
    
    return 0;
}