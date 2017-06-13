#include <stdio.h>
#include <limits.h>

void LCS(char *x, int m, char *y, int n, int (*c)[n+1]){
	for(int i=0;i<=m;i++)
		c[i][0]=0;
	for(int j=0;j<=n;j++)
		c[0][j]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i]==y[j])
				c[i][j]=1+c[i-1][j-1];
			else{
				int p=c[i-1][j];
				int q=c[i][j-1];
				c[i][j]=(p>q?p:q);
			}
		}
	}
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	char x[m],y[n];
	getchar();
	gets(x);
	getchar();
	gets(y);
	int c[m+1][n+1];
	LCS(x,m,y,n,c);
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
