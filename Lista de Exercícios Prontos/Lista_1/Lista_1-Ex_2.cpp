/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Acentos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico    nome_da_vari�vel */

float	num1 , num2 , soma;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 2\n\n");
	printf	("\n\nDigite o primreiro n�mero:");
	scanf	("%f" , &num1);
	printf	("\n\nDigite o segundo n�mero:");
	scanf	("%f" , &num2);
	soma = num1 + num2;
	printf	("\n\nA soma dos n�meros digitados �: %.0f" , soma);
	
	getch	();
}

