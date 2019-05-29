#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

float	hora_extra, hora_falta, M, grat;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 11");
	
	printf	("\n\nO cálculo da gratificação se dará de acordo com a tabela a seguir, em que: ");
	printf	("\n\nM = (Número de horas extras) - (2/3*(Números de horas-falta))");
	printf	("\n\n\tM em minutos\t\tPrêmio em R$");
	printf	("\n\t    >2400\t\t\t500,00\n\t1801 até 2400\t\t\t400,00");
	printf	("\n\t1201 ate 1800\t\t\t300,00\n\t 600 até 1200\t\t\t200,00");
	printf	("\n\tMenor que 600\t\t\t100,00\n\n");
	
	printf	("\n\nDigite o número de horas extras trabalhadas: ");
	scanf	("%f", &hora_extra);
	printf	("\n\nDigite o número de horas-falta: ");
	scanf	("%f", &hora_falta);
	
	M=(hora_extra*60)-((2/3)*(hora_falta*60));
	
	if	(M<=600)
	{
		grat=100;
		printf	("\n\nM=%.0f", M);
		printf	("\n\nA sua gratificação será de R$%.2f", grat);
		return	(0);
	}
	
	if	(M>600 && M<=1200)
	{
		grat=200;
		printf	("\n\nM=%.0f", M);
		printf	("\n\nA sua gratificação será de R$%.2f", grat);
		return	(0);
	}
	if	(M>1200 && M<=1800)
	{
		grat=300;
		printf	("\n\nM=%.0f", M);
		printf	("\n\nA sua gratificação será de R$%.2f", grat);
		return	(0);
	}
	if	(M>1800 && M<=2400)
	{
		grat=400;
		printf	("\n\nM=%.0f", M);
		printf	("\n\nA sua gratificação será de R$%.2f", grat);
		return	(0);
	}
	if	(M>2400)
	{
		grat=500;
		printf	("\n\nM=%.0f", M);
		printf	("\n\nA sua gratificação será de R$%.2f", grat);
		return	(0);
	}
	getch	();
}

