/***************************************************************
 * Name:      KalmanDemoApp.cpp
 * Purpose:   Code for Application Class
 * Author:    xionghao liu (lxiongh@126.com)
 * Created:   2013-04-27
 * Copyright: xionghao liu ()
 * License:
 **************************************************************/

#include "KalmanDemoApp.h"

//(*AppHeaders
#include "KalmanDemoMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(KalmanDemoApp);

bool KalmanDemoApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	KalmanDemoFrame* Frame = new KalmanDemoFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
