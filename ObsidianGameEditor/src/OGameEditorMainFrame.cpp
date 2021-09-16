#include "OGameEditor/OGameEditorMainFrame.h"

enum
{
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(OGameEditor::Main::OGameEditorMainFrame, wxFrame)
    EVT_MENU(ID_Hello,   OGameEditorMainFrame::OnHello)
    EVT_MENU(wxID_EXIT,  OGameEditorMainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, OGameEditorMainFrame::OnAbout)
wxEND_EVENT_TABLE()

OGameEditor::Main::OGameEditorMainFrame::OGameEditorMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );
}

void OGameEditor::Main::OGameEditorMainFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}

void OGameEditor::Main::OGameEditorMainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample", "About Hello World", wxOK | wxICON_INFORMATION );
}

void OGameEditor::Main::OGameEditorMainFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
