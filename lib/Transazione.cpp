//
// Created by Edoardo Nero on 11/07/24.
//

#include "Transazione.h"

Transazione::Transazione(int id, std::string &data, std::string &mittente, std::string &destinatario, double importo, bool tipo) {
    this->id = id;
    this->data = data;
    this->mittente = mittente;
    this->destinatario = destinatario;
    this->importo = importo;
    this->tipo = tipo;
}

Transazione::~Transazione() = default;

int Transazione::getId() const {
    return id;
}

std::string Transazione::getData() const {
    return data;
}

std::string Transazione::getMittente() const {
    return mittente;
}

std::string Transazione::getDestinatario() const {
    return destinatario;
}

double Transazione::getImporto() const {
    return importo;
}

bool Transazione::getTipo() const {
    return tipo;
}