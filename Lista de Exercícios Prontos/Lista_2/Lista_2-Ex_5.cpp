#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

float	massa, altura, IMC;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 5");
	printf	("\n\nCálculo do IMC (Índice de Massa Corporal)");
	printf	("\n\nDitige a sua massa em quilogramas (kg): ");
	scanf	("%f", &massa);
	printf	("\n\nAgora digite a sua altura em metros (m): ");
	scanf	("%f", &altura);
	
	IMC = (massa / (altura*altura));
	
	printf	("\n\nSituação:\n\t    IMC<20  --> Abaixo do peso\n\t20<=IMC<=25 --> Peso normal");
	printf	("\n\t25<=IMC<=30 --> Acima do peso\n\t30<=IMC<=34 --> Obeso");
	printf	("\n\t    IMC>34  --> Muito obeso");
	if	(IMC < 20)
	{
		printf	("\n\nO seu IMC é de %.2fkg/m^2.\n\nSegundo a Organização Mundial da Saúde (OMS) você está ABAIXO DO PESO!", IMC);
	}
	
	if	(IMC >= 20 && IMC <= 25)
	{
			printf	("\n\nO seu IMC é de %.2fkg/m^2.\n\nSegundo a Organização Mundial da Saúde (OMS) você está com PESO NORMAL!", IMC);
	}
	
	if	(IMC >= 25 && IMC <= 30)
	{
			printf	("\n\nO seu IMC é de %.2fkg/m^2.\n\nSegundo a Organização Mundial da Saúde (OMS) você está ACIMA DO PESO!", IMC);
	}
	
	if	(IMC >= 30 && IMC <= 35)
	{
			printf	("\n\nO seu IMC é de %.2fkg/m^2.\n\nSegundo a Organização Mundial da Saúde (OMS) você está OBESO!", IMC);
	}
	
	if	(IMC > 34)
	{
			printf	("\n\nO seu IMC é de %.2fkg/m^2.\n\nSegundo a Organização Mundial da Saúde (OMS) você está MUITO OBESO!", IMC);
	}
	
	getch	();
}
