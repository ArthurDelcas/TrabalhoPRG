# Projeto: Árvore de Busca Binária (ABB) e Algoritmos de Ordenação

**Curso:** Engenharia de Telecomunicações
**Disciplina:** Programação II
**Grupo:** Arthur Delcastanhel, Pablo Henrique Dias e Gustavo Ferreira de Castro

Esse projeto é uma implementação em linguagem C de uma Árvore de Busca Binária, desenvolvida como requisito acadêmico para apresentação em seminário avaliativo.

## Funcionalidades

O projeto é interativo e executado via terminal de qualquer IDE, com o seguinte menu de operações:

**Manipulação da Árvore:**
* Inserção de novos valores (respeitando as regras da ABB).
* Remoção de valores (tratando todos os cenários: nó folha, nó com um filho e nó com dois filhos).
* Busca de valores na estrutura.

**Navegação (Travessias):**
* Em-Ordem (Esquerda, Raiz, Direita) - exibe os dados de forma crescente.
* Pré-Ordem (Raiz, Esquerda, Direita).
* Pós-Ordem (Esquerda, Direita, Raiz) - método utilizado internamente para liberar a memória da árvore.

## Estrutura do Projeto

O código foi estrutura aplicando boas práticas de um projeto acadêmico, respeitando os escopos de responsabilidade:

```text
TrabalhoPRG/
├── CMakeLists.txt      # Arquivo de configuração para o sistema de compilação
├── README.md           # Documentação do projeto
└── src/
    ├── arvore_busca_binaria.c    # Implementação lógica das operações da árvore
    ├── arvore_busca_binaria.h    # Protótipos e estrutura da Árvore de Busca Binária
    └── main.c                    # Ponto de entrada (interface e menu do usuário)
```

## Pré-requisitos

Para compilar e executar este projeto, você precisará ter instalado em sua máquina:
* Um compilador C (como `gcc` ou `clang`).
* O sistema de automação de compilação [CMake](https://cmake.org/) (versão 3.10 ou superior).

##  Como compilar e executar

Recomenda-se a compilação *out-of-source* (criando um diretório específico para os arquivos binários) para manter o diretório do código fonte limpo.

Abra o terminal na raiz do projeto (onde o arquivo `CMakeLists.txt` está localizado) e execute os seguintes comandos:

1. Crie o diretório de build e acesse-o:
   ```bash
   mkdir build
   cd build
   ```

2. Gere os arquivos de compilação:
   ```bash
   cmake ..
   ```

3. Compile o código:
   ```bash
   cmake --build .
   ```

4. Execute o programa:
    * **No Linux/macOS:**
      ```bash
      ./TrabalhoPRG
      ```
    * **No Windows:**
      ```bash
      .\TrabalhoPRG.exe
      ```