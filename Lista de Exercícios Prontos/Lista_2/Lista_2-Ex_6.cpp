#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

int	A, B, C;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 6");
	printf	("\n\nVoc� digitar� a medida dos tr�s lados (A, B e C) de um tri�ngulo e eu lhe direi o tipo de tri�ngulo!");
	printf	("\n\nEnt�o vamos l�!\n\nDigite o lado A: ");
	scanf	("%i", &A);
	
	printf	("\n\nAgora digite o lado B: ");
	scanf	("%i", &B);
	
	printf	("\n\nPor fim, digite o lado C: ");
	scanf	("%i", &C);

	if	(A > (B+C))
	{
		printf	("\n\n\tSinto muito! Com essas medidas, nem forma um tri�ngulo.\n\n\tTente outra vez.");
		return	(0);
	}
	
	if	(A != B && A != C && B != C)
	{
		printf	("\n\n\tEsse tri�ngulo tem TODOS os seus lados DIFERENTES, logo, ele � ESCALENO!");
		return	(0);
	}
	if	(A == B || A == C || B == C)
	{
		if	(B == C && C == B && C == A)
		{
			printf	("\n\n\tEsse tri�ngulo tem TODOS os lados IGUAIS, logo, ele � EQUIL�TERO!");
			return	(0);
		}
		else
		{
			printf	("\n\n\tEsse tri�ngulo tem DOIS de seus lados IGUAIS, logo, ele � IS�CELES!");
			return	(0);
		}
	}
}

