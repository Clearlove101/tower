#ifndef ZCARD_H
#define ZCARD_H

#include <QLabel>
#include <QMovie>
#include <QSound>
#include <QMouseEvent>

#include "zObject.h"
#include "zScene.h"

class zCard : public zObject
{
public:
    zCard(QWidget* parent = 0);
    ~zCard();
    int plantIndex;
    int sunPoint = 50;
    int frame_max = 1, frame = 1;
    virtual void act();
    QWidget* front;
    QWidget* back;
    QLabel* frontText;
    void setIndex(int index);
    void transFront();
protected:
    void mousePressEvent(QMouseEvent* event);
};

class zSunFlowerCard : public zCard
{
public:
    zSunFlowerCard(QWidget* parent = 0);
    ~zSunFlowerCard();
private:
    QMovie* anim = new QMovie(":/Cards/rc/card_Sunflower.png");
};

class zPeaShooterCard : public zCard
{
public:
    zPeaShooterCard(QWidget* parent = 0);
    ~zPeaShooterCard();
private:
    QMovie* anim = new QMovie(":/Cards/rc/card_PeaShooter.png");
};

class zWallNutCard : public zCard
{
public:
    zWallNutCard(QWidget* parent = 0);
    ~zWallNutCard();
private:
    QMovie* anim = new QMovie(":/Cards/rc/card_WallNut.png");
};

class zIcePeaShooterCard: public zCard
{
public:
    zIcePeaShooterCard(QWidget* parent = 0);
    ~zIcePeaShooterCard();
private:
    QMovie* anim = new QMovie(":/Cards/rc/card_IcePeaShooter.png");
};

#endif // ZCARD_H
