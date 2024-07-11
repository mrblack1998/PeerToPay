//
// Created by Edoardo Nero on 08/07/24.
//

#include "include/view/HomePanelView.h"

enum MenuIDs{
    ID_EXPORT = 108
};

HomePanelView::HomePanelView(wxPanel *panel, const std::string& ab, const std::vector<Transazione>& transactions) {
    this->panel = panel;
    this->panel->SetSize(500, 400);
    this->panel->SetPosition(wxPoint(0, 0));

    std::string actualBalance = ab;
    if(actualBalance.empty()){
        actualBalance = "0.00";
    }if(actualBalance.find('.') != std::string::npos) {
        actualBalance = actualBalance.substr(0, actualBalance.find('.') + 3);
    }else{
        actualBalance += ".00";
    }
    actualBalance += " €";

    this->balance = new wxStaticText(this->panel, wxID_ANY, actualBalance, wxPoint(0, 30), wxSize(500, 30), wxALIGN_CENTER_HORIZONTAL);
    this->balance->SetFont(wxFont(35, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    this->transactions = new wxGrid(this->panel, wxID_ANY, wxPoint(20, 80), wxSize(460, 200));
    this->exportButton = new wxButton(this->panel, wxID_ANY, "Esporta Movimenti", wxPoint(150, 315), wxSize(200, 30));
    this->exportButton->SetId(ID_EXPORT);

    // Crea la tabella delle transazioni
    this->transactions->CreateGrid(0, 6); // 0 righe iniziali, 6 colonne
    this->transactions->SetColLabelValue(0, "ID");
    this->transactions->SetColLabelValue(1, "Mittente");
    this->transactions->SetColLabelValue(2, "Destinatario");
    this->transactions->SetColLabelValue(3, "Importo");
    this->transactions->SetColLabelValue(4, "Tipo");
    this->transactions->SetColLabelValue(5, "Data e Orario");

    for (size_t i = 0; i < transactions.size(); ++i) {
        this->transactions->AppendRows(1); // Aggiunge una nuova riga
        this->transactions->SetCellValue(i, 0, std::to_string(transactions[i].getId()));
        this->transactions->SetCellValue(i, 1, transactions[i].getMittente());
        this->transactions->SetCellValue(i, 2, transactions[i].getDestinatario());
        //importo arrotandato a 2 decimali
        std::string importo = std::to_string(transactions[i].getImporto());
        if(importo.find('.') != std::string::npos) {
            importo = importo.substr(0, importo.find('.') + 3);
        }else{
            importo += ".00";
        }
        this->transactions->SetCellValue(i, 3, importo + " €");
        this->transactions->SetCellValue(i, 4, transactions[i].getTipo() ? "Entrata" : "Uscita");
        //data formato gg/mm/aa hh:mm
        std::string data = transactions[i].getData();
        data = data.substr(0, data.find(' '));
        data = data.substr(8, 2) + "/" + data.substr(5, 2) + "/" + data.substr(2, 2) + " " + transactions[i].getData().substr(11, 5);
        this->transactions->SetCellValue(i, 5, data);
    }
    // Imposta la larghezza delle colonne
    this->transactions->SetColSize(0, 40);
    this->transactions->SetColSize(1, 90);
    this->transactions->SetColSize(2, 90);
    this->transactions->SetColSize(3, 80);
    this->transactions->SetColSize(4, 60);
    this->transactions->SetColSize(5, 100);
    this->transactions->EnableEditing(false);
}

HomePanelView::~HomePanelView() {
    this->panel->Destroy();
}

wxPanel *HomePanelView::getPanel() {
    return this->panel;
}