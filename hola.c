#include <stdio.h>

int main(void)
{
	int a=13;
	int b=10*5;
	int c=a+b;

	printf("El valor de la suma:%d\n",c);

	int x;
	float y;

	scanf("%d",&x);
	scanf("%f",&y);
	float w=x+y;

	printf("El valor de la suma:%f\n",w);

	if("a"=="a"){
		printf("%s\n","hola Mundo!" );
		printf("%s\n","Hola!" );

	}

	int n=0;
	while(n<20){
		printf("%s\n","Subzero");
		n++;
	}

	int arre[10]={2,5,3,2,5,42,5,2,77,23};
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", arre[i]);
	}



	return 0;
}