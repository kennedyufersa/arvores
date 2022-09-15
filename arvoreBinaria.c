#include<stdio.h>
#include "Aluno.c"

struct Node{
  Aluno aluno;
  struct Node* esq;
  struct Node* dir;
};

struct Node* inserir(struct Node* r, Aluno a){
  if(r != 0){
    if(a.nota < r->aluno.nota){
      return inserir(r->esq, a);
    }else if(a.nota > r->aluno.nota){
      return inserir(r->dir, a);
    }
  }
  return r;
}

int main(int argc, char const *argv[])
{
  struct Node *raiz = (struct Node*)malloc(sizeof(struct Node));
  raiz->esq = 0;
  raiz->dir = 0;
  Aluno *a = criarAluno("Kennedy\0", 10, 8.5);
  raiz->aluno = *a;

  Aluno *vetor[5];
  vetor[0] = criarAluno("aluno11\0", 11, 9.9);
  vetor[1] = criarAluno("aluno12\0", 11, 9.5);
  vetor[2] = criarAluno("aluno13\0", 11, 9.0);
  vetor[3] = criarAluno("aluno14\0", 11, 8.9);
  vetor[4] = criarAluno("aluno15\0", 11, 7.9);

  for (int i = 0; i < 5; i++)
  {
    inserir(raiz, *vetor[i]);
  }

  return 0;
}
