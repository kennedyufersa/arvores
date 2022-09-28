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

int main(int argc, char const *argv[]) {
    Node *raiz = 0;

    Aluno vetor[5];

    vetor[0] = criarAluno2("A\0", 8, 8);
    vetor[1] = criarAluno2("B\0", 4, 12);
    vetor[2] = criarAluno2("C\0", 6, 13);
    vetor[3] = criarAluno2("D\0", 12, 14);
    vetor[4] = criarAluno2("E\0", 14, 15);

    for (int i = 0; i < 5; i++) {
        raiz = inserir(raiz, vetor[i]);
    }

    return 0;
}
