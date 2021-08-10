/***************************************************************
 * Name:      convertisseurApp.cpp
 * Purpose:   Code for Application Class
 * Author:    G.Raapoto ()
 * Created:   2020-05-01
 * Copyright: G.Raapoto ()
 * License:
 **************************************************************/

#include "convertisseurApp.h"
#include "wx/msgdlg.h"

//AppHeaders
#include "convertisseurMain.h"
#include <wx/image.h>


IMPLEMENT_APP(convertisseurApp);

bool convertisseurApp::OnInit()
{
    //AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxMessageBox( wxT("Le programme est encore en chantier."), wxT("Bienvenue"));

    	// d�claration des composantes MVP de l'application
        convertisseurFrame* vue ;               // composante Vue de l'application
        convertisseurPresentation* presentation ; // composante Pr�sentation de l'application
        convertisseurModele* modele ;           // composante Mod�le de l'application

        vue = new convertisseurFrame();
        modele = new convertisseurModele();
        presentation = new convertisseurPresentation();

        presentation->setVue(vue);
        presentation->setModele(modele);
        // La vue conna�t la pr�sentation
        vue->setPresentation(presentation);

    	vue->Show();    //Affichage
    	SetTopWindow(vue);  //Mise en évidence
    }

    return wxsOK;
}
