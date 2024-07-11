//
// Created by Edoardo Nero on 11/07/24.
//

#ifndef PEERTOPAY_TRANSAZIONE_H
#define PEERTOPAY_TRANSAZIONE_H

#include <string>

class Transazione {
public:
    Transazione(int id, std::string &data, std::string &mittente, std::string &destinatario, double importo, bool tipo);
    ~Transazione();
    int getId() const;
    std::string getData() const;
    std::string getMittente() const;
    std::string getDestinatario() const;
    double getImporto() const;
    bool getTipo() const;   //true = entrata, false = uscita

private:
    int id;
    std::string data;
    std::string mittente;
    std::string destinatario;
    double importo;
    bool tipo;
};


#endif //PEERTOPAY_TRANSAZIONE_H
