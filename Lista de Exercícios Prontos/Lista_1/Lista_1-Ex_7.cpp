/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para cálculos matemáticos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico    nome_da_variável */

float	salario , h_dia , h_trab;
int		dia_semana;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 7");
	
	printf	("\n\nDigite o valor de seu salário: R$");
	scanf	("%f" , &salario);
	
	printf	("\n\nDigite quantos dias você trabalha na semana:");
	scanf	("%i" , &dia_semana);
	
	printf	("\n\nDigite quantas horas por dia:");
	scanf	("%f" , &h_dia);	
	
	h_trab = salario/(4.5*dia_semana*h_dia);
	
	printf	("\n\nO valor da sua hora de trabalho é R$%.2f" , h_trab);
	
	getch	();
}

