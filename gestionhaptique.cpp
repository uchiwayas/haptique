#include "gestionhaptique.h"

GestionHaptique::GestionHaptique(QMainWindow * fen): mFenetre(fen)
{
    //Création de la souris
    mSouris = new CImmMouse();

    if(!mSouris->Initialize(qWinAppInst(),(HWND) mFenetre->effectiveWinId()))
    {
        delete mSouris;
        mSouris = NULL;
        QApplication::quit();
        qDebug() << "==> Erreur chargement souris" << mSouris;
    }

    mProjet = new CImmProject();
    if(mProjet->OpenFile("C:/Users/M2IHM/Documents/projet_hap/friction10k.ifr", mSouris))
    {
        mFriction10k = new CImmFriction();
        if (!mFriction10k->InitializeFromProject(*mProjet, "Friction10k", mSouris,
        IMM_PARAM_NODOWNLOAD))
        { qDebug()<<"===>Erreur chargement mFriction10k ";
        delete mFriction10k;
        mFriction10k = NULL; }

        mFriction5k = new CImmFriction();
        if (!mFriction5k->InitializeFromProject(*mProjet, "Friction5k", mSouris,
        IMM_PARAM_NODOWNLOAD))
        { qDebug()<<"===>Erreur chargement mFriction5k ";
        delete mFriction5k;
        mFriction5k = NULL; }

        mInertie10k = new CImmInertia();
        if (!mInertie10k->InitializeFromProject(*mProjet, "Inertie10k", mSouris,
        IMM_PARAM_NODOWNLOAD))
        { qDebug()<<"===>Erreur chargement mInertie10k ";
        delete mInertie10k;
        mInertie10k = NULL; }

        mInertie5k = new CImmInertia();
        if (!mInertie5k->InitializeFromProject(*mProjet, "Inertie5k", mSouris,
        IMM_PARAM_NODOWNLOAD))
        { qDebug()<<"===>Erreur chargement mInertie5k ";
        delete mInertie5k;
        mInertie5k = NULL; }

        mTextureRoche = new CImmTexture();
        if (!mTextureRoche->InitializeFromProject(*mProjet, "TextureRoche", mSouris,
        IMM_PARAM_NODOWNLOAD))
        { qDebug()<<"===>Erreur chargement mTextureRoche ";
        delete mTextureRoche;
        mTextureRoche = NULL; }

        mMirroir = new CImmEnclosure();
        if (!mMirroir->InitializeFromProject(*mProjet, "Mirroir", mSouris,
        IMM_PARAM_NODOWNLOAD))
        { qDebug()<<"===>Erreur chargement mMirroir ";
        delete mMirroir;
        mMirroir = NULL; }

        mThrophee = new CImmEnclosure();
        if (!mThrophee->InitializeFromProject(*mProjet, "Throphee", mSouris,
        IMM_PARAM_NODOWNLOAD))
        { qDebug()<<"===>Erreur chargement mThrophee ";
        delete mThrophee;
        mThrophee = NULL; }

        mTremblement = new CImmPeriodic();
        if (!mTremblement->InitializeFromProject(*mProjet, "Tremblement", mSouris,
        IMM_PARAM_NODOWNLOAD))
        { qDebug()<<"===>Erreur chargement mTremblement ";
        delete mTremblement;
        mTremblement = NULL; }
    }
    else
    {
        qDebug() << "===> Erreur chargement projet IFR avec code" << CIFCErrors::GetLastErrorCode();
    }
}

CImmProject* GestionHaptique::GetProjet() const
{
    return this->mProjet;
}
