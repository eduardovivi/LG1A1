/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para c�lculos matem�ticos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico    nome_da_vari�vel */

float	raio , area;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 5");
	printf	("\n\nDigite o raio de um c�rculo:");
	scanf	("%f" , &raio);
	
	area = M_PI * pow(raio,2);
	
	printf	("\n\nA �rea do c�rculo de raio %.2f(unidade de dist�ncia) �: %f(unidade de �rea)" , raio , area);
	
}

