/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Tipos pr?-definidos (defini??o dos registros) */
typedef  struct
{
    float    valor_premio;
}
reg_premio;

/* Prot?tipos de fun??es */
void    cadastra_premios(void);
void    consulta_premios(void);
void    deleta_registro(void);
void    admin (void);

/* Constru??o das fun??es */
void    cadastra_premios(void)
{
    FILE        * Arqpremio;
    reg_premio  valor_do_premio;
    char        resposta;
    /* captura e valida o valor do pr?mio */
    do
    {
        system ("cls");
        printf ("\n=========== CADASTRO DE PREMIOS =============");
        printf ("\n            Valor do premio: R$ ");
        fflush (stdin); 
        scanf ("%f", &valor_do_premio.valor_premio);
    }
    while ( valor_do_premio.valor_premio < 0 || 
            valor_do_premio.valor_premio > 1000 );
            
    /* Verifica se ? para gravar ou n?o */
    printf ("\n ================================================");
    printf ("\n Deseja gravar este premio? [n/N = nao]");
    fflush (stdin); resposta = getche();
    /* se deseja gravar... (resposta != n?o) */    
    if ( resposta != 'n' && resposta != 'N' ) /* ... para gravar */
    {
        /* Abro o arquivo */
        Arqpremio = fopen ( "PREMIOS.DAT" , "a" ); 
        /* Grava dados no arquivo */
        fwrite ( &valor_do_premio, sizeof(valor_do_premio), 1, Arqpremio );
        /* Fecha o arquivo */
        fclose ( Arqpremio );
    }
}

void    consulta_premios(void)
{   FILE        * Arqpremio;
    reg_premio  valor_do_premio;
    int         numero_registro=0;
    system ("cls");
    printf ("\n============== PREMIOS CADASTRADOS ==============");
    printf ("\n                Valor em R$");
    printf ("\n ================================================");
    /* Abrir o arquivo */
    Arqpremio = fopen ( "PREMIOS.DAT" , "r" ); 
    /* testar se a abertura do arquivo foi BEM  SUCEDIDA */
    if ( Arqpremio == NULL ) /* NULL = 0000:0000 */
    {
        system ("cls");
        printf ("ERRO AO ABRIR O ARQUIVO! \n IMPOSSIVEL FAZER CONSULTA!");
        getch();
        exit(0);
    }
    /* Enquanto n?o chegar no fim do arquivo...*/
    while ( !feof(Arqpremio) )
    {
        /*...L?... e...*/
        fread ( &valor_do_premio, sizeof(valor_do_premio), 1, Arqpremio );
        /*... mostra o registro lido na tela ...*/
        if ( !feof(Arqpremio) )  /*...se n?o for o fim de arquivo */
        {
            numero_registro++;
            printf ("\n\t\t%i\tR$ %7.2f", numero_registro, valor_do_premio.valor_premio ); 
        }
    }
    /* Fecha o arquivo */
    fclose ( Arqpremio );
    /* aguarda pressionar uma tecla */
    printf ("\n ================================================");
    getch();
}

void    deleta_registro(void)
{
    FILE        * Arqpremio;
    FILE        * Arqtemp;
    reg_premio  valor_do_premio;
    int         numero_registro=0;
    int         registro_a_deletar;
    system ("cls");
    printf ("\n============== PREMIOS CADASTRADOS ==============");
    printf ("\n                Valor em R$");
    printf ("\n ================================================");
    /* Abrir o arquivo */
    Arqpremio = fopen ( "PREMIOS.DAT" , "r" ); 
    /* testar se a abertura do arquivo foi BEM  SUCEDIDA */
    if ( Arqpremio == NULL ) /* NULL = 0000:0000 */
    {
        system ("cls");
        printf ("ERRO AO ABRIR O ARQUIVO! \n IMPOSSIVEL FAZER CONSULTA!");
        getch();
        exit(0);
    }
    /* Enquanto n?o chegar no fim do arquivo...*/
    while ( !feof(Arqpremio) )
    {
        /*...L?... e...*/
        fread ( &valor_do_premio, sizeof(valor_do_premio), 1, Arqpremio );
        /*... mostra o registro lido na tela ...*/
        if ( !feof(Arqpremio) )  /*...se n?o for o fim de arquivo */
        {
            numero_registro++;
            printf ("\n\t\t%i\tR$ %7.2f", numero_registro, valor_do_premio.valor_premio ); 
        }
    }
    /* Fecha o arquivo */
    fclose ( Arqpremio );
    /* Captura o n?mero do registro que ser? deletado */
    do
    {
        printf ("\n ================================================");
        printf ("\n Qual o numero do registro que sera deletado? ");
        fflush (stdin);     scanf  ("%i", &registro_a_deletar);
    }
    while ( registro_a_deletar < 1 || registro_a_deletar > numero_registro );
    /* Abre o arquivo .DAT */
    Arqpremio = fopen ( "PREMIOS.DAT" , "r" ); 
    if ( Arqpremio == NULL ) /* NULL = 0000:0000 */
    {
        printf ("\n\nERRO AO ABRIR PREMIOS.DAT PARA DELETAR!");
        getch();
        exit(0);
    }
    /* Cria o arquivo .TMP */
    Arqtemp = fopen ( "PREMIOS.TMP" , "w" ); 
    if ( Arqpremio == NULL ) /* NULL = 0000:0000 */
    {
        printf ("\n\nERRO AO CRIAR PREMIOS.TMP!");
        getch();
        exit(0);
    }
    numero_registro=0;
    /* Enquanto n?o chegar no fim do arquivo .DAT ...*/
    while ( !feof(Arqpremio) )
    {
        /*...L? o .DAT e...*/
        fread ( &valor_do_premio, sizeof(valor_do_premio), 1, Arqpremio );
        /*... Verifica se j? ? o registro a ser deletado ... */
        if ( !feof(Arqpremio) )  /*...se n?o for o fim de arquivo .DAT */
        {
            numero_registro++; /* contabiliza o registro lido */
            /* se o lido for diferente do delet?vel...*/
            if ( registro_a_deletar != numero_registro )
            {
                fwrite ( &valor_do_premio, sizeof(valor_do_premio), 1, Arqtemp );
            }
        }
    }
    /* Fecha os dois arquivos (.DAT e .TMP) */
    fclose ( Arqpremio );
    fclose ( Arqtemp );
    /* Deleta o .DAT */
    system ("DEL  PREMIOS.DAT");
    /* Renomeia o .TMP para .DAT */
    system ("REN  PREMIOS.TMP PREMIOS.DAT");
    /* Avisa que a dele??o foi conclu?da */
    printf ("\n ================================================");
    printf ("\n Registro %i removido com sucesso!", registro_a_deletar );
    printf ("\n ================================================");
    getch();    
}

void    admin (void)
{   
  char  opc;
  do
  {
    /* Captura a op??o desejada */
    do
    {   system ("cls");
        printf ("\n=========== MENU DE GERENCIAMENTO DOS PREMIOS ==============");
        printf ("\n                    1. cadastro");
        printf ("\n                    2. consulta");
        printf ("\n                    3. relatorio");
        printf ("\n                    4. excluir registro");
        printf ("\n                    S. SAIR");    
        printf ("\n============================================================");
        printf ("\n                Escolha: "); fflush(stdin); opc = getche();
    }
    while ( opc != '1' && opc != '2' && opc != '3' && opc != '4' &&
            opc != 's' && opc != 'S' );
    /* dependendo da op??o, faz uma das opera??es */
    switch ( opc )
    {
        case '1' : cadastra_premios(); break;
        case '2' : consulta_premios(); break;
        case '3' : printf ("\nrelatorio de premios"); break;
        case '4' : deleta_registro(); break;
        case 's' : 
        case 'S' : exit(0); break;        
    }    
  }
  while ( opc != 's' && opc != 'S'); /* volta para o menu quando se escolhe s/S */
}

/* CORPO DO PROGRAMA */
main ()
{
    admin();
}

