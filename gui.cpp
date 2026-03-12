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
    configs.Add(wxT("Glisseur"));
    configs.Add(wxT("Pentamino R"));
    configs.Add(wxT("La structure en U"));
    configs.Add(wxT("Structure Infini"));

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

        
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
            if (jeu->getNow().EstOccupee(row, col)) {
                jeu->SupprimeCellule(row, col);
            } else {
                jeu->AjouteCellule(row, col);
            }
            Refresh(); 
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
    

    jeu->setNow(Grille(rows, cols));
    int mid_cols = rows / 2;
    int mid_rows = cols / 2;
    std::cout << "mid_cols: " << mid_cols << ", mid_rows: " << mid_rows << std::endl;

    switch (configChoice->GetSelection()) {
    // 0 0 is top left of tle grid
    // !!!!!-Careful with the coordinates, they are in (y, x) format (row, col)

    // LES STABLES
    case 0: // Bloc 
        jeu->ajoute_ligne(mid_rows - 1, mid_cols - 1, mid_cols);
        jeu->ajoute_ligne(mid_rows, mid_cols - 1, mid_cols);
        break;
        
    case 1: // Tube 
        jeu->AjouteCellule(mid_rows - 1, mid_cols);
        jeu->AjouteCellule(mid_rows + 1, mid_cols);
        jeu->AjouteCellule(mid_rows, mid_cols - 1);
        jeu->AjouteCellule(mid_rows, mid_cols + 1);
        break;
        
    case 2: // Bateau 
        jeu->ajoute_ligne(mid_rows - 1, mid_cols - 1, mid_cols);
        jeu->AjouteCellule(mid_rows, mid_cols - 1);
        jeu->AjouteCellule(mid_rows, mid_cols + 1);
        jeu->AjouteCellule(mid_rows + 1, mid_cols);
        break;
        
    case 3: // Ruche 
        jeu->ajoute_colonne(mid_rows - 1, mid_cols - 1, mid_cols);
        jeu->AjouteCellule(mid_cols - 2, mid_rows);
        jeu->AjouteCellule(mid_cols + 1, mid_rows);
        jeu->ajoute_colonne(mid_rows + 1, mid_cols - 1, mid_cols);
        break;
        
    case 4: // Hameçon 

        
        jeu->ajoute_ligne(mid_rows - 1, mid_cols - 1, mid_cols);
        jeu->AjouteCellule(mid_cols - 1, mid_rows);
        jeu->AjouteCellule(mid_cols + 1, mid_rows);
        jeu->AjouteCellule(mid_cols , mid_rows);
        jeu->AjouteCellule(mid_cols + 1 , mid_rows + 2);
        jeu->ajoute_ligne(mid_rows + 2, mid_cols + 1, mid_cols + 2);
        break;

    case 5: // Clignotant 
        jeu->ajoute_colonne(mid_cols, mid_rows - 1, mid_rows + 1);
        break;
        
    case 6: // Horloge 
        // Top Square 2x2
        jeu->ajoute_ligne(mid_rows - 5, mid_cols + 1, mid_cols + 2);
        jeu->ajoute_ligne(mid_rows - 4, mid_cols + 1, mid_cols + 2);
        // Bottom Square 2x2
        jeu->ajoute_ligne(mid_rows + 5, mid_cols - 1, mid_cols);
        jeu->ajoute_ligne(mid_rows + 6, mid_cols - 1, mid_cols);
        // Left 2x2
        jeu->ajoute_colonne(mid_cols - 5, mid_rows - 1, mid_rows);
        jeu->ajoute_colonne(mid_cols - 4, mid_rows - 1, mid_rows);
        // Right 2x2
        jeu->ajoute_colonne(mid_cols + 5, mid_rows + 2, mid_rows + 1);
        jeu->ajoute_colonne(mid_cols + 6, mid_rows + 2, mid_rows + 1);
        
        // LR inner cycle
        jeu->ajoute_colonne(mid_cols - 2, mid_rows - 1, mid_rows + 2);
        jeu->ajoute_colonne(mid_cols + 3, mid_rows - 1, mid_rows + 2);
        // TB inner cycle
        jeu->ajoute_ligne(mid_rows - 2, mid_cols - 1, mid_cols + 2);
        jeu->ajoute_ligne(mid_rows + 3, mid_cols - 1, mid_cols + 2);
        
        
        jeu->AjouteCellule(mid_cols , mid_rows- 1);
        jeu->AjouteCellule(mid_cols + 1, mid_rows );
        jeu->AjouteCellule(mid_cols + 1, mid_rows + 1);
        break;
        
    case 7: // Pentadecathlon
        // Top and bottom horizontal 2-cell segments
        jeu->ajoute_ligne(mid_rows - 4, mid_cols, mid_cols + 1);
        jeu->ajoute_ligne(mid_rows + 4, mid_cols, mid_cols + 1);

        // Left and right vertical 3-cell segments
        jeu->ajoute_colonne(mid_cols - 4, mid_rows - 1, mid_rows + 1);
        jeu->ajoute_colonne(mid_cols + 5, mid_rows - 1, mid_rows + 1);

        // Diagonal transition cells (AjouteCellule uses row, col = Y, X)
        //Top left
        jeu->AjouteCellule(mid_rows - 2, mid_cols - 3);
        jeu->AjouteCellule(mid_rows - 3, mid_cols - 2);

        //Top right
        jeu->AjouteCellule(mid_rows - 2, mid_cols + 4);
        jeu->AjouteCellule(mid_rows - 3, mid_cols + 3);

        //Bottom left
        jeu->AjouteCellule(mid_rows + 2, mid_cols - 3);
        jeu->AjouteCellule(mid_rows + 3, mid_cols - 2);

        //Bottom right
        jeu->AjouteCellule(mid_rows + 2, mid_cols + 4);
        jeu->AjouteCellule(mid_rows + 3, mid_cols + 3);
        break;
        
    case 8: // Galaxie 
        
        //Top right
        jeu->ajoute_ligne(mid_rows - 3, mid_cols, mid_cols + 5);
        jeu->ajoute_ligne(mid_rows - 4, mid_cols, mid_cols + 5);
         
        //Top left
        jeu->ajoute_colonne(mid_cols - 3, mid_rows - 4, mid_rows + 1);
        jeu->ajoute_colonne(mid_cols - 2, mid_rows - 4, mid_rows + 1);
        
        //Bottom left
        jeu->ajoute_ligne(mid_rows + 3, mid_cols - 3, mid_cols + 2);
        jeu->ajoute_ligne(mid_rows + 4, mid_cols - 3, mid_cols + 2);
        
        //Bottom right
        jeu->ajoute_colonne(mid_cols + 4, mid_rows - 1, mid_rows + 4);
        jeu->ajoute_colonne(mid_cols + 5, mid_rows - 1, mid_rows + 4);
        break;
    
    case 9: // Glisseur (Vaisseau)
        jeu->AjouteCellule(mid_rows - 1, mid_cols);
        jeu->AjouteCellule(mid_rows, mid_cols + 1);
        jeu->ajoute_ligne(mid_rows + 1, mid_cols - 1, mid_cols + 1);
        break;
    case 10: // Pentamino R
        jeu->AjouteCellule(mid_rows, mid_cols);
        jeu->AjouteCellule(mid_rows, mid_cols - 1);
        jeu->AjouteCellule(mid_rows - 1, mid_cols);
        jeu->AjouteCellule(mid_rows - 1, mid_cols + 1);
        jeu->AjouteCellule(mid_rows + 1, mid_cols);
        break;
    case 11: // La structure en U
        jeu->ajoute_ligne(mid_rows, mid_cols - 1, mid_cols + 1);
        jeu->AjouteCellule(mid_rows - 1, mid_cols + 1);
        jeu->AjouteCellule(mid_rows - 1, mid_cols - 1);
        jeu->AjouteCellule(mid_rows - 2, mid_cols + 1);
        jeu->AjouteCellule(mid_rows - 2, mid_cols - 1);
        break;

    case 12: //Structure Infini
        int r0 = mid_rows - 10;
            int c0 = mid_cols - 18;
            
            // Block 1 (Left square)
            jeu->ajoute_ligne(r0 + 4, c0, c0 + 1);
            jeu->ajoute_ligne(r0 + 5, c0, c0 + 1);
            
            // Mechanism 1 (Left engine)
            jeu->ajoute_colonne(c0 + 10, r0 + 4, r0 + 6);
            jeu->AjouteCellule(r0 + 3, c0 + 11); jeu->AjouteCellule(r0 + 7, c0 + 11);
            jeu->AjouteCellule(r0 + 2, c0 + 12); jeu->AjouteCellule(r0 + 8, c0 + 12);
            jeu->AjouteCellule(r0 + 2, c0 + 13); jeu->AjouteCellule(r0 + 8, c0 + 13);
            jeu->AjouteCellule(r0 + 5, c0 + 14);
            jeu->AjouteCellule(r0 + 3, c0 + 15); jeu->AjouteCellule(r0 + 7, c0 + 15);
            jeu->ajoute_colonne(c0 + 16, r0 + 4, r0 + 6);
            jeu->AjouteCellule(r0 + 5, c0 + 17);
            
            // Mechanism 2 (Right engine)
            jeu->ajoute_colonne(c0 + 20, r0 + 2, r0 + 4);
            jeu->ajoute_colonne(c0 + 21, r0 + 2, r0 + 4);
            jeu->AjouteCellule(r0 + 1, c0 + 22); jeu->AjouteCellule(r0 + 5, c0 + 22);
            jeu->ajoute_colonne(c0 + 24, r0 + 0, r0 + 1);
            jeu->ajoute_colonne(c0 + 24, r0 + 5, r0 + 6);
            
            // Block 2 (Right square)
            jeu->ajoute_ligne(r0 + 2, c0 + 34, c0 + 35);
            jeu->ajoute_ligne(r0 + 3, c0 + 34, c0 + 35);
            break;

    }
    Refresh();
}
