#ifndef CONVERTISSEURMODELE_H_INCLUDED
#define CONVERTISSEURMODELE_H_INCLUDED

class convertisseurModele
{
    private:
        float m_celsius;
        float m_fahrenheit;

    public:
        convertisseurModele();          //Constructeur par d�faut
        convertisseurModele(float);     //Constructeur modifiant celsius
        virtual ~convertisseurModele(); //Destructeur

        void setCelsius(float val);     //Setter de m_celsius
        float getCelsius() const;       //Getter de m_celsius
        float getFahrenheit() const;    //Getter de m_fahrenheit

        float celsiusToFahrenheit(float val);       //Conversion de celsius vers fahrenheit
};

#endif // CONVERTISSEURMODELE_H_INCLUDED
