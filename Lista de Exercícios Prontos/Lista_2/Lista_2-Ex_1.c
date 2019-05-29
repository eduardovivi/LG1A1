/* Este programa detecta a situação de um aluno ao final de LG1-A1 */

/* Bibliotecas */
#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Acentos */
#include	<math.h>
/* Variáveis de memória */
/* tipo_de_dado (natureza: inteiro, real, alfanumérico    nome_da_variável */
int	Faltas;
float	P1, P2, PJ, Media;

/* CORPO DO PROGRAMA */
int main()
{
	setlocale	(LC_ALL,	"");
	
	printf	("\n\nDigite o total de faltas: ");
	scanf	("%i"	,	&Faltas);
	
	/* Decisão se o aluno já está RETIDO POR FALTAS */
	if	( Faltas > 23 )
	{
	
		printf ("\n\n\t\tALUNO RETIDO POR FALTAS!!!"); /* Aviso o aluno */
		getch();    /* Aguarda o pressionar de alguma tecla qualquer */
		exit(0);	/* Fecha o programa */
	}
	
	else	/* Captura as notas; calcula a média e informa a situação do aluno */
	{
		printf	("\n\n\t\tDigite nota de P1:");
		scanf	("%f"	,	&P1);
		
		printf	("\n\n\t\tDigite nota de P2:");
		scanf	("%f"	,	&P2);

		printf	("\n\n\t\tDigite nota de PJ:");
		scanf	("%f"	,	&PJ);

		if	(PJ > 10)
		
			printf	("\n\n\t\tValor invalido!!!	Insira um valor até 10.");
		
		
		/* Calcula a média do aluno*/
		Media = (P1 + P2 + PJ)/3;
		
		/* Mostra a média do aluno */
		printf	("\n\n\t\tSua nota final foi: %.1f e suas faltas foram: %i"	, Media, Faltas);
				
		if	(Media >= 7)	/* Verifica a situação final do aluno */
		
			printf	("\n\n\t\tALUNO APROVADO!!!");
		
		else
		
			if	(Media < 5)
			
				printf	("\n\n\t\tALUNO REPROVADO!!!");
			
			else
			/* ou colocar isso --> if	(Media >= 4	&&	Media < 6)*/
			
				printf	("\n\n\t\tALUNO EM EXAME!!! ele precisa, no mínimo, de 6,0 para passar.");
			
			getch();	/* Aguarda teclar qualquer tecla */
	}
}

