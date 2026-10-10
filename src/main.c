#include <stdio.h>
#include <stdlib.h>
#include "arvore_busca_binaria.h"

void exibirMenu() {
    printf("1. Inserir valor\n");
    printf("2. Remover valor\n");
    printf("3. Buscar valor\n");
    printf("4. Exibir Em-Ordem (Crescente)\n");
    printf("5. Exibir Pré-Ordem\n");
    printf("6. Exibir Pós-Ordem\n");
    printf("0. Sair\n");
}

int main() {
    No* raiz = NULL;
    int opcao, valor;
    No* resultado = NULL;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida!\n");
            // limpa o buffer se a entrada não for um número
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
                printf("Comando de remoção executado para o valor %d.\n", valor);
                break;
            case 3:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                resultado = buscar(raiz, valor);
                if (resultado != NULL) {
                    printf(" Valor (%d) ENCONTRADO na árvore.\n", valor);
                } else {
                    printf(" O valor informado (%d) NÃO FOI ENCONTRADO na árvore.\n", valor);
                }
                break;
            case 4:
                printf("Árvore Em-Ordem: ");
                imprimirEmOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Árvore Pre-Ordem: ");
                imprimirPreOrdem(raiz);
                printf("\n");
                break;
            case 6:
                printf("Árvore Pos-Ordem: ");
                imprimirPosOrdem(raiz);
                printf("\n");
                break;
            case 0:
                printf("Limpando a memória e encerrando o programa...\n");
                liberarArvore(raiz);
                break;
            default:
                printf("Opcão inválida! Tente novamente \n");
        }
    } while (opcao != 0);

    return 0;
}