#include <iostream>
#include "fila.h"

using namespace std;

int main() {
    fila f(5);

    f.inserir(10);
    f.inserir(20);
    f.inserir(30);

    cout << "Inicio da fila: " << f.consultarInicio() << endl;
    cout << "Fila: ";
    f.imprimir();

    f.remover();
    cout << "Fila: ";
    f.imprimir();

    f.inserir(40);
    cout << "Fila: ";
    f.imprimir();

    while (!f.estaCheia()) f.inserir(1);

    cout << "Fila cheia? " << (f.estaCheia() ? "Sim" : "Não") << endl;

    while (!f.estaVazia()) f.remover();

    cout << "Fila vazia? " << (f.estaVazia() ? "Sim" : "Não") << endl;

    return 0;
}