/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para c�lculos matem�ticos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico)	nome_da_vari�vel */

float	area, litro, lata, preco;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\nEx. 16");
	
	printf	("\n\nDigite quantos metros quadrados voc� deseja pintar:");
	scanf	("%f", &area);
	litro = area/3;
	lata = int(litro/18)+1;	

	preco = lata*80;
	
	printf	("\n\nVoc� precisar� de %.0f lata(s) de tinta de R$80,00 cada.\n\nCom isso, gastar� R$%.2f", lata, preco);
		
	getch	();
}

