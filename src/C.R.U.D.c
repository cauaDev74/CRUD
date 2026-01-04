#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
#include "func.h"

int main(){
    Pessoa pessoas[MAX_PESSOA];
    int contaPessoas = 0;
    int escolha;

    carregarPessoas(pessoas, &contaPessoas);
    while(1){
        printf("\nMenu\n\n 1. Adicionar Pessoa.\n 2. Listar Pessoas.\n 3. Editar Pessoas.\n 4. Remover Pessoas.\n 5. Sair.\n\n Selecione: ");

        scanf("%d", &escolha);
        clearInputBuffer();

        system("cls");
        switch(escolha){
            case 1:
                addPessoa(pessoas, &contaPessoas);
                break;
            case 2:
                listarPessoa(pessoas, contaPessoas);
                break;
            case 3:
                editarPessoa(pessoas, contaPessoas);
                break;
            case 4:
                removerPessoa(pessoas, &contaPessoas);
                break;
            case 5:
                salvarPessoas(pessoas, contaPessoas);
                printf("Saindo do programa. Ate logo!\n");
                return 0;
            default:
                printf("Escolha invalida burro.\n");
        }
    }
    return 0;
}