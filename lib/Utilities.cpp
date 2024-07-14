//
// Created by Edoardo Nero on 14/07/24.
//

#include "Utilities.h"

bool Utilities::isAllDigits(const std::string& val) {
    return std::all_of(val.begin(), val.end(), ::isdigit);
}

bool Utilities::isValidExpirationDate(const std::string& expirationDate) {
    if(expirationDate.length() != 5){
        return false;
    }
    if(expirationDate[2] != '/'){
        return false;
    }
    std::string month = expirationDate.substr(0, 2);
    std::string year = expirationDate.substr(3, 2);
    if(!isAllDigits(month) || !isAllDigits(year)){
        return false;
    }
    int monthInt = std::stoi(month);
    int yearInt = std::stoi(year);
    if(monthInt < 1 || monthInt > 12){
        return false;
    }
    if(yearInt < 21 || yearInt > 99){
        return false;
    }
    return true;
}

std::string Utilities::checkBalance(const std::string& balance) {
    std::string balanceFormatted = balance;
    std::replace(balanceFormatted.begin(), balanceFormatted.end(), ',', '.');

    double number;
    try {
        number = std::stod(balanceFormatted);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("L'importo non è un numero valido.");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("L'importo è fuori dall'intervallo consentito.");
    }

    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << number;
    return stream.str();
}
