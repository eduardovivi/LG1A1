#include	<stdio.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

char	sex;
float	PC, I, Alt, GEB;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 4");
	printf	("\n\nC�lculo do Gasto Energ�tico Basal (GEB)");
	printf	("\n\nDigite a sua altura em cent�metros (cm): ");
	scanf	("%f", &Alt);
	printf	("\n\nDigite a sua massa corporal em quilogramas (kg): ");
	scanf	("%f", &PC);
	printf	("\n\nDigite a sua idade em anos completos: ");
	scanf	("%f", &I);
	printf	("\n\nDigite H se voc� � homem ou M se voc� � mulher: ");
	fflush	(stdin);
	scanf	("%c", &sex);
		
	if (sex == 'H')
	{
		GEB = 66.47+(13.75*PC)+(5*Alt)-(6.76*I);
	}
	
	else
	{
		GEB = 655.1+(9.56*PC)+(1.85*Alt)-(4.67*I);
	}
		printf	("\n\n\nVoc� � %c,\n tem %.0f anos de idade,\n pesa %.0fkg,\n tem %.0fcm de altura\n\n e o seu Gasto Energ�tico Basal � de %.2f(unidade n�o dada).", sex, I, PC, Alt, GEB);
	getch	();
}
