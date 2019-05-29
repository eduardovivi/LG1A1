#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	<conio.h>
#include	<locale.h>	/* Para acentos */

float	peso, excesso, multa;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nJoão Papo-de-Pescador, favor digitar quantos kg de peixe o senhor pescou hoje:");
	scanf	("%f",	&peso);
	if	(peso <= 50)
	{
	
		excesso = 0;
		multa = 0;
	
	}
	else
	{
		
		excesso = peso-50;
		multa = excesso*4;
		
	}
	printf	("\n\nO senhor pescou em excesso %.2fkg de peixe hoje.\n\nE, por isso, deverá pagar R$%.2f de multa.", excesso, multa);
	getch	();
	
}
