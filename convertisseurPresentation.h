#ifndef CONVERTISSEURPRESENTATION_H_INCLUDED
#define CONVERTISSEURPRESENTATION_H_INCLUDED

#include "convertisseurMain.h"
#include "convertisseurModele.h"
#include <stdlib.h>
#include <sstream>

class convertisseurFrame;

class convertisseurPresentation
{
    private:
        convertisseurFrame* m_vue;
        convertisseurModele* m_modele;

    public:
        convertisseurPresentation();
        virtual ~convertisseurPresentation();

        void setVue(convertisseurFrame*);
        void setModele(convertisseurModele*);

        //Events handlers
        void calculDeclenche() const;
        void effacementDeclenche() const;
        void notificationAcceptee() const;

        //Retourne un booléen indiquant si la valeur passée en paramètre est convertible en fahrenheit
        bool estConvertible(const std::string& s) const;
};


#endif // CONVERTISSEURPRESENTATION_H_INCLUDED
