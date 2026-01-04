#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void clearInputBuffer() {
    //Limpa caracteres restantes no buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addPessoa(Pessoa pessoas[], int* contaPessoas){
    if(*contaPessoas >= MAX_PESSOA){
        printf("Numero de usuarios topado\n");
        return;
    }

    Pessoa novaPessoa;

    printf("Digite o nome: ");
    if (fgets(novaPessoa.nome, NAME_LEN, stdin) == NULL) {
        printf("Erro ao ler o nome.\n");
        return;
    }
    novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0';

    printf("Digite a idade: ");
    while(scanf("%d", &novaPessoa.idade) != 1 || novaPessoa.idade <= 0){
        printf("Idade invalida. Por favor, insira uma idade valida:");
        clearInputBuffer();
    }
        clearInputBuffer();
    
        pessoas[*contaPessoas] = novaPessoa;
        (*contaPessoas)++;

        printf("Pessoa adicionada com sucesso. \n");
}

void listarPessoa(Pessoa pessoas[], int contaPessoa){
    if(contaPessoa == 0){
        printf("Nenhuma pessoa adicionadas. \n");
        return;
    }

    printf("\nPessoas Adicionadas: \n");
    for(int i = 0; i < contaPessoa; i++){
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n\n", pessoas[i].idade);
    }
}

void editarPessoa(Pessoa pessoas[], int contaPessoas){
    if(contaPessoas == 0){
        printf("Nenhuma pessoa para editar.\n");
        return;
    }

    int indice;
    printf("Digite o numero da pessoa que deseja editar (1 a %d): ", contaPessoas);
    if(scanf("%d", &indice) != 1 || indice < 1 || indice > contaPessoas){
        printf("Indice invalido. \n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    indice--; //Converte para indice do vetor

    printf("Novo nome: ");
    fgets(pessoas[indice].nome, NAME_LEN, stdin);
    pessoas[indice].nome[strcspn(pessoas[indice].nome, "\n")] = '\0';

    printf("Nova idade: ");
    while(scanf("%d", &pessoas[indice].idade) != 1 || pessoas[indice].idade <= 0){
        printf("Idade invalida. Digite novamente: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    printf("Pessoa editada com sucesso.\n");
}

void removerPessoa(Pessoa pessoas[], int *contaPessoas){
    if(*contaPessoas == 0){
        printf("Nenhuma pessoa para remover.\n");
        return;
    }

    int indice;

    printf("Digite o numero da pessoa que deseja remover (1 a %d): ", *contaPessoas);
    if(scanf("%d", &indice) != 1 || indice < 1 || indice > *contaPessoas){
        printf("Indice invalido.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    indice--; // Índice real do vetor

    //Desloca as pessoas para a esquerda
    for(int i = indice; i < *contaPessoas - 1; i++){
        pessoas[i] = pessoas[i + 1];
    }

    (*contaPessoas)--;

    printf("Pessoa removida com suceesso.\n");

}

void salvarPessoas(Pessoa pessoas[], int contaPessoas){
    FILE *file = fopen("data/pessoas.dat", "wb");

    if(file == NULL){
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    //Salva primeiro a quantidade
    fwrite(&contaPessoas, sizeof(int), 1, file);

    //Salva o vetor de structs
    fwrite(pessoas, sizeof(Pessoa), contaPessoas, file);

    fclose(file);

}

void carregarPessoas(Pessoa pessoas[], int *contaPessoas){
    FILE *file = fopen("data/pessoas.dat", "rb");

    if(file == NULL){
        //Arquivo não existe ainda -> primeira execução
        *contaPessoas = 0;
        return;
    }

    fread(contaPessoas, sizeof(int), 1,file);
    fread(pessoas, sizeof(Pessoa), *contaPessoas, file);

    fclose(file);
}