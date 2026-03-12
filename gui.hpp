#ifndef GUI_HPP
#define GUI_HPP

#include <wx/wx.h>
#include <wx/timer.h>
#include "Jeu.hpp"

// enums for event IDs
enum {
    ID_BTN_START = 101,
    ID_BTN_STOP = 102,
    ID_BTN_CLEAR = 103,
    ID_CHOICE_CONFIG = 104,
    ID_TIMER = 105
};

class GUI : public wxFrame {
public:
    GUI(const wxString& title, int rows = 30, int cols = 30);
    ~GUI();

private:
    Jeu* jeu;
    int rows, cols;
    int cellSize;

    wxPanel* controlPanel;
    wxButton* btnStart;
    wxButton* btnStop;
    wxButton* btnClear;
    wxChoice* configChoice;
    wxTimer* timer;

    void OnPaint(wxPaintEvent& evt);
    void OnMouseClick(wxMouseEvent& evt);
    void OnStart(wxCommandEvent& evt);
    void OnStop(wxCommandEvent& evt);
    void OnClear(wxCommandEvent& evt);
    void OnTimer(wxTimerEvent& evt);
    void OnConfigChoice(wxCommandEvent& evt);
    void loadConfig(const wxString& name);

    wxDECLARE_EVENT_TABLE(); // Statik olay tablosu bildirimi
};

#endif