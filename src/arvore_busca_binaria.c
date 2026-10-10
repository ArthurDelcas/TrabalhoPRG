#include <stdio.h>
#include <stdlib.h>
#include "arvore_busca_binaria.h"

// Cria um novo nó, alocando memória dinamicamente
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insere um novo valor respeitando a regra da BST
Node* insert(Node* root, int value) {
    // Caso base: se a árvore/subárvore estiver vazia, cria e retorna o novo nó
    if (root == NULL) {
        return createNode(value);
    }

    // Se o valor for menor, insere na subárvore esquerda
    if (value < root->value) {
        root->left = insert(root->left, value);
    } 
    // Se o valor for maior, insere na subárvore direita
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    // Valores duplicados são ignorados nesta implementação

    return root;
}

// Busca um valor específico na árvore
Node* search(Node* root, int value) {
    // Caso base: raiz nula ou valor encontrado
    if (root == NULL || root->value == value) {
        return root;
    }

    // Se o valor for maior que o da raiz, busca na direita
    if (root->value < value) {
        return search(root->right, value);
    }

    // Caso contrário, busca na esquerda
    return search(root->left, value);
}

// Encontra o menor valor de uma subárvore (usado na remoção)
// O menor valor sempre estará o mais à esquerda possível
Node* findMin(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Remove um nó da árvore tratando os 3 casos possíveis
Node* removeNode(Node* root, int value) {
    if (root == NULL) return root;

    // Navega pela árvore até encontrar o nó a ser removido
    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        // Nó encontrado. Avaliando os casos de remoção:

        // Caso 1 e 2: Nó com apenas um filho ou nenhum filho (folha)
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Caso 3: Nó com dois filhos. 
        // Solução: Substituir o valor do nó pelo menor valor da subárvore direita (sucessor em-ordem)
        Node* temp = findMin(root->right);
        root->value = temp->value; // Copia o valor do sucessor
        
        // Remove o sucessor original da subárvore direita
        root->right = removeNode(root->right, temp->value);
    }
    return root;
}

// Percorre a árvore Em-Ordem (Esquerda, Raiz, Direita) - Imprime os valores em ordem crescente
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->value);
        printInOrder(root->right);
    }
}

// Percorre a árvore em Pré-Ordem (Raiz, Esquerda, Direita)
void printPreOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Percorre a árvore em Pós-Ordem (Esquerda, Direita, Raiz)
void printPostOrder(Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->value);
    }
}

// Libera toda a memória alocada para a árvore, evitando memory leaks
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root); // Libera o nó atual em pós-ordem para não perder a referência dos filhos
    }
}