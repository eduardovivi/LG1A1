/* BIBLIOTECAS */
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h> /* para poder usar gets */
#include <time.h>   /* para poder usar srand */

/* VARI�VEIS GLOBAIS */
char    palavra[20+1]; /* vetor de palavra */
char    auxiliar[20+1]; /* vetor auxiliar   */
int     indice;
int     premio;
int     certos=0;
char    letra;
int     grana = 0;
int     contatracinhos=0;

/* CONSTRU��O DAS FUN��ES */
void   fornece_palavra (void)
{
    int  i; /* �ndice i local para usar no vetor auxiliar */
    printf ("\nDigite a palavra para teste: ");
    fflush (stdin);
    gets(palavra);
    _strupr(palavra); /* PASSA PARA MAI�SCULA */
    
    /* preenche o vetor auxiliar (com tracinhos no lugar das letras) */
    for ( i=0; palavra[i] != '\0' ; i++ )
    {
       auxiliar[i] = '-';
    }
    auxiliar[i] = '\0';
    /* mostra os tracinhos */
    printf ("\n\n\n %s", auxiliar);
    getch();

    /* mostra a palavra */
    printf ("\n\nPalavra digitada: %s", palavra);
    getch();    
}
/*
l�GICA DO PREENCHIMENTO DO VETOR auxiliar:
    1. verificar se a letra digitada est� no vetor palavras
    2. se estiver
            2.1. verificar se aquela posi��o do vetor auxiliar j� tem tracinho
            2.2. se tiver tracinho, coloca a letra achada
            2.3. se tiver outra coisa, n�o coloca nada (mant�m o que j� est�)
    3. at� o final da palavra ('\0')
    
L�GICA PARA DETECTAR QUE � PARA PARA DE PEDIR LETRAS:
    1. Contar quantos tracinhos h� no vetor auxiliar
    2. Se tiver 3 ou menos, � para pedir para digitar a palavra completa
*/
void jogar (void)
{ 
    do
    {   /* SORTEAR O VALOR DO PR�MIO */
        srand(time(NULL)); /* Garante que os n�meros sorteados n�o se repitam */
        premio = rand() % 1001; /* sorteia um pr�mio entre zero e 1000*/
        printf ("\n\nValendo R$ %i,00 --> forne�a uma letra: ", premio); 
        fflush (stdin);
        letra = getche(); 
    
        /* PROCURA A LETRA DENTRO DO VETOR */
        certos=0;
        printf ("\n\n");
        for ( indice=0  ;  palavra[indice] != '\0'   ;  indice++   )    
        {   /* ver se a letra digitada � a que est� na posi��o do vetor*/
            if ( letra == palavra[indice] ) 
            {
                printf ( "%c", letra );
                certos++;
            }
            else /* se n�o acha a letra, mostra um tracinho */
                printf (" _");
        }
        
        if ( certos > 0 )
        {  grana = grana + certos*premio;
           printf ("\n\nPr�mio acumulado = R$ %i,00", grana );
        }
        else
           printf ("\n\nPERDEU A VEZ, pois a letra %c N�O faz parte da palavra", letra);
        getch();
    }
    while ( certos!=0 );/* at� a pessoa ERRAR (certos=0) */
}

/* CORPO DO PROGRAMA */
main()
{    
    fornece_palavra ();        
    jogar();    
}
