/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para cálculos matemáticos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico    nome_da_variável */

float	raio , area;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 5");
	printf	("\n\nDigite o raio de um círculo:");
	scanf	("%f" , &raio);
	
	area = M_PI * pow(raio,2);
	
	printf	("\n\nA área do círculo de raio %.2f(unidade de distância) é: %f(unidade de área)" , raio , area);
	
}

