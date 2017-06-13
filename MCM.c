#include <stdio.h>
#include <limits.h>

void MCM(int *p, int n, int (*m)[n], int (*s)[n]){
	for(int i=0;i<n;i++){
		m[i][i]=0;
		s[i][i]=i;
	}
	for(int l=2;l<=n;l++){
		for(int i=0,j=l-1;i<=n-l;i++,j++){
			m[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}


int main(){
	int n;
	scanf("%d",&n);
	int p[n+1],m[n][n],s[n][n];
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=x;
		if(i==n-1)
			p[++i]=y;
	}
	MCM(p,n,m,s);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			printf("(%d,%d) ",m[i][j],s[i][j]);
		printf("\n");
	}
	return 0;
}
