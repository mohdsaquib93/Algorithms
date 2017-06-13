#include <stdio.h>
#include <string.h>
#include <ctype.h>

int FirstOcc(int a[], int n, int item){
	int low=0,high=n-1;
	if(a[0]==item)
		return 0;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid-1]<item && a[mid]==item)
			return mid;
		else if(a[mid]<item)
			low=mid+1;
		else high=mid-1;
	}
	return -1;
}


int LastOcc(int a[], int n, int item){
	int low=0,high=n-1;
	if(a[n-1]==item)
		return n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==item && a[mid+1]>item)
			return mid;
		else if(a[mid]>item)
			high=mid-1;
		else low=mid+1;
	}
	return -1;
}

int main(){
	int n,k;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	scanf("%d",&k);
	int fo=FirstOcc(a,n,k);
	int lo=LastOcc(a,n,k);
	if(fo==-1){
		printf("Element not present\n");
		return 0;
	}
	printf("First Occurence: %d\n",fo+1);
	printf("Last Occurence: %d\n",lo+1);
	printf("\n");
	return 0;
}
