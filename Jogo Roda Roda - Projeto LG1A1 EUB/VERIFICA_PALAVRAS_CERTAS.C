/* Dicas: https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html
          http://linguagemc.com.br/a-biblioteca-string-h/
*/

/* BIBLIOTECAS */
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h> /* para poder usar gets; strcmp */

/*
vari�vel do tipo inteiro = strcmp(string1, string2);
strcmp -------> compara o conte�do de duas strings;
Poss�veis valores de retorno:
0  : conte�do das strings s�o iguais
< 0: conte�do da string1 � menor do que string2
> 0: conte�do da string1 � maior do que string2
*/

/* VARI�VEIS GLOBAIS */
char    palavra  [20+1]; /* vetor de palavra */
char    resposta [20+1]; /* vetor de resposta digitada pelo jogador */

/* CONSTRU��O DAS FUN��ES */

void     captura_palavras      (void)
{   /* CAPTURA OS DADOS: no caso, as palavras */
    printf ("\nDigite uma palavra para teste: ");
    fflush (stdin);
    gets (palavra);
    _strupr(palavra); /* PASSA PARA MAI�SCULA */
    
    printf ("\nDigite a palavra de resposta: ");
    fflush (stdin);
    gets (resposta);  
    _strupr(resposta); /* PASSA PARA MAI�SCULA */    
}


void     ver_se_palavra_certa (void)
{    
    if ( strcmp( resposta, palavra) == 0 )
          printf ("\n\t\tACERTOU!\a\a\a\a");
    else
          printf ("\n\t\tERROU!!!!!!!!!!!!");     
    getch();
}


/* CORPO DO PROGRAMA */
main()
{   
    captura_palavras();
    ver_se_palavra_certa();        
}
