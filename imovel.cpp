#include "imovel.h"
#include <iostream>


Imovel::Imovel(const int id, Tipo tipo, int id_propriedade, double lat, double lng, std::string endereco, double preco)
    : id(id), tipo(tipo), id_propriedade(id_propriedade), lat(lat), lng(lng), endereco(endereco), preco(preco) {}

int Imovel::getId() {
    return id;
}

Imovel::Tipo Imovel::getTipo() {
    return tipo;
}

int Imovel::getId_propriedade() {
    return id_propriedade;
}

double Imovel::getLat() {
    return lat;
}

double Imovel::getLng() {
    return lng;
}

std::string Imovel::getEndereco() {
    return endereco;
}

double Imovel::getPreco() {
    return preco;
}


void Imovel::printInfo() {
    std::cout << "Imóvel ID: " << id << std::endl;
    std::cout << "Tipo: " << convertTipoToString(tipo) << std::endl;
    std::cout << "ID do Proprietário: " << id_propriedade << std::endl;
    std::cout << "Latitude: " << lat << ", Longitude: " << lng << std::endl;
    std::cout << "Endereço: " << endereco << std::endl;
    std::cout << "Preço: R$ " << preco << std::endl;
}