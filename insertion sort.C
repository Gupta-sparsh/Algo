#include<stdio.h>
#include<stdlib.h>
int main()
{
	 int arrSize,*arr,i,j,num;
	 printf("Insertion Sort Program\n");
	 printf("Enter the size of array : ");
	 scanf("%d",&arrSize);
	 arr=(int*)calloc(arrSize,sizeof(int));
	 printf("Enter data :\n");
	 for(i=0;i<arrSize;i++)
	 {
		scanf("%d",(arr+i));
	 }
	 i=0;
	 for(j=1;j<arrSize;j++)
	 {
	      num=*(arr+j);
	      i=j-1;
	      while(i>=0 && arr[i]>num)
	      {
		arr[i+1] = arr[i];
		i=i-1;
		arr[i+1] = num;
	      }
	 }
	printf("\n");
	for(i=0;i<arrSize;i++)
	{
		printf("%d\n",*(arr + i));
	}
	 return 0;
}

