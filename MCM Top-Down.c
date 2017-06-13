#include <stdio.h>
#include <limits.h>

int LOOKUP(int *p, int i, int j, int n, int (*m)[n]){
	if(m[i][j]<1000000)
		return m[i][j];
	if(i==j)
		m[i][j]=0;
	else {
		for(int k=i;k<j;k++){
			int q=LOOKUP(p,i,k,n,m)+LOOKUP(p,k+1,j,n,m)+p[i]*p[k+1]*p[j+1];
			if(q<m[i][j]){
				m[i][j]=q;
			}
		}
	}
	return m[i][j];
}

void MCM(int *p, int n, int (*m)[n]){
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			m[i][j]=1000000;
	LOOKUP(p,0,n-1,n,m);
}

int main(){
	int n;
	printf("Enter no of matrices: ");
	scanf("%d",&n);
	int p[n+1],m[n][n];
	for(int i=0;i<n;i++){
		int x,y;
		printf("Enter matrix%d dimensions: ",i+1);
		scanf("%d %d",&x,&y);
		p[i]=x;
		if(i==n-1)
			p[++i]=y;
	}
	MCM(p,n,m);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			printf("%d ",m[i][j]);
		printf("\n");
	}
	return 0;
}
