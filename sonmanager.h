#ifndef SONMANAGER_H
#define SONMANAGER_H
#include <QMediaPlayer>
#include <vector>

class SonManager
{
private:
    static const char* sons[];
    static SonManager * instance;

    SonManager();
    ~SonManager();

    std::vector<QMediaPlayer *> sounds;
    QMediaPlayer* playerBackground;

public:
    enum {DEBUT = 0, AMBIANT,
          CHAPITRE_1, CHAPITRE_2,
          CHAPITRE_3, EFFONDREMENT,
          END, PANIC,
          PORTE, REVEIL,
          HEAVEN, BIRD};


    static SonManager* getInstance();
    static void killManager();

    static void playBackground();
    static void pauseBackground();
    static void stopBackground();

    static void play(const int &i);

    static void clearAllSounds();

};

#endif // SONMANAGER_H
