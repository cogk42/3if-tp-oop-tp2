/*************************************************************************
                           SimpleTrip  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

// - Réalisation de la classe <SimpleTrip> (fichier SimpleTrip.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "App.h"
#include "SimpleTrip.h"
#include "Trip.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char *SimpleTrip::GetMode() const
{
    return this->mode;
}

void SimpleTrip::Display(std::ostream &out) const
{
    out << "Trajet Simple: " << startCity << " -> " << endCity << " (" << mode << ")" << EOL;
}

// Méthode virtuelle qui construit une copie de l'objet
// à l'aide du constructeur de copie
Trip *SimpleTrip::Clone() const
{
    return new SimpleTrip(*this);
}

//-------------------------------------------- Constructeurs - destructeur
SimpleTrip::SimpleTrip(const SimpleTrip &aSimpleTrip)
    : SimpleTrip(aSimpleTrip.startCity, aSimpleTrip.endCity, aSimpleTrip.mode)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SimpleTrip>" << endl;
#endif
} //----- Fin de SimpleTrip (constructeur de copie)

SimpleTrip::SimpleTrip(const char *start, const char *end, const char *mode)
    : Trip::Trip(start, end)
{
#ifdef MAP
    cout << "Appel au constructeur de <SimpleTrip>" << endl;
#endif
    if (mode != nullptr)
    {
        char *tmpMode = new char[strlen(mode) + 1];
        strcpy(tmpMode, mode);
        this->mode = tmpMode;
    }
    else
    {
        this->mode = nullptr;
    }
} //----- Fin de SimpleTrip

SimpleTrip::~SimpleTrip()
{
#ifdef MAP
    cout << "Appel au destructeur de <SimpleTrip>" << endl;
#endif
    delete[] mode;
} //----- Fin de ~SimpleTrip

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
