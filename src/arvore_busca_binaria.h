//
// Created by arthu on 09/10/2026.
//

#ifndef TRABALHOPRG_ARVORE_BUSCA_BINARIA_H
#define TRABALHOPRG_ARVORE_BUSCA_BINARIA_H

// estrutura do Nó da árvore
typedef struct Node {
    int value;              // Valor armazenado no nó
    struct Node* left;      // Ponteiro para a subárvore esquerda
    struct Node* right;     // Ponteiro para a subárvore direita
} Node;

// funções declaradas:
Node* createNode(int value);
Node* insert(Node* root, int value);
Node* search(Node* root, int value);
Node* findMin(Node* root);
Node* removeNode(Node* root, int value);
void printInOrder(Node* root);
void printPreOrder(Node* root);
void printPostOrder(Node* root);
void freeTree(Node* root);

#endif //TRABALHOPRG_ARVORE_BUSCA_BINARIA_H
