#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int l, int r){
	int p=a[r];
	int j=l,i=j-1;
	while(j<r){
		if(a[j]<=a[r]){
			i++;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		j++;
	}
	a[r]=a[i+1];
	a[i+1]=p;
	return i+1;
}

void quicksort(int a[],int l,int r){
	if(l<r){
		int p=partition(a,l,r);
		quicksort(a,l,p-1);
		quicksort(a,p+1,r);
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",*(a+i));
	printf("\n");
	return 0;
}
