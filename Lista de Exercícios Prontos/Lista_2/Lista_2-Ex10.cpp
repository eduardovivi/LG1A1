#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

int	i;
float	A, B, C;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 10");
	
	printf	("\n\nDigite 3 números reais, A, B e C");
	printf	("\n\nPrimeiro o valor de A: ");
	scanf	("%f", &A);
	
	printf	("\n\nDigite agora o valor de B: ");
	scanf	("%f", &B);
	
	printf	("\n\nDigite agora o valor de C: ");
	scanf	("%f", &C);
	
	printf	("\n\nAgora digite 1 ou 2 para o valor de i onde: ");
	printf	("\n\n**i=1 --> para mostrar A, B e C em ORDEM CRESCENTE;");
	printf	("\n**i=2 --> para mostrar A, B e C em ORDEM DECRESCENTE.\n\n\ti=");
	scanf	("%i", &i);
	
	if	(i != 1 && i != 2)
	{
		printf	("\n\nEU NÃO DISSE PRA DIGITAR %i!!!/nTente outra vez!", i);
		return	(0);
	}
	if	(i==2)
	{	
		if	(A>B && A>C)
		{
			if	(B>C)
			{
				printf	("\n\nORDEM DECRESCENTE\n\n\t%.0f > %.0f > %.0f", A, B, C);
				return	(0);
			}
			else
			{
				printf	("\n\nORDEM DECRESCENTE\n\n\t%.0f > %.0f > %.0f", A, C, B);
				return	(0);
			}
		}
		
		if	(B>A && B>C)
		{
			if	(A>C)
			{
				printf	("\n\nORDEM DECRESCENTE\n\n\t%.0f > %.0f > %.0f", B, A, C);
				return	(0);
			}
			else
			{
				printf	("\n\nORDEM DECRESCENTE\n\n\t%.0f > %.0f > %.0f", B, C, A);
				return	(0);
			}
		}
		
		if	(C>A && C>B)
		{
			if	(B>A)
			{
				printf	("\n\nORDEM DECRESCENTE\n\n\t%.0f > %.0f > %.0f", C, B, A);
				return	(0);
			}
			else
			{
				printf	("\n\nORDEM DECRESCENTE\n\n\t%.0f > %.0f > %.0f", C, A, B);
				return	(0);
			}
		}
	}
	
	if	(i==1)
	{	
		if	(A>B && A>C)
		{
			if	(B>C)
			{
				printf	("\n\nORDEM CRESCENTE\n\n\t%.0f < %.0f < %.0f", C, B, A);
				return	(0);
			}
			else
			{
				printf	("\n\nORDEM CRESCENTE\n\n\t%.0f < %.0f < %.0f", B, C, A);
				return	(0);
			}
		}
		
		if	(B>A && B>C)
		{
			if	(A>C)
			{
				printf	("\n\nORDEM CRESCENTE\n\n\t%.0f < %.0f < %.0f", C, A, B);
				return	(0);
			}
			else
			{
				printf	("\n\nORDEM CRESCENTE\n\n\t%.0f < %.0f < %.0f", A, C, B);
				return	(0);
			}
		}
		
		if	(C>A && C>B)
		{
			if	(B>A)
			{
				printf	("\n\nORDEM CRESCENTE\n\n\t%.0f < %.0f < %.0f", A, B, C);
				return	(0);
			}
			else
			{
				printf	("\n\nORDEM CRESCENTE\n\n\t%.0f < %.0f < %.0f", B, A, C);
				return	(0);
			}
		}
	}
	getch	();
}

