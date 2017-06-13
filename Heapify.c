#include <stdio.h>
#include <stdlib.h>

void MAX_HEAPIFY(int a[], int i, int heapSize) {
	int l=2*i+1,r=l+1,max=i;
	if(l<=heapSize && a[l]>a[i])
		max=l;
	if(r<=heapSize && a[r]>a[max])
		max=r;
	if(i!=max){
		int temp=a[max];
		a[max]=a[i];
		a[i]=temp;
		MAX_HEAPIFY(a,max,heapSize);
	}
}

void BUILD_MAX_HEAP(int a[], int n){
	for(int i=(n-1)/2;i>=0;i--)
		MAX_HEAPIFY(a,i,n-1);
}

int EXTRACT_MAX(int a[], int heapSize){
	if(heapSize < 0){
		printf("Heap Underflow\n");
		return -1;
	}
	int key=a[0];
	a[0]=a[heapSize];
	heapSize--;
	MAX_HEAPIFY(a,0,heapSize);
	return key;
}

void INCREASE_KEY(int a[], int i, int new){
	if(new < a[i]){
		printf("Error\n");
		return;
	}
	a[i]=new;
	while(i>0 && a[(i-1)/2] < a[i]){
		int temp=a[i];
		a[i]=a[(i-1)/2];
		a[(i-1)/2]=temp;
		i=(i-1)/2;
	}
}

void DECREASE_KEY(int a[], int i, int new, int heapSize){
	if(new > a[i]){
		printf("Error\n");
		return;
	}
	a[i]=new;
	MAX_HEAPIFY(a,i,heapSize);
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	BUILD_MAX_HEAP(a,n);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	/*printf("Max: %d\n",EXTRACT_MAX(a,n-1));
	int new,i;
	scanf("%d %d",&i,&new);
	INCREASE_KEY(a,i-1,new);
	DECREASE_KEY(a,i-1,new,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	return 0;
}
