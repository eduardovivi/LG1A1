#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <conio.h>


char palavra[10];
char palavratotal[10];
int i;
char letra;
float premios[] = {10, 20, 30};
float acumulado = 0;
int premioale;
int acertos = 0;

main(){
	
	printf("Digite uma palavra: ");
	gets(palavra);
	fflush(stdin);
	strupr(palavra);
	
	
	srand(time(NULL));
	
	for (i=0; palavra[i] != '\0'; i++){
		printf("_ ");
	}

do{
	setlocale(LC_ALL, "Portuguese");
	premioale = rand() % 100;
	printf("\nValendo R$%d.00 por letra.", premioale);
	printf("\nDigite uma letra: ");
	scanf("%c", &letra);
	
	letra = toupper(letra);
	
	fflush(stdin);
	
	acertos = 0;
	
	for (i=0; palavra[i] != '\0'; i++){
		
		if (palavra[i] == letra){
			printf(" %c", letra);
			palavratotal[i] = letra;
			acumulado = acumulado + premioale;
			acertos++;
		}
			else if (palavratotal[i] == palavra[i]){
				printf(" %c", palavratotal[i]);
			}
				else{
					printf(" _");
				}
	}
	
		if ( acertos>0){  
           printf ("\n\nPrêmio acumulado = R$ %.2f", acumulado);
        }
        	else{
          	 printf ("\n\nVocê PERDEU A VEZ, pois a letra informa '%c' NÃO faz parte da palavra", letra);
          	}
    getch();
    
}
	while (strcmp (palavra, palavratotal) && acertos!=0 );
}
