/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Acentos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico    nome_da_vari�vel */

float	vlr_m , vlr_cm;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 4");
	printf	("\n\nDigite uma medida em metros para ser ser convertida em cent�metros:");
	scanf	("%f" , &vlr_m);
	
	vlr_cm = vlr_m*100;
	
	printf	("\n\nA medida %.3f m � igual a %.3f cm" , vlr_m , vlr_cm);
	
	getch	();
}

