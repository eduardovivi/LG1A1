#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char palavra[10];
char palavratotal[10];
int i;
char letra;
int acertos;
float premios[] = {10, 20, 30};
float acumulado = 0;
int premioale;
int acertou = 0;

main(){
	
	printf("Digite uma palavra: ");
	scanf("%s", &palavra);
	fflush(stdin);
	
	srand(time(NULL));
	
	for (i=0; palavra[i] != '\0'; i++){
		printf("_ ");
	}

do{
	premioale = rand() % 100;
	printf(" Valendo R$%d.00 por letra.", premioale);
	printf("\nDigite uma letra: ");
	scanf("%c", &letra);
	fflush(stdin);
	
	for (i=0; palavra[i] != '\0'; i++){
		
			if (palavra[i] == letra){
				printf(" %c", letra);
				palavratotal[i] = letra;
				acertos = acertos + 1;
				acumulado = acumulado + premioale;
				acertou = 1;
				
				
			}
				else if (palavratotal[i] == palavra[i]){
					printf(" %c", palavratotal[i]);
					acertou = 1;
					
				}
					else if (acertou == 1){
						acertou = 1;
						printf(" _");
					}
						else{
							acertou = 0;
							exit (0);
						}
	}

}
	while (strcmp (palavra, palavratotal) == 1 && acertou == 1);
	printf("\nAcertos: %d", acertos);
	printf("\nValor total em premios: %.2f", acumulado);
	exit (0);
	
}
