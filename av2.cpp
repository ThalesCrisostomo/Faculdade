#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME "Henrique Duarte Coelho"
#define RA "3014200508"

main () {
	
	/* ATIV 1 */
	
	printf("Atividade 1\n");
	printf("Nome: %s, RA: %s\n\n", NOME, RA);
	
	/* ATIV 1 */
	
	/* ATIV 2 */
	
	int trocas = 1;
	int tamanho = 10;
	char vetor[] = RA;
	char temp;
	
	for(int i = 0; i < tamanho-1 && trocas == 1; i++) {
		trocas = 0;  
		
		for(int j = 0; j < tamanho-1-i; j++){
			
			if(vetor[j] > vetor[j+1]){
				temp = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = temp;
				trocas = 1;
				
			} 
		}
	}
	
	printf("Atividade 2\n");
	printf("Resultado: %s\n\n", vetor);
	
	/* ATIV 2 */
	
	/* ATIV 3 */
	
	/* Utilizando das variaveis do exercicio 2 */
	
	int soma = 0;
	int tempC;
	
	for (int i = 0; i < 10; i++) {
		tempC = (int)(vetor[i] - '0');
		soma += tempC;
		
	}
	
	soma = soma / 10;
	
	printf("Atividade 3\n");
	printf("Resultado: %d\n\n", soma);
	
	/* ATIV 3 */
	
	/* ATIV 4 */
	
	int n = 10;
	int low = 0;
	int high = n - 1;
	int found = 0;
	int mid;
	char k[10];
	char key = soma + '0';
	char *tempS;
	
	strcpy(k, vetor);
	
	while (low <= high && found == 0){
		
		mid = (low + high)/2;
		
		if (key < k[mid]) {
			high = mid - 1;
			
			} else if (key > k[mid]) {
			low = mid + 1;
			
			} else if (key == k[mid]) {
			found = 1;
			
		}
		
	}
	
	printf("Atividade 4\n");
	
	if (found == 1) {
		printf("Status: Encontrado, na posicao: %d\n\n", (mid+1)); // Não sei se vai querer a pós do CHAR ou da visão da pessoa (+1)
		
		} else {
		printf("Status: Nao Encontrado\n\n");
		
	}
	
	
	/* ATIV 4 */
	
	/* ATIV 5 */
	
	struct ALUNO {
		char *Cnome;
		char *Cra;
		float AV1;
	};
	
	struct ALUNO aluno;
	
	aluno.Cnome = NOME;
	aluno.Cra = RA;
	aluno.AV1 = 9.0;
	
	printf("Atividade 5\n");
	printf("Nome: %s, RA: %s, AV1: %0.1f\n", aluno.Cnome, aluno.Cra, aluno.AV1);
	
	/* ATIV 5 */
	
	system("pause");
	
}
