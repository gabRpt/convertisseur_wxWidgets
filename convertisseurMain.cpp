/***************************************************************
 * Name:      convertisseurMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    G.Raapoto ()
 * Created:   2020-05-01
 * Copyright: G.Raapoto ()
 * License:
 **************************************************************/

#include "convertisseurMain.h"
#include <wx/msgdlg.h>
#include <wx/sizer.h>

//InternalHeaders(convertisseurFrame)
#include <wx/font.h>
#include <wx/intl.h>

#include <wx/numformatter.h>


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

//IdInit(convertisseurFrame)
const long convertisseurFrame::ID_STATICTEXT1 = wxNewId();
const long convertisseurFrame::ID_STATICTEXT2 = wxNewId();
const long convertisseurFrame::ID_TEXTCTRL1 = wxNewId();
const long convertisseurFrame::ID_STATICTEXT4 = wxNewId();
const long convertisseurFrame::ID_BUTTON2 = wxNewId();
const long convertisseurFrame::ID_STATICTEXT3 = wxNewId();
const long convertisseurFrame::ID_BUTTON1 = wxNewId();
const long convertisseurFrame::ID_PANEL1 = wxNewId();


BEGIN_EVENT_TABLE(convertisseurFrame,wxFrame)
    //EventTable(convertisseurFrame)

END_EVENT_TABLE()

convertisseurFrame::convertisseurFrame()
{
    //Initialize(convertisseurFrame)
    Create(0, wxID_ANY, _("Celsius To Fahrenheit � v8"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(280,140));
    SetFocus();

    panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(280,140), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panel1->SetFocus();

    // https://docs.wxwidgets.org/3.0/classwx_static_text.html
    txtStatic_titre = new wxStaticText(panel1, ID_STATICTEXT1, _("Convertisseur de temp�ratures"), wxPoint(18,16), wxSize(245,19), 0, _T("ID_STATICTEXT1"));
    wxFont txtStatic_titreFont(13,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    txtStatic_titre->SetFont(txtStatic_titreFont);

    txtStatic_celsius = new wxStaticText(panel1, ID_STATICTEXT2, _("Degr�s Celsius"), wxPoint(40,48), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont txtStatic_celsiusFont(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txtStatic_celsius->SetFont(txtStatic_celsiusFont);

    // https://docs.wxwidgets.org/3.0/classwx_text_ctrl.html
    txtCtrl_celsius = new wxTextCtrl(panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(40,64), wxSize(88,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont txtCtrl_celsiusFont(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txtCtrl_celsius->SetFont(txtCtrl_celsiusFont);

    txtStatic_farenheit = new wxStaticText(panel1, ID_STATICTEXT4, _("Degr�s Farenheit"), wxPoint(144,48), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont txtStatic_farenheitFont(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txtStatic_farenheit->SetFont(txtStatic_farenheitFont);

    // https://docs.wxwidgets.org/3.0/classwx_button.html
    button_effacer = new wxButton(panel1, ID_BUTTON2, _("Effacer"), wxPoint(145,100), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont button_effacerFont(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    button_effacer->SetFont(button_effacerFont);

    txtStatic_converted = new wxStaticText(panel1, ID_STATICTEXT3, wxEmptyString, wxPoint(144,67), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont txtStatic_convertedFont(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txtStatic_converted->SetFont(txtStatic_convertedFont);

    button_convertir = new wxButton(panel1, ID_BUTTON1, _("Convertir"), wxPoint(40,100), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Center();

    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&convertisseurFrame::Onbutton_effacerClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&convertisseurFrame::Onbutton_convertirClick1);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&convertisseurFrame::OnClose);

    txtCtrl_celsius->SetFocus();    //éléement pré-sélectionné lorsqu'on ouvre l'app
    //Changement de l'ordre d'accès aux élements de l'app lorsqu'on appuie sur TAB
    button_convertir->MoveAfterInTabOrder(txtCtrl_celsius);
    button_effacer->MoveAfterInTabOrder(button_convertir);

    //Cr�ation
    wxBoxSizer* sizerTop = new wxBoxSizer(wxVERTICAL);      //Contient tous les sizer horizontaux
    wxBoxSizer* sizerVGauche = new wxBoxSizer(wxVERTICAL);  //Contient la partie gauche (sans les boutons)
    wxBoxSizer* sizerVDroite = new wxBoxSizer(wxVERTICAL);  //Contient la partie droite (sans les boutons)
    wxBoxSizer* sizerH2 = new wxBoxSizer(wxHORIZONTAL);     //Contient les sizer verticaux gauche et droite
    wxBoxSizer* sizerH3 = new wxBoxSizer(wxHORIZONTAL);     //Contient les boutons

    //Attribution des sizer secondaires
    sizerVGauche->Add(txtStatic_celsius, 0, wxALIGN_LEFT);
    sizerVGauche->Add(txtCtrl_celsius, 0, wxALIGN_LEFT);

    sizerVDroite->Add(txtStatic_farenheit, 0, wxALIGN_LEFT);
    sizerVDroite->Add(txtStatic_converted, 0, wxALIGN_LEFT);

    sizerH2->Add(sizerVGauche,0,wxALL,10);
    sizerH2->Add(sizerVDroite,0,wxALL,10);

    sizerH3->Add(button_convertir, 0, wxALL|wxALIGN_BOTTOM ,5);
    sizerH3->Add(button_effacer, 0, wxALL|wxALIGN_BOTTOM ,5);

    //Mise des sizer horizontaux dans le sizer vertical final
    sizerTop->Add(txtStatic_titre, 0, wxRIGHT|wxLEFT|wxTOP|wxALIGN_CENTER_HORIZONTAL, 10);  //1er niveau
    sizerTop->Add(sizerH2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 1);                          //2�me niveau
    sizerTop->Add(sizerH3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 8);                          //3�me niveau

    panel1->SetSizer(sizerTop);
    sizerTop->SetSizeHints(this);
}
//! Gestionnaire  d'�v�nements

convertisseurFrame::~convertisseurFrame()
{

}

//Gère l'évenement de la fermeture de l'application
void convertisseurFrame::OnClose(wxCloseEvent& event)
{
    int retour = wxMessageBox("Quitter le programme ?","Confirmation de fermeture",wxYES_NO | wxICON_QUESTION);
    if (retour == wxYES){
        Destroy();
        delete this->m_presentation;
    }
}

//Gère l'évènement du click sur le bouton de conversion
void convertisseurFrame::Onbutton_convertirClick1(wxCommandEvent& event)
{
    this->m_presentation->calculDeclenche();
}

//Gère l'évènement du click sur le bouton effacer
void convertisseurFrame::Onbutton_effacerClick(wxCommandEvent& event)
{
    this->clearFht();
    this->clearCelsius();
}

// Retourne la valeur saisie en celcius
string convertisseurFrame::getValC() const
{

    wxString wxS = txtCtrl_celsius->GetLineText(0);
    string s = wxS.ToStdString();

    return s;
}

// Gère l'affichage des degrés fht
void convertisseurFrame::setFht(float tempF)
{
    wxString wxS;
    wxS = wxNumberFormatter::ToString(tempF,7);
    txtStatic_converted->SetLabel(wxS);
}

//Affiche le message d'erreurs passé en paramètre, déclenche le clear les valeurs de l'application
void convertisseurFrame::errorMsg(string titre, string message)
{
    wxMessageBox(message,titre,wxOK | wxICON_ERROR);
    this->clearFht();
    this->clearCelsius();
}

//Efface les degrés celcius
void convertisseurFrame::clearCelsius()
{
    txtCtrl_celsius->SetLabel("");
    txtCtrl_celsius->SetFocus();    //Mise en focus de la textBox
}

//Efface les dregrés fht
void convertisseurFrame::clearFht()
{
    txtStatic_converted->SetLabel("");
}

//Setter presentation
void convertisseurFrame::setPresentation(convertisseurPresentation* p)
{
    this->m_presentation = p;
}
