#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

int	A, B, resto1, resto2;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 9");
	
	printf	("\n\nDigite dois valores, A e B, e lhe direi se eles s�o m�ltiplos");
	printf	("\n\nCome�ando pelo valor de A: ");
	scanf	("%i", &A);
	printf	("\n\nAgora digite o valor de B: ");
	scanf	("%i", &B);
	
	resto1 = A % B;
	resto2 = B % A;
	
	if	(resto1 == 0 || resto2 == 0)
	{
		printf	("\n\nOs valores de A=%i e B=%i S�O M�LTIPLOS!!!", A, B);
		return	(0);
	}
	else
	{
		printf	("\n\nOs valores de A=%i e B=%i N�O S�O M�LTIPLOS!!!", A, B);
		return	(0);
	}
}

