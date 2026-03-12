#ifndef GUI_HPP
#define GUI_HPP
#include <wx/wx.h>
#include "Jeu.hpp"

class GUI : public wxFrame {
private:
    Jeu* game;
    wxTimer* timer;
    wxPanel* drawPanel;

    
    void OnStart(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnMouseClick(wxMouseEvent& event);

public:
    GUI(const wxString& title);
    virtual ~GUI();
};

#endif