#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

float	salario, horas, valor_hora, grati, final;

int	main()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 2");
	
	printf	("\n\nDigite quantas horas voc� trabalha: ");
	scanf	("%f", &horas);
	printf	("\n\nDigite qual � o valor de sua hora de trabalho: ");
	scanf	("%f", &valor_hora);
	
	salario = horas*valor_hora;
	
	if	(salario <= 1500)
		{
			grati = 300;
		}
	
	else
		{
			grati = 500;
		}
	
	final = salario + grati;
	
	printf	("\n\nVoc� receber� esse m�s � R$%.2f", final);
	printf	("\nSendo R$%.2f de sal�rio + R$%.2f de gratifica��o.", salario, grati);
	
	getch	();
}
