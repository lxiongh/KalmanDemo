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
enum wxbuildinfoformat {
    short_f, long_f };

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
    wxMenuItem* MenuItem2;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("KalmanDemo V1.0"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel_kalman = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(330,218), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1->Add(Panel_kalman, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_error = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxSize(330,217), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer1->Add(Panel_error, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 13, 0, 0);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Seed"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_seed = new wxTextCtrl(this, ID_TEXTCTRL7, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    BoxSizer2->Add(TextCtrl_seed, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 6, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("qx"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_qx = new wxTextCtrl(this, ID_TEXTCTRL1, _("0.01"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer3->Add(TextCtrl_qx, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("qx_v"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_qx_v = new wxTextCtrl(this, ID_TEXTCTRL6, _("0.5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    FlexGridSizer3->Add(TextCtrl_qx_v, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("r"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_r = new wxTextCtrl(this, ID_TEXTCTRL2, _("0.1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer3->Add(TextCtrl_r, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("qv"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_qv = new wxTextCtrl(this, ID_TEXTCTRL3, _("0.01"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer3->Add(TextCtrl_qv, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("qa"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_qa = new wxTextCtrl(this, ID_TEXTCTRL4, _("0.1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer3->Add(TextCtrl_qa, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("ra"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer3->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_ra = new wxTextCtrl(this, ID_TEXTCTRL5, _("0.1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer3->Add(TextCtrl_ra, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_run = new wxButton(this, ID_BUTTON1, _("Run"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
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
    StatusBar1->SetStatusText("Sun Yat-sen University   by Xionghao Liu  Email: lxiongh@126.com  4/28/2013");
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
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
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
    for(unsigned int i=0; i<gp.Ideal_Time.size(); i+=100){
        ideal_x.push_back(gp.Ideal_X[i]);
        ideal_y.push_back(gp.Ideal_Y[i]);
    }
    vector<double> meas_x, meas_y;
    for(unsigned int i=0; i<gp.Meas_Time.size(); i++){
        meas_x.push_back(gp.Meas_X[i]);
        meas_y.push_back(gp.Meas_Y[i]);
    }

    //------------- Kalman Filter----------------
    vector<double> kalman_kx, kalman_ky;
    vector<double> pos_id, error_kalman_pos, error_meas_pos;
    double dt = gp.Meas_Time[1] - gp.Meas_Time[0];
    for(unsigned int i=0; i<gp.Meas_Time.size(); i++){
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
    }
    //-------------------------------------------
    double pos_x = 75;//Panel_kalman->GetSize().GetWidth()-5;
    double pos_y = 90;//Panel_kalman->GetSize().GetHeight()-5;

    mpWindow* m_plot = new mpWindow(Panel_kalman, -1, wxPoint(0,0), Panel_kalman->GetSize(), wxSUNKEN_BORDER );
    wxPen vectorpen(*wxBLUE,3,wxSOLID);

    Draw(m_plot, vectorpen, new mpText(wxT("meas(blue)"),pos_x, pos_y-5), meas_x, meas_y, false);
    vectorpen.SetColour(*wxRED);

    Draw(m_plot, vectorpen, new mpText(wxT("kalman(red)"),pos_x, pos_y-10), kalman_kx, kalman_ky, false);
    vectorpen.SetColour(*wxBLACK);
    Draw(m_plot, vectorpen, new mpText(wxT("ideal(black)"),pos_x, pos_y), ideal_x, ideal_y, false);

    mpWindow* m_plot_err = new mpWindow(Panel_error, -1, wxPoint(0,0), Panel_error->GetSize(), wxSUNKEN_BORDER );
    vectorpen.SetColour(*wxBLUE);
    pos_x = 65; pos_y = 0;
    Draw(m_plot_err, vectorpen, new mpText(wxT("meas_error(blue)"),pos_x, pos_y), pos_id, error_meas_pos, false);
    vectorpen.SetColour(*wxRED);
    Draw(m_plot_err, vectorpen, new mpText(wxT("kalman_error(red)"),pos_x, pos_y+5), pos_id, error_kalman_pos, false);
}

void KalmanDemoFrame::Draw(mpWindow* m_plot, wxPen vectorpen, mpText* mp_text, vector<double>& xs, vector<double>& ys, bool isContinuity)
{
    mpFXYVector* vectorLayer = new mpFXYVector();
    vectorLayer->SetData(xs,ys);
    vectorLayer->SetContinuity(isContinuity);
	vectorLayer->SetPen(vectorpen);
	vectorLayer->SetDrawOutsideMargins(false);

    mp_text->SetPen(vectorpen);

    mpScaleX* xaxis = new mpScaleX(wxT("X"), mpALIGN_BOTTOM, true, mpX_NORMAL);
    mpScaleY* yaxis = new mpScaleY(wxT("Y"), mpALIGN_LEFT, true);

    m_plot->AddLayer(xaxis);
    m_plot->AddLayer(yaxis);
    m_plot->AddLayer(vectorLayer);
    m_plot->AddLayer(mp_text);

    m_plot->EnableDoubleBuffer(true);
    //m_plot->SetMPScrollbars(false);
    m_plot->Fit();
}


