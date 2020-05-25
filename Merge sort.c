#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
int* mergeSort(int* ,int);
int* merge(int* ,int* , int , int);
int main()
{
	//clrscr();
	int *arr , arrSize;
	int i;
	printf("Merge Sort Program. \n");
	printf("Please Enter the size of the array : ");
	scanf("%d",&arrSize);
	arr = (int*)calloc(arrSize,sizeof(int));
	printf("Please enter elements : ");
	for(i=0 ; i<arrSize;i++)
	scanf("%d",(arr + i));
	arr = mergeSort(arr,arrSize);
	for(i=0;i<arrSize;i++)
	printf("%d ",*(arr+i));

//	getch();
	return 0;
}
int* mergeSort(int* arr,int arrSize)
{
	if(arrSize == 1)
	return arr;
	else
	{
		int i;

		int *arr1 , arr1Size;
		arr1Size = (arrSize + 1)/2;
		arr1=(int*)calloc(arr1Size,sizeof(int));
		for(i=0 ; i<arr1Size ; i++)
		{ *(arr1 + i) = *(arr + i); }

		int *arr2 , arr2Size;
		arr2Size = arrSize - arr1Size;
		arr2=(int*)calloc(arr2Size,sizeof(int));
		for(i=0;i<arr2Size ; i++)
		{ *(arr2 + i)  = *(arr+i+arr1Size ); }

		arr1 = mergeSort(arr1,arr1Size);
		arr2 = mergeSort(arr2,arr2Size);

		return merge(arr1,arr2,arr1Size,arr2Size);
	}
}
int* merge(int* arr_A , int* arr_B , int arr_Alen , int arr_Blen )
{
	int *arr_C , arr_Clen;
	arr_Clen = arr_Alen + arr_Blen;
	arr_C = (int*)calloc(arr_Clen , sizeof(int));
	int i=0,j=0,k=0;
	while(i<arr_Alen && j<arr_Blen)
	{
		if(*(arr_A + i) > *(arr_B + j))
		{
			*(arr_C + k) = *(arr_B + j);
			k++;
			j++;
		}
		else
		{
			*(arr_C + k) = *(arr_A + i );
			k++;
			i++;
		}
	}
	if(i<arr_Alen)
	{
		while(i<arr_Alen)
		{
		 *(arr_C + k) = *(arr_A + i);
		 i++;
		 k++;
		}
	}
	else if(j<arr_Blen)
	{
		while(j<arr_Blen)
		{
		*(arr_C + k) = *(arr_B + j);
		j++;
		k++;
		}
	}
	free (arr_A);
	free (arr_B);
	return arr_C;
}






