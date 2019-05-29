/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para cálculos matemáticos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico    nome_da_variável */

float	real, resu_1, resu_2, resu_3, num1, num2;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 10");
	
	printf	("\n\nDigite o primeiro nùmero inteiro: ");
	scanf	("%f" , &num1);
	
	printf	("\n\nDigite o segundo nùmero inteiro: ");
	scanf	("%f" , &num2);
	
	printf	("\n\nDigite um número real: ");
	scanf	("%f" , &real);
	
	resu_1 = (2*num1)*(num2/2);
	resu_2 = 3*num1+real;
	resu_3 = pow(real,3);
	
	printf	("\n\nO dobro do 1° número vezes metade do 2° é: %.2f", resu_1);
	printf	("\n\nA soma do triplo do 1° número com o 3° é: %.2f", resu_2);
	printf	("\n\nO cubo do 3° número é: %.2f", resu_3);
	getch	();
}

