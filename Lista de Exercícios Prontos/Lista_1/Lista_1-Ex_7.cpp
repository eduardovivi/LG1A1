/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para c�lculos matem�ticos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico    nome_da_vari�vel */

float	salario , h_dia , h_trab;
int		dia_semana;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 7");
	
	printf	("\n\nDigite o valor de seu sal�rio: R$");
	scanf	("%f" , &salario);
	
	printf	("\n\nDigite quantos dias voc� trabalha na semana:");
	scanf	("%i" , &dia_semana);
	
	printf	("\n\nDigite quantas horas por dia:");
	scanf	("%f" , &h_dia);	
	
	h_trab = salario/(4.5*dia_semana*h_dia);
	
	printf	("\n\nO valor da sua hora de trabalho � R$%.2f" , h_trab);
	
	getch	();
}

