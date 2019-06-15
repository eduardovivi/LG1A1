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
variável do tipo inteiro = strcmp(string1, string2);
strcmp -------> compara o conteúdo de duas strings;
Possíveis valores de retorno:
0  : conteúdo das strings são iguais
< 0: conteúdo da string1 é menor do que string2
> 0: conteúdo da string1 é maior do que string2
*/

/* VARIÁVEIS GLOBAIS */
char    palavra  [20+1]; /* vetor de palavra */
char    resposta [20+1]; /* vetor de resposta digitada pelo jogador */

/* CONSTRUÇÃO DAS FUNÇÕES */

void     captura_palavras      (void)
{   /* CAPTURA OS DADOS: no caso, as palavras */
    printf ("\nDigite uma palavra para teste: ");
    fflush (stdin);
    gets (palavra);
    _strupr(palavra); /* PASSA PARA MAIÚSCULA */
    
    printf ("\nDigite a palavra de resposta: ");
    fflush (stdin);
    gets (resposta);  
    _strupr(resposta); /* PASSA PARA MAIÚSCULA */    
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
