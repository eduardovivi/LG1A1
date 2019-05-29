#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

float	A, B, resul;
char	oper;

int main	()
{
	setlocale	(LC_ALL,	"");
	printf	("\nLista 2\nEx. 7");

	printf	("\n\nDigite um número real para o valor de A: ");
	scanf	("%f", &A);
	printf	("\n\nDigite um número real para o valor de B: ");
	scanf	("%f", &B);
	printf	("\n\nDigite:\n\n+ --> soma\n- --> subtração");
	printf	("\n* --> multiplicação\n/ --> divisão\n\n");
	fflush	(stdin);
	scanf	("%c", &oper);
	
	if	(oper == '+')
		{
			resul = A + B;
			printf	("A + B = %.1f + %.1f = %.1f", A, B, resul);
		}
		else
		{
			if	(oper == '-')
			{
				resul = A - B;
				printf	("A - B = %.1f - %.1f = %.1f", A, B, resul);
			}
			else
			{
				if	(oper == '*')
				{
					resul = A * B;
					printf	("A * B = %.1f * %.1f = %.2f", A, B, resul);
				}
				else
				{
					resul = A / B;
					printf	("A / B = %.1f / %.1f = %.3f", A, B, resul);
				}
			}
		}
}

