#include <stdio.h>
#include <stdlib.h>
#include "arvore_busca_binaria.h"

void displayMenu() {
    printf("\n==================================\n");
    printf("   ARVORE DE BUSCA BINARIA (BST)  \n");
    printf("==================================\n");
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
    Node* root = NULL;
    int option, value;
    Node* result = NULL;

    do {
        displayMenu();
        if (scanf("%d", &option) != 1) {
            printf("Entrada invalida!\n");
            // Limpa o buffer em caso de entrada não numérica
            while(getchar() != '\n'); 
            continue;
        }

        switch (option) {
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Valor %d inserido com sucesso.\n", value);
                break;
            case 2:
                printf("Digite o valor para remover: ");
                scanf("%d", &value);
                root = removeNode(root, value);
                printf("Comando de remocao executado para o valor %d.\n", value);
                break;
            case 3:
                printf("Digite o valor para buscar: ");
                scanf("%d", &value);
                result = search(root, value);
                if (result != NULL) {
                    printf(">>> Valor %d ENCONTRADO na arvore.\n", value);
                } else {
                    printf(">>> Valor %d NAO ENCONTRADO.\n", value);
                }
                break;
            case 4:
                printf("Arvore Em-Ordem: ");
                printInOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Arvore Pre-Ordem: ");
                printPreOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Arvore Pos-Ordem: ");
                printPostOrder(root);
                printf("\n");
                break;
            case 0:
                printf("Limpando a memoria e encerrando o programa...\n");
                freeTree(root);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (option != 0);

    return 0;
}