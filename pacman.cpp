#include "StdAfx.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926535897932384626433832795
 
int prev=3;
int matriz[30][30]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,1},
                    {1,8,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,8,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,0,0,1},
                    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                    {1,1,1,1,1,1,0,0,1,1,1,1,5,5,1,1,5,5,1,1,1,1,0,0,1,1,1,1,1,1},
                    {5,5,5,5,5,1,0,0,1,5,5,5,5,5,5,5,5,5,5,5,5,1,0,0,1,5,5,5,5,5},
                    {5,5,5,5,5,1,0,0,1,5,5,5,5,5,5,5,5,5,5,5,5,1,0,0,1,5,5,5,5,5},
                    {1,1,1,1,1,1,0,0,1,5,5,1,1,1,4,4,1,1,1,5,5,1,0,0,1,1,1,1,1,1},
                    {5,5,5,5,5,5,0,0,5,5,5,1,5,5,5,5,5,5,1,5,5,5,0,0,5,5,5,5,5,5},
                    {5,5,5,5,5,5,0,0,5,5,5,1,5,5,5,5,5,5,1,5,5,5,0,0,5,5,5,5,5,5},
                    {1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,5,5,1,0,0,1,1,1,1,1,1},
                    {1,1,1,1,1,1,0,0,1,5,5,5,5,5,5,5,5,5,5,5,5,1,0,0,1,1,1,1,1,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,0,0,1},
                    {1,0,0,0,0,1,0,0,1,0,0,0,0,0,6,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1},
                    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
                    {1,1,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,1,1,1},
                    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                    {1,8,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,8,0,1},
                    {1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
 
int sairam=0;
float ghostsSpeed = 150, pacmanSpeed = 150;
int keyPressed = 5;
int moveState = 1;
int started = 0;
int score = 0;
int lifes = 3;
int direction = 2;
int lightType = 0;
int camType=2;
int whiteghosts = 0;
 
 
 
void prints(char *str, void *font, float x, float y){
    glRasterPos2f(x, y);
 
    for (char* c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}
 
void drawHUD(){
     
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 30.0, 0.0, 30.0);
 
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);
 
    char str[50];
    sprintf(str, "Score: %d", score);
    prints(str, GLUT_BITMAP_9_BY_15, 0.5, 29.25);
    sprintf(str, "Lifes: %d", lifes);
    prints(str, GLUT_BITMAP_9_BY_15, 5, 29.25);
 
 
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
 
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
 
    glEnable(GL_LIGHTING);
}
 
void setMaterial(float ar, float ag, float ab, float dr, float dg, float db, float sr, float sg, float sb, float shine){
    GLfloat corAmbient[] = {ar, ag, ab, 1.0};
    GLfloat corDiffuse[] = {dr, dg, db, 1.0};
    GLfloat corSpecular[] = {sr , sg, sb, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, corAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, corDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, corSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);
}
 
class Ghost{
    private:
        int color;
 
    public:
        int saiu;
        int x, y, state;
        void draw();
        void move();
        void inicial(int, int);
        void inicialMat(int);
        void ghostsMoving();
 
};
 
 
void Ghost::draw(){
    glPushMatrix();
    glScalef(0.75f,0.75f,0.75);
     
    switch (this->color)
    {
        case 0: /* Orange */
            setMaterial(1,1,0,1,1,0,1,0,1,1);
            break;
        case 1: /* Green */
            setMaterial(0,1,0,0,1,0,1,0,1,1);
            break;
        case 2: /* Blue */
            setMaterial(0,0,1,0,0,1,0,0,1,1);
            break;
    }
 
    if(whiteghosts)
        setMaterial(1,1,1,1,1,1,1,1,1,1);
 
 
    glPushMatrix();
    glScalef(0.75f,0.75f,0.75);
    glTranslatef(0,0,-0.50);
 
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f( 0.75,-0.75, 0.0); 
    glVertex3f( 0.75,-0.75, 1.0); 
    glVertex3f( 0.75, 0.0, 0.0); 
    glVertex3f( 0.75, 0.75, 1.0); 
    glVertex3f( 0.75, 0.75, 0.0);
    glVertex3f( 0.0, 0.75, 1.0); 
    glVertex3f(-0.75, 0.75, 0.0);
    glVertex3f(-0.75, 0.75, 1.0); 
    glVertex3f(-0.75, 0.0, 0.0); 
    glVertex3f(-0.75, -0.75, 1.0); 
    glVertex3f(-0.75, -0.75, 0.0);
    glVertex3f( 0.0, -0.75, 1.0); 
    glVertex3f( 0.75,-0.75, 0.0); 
    glVertex3f( 0.75,-0.75, 1.0); 
    glEnd();
 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f( 0.0, 0.0, 2.0);
    glVertex3f( 0.75, 0.75, 1.0); 
    glVertex3f(-0.75, 0.75, 1.0); 
    glVertex3f(-0.75,-0.75, 1.0);
    glVertex3f( 0.75,-0.75, 1.0);
    glVertex3f( 0.75, 0.75, 1.0);
    glEnd();
 
    glPopMatrix();
 
    glPushMatrix();
    glScalef(0.75f,0.75f,0.75);
    glTranslatef(0,0,-0.50);
    glRotatef(22.5,0,0,1);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f( 0.75,-0.75, 0.0); 
    glVertex3f( 0.75,-0.75, 1.0); 
    glVertex3f( 0.75, 0.0, 0.0); 
    glVertex3f( 0.75, 0.75, 1.0); 
    glVertex3f( 0.75, 0.75, 0.0);
    glVertex3f( 0.0, 0.75, 1.0); 
    glVertex3f(-0.75, 0.75, 0.0);
    glVertex3f(-0.75, 0.75, 1.0); 
    glVertex3f(-0.75, 0.0, 0.0); 
    glVertex3f(-0.75, -0.75, 1.0); 
    glVertex3f(-0.75, -0.75, 0.0);
    glVertex3f( 0.0, -0.75, 1.0); 
    glVertex3f( 0.75,-0.75, 0.0); 
    glVertex3f( 0.75,-0.75, 1.0); 
    glEnd();
 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f( 0.0, 0.0, 2.0);
    glVertex3f( 0.75, 0.75, 1.0); 
    glVertex3f(-0.75, 0.75, 1.0); 
    glVertex3f(-0.75,-0.75, 1.0);
    glVertex3f( 0.75,-0.75, 1.0);
    glVertex3f( 0.75, 0.75, 1.0);
    glEnd();
 
    glPopMatrix();
 
    glPushMatrix();
    glScalef(0.75f,0.75f,0.75);
    glTranslatef(0,0,-0.50);
    glRotated(45,0,0,1);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f( 0.75,-0.75, 0.0); 
    glVertex3f( 0.75,-0.75, 1.0); 
    glVertex3f( 0.75, 0.0, 0.0); 
    glVertex3f( 0.75, 0.75, 1.0); 
    glVertex3f( 0.75, 0.75, 0.0);
    glVertex3f( 0.0, 0.75, 1.0); 
    glVertex3f(-0.75, 0.75, 0.0);
    glVertex3f(-0.75, 0.75, 1.0); 
    glVertex3f(-0.75, 0.0, 0.0); 
    glVertex3f(-0.75, -0.75, 1.0); 
    glVertex3f(-0.75, -0.75, 0.0);
    glVertex3f( 0.0, -0.75, 1.0); 
    glVertex3f( 0.75,-0.75, 0.0); 
    glVertex3f( 0.75,-0.75, 1.0); 
    glEnd();
 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f( 0.0, 0.0, 2.0);
    glVertex3f( 0.75, 0.75, 1.0); 
    glVertex3f(-0.75, 0.75, 1.0); 
    glVertex3f(-0.75,-0.75, 1.0);
    glVertex3f( 0.75,-0.75, 1.0);
    glVertex3f( 0.75, 0.75, 1.0);
    glEnd();
 
    glPopMatrix();
 
    glPushMatrix();
    glScalef(0.75f,0.75f,0.75);
    glTranslatef(0,0,-0.50);
    glRotated(65.5,0,0,1);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f( 0.75,-0.75, 0.0); 
    glVertex3f( 0.75,-0.75, 1.0); 
    glVertex3f( 0.75, 0.0, 0.0); 
    glVertex3f( 0.75, 0.75, 1.0); 
    glVertex3f( 0.75, 0.75, 0.0);
    glVertex3f( 0.0, 0.75, 1.0); 
    glVertex3f(-0.75, 0.75, 0.0);
    glVertex3f(-0.75, 0.75, 1.0); 
    glVertex3f(-0.75, 0.0, 0.0); 
    glVertex3f(-0.75, -0.75, 1.0); 
    glVertex3f(-0.75, -0.75, 0.0);
    glVertex3f( 0.0, -0.75, 1.0); 
    glVertex3f( 0.75,-0.75, 0.0); 
    glVertex3f( 0.75,-0.75, 1.0); 
    glEnd();
 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f( 0.0, 0.0, 2.0);
    glVertex3f( 0.75, 0.75, 1.0); 
    glVertex3f(-0.75, 0.75, 1.0); 
    glVertex3f(-0.75,-0.75, 1.0);
    glVertex3f( 0.75,-0.75, 1.0);
    glVertex3f( 0.75, 0.75, 1.0);
    glEnd();
 
    glPopMatrix();
     
    /*olhos*/
    glPushMatrix();
    setMaterial(1,1,1,1,1,1,0,0,1,0);
    glTranslated(0.40, 0.35, 1.0);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
 
    glPushMatrix();
    setMaterial(1,1,1,1,1,1,0,0,1,1);
    glTranslated(0.40, -0.35, 1.0);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
 
    /*iris*/
    glPushMatrix();
    setMaterial(0,0,0,0,0,0,0,0,0,0);
    glTranslated(0.60, 0.40, 1.0);
    glutSolidSphere(0.05, 16, 16);
    glPopMatrix();
 
    glPushMatrix();
    setMaterial(0,0,0,0,0,0,0,0,0,0);
    glTranslated(0.60, -0.40, 1.0);
    glutSolidSphere(0.05, 16, 16);
    glPopMatrix();
 
    glPopMatrix();
}
 
 
 
void Ghost::inicial(int x, int y){
    this->x=x;
    this->y=y;
}
 
Ghost orangeGhost; 
Ghost blueGhost; 
Ghost greenGhost;
 
class Pacman{
    private:
        int color;
 
    public:
        int x, y, angle, state;
        void draw();
        void move();
        void inicial(int, int, int, int);
 
};
 
Pacman pacman;
 
 
void drawLamp(){
        GLfloat pos[] = {pacman.x, pacman.y, 1.20f, 1};
        GLfloat dir[] = {0, 0, -0.35f};
 
        switch (direction)
        {
            case 0:
                dir[0] = -1;
                dir[1] = 0;
                break;
            case 1:
                dir[0] = 0;
                dir[1] = -1;
                break;
            case 2:
                dir[0] = 1;
                dir[1] = 0;
                break;
            case 3:
                dir[0] = 0;
                dir[1] = 1;
                break;
        }
 
    GLfloat ambientLight[] = {0.4f, 0.4f, 0.4f, 1.0f};
    GLfloat diffuseLight[] = {0.8f, 0.8f, 0.8, 1.0f};
    GLfloat specularLight[] = {0.5f, 0.5f, 0.5f, 1.0f};
 
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);
 
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30);  
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5);
    glLightfv(GL_LIGHT1, GL_POSITION, pos);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
 
 
 
}
 
void Ghost::inicialMat(int i){ 
    this->color = i;
}
 
void Pacman::draw(){
     
    glPushMatrix();
    glScalef(0.75f,0.75f,0.75);
    /*corpo*/
    glPushMatrix();
    setMaterial(1,1,0,1,1,0,1,1,0,5);
    glutSolidSphere(0.75, 16, 16);
    glPopMatrix();
 
    /*olhos*/
    glPushMatrix();
    setMaterial(1,1,1,1,1,1,0,0,1,0);
    glTranslated(0.40, 0.35, 0.5);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
 
    glPushMatrix();
    setMaterial(1,1,1,1,1,1,0,0,1,0);
    glTranslated(0.40, -0.35, 0.5);
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();
 
    /*sobrancelhas*/
    glPushMatrix();
    setMaterial(0,0,0,0,0,0,0,0,0,0);
    glTranslated(0.25, 0.29, 0.75);
    glRotated(35,0,0,1);
    glScalef(0.25f,1.0f,0.25f);
    glutSolidCube(0.4);
    glPopMatrix();
 
    glPushMatrix();
    setMaterial(0,0,0,0,0,0,0,0,0,0);
    glTranslated(0.25, -0.29, 0.75);
    glRotated(-35,0,0,1);
    glScalef(0.25f,1.0f,0.25f);
    glutSolidCube(0.4);
    glPopMatrix();
 
    /*iris*/
    glPushMatrix();
    setMaterial(0,1,0,0,1,0,0,0,0,0);
    glTranslated(0.60, 0.40, 0.5);
    glutSolidSphere(0.05, 16, 16);
    glPopMatrix();
 
    glPushMatrix();
    setMaterial(0,1,0,0,1,0,0,0,0,0);
    glTranslated(0.60, -0.40, 0.5);
    glutSolidSphere(0.05, 16, 16);
    glPopMatrix();
 
    glPopMatrix();
}
 
void Pacman::move(){
    glPushMatrix();
    glTranslated(this->x, this->y, 0.5);
    glRotated(this->angle,0,0,1);    
    this->draw();
    glPopMatrix();
 
}
 
float getGhostAngle(float gx, float gy, float px, float py){
     
    float delta_x = px - gx;
    float delta_y = py - gy;
    float theta_radians = atan2(delta_y, delta_x);
 
    return theta_radians * (180/PI);;
     
    
 
}
void Ghost::move(){
     
    float angle=getGhostAngle(this->x, this->y, pacman.x, pacman.y);
    glPushMatrix();
    glTranslated(this->x, this->y, 0.5);
    glRotatef(angle,0,0,1); 
    this->draw();
    glPopMatrix();
 
     
}
 
void Pacman::inicial(int x, int y, int ang, int s){
    this->x=x;
    this->y=y;
    this->angle=ang;
    this->state=s;
}
class Camera{
    public:
        int eyex, eyey, state;
        void setValues(int,int);
        void setState(int);
};
 
 
void Camera::setState(int s){
    state=s;
}
 
void Camera::setValues(int a, int b){
    eyex=a;
    eyey=b;
}
 
Camera cam;
 
 
 
void drawCube(int a, int b){
    glPushMatrix();
    glTranslated(a+0.5, b+0.5, 0.5);
    setMaterial(0,0,1,0,0,1,0,0,0,0);
    glutSolidCube(1);
    glPopMatrix();
}
 
void drawSmallSphere(int a, int b){
    glPushMatrix();
    setMaterial(0.24725,0.1995,0.0745,0.75164,0.60648,0.22648,0.628281,0.555802,0.366065,50);
    glTranslated(a+1, b+1, 0.5);
    glutSolidSphere (0.2, 50, 50);
    glPopMatrix();
}
 
 
void drawBigSphere(int a, int b){
    glPushMatrix();
    setMaterial(0.19125,0.0735,0.0225,0.7038,0.27048,0.0828,0.256777,0.137622,0.086014,50);
    glTranslated(a+1, b+1, 0.5);
    glutSolidSphere (0.40, 16, 16);
    glPopMatrix();
}
 
void drawGhostDoor(int a, int b){
    setMaterial(0,1.5,0,0,1.5,0,0,0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f (a, b+0.35, 0.5);
    glVertex3f (a, b+0.65, 0.5);
    glVertex3f (a+1, b+0.65, 0.5);
    glVertex3f (a+1, b+0.35, 0.5);
    glEnd();
}
 
 
void drawFloor(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    setMaterial(0,0,0,0,0,0,0,0,0,200); 
    for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                glBegin(GL_POLYGON);
                glVertex3f(i, j, -0.5f);
                glVertex3f(i + 1, j, -0.5f);
                glVertex3f(i + 1, j + 1, -0.5f);
                glVertex3f(i, j + 1, -0.5f);
 
    glEnd();
            }}
}
 
void drawMaze(){
 
    for (int a = 0; a < 30; a++)
    {
        for (int b = 0; b < 30; b++)
        {
            if (matriz[b][a]==1)        
                drawCube(a,29-b);
            else if (matriz[b][a]==4) //porta bloco dos fantasmas
                drawGhostDoor(a,29-b);
            else if(matriz[b][a]==0)
            {
                if((matriz[b+1][a+1]==0 || matriz[b+1][a+1]==8 || matriz[b+1][a+1]==6)
                && (matriz[b][a+1]==0 || matriz[b][a+1]==8 || matriz[b][a+1]==6) 
                && (matriz[b+1][a]==0 || matriz[b+1][a]==8 || matriz[b+1][a]==6))
                    drawSmallSphere(a,28-b);
            }
            else if (matriz[b][a]==8)
                if((matriz[b+1][a+1]==0 || matriz[b+1][a+1]==6) 
                && (matriz[b][a+1]==0 || matriz[b][a+1]==6) 
                && (matriz[b+1][a]==0 || matriz[b+1][a]==6))
                    drawBigSphere(a,28-b);
        }
    }
 
}
 
 
void myReshape(GLsizei w, GLsizei h) {
     
    float R=(float)w/(float)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(camType==1){
        if(R>1)
            glOrtho(0.0f*R, 30.0f*R, 0.0f, 30.0f, -10.0f, 30.0f);
        else
            glOrtho(0.0f, 30.0f, 0.0f/R, 30.0f/R, -10.0f,30.0f);
    }
    if(camType==2)
        gluPerspective(45.0f, w/h, 0.1f, 8000.00f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 
    if(camType==2)
        gluLookAt(cam.eyex,cam.eyey,3,pacman.x,pacman.y, 0.5, 0, 2, 2);
}
 
 
 
void callbackGhosts(int a){ 
    orangeGhost.ghostsMoving(); 
    blueGhost.ghostsMoving(); 
    greenGhost.ghostsMoving();
    glutPostRedisplay();
    glutTimerFunc(ghostsSpeed, callbackGhosts, 1);
}
 
void callbackt(int a){ 
    ghostsSpeed = 150;
    whiteghosts = 0; 
    glutPostRedisplay();
}
 
void eatSphere(int x, int y){
 
 
    if (matriz[29-y][x-1]==0)
    {
        matriz[29-y][x-1]=6;
        score++;
    }
    else if (matriz[29-y][x-1]==8)
    {   
        matriz[29-y][x-1]=6;
        whiteghosts = 1;
        ghostsSpeed = 250;
        glutTimerFunc(10000, callbackt, 1);
        score++;
    }
}
 
void checkGhostsCollisions(){
 
    if ((pacman.x == orangeGhost.x) &&
        (pacman.y == orangeGhost.y)){
        if (lifes>0)
            if(whiteghosts){
                orangeGhost.inicial(13,15);
            }
            else{
                lifes--;
                pacman.inicial(15,8,0,2);
            }   
    }
 
    if ((pacman.x == greenGhost.x) &&
        (pacman.y == greenGhost.y)){
        if (lifes>0)
            if(whiteghosts){
                greenGhost.inicial(17,15);
            }
            else{
                lifes--;
                pacman.inicial(15,8,0,2);
            }   
    }
 
    if ((pacman.x == blueGhost.x) &&
        (pacman.y == blueGhost.y)){
        if (lifes>0)
            if(whiteghosts){
                blueGhost.inicial(15,15);
            }
            else{
                lifes--;
                pacman.inicial(15,8,0,2);
            }           
    }
}
 
void saiFantasmas(){
 
     
    orangeGhost.inicial(13,24);
     
    greenGhost.inicial(17,24);
     
    blueGhost.inicial(15,24);
     
 
}
 
void Ghost::ghostsMoving(){
    int random;
    float angle;
    angle=getGhostAngle(this->x, this->y, pacman.x, pacman.y);
 
     
 
    if(whiteghosts==0){
        random=(rand() % 100);
        if((angle>135 && angle<=180) || (angle<-135 && angle>-180)){
            if(random>=75)
                this->state=2;
            else
                this->state=0;
        }
        else if((angle>0 && angle<=45) || (angle<0 && angle>-45)){
            if(random>=75)
                this->state=0;
            else
                this->state=2;
        }
        else if(angle>45 && angle<=135){
            if(random>=75)
                this->state=1;
            else
                this->state=3;
        }
        else if(angle<-45 && angle>-135){
            if(random>=75)
                this->state=3;
            else
                this->state=1;
        }
    }
    else{
        random=(rand() % 100);
        if((angle>135 && angle<=180) || (angle<-135 && angle>-180)){
            if(random>=75)
                this->state=0;
            else
                this->state=2;
        }
        else if((angle>0 && angle<=45) || (angle<0 && angle>-45)){
            if(random>=75)
                this->state=2;
            else
                this->state=0;
        }
        else if(angle>45 && angle<=135){
            if(random>=75)
                this->state=3;
            else
                this->state=1;
        }
        else if(angle<-45 && angle>-135){
            if(random>=75)
                this->state=1;
            else
                this->state=3;
        }
     
    }
 
    switch (this->state){
            case 0:
                if(matriz[29-this->y][this->x-2]!=1 && matriz[29-this->y+1][this->x-2]!=1)
                    this->x--;   
                break;
            case 1:
                if(matriz[29-this->y+2][this->x]!=1 && matriz[29-this->y+2][this->x-1]!=1)
                    this->y--;   
                break;
            case 2:
                if(matriz[29-this->y][this->x+1]!=1 && matriz[29-this->y+1][this->x+1]!=1)
                    this->x++;
                break;
            case 3:
                if(matriz[29-this->y-1][this->x]!=1 && matriz[29-this->y-1][this->x-1]!=1)
                    this->y++;   
                break;
        }
     
}
 
 
void PacmanMoving(){
 
    if(keyPressed!=5){
        switch(keyPressed){
            case 0:
                if(matriz[29-pacman.y][pacman.x-2]!=1 && matriz[29-pacman.y+1][pacman.x-2]!=1){ 
                    if(pacman.state==2)
                        pacman.angle+=180;
                    else if(pacman.state==1)
                        pacman.angle-=90;
                    else if(pacman.state==3)
                        pacman.angle+=90;
             
                    pacman.state=0;
                    direction=0;
                    keyPressed=5;
                    glutPostRedisplay();
                }
                break;
            case 1:
                if(matriz[29-pacman.y+2][pacman.x]!=1 && matriz[29-pacman.y+2][pacman.x-1]!=1){         
                    if(pacman.state==0) 
                        pacman.angle+=90;
                    else if(pacman.state==3)
                        pacman.angle+=180;
                    else if(pacman.state==2)
                        pacman.angle-=90;
                             
                    pacman.state=1;
                    direction=1;
                    keyPressed=5;
                    glutPostRedisplay();            
                }
                break;
            case 2:
                if(matriz[29-pacman.y][pacman.x+1]!=1 && matriz[29-pacman.y+1][pacman.x+1]!=1){         
                    if(pacman.state==0)
                        pacman.angle+=180;
                    else if(pacman.state==1)
                        pacman.angle+=90;
                    else if(pacman.state==3)
                        pacman.angle-=90;
                                     
                    pacman.state=2;
                    direction=2;
                    keyPressed=5;
                    glutPostRedisplay();
                 
                }
                break;
            case 3:
                if(matriz[29-pacman.y-1][pacman.x]!=1 && matriz[29-pacman.y-1][pacman.x-1]!=1){     
                    if(pacman.state==0) 
                        pacman.angle-=90;
                    else if(pacman.state==1)
                        pacman.angle+=180;
                    else if(pacman.state==2)
                        pacman.angle+=90;
                             
                    pacman.state=3;
                    direction=3;
                    keyPressed=5;
                    glutPostRedisplay();        
                }
                break;
        }
    }
 
    if(started){
        switch (pacman.state){
            case 0:
                if(matriz[29-pacman.y][pacman.x-2]!=1 && matriz[29-pacman.y+1][pacman.x-2]!=1){
                    pacman.x--;
                    cam.eyex--;
                    eatSphere(pacman.x,pacman.y);
                     
                }
                break;
            case 1:
                if(matriz[29-pacman.y+2][pacman.x]!=1 && matriz[29-pacman.y+2][pacman.x-1]!=1){
                    pacman.y--;
                    cam.eyey--;
                    eatSphere(pacman.x,pacman.y);
                     
                }
                break;
            case 2:
                if(matriz[29-pacman.y][pacman.x+1]!=1 && matriz[29-pacman.y+1][pacman.x+1]!=1){
                    pacman.x++;
                    cam.eyex++;
                    eatSphere(pacman.x,pacman.y);
                     
                }
                break;
            case 3:
                if(matriz[29-pacman.y-1][pacman.x]!=1 && matriz[29-pacman.y-1][pacman.x-1]!=1){
                    pacman.y+=1;
                    cam.eyey+=1;
                    eatSphere(pacman.x,pacman.y);
                     
                }
                break;
        }
    }
     
    glutPostRedisplay();
 
}
 
void callbackPacman(int a){ 
    PacmanMoving();
    glutPostRedisplay();
    glutTimerFunc(pacmanSpeed, callbackPacman, 1);
}
 
void KeyboardFunc(unsigned char key, int x, int y){
 
    switch (key){   
        case 'a': //move o pacman para a esquerda
            keyPressed=0;
            started=1;
            break;
        case 'd':   // move o pacman para a direita
            keyPressed=2;
            started=1;
            break;
        case 'w':   // move o pacman para cima
            keyPressed=3;
            started=1;
            break;
        case 's':  //move o pacman para baixo
            keyPressed=1;
            started=1;
            break;
        case '1':
            camType=1;
            myReshape(700,700);
            glutPostRedisplay();
            break;
        case '2':
            camType=2;
            myReshape(700,700);
            glutPostRedisplay();
            break;
        case '3':
            lightType = 1;
            glutPostRedisplay();
            break;
        case '4':
            lightType = 0;
            glutPostRedisplay();
            break;
        case '9':
            saiFantasmas();
            glutPostRedisplay();
            break;
    }
 
     
}
 
void myDisplay(void)
{   
    if (camType==1)
        glDisable(GL_DEPTH_TEST);
    if (camType==2){
        glClearDepth(1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glLoadIdentity();   
        gluLookAt(cam.eyex,cam.eyey,10,pacman.x,pacman.y, 0.5, 0, 0, 2);
    }   
     
 
    if (lightType == 0){ /* directional */
        glEnable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
    }
    else{ /* spotlight */
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT0);
    }
 
    drawLamp();
    drawFloor();
    drawMaze();
    pacman.move();
    orangeGhost.move();
    blueGhost.move();
    greenGhost.move();
    drawHUD();
    checkGhostsCollisions();
     
     
    glutSwapBuffers();
 
    glFlush();
}
 
 
 
void main(int argc, char** argv){
    printf("%d\n",started);
    cam.setValues(15,0);
    cam.setState(2);
    pacman.inicial(15,8,0,2);
    orangeGhost.state=2;
    orangeGhost.inicial(13,15);
    orangeGhost.inicialMat(0);
    orangeGhost.saiu=0;
    greenGhost.inicial(17,15);
    greenGhost.inicialMat(1);
    greenGhost.saiu=0;
    blueGhost.inicial(15,15);
    blueGhost.inicialMat(2);
    blueGhost.saiu=0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (700, 700);
    glutInitWindowPosition (0, 0); 
    glutCreateWindow("PacMan"); 
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(KeyboardFunc);
    glutReshapeFunc(myReshape);
    glutTimerFunc(pacmanSpeed, callbackPacman, 1);
    glutTimerFunc(ghostsSpeed, callbackGhosts, 1);
 
    //Faz-se enable as luzes depois de a janela ser criada
    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0);
 
    //Aqui vamos definir a fonte de luz LIGHT0
    float ambientLight[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    float diffuseLight[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float positionLight[] = { 0.5f, -1.0f, 0.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, positionLight);   
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);   
 
 
    glutMainLoop();
}
