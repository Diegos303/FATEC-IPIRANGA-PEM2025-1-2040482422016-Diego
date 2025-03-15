/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Modularizaçao                    *
* Data - 15/03/2025                                      * 
* Autor: Diego Souza                                     *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int estocarProduto(char (*estoque)[10][10], char (*nomeProduto)[10][50]) {
    char codigoProduto[10], nome[50];
    int rua, gondola;
    
    printf("Digite o codigo do produto: ");
    scanf("%s", codigoProduto);
    
    printf("Digite o nome do produto: ");
    scanf("%s", nome);  

    do {
        printf("Digite o numero da rua (1 - Rua A, 2 - Rua B, 3 - Rua C): ");
        scanf("%d", &rua);
        if (rua < 1 || rua > 3) {
            printf("Erro! Numero da rua invalido. Tente novamente.\n");
        }
    } while (rua < 1 || rua > 3);  // Continua pedindo até que a rua seja de 1 a 3
    
    do {
        printf("Digite o numero da gondola (1 a 10): ");
        scanf("%d", &gondola);
        if (gondola < 1 || gondola > 10) {
            printf("Erro! Numero da gondola invalido. Tente novamente.\n");
        }
    } while (gondola < 1 || gondola > 10);  // Continua pedindo até que a gondola seja de 1 a 10

    rua -= 1;  
    gondola -= 1;  

    char *ponteiroEstoque = &estoque[rua][gondola][0];
    char *ponteiroNomeProduto = &nomeProduto[rua][gondola][0];

    // Verifica se a gôndola está ocupada
    if (strcmp(ponteiroEstoque, "") == 0) {
        strcpy(ponteiroEstoque, codigoProduto);
        strcpy(ponteiroNomeProduto, nome);
        printf("Produto %s (%s) estocado com sucesso na Gondola %d da Rua %c.\n", ponteiroEstoque, ponteiroNomeProduto, gondola + 1, 'A' + rua);
        return 1; 
    } else {
        printf("Erro: Gondola ja ocupada com o produto %s (%s).\n", ponteiroEstoque, ponteiroNomeProduto);
        return 0; 
    }
}


int retirarProduto(char (*estoque)[10][10], char (*nomeProduto)[10][50]) {
    char codigoProduto[10];
    int encontrado = 0;

    printf("Digite o codigo do produto para retirada: ");
    scanf("%s", codigoProduto);
    
    // Buscar o código do produto
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (strcmp(estoque[i][j], codigoProduto) == 0) {
                printf("Produto %s (%s) retirado da Gondola %d da Rua %c.\n", codigoProduto, nomeProduto[i][j], j + 1, 'A' + i);
                char *ponteiroEstoque = estoque[i][j];
                char *ponteiroNome = nomeProduto[i][j];
                strcpy(ponteiroEstoque, ""); 
                strcpy(ponteiroNome, ""); 
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("Erro!!! Produto nao encontrado no estoque.\n");
        return 0; 
    }
    return 1; 
}

int main() {
    char estoque[3][10][10], nomeProduto[3][10][50];
    int opcao;

    // Inicializar as variáveis com a string vazia
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            char *ponteiroEstoque = estoque[i][j];
            char *ponteiroNome = nomeProduto[i][j];
            strcpy(ponteiroEstoque, ""); 
            strcpy(ponteiroNome, "");
        }
    }

    do {
        printf("\n1. Estocar produto\n");
        printf("2. Retirar produto\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            estocarProduto(estoque, nomeProduto);
        } else if (opcao == 2) {
            retirarProduto(estoque, nomeProduto);
        }
    } while (opcao != 3);

    printf("Saindo do sistema.\n");

    
    return 0;
}