/* BIBLIOTECAS */
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h> /* para poder usar gets */
#include <time.h>   /* para poder usar srand */

/* VARIÁVEIS GLOBAIS */
char    palavra[20+1]; /* vetor de palavra */
char    auxiliar[20+1]; /* vetor auxiliar   */
int     indice;
int     premio;
int     certos=0;
char    letra;
int     grana = 0;
int     contatracinhos=0;

/* CONSTRUÇÃO DAS FUNÇÕES */
void   fornece_palavra (void)
{
    int  i; /* índice i local para usar no vetor auxiliar */
    printf ("\nDigite a palavra para teste: ");
    fflush (stdin);
    gets(palavra);
    _strupr(palavra); /* PASSA PARA MAIÚSCULA */
    
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
lÓGICA DO PREENCHIMENTO DO VETOR auxiliar:
    1. verificar se a letra digitada está no vetor palavras
    2. se estiver
            2.1. verificar se aquela posição do vetor auxiliar já tem tracinho
            2.2. se tiver tracinho, coloca a letra achada
            2.3. se tiver outra coisa, não coloca nada (mantém o que já está)
    3. até o final da palavra ('\0')
    
LÓGICA PARA DETECTAR QUE É PARA PARA DE PEDIR LETRAS:
    1. Contar quantos tracinhos há no vetor auxiliar
    2. Se tiver 3 ou menos, é para pedir para digitar a palavra completa
*/
void jogar (void)
{ 
    do
    {   /* SORTEAR O VALOR DO PRÊMIO */
        srand(time(NULL)); /* Garante que os números sorteados não se repitam */
        premio = rand() % 1001; /* sorteia um prêmio entre zero e 1000*/
        printf ("\n\nValendo R$ %i,00 --> forneça uma letra: ", premio); 
        fflush (stdin);
        letra = getche(); 
    
        /* PROCURA A LETRA DENTRO DO VETOR */
        certos=0;
        printf ("\n\n");
        for ( indice=0  ;  palavra[indice] != '\0'   ;  indice++   )    
        {   /* ver se a letra digitada é a que está na posição do vetor*/
            if ( letra == palavra[indice] ) 
            {
                printf ( "%c", letra );
                certos++;
            }
            else /* se não acha a letra, mostra um tracinho */
                printf (" _");
        }
        
        if ( certos > 0 )
        {  grana = grana + certos*premio;
           printf ("\n\nPrêmio acumulado = R$ %i,00", grana );
        }
        else
           printf ("\n\nPERDEU A VEZ, pois a letra %c NÃO faz parte da palavra", letra);
        getch();
    }
    while ( certos!=0 );/* até a pessoa ERRAR (certos=0) */
}

/* CORPO DO PROGRAMA */
main()
{    
    fornece_palavra ();        
    jogar();    
}
