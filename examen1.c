#include<stdio.h>	
#include<string.h>
int main(void)
{
 char palabra[80];
 int x,y,z;
   printf("\n\nEscribe una palabra: ");
   scanf(" %s",palabra);
   x=strlen(palabra);
   printf("%d\n",x);

   int aux=(x/2);
    printf("%d\n",aux);
   int p=0;
   for (int i = 0;i<=aux;i++)
   {
   		printf("uno %hhd\n",palabra[i] );
   		printf("dos %hhd\n",palabra[x-1] );
   		char uno=palabra[i];
   		char dos=palabra[x-1];

   		if(palabra[i]==palabra[x-1]){
   			p++;
   			printf("p %d\n",p);
   		}
   		x--;

   }
   p--;
   printf("%d\n",p);
  
   if(p==aux){
   	printf("%s\n","palindromo" );
   }
   else
   	printf("%s\n", "no es palindromo");
   return 0;	
 
 }   		

