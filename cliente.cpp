#include "cliente.h"

using namespace std;

Cliente::Cliente(int id, string nome, string telefone) :Pessoa(id, nome, telefone) 
{}

void Cliente::printInfo()
{
    cout << "ID: " << getId() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Telefone: " << getTelefone() << endl;
}