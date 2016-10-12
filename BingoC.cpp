#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM_MAX 5
#define TAM_SORT 50

// Função pega da internet.
int myRand(int low, int high) {
	
   return rand() % (high - low + 1) + low;
   
}
// fim da internet


// Função para validar se o numero existe na Array Multi, se existe ele retorna Bool e a posição por REF.
bool inCartela(int array[TAM_MAX][TAM_MAX], int i, int *a, int *b) {
	
	for (int x = 0; x < TAM_MAX; x++) {
		
		for (int y = 0; y < TAM_MAX; y++) {
			
			if (array[x][y] == i) {
				
				*a = x;
				*b = y;
				return true;
				
			}
	
		}
	
	}
	
	return false;

}

// Função para validar se o numero existe na Array, se existe ele retorna Bool e a posição por REF.
bool inBingo(int array[TAM_SORT], int i, int *a) {
	
	for (int x = 0; x < TAM_SORT; x++) {
	
			if (array[x] == i) {
				
				*a = x;
				return true;
				
			}
		
	}
	
	return false;
	
}

// Procedure para Popular a Array Multi
void popularCartela(int cartela[TAM_MAX][TAM_MAX]) {
	
	int tmpRand;
	int a;
	int b;
	
	tmpRand = myRand(1, 99);
	
	for (int x = 0; x < TAM_MAX; x++) {
		
		for (int y = 0; y < TAM_MAX; y++) {
			
			while (inCartela(cartela, tmpRand, &a, &b) == true) {
			
				tmpRand = myRand(1, 99);
			
			}
			
			cartela[x][y] = tmpRand;
		
		}
		
	}
	
}

// Procedure para Exibir a Array
void exibeCartela(int cartela[TAM_MAX][TAM_MAX]) {
	
	for (int x = 0; x < TAM_MAX; x++) {
		
		for (int y = 0; y < TAM_MAX; y++) {
		
			printf("\t%d", cartela[x][y]);
		
		}
		
		printf("\n");
		
	}
	
}

// Procedure para Popular a Array
void popularBingo(int bingo[TAM_SORT]) {
	
	int tmpRand;
	int a;
	tmpRand = myRand(1, 99);
	
	for (int x = 0; x < TAM_SORT; x++) {
	
		while (inBingo(bingo, tmpRand, &a) == true) {
			
				tmpRand = myRand(1, 99);
			
		}
			
		bingo[x] = tmpRand;
			
	}
			
	
}

// Procedure para Comparar a Array Multi e Array normal, armazenando em outra Array Multi se existente
void conferirJogo(int cartela[TAM_MAX][TAM_MAX], int bingo[TAM_SORT], bool sorteado[TAM_MAX][TAM_MAX]) {
	
	int a;
		
	for (int x = 0; x < TAM_MAX; x++) {
		
		for (int y = 0; y < TAM_MAX; y++) {
			
			printf("\t%d", cartela[x][y]);
			
			if (inBingo(bingo, cartela[x][y], &a) == true) {
				
				sorteado[x][y] = true;
				printf("*");
				
			}
	
		}
		
		printf("\n");
		
	}
}

// Checa se foi Bingo e as Quinas, alem de apresentar os valores!
bool validarJogo(int cartela[TAM_MAX][TAM_MAX], bool sorteado[TAM_MAX][TAM_MAX]) {
	
	int tmpX = 0;
	int tmpY = 0;
	int tmpQ = 0;
	int tmpI;
	
	// Checa se foi BINGO (DUVIDO)
	for (int x = 0; x < TAM_MAX; x++) {
		
		for (int y = 0; y < TAM_MAX; y++) {
			
			if (sorteado[x][y] == true) {
				tmpX++;
			}
			
		}
		
	}
	
	if (tmpX == 25) {
		printf("BINGO! GANHOU!");
		return true;
	}
	// Checa se foi BINGO (DUVIDO) /* FIM */
	
	//Checar Quinas - Horizontal
	for (int x = 0; x < TAM_MAX; x++) {
		
		tmpY = 0;
		for (int y = 0; y < TAM_MAX; y++) {
			
			if (sorteado[x][y] == true) {
				tmpY++;
			}
			
			if (tmpY == 5) {
				printf("\n Quina Acertada (Horizontal): \n");
			
				for (int i = 0; i < TAM_MAX; i++) {
					printf(" %d", cartela[x][i]);
				}
			
				tmpQ++;
			}
			
		}
		
	}
	
	//Checar Quinas - Vertical
	for (int x = 0; x < TAM_MAX; x++) {
		
		tmpX = 0;
		for (int y = 0; y < TAM_MAX; y++) {
			
			if (sorteado[y][x] == true) {
				tmpX++;
			}
			
			if (tmpX == 5) {
				printf("\n Quina Acertada (Vertical): \n");
			
				for (int i = 0; i < TAM_MAX; i++) {
					printf(" %d\n", cartela[i][x]);
				}
			
				tmpQ++;
			}
			
		}
		
	}
	
	//Checar Quinas - Diagonal
	tmpX = 0;
		for (int y = 0; y < TAM_MAX; y++) {
			
			if (sorteado[y][y] == true) {
				tmpX++;
			}
			
		}
		
		if (tmpX == 5) {
				printf("\n Quina Acertada (Diagonal): \n");

				for (int i = 0; i < TAM_MAX; i++) {
					
					for (int x = 0; x < i; x++) {
						printf("\t");
					}
					
						printf(" %d\n", cartela[i][i]);
					}
				
					tmpQ++;
			}
		
		
	tmpX = 0;
		for (int y = 0; y < 5; y++) {
			tmpI = (4 - y);
			if (sorteado[y][tmpI] == true) {
				tmpX++;
			}
			
		}
		
		if (tmpX == 5) {
				printf("\n Quina Acertada (Diagonal): \n");

				for (int i = 4; i >= 0; i--) {
					
					tmpI = (4 - i);
					for (int x = 0; x < i; x++) {
						printf("\t");
					}
					
						printf(" %d\n", cartela[tmpI][i]);
					}
				
					tmpQ++;
			}
	
		
	// Exibe winner
	if (tmpQ > 0) {
		printf("\n Voce acertou: %d, Quinas! \n", tmpQ);
		return true;
	}
	
	return false;
}

main () {
	
	srand(time(NULL));
	int cartela[TAM_MAX][TAM_MAX];
	int bingo[TAM_SORT];
	bool sorteado[TAM_MAX][TAM_MAX];
	bool ganhouAlgo;
	
	printf("\n Seja bem vindo! Vamos jogar bingo? retire sua cartela! \n");
	popularCartela(cartela);
	system("PAUSE");
	printf("\n Observe os numeros da sua cartela! \n");
	exibeCartela(cartela);
	system("PAUSE");
	popularBingo(bingo);
	printf("\n");
	printf("\n Os numeros sorteados sao (Marcados com *): \n");
	conferirJogo(cartela, bingo, sorteado);
	ganhouAlgo = validarJogo(cartela, sorteado);
	printf("\n Agora vamos conferir! \n");
	system("PAUSE");
	
	if (ganhouAlgo) {
		
		printf("\n Parabens Campeao!");
		
	} else {
		
		printf("\n Voce nao ganhou! mas, nao fique triste e tente novamente!");
		
	}
	
}
