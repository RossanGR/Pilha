#include<stdio.h>
#include <stdlib.h>
#define TAMANHO_MAXIMO 10

typedef struct {  
  char titulo[50];
  int valor;
  float peso;
  int topoOficial;
} DOCUMENTO;

typedef struct {
	DOCUMENTO elementos[TAMANHO_MAXIMO];
	DOCUMENTO* topo;
} PILHA;

void inicializarPilha(PILHA* pilha);
void limpaPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);
int push(PILHA* pilha, DOCUMENTO* meuDoc);
void pop(PILHA* pilha);
int length(PILHA* pilha);

int main () {
	PILHA minhaPilha;
  DOCUMENTO meuDoc;
  // meuDoc.valor=2; //Comentar para interagir com USUARIO.
  int qtd,j;
  

	inicializarPilha(&minhaPilha);
// ************* INICIO INTERAÇÃO COM USUARIO ********
  // printf("Quantos numeros vc quer colocar na pilhar?: \n");
  // scanf("%d",&qtd);

  // for(j=0; j<qtd;j++){
  //   printf("Digite um numero: ");
  //   scanf("%d",&meuDoc.valor);
  //   	push(&minhaPilha, &meuDoc);
  // }
// ************** FIM INTERAÇÃO COM USUARIO **********


   meuDoc.valor=2;
   push(&minhaPilha, &meuDoc);

   meuDoc.valor=3;
   push(&minhaPilha, &meuDoc);

   meuDoc.valor=1;
   push(&minhaPilha, &meuDoc);
	
  
	imprimirPilha(&minhaPilha);

	pop(&minhaPilha);

	imprimirPilha(&minhaPilha);

  limpaPilha(&minhaPilha);
	

	imprimirPilha(&minhaPilha);
	
}

void pop(PILHA* pilha){
	if(length(pilha) > 0){
		 pilha->topo->topoOficial -= 1;
	}
}

int push(PILHA* pilha, DOCUMENTO* meuDoc) {
  
	if(length(pilha) < TAMANHO_MAXIMO) {
		 pilha->topo->topoOficial += 1;
		pilha->elementos[pilha->topo->topoOficial] = *meuDoc;
		
		return 1;
	}
	
	return 0;
}



void inicializarPilha(PILHA* pilha) {
  
 pilha->topo = (DOCUMENTO*) malloc(sizeof(DOCUMENTO));
 pilha->topo->topoOficial=-1;
 
}

void limpaPilha(PILHA* pilha) {
	 pilha->topo->topoOficial=-1;
}

int length(PILHA* pilha) {
	return 	 pilha->topo->topoOficial + 1;
}

void imprimirPilha(PILHA* pilha) {
 
	printf("PILHA :)\n");
	
	for(int i = pilha->topo->topoOficial; i >= 0; i--)
		printf("|_%d_|\n", pilha->elementos[i].valor);
		
	printf("\n\n");
}