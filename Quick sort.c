#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void quickSort(int* ,int , int);
void swap(int* , int* );
int arrange(int*, int, int);
int main()
{

	int *arr,arrSize,i,j;
	printf("Quick Sort Program \n");
	printf("Please enter the size of array : ");
	scanf("%d",&arrSize);
	arr=(int*)calloc(arrSize,sizeof(int));
	printf("Enter the elements :\n");
	for(i=0;i<arrSize;i++)
	{
		scanf("%d",(arr+i));
	}
    quickSort(&arr[0],0,(arrSize-1));
	printf("\nSorted elements are : ");
	for(i=0;i<arrSize;i++)
	{
		printf("%d ",*(arr+i));
	} 
    return 0;
}
int arrange(int *arr, int l, int h)
{
    int *pivot;
    pivot = &arr[l];
    while(l<h)
        {
            while(arr[l]<=(*pivot) && l<h)
            {
                l++;
            }
            while(arr[h]>(*pivot))
            {
                h--;
            }
            if(l<h)
            swap(&arr[l],&arr[h]);
        }
        swap(pivot,&arr[h]);
        return h;
}    
void quickSort(int* arr,int l,int h)
{   
    int lower=l;
    int upper=h;
     if(l<h)
    {
        int j = arrange(&arr[0],l,h);
        quickSort(&arr[0],lower,j-1);
        quickSort(&arr[0],j+1,upper);
    }
}    
void swap(int* a, int* b)
{
	int j = *a;
	*a = *b;
	*b = j;
}
