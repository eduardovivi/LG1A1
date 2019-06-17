#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>


//STRUCTS//


typedef struct{
	char pista[17];
	int qtd;
	char vetpalavras[3][17];
} 
cadastro;

//VARIÁVEIS GLOBAIS//
int auxi = 0;
cadastro dicas[5];
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
int valor_aleatorio;
int valor_aleatorioP;
int jogador;
float premio_jogador[1];


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
	printf("	    2. Consultar Palavras				   \n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("===============================================\n\n");
	printf("VOCE ESCOLHEU A OPCAO DE CONSULTAR PALAVRAS!   \n");
	printf("Pressione qualquer tecla para continuar.");
	getch();
	
	system("cls");
	printf("===============================================\n");				
	printf("	   BANCO DE DADOS DE PALAVRAS		       \n");
	printf("===============================================\n"); 
	FILE * arq; 
	
	arq = fopen ("PALAVRAS.dat", "r");
	
	if (arq == NULL){
		system("cls");
		printf("Ocorreu um erro ao ler o arquivo PALAVRAS.dat");
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
	printf("\n\nPressione qualquer tecla para continuar.");
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
	printf("Pressione qualquer tecla para continuar.");
	getch();
	
	
	system ("cls");
	printf("===============================================\n");
	printf("	   CADASTRO DE PALAVRAS     		       \n");
	printf("===============================================\n");
	printf("Digite a pista da(s) palavra(s): ");
	fflush(stdin);
	gets(cdstr.pista);

	
	do 
	{  printf ("\n\nQUANTIDADE DE PALAVRAS: ");
	fflush (stdin);
	scanf  ("%i" , &cdstr.qtd);
	}
	while (!(cdstr.qtd>=1 && cdstr.qtd<=3));
	for ( i=0; i<=cdstr.qtd-1; i++)
	{
	printf ("\n\n%ia. PALAVRA: ", i+1);   
	fflush (stdin);
	gets (cdstr.vetpalavras[i]);
	}
	gravaDados();
	printf("\n\nPressione qualquer tecla para continuar.");
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
	printf("Pressione qualquer tecla para continuar.");
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
	printf("\n\nPressione qualquer tecla para continuar.");
	getch();
		
}

void jogar (void){
	
	system("cls");
	
	srand(time(NULL));
	

	printf("Digite uma palavra: ");
	gets(palavra);
	fflush(stdin);
	strupr(palavra);
	

	
	printf("\t\t\t\t");
	for (i=0; palavra[i] != '\0'; i++){
		
		printf("_ ");
	}
	
	
	for(jogador=1; jogador <=3; jogador++){
		if (strcmp (palavra, palavratotal) == 0){
			exit(0);
		}
		
		acumulado = 0;
		
		do{
			system("cls");
			/*printf("\t\t\t\t");
			for (i=0; palavra[i] != '\0'; i++){
		
			printf("_ ");
			}*/
			
			printf("============================================================================\n");
			printf("\t\t\t\tJOGO DO RODA A RODA\n");
			printf("============================================================================\n");
			printf("\n\n\n\n");
			printf("\n\nJOGADOR %d", jogador);
			
			printf("\t\t\t\t");
			for (i=0; palavra[i] != '\0'; i++){
				if (palavratotal[i] == palavra[i]){
					printf(" %c", palavratotal[i]);
				}
					else{
							printf(" _");
						}
			}
			
			setlocale(LC_ALL, "Portuguese");
			
			valor_aleatorio = rand() % 12;
			
			premioale = premios[valor_aleatorio];
			
			printf("\n\t\t\t\tValendo R$%d.00 por letra para o jogador %d", premioale, jogador);
			
			printf("\n\t\t\t\tDigite uma letra: ");
			scanf("%c", &letra);
			
			letra = toupper(letra);
			
			fflush(stdin);
			
			acertos = 0;
			for (i=0; palavra[i] != '\0'; i++){
				
				if (palavra[i] == letra){
					//printf(" %c", letra);
					palavratotal[i] = letra;
					acumulado = acumulado + premioale;
					acertos++;
				}
					else if (palavratotal[i] == palavra[i]){
						//printf(" %c", palavratotal[i]);
					}
						else{
							//printf(" _");
						}
			}
			
			if ( acertos>0){  
	           printf ("\n\nO Prêmio acumulado do jogador %d foi de R$ %.2f", jogador, acumulado);
	           
	        }
	        	else{
	          	 printf ("\n\nVocê PERDEU A VEZ, pois a letra informa '%c' NÃO faz parte da palavra", letra);
	          	 premio_jogador[jogador] = acumulado;
	          	 printf("\n\nO premio do jogador %d foi R$ %.2f", jogador, acumulado);
	          	 getch();
	          	}
	        system("cls");
		    getch();
		    
		
		
		} while (strcmp (palavra, palavratotal) == 1 && acertos!=0 );
	}
		
		
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
