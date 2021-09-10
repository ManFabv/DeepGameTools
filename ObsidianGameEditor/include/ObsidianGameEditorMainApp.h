#ifndef __OBSIDIANGAMEEDITORMAINAPP_H
#define __OBSIDIANGAMEEDITORMAINAPP_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class ObsidianGameEditorMainApp: public wxApp
{
public:
    virtual bool OnInit();
};

DECLARE_APP(ObsidianGameEditorMainApp)

#endif
