//
// Created by arthu on 09/10/2026.
//

#ifndef TRABALHOPRG_ARVORE_BUSCA_BINARIA_H
#define TRABALHOPRG_ARVORE_BUSCA_BINARIA_H

// estrutura do Nó da árvore
typedef struct No {
    int valor;              // Valor armazenado no nó
    struct No* esquerda;    // Ponteiro para a subárvore à esquerda
    struct No* direita;     // Ponteiro para a subárvore à direita
} No;

// funções declaradas:
No* criarNo(int valor);
No* inserir(No* raiz, int valor);
No* buscar(No* raiz, int valor);
No* encontrarMinimo(No* raiz);
No* removerNo(No* raiz, int valor);
void imprimirEmOrdem(No* raiz);
void imprimirPreOrdem(No* raiz);
void imprimirPosOrdem(No* raiz);
void liberarArvore(No* raiz);

#endif //TRABALHOPRG_ARVORE_BUSCA_BINARIA_H
