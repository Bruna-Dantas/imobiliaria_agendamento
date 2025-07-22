#include "pessoa.h"

using namespace std;

Pessoa::Pessoa(int id, string nome, string telefone)
: id(id), nome(nome), telefone(telefone) {}

string Pessoa::getTelefone() {
    return telefone;
}

string Pessoa::getNome() {
    return nome;
}

int Pessoa::getId() {
    return id;
}

void Pessoa::printInfo() {
    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Telefone: " << telefone << endl;
}