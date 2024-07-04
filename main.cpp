//
// Created by Edoardo Nero on 03/07/24.
//
#include "wx/wx.h";
#include "include/view/LoginView.h"
#include "lib/DatabaseManager.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // Connessione al database
    try{
        DatabaseManager::getConnection();
        //recupero dati da tabella user
        MYSQL_RES* res = DatabaseManager::getUserData("edoardo@gmail.com", "123456");
        //stampa dati
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res)) != nullptr) {
            std::cout << "ID: " << row[0] << ", Nome: " << row[1] << ", Cognome: " << row[2] << ", Email: " << row[3] << std::endl;
        }
    }catch(std::invalid_argument& e){
        std::cerr << "Errore durante l'inizializzazione della connessione al database: " << e.what() << std::endl;
        return false;
    }catch(std::runtime_error& e){
        std::cerr << "Errore durante l'inizializzazione della connessione al database: " << e.what() << std::endl;
        return false;
    }catch(std::exception& e){
        std::cerr << "Errore durante la connessione al database: " << e.what() << std::endl;
        return false;
    }

    std::cout << "Connessione al database riuscita" << std::endl;
    auto* loginView = new LoginView("Login");
    loginView->Show(true);

    return true;
}