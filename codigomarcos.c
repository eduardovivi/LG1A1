#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int k,i,j,vencedor=3,num_jogador,letras_certas=0,letras_faltantes=0,letras_total=0;

char a,letra;
float x,saldo[3];
char palavra_escondida[3][17],palavra_digitada[3][17];

typedef struct registro{   
	
	char pista[17];
	int quantidade;
	char vetpalavras[3][17];
	
}registro;



registro palavras;//variavel estrutura global

///////////////////////// DEFINIÇÕES DAS FUNÇÕES //////////////////////////


void sorteia_palavra(void){
	
	//sorteia palavra de PALAVRAS.DAT//

		int registro_sorteado;
		system("cls");

		FILE*arquivo;
		
		arquivo=fopen("PALAVRAS.DAT","rb");
		int k,c=0;
		
		while(!feof(arquivo)){
			fread(&palavras,sizeof(palavras),1,arquivo);
			if ( !feof(arquivo) ){
				c++;
			}
		}
		
		srand(time(NULL));	
		registro_sorteado=1 + ( rand() % c );
	

		//volta ao inicio do arquivo//
		rewind(arquivo);
		
		for(k=0;k<registro_sorteado;k++){
			fread(&palavras,sizeof(palavras),1,arquivo);
	
		}
	
	fclose(arquivo);
	
	}
	
float sorteia_premio(void){

	//SORTEIA PREMIO DE PREMIOS.DAT
		
		float premio;
		FILE*arquivo_premio;
		int k,c=0,registro_sorteado;
		
		arquivo_premio=fopen("PREMIOS.DAT","rb");
		
		while(!feof(arquivo_premio)){
			fread(&premio,sizeof(premio),1,arquivo_premio);
			if ( !feof(arquivo_premio) ){
				c++;
			}
		}
		
		srand(time(NULL));	
		registro_sorteado=1 + ( rand() % c );
	
	
		
		rewind(arquivo_premio);
		
		for(k=0;k<registro_sorteado;k++){
			fread(&premio,sizeof(premio),1,arquivo_premio);
	
		}
		
	
	fclose(arquivo_premio);
	
	return premio;
}	

void verifica_letra(){	
	//verifica se a letra está correta,se estiver,substitui "-" em "palavra_aux" pela letra digitada //

	int j;
	
	for(j=0;j<palavras.quantidade;j++){
		
		int i=0;
		
		while (palavras.vetpalavras[j][i]!='\0'){
				
				
				if(letra==palavras.vetpalavras[j][i]){
					
					palavra_escondida[j][i]=letra; 
					letras_certas++;
					
				}
				
				i++;
		}		
	}
}
	
void cria_aux(){
	//susbtitui letras da palavra sorteada em PALAVRAS.DAT por "-" //
		int k,tamanho,i;
	
	for(i=0;i<palavras.quantidade;i++){
			
		tamanho=strlen(palavras.vetpalavras[i]);
		
		char palavra_aux[tamanho+1];	
		
		for(k=0;k<tamanho;k++){
			
			palavra_aux[k]='-';
			//conta total de letras//
			letras_total++;
		
		}
			
			palavra_aux[k]='\0';
			//copia palavra_aux para palavra_escondida//
			strcpy(palavra_escondida[i],palavra_aux);
	}

}

void tela_PassaAVez(){
	
	//tela exibida ao passar a vez//
	
	if(num_jogador>=3){
		num_jogador=1;
	}else{
		num_jogador++;
		}
	
	setlocale(LC_ALL,"");
		system("cls");
		printf("\n\n\n\t\tA palavra está associada com: ");
		printf("%s \n\n\n",palavras.pista);
		printf("\t\t\t\t%s\n\n\t\t\t\t%s\n\n\t\t\t\t%s",palavra_escondida[0],palavra_escondida[1],palavra_escondida[2]);		
		printf("\n\n\n");
		printf("\t   JOGADOR 1\t\tJOGADOR 2\t\tJOGADOR 3\n");
		printf("          ===========\t       ===========\t       ===========\n");	
		printf("\t  R$ %.2f\t\tR$ %.2f\t\t\tR$ %.2f\n",saldo[0],saldo[1],saldo[2]);
		printf("\n\n\tPASSA A VEZ!\n\n\tA vez será passada para o jogador %d\n\n",num_jogador);
		
	
	
}

tela_ErraLetra(){
	
	//tela exibida ao errar a letra //

	if(num_jogador>=3){
		num_jogador=1;
	}else{
		num_jogador++;
		}
	setlocale(LC_ALL,"");
		system("cls");
		printf("\n\n\n\t\tA palavra está associada com: ");
		printf("%s \n\n\n",palavras.pista);
		printf("\t\t\t\t%s\n\n\t\t\t\t%s\n\n\t\t\t\t%s",palavra_escondida[0],palavra_escondida[1],palavra_escondida[2]);		
		printf("\n\n\n");
		printf("\t   JOGADOR 1\t\tJOGADOR 2\t\tJOGADOR 3\n");
		printf("          ===========\t       ===========\t       ===========\n");	
		printf("\t  R$ %.2f\t\tR$ %.2f\t\t\tR$ %.2f\n",saldo[0],saldo[1],saldo[2]);
		printf("\n\n\tNão existe letra %c na palavra.\n\n\tA vez será passada para o jogador %d\n\n",letra,num_jogador);
}

tela_roda_a_roda(){
	
	//tela exibida ao inicio// 
		setlocale(LC_ALL,"");
		system("cls");
		printf("\n\n\n\t\tA palavra está associada com: ");
		printf("%s \n\n\n",palavras.pista);
		printf("\t\t\t\t%s\n\n\t\t\t\t%s\n\n\t\t\t\t%s",palavra_escondida[0],palavra_escondida[1],palavra_escondida[2]);		
		printf("\n\n\n");
		printf("\t   JOGADOR 1\t\tJOGADOR 2\t\tJOGADOR 3\n");
		printf("          ===========\t       ===========\t       ===========\n");	
		printf("\t  R$ %.2f\t\tR$ %.2f\t\t\tR$ %.2f\n",saldo[0],saldo[1],saldo[2]);
		printf("\n\n\tRODA A RODA [Aperte qualquer tecla]\n");
		
	
	
}

tela_palavras(){
	
	////tela exibida ao sobrar 3 letras//
	
		do{
		x=sorteia_premio();
		}while(x==11||x==0);
		
		float premio=x;
		int p,erro=0,t;
		
		while(erro<3){
			
				
			for(t=1;t<=5;t++){
				setlocale(LC_ALL,"");
				system("cls");
				printf("\n\n\n\t\tA palavra está associada com: ");
				printf("%s \n\n\n",palavras.pista);
				printf("\t\t\t\t%s\n\n\t\t\t\t%s\n\n\t\t\t\t%s",palavra_escondida[0],palavra_escondida[1],palavra_escondida[2]);		
				printf("\n\n\n");
				printf("\t   JOGADOR 1\t\tJOGADOR 2\t\tJOGADOR 3\n");
				printf("          ===========\t       ===========\t       ===========\n");	
				printf("\t  R$ %.2f\t\tR$ %.2f\t\t\tR$ %.2f\n",saldo[0],saldo[1],saldo[2]);
				printf("\n\n\tJogador %d: Faltam 3 letras para completar a palavra.\n",num_jogador);
				
					printf("\n\tVocê tem 5 segundos para pensar e depois digitar a palavra %d...\n",t);
					sleep(1);
			}
				
				printf("\n\tValendo R$ %.2f a palavra é: ",saldo[i]+premio);
				
				for(p=0;p<palavras.quantidade;p++){
					
					fflush(stdin);
					gets(palavra_digitada[p]);	
					
					if(strcmp(palavra_digitada[0],"nao sei")==0){
						break;
					}
				}
				
				if(strcmp(palavra_digitada[0],palavras.vetpalavras[0])==0&&strcmp(palavra_digitada[1],palavras.vetpalavras[1])==0&&strcmp(palavra_digitada[2],palavras.vetpalavras[2])==0){
							saldo[i]=saldo[i]+premio;
							vencedor=i;
							break;	
							
						}else{	
							
							erro++;
							
							i++;
							
							}
							
				if(num_jogador>=3){
					num_jogador=1;
				}else{
					num_jogador++;
					}
		}//while erro
}//função

tela_vencedor(){
	//tela exibida ao terminar o jogo,mostra o vencedor
	
	setlocale(LC_ALL,"");
		system("cls");
		printf("\n\n\n\t\tA palavra está associada com: ");
		printf("%s \n\n\n",palavras.pista);
		printf("\t\t\t\t%s\n\n\t\t\t\t%s\n\n\t\t\t\t%s",palavras.vetpalavras[0],palavras.vetpalavras[1],palavras.vetpalavras[2]);		
		printf("\n\n\n");
		printf("\t   JOGADOR 1\t\tJOGADOR 2\t\tJOGADOR 3\n");
		printf("          ===========\t       ===========\t       ===========\n");	
		printf("\t  R$ %.2f\t\tR$ %.2f\t\tR$ %.2f\n",saldo[0],saldo[1],saldo[2]);
		if(vencedor==0){
			printf("\n\t  ");
			printf("VENCEDOR!\n");
			}else{
				if(vencedor==1){
					printf("\n\t\t\t\t");
					printf("VENCEDOR!\n");
					}else{
						if(vencedor==2){
						printf("\n\t\t\t\t\t\t\t");
						printf("VENCEDOR!\n");
						}else{
							printf("\n\t\t\tNÃO HOUVE NENHUM VENCEDOR");
						}
					
					}
					
			}
			
}

tela_PerdeTudo(){
	//tela exibida ao perder tudo
	
	if(num_jogador>=3){
		num_jogador=1;
	}else{
		num_jogador++;
		}
	
	setlocale(LC_ALL,"");
		system("cls");
		printf("\n\n\n\t\tA palavra está associada com: ");
		printf("%s \n\n\n",palavras.pista);
		printf("\t\t\t\t%s\n\n\t\t\t\t%s\n\n\t\t\t\t%s",palavra_escondida[0],palavra_escondida[1],palavra_escondida[2]);		
		printf("\n\n\n");
		printf("\t   JOGADOR 1\t\tJOGADOR 2\t\tJOGADOR 3\n");
		printf("          ===========\t       ===========\t       ===========\n");	
		printf("\t  R$ %.2f\t\tR$ %.2f\t\t\tR$ %.2f\n",saldo[0],saldo[1],saldo[2]);
		printf("\n\n\tPERDE TUDO!\n\n\tA vez será passada para o jogador %d\n\n",num_jogador);
	
	
}


main(){
	
	//INICIO DO JOGO//
	
for(;;){	
	
	setlocale(LC_ALL,"");
	system("cls");
	
	printf("\nd8888b.  .d88b.  d8888b.  .d8b.      .d8b.     d8888b.  .d88b.  d8888b.  .d8b.\n"); 
	printf("88  `8D .8P  Y8. 88  `8D d8' `8b    d8' `8b    88  `8D .8P  Y8. 88  `8D d8' `8b\n");
	printf("88oobY' 88    88 88   88 88ooo88    88ooo88    88oobY' 88    88 88   88 88ooo88\n"); 
	printf("88`8b   88    88 88   88 88~~~88    88~~~88    88`8b   88    88 88   88 88~~~88\n"); 
	printf("88 `88. `8b  d8' 88  .8D 88   88    88   88    88 `88. `8b  d8' 88  .8D 88   88\n"); 
	printf("88   YD  `Y88P'  Y8888D' YP   YP    YP   YP    88   YD  `Y88P'  Y8888D' YP   YP\n");
	printf("\n\n\n\n\n\n\t\t\t\t  [1] - NOVO JOGO\n");
	printf("\t\t\t\t  [2] - SAIR\n");
	printf("\t\t\t\t =================  \n");
	printf("\t\t\t\t  ESCOLHA: ");
	
	//pede opção até ser 1 ou 2 
	
		do{
			a=getch();
		}while (a!='1'&& a!='2');
	
	
	switch(a){
		
		case '2':exit(0);
			break;	
		}
	
	
	saldo[0]=0;
	saldo[1]=0;
	saldo[2]=0;
	
	i=0;
	num_jogador=1;

///////////////////     sorteando registro em PALAVRAS.DAT       ///////////////////
	
	sorteia_palavra();
	
////////criando palavra auxiliar: (-------)/////
	
	cria_aux();

////////////////////// INICIO DO JOGO/////////////////

	letras_faltantes=letras_total;
	
	for(;;){
		
		
		tela_roda_a_roda();
		getch();
		
		if(letras_faltantes<=3){
					    	
			tela_palavras();
			break;
						
			}
		
		//sorteia o premio de PREMIOS.DAT
		
		x=sorteia_premio();	
		
		if (x==0){
			
			i++;
			tela_PassaAVez();
			getch();
			
		}else{
		
			if(x==11){
				
				saldo[i]=0;
				tela_PerdeTudo();
				i++;
				getch();
				
			}else{
				
				printf("\n\n\tUma letra por %.2f reais: ",x);
			
				//pede "letra" enquanto nao digitar uma letra
				
				do{
				letra=getch();
				letra=tolower(letra);
				}while(!isalpha(letra));
				
				letras_certas=0;
			    verifica_letra();   
			    
			    if (letras_certas==0){
			
					tela_ErraLetra();
			   		i++;
			    	getch();
					
				}else{
					saldo[i]+=x*letras_certas;
					}
				
			    
				letras_faltantes=letras_faltantes-letras_certas;
					
			}
			
		}
		
		if(i>2){
			i=0;
			
		}
		
	}//for infinito   */
		
	tela_vencedor();	
	getch();
	
	}//for jogo//
} //main
