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
	printf	("\n\nVocê digitará a medida dos três lados (A, B e C) de um triângulo e eu lhe direi o tipo de triângulo!");
	printf	("\n\nEntão vamos lá!\n\nDigite o lado A: ");
	scanf	("%i", &A);
	
	printf	("\n\nAgora digite o lado B: ");
	scanf	("%i", &B);
	
	printf	("\n\nPor fim, digite o lado C: ");
	scanf	("%i", &C);

	if	(A > (B+C))
	{
		printf	("\n\n\tSinto muito! Com essas medidas, nem forma um triângulo.\n\n\tTente outra vez.");
		return	(0);
	}
	
	if	(A != B && A != C && B != C)
	{
		printf	("\n\n\tEsse triângulo tem TODOS os seus lados DIFERENTES, logo, ele é ESCALENO!");
		return	(0);
	}
	if	(A == B || A == C || B == C)
	{
		if	(B == C && C == B && C == A)
		{
			printf	("\n\n\tEsse triângulo tem TODOS os lados IGUAIS, logo, ele é EQUILÁTERO!");
			return	(0);
		}
		else
		{
			printf	("\n\n\tEsse triângulo tem DOIS de seus lados IGUAIS, logo, ele é ISÓCELES!");
			return	(0);
		}
	}
}

