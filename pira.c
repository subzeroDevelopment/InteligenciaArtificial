#include <stdio.h>

int main(void){
	int n;
	printf("%s\n","ingrese numero" );
	scanf("%d",&n);
	int x=1;
	int me=(n*2);
	printf("%d\n",me);
	for(int i=1;i<=n;i++){
		for (int i=me;i>=0;i--)
		{
			printf(" ");
		}
		for (int j = 0; j <x; ++j)
		{
			printf("*");
			printf(" ");
		}
		me--;
			
		printf("\n");
		x++;
	}


}