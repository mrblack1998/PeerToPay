//
// Created by Edoardo Nero on 08/07/24.
//

#ifndef PEERTOPAY_SENDPANELVIEW_H
#define PEERTOPAY_SENDPANELVIEW_H

#include "wx/wx.h"

class SendPanelView {
public:
    SendPanelView(wxPanel* panel);
    ~SendPanelView();
    wxPanel* getPanel();
    std::string getAddress();
    std::string getAmount();
    void clearFields();

private:

    //aggiungere i componenti della view che sono: un campo di testo per l'inserimento dell'indirizzo del destinatario, un campo di testo per l'inserimento dell'importo da inviare, un bottone per confermare l'invio
    wxPanel* panel;
    wxTextCtrl* address;
    wxTextCtrl* amount;
    wxButton* sendButton;
};


#endif //PEERTOPAY_SENDPANELVIEW_H
