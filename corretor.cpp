#include "corretor.h"

using namespace std;

Corretor::Corretor(int id, string nome, string telefone, bool avaliador, double lat, double lng)
    : Pessoa(id, nome, telefone), avaliador(avaliador), lan(lat), lng(lng) {}

bool Corretor::getAvaliador() {
    return avaliador;
}

double Corretor::getLan() {
    return lan;
}

double Corretor::getLng() {
    return lng;
}

void Corretor::printInfo() {
    cout << "Corretor ID: " << getId() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "Telefone: " << getTelefone() << endl;
    cout << "Avaliador: " << (avaliador ? "Sim" : "Não") << endl;
    cout << "Latitude: " << lan << endl;
    cout << "Longitude: " << lng << endl;
}
