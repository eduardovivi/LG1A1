#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

float	A, B, C;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 8");
	
	printf	("\n\nDigite 3 n�meros, A, B e C\nPrimeiro o valor de A: ");
	scanf	("%f", &A);
	printf	("\n\nAgora o valor de B: ");
	scanf	("%f", &B);
	printf	("\n\nE por fim o valor de C: ");
	scanf	("%f", &C);
	printf	("\n\nVou processar aqui e quando voc� digitar qualquer tecla, vou lhe mostrar o maior entre eles...");
	getch	();
	
	if	(A==B || A==C || B==C)
	{
		printf	("\n\nN�o foi poss�vel decidir qual deles � o maior, pois voc� digitou valores iguais para alguns deles");
	}
	if	(A>B && A>C)
	{
		printf	("\n\nA=%.0f � o maior entre eles!!!", A);
		return	(0);
	}
	
	if	(B>A && B>C)
	{
		printf	("\n\nB=%.0f � o maior entre eles!!!", B);	
		return	(0);
	}
	
	if	(C>A && C>A)
	{
		printf	("\n\nC=%.0f � o maior entre eles!!!", C);
		return	(0);
	}
	
}

