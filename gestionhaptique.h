#ifndef GESTIONHAPTIQUE_H
#define GESTIONHAPTIQUE_H

#undef UNICODE

#include <ifc.h>
#include <QMainWindow>
#include <QDebug>
#include <QApplication>
class QMainWindow;

class GestionHaptique
{
public:
    QMainWindow *mFenetre;
    CImmMouse *mSouris;
    CImmProject *mProjet;
    CImmFriction *mFriction10k;
    CImmFriction *mFriction5k;
    CImmInertia *mInertie10k;
    CImmInertia *mInertie5k;
    CImmGrid *mBosse;
    CImmTexture *mTextureRoche;
    CImmEnclosure *mMirroir;
    GestionHaptique(QMainWindow * fen);
    ~GestionHaptique();
    CImmProject *GetProjet() const;
};

#endif // GESTIONHAPTIQUE_H
