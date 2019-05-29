/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para cálculos matemáticos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico    nome_da_variável */

float	lado , area , dobro;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 6");
	printf	("\n\nDigite o lado de um quadrado:");
	scanf	("%f" , &lado);
	
	area = lado * lado;
	dobro = area * 2;
	
	printf	("\n\nA área do quadrado de lado %.0f(unidade de distância) é: %.0f(unidade de área)" , lado , area);
	printf	("\n\nE o dobro de sua área é:%.0f(unidade de área)" , dobro);
	
	getch	();
}

