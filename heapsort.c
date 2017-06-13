#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int i, int heapsize){
	int l=2*i+1,r=l+1,max=i;
	if(l<=heapsize && a[l]>a[i])
		max=l;
	if(r<=heapsize && a[r]>a[max])
		max=r;
	if(i!=max){
		int temp=a[i];
		a[i]=a[max];
		a[max]=temp;
		heapify(a,max,heapsize);
	}
}

void build_heap(int a[], int heapsize){
	for(int i=heapsize/2;i>=0;i--)
		heapify(a,i,heapsize);
}

void heapsort(int a[], int heapsize){
	build_heap(a,heapsize);
	for(int i=heapsize;i>=1;i--){
		int temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapsize--;
		heapify(a,0,heapsize);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	heapsort(a,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
