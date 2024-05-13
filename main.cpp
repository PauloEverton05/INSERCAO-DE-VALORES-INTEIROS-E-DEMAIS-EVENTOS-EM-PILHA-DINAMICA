#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No {
  	int valor;
  	struct No *proximo;
} NoPilha;

NoPilha *topoPilha = NULL;

void inicializarPilha() {
  	topoPilha = NULL;
}

int verificarTamanhoPilha() {
  	int cont = 0;
  	NoPilha *aux = topoPilha;
  	while (aux != NULL) {
    	cont++;
    	aux = aux->proximo;
  	}
  	return cont;
}

void exibirPilha() {
  	if (topoPilha == NULL) {
    	printf("Pilha vazia\n");
    	return;
  	}else{
  	NoPilha *aux = topoPilha;
  	printf("Pilha: ");
  	while (aux != NULL) {
    	printf("%d -> ", aux->valor);
    	aux = aux->proximo;
	}
  	}
  	printf("NULL\n");
}

void inserirElemPilhaPUSH(int valor) {
  	NoPilha *novoNo = (NoPilha *) malloc(sizeof(NoPilha));
  	if (novoNo == NULL) {
    	printf("Erro de alocação de memória\n");
    	return;
  	}

  	novoNo->valor = valor;
  	novoNo->proximo = topoPilha;
  	topoPilha = novoNo;
}

int excluirElemPilhaPOP() {
  	if (topoPilha == NULL) {
    	printf("Pilha vazia, não é possível remover elemento\n");
    	return -1;
  	}

  	int valorTopo = topoPilha->valor;
  	NoPilha *aux = topoPilha;
  	topoPilha = topoPilha->proximo;
  	free(aux);
  	return valorTopo;
}

void reinicializarPilha() {
  	while (topoPilha != NULL) {
    	NoPilha *aux = topoPilha;
    	topoPilha = topoPilha->proximo;
    	free(aux);
  	}
}

int main() {
	
	setlocale(LC_ALL,"Portuguese");
  	int opcao, valor;

  	do {
    	printf("\n—---------------------------------MENU—---------------------------------\n"
    	"1) inicializar pilha\n"
    	"2) verificar tamanho da pilha\n"
    	"3) exibir pilha\n"
    	"4) inserir elemento pilha PUSH\n"
    	"5) excluir elemento pilha POP\n"
    	"6) reinicializar pilha\n"
    	"7) Sair do programa\n"
    	"Opção: ");
    	scanf("%d", &opcao);

    	switch (opcao) {
      		case 1:
        	inicializarPilha();
        	printf("Pilha inicializada com sucesso\n");
        	break;
      	case 2:
        	valor = verificarTamanhoPilha();
        	printf("Tamanho da pilha: %d\n", valor);
        	break;
      	case 3:
        	exibirPilha();
        	break;
      	case 4:
        	printf("Valor a inserir: ");
        	scanf("%d", &valor);
        	inserirElemPilhaPUSH(valor);
        	printf("Elemento inserido com sucesso\n");
        	break;
      	case 5:
        	valor = excluirElemPilhaPOP();
        	if (valor != -1) {
        	printf("Elemento removido: %d\n", valor);
        	}
        	break;
      	case 6:
        	reinicializarPilha();
        	printf("Pilha reinicializada com sucesso\n");
        	break;
      	case 7:
        	printf("Saindo...\n");
        	break;
      	default:
        	printf("Opção inválida!\n");
    	}
  	} while (opcao != 7);

  	return 0;
}
