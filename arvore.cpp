#include <string>
using namespace std;

// estrutura de nós
struct Node {
    string cenario;
    Node* esq;
    Node* dir;

    Node(const string& imagem, Node* esq = nullptr, Node* dir = nullptr) : cenario(imagem), esq(esq), dir(dir) {}
};

// inicializa árvore
Node* inicializarArvore() {
    Node* capa = new Node("img/capa.jpg");
    Node* floresta = new Node("img/floresta.jpg");
    Node* trilha = new Node("img/trilha.jpg");
    Node* lago = new Node("img/lago.jpg");
    Node* borboletas = new Node("img/borboletas.jpg");
    Node* abrigo = new Node("img/abrigo.jpg");
    Node* rua = new Node("img/rua.jpg");
    Node* crocodilos = new Node("img/crocodilos.jpg");
    Node* caminho_escuro = new Node("img/caminho_escuro.jpg");
    Node* flores = new Node("img/flores.jpg");
    Node* lugar_conhecido = new Node("img/lugar_conhecido.jpg");
    Node* chale = new Node("img/chale.jpg");
    Node* caverna = new Node("img/caverna.jpg");
    Node* cachorros = new Node("img/cachorros.jpg");

    capa->esq = floresta;
    capa->dir = floresta;

    floresta->esq = trilha;
    floresta->dir = lago;

    trilha->dir = caminho_escuro;
    trilha->esq = flores;

    lago->dir = borboletas;
    lago->esq = crocodilos;
    
    flores->dir = chale;
    flores->esq = lugar_conhecido;

    borboletas->dir = abrigo;
    borboletas->esq = rua;

    lugar_conhecido->dir = cachorros;
    lugar_conhecido->esq = caverna;


    return capa;
}

//deleta árvore
void deletarArvore(Node* no) {
    if (no) {
        deletarArvore(no->esq);
        deletarArvore(no->dir);
        delete no;
    }
}