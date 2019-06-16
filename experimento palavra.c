#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char palavra[10];
char palavratotal[10];
int i;
char letra;

main(){
	
	printf("Digite uma palavra: ");
	scanf("%s", &palavra);
	fflush(stdin);
	
	for (i=0; palavra[i] != '\0'; i++){
		printf("_ ");
	}

do{

	printf("\nDigite uma letra: ");
	scanf("%c", &letra);
	fflush(stdin);
	
	for (i=0; palavra[i] != '\0'; i++){
		
			if (palavra[i] == letra){
				printf(" %c", letra);
				palavratotal[i] = letra;
				
			}
				else if (palavratotal[i] == palavra[i]){
					printf(" %c", palavratotal[i]);
				}
					else{
						printf(" _");
					}
	}

}
	while (strcmp (palavra, palavratotal) == 1 );
	exit (0);	
}
