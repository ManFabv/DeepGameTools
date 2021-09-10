#include "ObsidianGameEditorMainApp.h"
#include "ObsidianGameEditorMainFrame.h"

IMPLEMENT_APP(ObsidianGameEditorMainApp)

bool ObsidianGameEditorMainApp::OnInit()
{
    ObsidianGameEngineEditorMainFrame *frame = new ObsidianGameEngineEditorMainFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}
