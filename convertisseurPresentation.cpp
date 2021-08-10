#include "convertisseurPresentation.h"

convertisseurPresentation::convertisseurPresentation():
    m_vue(new convertisseurFrame),
    m_modele(new convertisseurModele()){
}

convertisseurPresentation::~convertisseurPresentation()
{
    delete this->m_vue;
    delete this->m_modele;
}

void convertisseurPresentation::setVue(convertisseurFrame* vue)
{
    this->m_vue = vue;
}

void convertisseurPresentation::setModele(convertisseurModele* modele)
{
    this->m_modele = modele;
}

void convertisseurPresentation::calculDeclenche() const
{
    const string s = this->m_vue->getValC();
    float valC;

    if (this->estConvertible(s)){
        // https://www.cplusplus.com/reference/cstdlib/atof/
        // https://www.cplusplus.com/reference/string/string/c_str/
        valC = atof(s.c_str()); 
        this->m_modele->setCelsius(valC);
        this->m_vue->setFht(this->m_modele->getFahrenheit());
    }
    else
    {
        this->m_vue->errorMsg("Calcul impossible :","Le champ des temperatures Celsius est vide ou bien ne contient pas de valeur numerique.");
    }
}

bool convertisseurPresentation::estConvertible(const std::string& s) const
{
    // http://www.cplusplus.com/reference/sstream/istringstream/str/
    std::istringstream iss(s);
    float f;
    iss >> noskipws >> f; // noskipws consid�re les espaces comme invalides https://www.cplusplus.com/reference/ios/noskipws/
                          // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

void convertisseurPresentation::effacementDeclenche() const
{
    this->m_vue->clearCelsius();
    this->m_vue->clearFht();
}

void convertisseurPresentation::notificationAcceptee() const
{
    this->effacementDeclenche();
}
