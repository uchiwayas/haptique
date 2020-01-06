#ifndef SONMANAGER_H
#define SONMANAGER_H
#include <QMediaPlayer>
#include <vector>

/**
 * @brief The SonManager : Singleton responsable de s'occuper des sons
 */
class SonManager
{
private:
    /**
     * @brief sons : Chemin d'accès pour les différents sons
     */
    static const char* sons[];

    /**
     * @brief instance : Instance du Singleton
     */
    static SonManager * instance;

    SonManager();
    ~SonManager();

    /**
     * @brief sounds : Tableau des players d'effets sonores
     */
    std::vector<QMediaPlayer *> sounds;

    /**
     * @brief playerBackground : Player responsable de l'ambiance
     */
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
