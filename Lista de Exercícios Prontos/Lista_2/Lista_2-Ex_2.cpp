/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para cálculos matemáticos */

/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico)    nome_da_variável */

char	sexo;
float	altura, peso_ideal, peso_real,	dif; /*h=altura	P=peso*/

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\nOlá! Minha função aqui é calcular se você está com o seu peso ideal.");
	getch	();
	printf	("\n\nPara isso preciso de alguns dados seus, ok?");
	getch	();
	printf	("\n\nPrimeiro, preciso saber se você é homem ou mulher.");
	getch	();
	printf	("\n\nDigite M (para mulher) ou H (para homem):");
	scanf	("%c",	&sexo);
	printf	("\nOk.\n\nAgora digite a sua altura em metros:");
	scanf	("%f",	&altura);
	printf	("\nAgora digite o seu peso, em kg:");
	scanf	("%f",	&peso_real);
	printf	("\n...péra, estou processando... ");
	getch	();
	
	if	(sexo == 'M'	||	sexo == 'm')
	{
		peso_ideal=(62.1*altura)-44.7;
		printf("\n\nVocê é MULHER e o seu peso ideal é: %.2f kg", peso_ideal);
		
		if	(peso_real >= peso_ideal)
		{
			
			dif = peso_real - peso_ideal;
			printf("\n\n...e você está %.2fkg ACIMA de seu peso ideal!\n\nFaça atividade física SEMPRE!!!", dif);
		
		}
		else
			{
		
				dif = peso_ideal - peso_real;
				printf("\n\n...e você está %.2fkg ABAIXO de seu peso ideal!\n\nFaça atividade física SEMPRE!!!", dif);
			}
	}
	
	if	(sexo == 'H'	||	sexo == 'h')
	{	
	
		peso_ideal=(72.7*altura)-58;
		printf("\n\nVocê é HOMEM e seu peso ideal é: %.2f kg", peso_ideal);
		
		if	(peso_real >= peso_ideal)
		{
			
			dif = peso_real - peso_ideal;
			printf("\n\n...e você está %.2fkg ACIMA de seu peso ideal!\n\nFaça atividade física SEMPRE!!!", dif);
		
		}
		else
			{
		
				dif = peso_ideal - peso_real;
				printf("\n\n...e você está %.2fkg ABAIXO de seu peso ideal!\n\nFaça atividade física SEMPRE!!!", dif);
			}
		
	}
	
	getch	();
}
