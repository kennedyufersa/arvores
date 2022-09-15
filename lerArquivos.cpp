#include <stdio.h>

int main(){
    FILE *file = fopen("turma.dat", "r");
    int nota;
    char nome[80];
    int mat;

    if(!file){
        printf("Impossível de abrir o arquivo");
    }
    while(!feof(file)){
        fscanf(file, "%d %d %s", &nota, &mat, nome);
        printf("Nome: %s\nMatricula: %d\nNota:%d\n\n", nome, mat, nota);
    }

}