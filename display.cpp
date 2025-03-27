#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

void redimensionaSprite(Sprite& sprite, const Vector2u& tamanhoTela) {
    FloatRect bounds = sprite.getLocalBounds();

    // Calcula a escala para manter a proporção da imagem
    float escalaX = tamanhoTela.x / bounds.width;
    float escalaY = tamanhoTela.y / bounds.height;
    float escala = min(escalaX, escalaY); // Escolhe a menor escala para manter a proporção

    // Aplica a escala ao sprite
    sprite.setScale(escala, escala);

    // Centraliza o sprite na tela
    sprite.setPosition((tamanhoTela.x - bounds.width * escala) / 2, (tamanhoTela.y - bounds.height * escala) / 2);
}

// Exibe a imagem do jogo
void exibeImagem(RenderWindow& tela, const string& cenario) {
    try {
        Texture imagem;
        if (!imagem.loadFromFile(cenario)) {
            throw runtime_error("Erro ao carregar imagem: " + cenario);
        }

        Sprite sprite(imagem);
        redimensionaSprite(sprite, tela.getSize());

        tela.clear();
        tela.draw(sprite);
        tela.display();
    } catch (const runtime_error& e) {
        cerr << "Erro: " << e.what() << endl;
    }
}

// Transição lenta entre duas imagens
void transicao(RenderWindow& tela, const string& imagemInicial, const string& proximaImagem) {
    try {
        Texture texInicial, texProxima;
        if (!texInicial.loadFromFile(imagemInicial)) throw runtime_error("Erro ao carregar imagem inicial.");
        if (!texProxima.loadFromFile(proximaImagem)) throw runtime_error("Erro ao carregar próxima imagem.");

        Sprite spriteInicial(texInicial);
        Sprite proximoSprite(texProxima);

        redimensionaSprite(spriteInicial, tela.getSize());
        redimensionaSprite(proximoSprite, tela.getSize());

        Clock timer;
        float duracao = 1.0f; // Duração da transição em segundos

        while (timer.getElapsedTime().asSeconds() < duracao) {
            float alpha = timer.getElapsedTime().asSeconds() / duracao;
            spriteInicial.setColor(Color(255, 255, 255, static_cast<Uint8>(255 - alpha * 255)));
            proximoSprite.setColor(Color(255, 255, 255, static_cast<Uint8>(alpha * 255)));

            tela.clear();
            tela.draw(spriteInicial);
            tela.draw(proximoSprite);
            tela.display();
        }
    } catch (const runtime_error& e) {
        cerr << "Erro: " << e.what() << endl;
    }
}



