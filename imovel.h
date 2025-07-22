#ifndef IMOVEL_H
#define IMOVEL_H

using namespace std;

#include <string>
#include <iostream>

class Imovel{   
    public:
        enum Tipo { Casa, Apartamento, Terreno };

    private:
        int id;
        Tipo tipo;
        int id_propriedade;
        double lat;
        double lng;
        string endereco;
        double preco;
        
    public:

        Imovel(int id, Tipo tipo, int id_propriedade, double lat, double lng, string endereco, double preco);

        int getId();
        Tipo getTipo();

        int getId_propriedade();
        double getLat();
        double getLng();
        string getEndereco();
        double getPreco();

        void printInfo();
        static string convertTipoToString(Tipo tipo) {
            if (tipo == Casa) {
                return "Casa";
            } else if (tipo == Apartamento) {
                return "Apartamento";
            } else if (tipo == Terreno) {
                return "Terreno";
            } else {
                return "Desconhecido"; 
            }
        }
        static Tipo convertToTipo(string& tipoString) {
            if (tipoString == "Casa") {
                return Casa;
            } else if (tipoString == "Apartamento") {
                return Apartamento;
            } else if (tipoString == "Terreno") {
                 return Terreno;
            } else {
                return Casa; 
            }
        }

};
#endif