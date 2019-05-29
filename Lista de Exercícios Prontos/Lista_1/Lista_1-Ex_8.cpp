/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para cálculos matemáticos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico    nome_da_variável */

float	F , C , K;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 8");
	
	printf	("\n\nDigite o valor de temperatura em °F:");
	scanf	("%f" , &F);
	
	C = (5*(F-32)/9);
	K = (5*(F-32)/9) + 273;
	
	printf	("\n\nIsso corresponde a %.2f°C", C);
	printf	("\n\nOu a %.2fK", K);
	getch	();
}

