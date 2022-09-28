#include "arvoreBinaria.cpp"
#include "lerArquivos.cpp"

int main() {
    // Recuperando o nome dos alunos
    char *arquivo = (char *)"turma.dat";
    int quantidade;
    Aluno *alunos = getAlunos(arquivo, quantidade);

    // Inserindo na árvore
    Node *raiz = 0;
    for (int i = 0; i < quantidade; i++) {
        raiz = inserir(raiz, alunos[i]);
    }

    // Exibindo em pre-ordem
    //preordem(raiz);

    //Buscando um aluno pelo Id
    Node* aluno = buscar(raiz, 2019011352);

    //Removendo
    raiz = remover(raiz, 2019011352);
    
    preordem(raiz);
}