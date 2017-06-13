#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int l,int m,int r){
	int p=m-l+1,q=r-m;
	int *left=malloc(sizeof(int)*(p));
	int *right=malloc(sizeof(int)*(q));
	for(int i=l,j=0;i<=m;i++,j++)
		left[j]=a[i];
	for(int i=m+1,j=0;i<=r;i++,j++)
		right[j]=a[i];
	int i,j,k;
	i=j=0;
	k=l;
	while(i<p && j<q)
		left[i]<=right[j]?a[k++]=left[i++]:(a[k++]=right[j++]);
	while(i<p)
		a[k++]=left[i++];
	while(j<q)
		a[k++]=right[j++];
	free(left);
	free(right);
}

void mergesort(int a[],int l,int r){
	if(l<r){
		int m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",*(a+i));
	printf("\n");
	return 0;
}
