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
cadastro cdstr;

int auxi = 0;

char opcao;
float premios[] = {100, 900, 600, 1000, 0, 400, 200, 800, 2, 300, 500, 700};
float premio_zero[] = {0, 0};
float premio_perde[] = {2, 2};
int jogador_no_momento;


// VARIAVEIS DO JOGO //
int i;

int diferenca;
int qtdletras = 0;
int qtdletrastotal = 0;
char palavra[10];
char palavratotal[10];
char pista_usuario[10];

char letra;

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
	
	arq = fopen ("PALAVRAS.dat", "r"); //abre o arquivo em modo de leitura
	
	if (arq == NULL){ //caso o arquivo dê erro
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
	gets(cdstr.pista); //armazena na pista

	
	do //pede a quantidade de palavras, e conforme ela, armazena a quantidade de palavras desejada
	{  
	printf ("\n\nQUANTIDADE DE PALAVRAS: ");
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

	FILE *arq;
	
	arq = fopen ("premios.dat", "w"); // Cria um premios.dat toda vez que uma consulta é realizada para que não haja repetição dos prêmios
								   	   
	if (arq == NULL){ // caso o arquivo dê erro
		system("cls");
		printf("Ocorreu um erro ao gravar dados no arquivo PALAVRAS.DAT");
	}
		else{
			fwrite(&premios, sizeof(premios), 1, arq); //escreve os premios no arquivo
		}
	fclose(arq); //fecha o arquivo
}

void consultaPremios (void){
	
	
	system("cls");
	printf("===============================================\n");
	printf("	   RODA A RODA DO SILVIO SANTOS		       \n");
	printf("===============================================\n");
	printf("  	   								     	   \n");
	printf("  	   								     	   \n");
	printf("	    3. Consultar Premios		\n");
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
		
	arq = fopen ("premios.dat", "r"); //abre o arquivo em modo leitura //
	
	if (arq == NULL){ // caso dê erro
		system("cls");
		printf("Ocorreu um erro ao ler o arquivo PREMIOS.DAT");
	}
		else{
			fread(&premios, sizeof(premios), 1, arq); //lê o arquivo até o final, mostrando os prêmios armazenados
					for(i=0;i<10;i++){ 
						printf("\nPREMIO %d:[R$ %.2f]", i + 1, premios[i]); //printa todos os prêmios presentes no arquivo
					}					
		}		
			
	fclose(arq); //fecha o arquivo
	printf("\n\nPressione qualquer tecla para continuar.");
	getch();
		
}

void jogar (void){
	
	system("cls");
	
	srand(time(NULL)); //faz com que os números aleatórios "não se repitam"
	
	printf("Digite uma pista: "); //pede a pista e armazena
	gets(pista_usuario);
	fflush(stdin);
	strupr(pista_usuario); //deixa a pista toda em maiúscula
	
	printf("Digite uma palavra: "); //pede uma palavra e a armazena
	gets(palavra);
	fflush(stdin);
	strupr(palavra); //deixa a palavra toda em maiúscula
	
	
	
	printf("\t\t\t\t"); //printa os tracinhos
	for (i=0; palavra[i] != '\0'; i++){
		
		printf("_ ");
	}
	
	jogador = 1;
	
	inicio_do_for: //checkpoint
	
		
	while(jogador <= 3){ //faz um loop até chegar no terceiro jogador
		
			if (strcmp (palavra, palavratotal) == 0){ // caso a palavra adivinhada fique igual à palavra escolhida, o programa para
				tela_final: //checkpoint para a tela final do jogo
				getch();
				system("cls");
				printf("==========================================================================================\n");
				printf("\t\t\t\t    JOGO DO RODA A RODA\n");
				printf("==========================================================================================\n");
				printf("\n\n\n");
				printf("\t\t\t\t         PISTA: %s\n", pista_usuario);
				printf("\t\t\t\t        A PALAVRA ERA:\n");
				printf("\n\t\t\t\t\t  %s     ", palavra);
				printf("\n\n\n\t\t\t\t      O JOGO ACABOU!");
				printf("\n\t\t\t\t   E O RESULTADO FINAL FOI:");
				printf("\n\n JOGADOR 1\t\t\t\tJOGADOR 2\t\t\t\tJOGADOR 3", jogador); 
				printf("\n[R$%.2f]\t\t\t\t[R$%.2f]\t\t\t\t[R$%.2f]", premio_jogador[1], premio_jogador[2], premio_jogador[3]); //ESTRUTURA DO JOGUINHO
			
				exit(0);
			}
		
		int acumulado = 0;
				
				
			do{
				setlocale(LC_ALL, "Portuguese");
				
				valor_aleatorio = rand() % 12; // gera um valor aleatório de 0 até 12 para sortear o prêmio //
				
				premioale = premios[valor_aleatorio]; // armazena em premioale o premio que corresponde ao indice sorteado na linha anterior
				
				system("cls");
				printf("==========================================================================================\n");
				printf("\t\t\t\t    JOGO DO RODA A RODA\n");
				printf("==========================================================================================\n");
				printf("\n\n\n");
				printf("\t\t\t\t       PISTA: %s\n", pista_usuario);
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
				pede_outra_letra: //checkpoint para caso a letra digitada seja alguma que se encontra na palavra
				
				system("cls");
				printf("==========================================================================================\n");
				printf("\t\t\t\t    JOGO DO RODA A RODA\n");
				printf("==========================================================================================\n");
				printf("\n\n\n");
				printf("\t\t\t\t       PISTA: %s\n", pista_usuario);
				printf("\t\t\t\t\t PALAVRA\n");
				
				qtdletrastotal = 0; //zera sempre a contagem dos tracinhos
				
				printf("\n\t\t\t\t      "); // se tiver um caracter que ja foi dito antes e que se encontra na palavra, ele será printado
				for (i=0; palavra[i] != '\0'; i++){
					if (palavratotal[i] == palavra[i]){
						printf(" %c", palavratotal[i]);
					}
						else{
								printf(" _");
								qtdletrastotal = qtdletrastotal + 1; // caso contrário, ele printará os tracinhos e armazenará numa variável que contará
																	 // a quantidade de tracinhos
							}
				}
				
				if (qtdletrastotal <= 3){ //SE HOUVER SOMENTE 3 TRACINHOS OU MENOS RESTANTES, FARÁ:
				
					jogador_no_momento = jogador; //armazena o jogador que jogou por último	
					for(jogador= jogador_no_momento; jogador <= jogador_no_momento + 2; jogador++){ //faz um loop desde o jogador que jogou por último 
																									//até sua posição + 2
					
					char chute_jogador1[10];
					char chute_jogador2[10];
					char chute_jogador3[10];
					
							system("cls");
							
							printf("==========================================================================================\n");
							printf("\t\t\t\tJOGO DO RODA A RODA -- HORA DE CHUTAR!!\n");
							printf("==========================================================================================\n");
							printf("\n\n\n");
							printf("\t\t\t\t       PISTA: %s\n", pista_usuario);
							printf("\t\t\t\t\t PALAVRA\n");
						
							printf("\n\t\t\t\t      "); 
							
							//se tiver um caracter que ja foi dito antes e que se encontra na palavra, ele será printado
							for (i=0; palavra[i] != '\0'; i++){ 
								if (palavratotal[i] == palavra[i]){
									printf(" %c", palavratotal[i]);
								}
									else{
											printf(" _");
										}
							}
							
							//ESTRUTURA DO JOGUINHO
							printf("\n\n\n\nJOGADOR 1\t\t\t\tJOGADOR 2\t\t\t\tJOGADOR 3", jogador); 
							printf("\n[R$%.2f]\t\t\t\t[R$%.2f]\t\t\t\t[R$%.2f]", premio_jogador[1], premio_jogador[2], premio_jogador[3]); 
							
							//LÓGICA DO PRIMEIRO JOGADOR NO MOMENTO DA PALAVRA TER 3 TRACINHOS
							if(jogador_no_momento == 1){ //caso o último jogador tenha sido o 1:
								
								if (jogador == 1){
									printf("\n\n\t\t\t\tJogador 1, da um chute ae pai: ");
									gets(chute_jogador1);
									fflush(stdin);
									strupr(chute_jogador1);
								}	
								if(strcmp(chute_jogador1, palavra) == 0){
									goto tela_final;
									exit(0);
								}	
																
								if (jogador == 2){
									printf("\n\n\t\t\t\tJogador 2, da um chute ae pai: ");
									gets(chute_jogador2);
									fflush(stdin);
									strupr(chute_jogador2);	
								}
								if(strcmp(chute_jogador2, palavra) == 0){
									goto tela_final;
									exit(0);
								}
								
								if (jogador == 3){
									printf("\n\n\t\t\t\tJogador 3, da um chute ae pai: ");
									gets(chute_jogador3);
									fflush(stdin);
									strupr(chute_jogador3);
								}
								if(strcmp(chute_jogador3, palavra) == 0){
									goto tela_final;
									exit(0);
								}
									else if(strcmp(chute_jogador3, palavra) == 1){
										system("cls");
										printf("NINGUEM ACERTOU!"); 
										exit(0);
									}		
							}
						
							if(jogador_no_momento == 2){ //caso o último jogador tenha sido o 2:
								
								if (jogador == jogador_no_momento + 2 ){
									printf("\n\n\t\t\t\tJogador 1, da um chute ae pai: ");
									gets(chute_jogador1);
									fflush(stdin);
									strupr(chute_jogador1);
								}
								if(strcmp(chute_jogador1, palavra) == 0){
									goto tela_final;
									exit(0);
								}
									else if(strcmp(chute_jogador2, palavra) == 1){
										system("cls");
										printf("NINGUEM ACERTOU!");
										exit(0);
									}
								
								if (jogador == 2){
									printf("\n\n\t\t\t\tJogador 2, da um chute ae pai: ");
									gets(chute_jogador2);
									fflush(stdin);
									strupr(chute_jogador2);	
								}						
								if(strcmp(chute_jogador2, palavra) == 0){
									goto tela_final;
									exit(0);
								}		
																							
								if (jogador == jogador_no_momento + 1){
									printf("\n\n\t\t\t\tJogador 3, da um chute ae pai: ");
									gets(chute_jogador3);
									fflush(stdin);
									strupr(chute_jogador3);
								}								
								if(strcmp(chute_jogador3, palavra) == 0){
									goto tela_final;
									exit(0);
								}
							}
							
							if(jogador_no_momento == 3){ //caso o último jogador tenha sido o 3:
								
								if (jogador == jogador_no_momento + 1 ){
									printf("\n\n\t\t\t\tJogador 1, da um chute ae pai: ");
									gets(chute_jogador1);
									fflush(stdin);
									strupr(chute_jogador1);
								}								
								if(strcmp(chute_jogador1, palavra) == 0){
									goto tela_final;
									exit(0);
								}
										
								if (jogador == jogador_no_momento + 2){
									printf("\n\n\t\t\t\tJogador 2, da um chute ae pai: ");
									gets(chute_jogador2);
									fflush(stdin);
									strupr(chute_jogador2);	
								}								
								if(strcmp(chute_jogador2, palavra) == 0){
									goto tela_final;
									exit(0);
								}
									else if(strcmp(chute_jogador2, palavra) == 1){
										system("cls");
										printf("NINGUEM ACERTOU!");
										exit(0);
									}
										
								if (jogador == jogador_no_momento){
									printf("\n\n\t\t\t\tJogador 3, da um chute ae pai: ");
									gets(chute_jogador3);
									fflush(stdin);
									strupr(chute_jogador3);
								}	
								if(strcmp(chute_jogador3, palavra) == 0){
									goto tela_final;
									exit(0);
								}
							}						
					}  					
				}
				
				if (premioale == premio_zero[1]){ //CASO O PREMIO SORTEADO SEJA O PASSA A VEZ
					goto passaavez;
				} 
				
				if (premioale == premio_perde[1]){ //CASO O PREMIO SORTEADO SEJA O PERDE TUDO 
					goto perdetudo;
				} 
				
				//ESTRUTURA DO JOGUINHO
				printf("\n\n\n\nJOGADOR 1\t\t\t\tJOGADOR 2\t\t\t\tJOGADOR 3", jogador); 
				printf("\n[R$%.2f]\t\t\t\t[R$%.2f]\t\t\t\t[R$%.2f]", premio_jogador[1], premio_jogador[2], premio_jogador[3]); 
				printf("\n\n\n\t\t\t\tValendo R$%d.00 por letra para o jogador %d", premioale, jogador);				
	
				//pede uma letra e a armazena
				printf("\n\n\t\t\t\tJogador %d, digite uma letra: ", jogador);
				scanf("%c", &letra);
				letra = toupper(letra); //transforma a letra em maiusculo
				fflush(stdin);
				
				acertos = 0;
				
				//verifica se a letra foi digitada anteriormente
				for (i=0; palavra[i] != '\0'; i++){ 
					
					if (palavratotal[i] == letra){
						acertos++;
						goto pede_outra_letra;
					}
						
				}

				//analisa se o caractere digitado se encontra na palavra escolhida
				for (i=0; palavra[i] != '\0'; i++){ 
					
					if (palavra[i] == letra){
						palavratotal[i] = letra;
						acumulado = acumulado + premioale;
						acertos++;
					}
						
				}
		 		
		 		//verifica se o passa a vez ocorreu
		 		if (premioale == premio_zero[1]){  
					goto passaavez;
				} 
				
				//verifica se o perde tudo ocorreu
				if (premioale == premio_perde[1]){ //CASO O PREMIO SORTEADO SEJA 0 
					goto perdetudo;
				} 
				
					
				if ( acertos>0){  //se houver algum acerto, o jogador receberá o prêmio
		           premio_jogador[jogador] = premio_jogador[jogador] + acumulado;
		           goto inicio_do_for; 
		           
		        }
						else{ //se nao houver acertos
							printf ("\n\nVocê PERDEU A VEZ, pois a letra informa '%c' NÃO faz parte da palavra", letra);
							premio_jogador[jogador] = premio_jogador[jogador];
							printf("\n\nO premio do jogador %d foi R$ %.2f", jogador, premio_jogador[jogador]);
							jogador++; 
							getch();
						}	
				
		        
				passaavez: //checkpoint que apresenta o que acontecerá se for sorteado o "passa a vez"
		        if (premios[valor_aleatorio] == premio_zero[1]){ 
					
					printf ("\n\n\t\tO JOGADOR %d PERDEU A VEZ", jogador);
					jogador++;
					getch();
				}
						else if(strcmp (palavra, palavratotal) == 0){
							goto tela_final;
						}
							else{
								goto inicio_do_for;
							}
							
				perdetudo: //checkpoint que apresenta o que acontecerá se for sorteado o "perde tudo"
				if (premios[valor_aleatorio] == premio_perde[1]){ 
					
					printf ("\n\n\t\tO JOGADOR %d PERDEU TUDO", jogador);
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
		printf("	    3. Consultar Premios	\n");
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
