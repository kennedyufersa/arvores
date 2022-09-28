#ifndef ALUNO_CPP
#define ALUNO_CPP
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

#endif