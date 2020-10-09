#include<stdio.h>

void mergesort(int i,int j);
int temp[10000],a[1000];

int main()
{
	int n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter array elements:");

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	mergesort(0,n-1);

	printf("\nSorted array is :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	return 0;
}

void mergesort(int lo,int hi){

    if(lo==hi) return;
    int mid=(lo+hi)/2;
    mergesort(lo,mid);
    mergesort(mid+1,hi);

    int i=lo;
    int j=mid+1;
    for(int k=lo; k<=hi;k++){
        if(i==mid+1) temp[k]=a[j++];
        else if(j== hi+1) temp[k]=a[i++];
        else if(a[i]<a[j]) temp[k]=a[i++];
        else temp[k]=a[j++];
    }

    for(int k=lo;k<=hi;k++) a[k]=temp[k];

}

