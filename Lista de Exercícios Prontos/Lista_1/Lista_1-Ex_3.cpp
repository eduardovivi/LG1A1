/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Acentos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico    nome_da_vari�vel */

float	P1 , P2 , P3 , P4 , media;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 3");
	printf	("\n\nDigite a nota da P1:");
	scanf	("%f" , &P1);
	
	printf	("\n\nDigite a nota da P2:");
	scanf	("%f" , &P2);
	
	printf	("\n\nDigite a nota da P3:");
	scanf	("%f" , &P3);
	
	printf	("\n\nDigite a nota da P4:");
	scanf	("%f" , &P4);
		
	media = (P1 + P2 + P3 + P4)/4;
	printf	("\n\nA m�dia das notas �: %.1f" , media);
	
	getch	();
}

