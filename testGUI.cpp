#include "newgui.hpp"
#include "testGUI.hpp"
bool MyApp::OnInit(){
    GUI* gui= new GUI(wxT("My GUI"));
    gui->Show(true);
    return true;
}
wxIMPLEMENT_APP(MyApp);