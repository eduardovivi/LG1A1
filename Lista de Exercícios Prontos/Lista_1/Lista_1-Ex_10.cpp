/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para c�lculos matem�ticos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico    nome_da_vari�vel */

float	real, resu_1, resu_2, resu_3, num1, num2;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 10");
	
	printf	("\n\nDigite o primeiro n�mero inteiro: ");
	scanf	("%f" , &num1);
	
	printf	("\n\nDigite o segundo n�mero inteiro: ");
	scanf	("%f" , &num2);
	
	printf	("\n\nDigite um n�mero real: ");
	scanf	("%f" , &real);
	
	resu_1 = (2*num1)*(num2/2);
	resu_2 = 3*num1+real;
	resu_3 = pow(real,3);
	
	printf	("\n\nO dobro do 1� n�mero vezes metade do 2� �: %.2f", resu_1);
	printf	("\n\nA soma do triplo do 1� n�mero com o 3� �: %.2f", resu_2);
	printf	("\n\nO cubo do 3� n�mero �: %.2f", resu_3);
	getch	();
}

