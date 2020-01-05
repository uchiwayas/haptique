#ifndef GESTIONHAPTIQUE_H
#define GESTIONHAPTIQUE_H

#undef UNICODE

#include <ifc.h>
#include <QMainWindow>
#include <QDebug>
#include <QApplication>
class QMainWindow;

/**
 * @brief The GestionHaptique class
 * Classe pour la gestion haptique et sonore
 */
class GestionHaptique
{
public:
    static GestionHaptique* getInstance(QMainWindow*);
    static void killInstance();
private:
    static GestionHaptique* instance;
    GestionHaptique(QMainWindow * fen);
    ~GestionHaptique();
public:
    QMainWindow *mFenetre;
    CImmMouse *mSouris;
    CImmProject *mProjet;
    CImmFriction *mFriction10k;
    CImmFriction *mFriction5k;
    CImmInertia *mInertie10k;
    CImmInertia *mInertie5k;
    CImmEnclosure *mThrophee;
    CImmTexture *mTextureRoche;
    CImmEnclosure *mPaint;
    CImmPeriodic *mTremblement;
    CImmProject *GetProjet() const;
};

#endif // GESTIONHAPTIQUE_H
