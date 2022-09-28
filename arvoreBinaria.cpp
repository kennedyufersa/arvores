#include "Aluno.cpp"
#include <stdio.h>

struct Node {
    Aluno aluno;
    struct Node *esq;
    struct Node *dir;
};

Node *novoNo(Aluno a) {
    Node *aux = (Node *)malloc(sizeof(Node));
    aux->aluno = criarAluno2(a.nome, a.Id, a.nota);
    aux->esq = 0;
    aux->dir = 0;
    return aux;
}

Node *inserir(Node *r, Aluno a) {
    if (r == 0) {
        r = novoNo(a);
    }
    if (a.Id < r->aluno.Id) {
        r->esq = inserir(r->esq, a);
    } else if (a.Id > r->aluno.Id) {
        r->dir = inserir(r->dir, a);
    }
    return r;
}

void print(Aluno A) {
    printf("Id: %d\nNome: %s\nNota: %f\n\n", A.Id, A.nome, A.nota);
}

void preordem(Node *raiz) {
    if (raiz != 0) {
        print(raiz->aluno);
    }
    if (raiz->esq != 0) {
        preordem(raiz->esq);
    }
    if (raiz->dir != 0) {
        preordem(raiz->dir);
    }
}
