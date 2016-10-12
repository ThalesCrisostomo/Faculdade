#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM_MAX 5

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
bool inBingo(int array[(TAM_MAX*TAM_MAX)], int i, int *a) {
	
	for (int x = 0; x < (TAM_MAX * TAM_MAX); x++) {
	
			if (array[x] == i) {
				
				*a = x;
				return true;
				
			}
		
	}
	
	return false;
	
}

// Função para Popular a Array Multi
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

// Função para Exibir a Array
void exibeCartela(int cartela[TAM_MAX][TAM_MAX]) {
	
	for (int x = 0; x < TAM_MAX; x++) {
		
		for (int y = 0; y < TAM_MAX; y++) {
		
			printf("|%d", cartela[x][y]);
		
		}
		
		printf("\n");
		
	}
	
}

// Função para Popular a Array
void popularBingo(int bingo[(TAM_MAX*TAM_MAX)]) {
	
	int tmpRand;
	int a;
	
	for (int x = 0; x < (TAM_MAX * TAM_MAX); x++) {
	
		while (inBingo(bingo, tmpRand, &a) == true) {
			
				tmpRand = myRand(1, 99);
			
		}
			
		bingo[x] = tmpRand;
			
	}
			
	
}

// Função para Comparar a Array Multi e Array normal, armazenando em outra Array Multi se existente
void conferirJogo(int cartela[TAM_MAX][TAM_MAX], int bingo[(TAM_MAX*TAM_MAX)], bool sorteado[TAM_MAX][TAM_MAX]) {
	
	int a;
		
	for (int x = 0; x < TAM_MAX; x++) {
		
		for (int y = 0; y < TAM_MAX; y++) {
			
			printf("| %d", cartela[x][y]);
			
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
	
	// Checa se foi BINGO (DUVIDO)
	for (int x = 0; x < TAM_MAX; x++) {
		
		for (int y = 0; y < TAM_MAX; y++) {
			
			if (sorteado[x][y] == true) {
				tmpX++;
			}
			
		}
		
	}
	
	if (tmpX == 50) {
		printf("BINGO! GANHOU!");
		return true;
	}
	// Checa se foi BINGO (DUVIDO) /* FIM */
	
	//Checar Quinas - Vertical
	for (int x = 0; x < TAM_MAX; x++) {
		
		tmpY = 0;
		for (int y = 0; y < TAM_MAX; y++) {
			
			if (sorteado[x][y] == true) {
				tmpY++;
			}
			
		}
		
		if (tmpY == 5) {
			tmpQ++;
		}
		
	}
	
	//Checar Quinas - Horizontal
	for (int x = 0; x < TAM_MAX; x++) {
		
		tmpX = 0;
		for (int y = 0; y < TAM_MAX; y++) {
			
			if (sorteado[y][x] == true) {
				tmpX++;
			}
			
		}
		
		if (tmpX == 5) {
			tmpQ++;
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
			tmpQ++;
		}
		
	tmpX = 0;
		for (int y = 4; y >= 0; y--) {
			
			if (sorteado[y][y] == true) {
				tmpX++;
			}
			
		}
		
		if (tmpX == 5) {
			tmpQ++;
		}
		
		
	// Exibe winner
	if (tmpQ > 0) {
		printf("Voce acertou: %d, Quinas!", tmpQ);
		return true;
	}
	
	return false;
}

main () {
	
	srand(time(NULL));
	int cartela[TAM_MAX][TAM_MAX];
	int bingo[(TAM_MAX*TAM_MAX)];
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
	printf("\n Os numeros sorteados sao: \n");
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
