#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>

#include "pessoa.h"

class Cliente : public Pessoa{

    public:
        Cliente(int id, string nome, string telefone);

        void printInfo() override;
};

#endif