#include <stdio.h>
#include <string.h>
#include <time.h>
//Insertion of Id
void insertionId(int id[],int x){
int i,key,j; 
    for (i=1;i<x;i++){ 
        key=id[i]; 
        j=i-1; 
  
        while (j>=0&&id[j]>key){ 
            id[j+1]=id[j]; 
            j=j-1; 
        } 
        id[j+1]=key; 
    } 
}
//Insertion of Name and Surname
void insertionNameSurname(char name[],int x){
    int i, j;
    char y;
    for (i=1;i<x;i++)
    {
        y=name[i];

        for(j=i-1;j>=0&&name[j]>y;j--)
        {
            name[j+1]=name[j];
        }
        name[j+1] =y;
    }
}
//Classic swapping Function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Swapping Function for Characters
void swapChar(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
//Function to print sorted array
void printArray(int arr[],int x){
	int i;
    for (i=0;i<x;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//Bubble sorter for Id
void bubbleId(int id[],int x){
    int flag=0,i=0,j;
    do
    {
        flag=0;
        for (j =0;j<x-i-1;j++)
        {
            if(id[j]>id[j+1])
            {
                swap(&id[j],&id[j+1]);
                flag=1;
            }
        }
        i++;
    } while(flag);
}
//Bubble sorter for Name and Surname
void bubbleNameSurname(char name[],int x){
    int flag=0,i=0,j;
    do
    {
        flag=0;
        for(j=0;j<x-i-1;j++)
        {
            if(name[j]>name[j+1])
            {
                swapChar(&name[j],&name[j+1]);
                flag=1;
            }
        }
        i++;
    } while (flag);
}
//Merge sorter for Id
void mergeIdSorter(int id[],int left,int middle,int right){
    int i,j,key;

    int leftSize=middle-left+1;
    int rightSize=right-middle;

    int leftx[leftSize],rightx[rightSize];

    for (i=0;i<leftSize;i++)
    {
        leftx[i] = id[left+i];
    }
    for (j=0;j<rightSize;j++)
    {
        rightx[j]=id[middle+1+j];
    }

    j=0,i=0,key=left;

    while(leftSize>i&&rightSize>j)
    {
        if (leftx[i]<=rightx[j])
        {
            id[key]=leftx[i];
            i++;
        }
        else
        {
            id[key]=rightx[j];
            j++;
        }
        key++;
    }

    while(leftSize>i)
    {
        id[key]=leftx[i];
        key++;
        i++;
    }
    while(rightSize>j)
    {
        id[key]=rightx[j];
        key++;
        j++;
    }
}
void mergeId(int id[],int left,int right){
    if(left<right)
    {
        int middle=left+(right-left)/2;

        mergeId(id,left,middle);
        mergeId(id,middle+1,right);

        mergeIdSorter(id,left,middle,right);
    }
}
//Merge sorter for Name and Surname
void mergeNameSurnameSorter(char id[],int left,int middle,int right){
    int i, j, key;

    int leftSize=middle-left+1;
    int rightSize =right-middle;

    int leftx[leftSize],rightx[rightSize];

    for(i=0;i<leftSize;i++)
    {
        leftx[i]=id[left+i];
    }
    for(j=0;j<rightSize;j++)
    {
        rightx[j]=id[middle+1+j];
    }

    j=0,i=0,key=left;

    while(leftSize>i&&rightSize>j)
    {
        if(leftx[i]<=rightx[j])
        {
            id[key]=leftx[i];
            i++;
        }
        else
        {
            id[key]=rightx[j];
            j++;
        }
        key++;
    }

    while(leftSize>i)
    {
        id[key]=leftx[i];
        key++;
        i++;
    }
    while(rightSize>j)
    {
        id[key]=rightx[j];
        key++;
        j++;
    }
}

void mergeNameSurname(char id[],int left,int right)
{
    if(left<right)
    {
        int middle=left+(right-left)/2;

        mergeNameSurname(id,left,middle);
        mergeNameSurname(id,middle+1,right);

        mergeNameSurnameSorter(id,left,middle,right);
    }
}
//Selection sorter for Id
void selectionId(int num[],int x){

    int i,j,temp,minIndex;

    for (i=0;i<x-1;i++)
    {
        minIndex=i;
        for (j=i+1;j<x;j++)
        {
            if (num[minIndex]>num[j])
            {
                minIndex=j;
            }
        }
        swap(&num[i], &num[minIndex]);
    }
}
//Selection sorter for Name and Surname
void selectionNameSurname(char name[],int x){

    int i,j,temp,minIndex;

    for(i=0;i<x-1;i++)
    {
        minIndex=i;
        for (j=i+1;j<x;j++)
        {
            if(name[minIndex]>name[j])
            {
                minIndex=j;
            }
        }
        swapChar(&name[i], &name[minIndex]);
    }
}
int main(int argc, char const *argv[])
{
    int id[] = {2,0,1,7,5,5,6,0,7,2};
    char nameSurname[] = "soner can zencirkiran";
    int sizeId = sizeof(id)/sizeof(id[0]);
    int sizeNameSurname=(sizeof(nameSurname)/sizeof(nameSurname[0]))-1;
    clock_t start,stop;
    double time;
//Timer for insertion(Id)
    start = clock();
    insertionId(id,sizeId);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Insertion sort for Id - ");
    insertionId(id,sizeId);
    printArray(id,sizeId);
    printf("passed time - %f\n",time);
//Timer for insertion(Name and Surname)
    start = clock();
    insertionNameSurname(nameSurname, sizeNameSurname);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Insertion sort for name and surname -");
    printf("%s\n", nameSurname);
    printf("passed time - %f\n",time);
    
    printf("-------------------------------------------------------------------------\n");
    
    int id2[]={2,0,1,7,5,5,6,0,7,2};
    char nameSurname2[]="soner can zencirkiran";
//Timer for Bubble(Id)
    start = clock();
    bubbleId(id2,sizeId);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Bubble sort for Id - ");
    printArray(id2,sizeId);
    printf("passed time - %f\n",time);
//Timer for Bubble(Name and Surname)
    start = clock();
    bubbleNameSurname(nameSurname2, sizeNameSurname);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Bubble sort for name and surname -");
    printf("%s\n", nameSurname2);
    printf("passed time - %f\n",time);

    printf("-------------------------------------------------------------------------\n");

    int id3[]={2,0,1,7,5,5,6,0,7,2};
    char nameSurname3[]="soner can zencirkiran";
//Timer for Merge(Id)
    start = clock();
    mergeId(id3,0,sizeId-1);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Merge sort for Id - ");
    printArray(id3,sizeId);
    printf("passed time - %f\n",time);
//Timer for Merge(Name and Surname)
    start = clock();
    mergeNameSurname(nameSurname3,0,sizeNameSurname-1);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Merge sort for name and surname -");
    printf("%s\n",nameSurname3);
    printf("passed time = %f\n",time);
    
    printf("-------------------------------------------------------------------------\n");
    
    int id4[]={2,0,1,7,5,5,6,0,7,2};
    char nameSurname4[] = "soner can zencirkiran";
//Timer for Selection(Id)
    start = clock();
    selectionId(id4, sizeId);
    stop = clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Selection sort for Id - ");
    printArray(id4, sizeId);
    printf("passed time - %f\n",time);
//Timer for Selection(Name and Surname)
    start=clock();
    selectionNameSurname(nameSurname4, sizeNameSurname);
    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("Selection sort for name and surname -");
    printf("%s\n", nameSurname4);
    printf("passed time - %f\n",time);
  
    return 0;
}
