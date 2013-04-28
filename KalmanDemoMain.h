/***************************************************************
 * Name:      KalmanDemoMain.h
 * Purpose:   Defines Application Frame
 * Author:    xionghao liu (lxiongh@126.com)
 * Created:   2013-04-27
 * Copyright: xionghao liu ()
 * License:
 **************************************************************/

#ifndef KALMANDEMOMAIN_H
#define KALMANDEMOMAIN_H

//(*Headers(KalmanDemoFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include <wx/dc.h>
#include <wx/dcclient.h>
#include "mathplot.h"
#include "GpsPath.h"
#include "Kalman2D.h"

using namespace std;

class KalmanDemoFrame: public wxFrame
{
    public:

        KalmanDemoFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~KalmanDemoFrame();

    private:

        //(*Handlers(KalmanDemoFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton_runClick(wxCommandEvent& event);
        void Draw(mpWindow* m_plot, wxPen vectorpen, mpText* mp_text, vector<double>& xs, vector<double>& ys, bool isContinuity);
        //*)

        //(*Identifiers(KalmanDemoFrame)
        static const long ID_PANEL1;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(KalmanDemoFrame)
        wxStaticText* StaticText2;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl_seed;
        wxPanel* Panel_kalman;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxTextCtrl* TextCtrl_qx_v;
        wxTextCtrl* TextCtrl_qa;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxButton* Button_run;
        wxTextCtrl* TextCtrl_qv;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl_r;
        wxPanel* Panel_error;
        wxTextCtrl* TextCtrl_qx;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl_ra;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // KALMANDEMOMAIN_H
