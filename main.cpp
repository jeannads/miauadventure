#include "arvore.cpp"
#include "display.cpp"

int main() {
    RenderWindow tela(VideoMode(1345, 748), "MiauAdventure");

    Node* noAtual = inicializarArvore();

    exibeImagem(tela, noAtual->cenario);

    while (tela.isOpen()) {
        Event evento;
        while (tela.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                tela.close();
            } else if (evento.type == Event::KeyPressed) {
                string imagemInicial = noAtual->cenario;

                if (evento.key.code == Keyboard::Space && !noAtual->esq && !noAtual->dir) {
                    noAtual = inicializarArvore();
                } else if(evento.key.code == Keyboard::Space){
                    noAtual = inicializarArvore();
                    noAtual = noAtual->esq;
                } else if (evento.key.code == Keyboard::Left && noAtual->esq) {
                    noAtual = noAtual->esq;
                } else if (evento.key.code == Keyboard::Right && noAtual->dir) {
                    noAtual = noAtual->dir;
                }

                transicao(tela, imagemInicial, noAtual->cenario);
            }
        }
    }

    deletarArvore(noAtual); // Deleta a árvore inteira

    return 0;
}