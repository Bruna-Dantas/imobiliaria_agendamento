#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using namespace std;

class Pessoa {
        protected:
            string telefone;
            string nome;
            int id;

            Pessoa(int id, string nome, string telefone);
        public:

            string getTelefone();
            string getNome();
            int getId();

            virtual ~Pessoa() = default;
            virtual void printInfo();
    };

#endif