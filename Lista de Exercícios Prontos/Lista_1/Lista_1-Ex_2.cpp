/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Acentos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico    nome_da_variável */

float	num1 , num2 , soma;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 2\n\n");
	printf	("\n\nDigite o primreiro número:");
	scanf	("%f" , &num1);
	printf	("\n\nDigite o segundo número:");
	scanf	("%f" , &num2);
	soma = num1 + num2;
	printf	("\n\nA soma dos números digitados é: %.0f" , soma);
	
	getch	();
}

