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

Node *buscar(Node *r, matricula Id) {
    if (r == 0) {
        return r;
    }
    Node *res = r;
    if (res->aluno.Id == Id) {
        return res;
    }
    if (Id < r->aluno.Id) {
        res = buscar(r->esq, Id);
    } else if (Id > r->aluno.Id) {
        res = buscar(r->dir, Id);
    }
    return res;
}

// Node *remover(Node *r, matricula Id) {
//     // Valor não encontrado
//     if (r == 0) {
//         return r;
//     }
//     if (r->aluno.Id == Id) {
//         if (r->esq == 0 && r->dir == 0) {
//             free(r);
//             r = 0;
//             return r;
//         }
//     } else {
//         if (r->aluno.Id < Id) {
//             r->esq = remover(r->esq, Id);
//         } else {
//             r->dir = remover(r->dir, Id);
//         }
//         return r;
//     }
//     return r;
// }

Aluno sucessor(Node *r){
    Aluno s = r->aluno;
    while(r->esq != 0){
        s = r->esq->aluno;
        r = r->esq;
    }
    r->esq = 0;
    return s;
}

Node* remover(Node* r, matricula Id){
    if(r == 0){
        return r;
    }
    if(Id < r->aluno.Id){
        r->esq = remover(r->esq, Id);
    }else if(Id > r->aluno.Id){
        r->dir = remover(r->dir, Id);
    }else{

        if(r->esq == 0){
            return r->dir;
        }if(r->dir == 0){
            return r->esq;
        }

        r->aluno = sucessor(r->dir);
        r->dir = remover(r->dir, r->aluno.Id);

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
void posordem(Node *raiz) {
    if (raiz->esq != 0) {
        posordem(raiz->esq);
    }
    if (raiz->dir != 0) {
        posordem(raiz->dir);
    }
    if (raiz != 0) {
        print(raiz->aluno);
    }
}

void inordem(Node *raiz) {
    if (raiz->esq != 0) {
        inordem(raiz->esq);
    }
    if (raiz != 0) {
        print(raiz->aluno);
    }
    if (raiz->dir != 0) {
        inordem(raiz->dir);
    }
}