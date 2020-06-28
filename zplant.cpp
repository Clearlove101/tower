#include "zPlant.h"

zPlant::zPlant(QWidget *parent) : zObject(parent)
{

}

void zPlant::act()
{

}

void zPlant::hit(int damage)
{
    this->strength -= damage;
    if (this->strength <= 0)
    {
        this->alive = false;
    }
}



zPeaShooter::zPeaShooter(QWidget *parent) : zPlant(parent)
{
    this->setMovie(anim);
    anim->start();
    this->show();
    this->TimerShoot_max = 50;
    this->TimerShoot = this->TimerShoot_max;
    this->strength = 200;
}

void zPeaShooter::act()
{
    if (this->TimerShoot <= 0)
    {
        if (!(scene->hasEnemy[this->raw]))
        {
            this->TimerShoot = qrand() % 20;// not to shoot too many peas in a single timer event
            return;
        }
        this->TimerShoot = this->TimerShoot_max;
        zPea* pea = new zPea(scene);
        pea->setGeometry(this->x() + 20, this->y() + 15 - (qrand() % 5), 80, 40);
        pea->raw = this->raw;
        scene->FlyingObjects.append(pea);
        QSound::play(":/Sounds/rc/PeaHit.wav");
    }
    else
    {
        this->TimerShoot --;
    }
}

zPeaShooter::~zPeaShooter()
{
    delete this->anim;
}



zSunFlower::zSunFlower(QWidget *parent) : zPlant(parent)
{
    this->setMovie(anim);
    anim->start();
    this->show();
    this->TimerSun_max = 500;
    this->TimerSun = qrand() % this->TimerSun_max;
    this->strength = 200;
}

void zSunFlower::act()
{
    if (this->TimerSun <= 0)
    {
        this->TimerSun = this->TimerSun_max;
        zSun* sun = new zSun(scene);
        sun->setGeometry(this->x(), this->y() + 15 - (qrand() % 5), 80, 80);
        sun->level = this->y() + 40;
        scene->Bonuses.append(sun);
        //QSound::play(":/Sounds/rc/PeaHit.wav");
    }
    else
    {
        this->TimerSun --;
    }
}

zSunFlower::~zSunFlower()
{
    delete this->anim;
}



zWallNut::zWallNut(QWidget *parent) : zPlant(parent)
{
    this->setMovie(anim);
    anim->start();
    anim_1->start();
    anim_2->start();
    this->show();
    this->strength = 1200;
}

void zWallNut::act()
{
    if ((this->strength < 800) && (this->strength >= 800))
    {
        this->setMovie(anim_1);
    }
    if (this->strength < 400)
    {
        this->setMovie(anim_2);
    }
}

zWallNut::~zWallNut()
{
    delete this->anim;
    delete this->anim_1;
    delete this->anim_2;
}



zIcePeaShooter::zIcePeaShooter(QWidget *parent) : zPlant(parent)
{
    this->setMovie(anim);
    anim->start();
    this->show();
    this->TimerShoot_max = 50;
    this->TimerShoot = this->TimerShoot_max;
    this->strength = 200;
}

void zIcePeaShooter::act()
{
    if (this->TimerShoot <= 0)
    {
        if (!(scene->hasEnemy[this->raw]))
        {
            this->TimerShoot = qrand() % 20;// not to shoot too many peas in a single timer event
            return;
        }
        this->TimerShoot = this->TimerShoot_max;
        zIcePea* pea = new zIcePea(scene);
        pea->setGeometry(this->x() + 20, this->y() + 15 - (qrand() % 5), 80, 40);
        pea->raw = this->raw;
        scene->FlyingObjects.append(pea);
        QSound::play(":/Sounds/rc/PeaHit.wav");
    }
    else
    {
        this->TimerShoot --;
    }
}

zIcePeaShooter::~zIcePeaShooter()
{
    delete this->anim;
}


