#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//STRUCTS//

typedef struct{
	char pista[17];
	int qtd;
	char vetpalavras[3][17];
} 
cadastro;

typedef struct{
	float premio[12];
}
premios;

//VARIÁVEIS GLOBAIS//

cadastro cdstr;
premios valor;
char opcao;


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
	
	FILE *arq;
	
	arq = fopen ("premios.dat", "a"); // Abre um arquivo texto para gravação e leitura. 
								   	   // Os dados serão adicionados no fim do arquivo se ele já existir, 
									   // ou um novo arquivo será criado, no caso de arquivo não existente anteriormente.
	if (arq == NULL){ // caso o arquivo dê erro
		system("cls");
		printf("Ocorreu um erro ao gravar dados no arquivo PALAVRAS.DAT");
	}
		else{
			fwrite(&valor, sizeof(valor), 1, arq);
	}
	fclose(arq);
}

void capturaPremios (void){
	
	
	system("cls");
	printf("===============================================\n");
	printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
	printf("===============================================\n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("	    3. Gravar Premios			\n");
	printf("  	   								     	   \n");
	printf("===============================================\n\n");
	printf("VOCE ESCOLHEU A OPCAO DE GRAVAR PREMIOS!   \n");
	printf("Pressione ENTER para continuar.");
	getch();
	system("cls");
	
	int i;
	printf("===============================================\n");				
	printf("	   CADASTRO DE PREMIOS      		       \n");
	printf("===============================================\n"); 
	
	for (i=0; i<10; i++){
		printf("Digite o valor do %do premio: ", i + 1);
		scanf("%f", &valor.premio[i]);
		fflush(stdin);
	}
	
	gravaPremios();
	
	
	printf("\n\nPressione ENTER para voltar ao MENU PRINCIPAL.");
	getch();

	
	
}

void consultaPremios (void){
	int i;
	
	system("cls");
	printf("===============================================\n");
	printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
	printf("===============================================\n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("	    4. Consultar Premios			\n");
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
				while(!feof(arq)){ // Enquanto não houver o término do arquivo 
					fread(&valor, sizeof(valor), 1, arq); // É lido todo o arquivo
						if(!feof(arq)){	// se não houver o término do arquivo, faça:
							for(i=0;i<10;i++){ //COLOQUEI ATÉ 10 POIS SÃO ARMAZENADOS 10 PRÊMIOS PELO USUÁRIO E +2 PREDEFINIDOS COMO
											   //OS VALORES DE PASSA A VEZ E PERDE TUDO
								printf("\nPREMIO %d:[R$ %.2f]", i, valor.premio[i]); 
							}
							
						}
				}		
			}
		fclose(arq);
		printf("\n\nPressione ENTER para voltar ao MENU PRINCIPAL.");
		getch();
		
}


void admin (void){
	
	system("cls");
	
	do{
		printf("===============================================\n");
		printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
		printf("===============================================\n");
		printf("  	    1. Cadastrar Palavras		\n");
		printf("	    2. Consultar Palavras		\n");
		printf("	    3. Gravar Premios			\n");
		printf("	    4. Consultar Premios		\n");
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
				capturaPremios();
			}
		break;
		
		case '4':
			{
				consultaPremios();
			}
		break;
		
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
	do{
		admin();
	} while (opcao != 'S' && opcao != 's');
}
