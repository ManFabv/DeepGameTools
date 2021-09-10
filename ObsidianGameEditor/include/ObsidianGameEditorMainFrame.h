#ifndef __OBSIDIANGAMEEDITORMAINFRAME_H
#define __OBSIDIANGAMEEDITORMAINFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class ObsidianGameEngineEditorMainFrame: public wxFrame
{
public:
    ObsidianGameEngineEditorMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    //declare events table
    wxDECLARE_EVENT_TABLE();
};

#endif
