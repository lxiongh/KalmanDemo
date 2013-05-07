/***************************************************************
 * Name:      KalmanDemoMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    xionghao liu (lxiongh@126.com)
 * Created:   2013-04-27
 * Copyright: xionghao liu ()
 * License:
 **************************************************************/

#include "KalmanDemoMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(KalmanDemoFrame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(KalmanDemoFrame)
const long KalmanDemoFrame::ID_PANEL1 = wxNewId();
const long KalmanDemoFrame::ID_PANEL2 = wxNewId();
const long KalmanDemoFrame::ID_PANEL3 = wxNewId();
const long KalmanDemoFrame::ID_PANEL4 = wxNewId();
const long KalmanDemoFrame::ID_PANEL5 = wxNewId();
const long KalmanDemoFrame::ID_PANEL6 = wxNewId();
const long KalmanDemoFrame::ID_TEXTCTRL8 = wxNewId();
const long KalmanDemoFrame::ID_STATICTEXT7 = wxNewId();
const long KalmanDemoFrame::ID_TEXTCTRL7 = wxNewId();
const long KalmanDemoFrame::ID_STATICTEXT1 = wxNewId();
const long KalmanDemoFrame::ID_TEXTCTRL1 = wxNewId();
const long KalmanDemoFrame::ID_STATICTEXT2 = wxNewId();
const long KalmanDemoFrame::ID_TEXTCTRL6 = wxNewId();
const long KalmanDemoFrame::ID_STATICTEXT3 = wxNewId();
const long KalmanDemoFrame::ID_TEXTCTRL2 = wxNewId();
const long KalmanDemoFrame::ID_STATICTEXT4 = wxNewId();
const long KalmanDemoFrame::ID_TEXTCTRL3 = wxNewId();
const long KalmanDemoFrame::ID_STATICTEXT5 = wxNewId();
const long KalmanDemoFrame::ID_TEXTCTRL4 = wxNewId();
const long KalmanDemoFrame::ID_STATICTEXT6 = wxNewId();
const long KalmanDemoFrame::ID_TEXTCTRL5 = wxNewId();
const long KalmanDemoFrame::ID_BUTTON1 = wxNewId();
const long KalmanDemoFrame::idMenuQuit = wxNewId();
const long KalmanDemoFrame::idMenuAbout = wxNewId();
const long KalmanDemoFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(KalmanDemoFrame,wxFrame)
    //(*EventTable(KalmanDemoFrame)
    //*)
END_EVENT_TABLE()

KalmanDemoFrame::KalmanDemoFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(KalmanDemoFrame)
    wxBoxSizer* BoxSizer4;
    wxMenuItem* MenuItem2;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("KalmanDemo V1.0"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel_kalman = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(294,142), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1->Add(Panel_kalman, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_error = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxSize(204,144), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer1->Add(Panel_error, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Panel_xv = new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxSize(296,131), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer3->Add(Panel_xv, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_yv = new wxPanel(this, ID_PANEL4, wxDefaultPosition, wxSize(210,129), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer3->Add(Panel_yv, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Panel_x = new wxPanel(this, ID_PANEL5, wxDefaultPosition, wxSize(296,137), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    BoxSizer4->Add(Panel_x, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_y = new wxPanel(this, ID_PANEL6, wxDefaultPosition, wxSize(208,136), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BoxSizer4->Add(Panel_y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 13, 0, 0);
    TextCtrl_result = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxSize(295,61), wxTE_AUTO_SCROLL|wxTE_MULTILINE|wxTE_RICH, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    FlexGridSizer2->Add(TextCtrl_result, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Seed"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_seed = new wxTextCtrl(this, ID_TEXTCTRL7, _("0"), wxDefaultPosition, wxSize(25,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    BoxSizer2->Add(TextCtrl_seed, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 6, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("qx"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_qx = new wxTextCtrl(this, ID_TEXTCTRL1, _("0.01"), wxDefaultPosition, wxSize(34,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer3->Add(TextCtrl_qx, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("qx_v"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_qx_v = new wxTextCtrl(this, ID_TEXTCTRL6, _("0.5"), wxDefaultPosition, wxSize(27,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    FlexGridSizer3->Add(TextCtrl_qx_v, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("r"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_r = new wxTextCtrl(this, ID_TEXTCTRL2, _("0.1"), wxDefaultPosition, wxSize(28,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer3->Add(TextCtrl_r, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("qv"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_qv = new wxTextCtrl(this, ID_TEXTCTRL3, _("0.01"), wxDefaultPosition, wxSize(33,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer3->Add(TextCtrl_qv, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("qa"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_qa = new wxTextCtrl(this, ID_TEXTCTRL4, _("0.1"), wxDefaultPosition, wxSize(27,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer3->Add(TextCtrl_qa, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("ra"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer3->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_ra = new wxTextCtrl(this, ID_TEXTCTRL5, _("0.1"), wxDefaultPosition, wxSize(30,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer3->Add(TextCtrl_ra, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_run = new wxButton(this, ID_BUTTON1, _("Run"), wxDefaultPosition, wxSize(42,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(Button_run, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalmanDemoFrame::OnButton_runClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&KalmanDemoFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&KalmanDemoFrame::OnAbout);
    //*)

    wxCommandEvent event;
    OnButton_runClick(event);
}

KalmanDemoFrame::~KalmanDemoFrame()
{
    //(*Destroy(KalmanDemoFrame)
    //*)
}

void KalmanDemoFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void KalmanDemoFrame::OnAbout(wxCommandEvent& event)
{
    //wxString msg = wxbuildinfo(long_f);
    wxString msg = "By: Xionghao Liu      ID: 12212894";
    wxMessageBox(msg, _("About"));
}

void KalmanDemoFrame::OnButton_runClick(wxCommandEvent& event)
{
    Kalman2D* k2d_x = new Kalman2D();
    Kalman2D* k2d_y = new Kalman2D();
    Kalman2D* k2d_vx = new Kalman2D();
    Kalman2D* k2d_vy = new Kalman2D();
    double qx = atof(TextCtrl_qx->GetValue().c_str());
    double qx_v = atof(TextCtrl_qx_v->GetValue().c_str());
    double qv = atof(TextCtrl_qv->GetValue().c_str());
    double qa = atof(TextCtrl_qa->GetValue().c_str());
    double r = atof(TextCtrl_r->GetValue().c_str());
    double ra = atof(TextCtrl_ra->GetValue().c_str());

    k2d_x->Reset(qx,qx_v,r,200,0);
    k2d_y->Reset(qx,qx_v,r,200,0);
    k2d_vx->Reset(qv,qa,ra,200,0);
    k2d_vy->Reset(qv,qa,ra,200,0);

    GpsPath gp = GpsPath(atof(TextCtrl_seed->GetValue().c_str()));
    vector<double> ideal_x, ideal_y;
    for(unsigned int i=0; i<gp.Ideal_Time.size(); i+=100)
    {
        ideal_x.push_back(gp.Ideal_X[i]);
        ideal_y.push_back(gp.Ideal_Y[i]);
    }
    vector<double> meas_x, meas_y;
    for(unsigned int i=0; i<gp.Meas_Time.size(); i++)
    {
        meas_x.push_back(gp.Meas_X[i]);
        meas_y.push_back(gp.Meas_Y[i]);
    }

    //------------- Kalman Filter----------------
    vector<double> kalman_kx, kalman_ky;
    vector<double> pos_id, error_kalman_pos, error_meas_pos;

    vector<double> bag_xv,bag_yv,bag_x,bag_y;
    vector<double> kal_xv,kal_yv,kal_x,kal_y;

    vector<double> err_xv,err_yv,err_x,err_y;
    vector<double> err_kxv,err_kyv,err_kx,err_ky;

    double dt = gp.Meas_Time[1] - gp.Meas_Time[0];
    for(unsigned int i=0; i<gp.Meas_Time.size(); i++)
    {
        double vx = k2d_vx->Update(gp.Meas_VX[i],gp.Meas_AX[i],dt);
        double vy = k2d_vy->Update(gp.Meas_VY[i],gp.Meas_AY[i],dt);
        double kx = k2d_x->Update(gp.Meas_X[i],vx,dt);
        double ky = k2d_y->Update(gp.Meas_Y[i],vy,dt);
        kalman_kx.push_back(kx);
        kalman_ky.push_back(ky);
        int oversampling = gp.GetPosOverSampling();
        double dx = kx-gp.Ideal_X[i*oversampling];
        double dy = ky-gp.Ideal_Y[i*oversampling];
        double d_meas_x = gp.Meas_X[i] - gp.Ideal_X[i*oversampling];
        double d_meas_y = gp.Meas_Y[i] - gp.Ideal_Y[i*oversampling];
        error_kalman_pos.push_back(sqrt(dx*dx + dy*dy));
        error_meas_pos.push_back(sqrt(d_meas_x*d_meas_x + d_meas_y*d_meas_y));
        pos_id.push_back(i);

        bag_xv.push_back(gp.Meas_VX[i]);
        kal_xv.push_back(vx);
        bag_yv.push_back(gp.Meas_VY[i]);
        kal_yv.push_back(vy);
        bag_x.push_back(gp.Meas_X[i]);
        kal_x.push_back(kx);
        bag_y.push_back(gp.Meas_Y[i]);
        kal_y.push_back(ky);

        //error
        err_xv.push_back(gp.Meas_VX[i]-gp.idealVX[i]);
        err_kxv.push_back(vx-gp.idealVX[i]);
        err_yv.push_back(gp.Meas_VY[i]-gp.idealVY[i]);
        err_kyv.push_back(vy-gp.idealVY[i]);
        err_x.push_back(gp.Meas_X[i]-gp.Ideal_X[i*oversampling]);
        err_kx.push_back(kx-gp.Ideal_X[i*oversampling]);
        err_y.push_back(gp.Meas_Y[i]-gp.Ideal_Y[i*oversampling]);
        err_ky.push_back(ky-gp.Ideal_Y[i*oversampling]);
    }
    //-------------------------------------------

    mpInfoLegend* leg1 = new mpInfoLegend(wxRect(100,50,40,40), wxTRANSPARENT_BRUSH);
    mpWindow* m_plot = new mpWindow(Panel_kalman, -1, wxPoint(0,0), Panel_kalman->GetSize(), wxSUNKEN_BORDER );

    wxPen vectorpen(*wxBLUE,3,wxSOLID);
    Draw(m_plot, vectorpen, "meas", leg1, meas_x, meas_y, false);

    vectorpen.SetColour(*wxRED);
    Draw(m_plot, vectorpen, "kalman", leg1, kalman_kx, kalman_ky, false);

    vectorpen.SetColour(*wxBLACK);
    Draw(m_plot, vectorpen, "ideal", leg1, ideal_x, ideal_y, false);

    //---------------------------------------------------------------
    mpWindow* m_plot_err = new mpWindow(Panel_error, -1, wxPoint(0,0), Panel_error->GetSize(), wxSUNKEN_BORDER );
    mpInfoLegend* leg2 = new mpInfoLegend(wxRect(100,0,40,40), wxTRANSPARENT_BRUSH);

    vectorpen.SetColour(*wxBLUE);
    Draw(m_plot_err, vectorpen, "meas_error", leg2, pos_id, error_meas_pos, false);

    vectorpen.SetColour(*wxRED);
    Draw(m_plot_err, vectorpen, "kalman_error", leg2, pos_id, error_kalman_pos, false);

    //-------------------------------------------
    mpWindow* m_plot_xv = new mpWindow(Panel_xv, -1, wxPoint(0,0), Panel_xv->GetSize(), wxSUNKEN_BORDER );
    mpInfoLegend* leg3 = new mpInfoLegend(wxRect(100,0,40,40), wxTRANSPARENT_BRUSH);

    vectorpen.SetColour(*wxBLUE);
    Draw(m_plot_xv, vectorpen, "speed of x before filter", leg3, pos_id, bag_xv, false);

    vectorpen.SetColour(*wxRED);
    Draw(m_plot_xv, vectorpen, "speed of x after filter", leg3, pos_id, kal_xv, false);

    //-----------------------------------------------------------
    mpWindow* m_plot_yv = new mpWindow(Panel_yv, -1, wxPoint(0,0), Panel_yv->GetSize(), wxSUNKEN_BORDER );
    mpInfoLegend* leg4 = new mpInfoLegend(wxRect(100,0,40,40), wxTRANSPARENT_BRUSH);

    vectorpen.SetColour(*wxBLUE);
    Draw(m_plot_yv, vectorpen, "speed of y before filter", leg4, pos_id, bag_yv, false);

    vectorpen.SetColour(*wxRED);
    Draw(m_plot_yv, vectorpen, "speed of y after filter", leg4, pos_id, kal_yv, false);

    //---------------------------------------------------------------
    mpWindow* m_plot_x = new mpWindow(Panel_x, -1, wxPoint(0,0), Panel_x->GetSize(), wxSUNKEN_BORDER );
    mpInfoLegend* leg5 = new mpInfoLegend(wxRect(100,80,40,40), wxTRANSPARENT_BRUSH);

    vectorpen.SetColour(*wxBLUE);
    Draw(m_plot_x, vectorpen, "position of x before filter", leg5, pos_id, bag_x, false);

    vectorpen.SetColour(*wxRED);
    Draw(m_plot_x, vectorpen, "position of x after filter", leg5, pos_id, kal_x, false);

    //---------------------------------------------------------------
    mpWindow* m_plot_y = new mpWindow(Panel_y, -1, wxPoint(0,0), Panel_y->GetSize(), wxSUNKEN_BORDER );
    mpInfoLegend* leg6 = new mpInfoLegend(wxRect(100,80,40,40), wxTRANSPARENT_BRUSH);

    vectorpen.SetColour(*wxBLUE);
    Draw(m_plot_y, vectorpen, "position of y before filter", leg6, pos_id, bag_y, false);

    vectorpen.SetColour(*wxRED);
    Draw(m_plot_y, vectorpen, "position of y after filter", leg6, pos_id, kal_y, false);

    //--------------------------------------------------------
    StatusBar1->SetStatusText("By: Xionghao Liu       ID: 12212894");

    //result output
    double vx_rmse,kvx_rmse,vy_rmse,kvy_rmse,x_rmse,kx_rmse,y_rmse,ky_rmse,rmse,krmse;
    vx_rmse = RMSE(err_xv);kvx_rmse = RMSE(err_kxv);
    vy_rmse = RMSE(err_yv);kvy_rmse = RMSE(err_kyv);
    x_rmse = RMSE(err_x);kx_rmse = RMSE(err_kx);
    y_rmse = RMSE(err_y);ky_rmse = RMSE(err_ky);
    rmse = RMSE(error_meas_pos);
    krmse = RMSE(error_kalman_pos);

    string msg, res;
    stringstream ss1,ss11,ss2,ss22,ss3,ss33,ss4,ss44,ss5,ss55;
    ss1 << vx_rmse; ss1 >> msg; res = "VX-RMSE(BF): " + msg + "\n";
    ss11 << kvx_rmse; ss11 >> msg; res += "VX-RMSE(AF): " + msg + "\n";

    ss2 << vy_rmse; ss2 >> msg; res += "VY-RMSE(BF): " + msg + "\n";
    ss22 << kvy_rmse; ss22 >> msg; res += "VY-RMSE(AF): " + msg + "\n";

    ss3 << x_rmse; ss3 >> msg; res+= "X-RMSE(BF): " + msg + "\n";
    ss33 << kx_rmse; ss33 >> msg; res+= "X-RMSE(AF): " + msg + "\n";

    ss4 << y_rmse; ss4 >> msg; res += "Y-RMSE(BF): " + msg + "\n";
    ss44 << ky_rmse; ss44 >> msg; res += "Y-RMSE(AF): " + msg + "\n";

    ss5<< rmse; ss5 >> msg; res += "RMSE(BF): " + msg + "\n";
    ss55 << krmse; ss55 >>msg; res += "RMSE(AF): " + msg;

    TextCtrl_result->SetValue(res);
}

void KalmanDemoFrame::Draw(mpWindow* m_plot, wxPen vectorpen, string name, mpInfoLegend* leg, vector<double>& xs, vector<double>& ys, bool isContinuity)
{
    mpFXYVector* vectorLayer = new mpFXYVector(name);
    vectorLayer->SetData(xs,ys);
    vectorLayer->SetContinuity(isContinuity);
    vectorLayer->SetPen(vectorpen);
    vectorLayer->SetDrawOutsideMargins(false);

    //mp_text->SetPen(vectorpen);

    mpScaleX* xaxis = new mpScaleX(wxT("X"), mpALIGN_BOTTOM, true, mpX_NORMAL);
    mpScaleY* yaxis = new mpScaleY(wxT("Y"), mpALIGN_LEFT, true);

    m_plot->AddLayer(xaxis);
    m_plot->AddLayer(yaxis);
    m_plot->AddLayer(vectorLayer);
    //m_plot->AddLayer(mp_text);

    //mpInfoLegend* leg;
    m_plot->AddLayer(leg); //&hatch2));
    leg->SetVisible(true);

    m_plot->EnableDoubleBuffer(true);
    //m_plot->SetMPScrollbars(false);
    m_plot->Fit();
}

double KalmanDemoFrame::RMSE(vector<double> vecs)
{
    int num;
    double mu, rms,sum;
    num = vecs.size();
    sum = 0;
    for(int i=0; i<num; i++)
    {
        sum += vecs[i];
    }
    mu = sum/num;
    sum = 0;
    for(int i=0; i<num; i++)
    {
        sum += (vecs[i]-mu)*(vecs[i]-mu);
    }
    rms = sum/num;
    rms = sqrt(rms);
    return rms;
}


