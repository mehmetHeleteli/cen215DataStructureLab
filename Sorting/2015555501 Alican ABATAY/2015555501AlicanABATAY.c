#include<stdio.h> 
#include<time.h>
#include<unistd.h>


	void swapInt (int *x , int *y) ;
	void swapChar(char *x , char *y);
	void convertLowerCase(char str[]);
	void bubbleSortStr(char str[] , int size) ;
	void bubbleSortInt(int arr[] , int size) ;
	void printArray(int arr[] ,int size) ;
	void insertionSortStr(char arr[] , int size);
	void insertionSortInt(int arr[] , int size);
	void selectionSortInt (int arr[] , int size);
	void selectionSortStr (char str[] , int size);
	void mergeInt(int array[] , int left ,int middle , int right ) ;
	void mergeSortInt(int array[] , int left , int right );
	void mergeSortChar(char arr[], char left, char right);
	void mergeChar(char array[] , int left ,int middle , int right ) ;
	
int main() {
	
    

	
	printf("\n******************************  TIME ANALYSIS OF SORTING ALGORITHMS   ***********************************\n\n");
	
	
	char name[] = "Alican ABATAY";
	int number[] = {2,0,1,5,5,5,5,5,0,1};

	int sizeStr = sizeof(name) / sizeof(char) -1;
	int sizeNum = sizeof(number) / sizeof(int);

	
	int i;
	
	clock_t start , end;
	 double  time_used;
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////BUBBLE

 printf("-------------------------------------------------------------------------------------------\n");
	
	char name1[] = "Alican ABATAY";
	int number1[] = {2,0,1,5,5,5,5,5,0,1};
printf("BUBBLE SORT \n");
	printf("\n      Original number :")	;
	printArray(number1,sizeNum) ;
	start = clock();
	bubbleSortInt(number1,sizeNum);

	end = clock();
	time_used = (( double) (end - start)) / CLOCKS_PER_SEC;

	printf("\n      Sorted number   :")	;
	printArray(number1,sizeNum) ;
	printf("\n        Time          : %.10lf \n\n\n",time_used);
	
	printf("      Original Name   : %s",name1);
 	convertLowerCase(name1);
	start = clock();
	bubbleSortStr(name1,sizeStr);
	end = clock();
	time_used = (( double) (end - start)) / CLOCKS_PER_SEC;

	printf("\n      Sorted name     :")	;
	printf("%s",name1);
	printf("\n        Time          : %.10lf",time_used);

 
 printf("\n-------------------------------------------------------------------------------------------\n");
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////SELECTION
	
	char name2[] = "Alican ABATAY";
	int number2[] = {2,0,1,5,5,5,5,5,0,1};
printf("INSERTION SORT \n");
	printf("\n      Original number :")	;
	printArray(number2,sizeNum) ;
	
	
	
	start = clock();
	insertionSortInt(number2,sizeNum);
	end = clock();
	time_used = (( double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n      Sorted number   :")	;
	printArray(number2,sizeNum) ;
	printf("\n        Time          : %.10lf \n\n\n",time_used);
	
	
	
	
	
	
	
	
	printf("      Original Name   : %s",name2);
 	convertLowerCase(name2);
	start = clock();
	insertionSortStr(name2,sizeStr);
	end = clock();
	time_used = (( double) (end - start)) / CLOCKS_PER_SEC;
	
	
	
	printf("\n      Sorted name     :")	;
	printf("%s",name2);
	printf("\n        Time          : %.10lf",time_used);
 printf("\n-------------------------------------------------------------------------------------------\n");



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////INSERTION
	
	char name3[] = "Alican ABATAY";
	int number3[] = {2,0,1,5,5,5,5,5,0,1};
printf("SELECTION SORT \n");
	printf("\n      Original number :")	;
	printArray(number3,sizeNum) ;
	
	
	start = clock();
	selectionSortInt(number3,sizeNum);
	end = clock();
	time_used = (( double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n      Sorted number   :")	;
	printArray(number3,sizeNum) ;
	printf("\n        Time          : %.10lf \n\n\n",time_used);
	
	
	
	
	
	printf("      Original Name   : %s",name3);
 	convertLowerCase(name3);
	start = clock();
	selectionSortStr(name3,sizeStr);
	end = clock();
	time_used = (( double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n      Sorted name     :")	;
	printf("%s",name3);
	printf("\n        Time          : %.10lf",time_used);

 
 printf("\n-------------------------------------------------------------------------------------------\n");



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////MERGE
	
	char name4[] = "Alican ABATAY";
	int number4[] = {2,0,1,5,5,5,5,5,0,1};
printf("MERGE SORT \n");

	printf("\n      Original number :")	;
	printArray(number4,sizeNum) ;
	
	
	start = clock();
	mergeSortInt(number4,0,sizeNum);
	end = clock();
	
	
	time_used = (( double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n      Sorted number   :")	;
	printArray(number4,sizeNum) ;
	printf("\n        Time          : %.10lf \n\n\n",time_used);




	printf("      Original Name   : %s",name4);
 	convertLowerCase(name4);
	start = clock();
	mergeSortChar(name4,0,sizeStr-1);
	end = clock();
	time_used = (( double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n      Sorted name     :")	;
	printf("%s",name4);
	printf("\n        Time          : %.10lf",time_used);

 
 printf("\n-------------------------------------------------------------------------------------------\n");


























}



//END OF MAIN FUNCTION










///////////////////////////////////////////////////////////////////////////////////////  HELPER FUNCTIONS 

void swapChar(char *x , char *y)     		
{
 	char temp = *x;
 	*x=*y;
 	*y=temp;
 	
}




void swapInt (int *x , int *y) { 				
	int temp = *x;
 	*x=*y;
 	*y=temp;
}




void convertLowerCase(char str[]) {				// This function converts all character to lower case 
	int i;
	   for(i=0;str[i]!='\0';i++){
	      if(str[i]>=65&&str[i]<=90)
	         str[i]=str[i]+32;
	         
  			 }
  			 
  			 
}


void printArray(int arr[] ,int size) {			//prints integer array
	

	int i;
	for(i=0;i<size;i++) {
		printf("%d ",arr[i]);
		
	}
	
}




////////////////////////////////////////////////////////////////////////////////////////// bubble SORT

void bubbleSortInt(int arr[] , int size)  {		 
	int i , j;
	for(i=0;i<size;i++) {
		
		for(j=0;j<size-1;j++){
			
			if(arr[j]>arr[j+1])
				swapInt(&arr[j],&arr[j+1]);
				
		}
		
	}
}





void bubbleSortStr(char str[] , int size) {		
	int i , j ;
	
	for(i=0 ; i<size ; i++) {
			
		for(j=0;j<size-1;j++){
			
			if(str[j]>str[j+1])
				swapChar(&str[j],&str[j+1]);
				
		}
		
		
	}
	
}




////////////////////////////////////////////////////////////////////////////////////////// INSERTION SORT



void insertionSortInt(int arr[] , int size) {		
	
	int i , j , key;
	for(i=1;i<size;i++) {
		key=arr[i];
		
		for(j=i-1;j>=0&&arr[j] > key;j--) {
			arr[j+1] = arr[j];
			
		}
		arr[j+1] = key;
		
	}
	
	
	
	
	
	
}

void insertionSortStr(char arr[] , int size) {		
	
	int i , j , key;
	for(i=1;i<size;i++) {
		key = arr[i];
		for(j=i-1;j>=0 && arr[j] > key ; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1 ] = key;
	}
}




//////////////////////////////////////////////////////////////////////////////////////////SELECTION SORT



void selectionSortInt (int arr[] , int size) {
	int i , j  , min ;

	for(i=0;i<size;i++) {
		min = i;
		for(j=i+1;j<size;j++) {
			if(arr[j] < arr[min] ) 
				min=j;	
		}
		swapInt(&arr[i],&arr[min]);
	}
}



void selectionSortStr (char str[] , int size) {
	int i , j  , min ;
	for(i=0;i<size;i++) {
		min = i;
		for(j=i+1;j<size;j++) {
			if(str[j] < str[min] ) 
				min=j;	
		}
		swapChar(&str[i],&str[min]);
	}
}













////////////////////////////////////////////////////////////////////////////////////////// MERGE SORT

void mergeInt(int arr[], int left, int middle, int right) {

	int lsize = middle - left + 1;
	int rsize = right - middle;
	int Left[lsize];
	int Right[rsize];
	int i;
	for ( i = 0; i < lsize; i++) {

		Left[i] = arr[left + i];

	}
	int j;
	for ( j = 0; j < rsize; j++) {

		Right[j] = arr[middle + 1 + j];

	}

	i = 0; j = 0;
	int org=left;
	while (i<lsize && j<rsize) {
		if (Left[i] <= Right[j]) {

			arr[org] = Left[i];
			i++;
		}
		else {
			arr[org] = Right[j];
			j++;
		}
		org++;
			
	}
	while (i < lsize) {
		arr[org] = Left[i];
		i++; 
		org++;
	}
	while (j < rsize) {
		arr[org] = Right[j];
		j++;
		org++;

	}
}

	void mergeSortInt(int arr[], int left, int right) {
		
	if (left<right) {

		int middle = (left + right) / 2; 
		mergeSortInt(arr,left,middle );
		mergeSortInt(arr,middle+1,right );
		mergeInt(arr,left,middle,right);
	}
}







void mergeChar(char arr[], int left, int middle, int right) {

	int lsize = middle - left + 1;
	int rsize = right - middle;
	char Left[lsize];
	char Right[rsize];
	int i;
	for ( i = 0; i < lsize; i++) {

		Left[i] = arr[left + i];

	}
	int j;
	for ( j = 0; j < rsize; j++) {

		Right[j] = arr[middle + 1 + j];

	}

	i = 0; j = 0;
	int org=left;
	while (i<lsize && j<rsize) {
		if (Left[i] <= Right[j]) {

			arr[org] = Left[i];
			i++;
		}
		else {
			arr[org] = Right[j];
			j++;
		}
		org++;
			
	}
	while (i < lsize) {
		arr[org] = Left[i];
		i++; 
		org++;
	}
	while (j < rsize) {
		arr[org] = Right[j];
		j++;
		org++;

	}
}

	void mergeSortChar(char arr[], char left, char right) {
		
	if (left<right) {

		int middle = (left + right) / 2; 
		mergeSortChar(arr,left,middle );
		mergeSortChar(arr,middle+1,right );
		mergeChar(arr,left,middle,right);
	}
}