#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int l, int r){
	int x=a[r],i,j;
	for(j=l,i=j-1;j<r;j++){
		if(a[j]<=x){
			i++;
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	a[r]=a[i+1];
	a[i+1]=x;
	return i+1;
}

int kth(int a[], int l, int r, int k){
	while(1){
		int p=partition(a,l,r);
		if(p==k)
			return a[p];
		if(p>k)
			r=p-1;
		else
			l=p+1;
	}	
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	printf("%d",kth(a,0,n-1,(n-1)/2));
	printf("\n");
	return 0;
}
