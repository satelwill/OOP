#ifndef GUI_HPP
#define GUI_HPP
#include <wx/wx.h>



class GUI: public wxFrame{
    private:
        wxPanel* panel;
        wxButton* button;
        wxStaticText* label;
        wxTextCtrl* textCtrl;
    
        void onButtonClicked(wxCommandEvent& event);
    
        wxDECLARE_EVENT_TABLE();    
    public:
        //Getters and setters
        wxPanel* getPanel() const;
        void setPanel(wxPanel* panel);

        wxButton* getButton() const;
        void setButton(wxButton* button);

        wxStaticText* getLabel() const;
        void setLabel(wxStaticText* label);

        wxTextCtrl* getTextCtrl() const;
        void setTextCtrl(wxTextCtrl* textCtrl);

        GUI(const wxString& title);
        ~GUI();


};


#endif // GUI_HPP