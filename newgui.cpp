#include "newgui.hpp"

enum { ID_TIMER = 1, ID_START, ID_STOP, ID_CLEAR };

GUI::GUI(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 700)) {
    game = new Jeu(20, 20, 500); // 20x20  
    timer = new wxTimer(this, ID_TIMER);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    
    
    drawPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(400, 400));
    drawPanel->SetBackgroundColour(*wxWHITE);
    
    
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->Add(new wxButton(this, ID_START, "Start"), 0, wxALL, 5);
    buttonSizer->Add(new wxButton(this, ID_STOP, "Stop"), 0, wxALL, 5);
    buttonSizer->Add(new wxButton(this, ID_CLEAR, "Clear"), 0, wxALL, 5);

    mainSizer->Add(drawPanel, 1, wxEXPAND | wxALL, 10);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxBOTTOM, 10);
    this->SetSizer(mainSizer);

   
    Bind(wxEVT_BUTTON, &GUI::OnStart, this, ID_START);
    Bind(wxEVT_BUTTON, &GUI::OnStop, this, ID_STOP);
    Bind(wxEVT_BUTTON, &GUI::OnClear, this, ID_CLEAR);
    Bind(wxEVT_TIMER, &GUI::OnTimer, this, ID_TIMER);
    drawPanel->Bind(wxEVT_PAINT, &GUI::OnPaint, this);
    drawPanel->Bind(wxEVT_LEFT_DOWN, &GUI::OnMouseClick, this);
}

void GUI::OnStart(wxCommandEvent& event) { timer->Start(game->getTime()); }
void GUI::OnStop(wxCommandEvent& event) { timer->Stop(); }

void GUI::OnClear(wxCommandEvent& event) {
    timer->Stop();
    *game = Jeu(20, 20, 500); 
    drawPanel->Refresh();
}

void GUI::OnTimer(wxTimerEvent& event) {
    game->avance();
    drawPanel->Refresh(); 
}


//i get ask AI  abt this func
void GUI::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(drawPanel);
    int w, h;
    drawPanel->GetSize(&w, &h);
    int cellW = w / game->getNow().getCol();
    int cellH = h / game->getNow().getRow();

    dc.SetBrush(*wxBLACK_BRUSH);
    for (int i = 0; i < game->getNow().getRow(); ++i) {
        for (int j = 0; j < game->getNow().getCol(); ++j) {
            if (game->getNow().EstOccupee(i, j)) {
    
                dc.DrawEllipse(j * cellW, i * cellH, cellW - 2, cellH - 2);
            }
        }
    }
}

void GUI::OnMouseClick(wxMouseEvent& event) {
    int w, h;
    drawPanel->GetSize(&w, &h);
    int i = event.GetY() / (h / game->getNow().getRow());
    int j = event.GetX() / (w / game->getNow().getCol());

    if (game->getNow().EstOccupee(i, j)) game->SupprimeCellule(i, j);
    else game->AjouteCellule(i, j);

    drawPanel->Refresh(); 
}

GUI::~GUI() { delete game; }