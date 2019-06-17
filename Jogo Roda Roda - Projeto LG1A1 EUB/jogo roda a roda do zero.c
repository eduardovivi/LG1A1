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
float premios[] = {100, 900, 600, 1000, 0, 400, 200, 800, 2, 300, 500, 700};
float premio_zero[] = {0, 0};
float premio_perde[] = {2, 2};

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
	
	srand(time(NULL)); //faz com que os números aleatórios "não se repitam"
	
	printf("Digite uma palavra: ");
	gets(palavra);
	fflush(stdin);
	strupr(palavra); //deixa a palavra toda em maiúscula
	
	printf("\t\t\t\t"); //printa os tracinhos
	for (i=0; palavra[i] != '\0'; i++){
		
		printf("_ ");
	}
	
	jogador = 1;
	inicio_do_for:
	while(jogador <= 3){ //faz um loop até chegar no terciro jogador
		tela_final:
			if (strcmp (palavra, palavratotal) == 0){ // caso a palavra adivinhada fique igual à palavra escolhida, o programa para
				printf ("\n\nO Prêmio acumulado do jogador %d foi de R$ %.2f", jogador, acumulado);
				getch();
				system("cls");
				printf("==========================================================================================\n");
				printf("\t\t\t\t    JOGO DO RODA A RODA\n");
				printf("==========================================================================================\n");
				printf("\n\n\n");
				printf("\t\t\t\t\t PALAVRA\n");
				printf("\n\t\t\t\t\t  %s     ", palavra);
				printf("\n\n\n\nJOGADOR 1\t\t\t\tJOGADOR 2\t\t\t\tJOGADOR 3", jogador); //ESTRUTURA DO JOGUINHO
				printf("\n[R$%.2f]\t\t\t\t[R$%.2f]\t\t\t\t[R$%.2f]", premio_jogador[1], premio_jogador[2], premio_jogador[3]); //ESTRUTURA DO JOGUINHO
				
				if(premio_jogador[1] > premio_jogador[2] && premio_jogador[1] > premio_jogador[2]){
					printf ("\n\n\t\tO JOGO ACABOU E O VENCEDOR FOI O JOGADOR 1 QUE VAI LEVAR PARA CASA R$%.2f!", premio_jogador[1]);	
				}
					else if(premio_jogador[2] > premio_jogador[1] && premio_jogador[2] > premio_jogador[3]){
						printf ("\n\n\t\tO JOGO ACABOU E O VENCEDOR FOI O JOGADOR 2 QUE VAI LEVAR PARA CASA R$%.2f!", premio_jogador[2]);		
					}
						else{
							printf ("\n\n\t\tO JOGO ACABOU E O VENCEDOR FOI O JOGADOR 3 QUE VAI LEVAR PARA CASA R$%.2f!", premio_jogador[3]);
						}
				
				
				exit(0);
			}
		
		acumulado = 0;
		
		do{
			setlocale(LC_ALL, "Portuguese");
			
			valor_aleatorio = rand() % 12; // gera um valor aleatório de 0 até 12 //
			
			premioale = premios[valor_aleatorio]; // armazena em premioale o premio que corresponde ao indice sorteado na linha anterior
			
			system("cls");
			printf("==========================================================================================\n");
			printf("\t\t\t\t    JOGO DO RODA A RODA\n");
			printf("==========================================================================================\n");
			printf("\n\n\n");
			printf("\t\t\t\t\t PALAVRA\n");
			
			printf("\n\t\t\t\t      "); // se tiver um caracter que ja foi dito antes e que se encontra na palavra, ele será printado
			for (i=0; palavra[i] != '\0'; i++){
				if (palavratotal[i] == palavra[i]){
					printf(" %c", palavratotal[i]);
				}
					else{
							printf(" _"); // caso contrário, ele printará o tracinho
						}
			}
			pede_outra_letra:
			
			system("cls");
			printf("==========================================================================================\n");
			printf("\t\t\t\t    JOGO DO RODA A RODA\n");
			printf("==========================================================================================\n");
			printf("\n\n\n");
			printf("\t\t\t\t\t PALAVRA\n");
			
			printf("\n\t\t\t\t      "); // se tiver um caracter que ja foi dito antes e que se encontra na palavra, ele será printado
			for (i=0; palavra[i] != '\0'; i++){
				if (palavratotal[i] == palavra[i]){
					printf(" %c", palavratotal[i]);
				}
					else{
							printf(" _"); // caso contrário, ele printará o tracinho
						}
			}
			
			if (premioale == premio_zero[1]){ //CASO O PREMIO SORTEADO SEJA 0 
				goto passaavez;
			} 
			
			if (premioale == premio_perde[1]){ //CASO O PREMIO SORTEADO SEJA 0 
				goto perdetudo;
			} 
			
			printf("\n\n\n\nJOGADOR 1\t\t\t\tJOGADOR 2\t\t\t\tJOGADOR 3", jogador); //ESTRUTURA DO JOGUINHO
			printf("\n[R$%.2f]\t\t\t\t[R$%.2f]\t\t\t\t[R$%.2f]", premio_jogador[1], premio_jogador[2], premio_jogador[3]); //ESTRUTURA DO JOGUINHO
			
			printf("\n\n\n\t\t\t\tValendo R$%d.00 por letra para o jogador %d", premioale, jogador);
			
			printf("\n\n\t\t\t\tJogador %d, digite uma letra: ", jogador);
			scanf("%c", &letra);
			letra = toupper(letra); //transforma o caractere em maiusculo
			fflush(stdin);
			
			acertos = 0;
			
			/////////////////////////////////////VERIFICA SE A LETRA FOI DIGITADA
			for (i=0; palavra[i] != '\0'; i++){ 
				
				if (palavratotal[i] == letra){
					acertos++;
					goto pede_outra_letra;
				}
					
			}
			////////////////////////////////////
			
			for (i=0; palavra[i] != '\0'; i++){ //analisa se o caractere digitado se encontra na palavra escolhida
				
				if (palavra[i] == letra){
					palavratotal[i] = letra;
					acumulado = acumulado + premioale;
					acertos++;
				}
					
			}
	 		
	 		if (premioale == premio_zero[1]){ //CASO O PREMIO SORTEADO SEJA 0 
				goto passaavez;
			} 
			
			if (premioale == premio_perde[1]){ //CASO O PREMIO SORTEADO SEJA 0 
				goto perdetudo;
			} 
				
			if ( acertos>0){  //se houver algum acerto, o jogador receberá o prêmio
	           //printf ("\n\nO Prêmio acumulado do jogador %d foi de R$ %.2f", jogador, acumulado);
	           premio_jogador[jogador] = premio_jogador[jogador] + acumulado;
	           goto inicio_do_for; ////////////////////////////////////////////////////////
	           
	        }
					else{
						printf ("\n\nVocê PERDEU A VEZ, pois a letra informa '%c' NÃO faz parte da palavra", letra);
						premio_jogador[jogador] = premio_jogador[jogador];
						printf("\n\nO premio do jogador %d foi R$ %.2f", jogador, premio_jogador[jogador]);
						jogador++; ////////////////////////////////////////////////////////////
						getch();
				
	          		}
	        
			passaavez:
	        if (premios[valor_aleatorio] == premio_zero[1]){ //CASO O PREMIO SORTEADO SEJA 0 
				
				printf ("\n\n\t\tO JOGADOR %d PERDEU A VEZ, pois o premio sorteado foi 0!", jogador);
				jogador++;
				getch();
			}
					else if(strcmp (palavra, palavratotal) == 0){
						goto tela_final;
					}
						else{
							goto inicio_do_for;
						}
						
			perdetudo:
			if (premios[valor_aleatorio] == premio_perde[1]){ //CASO O PREMIO SORTEADO SEJA 0 
				
				printf ("\n\n\t\tO JOGADOR %d PERDEU TUDO, pois o premio sorteado foi 0!", jogador);
				premio_jogador[jogador] = 0;
				jogador++;
				getch();
			}
					else if(strcmp (palavra, palavratotal) == 0){
						goto tela_final;
					}
						else{
							goto inicio_do_for;
						}
			
		
		} while (strcmp (palavra, palavratotal) == 1 && acertos!=0 ); // Realiza o loop enquanto a palavra sorteada não for descoberta
																	  // totalmente e enquanto os acertos serem diferentes de 0
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

	setlocale(LC_ALL, "Portuguese");
	
	do{
		admin();
	} while (opcao != 'S' && opcao != 's');
	
}
