#include <stdio.h>
#include <iostream>
#include <time.h>

// 使用大堆演示堆排序的思路

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

void ajustRoot(int a[], int k, int len) // 调整大根堆(逻辑二叉树) k位置的非叶子结点. 小于左右子树就下沉.
{
	a[0]=a[k];
	for(int i=k*2; i<=len; i*=2)  // 一直下沉到合适的位置
	{
		if(i<len && a[i]<a[i+1]) i++;
		if(a[0]>=a[i]) break;
		else
		{
			a[k]=a[i];
			k=i;
		}
		a[k]=a[0];
	}
}

void buildMaxHeap(int a[],int len)  // 建立大根堆
{
	for(int i=len/2; i>0; i--)
		ajustRoot(a, i, len);
}


void heapSort(int a[], int len)
{
	buildMaxHeap(a,len);
	for(int i=len; i>1; i--) // 这里用顺序表思维思考
	{
		swap(a[1],a[i]);
		ajustRoot(a, 1, i-1);
	}
}

int main()
{
	int num,data;
	clock_t start,end;
	scanf("%d", &num);
	int a[num+1];
	for(int i=1; i<=num; i++)
	{
		scanf("%d", &data);
		a[i]=data;
	}

	start = clock();
	heapSort(a,num);
	end = clock();
	for(int i=1; i<=num; i++)
	{
		printf("%d ", a[i]);
		if(i == num) printf("\n");
	}
	printf("heapsort run time is %lf", (double)(end-start)/CLOCKS_PER_SEC);
}
