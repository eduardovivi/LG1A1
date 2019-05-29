/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para cálculos matemáticos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico)	nome_da_variável */

float	area, litro, lata, preco;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\nEx. 16");
	
	printf	("\n\nDigite quantos metros quadrados você deseja pintar:");
	scanf	("%f", &area);
	litro = area/3;
	lata = int(litro/18)+1;	

	preco = lata*80;
	
	printf	("\n\nVocê precisará de %.0f lata(s) de tinta de R$80,00 cada.\n\nCom isso, gastará R$%.2f", lata, preco);
		
	getch	();
}

