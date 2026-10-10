#include <stdio.h>
#include <stdlib.h>
#include "arvore_busca_binaria.h"

// cria um novo nó, alocando a memória automaticamente
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

// insere um novo valor respeitando a regra (ideia por trás) da Árvore de Busca Binária
No* inserir(No* raiz, int valor) {
    // caso base: se a árvore/subárvore estiver vazia, vai criar e retornar o novo nó
    if (raiz == NULL) {
        return criarNo(valor);
    }

    // se o valor for menor, insere na subárvore à esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // se o valor for maior, insere na subárvore à direita
    else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    // os valores duplicados são ignorados ao inseri-los

    return raiz;
}

// busca um valor específico na árvore
No* buscar(No* raiz, int valor) {
    // caso base: raiz nula ou valor encontrado
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    // se o valor buscado for maior que o da raiz atual, busca na direita
    if (raiz->valor < valor) {
        return buscar(raiz->direita, valor);
    }

    // se for menor, busca na esquerda
    return buscar(raiz->esquerda, valor);
}

// encontra o menor valor de uma subárvore (usado principalmente na remoção)
// o menor valor sempre estará o mais à esquerda possível
No* encontrarMinimo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// remove um nó da árvore tratando os 3 casos possíveis
No* removerNo(No* raiz, int valor) {
    if (raiz == NULL) return raiz;

    // percorre a árvore até encontrar o nó a ser removido
    if (valor < raiz->valor) {
        raiz->esquerda = removerNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerNo(raiz->direita, valor);
    } else {
        // Nó foi encontrado, passa a avaliar os casos de remoção:

        // casos 1 e 2: Nó com apenas um filho ou nenhum filho (folha)
        if (raiz->esquerda == NULL) {
            No* temporario = raiz->direita;
            free(raiz);
            return temporario;
        } else if (raiz->direita == NULL) {
            No* temporario = raiz->esquerda;
            free(raiz);
            return temporario;
        }

        // caso 3: Nó com dois filhos.
        // solução: substituir o valor do nó pelo menor valor da subárvore à direita (sucessor)
        No* temporario = encontrarMinimo(raiz->direita);
        raiz->valor = temporario->valor; // copia o valor do sucessor

        // remove o sucessor original da subárvore à direita
        raiz->direita = removerNo(raiz->direita, temporario->valor);
    }
    return raiz;
}

// percorre a árvore Em-Ordem (esquerda, raiz, direita) e depois imprime em ordem crescente
void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

// percorre a árvore em Pré-Ordem (raiz, esquerda, direita)
void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

// percorre a árvore em Pós-Ordem (esquerda, direita, raiz)
void imprimirPosOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirPosOrdem(raiz->esquerda);
        imprimirPosOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// libera toda a memória alocada para a árvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz); // libera o nó atual em pós-ordem para não perder a referência dos filhos
    }
}