#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

int	horas, hora_extra, dif_hora;
float	extra, salario, final;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 3");
	
	printf	("\n\nDigite o n�mero de horas trabalhadas esse m�s: ");
	scanf	("%i", &horas);
	
	if	(horas > 50)
	{
		hora_extra = horas-50;
		dif_hora = horas - hora_extra;
		extra = 20*hora_extra;
		salario = 10*horas;
		final = salario + extra;
	}
	else
	{
		extra = 0;
		salario = 10*horas;
		final = salario + extra;
		hora_extra = 0;
	}
	
	printf	("\n\nVoc� trabalhou esse m�s %ih e vai receber R$%.2f de sal�rio", horas, final);
	printf	("\nSendo que R$%.2f � referente a %ih e R$%.2f � referente �s %ih extras.", salario, dif_hora, extra, hora_extra);
	
	getch	();
}
