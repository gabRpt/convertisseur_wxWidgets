#include "convertisseurModele.h"

//Valeurs par défaut 0°C = 32°F
convertisseurModele::convertisseurModele():
    m_celsius(0),
    m_fahrenheit(32){
}


convertisseurModele::convertisseurModele(float val):
    m_celsius(val){
        this->m_fahrenheit = this->celsiusToFahrenheit(val);
}

convertisseurModele::~convertisseurModele()
{

}

void convertisseurModele::setCelsius(float val)
{
    this->m_celsius = val;
    this->m_fahrenheit = this->celsiusToFahrenheit(val);
}

float convertisseurModele::getCelsius() const
{
    return this->m_celsius;
}

float convertisseurModele::getFahrenheit() const
{
    return this->m_fahrenheit;
}

//Contient la formule de conversion °C -> °F
float convertisseurModele::celsiusToFahrenheit(float val)
{
    return (val*9.000000/5.000000+32.000000);
}
