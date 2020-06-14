#ifndef ZFLYINGOBJECT_H
#define ZFLYINGOBJECT_H

#include <QWidget>
#include <QMovie>

#include "zObject.h"
#include "zScene.h"
#include "zAnim.h"

class zFlyingObject : public zObject
{
public:
    zFlyingObject(QWidget* parent = 0);
    virtual void act();
    int raw;
    bool canFire = false;
};

class zPea : public zFlyingObject
{
public:
    zPea(QWidget* parent = 0);
    ~zPea();
    void act();
private:
    QMovie* anim = new QMovie(":/FlyingObjects/Pea.gif");
    int speed;
};
#endif // ZFLYINGOBJECT_H
