/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para c�lculos matem�ticos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico    nome_da_vari�vel */

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
	
	printf	("\n\nA �rea do quadrado de lado %.0f(unidade de dist�ncia) �: %.0f(unidade de �rea)" , lado , area);
	printf	("\n\nE o dobro de sua �rea �:%.0f(unidade de �rea)" , dobro);
	
	getch	();
}

