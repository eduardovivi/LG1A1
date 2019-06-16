#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

//STRUCTS//


typedef struct{
	char pista[17];
	int qtd;
	char vetpalavras[3][17];
} 
cadastro;

//VARIÁVEIS GLOBAIS//

cadastro cdstr;
char opcao;
float premios[] = {100, 900, 600, 1000, 0, 400, 200, 800, 0.01, 300, 500, 700};

// VARIAVEIS DO JOGO //
char palavra[10];
char palavratotal[10];
int i;
char letra;
float acumulado = 0;
int premioale;
int acertos = 0;



void gravaDados (void){
	
	FILE *arq;
	
	arq = fopen ("palavras.dat", "a"); // Abre um arquivo texto para gravação e leitura. 
								   	   // Os dados serão adicionados no fim do arquivo se ele já existir, 
									   // ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
	if (arq == NULL){ // caso o arquivo dê erro
		system("cls");
		printf("Ocorreu um erro ao gravar dados no arquivo PALAVRAS.DAT");
	}
		else{
			fwrite(&cdstr, sizeof(cdstr), 1, arq);
	}
	fclose(arq);
}

void consultaPalavras (void){

	system("cls");
	printf("===============================================\n");
	printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
	printf("===============================================\n");
	printf("  	   								     	   \n");
	printf("	    2. Consultar Palavras		\n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("===============================================\n\n");
	printf("VOCE ESCOLHEU A OPCAO DE CONSULTAR PALAVRAS!   \n");
	printf("Pressione ENTER para continuar.");
	getch();
	system("cls");
	
	printf("===============================================\n");				
	printf("	   BANCO DE DADOS DE PALAVRAS		       \n");
	printf("===============================================\n"); 
	FILE * arq; 
	
	arq = fopen ("palavras.dat", "r");
	
	if (arq == NULL){
		system("cls");
		printf("Ocorreu um erro ao ler o arquivo PALAVRAS.DAT");
	}
		else{
			while(!feof(arq)){ // Enquanto não houver o término do arquivo 
				fread(&cdstr, sizeof(cdstr), 1, arq); // É lido todo o arquivo
					if(!feof(arq)){	// se não houver o término do arquivo, faça:
						printf("\nPISTA:[%16s]", cdstr.pista);
						printf("   QTD:[%2d]", cdstr.qtd);
						printf("	   PALAVRAS:[%16s] [%16s] [%16s]", cdstr.vetpalavras[0], cdstr.vetpalavras[1], cdstr.vetpalavras[2]);
						
					}
			}		
		}
	printf("\n\nPressione ENTER para voltar ao MENU PRINCIPAL.");
	getch();
}

void capturaDados (void){
	
	system("cls");
	
	printf("===============================================\n");
	printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
	printf("===============================================\n");
	printf("  	    1. Cadastrar Palavras		\n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("===============================================\n\n");
	printf("VOCE ESCOLHEU A OPCAO DE CADASTRO!\n");
	printf("Pressione ENTER para continuar.");
	getch();
	
	system ("cls");
	
	int i;
	
	printf("===============================================\n");
	printf("	   CADASTRO DE PALAVRAS     		       \n");
	printf("===============================================\n");
	printf("Digite a pista da(s) palavra(s): ");
	fflush(stdin);
	gets(cdstr.pista);
	
	printf("\nInforme a quantidade de palavras a serem cadastradas: ");
	scanf("%d", &cdstr.qtd);
	fflush(stdin);
	
	for (i=0; i<cdstr.qtd; i++){
		printf("Digite a %da palavra: ", i + 1);
		gets(cdstr.vetpalavras[i]);
	}
	
	gravaDados();
	
	getch();
}

void gravaPremios (void){
	
	int i;
	FILE *arq;
	
	arq = fopen ("premios.dat", "w"); // Cria um premios.dat toda vez que uma consulta é realizada para que não haja repetição dos prêmios
								   	   
	if (arq == NULL){ // caso o arquivo dê erro
		system("cls");
		printf("Ocorreu um erro ao gravar dados no arquivo PALAVRAS.DAT");
	}
		else{
				fwrite(&premios, sizeof(premios), 1, arq);
			}
	
	fclose(arq);
}

void consultaPremios (void){
	int i;
	
	system("cls");
	printf("===============================================\n");
	printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
	printf("===============================================\n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("	    3. Consultar Premios(SÓ PRA TESTAR)		\n");
	printf("  	   								     	   \n");
	printf("===============================================\n\n");
	printf("VOCE ESCOLHEU A OPCAO DE CONSULTAR PREMIOS!   \n");
	printf("Pressione ENTER para continuar.");
	getch();
	system("cls");
	
	printf("===============================================\n");				
	printf("	   BANCO DE PREMIOS      		           \n"); 
	printf("===============================================\n");
	
	FILE * arq; 
		
	arq = fopen ("premios.dat", "r");
	
	if (arq == NULL){
		system("cls");
		printf("Ocorreu um erro ao ler o arquivo PREMIOS.DAT");
	}
		else{
			fread(&premios, sizeof(premios), 1, arq); 
					for(i=0;i<10;i++){ 
						printf("\nPREMIO %d:[R$ %.2f]", i + 1, premios[i]); 
					}					
		}		
			
	fclose(arq);
	printf("\n\nPressione ENTER para voltar ao MENU PRINCIPAL.");
	getch();
		
}

void jogar (void){
	
	system("cls");
	printf("Digite uma palavra: ");
	gets(palavra);
	fflush(stdin);
	strupr(palavra);
	
	
	srand(time(NULL));
	
	for (i=0; palavra[i] != '\0'; i++){
		printf("_ ");
	}


	do{
		setlocale(LC_ALL, "Portuguese");
		premioale = rand() % 100;
		printf("\nValendo R$%d.00 por letra.", premioale);
		
		printf("\nDigite uma letra: ");
		scanf("%c", &letra);
		
		letra = toupper(letra);
		
		fflush(stdin);
		
		acertos = 0;
		for (i=0; palavra[i] != '\0'; i++){
			
			if (palavra[i] == letra){
				printf(" %c", letra);
				palavratotal[i] = letra;
				acumulado = acumulado + premioale;
				acertos++;
			}
				else if (palavratotal[i] == palavra[i]){
					printf(" %c", palavratotal[i]);
				}
					else{
						printf(" _");
					}
		}
		
		if ( acertos>0){  
           printf ("\n\nPrêmio acumulado = R$ %.2f", acumulado);
        }
        	else{
          	 printf ("\n\nVocê PERDEU A VEZ, pois a letra informa '%c' NÃO faz parte da palavra", letra);
          	}
          	
	    getch();
	    
	}
		while (strcmp (palavra, palavratotal) && acertos!=0 );
		
}
void admin (void){
	
	system("cls");
	
	do{
		system("cls");
		printf("===============================================\n");
		printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
		printf("===============================================\n");
		printf("  	    1. Cadastrar Palavras		\n");
		printf("	    2. Consultar Palavras		\n");
		printf("	    3. Consultar Premios(SÓ PRA TESTAR)		\n");
		printf("	    4. JOGAR		\n");
		printf("	    S. Sair						\n");
		printf("===============================================\n\n");
		printf("Escolha uma opcao: ");
		opcao = getch();
			
	} while(opcao != 's' && opcao != 'S' && opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4');
	
	switch(opcao){
		
		case '1':
		{
			capturaDados();
		}
		break;
		
		case '2':
		{
			consultaPalavras();
		}
		break;
		
		case '3':
			{
				gravaPremios();
				consultaPremios();
			}
		break;
		
		case '4':
			{
				jogar();
			}
		
		case 'S':
		{
			printf("\nVoce decidiu SAIR. O jogo foi encerrado.");
			exit (0);
		}
		break;
		
		case 's':
		{
			printf("\nVoce decidiu SAIR. O jogo foi encerrado.");
			exit (0);
		}
		break;	
	}
}

main(){

	setlocale(LC_ALL, "Portuguese");
	
	do{
		admin();
	} while (opcao != 'S' && opcao != 's');
	
}
