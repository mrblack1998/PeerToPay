//
// Created by Edoardo Nero on 05/07/24.
//

#ifndef PEERTOPAY_REGISTERCONTROLLER_H
#define PEERTOPAY_REGISTERCONTROLLER_H

#include "include/model/Register.h"
#include "include/view/RegisterView.h"

class RegisterController {
public:
    RegisterController(RegisterView* view, Register* model);
    void Init();
    void SwitchToLogin(wxCommandEvent& event);
    void OnRegister(wxCommandEvent& event);

private:
    RegisterView* view;
    Register* model;
};


#endif //PEERTOPAY_REGISTERCONTROLLER_H
