#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

namespace OGameEditor
{
    namespace Main
    {
        class OGameEditorMainApp : public wxApp
        {
        public:
            virtual bool OnInit();
        };

        DECLARE_APP(OGameEditorMainApp)
    }
}
