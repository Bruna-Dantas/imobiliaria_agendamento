#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>
#include <iostream>

#include "pessoa.h"

class Corretor : public Pessoa{
    private:
        bool avaliador;
        double lan;
        double lng;

    public:

        Corretor(int id, string nome, string telefone, bool avaliador, double lat, double lng);
        bool getAvaliador();
        double getLan();
        double getLng();

        void printInfo() override;

};

#endif