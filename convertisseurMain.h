/***************************************************************
 * Name:      convertisseurMain.h
 * Purpose:   Defines Application Frame
 * Author:    G.Raapoto ()
 * Created:   2020-05-01
 * Copyright: G.Raapoto ()
 * License:
 **************************************************************/

#ifndef CONVERTISSEURMAIN_H
#define CONVERTISSEURMAIN_H

//Headers(convertisseurFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <iostream>
#include "convertisseurPresentation.h"

class convertisseurPresentation;

using namespace std;

class convertisseurFrame: public wxFrame
{
    public:
        convertisseurFrame();
        convertisseurFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~convertisseurFrame();

    private:
        convertisseurPresentation* m_presentation;  //Pointeur vers la pr�sentation

    public:
        string getValC() const;    //Retourne la valeur dans la zone de saisie (celsius)
        void setFht(float tempF);  //Sert � afficher le texte des fahrenheit � l'�cran
        void errorMsg(string titre, string message);    //Affiche un message d'erreur
        void clearCelsius(); //Efface la zone de saisie
        void clearFht(); //Efface les degr�s Fahrenheit
        void setPresentation(convertisseurPresentation*); //Setter de pr�sentation

        //Handlers(convertisseurFrame)
        void OnClose(wxCloseEvent& event);
        void Onbutton_effacerClick(wxCommandEvent& event);
        void Onbutton_convertirClick1(wxCommandEvent& event);


        //Identifiers(convertisseurFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT4;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON1;
        static const long ID_PANEL1;


        //Declarations(convertisseurFrame)
        wxButton* button_convertir;
        wxButton* button_effacer;

        wxPanel* panel1;

        wxStaticText* txtStatic_celsius;
        wxStaticText* txtStatic_converted;
        wxStaticText* txtStatic_farenheit;
        wxStaticText* txtStatic_titre;

        wxTextCtrl* txtCtrl_celsius;



        DECLARE_EVENT_TABLE()
};

#endif // CONVERTISSEURMAIN_H
