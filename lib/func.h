#ifndef FUNC_H
#define FUNC_H

#include "structs.h"

void clearInputBuffer();

void addPessoa(Pessoa pessoas[], int* contaPessoas);

void listarPessoa(Pessoa pessoas[], int contaPessoa);

void editarPessoa(Pessoa pessoas[], int contaPessoas);

void removerPessoa(Pessoa pessoas[], int *contaPessoas);

void salvarPessoas(Pessoa pessoas[], int contaPessoas);

void carregarPessoas(Pessoa pessoas[], int *contaPessoas);

#endif