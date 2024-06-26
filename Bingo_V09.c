#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void geraCartela(int cartela[3][5]);
bool contemValor(int cartela[3][5], int numero);
void printaCartela(int cartela[3][5], int sorteados[]);
bool verificaVetor(int numerosSorteados[], int numero); 
int sorteiaNumeros(int numerosSorteados[], int quantidadeNumSort);
void printaVetorSort(int sorteados[]);
void printaJogadores(int cartelaUm[3][5], int cartelaDois[3][5], int cartelaTres[3][5], int sorteados[]);


int main(){
	
	int cartelaUm[3][5], cartelaDois[3][5], cartelaTres[3][5], pontuacaoUm = 0, pontuacaoDois = 0, pontuacaoTres = 0;
	int sorteados[60] = {0}, quantidade = 0, i = 0, sorteado = 0;
	
		srand(time(NULL));
		
		geraCartela(cartelaUm);  //função gera cartela vai gerar os valores aleatorios na cartela;
		geraCartela(cartelaDois);
		geraCartela(cartelaTres); 
		
	
		do{
			
			printaJogadores(cartelaUm, cartelaDois, cartelaTres, sorteados);
			printf("\nOs numeros sorteados foram: \n");	
			printaVetorSort(sorteados);  //funcao pra mostrar o vetor(numeros sorteados)
						
			getchar();
			
			sorteado = sorteiaNumeros(sorteados, quantidade); //gera valores unicos no vetor;
			
			if(contemValor(cartelaUm, sorteado)){  //contagem de pontos dizendo se o valor existe na cartela;
				pontuacaoUm++;
			}
			if(contemValor(cartelaDois, sorteado)){
				pontuacaoDois++;
			}
			if(contemValor(cartelaTres, sorteado)){
				pontuacaoTres++;
			}
		
			
			printf("\nO numero sorteado foi:%d\n", sorteado); //printa os vetores q passaram pela verificacao em sorteiaNumeros;
			
			
			quantidade++; //contador;
			
			system("cls");  
			
		}while((pontuacaoUm != 15) && (pontuacaoDois != 15) && (pontuacaoTres != 15)); //enquanto a pontuação de todos forem diferentes de 15, o jogo continua;
		
					
				printaJogadores(cartelaUm, cartelaDois, cartelaTres, sorteados);  
				
				printf("\nOs numeros sorteados foram: \n");	
				printaVetorSort(sorteados);
				
					
				printf("\n\n\nBINGOOOOOO!!!\n");
				
				if(pontuacaoUm == 15){
					printf("Jogador Um Venceu!"); //verificacao de qual dos jogadores ganhou;
				}
				if(pontuacaoDois == 15){
					printf("Jogador Dois venceu!");
				}if(pontuacaoTres == 15){
					printf("Jogador Tres venceu!");
				}
				
				
	
	
	return 0;
}


void geraCartela(int cartela[3][5]){  //recebe uma matriz [3][5] q é a cartela, para gerar valores unicos na mesma;
	
	int i = 0, j = 0, aux = 0;
			
		
	for(i = 0; i < 3; i++){

		for(j = 0; j < 5; j++){ //for pra percorrer a matriz;
		
			aux = 1 + rand() % 60; // variavel auxiliar recebe um valor aleatorio;
		
				if(contemValor(cartela, aux)){ //esse if faz uma verificação, caso o valor retorne true (valor repetido na cartela) ent decrementa o j
					j--;							// para gerar um novo valor para a posição j;	
				}
				else{
					cartela[i][j] = aux; //atribui o valor de aux na matriz;
				}
		}
	}
}

bool contemValor(int cartela[3][5], int numero) { //essa função percorre a matriz e verifica se o numero (aux) existe dentro dela;
	
	int i = 0, j = 0;
	
	for(i = 0; i < 3; i++){

		for(j = 0; j < 5; j++){
		
			if(cartela[i][j] == numero){ //return true = existe na cartela;
				return true;
			}
			
		}
	}
	
	return false;  //return false = nao existe na cartela;
}

void printaCartela(int cartela[3][5], int sorteados[]){  //funçao para mostrar os valores na cartela e substituir eles por "X" quando sao valores sorteados;
	
	int i = 0, j = 0;
	
		for(i = 0; i < 3; i++){

			for(j = 0; j < 5; j++){ //percorre a matriz;
			
			if(verificaVetor(sorteados, cartela[i][j])){    //envia o vetor e o numero da cartela na posiçao [i][j];
				printf("X\t");		//se retorna true = substitui por "X";						
			
			}else{	
				printf("%d\t", cartela[i][j]);  //return false = mantem o valor normal;
			}
			
		}
		printf("\n");
	}
	printf("\n");
}

int sorteiaNumeros(int numerosSorteados[], int quantidadeNumSort){  //sorteia numeros e assegura q os valores sejam unicos no vetor;
	
	int i = 0, numero = 0;	
	
	
	while(verificaVetor(numerosSorteados, numero)){  //enquanto verificaVetor for true, vai gerar numeros aleatorios pois o valor gerado já existe no vetor;
			numero = 1 + rand() % 60;  
	}
	
	
	numerosSorteados[quantidadeNumSort] = numero; //quando verificaVetor for false, é atribuido o numero sorteado no vetor na posição "quantidade";
	
	return numero;   
}

bool verificaVetor(int numerosSorteados[], int numero){  //percorre o vetor e diz se o valor enviado por parametro existe dentro do mesmo;
	
	int i = 0;
	
	for(i = 0; i < 60; i++){
		if(numerosSorteados[i] == numero){ //percorre o vetor;
			return true;      //retorna true se existe;
		}
	}
	return false; //retorna false se nao existe;
}

void printaVetorSort(int sorteados[]){ //funcao para mostrar o vetor
	
	int i = 0;
	
	for(i = 0; i < 60; i++){ 
		if(sorteados[i] != 0){ //foi atribuido os valores do vetor para 0 no inicio do jogo, e assim nessa condicional se o valor for igual a zero, nao eh mostrado;
		printf("[%d]\t", sorteados[i]); //vai printando os valores q sao sorteados ao passar pelas verificacoes;
		}
	}
	
}

void printaJogadores(int cartelaUm[3][5], int cartelaDois[3][5], int cartelaTres[3][5], int sorteados[]){ //funçao pra printar os jogadores e suas respectivas cartelas
	
				printf("-------- Jogador Um --------\n");   
				printaCartela(cartelaUm, sorteados);		
				
				printf("-------- Jogador Dois --------\n");
				printaCartela(cartelaDois, sorteados);
				
				printf("-------- Jogador Tres --------\n");
				printaCartela(cartelaTres, sorteados);
	
	
}

