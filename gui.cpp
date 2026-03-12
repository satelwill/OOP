#include "gui.hpp"

// Connect event table by IDs
wxBEGIN_EVENT_TABLE(GUI, wxFrame)
    EVT_PAINT(GUI::OnPaint)
    EVT_LEFT_DOWN(GUI::OnMouseClick)
    EVT_BUTTON(ID_BTN_START, GUI::OnStart)
    EVT_BUTTON(ID_BTN_STOP, GUI::OnStop)
    EVT_BUTTON(ID_BTN_CLEAR, GUI::OnClear)
    EVT_CHOICE(ID_CHOICE_CONFIG, GUI::OnConfigChoice)
    EVT_TIMER(ID_TIMER, GUI::OnTimer)
wxEND_EVENT_TABLE()



GUI::GUI(const wxString& title, int rows, int cols)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(cols * 15 + 20, rows * 15 + 100), wxDEFAULT_FRAME_STYLE),
      jeu(new Jeu(rows, cols)), rows(rows), cols(cols), cellSize(15)
{

    controlPanel = new wxPanel(this, wxID_ANY, wxPoint(0, rows * cellSize), wxSize(cols * cellSize + 20, 100));

    btnStart = new wxButton(controlPanel, ID_BTN_START, wxT("Start"), wxPoint(10, 10));
    btnStop  = new wxButton(controlPanel, ID_BTN_STOP, wxT("Stop"), wxPoint(100, 10));
    btnClear = new wxButton(controlPanel, ID_BTN_CLEAR, wxT("Clear"), wxPoint(190, 10));

    wxArrayString configs;
    configs.Add(wxT("Bloc"));
    configs.Add(wxT("Tube"));
    configs.Add(wxT("Bateau"));
    configs.Add(wxT("Ruche"));
    configs.Add(wxT("Hameçon"));
    configs.Add(wxT("Clignotant"));
    configs.Add(wxT("Horloge"));
    configs.Add(wxT("Pentadecathlon"));
    configs.Add(wxT("Galaxie"));
    
    configChoice = new wxChoice(controlPanel, ID_CHOICE_CONFIG, wxPoint(280, 10), wxDefaultSize, configs);

    timer = new wxTimer(this, ID_TIMER);
}

GUI::~GUI() {
    delete timer;
    delete jeu;
}

void GUI::OnPaint(wxPaintEvent& evt) {
    wxPaintDC dc(this);
    dc.SetBackground(*wxBLACK_BRUSH);
    dc.Clear();
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.SetPen(*wxTRANSPARENT_PEN);

    Grille g = jeu->getNow();
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (g.EstOccupee(r, c)) {
                dc.DrawCircle(c * cellSize + cellSize / 2, r * cellSize + cellSize / 2, cellSize / 2 - 1);
            }
        }
    }
}

void GUI::OnMouseClick(wxMouseEvent& evt) {
    int col = evt.GetX() / cellSize;
    int row = evt.GetY() / cellSize;

    // Sınır kontrolü (Kullanıcının kontrol paneline tıklamasını filtrelemek için)
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        if (jeu->getNow().EstOccupee(row, col)) {
            jeu->SupprimeCellule(row, col);
        } else {
            jeu->AjouteCellule(row, col);
        }
        Refresh(); // Çizimi tetikler (OnPaint'i çağırır)
    }
}

void GUI::OnStart(wxCommandEvent& evt) {
    timer->Start(150);
}

void GUI::OnStop(wxCommandEvent& evt) {
    timer->Stop();
}

void GUI::OnClear(wxCommandEvent& evt) {
    timer->Stop();
    jeu->setNow(Grille(rows, cols));
    Refresh();
}

void GUI::OnTimer(wxTimerEvent& evt) {
    jeu->avance();
    Refresh();
}

void GUI::OnConfigChoice(wxCommandEvent& evt) {
    loadConfig(configChoice->GetStringSelection());
}

void GUI::loadConfig(const wxString& name) {
    // TODO: Fix x y and row col confusion in the following code

    jeu->setNow(Grille(rows, cols));
    int mid_cols = rows / 2;
    int mid_rows = cols / 2;
    std::cout << "mid_cols: " << mid_cols << ", mid_rows: " << mid_rows << std::endl;

    switch (configChoice->GetSelection()) {
    // LES STABLES
    // 0 0 is top left of tle grid
        switch (configChoice->GetSelection()) {
    case 0: // Bloc 
        ajoute_ligne(mid_rows - 1, mid_cols - 1, mid_cols);
        ajoute_ligne(mid_rows, mid_cols - 1, mid_cols);
        break;
        
    case 1: // Tube 
        jeu->AjouteCellule(mid_rows - 1, mid_cols);
        jeu->AjouteCellule(mid_rows + 1, mid_cols);
        jeu->AjouteCellule(mid_rows, mid_cols - 1);
        jeu->AjouteCellule(mid_rows, mid_cols + 1);
        break;
        
    case 2: // Bateau 
        ajoute_ligne(mid_rows - 1, mid_cols - 1, mid_cols);
        jeu->AjouteCellule(mid_rows, mid_cols - 1);
        jeu->AjouteCellule(mid_rows, mid_cols + 1);
        jeu->AjouteCellule(mid_rows + 1, mid_cols);
        break;
        
    case 3: // Ruche 
        ajoute_ligne(mid_rows - 1, mid_cols - 1, mid_cols);
        jeu->AjouteCellule(mid_rows, mid_cols - 2);
        jeu->AjouteCellule(mid_rows, mid_cols + 1);
        ajoute_ligne(mid_rows + 1, mid_cols - 1, mid_cols);
        break;
        
    case 4: // Hameçon 
        ajoute_ligne(mid_rows - 1, mid_cols - 1, mid_cols);
        jeu->AjouteCellule(mid_rows, mid_cols - 1);
        jeu->AjouteCellule(mid_rows, mid_cols + 1);
        jeu->AjouteCellule(mid_rows + 1, mid_cols + 1);
        ajoute_ligne(mid_rows + 2, mid_cols + 1, mid_cols + 2);
        break;

    case 5: // Clignotant 
        ajoute_colonne(mid_cols, mid_rows - 1, mid_rows + 1);
        break;
        
    case 6: // Horloge 
        // Top Square 2x2
        ajoute_ligne(mid_rows - 6, mid_cols - 1, mid_cols);
        ajoute_ligne(mid_rows - 5, mid_cols - 1, mid_cols);
        // Bottom Square 2x2
        ajoute_ligne(mid_rows + 5, mid_cols - 1, mid_cols);
        ajoute_ligne(mid_rows + 6, mid_cols - 1, mid_cols);
        // Left 2x2
        ajoute_colonne(mid_cols - 6, mid_rows - 1, mid_rows);
        ajoute_colonne(mid_cols - 5, mid_rows - 1, mid_rows);
        // Right 2x2
        ajoute_colonne(mid_cols + 5, mid_rows - 1, mid_rows);
        ajoute_colonne(mid_cols + 6, mid_rows - 1, mid_rows);
        
        // LR inner cycle
        ajoute_colonne(mid_cols - 2, mid_rows - 2, mid_rows + 1);
        ajoute_colonne(mid_cols + 2, mid_rows - 1, mid_rows + 2);
        // TB inner cycle
        ajoute_ligne(mid_rows - 2, mid_cols - 1, mid_cols + 1);
        ajoute_ligne(mid_rows + 2, mid_cols - 2, mid_cols);
        
        
        jeu->AjouteCellule(mid_rows - 1, mid_cols - 1);
        jeu->AjouteCellule(mid_rows, mid_cols + 1);
        break;
        
    case 7: // Pentadecathlon 

        ajoute_ligne(mid_rows - 2, mid_cols - 1, mid_cols + 2);
        ajoute_ligne(mid_rows + 3, mid_cols - 1, mid_cols + 2);
        
        ajoute_colonne(mid_cols - 3, mid_rows, mid_rows + 1);
        ajoute_colonne(mid_cols + 4, mid_rows, mid_rows + 1);
        
        jeu->AjouteCellule(mid_rows - 1, mid_cols - 2); 
        jeu->AjouteCellule(mid_rows + 2, mid_cols - 2); 
        jeu->AjouteCellule(mid_rows - 1, mid_cols + 3); 
        jeu->AjouteCellule(mid_rows + 2, mid_cols + 3); 
        break;
        
    case 8: // Galaxie 
        
        ajoute_ligne(mid_rows - 4, mid_cols - 4, mid_cols + 1);
        ajoute_ligne(mid_rows - 3, mid_cols - 4, mid_cols + 1);
         
        ajoute_colonne(mid_cols + 3, mid_rows - 4, mid_rows + 1);
        ajoute_colonne(mid_cols + 4, mid_rows - 4, mid_rows + 1);
        
        ajoute_ligne(mid_rows + 3, mid_cols - 1, mid_cols + 4);
        ajoute_ligne(mid_rows + 4, mid_cols - 1, mid_cols + 4);
        
        ajoute_colonne(mid_cols - 4, mid_rows - 1, mid_rows + 4);
        ajoute_colonne(mid_cols - 3, mid_rows - 1, mid_rows + 4);
        break;
    }
    Refresh();
}