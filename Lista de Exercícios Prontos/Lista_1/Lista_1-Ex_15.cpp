/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para c�lculos matem�ticos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico)	nome_da_vari�vel */

float	bruto, liq, IR, INSS, sind, hora_aula;
int		aula_semana;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\nEx. 15");
	printf	("\n\nDigite quantas aulas voc� trabalha por semana:");
	scanf	("%i", &aula_semana);	
	
	printf	("\nDigite o quanto voc� recebe por aula:");
	scanf	("%f", &hora_aula);	
	
	bruto = (aula_semana*hora_aula*4.5);
	IR = bruto*0.11;
	INSS = bruto*0.08;
	sind = /*bruto*0.05*/0;
	liq = bruto-IR-INSS-sind;
	
	printf	("\n\nAbaixo o seu holerite:");
	printf	("\n\n\nSal�rio bruto: +R$%.2f",	bruto);
	printf	("\n\n\nDescontos:");
	printf	("\n\nI.R. (11%%): -R$%.2f",	IR);
	printf	("\n\nINSS (8%%): -R$%.2f",	INSS);
	printf	("\n\nSindicato (5%%): -R$%.2f",	sind);
	printf	("\n\n\nSal�rio l�quido = Sal�rio bruto - Descontos");
	printf	("\n\nSal�rio l�quido: +R$%.2f", liq);
	
	getch	();
}

