#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "arvore_busca_binaria.h"

void exibirMenu() {
    printf("1. Inserir valor\n");
    printf("2. Remover valor\n");
    printf("3. Buscar valor\n");
    printf("4. Exibir Em-Ordem (Crescente)\n");
    printf("5. Exibir Pre-Ordem\n");
    printf("6. Exibir Pos-Ordem\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    No* raiz = NULL;
    int opcao, valor;
    No* resultado = NULL;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            // Limpa o buffer em caso de entrada não numérica
            while(getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                printf("Valor %d inserido com sucesso.\n", valor);
                break;
            case 2:
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);
                raiz = removerNo(raiz, valor);
                printf("Comando de remocao executado para o valor %d.\n", valor);
                break;
            case 3:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                resultado = buscar(raiz, valor);
                if (resultado != NULL) {
                    printf(">>> Valor %d ENCONTRADO na arvore.\n", valor);
                } else {
                    printf(">>> Valor %d NAO ENCONTRADO.\n", valor);
                }
                break;
            case 4:
                printf("Arvore Em-Ordem: ");
                imprimirEmOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Arvore Pre-Ordem: ");
                imprimirPreOrdem(raiz);
                printf("\n");
                break;
            case 6:
                printf("Arvore Pos-Ordem: ");
                imprimirPosOrdem(raiz);
                printf("\n");
                break;
            case 0:
                printf("Limpando a memoria e encerrando o programa...\n");
                liberarArvore(raiz);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}