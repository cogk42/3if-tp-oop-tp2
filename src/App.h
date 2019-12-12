/*************************************************************************
                           App  -  description
                             -------------------
    début                : 2019-11-19
    copyright            : (C) 2019 BERTHOMET Guillaume & FORLER Corentin
    e-mail               : guillaume.berthomet@insa-lyon.fr
                           corentin.forler@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <App> (fichier App.h) ----------------
#if !defined(APP_H)
#define APP_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalog.h"
#include "CompoundTrip.h"
#include "SimpleTrip.h"
#include "Trip.h"
#include "UI.h"

//------------------------------------------------------------- Constantes
#define EOL "\r\n"

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <App>
//
//
//------------------------------------------------------------------------

class App
{
    //----------------------------------------------------------------- PUBLIC

    enum MenuStatus
    {
        DONE, // On a terminé sans problème.
        ERROR // On sort de la boucle et on a déjà
              // affiché une erreur à l'utilisateur.
    };

public:
    //----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    //
    // Contrat :
    //
    int Run();

    // On désactive l'opérateur d'affectation
    App &operator=(const App &) = delete;

    //-------------------------------------------- Constructeurs - destructeur
    // On désactive le constructeur de copie
    App(const App &anApp) = delete;

    App();
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~App();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Catalog *catalog;

    MenuStatus menuPrincipal();
    MenuStatus menuConsulter() const;
    MenuStatus menuAjouter();
    MenuStatus menuAjouterTrajetSimple();
    MenuStatus menuAjouterTrajetCompose();
    MenuStatus menuRechercher() const;
};

//-------------------------------- Autres définitions dépendantes de <App>

#endif // APP_H
