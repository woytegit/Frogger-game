#ifndef FROG_H
#define FROG_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

/** Klasa odpowiedzialna za tworzenie bohatera gry */
class Frog :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /** Constructor of Frog class
    * @param w parametr mowiacy jaka wielkosc ma pojedyncza kratka w grze
    * */
    Frog(int w=32);
    /**
     * Sprawdzanie ktory klawisz na klawiaturze zostal wcisniety
     * @param event pointer to QKeyEvent
     */
    void keyPressEvent(QKeyEvent * event);
    /**
     * Reset pozycji bohatera (srodek mapy na samym dole)
     */
    void Reset();
    /** Zwraca wartosc aktualnego wyniku punktowego
    * @return aktualny score
    */
    int getScore();
    /** Zwraca wartosc aktualnego najwyzszego wyniku punktowego
    * @return aktualny highscore
    */
    int getHighScore();
    void resetHighscore();
    bool IsAlive;
public slots:
    void IsFrogAlive();
private:
    int grid = 0;
    // Aktualny wynik punktowy bohatera
    int score = 0;
    // Najlepszy wynik punktowy bohatera
    int highscore = 0;
    // Poziom na mapie na ktorym znajduje sie aktualnie bohater
    int line=0;
    // Sprawdzenie czy zaba znajduje sie na klodzie bedac w obszarze wody
    bool frogOnLog;
    /// Sprawdza czy wystapila kolizja miedzy zaba a pojazdem
    void IsCollisionWithCar();
    /// Sprawdza czy wystapila kolizja miedzy zaba a kloda
    void IsFrogOnLog();
    /// Sprawdza czy zaba jest w obszarze wody i nie ma kontaktu z kloda
    void IsFrogInWater();
    /// Sprawdza czy zaba osiagnela cel
    void IsFrogOnFinishPoint();
    bool directionChanged=false;
    /// Sprawdza czy zaba znajduje sie na lini początkowej
    void IsFrogOnStartLine();

};

#endif // FROG_H
