/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para c�lculos matem�ticos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico)    nome_da_vari�vel */

char	sexo;
float	altura, peso_ideal, peso_real,	dif; /*h=altura	P=peso*/

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\nOl�! Minha fun��o aqui � calcular se voc� est� com o seu peso ideal.");
	getch	();
	printf	("\n\nPara isso preciso de alguns dados seus, ok?");
	getch	();
	printf	("\n\nPrimeiro, preciso saber se voc� � homem ou mulher.");
	getch	();
	printf	("\n\nDigite M (para mulher) ou H (para homem):");
	scanf	("%c",	&sexo);
	printf	("\nOk.\n\nAgora digite a sua altura em metros:");
	scanf	("%f",	&altura);
	printf	("\nAgora digite o seu peso, em kg:");
	scanf	("%f",	&peso_real);
	printf	("\n...p�ra, estou processando... ");
	getch	();
	
	if	(sexo == 'M'	||	sexo == 'm')
	{
		peso_ideal=(62.1*altura)-44.7;
		printf("\n\nVoc� � MULHER e o seu peso ideal �: %.2f kg", peso_ideal);
		
		if	(peso_real >= peso_ideal)
		{
			
			dif = peso_real - peso_ideal;
			printf("\n\n...e voc� est� %.2fkg ACIMA de seu peso ideal!\n\nFa�a atividade f�sica SEMPRE!!!", dif);
		
		}
		else
			{
		
				dif = peso_ideal - peso_real;
				printf("\n\n...e voc� est� %.2fkg ABAIXO de seu peso ideal!\n\nFa�a atividade f�sica SEMPRE!!!", dif);
			}
	}
	
	if	(sexo == 'H'	||	sexo == 'h')
	{	
	
		peso_ideal=(72.7*altura)-58;
		printf("\n\nVoc� � HOMEM e seu peso ideal �: %.2f kg", peso_ideal);
		
		if	(peso_real >= peso_ideal)
		{
			
			dif = peso_real - peso_ideal;
			printf("\n\n...e voc� est� %.2fkg ACIMA de seu peso ideal!\n\nFa�a atividade f�sica SEMPRE!!!", dif);
		
		}
		else
			{
		
				dif = peso_ideal - peso_real;
				printf("\n\n...e voc� est� %.2fkg ABAIXO de seu peso ideal!\n\nFa�a atividade f�sica SEMPRE!!!", dif);
			}
		
	}
	
	getch	();
}
