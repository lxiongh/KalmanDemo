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
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include <wx/dc.h>
#include <wx/dcclient.h>
#include "mathplot.h"

#include "GpsPath.h"
#include "Kalman2D.h"
#include <sstream>

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
        void Draw(mpWindow* m_plot, wxPen vectorpen, string name, mpInfoLegend* leg, vector<double>& xs, vector<double>& ys, bool isContinuity);
        //*)

        double RMSE(vector<double> vec);

        //(*Identifiers(KalmanDemoFrame)
        static const long ID_PANEL1;
        static const long ID_PANEL2;
        static const long ID_PANEL3;
        static const long ID_PANEL4;
        static const long ID_PANEL5;
        static const long ID_PANEL6;
        static const long ID_TEXTCTRL8;
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
        wxTextCtrl* TextCtrl_seed;
        wxPanel* Panel_xv;
        wxStatusBar* StatusBar1;
        wxPanel* Panel_error;
        wxTextCtrl* TextCtrl_result;
        wxPanel* Panel_kalman;
        wxTextCtrl* TextCtrl_ra;
        wxStaticText* StaticText1;
        wxTextCtrl* TextCtrl_qx_v;
        wxStaticText* StaticText3;
        wxPanel* Panel_y;
        wxPanel* Panel_yv;
        wxTextCtrl* TextCtrl_qx;
        wxTextCtrl* TextCtrl_qv;
        wxStaticText* StaticText7;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl_qa;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl_r;
        wxPanel* Panel_x;
        wxButton* Button_run;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // KALMANDEMOMAIN_H
