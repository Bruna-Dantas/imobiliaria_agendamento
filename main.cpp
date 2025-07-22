#include "cliente.h"
#include "corretor.h"
#include "imovel.h"
#include "pessoa.h"
#include "agendamentos.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <locale>
#include <algorithm>

using namespace std;

bool leBloco(int& bloco) {
    string linha;
    // Pula linhas em branco
    while (getline(cin, linha)) {
        if (!linha.empty()) break;
    }

    if (linha.empty()) {
        cerr << "Erro: linha do bloco está vazia ou só contém espaços.\n";
        return false;
    }

    try {
        bloco = stoi(linha);
        return true;
    } catch (const std::exception& e) {
        cerr << "Erro: valor inválido para inteiro: '" << linha << "'\n";
        return false;
    }
}

int main() {
    cin.imbue(locale("C"));

    vector<Cliente> clientes;
    vector<Corretor> corretores;
    vector<Imovel> imoveis;

    string row;
    int bloco;

    // --- Corretores ---
    if (!leBloco(bloco)) return 1;

    for (int ii = 0; ii < bloco; ii++) {
        getline(cin, row);
        istringstream iss(row);

        string telefone, nome;
        bool avaliador;
        double lat, lng;

        if (!(iss >> telefone >> avaliador >> lat >> lng)) {
            cerr << "Erro ao ler corretor na linha " << ii + 1 << ": " << row << endl;
            continue;
        }

        getline(iss, nome);
        if (!nome.empty() && nome[0] == ' ') nome = nome.substr(1);

        corretores.emplace_back(ii + 1, nome, telefone, avaliador, lat, lng);
    }

    // --- Clientes ---
    if (!leBloco(bloco)) return 1;

    for (int ii = 0; ii < bloco; ii++) {
        getline(cin, row);
        istringstream iss(row);

        string telefone, nome;
        if (!(iss >> telefone)) {
            cerr << "Erro ao ler telefone do cliente na linha " << ii + 1 << ": " << row << endl;
            continue;
        }

        getline(iss, nome);
        if (!nome.empty() && nome[0] == ' ') nome = nome.substr(1);

        clientes.emplace_back(ii + 1, nome, telefone);
    }

    // --- Imóveis ---
    if (!leBloco(bloco)) return 1;

    for (int ii = 0; ii < bloco; ii++) {
        getline(cin, row);
        replace(row.begin(), row.end(), ',', '.'); 
        istringstream iss(row);

        string tipoStr, endereco;
        int id_proprietario;
        double lat, lng, preco;

        if (!(iss >> tipoStr >> id_proprietario >> lat >> lng >> preco)) {
            cerr << "Erro ao ler imóvel na linha " << ii + 1 << ": " << row << endl;
            continue;
        }

        getline(iss, endereco);
        if (!endereco.empty() && endereco[0] == ' ') endereco = endereco.substr(1);

        Imovel::Tipo tipoC = Imovel::convertToTipo(tipoStr);
        imoveis.emplace_back(ii + 1, tipoC, id_proprietario, lat, lng, endereco, preco);
    }

    // --- Impressão ---
    cout << "\n--- Corretores ---\n";
    for (auto& c : corretores) c.printInfo();

    cout << "\n--- Clientes ---\n";
    for (auto& c : clientes) c.printInfo();

    cout << "\n--- Imóveis ---\n";
    for (auto& i : imoveis) i.printInfo();

    cout << "\n--- Agendamentos ---\n";
    agendarVisitas(corretores, imoveis);

    return 0;
}
