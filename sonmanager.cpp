#include "sonmanager.h"
#include <QDebug>
#include <QMediaPlaylist>

SonManager* SonManager::instance = NULL;

const char* SonManager::sons[] = {
    "qrc:/sons/sons/début.mp3",
    "qrc:/ambiant/sons/ambiant_short.mp3",
    "qrc:/sons/sons/chap1.mp3",
    "qrc:/sons/sons/chap2.mp3",
    "qrc:/sons/sons/chap3.mp3",
    "qrc:/sons/sons/effondrement.mp3",
    "qrc:/sons/sons/end.mp3",
    "qrc:/sons/sons/panic.mp3",
    "qrc:/sons/sons/porte.mp3",
    "qrc:/sons/sons/reveil.mp3",
    "qrc:/sons/sons/heaven.mp3",
    "qrc:/sons/sons/bird.mp3"
};

SonManager::SonManager()
{
    playerBackground = new QMediaPlayer();
    sounds = std::vector<QMediaPlayer *>();
}

SonManager::~SonManager()
{
    clearAllSounds();

    if(playerBackground->state() != QMediaPlayer::StoppedState)
        playerBackground->stop();

    delete playerBackground;
}

SonManager* SonManager::getInstance(){
    if (instance == NULL)
        instance = new SonManager();
    return instance;
}

void SonManager::killManager(){
    delete instance;
    instance = NULL;
}

void SonManager::playBackground(){
    if(getInstance()->playerBackground->playlist() == NULL){
        QMediaPlaylist *playlist = new QMediaPlaylist();
        playlist->addMedia(QUrl(sons[AMBIANT]));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        getInstance()->playerBackground->setPlaylist(playlist);
    }

    getInstance()->playerBackground->play();
}
void SonManager::pauseBackground(){
    getInstance()->playerBackground->pause();
}
void SonManager::stopBackground(){
    getInstance()->playerBackground->stop();
}

void SonManager::play(const int &i)
{
    QMediaPlayer * toAdd = new QMediaPlayer();
    getInstance()->sounds.push_back(toAdd);
    if(i == BIRD)//Si c'est le son de l'oiseau, on le fait boucler
    {
        QMediaPlaylist *playlist = new QMediaPlaylist();
        playlist->addMedia(QUrl(sons[BIRD]));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        toAdd->setPlaylist(playlist);
    }
    else // pas de comportement spéciale pour les autres son
        toAdd->setMedia(QUrl(sons[i]));
    if(i == PANIC) toAdd->setVolume(70); //La musique lors de l'effondrement est trop forte par rapport au Sound Effects

    toAdd->play();
}

//Just to re-commit
void SonManager::clearAllSounds(){
    for(QMediaPlayer * p : getInstance()->sounds)
    {
        if(p->state() != QMediaPlayer::StoppedState)
            p->stop();
        delete p;
    }
    getInstance()->sounds.clear();
}
