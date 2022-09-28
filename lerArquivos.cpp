#include "Aluno.cpp"
#include <stdio.h>

Aluno *getAlunos(char *arquivo, int &quantidade) {
    FILE *file = fopen(arquivo, "r");
    Aluno *res = (Aluno *)malloc(50 * sizeof(Aluno));
    float nota;
    char *nome;
    int mat;
    int i = 0;
    Aluno aux;
    if (!file) {
        printf("Impossível de abrir o arquivo");
    }
    while (!feof(file)) {
        // fscanf(file, "%d %d %s", &nota, &mat, nome);
        // printf("Nome: %s\nMatricula: %d\nNota:%d\n\n", nome, mat, nota);
        nome = (char*)malloc(30*sizeof(char));
        fscanf(file, "%f %d %s", &nota, &mat, nome);
        aux = criarAluno2(nome, mat, nota);
        res[i++] = aux;
    }
    quantidade = i;
    return res;
}
/*
int main() {
    char *arquivo = (char *)"turma.dat";
    Aluno *alunos = getAlunos(arquivo);
}*/