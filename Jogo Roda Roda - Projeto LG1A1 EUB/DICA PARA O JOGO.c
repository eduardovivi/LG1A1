// BIBLIOTECAS    
#include <stdio.h>      // manipular arquivos 
#include <conio.h>      // habilita uso do getch
#include <locale.h>     // acentua??o
#include <stdlib.h>     // habilita uso do system
#include <string.h>     // para trabalhar com strings (uso da fun??o gets)
#include <time.h>       // PARA USAR srand e time (NULL)
/* TIPOS PR?-DEFINIDOS PELO PROGRAMADOR */
typedef    struct
{
    char   pista[17];
    int    qtd;   /* linha coluna */
    char   vetpalavras[3][17]; /*3 linhas por 17 colunas*/
}
registro; /* registro = tipo de dado rec?m-criado */

/* VARI?VEIS GLOBAIS */ 
registro    reg; /* reg = vari?vel do tipo registro */
char        escolha;
int         totalregs=0, num;

/* CRIA??O DAS FUN??ES */
void   menu (void)
{
  do
  {
    system ("cls");
    printf ("\n--------- M E N U ----------");
    printf ("\n    1. Cadastra palavras    ");
    printf ("\n    2. Consulta palavras    ");
    printf ("\n    3. JOGAR                ");
    printf ("\n    S. SAIR                 ");
    printf ("\n----------------------------");
    printf ("\n    Escolha: ");
    fflush (stdin); 
    escolha = getche ();
  }
  while ( escolha != '1' && escolha != '2' && escolha != '3' &&
          escolha != 'S' && escolha != 's');
}

void captura_dados ( void )
{
    int    indice;
    system ("cls");
    printf ("\n=========== CADASTRO DE PALAVRAS ===============");
    printf ("\nPISTA: ");
    fflush (stdin);
    gets(reg.pista);

    do 
    {  printf ("\n\nQUANTIDADE DE PALAVRAS: ");
       fflush (stdin);
       scanf  ("%i" , &reg.qtd);
    }
    while ( !(reg.qtd>=1 && reg.qtd<=3) );
    
    for ( indice=0   ; indice<=reg.qtd-1     ; indice++   )
    {
        printf ("\n\n%ia. PALAVRA: ", indice+1);   
        fflush (stdin);
        gets (reg.vetpalavras[indice]);
    }
}

void  grava_dados ( void )
{
  FILE * Arq;
  Arq = fopen ( "PALAVRAS.DAT" , "a" );   /* abrir arquivo */
  fwrite ( &reg , sizeof(reg), 1, Arq);   /* grava no arquivo */
  fclose (Arq);                           /* fecha arquivo */
}

void  consulta ( void )
{
  FILE * Arq;
  
  Arq = fopen ( "PALAVRAS.DAT" , "r" );   /* abrir arquivo */
  while ( !feof(Arq) ) /* enquanto n?o for fim do arquivo...*/
  {
       fread ( &reg, sizeof(reg), 1, Arq); /*...l? e...*/
       if ( !feof(Arq) )
       {
          printf("\n[%16s] [%02d] [%16s] [%16s] [%16s]",  /*...mostra na tela*/
          reg.pista, reg.qtd, reg.vetpalavras[0], reg.vetpalavras[1], reg.vetpalavras[2]);
          
          totalregs++;
       }        
  }
  fclose (Arq);/* fecha arquivo */
}

void  cadastra ( void ) 
{
    captura_dados();
    grava_dados();
}

void   jogar (void)
{
  FILE * Arq;
  int  contaux=-1;
  printf ("\n\nTotal de registros = %i", totalregs);
  /* Sorteia um dos totalregs*/
  srand(time(NULL)); /* Garante que os n?meros sorteados n?o se repitam */
  num = rand() % totalregs;
  printf ("\n\nVai sortear o num = %i", num);
  Arq = fopen ( "PALAVRAS.DAT" , "r" );   /* abrir arquivo */
  while ( !feof(Arq) ) /* enquanto n?o for fim do arquivo...*/
  {
       fread ( &reg, sizeof(reg), 1, Arq); /*...l? e...*/
       if ( !feof(Arq) )       
       {
            contaux++;
            if (contaux == num) /* P?RA a LEITURA */
               break;
       }        
  }
  fclose (Arq);/* fecha arquivo */
  
  printf ("\nPISTA : %s", reg.pista);
  printf ("\ncom %i palavras", reg.qtd);
  getch();
}

void   admin ( void )
{    
    menu();  
    switch ( escolha )
    {
        case '1' : 
        {
            cadastra();
        }
        break;
        
        case '2' : 
        {
            consulta();
        }
        break;
        
        case '3' : 
        {
            jogar();
        }
        break;
        
        case 's' : 
        case 'S' : exit (0); break;
    }
    getch();    
}

/* CORPO DO PROGRAMA */
main()
{
  do
  {
      admin();
  }
  while (escolha != 'S' && escolha != 's');
}
















