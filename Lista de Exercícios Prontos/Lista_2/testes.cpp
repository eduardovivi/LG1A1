#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>
#include	<locale.h>
#include	<math.h>

char palavra[256], m, i;

int main ()
{
	setlocale	(LC_ALL, "");
	printf("Informe a palavra: ");
	i = 0;
	fflush	(stdin);
	do
	{
		scanf("%c", &palavra[i]);i++;
	}
	while	(palavra[i-1] != '\n');
	m = i-1;
	printf("\n\nA palavra digitada foi: \n\n\t");
	
	for (i = 0; i < m; i++ )
	
		printf("%c", palavra[i]);
	
	printf("\n");
}
	
/*
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

printf("Informe a palavra: ");i = 0;do {scanf("%c", &palavra[i]);i++;} while(palavra[i-1] != ’\n’);m = i-1;

*/
