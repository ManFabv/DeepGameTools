#include "OGameEditor/OGameEditorMainApp.h"
#include "OGameEditor/OGameEditorMainFrame.h"

IMPLEMENT_APP(OGameEditor::Main::OGameEditorMainApp)

bool OGameEditor::Main::OGameEditorMainApp::OnInit()
{
    OGameEditorMainFrame *frame = new OGameEditorMainFrame( "Obsidian Game Editor", wxPoint(50, 50), wxSize(800, 600) );
    frame->Show( true );
    return true;
}
