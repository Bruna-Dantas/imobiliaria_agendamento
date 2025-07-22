#include "corretor.h"
#include "imovel.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

constexpr double EARTH_R = 6371.0;

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

vector<Imovel*> otimizarRota(Corretor& corretor, vector<Imovel*>& imoveis) {
    vector<Imovel*> rota;
    vector<bool> visitado(imoveis.size(), false);

    double atualLat = corretor.getLan();
    double atualLng = corretor.getLng();

    for (size_t i = 0; i < imoveis.size(); ++i) {
        double menorDist = 1e9;
        int proximo = -1;

        for (size_t j = 0; j < imoveis.size(); ++j) {
            if (!visitado[j]) {
                double dist = haversine(atualLat, atualLng, imoveis[j]->getLat(), imoveis[j]->getLng());
                if (dist < menorDist) {
                    menorDist = dist;
                    proximo = j;
                }
            }
        }

        if (proximo != -1) {
            visitado[proximo] = true;
            rota.push_back(imoveis[proximo]);
            atualLat = imoveis[proximo]->getLat();
            atualLng = imoveis[proximo]->getLng();
        }
    }

    return rota;
}

void agendarVisitas(vector<Corretor>& corretores, vector<Imovel>& imoveis) {
    vector<Corretor> avaliadores;
    for (auto& c : corretores) {
        if (c.getAvaliador()) {
            avaliadores.push_back(c);
        }
    }

    int nAvaliadores = avaliadores.size();
    vector<vector<Imovel*>> agenda(nAvaliadores);

    for (size_t i = 0; i < imoveis.size(); ++i) {
        agenda[i % nAvaliadores].push_back(&imoveis[i]);
    }

    for (size_t i = 0; i < avaliadores.size(); ++i) {
        auto& corretor = avaliadores[i];
        auto rotaOtima = otimizarRota(corretor, agenda[i]);

        cout << "\nCorretor " << corretor.getId() << " - " << corretor.getNome() << endl;
        int hora = 9;
        int minuto = 0;
        double atualLat = corretor.getLan();
        double atualLng = corretor.getLng();

        for (auto& imovel : rotaOtima) {
            double dist = haversine(atualLat, atualLng, imovel->getLat(), imovel->getLng());
            int tempoDeslocamento = static_cast<int>(round(dist * 2.0)); // 2 minutos por km

            minuto += tempoDeslocamento;
            while (minuto >= 60) {
                minuto -= 60;
                hora++;
            }

            cout << setw(2) << setfill('0') << hora << ":"
                 << setw(2) << setfill('0') << minuto
                 << " -> Visita ao Imóvel ID " << imovel->getId() << " - " << imovel->getEndereco() << endl;

            hora++; // visita de 1 hora
            atualLat = imovel->getLat();
            atualLng = imovel->getLng();
        }
    }
}