/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Acentos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico    nome_da_variável */

float	num;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 1\n\n");
	printf	("Digite um número:");
	scanf	("%f" , &num);
	printf	("\n\nO número digitado foi: %.0f" , num);
	
	getch	();
}

