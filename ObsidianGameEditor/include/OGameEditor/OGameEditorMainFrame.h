#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

namespace OGameEditor
{
    namespace Main
    {
        class OGameEditorMainFrame : public wxFrame
        {
        public:
            OGameEditorMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
        private:
            void OnHello(wxCommandEvent& event);
            void OnExit(wxCommandEvent& event);
            void OnAbout(wxCommandEvent& event);

            //declare events table
            wxDECLARE_EVENT_TABLE();
        };
    }
}
