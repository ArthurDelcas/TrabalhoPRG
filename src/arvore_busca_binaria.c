#include <stdio.h>
#include <stdlib.h>
#include "arvore_busca_binaria.h"

// Cria um novo nó, alocando memória dinamicamente
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Insere um novo valor respeitando a regra da Árvore de Busca Binária
No* inserir(No* raiz, int valor) {
    // Caso base: se a árvore/subárvore estiver vazia, cria e retorna o novo nó
    if (raiz == NULL) {
        return criarNo(valor);
    }

    // Se o valor for menor, insere na subárvore à esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // Se o valor for maior, insere na subárvore à direita
    else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    // Valores duplicados são ignorados nesta implementação

    return raiz;
}

// Busca um valor específico na árvore
No* buscar(No* raiz, int valor) {
    // Caso base: raiz nula ou valor encontrado
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    // Se o valor buscado for maior que o da raiz atual, busca na direita
    if (raiz->valor < valor) {
        return buscar(raiz->direita, valor);
    }

    // Caso contrário, busca na esquerda
    return buscar(raiz->esquerda, valor);
}

// Encontra o menor valor de uma subárvore (usado principalmente na remoção)
// O menor valor sempre estará o mais à esquerda possível
No* encontrarMinimo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// Remove um nó da árvore tratando os 3 casos possíveis
No* removerNo(No* raiz, int valor) {
    if (raiz == NULL) return raiz;

    // Navega pela árvore até encontrar o nó a ser removido
    if (valor < raiz->valor) {
        raiz->esquerda = removerNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerNo(raiz->direita, valor);
    } else {
        // Nó encontrado. Avaliando os casos de remoção:

        // Casos 1 e 2: Nó com apenas um filho ou nenhum filho (folha)
        if (raiz->esquerda == NULL) {
            No* temporario = raiz->direita;
            free(raiz);
            return temporario;
        } else if (raiz->direita == NULL) {
            No* temporario = raiz->esquerda;
            free(raiz);
            return temporario;
        }

        // Caso 3: Nó com dois filhos.
        // Solução: Substituir o valor do nó pelo menor valor da subárvore à direita (sucessor)
        No* temporario = encontrarMinimo(raiz->direita);
        raiz->valor = temporario->valor; // Copia o valor do sucessor

        // Remove o sucessor original da subárvore à direita
        raiz->direita = removerNo(raiz->direita, temporario->valor);
    }
    return raiz;
}

// Percorre a árvore Em-Ordem (Esquerda, Raiz, Direita) - Imprime em ordem crescente
void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

// Percorre a árvore em Pré-Ordem (Raiz, Esquerda, Direita)
void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

// Percorre a árvore em Pós-Ordem (Esquerda, Direita, Raiz)
void imprimirPosOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirPosOrdem(raiz->esquerda);
        imprimirPosOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Libera toda a memória alocada para a árvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz); // Libera o nó atual em pós-ordem para não perder a referência dos filhos
    }
}