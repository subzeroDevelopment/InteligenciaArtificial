#include <stdio.h>

int main(void)
{
	int n,m;
	printf("%s\n","ingrese n" );
	scanf("%d",&n);
	printf("%s\n","ingrese m" );
	scanf("%d",&m);
	int arre[n][m];

	int valor=0;
	for (int i = 0; i <n; ++i)
	{
		for (int j = 0;  j<m; ++j)
		{
			printf("ingrese valor %d%d\n",i,j);
			scanf("%d",&valor);
			arre[i][j]=valor;
		}
	}
	for (int i = 0; i <n;i++)
	{
		for (int j = 0;  j<m; j++)
		{
			printf("%d",arre[i][j]);
			
		}
		printf("\n");
	}


	int arre2[n][m];
	for (int i = 0; i <n;i++)
	{
		for (int j = 0;  j<m; j++)
		{
			arre2[i][j]=0;
			
		}
	
	}

	int x=0;
	int y=0;
	for (int i =(n-1); i>=0;i--)
	{
		for (int j = (m-1);j>=0;j--)
		{
			valor=arre[i][j];
			printf("v%d\n",valor);
			arre2[x][y]=valor;

			y++;
		}
		x++;
		y=0;
	}

	for (int i = 0; i <n;i++)
	{
		for (int j = 0;j<m; j++)
		{
			printf("%d",arre2[i][j]);
			
		}
		printf("\n");
	}






	return 0;
}