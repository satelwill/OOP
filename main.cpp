#include "Jeu.hpp"
#include "gui.hpp"
#include "Grille.hpp"
#include <wx/wx.h>

class App : public wxApp {
public:
    bool OnInit() override {
        GUI* win = new GUI(wxT("Game of Life"), 30, 30);
        win->Show(true);
        SetTopWindow(win);
        return true;
    }
};

wxIMPLEMENT_APP(App);