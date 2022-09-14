#ifndef ALUNO_C
#define ALUNO_C
#include <stdio.h>
#include <stdlib.h>

typedef float Nota;
typedef unsigned int matricula; 

typedef struct aluno{
  const char* nome;
  matricula Id;
  Nota nota;
} Aluno;

Aluno* criarAluno(const char *nome, matricula Id, Nota n){
  Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
  novo->nome = nome;
  novo->nota = n;
  novo->Id = Id;
  return novo;
}

Aluno criarAluno2(const char *nome, matricula Id, Nota n){
  Aluno novo;
  novo.nome = nome;
  novo.nota = n;
  novo.Id = Id;
  return novo;
}

/*int main(int argc, char const *argv[]){
  Aluno* a = criarAluno("Kennedy\0", 10, 8.);
  printf("Nome: %s\n", a->nome);
  printf("Id: %d\n", a->Id);
  printf("Nota: %f\n", a->nota);

  Aluno b = criarAluno2("Kennedy\0", 10, 8.);
  printf("Nome: %s\n", b.nome);
  printf("Id: %d\n", b.Id);
  printf("Nota: %f\n", b.nota);
  return 0;
}*/




#endif