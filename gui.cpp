#include "gui.hpp"

//Getters and setters

wxPanel* GUI::getPanel() const {
    return panel;
}

void GUI::setPanel(wxPanel* panel) {
    this->panel = panel;
}

wxButton* GUI::getButton() const {
    return button;
}

void GUI::setButton(wxButton* button) {
    this->button = button;
}

wxStaticText* GUI::getLabel() const {
    return label;
}

void GUI::setLabel(wxStaticText* label) {
    this->label = label;
}

wxTextCtrl* GUI::getTextCtrl() const {
    return textCtrl;
}

void GUI::setTextCtrl(wxTextCtrl* textCtrl) {
    this->textCtrl = textCtrl;
}


GUI::GUI(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {
    panel = new wxPanel(this, wxID_ANY);
    button = new wxButton(panel, wxID_ANY, "Click Me", wxPoint(150, 50));
    label = new wxStaticText(panel, wxID_ANY, "Hello, World!", wxPoint(150, 100));
    textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 150), wxSize(200, -1));

    button->Bind(wxEVT_BUTTON, &GUI::onButtonClicked, this);
}

GUI::~GUI() {
    // No need to manually delete controls, wxWidgets handles it
}



