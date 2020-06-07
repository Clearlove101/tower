#ifndef ZPLANT_H
#define ZPLANT_H

class zPlant : public zObject
{
    Q_OBJECT
public:
    zPlant(QWidget* parent = 0);
    virtual void act();
    virtual void hit(int damage);
    int raw, column;
};

//豌豆射手

class zPeaShooter : public zPlant
{
    Q_OBJECT
public:
    zPeaShooter(QWidget* parent = 0);
    ~zPeaShooter();
    void act();
private:
    QMovie* anim = new QMovie(":/Plants/rc/Peashooter.gif");
    int TimerShoot, TimerShoot_max;
};

//太阳花

class zSunFlower : public zPlant
{
    Q_OBJECT
public:
    zSunFlower(QWidget* parent = 0);
    ~zSunFlower();
    void act();
private:
    QMovie* anim = new QMovie(":/Plants/rc/SunFlower.gif");
    int TimerSun, TimerSun_max;
};

//坚果墙

class zWallNut : public zPlant
{
    Q_OBJECT
public:
    zWallNut(QWidget* parent = 0);
    ~zWallNut();
    void act();
private:
    QMovie* anim = new QMovie(":/Plants/rc/WallNut.gif");
    QMovie* anim_1 = new QMovie(":/Plants/rc/Wallnut_1.gif");
    QMovie* anim_2 = new QMovie(":/Plants/rc/Wallnut_2.gif");
};
