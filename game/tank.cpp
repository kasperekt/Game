#include "tank.h"

Tank::Tank()
{
    id = 0;
    color[0] = 1;
    color[1] = 0;
    color[2] = 0;
    color[3] = 1;
    cannonColor[0] = 0;
    cannonColor[1] = 0;
    cannonColor[2] = 0;
    cannonColor[3] = 1;
    rotation = 0;
    xPos = 0;
    yPos = 0;
    cannonRotation = 0;
    ammo = 50;
    ableToShoot = true;
}

Tank::Tank(int i)
{
    ableToShoot = true;
    id = i;
    color[0] = 1;
    color[1] = 0;
    color[2] = 0;
    color[3] = 1;
    cannonColor[0] = 0;
    cannonColor[1] = 0;
    cannonColor[2] = 0;
    cannonColor[3] = 1;
    rotation = 0;
    cannonRotation = 0;
    xPos = 0;
    yPos = 0;
    ammo = 50;
}

Tank::Tank(int i, GLfloat x, GLfloat y, GLfloat rot)
{
    ableToShoot = true;
    id = i;
    color[0] = 1;
    color[1] = 0;
    color[2] = 0;
    color[3] = 1;
    cannonColor[0] = 0;
    cannonColor[1] = 0;
    cannonColor[2] = 0;
    cannonColor[3] = 1;
    rotation = rot;
    cannonRotation = 0;
    xPos = x;
    yPos = y;
    ammo = 50;
}

bool Tank::canShoot()
{
    return ableToShoot;
}

void Tank::canShoot(bool value)
{
    ableToShoot = value;
}

void Tank::print()
{
        glPushMatrix();
            glTranslatef(xPos,yPos,0);
            glRotatef(-rotation,0,0,1);
            glPushMatrix();
                glRotatef(-cannonRotation,0,0,1);
                glBegin(GL_POLYGON);
                glColor4fv(cannonColor);
                glVertex2d(-0.36,0.36);
                glVertex2d(0.36,0.36);
                glVertex2d(0.36,-0.36);
                glVertex2d(-0.36,-0.36);
                glEnd();
                glBegin(GL_POLYGON);
                glColor4fv(cannonColor);
                glVertex2d(-0.12, 0);
                glVertex2d(-0.12, 1.2);
                glVertex2d(0.12,1.2);
                glVertex2d(0.12,0);
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glBegin(GL_POLYGON);
                glColor4fv(color);
                glVertex2d(-0.6,0.6);
                glVertex2d(0,0.9);
                glVertex2d(0.6,0.6);
                glVertex2d(0.6,-0.6);
                glVertex2d(0.48,-0.72);
                glVertex2d(-0.48,-0.72);
                glVertex2d(-0.6,-0.6);
                glEnd();
            glPopMatrix();
        glPopMatrix();
}

GLfloat Tank::getRotation()
{
    return rotation;
}

void Tank::setRotation(GLfloat value)
{
    rotation = value;
}

void Tank::setPos(GLfloat x, GLfloat y)
{
    xPos = x;
    yPos = y;
}

void Tank::move(GLfloat speed)
{
    xPos += sin(rotation*M_PI/180)*speed;
    yPos += cos(rotation*M_PI/180)*speed;
}

void Tank::rotate(GLfloat value)
{
    rotation = (int)(rotation + value)%360;
}

GLfloat Tank::getXPos()
{
    return xPos;
}

GLfloat Tank::getYPos()
{
    return yPos;
}

GLfloat Tank::getCannonRotation()
{
    return cannonRotation;
}

void Tank::setCannonRotation(GLfloat value)
{
    cannonRotation = value;
}

void Tank::rotateCannon(GLfloat value)
{
    cannonRotation = (int)(cannonRotation + value)%360;
}

bool Tank::canMove(GLfloat speed, QList<Tank *> *tanksList, GLfloat top, GLfloat right, GLfloat bottom, GLfloat left, GLfloat offset)
{
    GLfloat radius = 1.2;
    GLfloat xCheck = xPos + sin(rotation*M_PI/180)*speed;
    GLfloat yCheck = yPos + cos(rotation*M_PI/180)*speed;
    for(int i = 0; i < tanksList->size(); ++i)
    {
        if(i != id)
        {
            GLfloat xVector = xCheck - tanksList->at(i)->getXPos();
            GLfloat yVector = yCheck - tanksList->at(i)->getYPos();
            GLfloat vector = sqrt(xVector*xVector + yVector*yVector);
            if(vector <= radius*2)
                return false;
        }
    }
    return xCheck > (left + offset) && xCheck < (right - offset) && yCheck > (bottom + offset) && yCheck < (top - offset);
}

bool Tank::hasAmmo()
{
    if(ammo > 0)
        return true;
    else
        return false;
}

void Tank::takeAmmo(int value)
{
    ammo -= value;
}

QString Tank::ammoText()
{
    return QString::number(ammo);
}
