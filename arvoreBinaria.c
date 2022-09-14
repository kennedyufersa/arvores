#include<stdio.h>
#include "Aluno.c"

struct Node{
  Aluno aluno;
  struct Node* esq;
  struct Node* dir;
};

int main(int argc, char const *argv[])
{
  struct Node *raiz = (struct Node*)malloc(sizeof(struct Node));
  raiz->esq = 0;
  raiz->dir = 0;
  Aluno *a = criarAluno("Kennedy\0", 10, 8.5);
  raiz->aluno = *a;
  return 0;
}
