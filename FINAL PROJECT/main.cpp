#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <GL/glut.h>
#include <math.h>
#define PI 3.14
#define X_SCALE 80.0f
#define Y_SCALE 72.727f
#define X_OFFSET -2000.0f
#define Y_OFFSET -1200.0f

#define TRANSFORM_X(x) ((x + 12) * X_SCALE + X_OFFSET)
#define TRANSFORM_Y(y) ((y + 19) * Y_SCALE + Y_OFFSET)
#include <stdlib.h>
using namespace std;
// Declare the traffic light state globally
enum TrafficLightState { RED, YELLOW, GREEN };
TrafficLightState trafficLight = RED; // Default: Red light (cars stop)

// Variables
int _carOne = 0;
int _carTwo = 0;
int _carThree = 0;
int _carFour = 0;
float _boatOne = 0.0;
float _boatTwo = 0.0;
float _boatThree = 0.0;
float _cloudOne = 0.0;
float _cloudTwo = 0.0;
float _cloudThree = 0.0;
float _plane = 0.0;
float _angle = 00.0f;
float _rain = 0.0f;
float riverFlowOffset = 0.0f;
bool isGreenLight = false; // Default: Red light (cars stop)
bool isRainyDay = false;


float moveC = 0.0f, moveB1 = 0.0f, moveB2 = 0.0f, speed = 2.5f;
bool isDay = true;
float transitionProgress = 0.0f;
float transitionSpeed = 0.03f;
float t=0;

GLint i, j, k,x=0,y=0,speed=0,alt=0,n1=1000,n2=1100,s1=0,s2=1,s3=1;
GLfloat sun_spin=0, sun_x=0, sun_y=0,reduce=10;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;

bool condition=false;
GLfloat position = 0.0f;
GLfloat _move =5.0f;
GLfloat position1 = 0.0f;
GLfloat _move1 =3.0f;
GLfloat position2 = 900.0f;
GLfloat _move2 =3.0f;



float r(int a){

return x=4,y=8;


}


float r(int a,int b){


    return x=0,y=0;

}

float motion = -1500.0f; // Start position of car
bool isNight = false;
bool isSnowing = false; // New variable to track snowfall


void drawSky(void)//  Sky   22-46425-1_001
{
    glBegin(GL_QUADS);
    if (isRainyDay) {
        glColor3ub(70, 100, 120); // Rainy sky color
    } else {
        glColor3ub(102, 190, 250); // Normal sky color
    }
    glVertex2i(0, 800);
    glVertex2i(1050, 800);
    glVertex2i(1050, 1000);
    glVertex2i(0, 1000);
    glEnd();
}


void drawSkyBottom(void) // skyBottom 22-46425-1_001
{
    glBegin(GL_QUADS);
    glColor3ub(30, 86, 49); // Maximum Green
    glVertex2i(0, 800);
    glVertex2i(1050, 750);
    glVertex2i(1050, 900);
    glVertex2i(900, 860);
    glVertex2i(860, 820);
    glVertex2i(800, 870);
    glVertex2i(700, 870);
    glVertex2i(600, 820);
    glVertex2i(0, 840);
    glEnd();
}

void drawRiver(void) //River 22-46425-1_002
{
    glBegin(GL_QUADS);
    glColor3ub(0, 191, 255);  // Clear shallow water, light blue
    glVertex2i(0, 600);
    glVertex2i(1050, 600);
    glVertex2i(1050, 800);
    glVertex2i(0, 800);
    glEnd();
}

void drawBoatOne(void) //Boat One 22-46425-1_003
{
    // Part one
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2i(50, 710);
    glVertex2i(115, 710);
    glVertex2i(130, 740);
    glVertex2i(40, 740);
    glEnd();

    // Part two
    glBegin(GL_POLYGON);
    glColor3ub(255,0, 0);
    glVertex2i(55, 740);
    glVertex2i(120, 740);
    glVertex2i(90, 750);
    glVertex2i(80, 750);
    glEnd();

    // Part three
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(50, 740);
    glVertex2i(55, 740);
    glVertex2i(55, 780);
    glVertex2i(50, 780);
    glEnd();
}

void drawBoatTwo(void)//Boat two 22-46425-1_004
{
    // Part one
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2i(850, 760);
    glVertex2i(920, 760);
    glVertex2i(930, 790);
    glVertex2i(840, 790);
    glEnd();

    // Part two
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2i(860, 790);
    glVertex2i(920, 790);
    glVertex2i(900, 800);
    glVertex2i(880, 800);
    glEnd();

    // Part three
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(850, 790);
    glVertex2i(855, 790);
    glVertex2i(855, 830);
    glVertex2i(850, 830);
    glEnd();
}
void drawBoatThree(void)//Boat Three 22-46425-1_005
{
    // Part one
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2i(850, 760);
    glVertex2i(920, 760);
    glVertex2i(930, 790);
    glVertex2i(840, 790);
    glEnd();

    // Part two
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2i(860, 790);
    glVertex2i(920, 790);
    glVertex2i(900, 800);
    glVertex2i(880, 800);
    glEnd();

    // Part three
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(850, 790);
    glVertex2i(855, 790);
    glVertex2i(855, 830);
    glVertex2i(850, 830);
    glEnd();
}

void drawGrass(void)//Grass 22-46425-1_006
{
    glBegin(GL_QUADS);
    glColor3ub(107, 142, 35); // Olive Drab color
    glVertex2i(0, 220);
    glVertex2i(1050, 220);
    glVertex2i(1050, 600);
    glVertex2i(0, 600);
    glEnd();
}

void drawLandShades(void)// Landshades 22-46425-1_006
{
    //land shade 1
    glBegin(GL_POLYGON);
    glColor3ub(107, 142, 35); // Olive Drab color
    glVertex2i(1050, 220);
    glVertex2i(1050, 320);
    glVertex2i(690, 220);
    glEnd();

    // land shade2
    glBegin(GL_POLYGON);
    glColor3ub(107, 142, 35); // Olive Drab color
    glVertex2i(1050, 330);
    glVertex2i(0, 300);
    glVertex2i(0, 650);
    glVertex2i(1050, 380);
    glEnd();

    //land shade 3
    glBegin(GL_POLYGON);
    glColor3ub(107, 142, 35); // Olive Drab color
    glVertex2i(1050, 620);
    glVertex2i(1050, 500);
    glVertex2i(500, 490);
    glVertex2i(500, 400);
    glEnd();
}

void drawRoads(void)// Road 22-46425-1_007
{
    //Road 1
    glBegin(GL_QUADS);
    glColor3ub(96, 106, 116); // Ash
    glVertex2i(0, 10);
    glVertex2i(1050, 10);
    glVertex2i(1050, 200);
    glVertex2i(0, 200);
    glEnd();

    //Road 2
    glBegin(GL_POLYGON);
    glColor3ub(96, 78, 56);
    glVertex2i(520, 200);
    glVertex2i(690, 200);
    glVertex2i(480, 600);
    glVertex2i(370, 600);
    glEnd();

    //Road 3
    glBegin(GL_POLYGON);
    glColor3ub(96, 78, 56);
    glVertex2i(0, 600);
    glVertex2i(500, 530);
    glVertex2i(480, 605);
    glVertex2i(0, 630);
    glEnd();

   // Bottom White Border (Extending Downward)
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White Line
    glVertex2i(0, 0);
    glVertex2i(1050, 0);
    glVertex2i(1050, 15);
    glVertex2i(0, 15);
    glEnd();

    // Top White Border (Moderate Increase in Height)
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White Line
    glVertex2i(0, 180);
    glVertex2i(1050, 180);
    glVertex2i(1050, 220);  // Increased moderately
    glVertex2i(0, 220);
    glEnd();
}

void drawRoadSigns(void)// RoadSign 22-46425-1_007
{
    //sign 1
    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(255, 255, 255); // White
    glVertex2i(50, 100);
    glVertex2i(200, 100);
    glVertex2i(200, 110);
    glVertex2i(50, 110);
    glEnd();

    //sign 2
    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(255, 255, 255); // white
    glVertex2i(250, 100);
    glVertex2i(400, 100);
    glVertex2i(400, 110);
    glVertex2i(250, 110);
    glEnd();

    //sign 3
    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(255, 255, 255); // white
    glVertex2i(450, 100);
    glVertex2i(600, 100);
    glVertex2i(600, 110);
    glVertex2i(450, 110);
    glEnd();

    //sign 4
    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(255, 255, 255); // white
    glVertex2i(650, 100);
    glVertex2i(800, 100);
    glVertex2i(800, 110);
    glVertex2i(650, 110);
    glEnd();

    //sign 5
    glBegin(GL_QUADS);         // Each set of 4 vertices form a quad
    glColor3ub(255, 255, 255); // white
    glVertex2i(850, 100);
    glVertex2i(990, 100);
    glVertex2i(990, 110);
    glVertex2i(850, 110);
    glEnd();
}


void drawCarOne(void)//Car one 22-46425-1_008
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);
    glVertex2i(795, 50);
    glVertex2i(885, 50);
    glVertex2i(890, 80);
    glVertex2i(800, 80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2i(800, 80);
    glVertex2i(875, 80);
    glVertex2i(850, 110);
    glVertex2i(800, 110);

    glEnd();

    //wheel 1
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 815;
        float y = r * sin(A) + 50;
        glVertex2f(x, y);
    }

    glEnd();

    //wheel 2
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 865;
        float y = r * sin(A) + 50;
        glVertex2f(x, y);
    }

    glEnd();
}

void drawCarTwo(void)//Car Two 22-46425-1_009
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2i(95, 50);
    glVertex2i(185, 50);
    glVertex2i(180, 80);
    glVertex2i(100, 80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2i(100, 80);
    glVertex2i(170, 80);
    glVertex2i(150, 110);
    glVertex2i(110, 110);

    glEnd();
    // wheel 1
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 115;
        float y = r * sin(A) + 50;
        glVertex2f(x, y);
    }

    glEnd();
    //wheel 2
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 165;
        float y = r * sin(A) + 50;
        glVertex2f(x, y);
    }

    glEnd();
}

void drawCarThree(void)//Car Three 22-46425-1_010
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);
    glVertex2i(475, 150);
    glVertex2i(600, 150);
    glVertex2i(600, 180);
    glVertex2i(490, 180);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 255);
    glVertex2i(500, 180);
    glVertex2i(580, 180);
    glVertex2i(570, 210);
    glVertex2i(510, 210);

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 505;
        float y = r * sin(A) + 150;
        glVertex2f(x, y);
    }

    glEnd();
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 570;
        float y = r * sin(A) + 150;
        glVertex2f(x, y);
    }

    glEnd();
}
void drawCarFour(void)//Car Four 22-46425-1_011
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);
    glVertex2i(475, 150);
    glVertex2i(600, 150);
    glVertex2i(590, 180);
    glVertex2i(490, 180);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2i(500, 180);
    glVertex2i(580, 180);
    glVertex2i(570, 210);
    glVertex2i(510, 210);

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 505;
        float y = r * sin(A) + 150;
        glVertex2f(x, y);
    }

    glEnd();
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(1.0, 0, 1.0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + 570;
        float y = r * sin(A) + 150;
        glVertex2f(x, y);
    }

    glEnd();
}


void drawBuildings(void)//Buildings 22-46425-1_014
{
    // Left side building (Adjusted to avoid road overlap)
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex2i(50, 200);
    glVertex2i(250, 200);
    glVertex2i(250, 600);
    glVertex2i(50, 600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 153, 255); // Windows
    for (int x = 70; x < 250; x += 50) {
        for (int y = 220; y < 580; y += 80) {
            glVertex2i(x, y);
            glVertex2i(x + 30, y);
            glVertex2i(x + 30, y + 40);
            glVertex2i(x, y + 40);
        }
    }
    glEnd();

    // Middle building (Newly added between left and right buildings)
    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex2i(425, 200);
    glVertex2i(625, 200);
    glVertex2i(625, 600);
    glVertex2i(425, 600);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3ub(0, 0, 0); // Windows
    glColor3ub(0, 204, 204);
    for (int x = 445; x < 625; x += 50) {
        for (int y = 220; y < 580; y += 80) {
            glVertex2i(x, y);
            glVertex2i(x + 30, y);
            glVertex2i(x + 30, y + 40);
            glVertex2i(x, y + 40);
        }
    }
    glEnd();

    // Right side building (Adjusted to avoid road overlap)
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex2i(800, 200);
    glVertex2i(1000, 200);
    glVertex2i(1000, 600);
    glVertex2i(800, 600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
    for (int x = 820; x < 1000; x += 50) {
        for (int y = 220; y < 580; y += 80) {
            glVertex2i(x, y);
            glVertex2i(x + 30, y);
            glVertex2i(x + 30, y + 40);
            glVertex2i(x, y + 40);
        }
    }
    glEnd();
}



void drawCloudOne(void)// Cloud 22-46425-1_012
{
    //cloud 1
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(241, 241, 241);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 30.85;
        float x = r * cos(A) + 350;
        float y = r * sin(A) + 920;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(240, 240, 240);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 30.85;
        float x = r * cos(A) + 320;
        float y = r * sin(A) + 900;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(240, 240, 240);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 30.85;
        float x = r * cos(A) + 380;
        float y = r * sin(A) + 880;
        glVertex2f(x, y);
    }

    glEnd();
}

void drawCloudTwo(void)//Cloud 22-46425-1_012
{
    //cloud 2
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(240, 240, 240);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 38.85;
        float x = r * cos(A) + 70;
        float y = r * sin(A) + 950;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(240, 240, 240);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 38.85;
        float x = r * cos(A) + 30;
        float y = r * sin(A) + 925;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(240, 240, 240);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 38.85;
        float x = r * cos(A) + 100;
        float y = r * sin(A) + 910;
        glVertex2f(x, y);
    }

    glEnd();
}

void drawCloudThree(void)//Cloud 22-46425-1_012
{
    //cloud 3
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(220, 249, 249);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 35.85;
        float x = r * cos(A) + 790;
        float y = r * sin(A) + 950;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(220, 249, 249);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 28.85;
        float x = r * cos(A) + 760;
        float y = r * sin(A) + 930;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(220, 249, 249);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 27.85;
        float x = r * cos(A) + 835;
        float y = r * sin(A) + 970;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(220, 249, 249);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 27.85;
        float x = r * cos(A) + 835;
        float y = r * sin(A) + 940;
        glVertex2f(x, y);
    }

    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(220, 249, 249);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 25.85;
        float x = r * cos(A) + 865;
        float y = r * sin(A) + 945;
        glVertex2f(x, y);
    }

    glEnd();
}

void drawSun(void)//Sun 22-46425-1_012
{
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(240, 250, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 30.85;
        float x = r * cos(A) + 250;
        float y = r * sin(A) + 860;
        glVertex2f(x, y);
    }

    glEnd();
}

void drawSignals(void)//Traffic Light 22-46425-1_015
{
    // Position the signal beside the left building
    int signalX = 350; // X-coordinate (right side of the left building)
    int signalY = 200; // Y-coordinate (base of the signal)

    // Signal Post
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Black color for the post
    glVertex2i(signalX + 10, signalY + 220); // Top right
    glVertex2i(signalX, signalY + 220);      // Top left
    glVertex2i(signalX, signalY);            // Bottom left
    glVertex2i(signalX + 10, signalY);       // Bottom right
    glEnd();

    // Signal Box
    glBegin(GL_QUADS);
    glColor3ub(172, 172, 172); // Light gray color for the box
    glVertex2i(signalX + 15, signalY + 220); // Top right
    glVertex2i(signalX - 10, signalY + 220); // Top left
    glVertex2i(signalX - 10, signalY + 140); // Bottom left
    glVertex2i(signalX + 15, signalY + 140); // Bottom right
    glEnd();

    float pi = 3.1416;

    // **Red Light**
    glBegin(GL_POLYGON);
    if (trafficLight == RED) {
        glColor3ub(255, 0, 0); // RED ON
    } else {
        glColor3ub(100, 100, 100); // Gray (OFF)
    }
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + signalX + 2; // Center X
        float y = r * sin(A) + signalY + 205; // Center Y (Red light position)
        glVertex2f(x, y);
    }
    glEnd();

    // **Yellow Light**
    glBegin(GL_POLYGON);
    if (trafficLight == YELLOW) {
        glColor3ub(255, 255, 0); // YELLOW ON
    } else {
        glColor3ub(100, 100, 100); // Gray (OFF)
    }
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + signalX + 2; // Center X
        float y = r * sin(A) + signalY + 180; // Center Y (Yellow light position)
        glVertex2f(x, y);
    }
    glEnd();

    // **Green Light**
    glBegin(GL_POLYGON);
    if (trafficLight == GREEN) {
        glColor3ub(0, 255, 0); // GREEN ON
    } else {
        glColor3ub(100, 100, 100); // Gray (OFF)
    }
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 10.85;
        float x = r * cos(A) + signalX + 2; // Center X
        float y = r * sin(A) + signalY + 155; // Center Y (Green light position)
        glVertex2f(x, y);
    }
    glEnd();
}


void drawBenchextra(void)// Brench 22-46425-1_016
{
    int xOffset = -30; // Move left
    int yOffset = 100;  // Move up

    // bench (part 1)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(780 + xOffset, 425 + yOffset);
    glVertex2i(775 + xOffset, 425 + yOffset);
    glVertex2i(775 + xOffset, 388 + yOffset);
    glVertex2i(780 + xOffset, 388 + yOffset);
    glEnd();

    // bench (part 2)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(700 + xOffset, 425 + yOffset);
    glVertex2i(705 + xOffset, 425 + yOffset);
    glVertex2i(705 + xOffset, 388 + yOffset);
    glVertex2i(700 + xOffset, 388 + yOffset);
    glEnd();

    // bench (part 3)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 420 + yOffset);
    glVertex2i(680 + xOffset, 420 + yOffset);
    glVertex2i(680 + xOffset, 413 + yOffset);
    glVertex2i(800 + xOffset, 413 + yOffset);
    glEnd();

    // bench (part 4)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 410 + yOffset);
    glVertex2i(680 + xOffset, 410 + yOffset);
    glVertex2i(680 + xOffset, 403 + yOffset);
    glVertex2i(800 + xOffset, 403 + yOffset);
    glEnd();

    // bench (part 5)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 400 + yOffset);
    glVertex2i(680 + xOffset, 400 + yOffset);
    glVertex2i(680 + xOffset, 393 + yOffset);
    glVertex2i(800 + xOffset, 393 + yOffset);
    glEnd();

    // bench (part 6)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 388 + yOffset);
    glVertex2i(680 + xOffset, 388 + yOffset);
    glVertex2i(670 + xOffset, 368 + yOffset);
    glVertex2i(810 + xOffset, 368 + yOffset);
    glVertex2i(670 + xOffset, 368 + yOffset);
    glVertex2i(810 + xOffset, 368 + yOffset);
    glVertex2i(810 + xOffset, 360 + yOffset);
    glVertex2i(670 + xOffset, 360 + yOffset);
    glEnd();

    // bench (part 7)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(680 + xOffset, 360 + yOffset);
    glVertex2i(685 + xOffset, 360 + yOffset);
    glVertex2i(687 + xOffset, 330 + yOffset);
    glVertex2i(680 + xOffset, 330 + yOffset);
    glEnd();

    // bench (part 8)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(690 + xOffset, 360 + yOffset);
    glVertex2i(695 + xOffset, 360 + yOffset);
    glVertex2i(697 + xOffset, 340 + yOffset);
    glVertex2i(690 + xOffset, 340 + yOffset);
    glEnd();

    // bench (part 9)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 360 + yOffset);
    glVertex2i(795 + xOffset, 360 + yOffset);
    glVertex2i(795 + xOffset, 330 + yOffset);
    glVertex2i(802 + xOffset, 330 + yOffset);
    glEnd();

    // bench (part 10)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(790 + xOffset, 360 + yOffset);
    glVertex2i(785 + xOffset, 360 + yOffset);
    glVertex2i(785 + xOffset, 340 + yOffset);
    glVertex2i(792 + xOffset, 340 + yOffset);
    glEnd();
}
void drawBench(void)// Brench 22-46425-1_016
{
    int xOffset = -410; // Move left
    int yOffset = 100;  // Move up

    // bench (part 1)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(780 + xOffset, 425 + yOffset);
    glVertex2i(775 + xOffset, 425 + yOffset);
    glVertex2i(775 + xOffset, 388 + yOffset);
    glVertex2i(780 + xOffset, 388 + yOffset);
    glEnd();

    // bench (part 2)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(700 + xOffset, 425 + yOffset);
    glVertex2i(705 + xOffset, 425 + yOffset);
    glVertex2i(705 + xOffset, 388 + yOffset);
    glVertex2i(700 + xOffset, 388 + yOffset);
    glEnd();

    // bench (part 3)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 420 + yOffset);
    glVertex2i(680 + xOffset, 420 + yOffset);
    glVertex2i(680 + xOffset, 413 + yOffset);
    glVertex2i(800 + xOffset, 413 + yOffset);
    glEnd();

    // bench (part 4)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 410 + yOffset);
    glVertex2i(680 + xOffset, 410 + yOffset);
    glVertex2i(680 + xOffset, 403 + yOffset);
    glVertex2i(800 + xOffset, 403 + yOffset);
    glEnd();

    // bench (part 5)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 400 + yOffset);
    glVertex2i(680 + xOffset, 400 + yOffset);
    glVertex2i(680 + xOffset, 393 + yOffset);
    glVertex2i(800 + xOffset, 393 + yOffset);
    glEnd();

    // bench (part 6)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 388 + yOffset);
    glVertex2i(680 + xOffset, 388 + yOffset);
    glVertex2i(670 + xOffset, 368 + yOffset);
    glVertex2i(810 + xOffset, 368 + yOffset);
    glVertex2i(670 + xOffset, 368 + yOffset);
    glVertex2i(810 + xOffset, 368 + yOffset);
    glVertex2i(810 + xOffset, 360 + yOffset);
    glVertex2i(670 + xOffset, 360 + yOffset);
    glEnd();

    // bench (part 7)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(680 + xOffset, 360 + yOffset);
    glVertex2i(685 + xOffset, 360 + yOffset);
    glVertex2i(687 + xOffset, 330 + yOffset);
    glVertex2i(680 + xOffset, 330 + yOffset);
    glEnd();

    // bench (part 8)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(690 + xOffset, 360 + yOffset);
    glVertex2i(695 + xOffset, 360 + yOffset);
    glVertex2i(697 + xOffset, 340 + yOffset);
    glVertex2i(690 + xOffset, 340 + yOffset);
    glEnd();

    // bench (part 9)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(800 + xOffset, 360 + yOffset);
    glVertex2i(795 + xOffset, 360 + yOffset);
    glVertex2i(795 + xOffset, 330 + yOffset);
    glVertex2i(802 + xOffset, 330 + yOffset);
    glEnd();

    // bench (part 10)
    glBegin(GL_QUADS);
    glColor3ub(150, 70, 0);
    glVertex2i(790 + xOffset, 360 + yOffset);
    glVertex2i(785 + xOffset, 360 + yOffset);
    glVertex2i(785 + xOffset, 340 + yOffset);
    glVertex2i(792 + xOffset, 340 + yOffset);
    glEnd();
}

void drawWindmillTop(void)// Windmill 22-46425-1_017
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2i(0, 0);
    glVertex2i(30, 15);
    glVertex2i(5, -2);
    glVertex2i(0, 0);
    glVertex2i(-25, 15);
    glVertex2i(5, -8);
    glVertex2i(0, 0);
    glVertex2i(10, -30);
    glVertex2i(5, 0);
    glEnd();
}

void drawWindmillOne(void)// Windmill 22-46425-1_017
{
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(490, 910);
    glVertex2i(485, 910);
    glVertex2i(485, 830);
    glVertex2i(490, 830);
    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(0, 153, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 5.0;
        float x = r * cos(A) + 488;
        float y = r * sin(A) + 910;
        glVertex2f(x, y);
    }
    glEnd();
}

void drawWindmillTwo(void)// Windmill 22-46425-1_017
{
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(575, 910);
    glVertex2i(580, 910);
    glVertex2i(580, 835);
    glVertex2i(575, 835);
    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(0, 153, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 4.80;
        float x = r * cos(A) + 577;
        float y = r * sin(A) + 910;
        glVertex2f(x, y);
    }
    glEnd();
}

void drawWindmillThree(void)// Windmill 22-46425-1_017
{
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(650, 910);
    glVertex2i(655, 910);
    glVertex2i(655, 845);
    glVertex2i(650, 841);
    glEnd();

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(0, 153, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 5.0;
        float x = r * cos(A) + 653;
        float y = r * sin(A) + 910;
        glVertex2f(x, y);
    }
    glEnd();
}

void drawPlane(void)// Plane 22-46425-1_013
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2i(40, 965);
    glVertex2i(90, 970);
    glVertex2i(90, 955);
    glVertex2i(20, 955);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,0);
    glVertex2i(90, 970);
    glVertex2i(90, 955);
    glVertex2i(100, 960);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 200);
    glVertex2i(45, 959);
    glVertex2i(60, 959);
    glVertex2i(15, 935);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 200);
    glVertex2i(70, 963);
    glVertex2i(55, 963);
    glVertex2i(45, 990);
    glEnd();

    glBegin(GL_QUADS); // Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 200);
    glVertex2i(20, 957);
    glVertex2i(30, 959);
    glVertex2i(25, 980);
    glVertex2i(20, 980);
    glEnd();
}

void drawZebracrossing(void)
{
    glBegin(GL_QUADS); // Draw a Red 1x1 Square centered at origin
    glColor3ub(255, 255, 255);
    glVertex2i(40, 10);
    glVertex2i(100, 10);
    glVertex2i(85, 200);
    glVertex2i(55, 200);
    glEnd();

    glBegin(GL_QUADS); // Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2i(45, 30);
    glVertex2i(95, 15);
    glVertex2i(93, 35);
    glVertex2i(47, 50);
    glEnd();

    glBegin(GL_QUADS); // Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2i(47, 65);
    glVertex2i(93, 50);
    glVertex2i(91, 70);
    glVertex2i(49, 85);
    glEnd();

    glBegin(GL_QUADS); // Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2i(50, 100);
    glVertex2i(91, 85);
    glVertex2i(89, 105);
    glVertex2i(52, 120);
    glEnd();

    glBegin(GL_QUADS); // Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2i(54, 135);
    glVertex2i(89, 120);
    glVertex2i(87, 140);
    glVertex2i(55, 155);
    glEnd();

    glBegin(GL_QUADS); // Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2i(56, 170);
    glVertex2i(87, 155);
    glVertex2i(85, 175);
    glVertex2i(57, 190);
    glEnd();
}


void drawTree(int x, int y)//Trees 22-46425-1_018
{
    // Tree trunk
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19); // Brown
    glVertex2i(x - 10, y);
    glVertex2i(x + 10, y);
    glVertex2i(x + 10, y + 100);
    glVertex2i(x - 10, y + 100);
    glEnd();

    // Tree leaves
    glBegin(GL_TRIANGLES);
    glColor3ub(34, 139, 34); // Green
    glVertex2i(x - 30, y + 40);
    glVertex2i(x + 30, y + 40);
    glVertex2i(x, y + 110);
    glEnd();

    glBegin(GL_TRIANGLES);
    //glColor3ub(34, 139, 34);
    glColor3ub(60, 179, 113);
    glVertex2i(x - 30, y + 80);
    glVertex2i(x + 30, y + 80);
    glVertex2i(x, y + 200);
    glEnd();
}

bool isOverlappingBuildingOrSignal(int x, int y) {
    // Ensure trees do not overlap buildings or signals
    return (x > 40 && x < 250 && y > 200 && y < 600) ||  // Left building
           (x > 420 && x < 630 && y > 200 && y < 600) || // Middle building
           (x > 800 && x < 1000 && y > 200 && y < 600) || // Right building
           (x > 250 && x < 280 && y > 180 && y < 250);   // Signal area
}

void drawTrees() {
    // Adding trees beside buildings without overlapping them or signals
    int treePositions[][2] = {
        {40, 220}, {280, 220}, {640, 220}, {780, 220}, {1020, 220}
    };

    for (int i = 0; i < 5; i++) {
        int x = treePositions[i][0];
        int y = treePositions[i][1];
        if (!isOverlappingBuildingOrSignal(x, y)) {
            drawTree(x, y);
        }
    }
}

void drawRain(int value)//Rain 22-46425-1_020
{                        // rain Effect 22-46425-1_002

    if (isRainyDay)
    {
        _rain += 0.01f;

        glBegin(GL_POINTS);
        for (int i = 1; i <= 1050; i++)
        {
            int x = rand();
            int y = rand();
            x %= 1050;
            y %= 1050;
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(x, y);
            glVertex2d(x + 5, y + 20);
            glEnd();
        }
        glEnd();
    }
}
// Function to draw river with tide and flow animation
void drawRiverWithTideAndFlow(float flowOffset)// River Animation 22-46425-1_003
 {
    float waveHeight = sin(_rain * 10) * 10; // Creates wave-like motion
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex2i(0 + flowOffset, 600 + waveHeight);
    glVertex2i(1050 + flowOffset, 600 + waveHeight);
    glVertex2i(1050 + flowOffset, 800 + waveHeight);
    glVertex2i(0 + flowOffset, 800 + waveHeight);
    glEnd();
}

void drawFence()//Fence 22-46425-1_019
 {
    int startX = 0, endX = 1050, y = 600; // Fence along the river

    // Draw vertical fence posts
    for (int i = startX; i <= endX; i += 40) {
        glBegin(GL_QUADS);
        glColor3ub(139, 69, 19); // Brown color
        glVertex2i(i, y);
        glVertex2i(i + 10, y);
        glVertex2i(i + 10, y + 50);
        glVertex2i(i, y + 50);
        glEnd();
    }

    // Draw horizontal planks
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45); // Darker brown
    glVertex2i(startX, y + 30);
    glVertex2i(endX, y + 30);
    glVertex2i(endX, y + 35);
    glVertex2i(startX, y + 35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex2i(startX, y + 10);
    glVertex2i(endX, y + 10);
    glVertex2i(endX, y + 15);
    glVertex2i(startX, y + 15);
    glEnd();
}


void DrawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1415926f * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void updateTransition(int value) {
    float target = isDay ? 0.0f : 1.0f;
    if (fabs(transitionProgress - target) > 0.001f) {  // Ensures gradual transition
        transitionProgress += (target - transitionProgress) * transitionSpeed;
        glutPostRedisplay();
        glutTimerFunc(16, updateTransition, 0);
    } else {
        transitionProgress = target;  // Ensures exact match with target
    }
}


//Interpolation (scene transitions)
GLubyte lerpColor(GLubyte day, GLubyte night, float t) {
    return day + t * (night - day);
}

void interpolateColor3ub(GLubyte dayR, GLubyte dayG, GLubyte dayB,
                         GLubyte nightR, GLubyte nightG, GLubyte nightB,
                         float t) {
    glColor3ub(lerpColor(dayR, nightR, t),
               lerpColor(dayG, nightG, t),
               lerpColor(dayB, nightB, t));
}


void DrawAllComponents() {

    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glLoadIdentity();

    float skyR = 115 - (90 * transitionProgress);
    float skyG = 160 - (125 * transitionProgress);
    float skyB = 228 - (173 * transitionProgress);

    glClearColor(skyR / 255.0f, skyG / 255.0f, skyB / 255.0f, 1.0f);


    // Sky 21-45465-3 (01)
    glBegin(GL_POLYGON);
    interpolateColor3ub(115, 160, 228,   // Day sky
                        25, 30, 50,      // Night sky
                        t);
    //glColor3ub(115, 160, 228);  // Daytime sky blue

    glVertex2f(TRANSFORM_X(38.0f), TRANSFORM_Y(3.0f));
    glVertex2f(TRANSFORM_X(38.0f), TRANSFORM_Y(14.0f));
    glVertex2f(TRANSFORM_X(-12.0f), TRANSFORM_Y(14.0f));
    glVertex2f(TRANSFORM_X(-12.0f), TRANSFORM_Y(3.0f));
    glEnd();

    // Sun/Moon transition 21-45465-3 (02)
    float sunY = 10.0f;
    glPushMatrix();
    glTranslatef(TRANSFORM_X(30.0), TRANSFORM_Y(sunY), 0);

    interpolateColor3ub(250, 200, 0,   // Day sun
                        255, 255, 255,   // Night moon
                        transitionProgress);
    DrawCircle(0, 0, 120.0f);
    glPopMatrix();


    // Clouds 21-45465-3 (03)

    glPushMatrix();
    glTranslatef(moveC, 0.0f, 0.0f);
//    glColor3ub(255, 255, 255);
    interpolateColor3ub(255, 255, 255,   // Day clouds
                        150, 150, 200,   // Night clouds
                        transitionProgress);

    DrawCircle(TRANSFORM_X(1.0), TRANSFORM_Y(10.0), 100.0f);
    DrawCircle(TRANSFORM_X(2.0), TRANSFORM_Y(10.5), 80.0f);
    DrawCircle(TRANSFORM_X(0.0), TRANSFORM_Y(10.5), 80.0f);
    DrawCircle(TRANSFORM_X(3.0), TRANSFORM_Y(9.5), 90.0f);
    DrawCircle(TRANSFORM_X(-1.0), TRANSFORM_Y(9.5), 90.0f);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(moveC, 0.0f, 0.0f);
//    glColor3ub(255, 255, 255);
    interpolateColor3ub(255, 255, 255,   // Day clouds
                        150, 150, 200,   // Night clouds
                        transitionProgress);

    DrawCircle(TRANSFORM_X(10.0), TRANSFORM_Y(11.0), 100.0f);
    DrawCircle(TRANSFORM_X(11.0), TRANSFORM_Y(11.5), 80.0f);
    DrawCircle(TRANSFORM_X(9.0), TRANSFORM_Y(11.5), 80.0f);
    DrawCircle(TRANSFORM_X(12.0), TRANSFORM_Y(10.5), 90.0f);

    glPopMatrix();


    // Sea 21-45465-3 (04)
    glBegin(GL_POLYGON);
//    glColor3ub(65, 105, 225);  // Daytime sea blue
    interpolateColor3ub(65, 105, 225,    // Day sea
                        20, 30, 50,      // Night sea
                        transitionProgress);

    glVertex2f(TRANSFORM_X(38.0f), TRANSFORM_Y(-19.0f));
    glVertex2f(TRANSFORM_X(38.0f), TRANSFORM_Y(-10.0f));
    glVertex2f(TRANSFORM_X(-12.0f), TRANSFORM_Y(-7.0f));
    glVertex2f(TRANSFORM_X(-12.0f), TRANSFORM_Y(-19.0f));
    glEnd();

    // Ground 21-45465-3 (05)
    glBegin(GL_POLYGON);
//    glColor3ub(25, 128, 0);  // Daytime ground green
    interpolateColor3ub(25, 128, 0,      // Day ground
                        10, 30, 5,       // Night ground
                        transitionProgress);

    glVertex2f(TRANSFORM_X(1.0f), TRANSFORM_Y(-8.0f));
    glVertex2f(TRANSFORM_X(38.0f), TRANSFORM_Y(-12.0f));
    glVertex2f(TRANSFORM_X(38.0f), TRANSFORM_Y(3.0f));
    glVertex2f(TRANSFORM_X(-12.0f), TRANSFORM_Y(3.0f));
    glVertex2f(TRANSFORM_X(-12.0f), TRANSFORM_Y(-11.0f));
    glEnd();


    // Road 21-45465-3 (06)
    glBegin(GL_POLYGON);
    glColor3ub(72,72,76);  // Original color preserved

    glVertex2f(TRANSFORM_X(6.0f), TRANSFORM_Y(-8.6f));  // (-560, -443.64)
    glVertex2f(TRANSFORM_X(6.0f), TRANSFORM_Y(3.0f));    // (-560, 400)
    glVertex2f(TRANSFORM_X(5.2f), TRANSFORM_Y(3.0f));    // (-624, 400)
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-8.2f));   // (-880, -414.55)

    glEnd();

    // Road divider 21-45465-3 (07)
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);  // White color maintained

    glVertex2f(TRANSFORM_X(4.2f), TRANSFORM_Y(-8.5f));
    glVertex2f(TRANSFORM_X(5.6f), TRANSFORM_Y(3.0f));
    glVertex2f(TRANSFORM_X(5.5f), TRANSFORM_Y(3.0f));
    glVertex2f(TRANSFORM_X(4.0f), TRANSFORM_Y(-8.4f));

    glEnd();


    // Left side house 1/// 21-45465-3 (08)

    // roof
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);  // Standard brown
    glVertex2f(TRANSFORM_X(-2.7f), TRANSFORM_Y(1.2f));
    glVertex2f(TRANSFORM_X(-6.7f), TRANSFORM_Y(1.2f));
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-1.0f));
    glVertex2f(TRANSFORM_X(-1.0f), TRANSFORM_Y(-1.0f));
    glEnd();

    // roof side
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(TRANSFORM_X(-6.5f), TRANSFORM_Y(1.0f));
    glVertex2f(TRANSFORM_X(-6.7f), TRANSFORM_Y(1.2f));
    glVertex2f(TRANSFORM_X(-8.5f), TRANSFORM_Y(-1.0f));
    glVertex2f(TRANSFORM_X(-8.0f), TRANSFORM_Y(-1.0f));
    glEnd();

    // Left side house left wall
    glBegin(GL_POLYGON);
    glColor3ub(205,133,63);
    glVertex2f(TRANSFORM_X(-6.5f), TRANSFORM_Y(1.0f));
    glVertex2f(TRANSFORM_X(-8.0f), TRANSFORM_Y(-1.0f));
    glVertex2f(TRANSFORM_X(-8.0f), TRANSFORM_Y(-2.5f));
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-3.0f));
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-1.0f));
    glEnd();

    // Left side house left wall- window
    glBegin(GL_POLYGON);
    glColor3ub(128,135,32);
    glVertex2f(TRANSFORM_X(-6.0f), TRANSFORM_Y(-2.0f));
    glVertex2f(TRANSFORM_X(-6.0f), TRANSFORM_Y(-1.0f));
    glVertex2f(TRANSFORM_X(-7.0f), TRANSFORM_Y(-1.0f));
    glVertex2f(TRANSFORM_X(-7.0f), TRANSFORM_Y(-2.0f));
    glEnd();

    // Left side house left base
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-3.0f));
    glVertex2f(TRANSFORM_X(-8.0f), TRANSFORM_Y(-2.5f));
    glVertex2f(TRANSFORM_X(-8.3f), TRANSFORM_Y(-2.9f));
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-3.5f));
    glEnd();

    // Left side house main(right) wall
    glBegin(GL_POLYGON);
    glColor3ub(184,134,11);
    glVertex2f(TRANSFORM_X(-1.5f), TRANSFORM_Y(-3.0f));
    glVertex2f(TRANSFORM_X(-1.5f), TRANSFORM_Y(-1.0f));
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-1.0f));
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-3.0f));
    glEnd();

    // Left side house right base
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-3.0f));
    glVertex2f(TRANSFORM_X(-5.0f), TRANSFORM_Y(-3.5f));
    glVertex2f(TRANSFORM_X(-1.0f), TRANSFORM_Y(-3.5f));
    glVertex2f(TRANSFORM_X(-1.5f), TRANSFORM_Y(-3.0f));
    glEnd();

    // Door

    // Main door
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(-2.5f), TRANSFORM_Y(-3.0f));
    glVertex2f(TRANSFORM_X(-2.5f), TRANSFORM_Y(-1.2f));
    glVertex2f(TRANSFORM_X(-4.0f), TRANSFORM_Y(-1.2f));
    glVertex2f(TRANSFORM_X(-4.0f), TRANSFORM_Y(-3.0f));
    glEnd();

    // Main Door panel left
    glBegin(GL_POLYGON);
    glColor3ub(128,135,32);
    glVertex2f(TRANSFORM_X(-3.3f), TRANSFORM_Y(-3.0f));
    glVertex2f(TRANSFORM_X(-3.3f), TRANSFORM_Y(-1.4f));
    glVertex2f(TRANSFORM_X(-4.0f), TRANSFORM_Y(-1.2f));
    glVertex2f(TRANSFORM_X(-4.0f), TRANSFORM_Y(-3.0f));
    glEnd();

    // Main Door panel right
    glBegin(GL_POLYGON);
    glColor3ub(128,135,32);
    glVertex2f(TRANSFORM_X(-2.5f), TRANSFORM_Y(-3.0f));
    glVertex2f(TRANSFORM_X(-2.5f), TRANSFORM_Y(-1.2f));
    glVertex2f(TRANSFORM_X(-3.2f), TRANSFORM_Y(-1.4f));
    glVertex2f(TRANSFORM_X(-3.2f), TRANSFORM_Y(-3.0f));
    glEnd();


    // Right side house 2   21-45465-3 (09)
    // roof
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);  // Standard brown
    glVertex2f(TRANSFORM_X(25-5), TRANSFORM_Y(1.2f+1));
    glVertex2f(TRANSFORM_X(21-5), TRANSFORM_Y(1.2f+1));
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-1.0f+1));
    glVertex2f(TRANSFORM_X(27-5), TRANSFORM_Y(-1.0f+1));
    glEnd();

    // roof side
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);  // Standard brown
    glVertex2f(TRANSFORM_X(21.5-5), TRANSFORM_Y(1.0f+1));
    glVertex2f(TRANSFORM_X(21.3-5), TRANSFORM_Y(1.2f+1));
    glVertex2f(TRANSFORM_X(19.5-5), TRANSFORM_Y(-1.0f+1));
    glVertex2f(TRANSFORM_X(20-5), TRANSFORM_Y(-1.0f+1));
    glEnd();

    // Right side house-2 left wall
    glBegin(GL_POLYGON);
    glColor3ub(205,133,63);
    glVertex2f(TRANSFORM_X(21.5-5), TRANSFORM_Y(1.0f+1));
    glVertex2f(TRANSFORM_X(20-5), TRANSFORM_Y(-1.0f+1));
    glVertex2f(TRANSFORM_X(20-5), TRANSFORM_Y(-2.5f+1));
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-3.0f+1));
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-1.0f+1));
    glEnd();

    // Right side house-2 left wall- window
    glBegin(GL_POLYGON);
    glColor3ub(128,135,32);
    glVertex2f(TRANSFORM_X(22-5), TRANSFORM_Y(-2.0f+1));
    glVertex2f(TRANSFORM_X(22-5), TRANSFORM_Y(-1.0f+1));
    glVertex2f(TRANSFORM_X(21-5), TRANSFORM_Y(-1.0f+1));
    glVertex2f(TRANSFORM_X(21-5), TRANSFORM_Y(-2.0f+1));
    glEnd();

    // Right side house-2 left base
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-3.0f+1));
    glVertex2f(TRANSFORM_X(20-5), TRANSFORM_Y(-2.5f+1));
    glVertex2f(TRANSFORM_X(19.7-5), TRANSFORM_Y(-2.9f+1));
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-3.5f+1));
    glEnd();

    // Right side house-2 right base
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-3.0f+1));
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-3.5f+1));
    glVertex2f(TRANSFORM_X(27-5), TRANSFORM_Y(-3.5f+1));
    glVertex2f(TRANSFORM_X(26.5-5), TRANSFORM_Y(-3.0f+1));
    glEnd();

    // Right side house-2 main(right) wall
    glBegin(GL_POLYGON);
    glColor3ub(184,134,11);
    glVertex2f(TRANSFORM_X(26.5-5), TRANSFORM_Y(-3.0f+1));
    glVertex2f(TRANSFORM_X(26.5-5), TRANSFORM_Y(-1.0f+1));
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-1.0f+1));
    glVertex2f(TRANSFORM_X(23-5), TRANSFORM_Y(-3.0f+1));
    glEnd();

    // Door ///

    // Main door
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(25.5-5), TRANSFORM_Y(-3.0f+1));
    glVertex2f(TRANSFORM_X(25.5-5), TRANSFORM_Y(-1.2f+1));
    glVertex2f(TRANSFORM_X(24-5), TRANSFORM_Y(-1.2f+1));
    glVertex2f(TRANSFORM_X(24-5), TRANSFORM_Y(-3.0f+1));
    glEnd();

    // Right side house-2 Door panel left
    glBegin(GL_POLYGON);
    glColor3ub(128,135,32);
    glVertex2f(TRANSFORM_X(24.7-5), TRANSFORM_Y(-3.0f+1));
    glVertex2f(TRANSFORM_X(24.7-5), TRANSFORM_Y(-1.4f+1));
    glVertex2f(TRANSFORM_X(24-5), TRANSFORM_Y(-1.2f+1));
    glVertex2f(TRANSFORM_X(24-5), TRANSFORM_Y(-3.0f+1));
    glEnd();

    // Right side house-2 door panel right
    glBegin(GL_POLYGON);
    glColor3ub(128,135,32);
    glVertex2f(TRANSFORM_X(25.5-5), TRANSFORM_Y(-3.0f+1));
    glVertex2f(TRANSFORM_X(25.5-5), TRANSFORM_Y(-1.2f+1));
    glVertex2f(TRANSFORM_X(24.8-5), TRANSFORM_Y(-1.4f+1));
    glVertex2f(TRANSFORM_X(24.8-5), TRANSFORM_Y(-3.0f+1));
    glEnd();

//////////////

    // House on right side 1  ///   21-45465-3 (10)

    // roof
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(TRANSFORM_X(25.3), TRANSFORM_Y(1.2));
    glVertex2f(TRANSFORM_X(21.3), TRANSFORM_Y(1.2));
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-1.0));
    glVertex2f(TRANSFORM_X(27.0), TRANSFORM_Y(-1.0));
    glEnd();

    // Roof extension
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(TRANSFORM_X(21.5), TRANSFORM_Y(1.0));
    glVertex2f(TRANSFORM_X(21.3), TRANSFORM_Y(1.2));
    glVertex2f(TRANSFORM_X(19.5), TRANSFORM_Y(-1.0));
    glVertex2f(TRANSFORM_X(20.0), TRANSFORM_Y(-1.0));
    glEnd();

    // Side wall
    glBegin(GL_POLYGON);
    glColor3ub(184,134,11);
    glVertex2f(TRANSFORM_X(21.5), TRANSFORM_Y(1.0));
    glVertex2f(TRANSFORM_X(20.0), TRANSFORM_Y(-1.0));
    glVertex2f(TRANSFORM_X(20.0), TRANSFORM_Y(-2.5));
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-3.0));
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-1.0));
    glEnd();

    // Window
    glBegin(GL_POLYGON);
    glColor3ub(160,82,45);
    glVertex2f(TRANSFORM_X(22.0), TRANSFORM_Y(-2.0));
    glVertex2f(TRANSFORM_X(22.0), TRANSFORM_Y(-1.0));
    glVertex2f(TRANSFORM_X(21.0), TRANSFORM_Y(-1.0));
    glVertex2f(TRANSFORM_X(21.0), TRANSFORM_Y(-2.0));
    glEnd();

    // Right side house-1 left base
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-3.0));
    glVertex2f(TRANSFORM_X(20.0), TRANSFORM_Y(-2.5));
    glVertex2f(TRANSFORM_X(19.7), TRANSFORM_Y(-2.9));
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-3.5));
    glEnd();

    // Right side house-1 right base
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-3.0));
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-3.5));
    glVertex2f(TRANSFORM_X(27.0), TRANSFORM_Y(-3.5));
    glVertex2f(TRANSFORM_X(26.5), TRANSFORM_Y(-3.0));
    glEnd();

    // Right side house-1 Main wall
    glBegin(GL_POLYGON);
    glColor3ub(205,133,63);
    glVertex2f(TRANSFORM_X(26.5), TRANSFORM_Y(-3.0));
    glVertex2f(TRANSFORM_X(26.5), TRANSFORM_Y(-1.0));
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-1.0));
    glVertex2f(TRANSFORM_X(23.0), TRANSFORM_Y(-3.0));
    glEnd();



    // Door ///

    // Main door
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(25.5), TRANSFORM_Y(-3.0));
    glVertex2f(TRANSFORM_X(25.5), TRANSFORM_Y(-1.2));
    glVertex2f(TRANSFORM_X(24.0), TRANSFORM_Y(-1.2));
    glVertex2f(TRANSFORM_X(24.0), TRANSFORM_Y(-3.0));
    glEnd();

    // Right side House-1 door panel left
    glBegin(GL_POLYGON);
    glColor3ub(160,82,45);
    glVertex2f(TRANSFORM_X(24.7), TRANSFORM_Y(-3.0));
    glVertex2f(TRANSFORM_X(24.7), TRANSFORM_Y(-0.8));
    glVertex2f(TRANSFORM_X(24.0), TRANSFORM_Y(-1.2));
    glVertex2f(TRANSFORM_X(24.0), TRANSFORM_Y(-3.0));
    glEnd();

    // Right side House-1 door panel right
    glBegin(GL_POLYGON);
    glColor3ub(160,82,45);
    glVertex2f(TRANSFORM_X(25.5), TRANSFORM_Y(-3.0));
    glVertex2f(TRANSFORM_X(25.5), TRANSFORM_Y(-1.2));
    glVertex2f(TRANSFORM_X(24.8), TRANSFORM_Y(-1.4));
    glVertex2f(TRANSFORM_X(24.8), TRANSFORM_Y(-3.0));
    glEnd();



    // Hill 1 ///     21-45465-3 (11)
    glBegin(GL_TRIANGLES);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(-12), TRANSFORM_Y(3));
    glVertex2f(TRANSFORM_X(-7.5), TRANSFORM_Y(7));
    glVertex2f(TRANSFORM_X(-2), TRANSFORM_Y(3));
    glEnd();

    // Hill 2 /// 21-45465-3 (12)
    glBegin(GL_POLYGON);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(-1), TRANSFORM_Y(3));
    glVertex2f(TRANSFORM_X(-0.5), TRANSFORM_Y(6));
    glVertex2f(TRANSFORM_X(4.5), TRANSFORM_Y(6));
    glVertex2f(TRANSFORM_X(5), TRANSFORM_Y(3));
    glEnd();

    glBegin(GL_POLYGON);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(-0.5), TRANSFORM_Y(6));
    glVertex2f(TRANSFORM_X(0), TRANSFORM_Y(7));
    glVertex2f(TRANSFORM_X(4), TRANSFORM_Y(7));
    glVertex2f(TRANSFORM_X(4.5), TRANSFORM_Y(6));
    glEnd();

    glBegin(GL_POLYGON);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(0), TRANSFORM_Y(7));
    glVertex2f(TRANSFORM_X(1), TRANSFORM_Y(8));
    glVertex2f(TRANSFORM_X(3), TRANSFORM_Y(8));
    glVertex2f(TRANSFORM_X(4), TRANSFORM_Y(7));
    glEnd();

    glBegin(GL_TRIANGLES);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(1), TRANSFORM_Y(8));
    glVertex2f(TRANSFORM_X(3), TRANSFORM_Y(8));
    glVertex2f(TRANSFORM_X(2), TRANSFORM_Y(8.3));
    glEnd();

    // Hill 3 /// 21-45465-3 (13)
    glBegin(GL_POLYGON);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(7), TRANSFORM_Y(3));
    glVertex2f(TRANSFORM_X(8), TRANSFORM_Y(5));
    glVertex2f(TRANSFORM_X(13), TRANSFORM_Y(5));
    glVertex2f(TRANSFORM_X(14), TRANSFORM_Y(3));
    glEnd();

    glBegin(GL_POLYGON);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(8), TRANSFORM_Y(5));
    glVertex2f(TRANSFORM_X(9), TRANSFORM_Y(6));
    glVertex2f(TRANSFORM_X(12), TRANSFORM_Y(6));
    glVertex2f(TRANSFORM_X(13), TRANSFORM_Y(5));
    glEnd();

    glBegin(GL_TRIANGLES);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(9), TRANSFORM_Y(6));
    glVertex2f(TRANSFORM_X(12), TRANSFORM_Y(6));
    glVertex2f(TRANSFORM_X(10.5), TRANSFORM_Y(6.5));
    glEnd();

    // Hill 4 /// 21-45465-3 (14)
    glBegin(GL_TRIANGLES);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(14), TRANSFORM_Y(3));
    glVertex2f(TRANSFORM_X(20), TRANSFORM_Y(7));
    glVertex2f(TRANSFORM_X(29), TRANSFORM_Y(3));
    glEnd();

    // Hill 5 /// 21-45465-3 (15)
    glBegin(GL_POLYGON);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(29), TRANSFORM_Y(3));
    glVertex2f(TRANSFORM_X(29.5), TRANSFORM_Y(4));
    glVertex2f(TRANSFORM_X(30.5), TRANSFORM_Y(4));
    glVertex2f(TRANSFORM_X(31), TRANSFORM_Y(3));
    glEnd();

    glBegin(GL_TRIANGLES);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(29.5), TRANSFORM_Y(4));
    glVertex2f(TRANSFORM_X(30), TRANSFORM_Y(4.5));
    glVertex2f(TRANSFORM_X(30.5), TRANSFORM_Y(4));
    glEnd();

    // Hill 6 /// 21-45465-3 (16)
    glBegin(GL_TRIANGLES);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(31), TRANSFORM_Y(3));
    glVertex2f(TRANSFORM_X(32.5), TRANSFORM_Y(4.5));
    glVertex2f(TRANSFORM_X(35), TRANSFORM_Y(3));
    glEnd();

    // Hill 7 /// 21-45465-3 (17)

    //polygon-1
    glBegin(GL_POLYGON);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(33), TRANSFORM_Y(3));
    glVertex2f(TRANSFORM_X(33.5), TRANSFORM_Y(4.5));
    glVertex2f(TRANSFORM_X(37.5), TRANSFORM_Y(4.5));
    glVertex2f(TRANSFORM_X(38), TRANSFORM_Y(3));
    glEnd();

    //polygon-2
    glBegin(GL_POLYGON);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(33.5), TRANSFORM_Y(4.5)); // (1140, 572.73)
    glVertex2f(TRANSFORM_X(34), TRANSFORM_Y(5));     // (1160, 618.18)
    glVertex2f(TRANSFORM_X(37), TRANSFORM_Y(5));     // (1360, 618.18)
    glVertex2f(TRANSFORM_X(37.5), TRANSFORM_Y(4.5)); // (1400, 572.73)
    glEnd();

    //triangle part
    glBegin(GL_TRIANGLES);
//    glColor3ub(0,100,0);
    interpolateColor3ub(0, 100, 0,       // Day hills
                        0, 20, 0,        // Night hills
                        transitionProgress);

    glVertex2f(TRANSFORM_X(34), TRANSFORM_Y(5));     // (1160, 618.18)
    glVertex2f(TRANSFORM_X(37), TRANSFORM_Y(5));     // (1360, 618.18)
    glVertex2f(TRANSFORM_X(35.5), TRANSFORM_Y(5.5)); // (1260, 672.73)
    glEnd();


    // Boat-1 moving from left to right  21-45465-3 (18)

    glPushMatrix();
    glTranslatef(moveB1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
//    glColor3ub(139,69,19);
    interpolateColor3ub(139, 69, 19,     // Day boat
                        60, 30, 10,      // Night boat
                        transitionProgress);

    glVertex2f(TRANSFORM_X(1.0f), TRANSFORM_Y(-14.0f));
    glVertex2f(TRANSFORM_X(1.50f), TRANSFORM_Y(-13.0f));
    glVertex2f(TRANSFORM_X(-2.0f), TRANSFORM_Y(-13.0f));
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-14.0f));
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-14.5f));
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-14.0f));
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-14.0f));
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-14.5f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-14.5f));
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-14.0f));
    glVertex2f(TRANSFORM_X(-4.5f), TRANSFORM_Y(-13.7f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-14.5f));
    glVertex2f(TRANSFORM_X(3.5f), TRANSFORM_Y(-13.7f));
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-14.0f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-14.0f));
    glVertex2f(TRANSFORM_X(1.5f), TRANSFORM_Y(-13.0f));
    glVertex2f(TRANSFORM_X(1.0f), TRANSFORM_Y(-14.0f));
    glEnd();
    glPopMatrix();

    // Boat-2 moving from right to left 21-45465-3 (19)

    glPushMatrix();
    glTranslatef(moveB2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
//    glColor3ub(139,69,19);
    interpolateColor3ub(139, 69, 19,     // Day boat
                        60, 30, 10,      // Night boat
                        transitionProgress);

    glVertex2f(TRANSFORM_X(22.0f), TRANSFORM_Y(-17.5f));
    glVertex2f(TRANSFORM_X(21.0f), TRANSFORM_Y(-16.5f));
    glVertex2f(TRANSFORM_X(17.50f), TRANSFORM_Y(-16.5f));
    glVertex2f(TRANSFORM_X(18.0f), TRANSFORM_Y(-17.5f));
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(22.0f), TRANSFORM_Y(-18.0f));
    glVertex2f(TRANSFORM_X(22.0f), TRANSFORM_Y(-17.5f));
    glVertex2f(TRANSFORM_X(17.0f), TRANSFORM_Y(-17.5f));
    glVertex2f(TRANSFORM_X(17.0f), TRANSFORM_Y(-18.0f));
    glEnd();

    //Main sail of Boat-2
    glBegin(GL_QUADS);
//    glColor3ub(255,99,71);
    interpolateColor3ub(255, 99, 71,     // Day boat
                        60, 30, 10,      // Night boat
                        transitionProgress);

    glVertex2f(TRANSFORM_X(20.5f), TRANSFORM_Y(-16.5f));
    glVertex2f(TRANSFORM_X(21.0f), TRANSFORM_Y(-14.5f));
    glVertex2f(TRANSFORM_X(18.5f), TRANSFORM_Y(-14.5f));
    glVertex2f(TRANSFORM_X(18.0f), TRANSFORM_Y(-16.5f));
    glEnd();

    glBegin(GL_QUADS);
//    glColor3ub(139,69,19);
    interpolateColor3ub(139, 69, 19,     // Day boat
                        60, 30, 10,      // Night boat
                        transitionProgress);

    glVertex2f(TRANSFORM_X(19.8f), TRANSFORM_Y(-14.5f));
    glVertex2f(TRANSFORM_X(19.8f), TRANSFORM_Y(-14.0f));
    glVertex2f(TRANSFORM_X(19.7f), TRANSFORM_Y(-14.0f));
    glVertex2f(TRANSFORM_X(19.7f), TRANSFORM_Y(-14.5f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(17.0f), TRANSFORM_Y(-18.0f));
    glVertex2f(TRANSFORM_X(17.0f), TRANSFORM_Y(-17.5f));
    glVertex2f(TRANSFORM_X(15.5f), TRANSFORM_Y(-17.2f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(22.0f), TRANSFORM_Y(-17.5f));
    glVertex2f(TRANSFORM_X(22.0f), TRANSFORM_Y(-18.0f));
    glVertex2f(TRANSFORM_X(23.5f), TRANSFORM_Y(-17.2f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(17.0f), TRANSFORM_Y(-17.5f));
    glVertex2f(TRANSFORM_X(18.0f), TRANSFORM_Y(-17.5f));
    glVertex2f(TRANSFORM_X(17.5f), TRANSFORM_Y(-16.5f));
    glEnd();
    glPopMatrix();

    // Still Boat-3 21-45465-3 (20)

    glBegin(GL_POLYGON);
//    glColor3ub(0,69,19);
    interpolateColor3ub(0, 69, 19,     // Day boat
                        60, 30, 10,      // Night boat
                        transitionProgress);

    glVertex2f(TRANSFORM_X(-3), TRANSFORM_Y(-10));
    glVertex2f(TRANSFORM_X(-3), TRANSFORM_Y(-7.5));
    glVertex2f(TRANSFORM_X(-3.1), TRANSFORM_Y(-7.5));
    glVertex2f(TRANSFORM_X(-3.1), TRANSFORM_Y(-10));
    glEnd();

    glPushMatrix();
    glBegin(GL_QUADS);
//    glColor3ub(139,69,19);
    interpolateColor3ub(139, 69, 19,     // Day boat
                        60, 30, 10,      // Night boat
                        transitionProgress);

    glVertex2f(TRANSFORM_X(1.0f), TRANSFORM_Y(-10.0f));
    glVertex2f(TRANSFORM_X(1.50f), TRANSFORM_Y(-9.0f));
    glVertex2f(TRANSFORM_X(-2.0f), TRANSFORM_Y(-9.0f));
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-10.0f));
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-10.5f));
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-10.0f));
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-10.0f));
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-10.5f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-10.5f));
    glVertex2f(TRANSFORM_X(-3.0f), TRANSFORM_Y(-10.0f));
    glVertex2f(TRANSFORM_X(-4.5f), TRANSFORM_Y(-9.7f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-10.5f));
    glVertex2f(TRANSFORM_X(3.5f), TRANSFORM_Y(-9.7f));
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-10.0f));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(TRANSFORM_X(2.0f), TRANSFORM_Y(-10.0f));
    glVertex2f(TRANSFORM_X(1.5f), TRANSFORM_Y(-9.0f));
    glVertex2f(TRANSFORM_X(1.0f), TRANSFORM_Y(-10.0f));
    glEnd();
    glPopMatrix();

    //glutSwapBuffers();

}
void brown_hill()
{
    glColor3f(0.50196, 0.25098, 0.0);


     glPushMatrix();
     glTranslatef(0,-220,0);
     glScaled(0.8,0.76,0);
     glBegin(GL_POLYGON);





    glVertex3i(600, 600, 0);
    glVertex3i(800, 900, 0);
    glVertex3i(900, 650, 0);
    //glVertex3i(600, 600, 0);

    glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);

    //glVertex3i(600, 600, 0);
    glVertex3i(900, 650, 0);
    glVertex3i(1000, 800, 0);
    glVertex3i(1100, 620, 0);

    glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(1050, 620, 0);
    glVertex3i(1200, 800, 0);
    glVertex3i(1200, 600, 0);





    glPopMatrix();


    glEnd();

}



/// All_Model ///

void sound()
{

    PlaySound(TEXT("fire.wav"), NULL, SND_ASYNC|SND_FILENAME);


}

/// Circle_Model ///



void circle(GLdouble rad)
{
   glBegin(GL_POLYGON);
    {
      	for(int i=0;i<50;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/50;
            float r=rad;
            float x = r * cos(A);

            float y = r * sin(A);
            glVertex2f(x,y );
        }
    }
    glEnd();
}





void circle1(GLdouble rad)
{

    glBegin(GL_POLYGON);
    {
      	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=rad;
            float x = r * cos(A);

            float y = r+10 * sin(A);
            glVertex2f(x,y );
        }
    }
        glEnd();
}

void fire(){
	glBegin(GL_POLYGON);

	glVertex2f(13.5,0.0);
	glVertex2f(8,10);
	glVertex2f(15,4);

    glVertex2f(17, 10);
	glVertex2f(19,4);
	glVertex2f(26.0,10);
    glVertex2f(20.5, 0.0);


    glEnd();
}


///  Sun_Model ///
void Sun_Model(){

    glPushMatrix();
    glTranslatef(600,1100,0);
    circle(33);
    glPopMatrix();

}

void update2(int value) {

    //position2 -= 5;
    if(position2 <-1.3)
    {
        position2 -= _move2;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update2, 0); //Notify GLUT to call update again in 25 milliseconds
}








/// Cloud_Model ///
void cloud_model_one(){

    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right

    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();

    /// Fill End

}

void cloud_model_Two(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();



}

void cloud_model_Three(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();




    ///Fill End

}
///  Hill_Model  ///
void hill_big1(){


    glColor3ub(231,76,60);
    glPushMatrix();
    glTranslatef(200,150,0);
    circle1(34);
    glPopMatrix();


	///Hill_BODY
    glBegin(GL_POLYGON);
    glColor3ub(151.0, 154.0, 154.0);
    glVertex2i(330, 70);

	glVertex2i(200, 170);
	glVertex2i(230, 190);
	glVertex2i(220, 180);
	glVertex2i(200, 190);
	glVertex2i(190, 180);
	glVertex2i(170, 190);
glVertex2i(70, 70);
	glEnd();

}
void hill_big2(){

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);

	glEnd();

	///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);

	glVertex2i(200, 225);
	glVertex2i(230, 190);
	glVertex2i(220, 180);
	glVertex2i(200, 190);
	glVertex2i(190, 180);
	glVertex2i(170, 190);

	glEnd();

}

void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 100);
	glVertex2i(310, 175);
	glVertex2i(370, 100);

	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
	glVertex2i(310, 175);
	glVertex2i(330, 150);
	glVertex2i(325, 140);
	glVertex2i(310, 150);
	glVertex2i(300, 140);


	glEnd();
}

///  Tilla_Model  ///
void Tilla_One_Model(){
        ///Tilla
	glBegin(GL_POLYGON);
	glColor3ub(34.0, 153.0, 84.0);
	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);

	glEnd();

}

void Tilla_Two_Model(){

	glColor3ub(34.0, 153.0, 84.0);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430,90,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,87,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,70,0);
    circle(30);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(445,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,75,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,70,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,65,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,60,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,55,0);
    circle(20);
    glPopMatrix();



}
///  House_Model  ///

void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3ub(44.0, 62.0, 80.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

  ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(255.0, 0.0, 0.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(255.0, 0.0, 0.0);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3ub(243.0, 156.0, 18.0);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();


}



void house1(){
    ///House_Roof
	glBegin(GL_POLYGON);
     glColor3ub(243.0, 156.0, 18.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3ub(245.0, 176.0, 65.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(255.0, 0.0, 0.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(255.0, 0.0, 0.0);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3ub(19, 141.0, 117.0);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();


    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3ub(160.0, 64.0, 0.0);
	glVertex2i(290, 70);
	glVertex2i(290, 140);
	glVertex2i(270, 140);

	glVertex2i(270, 70);

	glEnd();


	  ///House_somewall side
	glBegin(GL_POLYGON);
    glColor3ub(160.0, 64.0, 0.0);
	glVertex2i(265, 90);
	glVertex2i(265, 160);
	glVertex2i(270, 140);
	glVertex2i(270, 70);

	glEnd();

  ///House_somewall top

	  ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(265, 160);
	glVertex2i(270, 140);
	glVertex2i(290, 140);
	glVertex2i(285, 160);
glEnd();

}

void house2(){

    glPushMatrix();
    glTranslatef(690, 250,0);
    glScalef(0.18,0.35,0);



    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(0.0f, 128.0f, 128.0f); // Red
	glVertex2f(150.0f, 30.0f);    // x, y
	glVertex2f(150.0f, 200.0f);    // x, y
	glVertex2f(450.0f, 200.0f);
	glVertex2f(450.0f, 30.0f);
	glEnd();


    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3ub(165.0f, 42.0f, 42.0f); // Red
	glVertex2f(100.0f, 200.0f);    // x, y
	glVertex2f(300.0f, 300.0f);    // x, y
	glVertex2f(500.0f, 200.0f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(128.0f, 0.0f, 0.0f); // Red
	glVertex2f(250.0f, 30.0f);    // x, y
	glVertex2f(250.0f, 120.0f);    // x, y
	glVertex2f(320.0f, 120.0f);
	glVertex2f(320.0f, 30.0f);
	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(128.0f, 0.0f, 0.0f); // Red
	glVertex2f(350.0f, 120.0f);    // x, y
	glVertex2f(350.0f, 145.0f);    // x, y
	glVertex2f(395.0f, 145.0f);
	glVertex2f(395.0f, 120.0f);
	glEnd();



	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(128.0f, 0.0f, 0.0f); // Red
	glVertex2f(175.0f, 120.0f);    // x, y
	glVertex2f(175.0f, 145.0f);    // x, y
	glVertex2f(220.0f, 145.0f);
	glVertex2f(220.0f, 120.0f);
	glEnd();






    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(185.0f, 119.0f, 14.0f); // Red
	glVertex2f(450.0f, 30.0f);    // x, y
	glVertex2f(450.0f, 150.0f);    // x, y
	glVertex2f(800.0f, 150.0f);
	glVertex2f(800.0f, 30.0f);
	glEnd();



    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(128.0f, 0.0f, 0.0f); // Red
	glVertex2f(500.0f, 80.0f);    // x, y
	glVertex2f(500.0f, 110.0f);    // x, y
	glVertex2f(570.0f, 110.0f);
	glVertex2f(570.0f, 80.0f);
	glEnd();



    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(128.0f, 0.0f, 0.0f); // Red
	glVertex2f(600.0f, 80.0f);    // x, y
	glVertex2f(600.0f, 110.0f);    // x, y
	glVertex2f(670.0f, 110.0f);
	glVertex2f(670.0f, 80.0f);
	glEnd();


    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(128.0f, 0.0f, 0.0f); // Red
	glVertex2f(700.0f, 80.0f);    // x, y
	glVertex2f(700.0f, 110.0f);    // x, y
	glVertex2f(770.0f, 110.0f);
	glVertex2f(770.0f, 80.0f);
	glEnd();
	glPopMatrix();


}









///  Field_Model  ///
void field(){
    ///Field


	glBegin(GL_POLYGON);
    glColor3ub(90, 153, 51);
	glVertex2i(0, 250);
	glVertex2i(0,270);
	glVertex2i(1000, 270);
	glVertex2i(1000, 250);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3ub(0, 153, 51);
	glVertex2i(0, 230);
	glVertex2i(0, 250);
	glVertex2i(1000, 250);
	glVertex2i(1000, 200);

	glEnd();



	 ///river0.7/0.4/0.4


	glBegin(GL_POLYGON);
    glColor3ub(0, 143, 179);
	glVertex2i(0,0);
	glVertex2i(0,230);
	glVertex2i(600,225);
	glVertex2i(600,0);

	glEnd();

    ///river curve
	glBegin(GL_POLYGON);
	glColor3ub(0, 143, 179);
	glVertex2i(600,0);
	glVertex2i(600, 225);
	glVertex2i(1000, 245);
	glVertex2i(1000,0);

	glEnd();


	 ///Field_2
	glBegin(GL_POLYGON);
	glColor3ub(0, 153, 51);
	glVertex2i(0, 00);
	glVertex2i(0, 80);
	glVertex2i(600,50);
	glVertex2i(640, 0);

	glEnd();




		 ///Field_Shadow2
	glBegin(GL_POLYGON);
	glColor3ub(0, 153, 51);
	glVertex2i(0, 00);
	glVertex2i(0, 50);
	glVertex2i(600,50);
	glVertex2i(600, 0);

	glEnd();

	///Field_Shadow3
	glBegin(GL_POLYGON);
	glColor3ub(0, 153, 51);
	glVertex2i(600,0);
	glVertex2i(600, 50);
	glVertex2i(1000,30);
	glVertex2i(1000,0);

	glEnd();

}
    ///  Boat
void Boat(){


        glPushMatrix();
        glTranslatef(position,0.0f,0.0f);
        glTranslatef(-70,40.0f,0.0f);

        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(200,50);
        glVertex2i(100, 100);
        glVertex2i(400,100);
        glVertex2i(300,50);


        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(165.0, 42.0, 42.0);
        glVertex2i(180,100);
        glVertex2i(180, 150);
        glVertex2i(320,150);
        glVertex2i(320,100);


        glEnd();



        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(360,140);
        glVertex2i(350, 80);
        glVertex2i(360,50);



        glEnd();

        glPopMatrix();

}
//  Tree_Model  ///
void Tree_Model_One(){


    glPushMatrix();
    glTranslatef(110,110,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,100,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(27.0, 38,49);
	glVertex2f(109, 70);
	glVertex2f(109, 90);
	glVertex2f(111, 90);
	glVertex2f(111, 70);

    glEnd();

}
void Tree_Model_Two(){

    glPushMatrix();
    glTranslatef(130,130,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,125,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(27, 38, 49);
	glVertex2f(129, 110);
	glVertex2f(129, 124);
	glVertex2f(131, 124);
	glVertex2f(131, 110);

    glEnd();
}

void Tree_Model_Three(){


    glBegin(GL_POLYGON);

	glVertex2f(125, 123);
	glVertex2f(133, 145);
	glVertex2f(141, 123);

	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 38, 49);
	glVertex2f(132, 110);
	glVertex2f(132, 124);
	glVertex2f(134, 124);
	glVertex2f(134, 110);

    glEnd();
}

///  Windmill_Stand_Model  ///
void Windmill_Stand_Model(){

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///  Windmill_Blades_Model  ///

void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///  Windmill_Final_Model  ///
void Windmill(){



        ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3ub(208, 211, 212);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3ub(208, 211, 212);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();




}
  ///plane//

void plane(){


    glPushMatrix();
   // glTranslatef(position,0.0f,0.0f);
    glBegin(GL_POLYGON);//1t


	//glColor3ub(247, 249, 249);
	glVertex2f(20.0f, 20.0f);
    glVertex2f(25.0f, 20.0f);
	glVertex2f(25.0f,21.0f);
	glVertex2f(22.0f, 21.0f);


	glEnd();

    glBegin(GL_POLYGON);
	glColor3f(255.0f, 0.0f, 0.0f);
	glVertex2f(25.0f,22.0f);
    glVertex2f(24.0f, 21.0f);
    glVertex2f(25.0f, 21.0f);
	glEnd();



    glBegin(GL_POLYGON);// window 1

    glColor3f(255.0f, 0.0f, 0.0f);
	glVertex2f(23.7f, 20.2f);
    glVertex2f(24.2f, 20.2f);
	glVertex2f(24.2f,20.7f);
	glVertex2f(23.7f, 20.7f);

	glEnd();

    glBegin(GL_POLYGON);// door

    glColor3f(255.0f, 0.0f, 0.0f);
	glVertex2f(21.8f, 20.0f);
    glVertex2f(22.2f, 20.0f);
	glVertex2f(22.2f,20.6f);

	glVertex2f(21.8f, 20.6f);

	glEnd();

    glBegin(GL_POLYGON);// window 2

	glColor3f(255.0f, 0.0f, 0.0f);
	glVertex2f(22.8f, 20.2f);
    glVertex2f(23.3f, 20.2f);
	glVertex2f(23.3f,20.7f);
	glVertex2f(22.8f, 20.7f);

	glEnd();

    glPopMatrix();


}

        ///   Object  ///


///  sun   /// 22-48092-2-0001
void Sun(){
    glColor3f(s3, s2,s1);
    glPushMatrix();
     Sun_Model();
    glPopMatrix();
}


///   plane ///  22-48092-2-0002
void plane1(){
    glColor3ub(241, 196, 15);
    glPushMatrix();

    glTranslatef(position1,0,0);
    glTranslatef(0,360,0);
    glScaled(10.0f,10.0f,0.0f);
    plane();
    glPopMatrix();
}

void plane2(){  ///22-48092-2-0003
    glColor3ub(247, 249, 249);
    glPushMatrix();
    glTranslatef(position1,0,0);
    glTranslatef(100,320,0);
    glScaled(10.0f,10.0f,0.0f);
    plane();
    glPopMatrix();
}
///  Hill_volkano /// 22-48092-2-0004
void hill_volkano(){
    glPushMatrix();
    glTranslatef(0,200,0);
    hill_big1();
    glPopMatrix();
}
///  Hill_big_Two ///22-48092-2-0005
void Hill_Big_Two(){
    glPushMatrix();
    glTranslatef(550,180,0);//-20
    hill_big2();
    glPopMatrix();
}
/// Hill_Small_One ///22-48092-2-0006
void Hill_Small_One(){
    glPushMatrix();
    glTranslatef(0,200,0);
    hill_small();
    glPopMatrix();

}



void star(){                ///22-48092-2-00029
if ( condition==true)

{
             glBegin(GL_POINTS);        // Each set of 4 vertices form a quad
             glColor3ub(247, 249, 249); // Red
             glVertex2f(500.1f, 500.3f);// x, y
             glVertex2f( 550.1f, 504.0f);
             glVertex2f( 150.1f, 504.0f);
             glVertex2f( 310.1f, 504.0f);
             glVertex2f( 261.0f, 505.0f);
             glVertex2f( 453.1f, 506.0f);
             glVertex2f( 616.1f, 507.0f);
             glVertex2f( 763.1f, 508.0f);
             glVertex2f( 587.1f, 524.0f);
             glVertex2f( 954.1f, 574.0f);
             glVertex2f( 231.1f, 585.0f);
             glVertex2f( 275.1f, 566.0f);
             glVertex2f( 852.1f, 557.0f);
             glVertex2f( 476.1f, 548.0f);
             glVertex2f( 140.1f, 509.0f);
             glVertex2f( 350.1f, 510.0f);
             glVertex2f( 061.1f, 511.0f);
             glVertex2f( 463.1f, 512.0f);
             glVertex2f( 822.1f, 513.0f);
             glVertex2f( 110.1f, 514.0f);
             glVertex2f( 966.1f, 515.0f);
             glVertex2f( 211.1f, 516.0f);
             glVertex2f( 313.1f, 517.0f);
             glVertex2f( 869.1f, 518.0f);
             glVertex2f( 639.1f, 519.0f);
             glVertex2f( 106.1f, 520.0f);
             glVertex2f( 140.1f, 709.0f);
             glVertex2f( 350.1f, 810.0f);
             glVertex2f( 061.1f, 911.0f);
             glVertex2f( 463.1f, 412.0f);
             glVertex2f( 822.1f, 713.0f);
             glVertex2f( 110.1f, 614.0f);
             glVertex2f( 966.1f, 815.0f);
             glVertex2f( 211.1f, 916.0f);
             glVertex2f( 313.1f, 1017.0f);
             glVertex2f( 869.1f, 718.0f);
             glVertex2f( 639.1f, 919.0f);
             glVertex2f( 106.1f, 902.0f);
             glVertex2f( 106.1f, 908.0f);
             glVertex2f( 106.1f, 620.0f);
             glVertex2f( 250.1f, 630.0f);
             glVertex2f( 106.1f, 906.0f);
             glVertex2f( 116.1f, 530.0f);
             glVertex2f( 980.1f, 980.0f);
             glVertex2f( 900.1f, 930.0f);
             glVertex2f( 858.1f, 666.0f);
             glVertex2f( 845.1f, 642.0f);
             glVertex2f( 900.1f, 900.0f);
             glVertex2f( 910.1f, 903.0f);
             glVertex2f( 915.1f, 908.0f);
             glVertex2f( 919.1f, 920.0f);
             glVertex2f( 930.1f, 903.0f);
             glVertex2f( 935.1f, 905.0f);
             glVertex2f( 940.1f, 905.0f);
             glVertex2f( 945.1f, 910.0f);
             glVertex2f( 600.1f, 525.0f);
             glVertex2f( 650.1f, 535.0f);
             glVertex2f( 690.1f, 490.0f);
             glVertex2f( 550.1f, 600.0f);
             glVertex2f( 500.1f, 600.0f);





    glEnd();

}



}
void night(){           ///22-48092-2-00028

    glColor3f(.0, 0.0, 0.0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3i(0,n1,0);
    glVertex3i(0,1000, 0);
    glVertex3i(1200,1000, 0);
    glVertex3i(1200,n1, 0);
    glPopMatrix();


glEnd();

}

/// Cloud_One_Model_One /// 22-48092-2-00032
void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,225,0);
    cloud_model_one();
    glPopMatrix();

}
/// Cloud_Two_Model_one ///

void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+100,290,0);
    cloud_model_one();
    glPopMatrix();

}

///  Cloud_Three_Model_Two ///

void cloud_three(){
    glPushMatrix();
    glTranslatef(ax-80,230,0);
    cloud_model_Two();
    glPopMatrix();

}
/// Cloud_Four_Model_Two ///

void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,275,0);
    cloud_model_Two();
    glPopMatrix();

}
/// Cloud_Five_Model_Three  ///
void cloud_five(){

    glPushMatrix();
    glTranslatef(ax+-300,310,0);
    cloud_model_Three();
    glPopMatrix();
}
///  Cloud_Six_Model_Three ///
void cloud_six(){

    glPushMatrix();
    glTranslatef(cx+-500,390,0);
    cloud_model_Three();
    glPopMatrix();
}

/// House_One ///22-48092-2-00025
void house_one(){
    glPushMatrix();
    glTranslatef(0,200,0);
    house1();
    glPopMatrix();
}



/// House_Two  ///22-48092-2-00026
void house_three(){
    glPushMatrix();
    glTranslatef(320, 237,0);
    house();
    glPopMatrix();
}

///  Tilla_One_Model_One  /// 22-48092-2-0007

void Tilla_One(){

    glPushMatrix();
    glTranslatef(0,200,0);
    Tilla_One_Model();
    glPopMatrix();

}
/// *** Tilla_Two_Model_Two ***///22-48092-2-0008
void Tilla_Two(){

    glPushMatrix();
    glTranslatef(0,200,0);
    Tilla_Two_Model();
    glPopMatrix();


}
///  Tilla_Three_Model_Two  ///22-48092-2-0009
void Tilla_Three(){

    glPushMatrix();
    glTranslatef(400,200,0);
    Tilla_Two_Model();
    glPopMatrix();


}
///  Tilla_Four_Model_One  ///22-48092-2-00010
void Tilla_Four(){

    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380,200,0);
    Tilla_One_Model();
    glPopMatrix();


}
///  Tree_1   /// 22-48092-2-00011
void Tree_One(){
    glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(0,200,0);
    Tree_Model_One();
    glPopMatrix();
}

///  Tree_2  ///22-48092-2-00012
void Tree_Two(){
     glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(540,200,0);
    Tree_Model_One();
    glPopMatrix();
}

///   Tree_3  ///22-48092-2-00013
void Tree_Three(){
 glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(750,200,0);
    Tree_Model_One();
    glPopMatrix();
}
///  Tree_4  ///22-48092-2-00014
void Tree_Four(){
    glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(292,240,0);
    Tree_Model_One();
    glPopMatrix();
}

///  Tree_5   ///22-48092-2-00015
void Tree_Five(){
    glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(30,180,0);//-20
    Tree_Model_Two();
    glPopMatrix();
}

///  Tree_6  ///22-48092-2-00016
void Tree_Six(){
    glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(50,190,0);//-10
    Tree_Model_Two();
    glPopMatrix();
}
///  Tree_7  ///22-48092-2-00017
void Tree_Seven(){
     glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(322,200,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***/// 22-48092-2-00018
void Tree_Eight(){
     glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(350,185,0);//-15
    Tree_Model_Two();
    glPopMatrix();
}

///  Tree_9  ///22-48092-2-00019
void Tree_Nine(){
    glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(760,125,0);//-75
    Tree_Model_Two();
    glPopMatrix();
}

///  Tree_10  ///22-48092-2-00020
void Tree_Ten(){
     glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(90,198,0);//-2
    Tree_Model_Three();
    glPopMatrix();
}

///  Tree_11  ///22-48092-2-00021
void Tree_Eleven(){
     glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(125,200,0);
    Tree_Model_Three();
    glPopMatrix();
}

///  Tree_12  ///22-48092-2-00022
void Tree_Twelve(){
     glColor3ub(46, 204, 13.0);
    glPushMatrix();
    glTranslatef(408,178,0);
    Tree_Model_Three();
    glPopMatrix();
}

///  Windmill   ///
void Windmill_One(){        ///22-48092-2-00023
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,190,0);
    Windmill();
    glPopMatrix();

}

void Windmill_Two(){        ///22-48092-2-00024
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,130,0);
    Windmill();
    glPopMatrix();

}
void tree(){            ///22-48092-2-00027


    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(-120,-110,0);
    Windmill();
    glPopMatrix();

}
void fire2(){       ///22-48092-2-00031

    glColor3f(1,1, 0);
    glPushMatrix();
    glTranslatef(130,390,0);
    glScaled(x,x,0);
    fire();

    glPopMatrix();



}

void fire1(){           ///22-48092-2-00030

    glColor3f(0.7, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(63,390,0);
    glScaled(y,y,0);
    fire();


    glPopMatrix();



}
oid drawCircle(float radius, float xc, float yc, float r, float g, float b)//22-49252-3(1)
 {
    glColor3f(r, g, b); // Set color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}
/ Function to change background color
void setSkyColor() //22-49252-3 (2)
 {
    if (isNight) {
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue for night
    } else {
        glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Light blue for day
    }
}

// Function to draw a single snowflake
/*void drawSnow() {
    if (isSnowing) {
        for (int i = 0; i < MAX_SNOWFLAKES; i++) {
            drawCircle(5, snowX[i], snowY[i], 1.0f, 1.0f, 1.0f);
        }
    }
}*/

const int MAX_SNOWFLAKES = 2000; // Increased number of snowflakes
float snowX[MAX_SNOWFLAKES], snowY[MAX_SNOWFLAKES];

void initializeSnow() {
    srand(time(0)); // Seed the random number generator for variation

    for (int i = 0; i < MAX_SNOWFLAKES; i++) {
        snowX[i] = (rand() % 4000) - 2000; // Spread across the screen width
        snowY[i] = (rand() % 2400) - 1200; // Start from above the top (extended)
    }
}


void drawSnow() {
    if (!isSnowing) return;

    glPointSize(2.0); // Adjust snowflake size
    glBegin(GL_POINTS); // Use points for snowflakes (more efficient)
    for (int i = 0; i < MAX_SNOWFLAKES; i++) {
        glColor3f(1.0f, 1.0f, 1.0f); // White snow
        glVertex2f(snowX[i], snowY[i]);
    }
    glEnd();
}
void Grass() //22-49252-3 (3)
{
    glBegin(GL_QUADS);
    //glColor3f(0.0f, 0.6f, 0.0f); // Green color for grass
    //glColor3ub(128, 250, 97); // Green color for grass
    if (isNight) {
        glColor3ub(51,102,0.0); // Red sun at night
    } else {
         glColor3ub(128,250,97); // Yellow sun during the day
    }
    glVertex2f(-2000, -200);
    glVertex2f(-2000, -1200);
    glVertex2f(2000, -1200);
    glVertex2f(2000, -200);
    glEnd();
}
void Grass1() //22-49252-3 (4)
{
    glBegin(GL_QUADS);
    //glColor3ub(124, 252, 0); // Green color for grass
    if (isNight) {
        glColor3ub(51,102,0.0); // for night
    } else {
         glColor3ub(124, 252, 0); // Yellow sun during the day
    }
    glVertex2f(-2000,500);
    glVertex2f(-2000, 200);
    glVertex2f(2000, 200);
    glVertex2f(2000,500);
    glEnd();
}

void Mountain() //22-49252-3 (5)
{
    glBegin(GL_POLYGON);
    //glColor3ub(48,149,37);
    if (isNight) {
        glColor3ub(102,80,60); // Red sun at night
    } else {
         glColor3ub(48,149,37); // Yellow sun during the day
    }
    glVertex2f(-1924.938193436626, 400.2029251378721); // A
    glVertex2f(-1813.6618406647808, 519.4275888219919); // B
    glVertex2f(-1765.971975191133, 634.6780970499743); // C
    glVertex2f(-1678.5405551561116, 749.9286052779568); // D
    glVertex2f(-1702.3854878929355,547.2466770149532);//E
    glVertex2f(-1654.6956224192877,503.5309669974426);//U
    glVertex2f(-1829.5584624893302,404.1770805940095);//T
    /*glBegin(GL_POLYGON);
    glColor3f(0.8f, 1.0f, 0.89f);
    glVertex2f(-1678.5405551561116,749.9286052779568);//D
    glVertex2f(-1702.3854878929355,547.2466770149532);//E
    glVertex2f(-1654.6956224192877,503.5309669974426);//U
    glVertex2f(-1571.2383578403992,594.9365424886054);//Z*/
    glBegin(GL_POLYGON);
    //glColor3ub(109,225,96);
    if (isNight) {
         glColor3ub(102,80,60);// Red sun at night
    } else {
         glColor3ub(109,225,96); // Yellow sun during the day
    }
    glVertex2f(-1654.6956224192877,503.5309669974426);//U
    glVertex2f(-1571.2383578403992,594.9365424886054);//Z
    glVertex2f(-1440.0912277878717,718.1353616288582);//F
    glVertex2f(-1352.6598077528504,765.8252271025061);//G
    glVertex2f(-1340.7373413844384,837.360025312978);//H
    glVertex2f (-1177.7969676828077,972.4813108216471);//I
    glVertex2f(-1200,800);//J
    glVertex2f(-1200,600);//K
    glVertex2f(-1102.2880140161985,598.9106979447384);//L
    glVertex2f(-1050.623993086413,431.9961687869707);//M
    glVertex2f(-1229.4609886125932,439.9444796992454);//W
    glVertex2f(-1467.910315980833,523.4017442781292);//V
    glBegin(GL_POLYGON);
    //glColor3ub(109,225,96);
    if (isNight) {
         glColor3ub(102,80,60); // Red sun at night
    } else {
        glColor3ub(109,225,96); // Yellow sun during the day
    }
    glVertex2f (-1177.7969676828077,972.4813108216471);//I
    glVertex2f(-1200,800);//J
    glVertex2f(-1200,600);//K
    glVertex2f(-1102.2880140161985,598.9106979447384);//L
    glVertex2f(-1050.623993086413,431.9961687869707);//M
    glVertex2f(-907.5543966654692,428.0220133308334);//N
    glVertex2f(-816.1488211743106,563.1432988395024);//O
    glVertex2f(-732.6915565954266,666.4713406990729);//S
    glVertex2f(-947.2959512268425,912.8689789795872);//R
    glBegin(GL_POLYGON);
    //glColor3ub(121,240,108);
    if (isNight) {
 glColor3ub(102,80,60); // Red sun at night
    } else {
       glColor3ub(121,240,108); // Yellow sun during the day
    }
    glVertex2f(-907.5543966654692,428.0220133308334);//N
    glVertex2f(-816.1488211743106,563.1432988395024);//O
    glVertex2f(-732.6915565954266,666.4713406990729);//S
    glVertex2f(-669.1050692972293,682.3679625236223);//P
    glVertex2f(-255.7929018589467,408.1512360501467);//Q
    glBegin(GL_POLYGON);
    //glColor3f(137, 239, 126);
    if (isNight) {
         glColor3ub(102,80,60); // Red sun at night
    } else {
       glColor3f(137, 239, 126);  // Yellow sun during the day
    }
    glVertex2f(-1829.5584624893302,404.1770805940095);//T
    glVertex2f(-1654.6956224192877,503.5309669974426);//U
    glVertex2f(-1467.910315980833,523.4017442781292);//V
    glVertex2f(-1229.4609886125932,439.9444796992454);//W
    glVertex2f(-1050.623993086413,431.9961687869707);//M
    glVertex2f(-907.5543966654692,428.0220133308334);//N
    glVertex2f(-740.6398675076945,412.1253915062884);//A1
    glEnd();
}

void Leaf() //22-49252-3 (6)
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.6,0.2);
    glVertex2f(0,1000);
    glVertex2f(-200,800);
    glVertex2f(200,800);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.8,0.4);
    glVertex2f(-136.4581035254357,800);
    glVertex2f(-279.637834595763,638.6522525061159);
    glVertex2f(272.7697738073261,642.6264079622533);
    glVertex2f(121.7518664741075,800);
    glEnd();

//3rd leaf
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.5);
    glVertex2f(-160.4193413217292,639.5099395080874);//I1
    glVertex2f(-283.4204827352345,492.828326609662);//j1
    glVertex2f(271.7917266007077,496.7800149323378);//L1
    glVertex2f(159.2005228328263,641.8093629912138);//K1
    glEnd();
}
void Tree() //22-49252-3 (7)
{
    glBegin(GL_QUADS);
    glColor3f(0.4,0.2,0.0);
    glVertex2f(-79.2018237138391,494.281840197003);//M1
    glVertex2f(-75.9568457947579,208.3067673770099);//N1
    glVertex2f(79.6028684471956,203.3181250177116);//P1
    glVertex2f(79.5967864186112,495.4120794150257);//O1

    glEnd();
}

void Road()  //22-49252-3 (8)
{
    glBegin(GL_QUADS);
   //glColor3ub(169,169,169);
    if (isNight) {
         glColor3ub(64,64,64); // Red sun at night
    } else {
       glColor3f(169,169,169);  // Yellow sun during the day
    }
    glVertex2f(-2000, 200);
    glVertex2f(-2000, -200);
    glVertex2f(2000, -200);
    glVertex2f(2000, 200);
    glEnd();
}

void Roadmarking() //22-49252-3 (9)
{
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0.0);
    for (int i = -2000; i <= 2000; i += 400) {
        glVertex2f(i, 0.0);
        glVertex2f(i + 200, 0.0);
    }
    glEnd();
}

void Roadsidemarking() //22-49252-3 (10)
{
    glLineWidth(5.5);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-2000, 200);
    glVertex2f(2000, 200);
    glVertex2f(-2000, -200);
    glVertex2f(2000, -200);
    glEnd();
}

void Car()  //22-49252-3 (11)
{
    glPushMatrix();
    glTranslatef(motion, 0, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-2000, 119.44);
    glVertex2f(-1898.91, 120.78);
    glVertex2f(-1799.39, 159.78);
    glVertex2f(-1600.35, 159.78);
    glVertex2f(-1499.48, 120.78);
    glVertex2f(-1299.10, 119.44);
    glVertex2f(-1299.10, 42.78);
    glVertex2f(-1498.14, 38.74);
    glVertex2f(-1541.68, 38.92);
    glVertex2f(-1855.70, 41.43);
    glVertex2f(-2000, 40.09);
    glEnd();

    drawCircle(50, -1855.70, 20, 0, 0, 0);
    drawCircle(30, -1855.70, 20, 1, 1, 1);
    drawCircle(50, -1541.68, 20, 0, 0, 0);
    drawCircle(30, -1541.68, 20, 1, 1, 1);

    glPopMatrix();
}

void update(int value) //22-49252-3 (1)
{
    motion += 10.0f;
    if (motion > 4000.0f) {
        motion = -2000.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(15, update, 0);
}
void Bulding() //22-49252-3 (12)
{
    //Left corner
    glBegin(GL_POLYGON);
    glColor3f(0.57,0.38,0.27);
    glVertex2f(599.9767413592405,640.2046351666261);//E3
    glVertex2f(499.1320865423542,580.5653231781454);//G3
    glVertex2f(539.2530782436961,579.4809720510821);//J3
    glEnd();
    //Chal
    glBegin(GL_POLYGON);
    glColor3f(0.48,0.30,0.20);
    glVertex2f(599.9767413592405,640.2046351666261);//E3
    glVertex2f(680.2187247619242,561.0470028910063);//H3
    glVertex2f(922.0290260970388,561.0470028910063);//I3
    glVertex2f(822.2687224072158,641.2889862936894);//F3
    glEnd();
    //Left side
    glBegin(GL_POLYGON);
    glColor3f(0.49,0.76,0.36);
    glVertex2f(599.9767413592405,640.2046351666261);//E3
    glVertex2f(539.2530782436961,579.4809720510821);//j3
    glVertex2f(539.2530782436961,439.5996766599183);//K3
    glVertex2f(678.0500225077977,420.0813563727792);//L3
    glVertex2f(680.2187247619242,561.0470028910063);//H3
    glEnd();
    //front side
    glBegin(GL_POLYGON);
    glColor3f(0.58,0.60,0.64);
    glVertex2f(680.2187247619242,561.0470028910063);//H3
    glVertex2f(678.0500225077977,420.0813563727792);//L3
    glVertex2f(919.8603238429122,433.0935698975386);//M3
    glVertex2f(922.0290260970388,561.0470028910063);//I3
    glEnd();
    //janala
    glBegin(GL_POLYGON);
    glColor3f(0.77,0.86,0.31);
    glVertex2f(579.330150798918,540.700958527913);//Q3
    glVertex2f(577.848897978669,508.8540228925593);//S3
    glVertex2f(615.620844895019,508.1133964824348);//T3
    glVertex2f(617.8427241253926,537.738452887415);//R3
    glEnd();
    //Door
    glBegin(GL_POLYGON);
    glColor3f(0.19,0.37,0.17);
    glVertex2f(770.4117646110416,499.9665059710653);//U3
    glVertex2f(774.1809481598998,425.2543209818608);//V3
    glVertex2f(810.4550680293986,427.206291557798);//Z3
    glVertex2f(809.6649643476405,500.7071323811898);//W3
    glEnd();
    //left pira
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.0,0.0);
    glVertex2f(539.2530782436961,439.5996766599183);//K3
    glVertex2f(539.2530782436961,420.0813563727792);//N3
    glVertex2f(678.0500225077977,400.5630360856401);//O3
    glVertex2f(678.0500225077977,420.0813563727792);//L3
    glEnd();

    //front pira
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.0,0.0);
    glVertex2f(678.0500225077977,420.0813563727792);//L3
    glVertex2f(678.0500225077977,400.5630360856401);//O3
    glVertex2f(919.8603238429122,411.4065473562729);//P3
    glVertex2f(919.8603238429122,433.0935698975386);//M3
    glEnd();

}
void Wood() //22-49252-3 (13)
{
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1706.7985540149004,-986.4832774047668);//B4
    glVertex2f(-1824.3109746773243,-984.6471458319164);//C4
    glVertex2f(-1839.0000272601274,-1037.8949614445776);//D4
    glVertex2f(-1805.9496589488215,-1081.9621191929866);//E4
    glVertex2f(-1765.5547643461132,-1076.4537244744356);//F4
    glVertex2f(-1732.5043960348064,-1030.550435153176);//G4
    glVertex2f(-1677.420448849295,-1021.3697772889241);//H4
    //glVertex2f;
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1677.420448849295,-1021.3697772889241);//H4
    glVertex2f(-1732.5043960348064,-1030.550435153176);//G4
    glVertex2f(-1765.5547643461132,-1076.4537244744356);//F4
    glVertex2f(-1736.1766591805072,-1109.5040927857424);//I4
    glVertex2f(-1673.7481857035943,-1113.1763559314431);//J4
    glVertex2f(-1614.9919753723825,-1063.6008034644829);//K4
    //glVertex2f;
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1614.9919753723825,-1063.6008034644829);//K4
    glVertex2f(-1609.4835806538313,-1115.0124875042936);//L4
    glVertex2f(-1572.7609491968237,-1135.2099348056477);//M4
    glVertex2f(-1508.4963441470607,-1127.8654085142462);//N4
    glVertex2f(-1482.7905021271554,-1089.3066454843881);//O4
    glVertex2f(-1493.8072915642576,-1054.4201456002309);//P4
    glVertex2f(-1537.8744493126667,-1032.3865667260263);//Q4
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1614.9919753723825,-1063.6008034644829);//K4
    glVertex2f(-1556.2357650411705,-1054.4201456002309);//R4
    glVertex2f(-1493.8072915642576,-1054.4201456002309);//P4
    glVertex2f(-1537.8744493126667,-1032.3865667260263);//Q4
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1493.8072915642576,-1054.4201456002309);//P4
    glVertex2f(-1482.7905021271554,-1089.3066454843881);//O4
    glVertex2f(-1413.017502358841,-1113.1763559314431);//S4
    glVertex2f(-1350.5890288819282,-1109.5040927857424);//T4
    glVertex2f(-1323.0470552891727,-1078.2898560472859);//U4
    glVertex2f(-1328.5554500077237,-1041.5672245902783);//V4
    glVertex2f(-1365.2780814647313,-1039.7310930174278);//W4
    glVertex2f(-1405.6729760674395,-1026.878172007475);//Z4
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(80,16,18);
    glVertex2f(-1405.6729760674395,-1026.878172007475);//Z4
    glVertex2f(-1295.505081696417,-1047.0756193088293);//A5
    glVertex2f(-1286.3244238321652,-1081.9621191929866);//B5
    glVertex2f(-1262.4547133851104,-1052.5840140273806);//C5
    glVertex2f(-1264.2908449579606,-993.8278036961683);//D5
    glVertex2f(-1367.1142130375817,-997.500066841869);//E5
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(252,64,71);
    glVertex2f(-1706.7985540149004,-986.4832774047668);//B4
    glVertex2f(-1677.420448849295,-1021.3697772889241);//H4
    glVertex2f(-1614.9919753723825,-1063.6008034644829);//K4
    glVertex2f(-1537.8744493126667,-1030.550435153176);//Q4
    glVertex2f(-1493.8072915642576,-1054.4201456002309);//P4
    glVertex2f(-1405.6729760674395,-1026.878172007475);//Z4
    glVertex2f(-1367.1142130375817,-997.500066841869);//E5
    glVertex2f(-1354.2612920276292,-951.5967775206095);//F5
    glVertex2f(-1359.7696867461802,-898.3489619079485);//G5
    glVertex2f(-1394.6561866303375,-843.265014722437);//H5
    glVertex2f(-1411.1813707859908,-766.1474886627209);//I5
    glVertex2f(-1436.887212805896,-843.265014722437);//J5
    glVertex2f(-1453.4123969615493,-795.525593828327);//K5
    glVertex2f(-1442.395607524447,-740.4416466428155);//L5
    glVertex2f(-1446.0678706701478,-690.8660941758552);//M5
    glVertex2f(-1473.6098442629036,-643.1266732817453);//N5
    glVertex2f(-1477.2821074086044,-696.3744888944063);//O5
    glVertex2f(-1491.9711599914074,-736.7693834971147);//P5
    glVertex2f(-1501.1518178556591,-678.0131731659026);//Q5
    glVertex2f(-1514.004738865612,-633.9460154174933);//R5
    glVertex2f(-1504.82408100136,-578.8620682319819);//S5
    glVertex2f(-1528.693791448415,-510.9252000365177);//T5
    glVertex2f(-1530.5299230212652,-562.3368840763285);//U5
    glVertex2f(-1554.39963346832,-633.9460154174933);//V5
    glVertex2f(-1558.0718966140207,-556.8284893577772);//W5
    glVertex2f(-1596.6306596438787,-624.7653575532414);//Z5
    glVertex2f(-1603.9751859352803,-670.668646874501);//A6
    glVertex2f(-1603.9751859352803,-720.2441993414614);//B6
    glVertex2f(-1622.336501663784,-747.7861729342171);//C6
    glVertex2f(-1631.5171595280358,-707.3912783315086);//D6
    glVertex2f(-1648.0423436836893,-666.9963837288002);//E6
    glVertex2f(-1644.3700805379885,-619.2569628346903);//F6
    glVertex2f(-1668.2397909850433,-687.1938310301545);//G6
    glVertex2f(-1664.5675278393426,-736.7693834971147);//H6
    glVertex2f(-1660.8952646936418,-788.1810675369255);//I6
    glVertex2f(-1675.5843172764448,-834.0843568581851);//J6
    glVertex2f(-1700,-800);//K6
    glVertex2f(-1703.1262908692004,-835.9204884310354);//L6
    glVertex2f(-1719.6514750248539,-872.6431198880431);//M6
    glVertex2f(-1721.4876065977041,-931.3993302192553);//N6
    glEnd();
}
void drawSun() //22-49252-3 (14)
{
    if (isNight) {
        drawCircle(150, 1500, 900, 1.0, 1.0, 1.0); // Red sun at night
    } else {
        drawCircle(150, 1500, 900, 1.0, 1.0, 0.0); // Yellow sun during the day
    }
}
void Laftside()  //22-49252-3 (15)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(129.4325555435912,363.5193328942221);//w6
    glVertex2f(127.277924683114,304.6260893745122);//A7
    glVertex2f(136.6146584118485,303.9078790876864);//B7
    glVertex2f(139.4874995591514,362.8011226073963);//Z6
    glEnd();
}
void Laftside1()  //22-49252-3 (16)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(118.6594012412056,290.2618836379975);//L7
    glVertex2f(118.6594012412053,237.1143224128934);//N7
    glVertex2f(130.8689761172427,237.1143224128934);//M7
    glVertex2f(130.1507658304173,290.2618836379975);//K7
    glEnd();
}
void middleside()  //22-49252-3 (17)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(241.4733602884045,363.5193328942221);//C7
    glVertex2f(241.4733602884045,306.7807202349894);//e7
    glVertex2f(250.0918837303132,306.7807202349894);//F7
    glVertex2f(252.2465145907904,363.5193328942221);//D7
    glEnd();
}

void middleside1()  //22-49252-3 (18)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(240.036939714753,290.9800939248233);//P7
    glVertex2f(241.4733602884045,237.1143224128934);//R7
    glVertex2f(255.1193557380933,236.3961121260677);//Q7
    glVertex2f(255.837566024919,289.5436733511718);//O7
    glEnd();
}
void Rightside() //22-49252-3 (19)
 {
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(351.3595341727406,363.5193328942221);//G7
    glVertex2f(356.3870061805206,306.0625099481636);//J7
    glVertex2f(365.0055296224293,306.0625099481636);//I7
    glVertex2f(363.5691090487779,363.5193328942221);//H7
    glEnd();
}
void Rightside1()  //22-49252-3 (20)
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(364.2873193356036,291.698304211649);//T7
    glVertex2f(362.1326884751264,238.5507429865449);//V7
    glVertex2f(375.7786839248152,237.1143224128934);//U7
    glVertex2f(378.6515250721181,291.698304211649);//S7
    glEnd();
}
void Bench() //22-49252-3 (21)
{
    glBegin(GL_QUADS);
    glColor3ub(204,0.0,0.0);
    glVertex2f(114.3501395202513,361.3647020337449);//W7
    glVertex2f(113.6319292334255,346.2822860104046);//A8
    glVertex2f(377.9333147852933,346.2822860104046);//B8
    glVertex2f(377.9333147852933,362.0829123205706);//z7;
    glEnd();
}
void Bench2() //22-49252-3 (22)
{
    glBegin(GL_QUADS);
    glColor3ub(204,0.0,0.0);
    glVertex2f(115.068349807077,339.1001831421472);//C8
    glVertex2f(114.3501395202513,324.7359774056326);//E8
    glVertex2f(377.2151044984676,324.0177671188069);//f8
    glVertex2f(376.4968942116418,340.5366037157987);//D8
    glEnd();
}
void Bench3() //22-49252-3 (23)
{
    glBegin(GL_QUADS);
    glColor3ub(204,0.0,0.0);
    glVertex2f(113.6319292334256,305.3442996613379);//G8
    glVertex2f(100.7041440705625,293.1347247853005);//I8
    glVertex2f(392.2975205218078,295.2893556457777);//j8
    glVertex2f(375.7786839248161,306.0625099481636);//H8
    glEnd();
}


void mergesense(void)
{
   // glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    if (isRainyDay) {
        glClearColor(70 / 255.0, 100 / 255.0, 120 / 255.0, 1.0); // Dark rainy sky
    } else {
        glClearColor(102 / 255.0, 190 / 255.0, 250 / 255.0, 1.0); // Normal sky color
    }

    glClear(GL_COLOR_BUFFER_BIT); // Apply background color
    drawSky(); // Draw the sky

    if (!isRainyDay) {
        drawSun(); // Draw the sun only if it's NOT raining
    }

    // Draw river with tide animation during rain
    if (isRainyDay) {
        drawRiverWithTideAndFlow(riverFlowOffset);
        drawRain(_rain); // Draw rain effect
    } else {
        drawRiver();
    }


    // Sky and River
    /*drawSky();
    drawRiver();*/
     drawSkyBottom();
    // Boat 1 with animation
    glPushMatrix();
    glTranslated(_boatOne, 0, 0);
    drawBoatOne();
    glPopMatrix();

    // Boat 2 with animation
    glPushMatrix();
    glTranslated(_boatTwo, 0, 0);
    drawBoatTwo();
    glPopMatrix();

    // Boat 3 with animation
    glPushMatrix();
    glTranslated(_boatThree,-100, 0);
    drawBoatThree();
    glPopMatrix();

    // Grass, Shades, Roads, Signals, Zebra-crossing,Building,trees
    drawGrass();
    drawLandShades();
    drawRoads();
    drawRoadSigns();
    drawZebracrossing();
    drawSignals();
    drawBuildings();
    drawTrees();


    //Car 1 with animation
    glPushMatrix();
    glTranslated(_carOne, 5, 0);
    drawCarOne(); //Cars Movement 22-46425-1_011
    glPopMatrix();

    //Car 2
    glPushMatrix();
    glTranslated(_carTwo, -25, 0);
    drawCarTwo();//Cars Movement 22-46425-1_011
    glPopMatrix();

    // Car 3 with animation
    glPushMatrix();
    glTranslated(_carThree, 20, 0);
    //drawCarThree();
    glPopMatrix();

    // Car 4 with animation
    glPushMatrix();
    glTranslated(_carFour, -25, 0);
    drawCarFour(); //Cars Movement 22-46425-1_011
    glPopMatrix();


    // Cloud 1 with Animation
    glPushMatrix();
    glTranslated(_cloudOne, 0, 0);
    drawCloudOne();// Cloud movement 22-46425-1_007
    glPopMatrix();


    // cloud 2 with animation
    glPushMatrix();
    glTranslated(_cloudTwo, 0, 0);
    drawCloudTwo();// Cloud movement 22-46425-1_007
    glPopMatrix();

    // cloud 3 with animation
    glPushMatrix();
    glTranslated(_cloudThree, 0, 0);
    drawCloudThree();// Cloud movement 22-46425-1_007
    glPopMatrix();

    // plane with animation
    glPushMatrix();
    glTranslated(_plane, 0, 0);
    drawPlane();// Plane movement 22-46425-1_008
    glPopMatrix();

    // Bench

    drawBench();
    drawBenchextra();

    // Windmill One with rotating head
    glPushMatrix();
    glTranslatef(487, 910, 0);
    glRotatef(_angle, 0, 0, 1);
    drawWindmillTop(); //Windmill rotation 22-46425-1_009
    glPopMatrix();
    drawWindmillOne();

    // Windmill Two with rotating head
    glPushMatrix();
    glTranslatef(576, 910, 0);
    glRotatef(_angle, 0, 0, 1);
    drawWindmillTop();//Windmill rotation 22-46425-1_009
    glPopMatrix();
    drawWindmillTwo();

    // Windmill Three  with rotating head
    glPushMatrix();
    glTranslatef(653, 910, 0);
    glRotatef(_angle, 0, 0, 1);
    drawWindmillTop();//Windmill rotation 22-46425-1_009
    glPopMatrix();
    drawWindmillThree();

        // Add fence beside the river
    drawFence();
DrawAllComponents();
night();
    star();
    brown_hill();
    Sun();
    plane1();
    plane2();
    fire1();
    fire2();
    tree();
    hill_volkano();
    Tilla_Four();
    house_three();
    Hill_Big_Two();
    Hill_Small_One();
    cloud_three();
    cloud_four();
    Windmill_One();
    Windmill_Two();
    Tilla_One();
    Tilla_Two();
    Tilla_Three();
    house_one();
    cloud_one();
    house2();
    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();
    cloud_two();
    cloud_five();
    cloud_six();
    field();
    Boat();
Grass1();
    Mountain();
    Bulding();
    Leaf();
    Tree();
    Road();
    Roadmarking();
    Roadsidemarking();
    Car();

    Grass();
       Wood();
       drawSun();
       Bench();
       Laftside();
       Laftside1();
       middleside();
       middleside1() ;
       Rightside();
       Rightside1();
       Bench();
        Bench2();
        Bench3();
    if (isSnowing) {
        drawSnow();
    }


    glutSwapBuffers();
}

void playBackgroundSound(const char* soundPath)//Background sound based on mode 22-46425-1_006
 {
    // Stop any currently playing sound
    mciSendString("close mp3", NULL, 0, NULL);

    // Construct command to open the MP3 file
    char command[512];
    sprintf(command, "open \"%s\" type mpegvideo alias mp3", soundPath);
    mciSendString(command, NULL, 0, NULL);

    // Play the MP3 file in a loop
    mciSendString("play mp3 repeat", NULL, 0, NULL);
}


void myMouse(int button, int state, int x, int y)//Mouse interaction for traffic light 22-46425-1_004
 {
    if (state == GLUT_DOWN) { // Detect mouse click
        if (button == GLUT_LEFT_BUTTON) {
            trafficLight = GREEN;  // Change to GREEN (Cars move)
        }
        else if (button == GLUT_MIDDLE_BUTTON) {
            trafficLight = YELLOW; // Change to YELLOW (Cars slow down)
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            trafficLight = RED;    // Change to RED  (Cars stop)
        }
        glutPostRedisplay(); // Update display to show the light change
    }
}



void myKeyboard(unsigned char key, int x, int y)//Keyboard interaction for rainy/normal mode 22-46425-1_005
 {
    switch (key) {
        case 'r': // Enable Rainy Day Mode
            isRainyDay = true;
            playBackgroundSound("C:\\Users\\Asus\\OneDrive\\Desktop\\Documents\\Computer Graphics\\project rainy\\rainy-day.mp3");
            break;

        case 's': // Disable Rainy Day Mode
            isRainyDay = false;
            playBackgroundSound("C:\\Users\\Asus\\OneDrive\\Desktop\\Documents\\Computer Graphics\\project rainy\\Normal day.mp3");
            break;

        case 'e': // Exit program
            mciSendString("close mp3", NULL, 0, NULL); // Stop any playing sound
            exit(0);
            break;

        default:
            break;
    }
}
void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':   //stops boat
        speed = 0.0f;
        break;
    case 'r':   //runs boat
        speed = 0.5f;
        break;
    case 'd':  // Switch to day
        isDay = true;
        glutTimerFunc(16, updateTransition, 0);
        break;
    case 'n':  // Switch to night
        isDay = false;
        glutTimerFunc(16, updateTransition, 0);
        break;
    }
    glutPostRedisplay();
}


void handleMouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON)
    {
        speed += 1.0f;  //mouse left click
    }


    else if (button == GLUT_RIGHT_BUTTON)
    {
        speed -= 1.0f;  //mouse right click
    }
    glutPostRedisplay();
}
void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }

}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'f':
  r(1);
sound();
break;
case 'g':

r(1,1);
break;



case 'i':
    _move = 0.0f;

    break;
case 'o':
    _move = 5.0f;
    break;

    case 'k':
    _move1 = 0.0f;
    break;
case 'l':
    _move1 = 3.0f;

    break;

case 'n':

     updatex();
 condition=true;
    break;

  case 'd':
updatex1();
 condition=false;
    break;

glutPostRedisplay();
	}

	}


void keyboard(unsigned char key, int x, int y) {
    if (key == 'N' || key == 'n') {
        isNight = !isNight; // Toggle night/day
        isSnowing = isNight; // Toggle snow along with night
        if (isSnowing) {
            glutTimerFunc(30, updateSnow, 0); // Start snowfall animation
        }
    } else if (key == 'D' || key == 'd') {
        isNight = !isNight; // Toggle night/day
        isSnowing = isNight; // Toggle snow along with day
    }
    setSkyColor();
    glutPostRedisplay();
}
void update(int value)//All moving animation 22-46425-1_001
{
    _angle += 10.0;
    if (_angle > 360) {
        _angle -= 360;
    }

    if (trafficLight == GREEN) {  // Cars move normally
        _carOne += 3.0;
        if (_carOne > 250) _carOne = -900;

        _carTwo += 5.0;
        if (_carTwo > 950) _carTwo -= 2000;

        _carThree -= 2.0;
        if (_carThree < -640) _carThree = 640;

        _carFour -= 6.0;
        if (_carFour < -740) _carFour = 940;
    }
    else if (trafficLight == YELLOW) {  // Cars move slower
        _carOne += 1.5;
        if (_carOne > 250) _carOne = -900;

        _carTwo += 2.5;
        if (_carTwo > 950) _carTwo -= 2000;

        _carThree -= 1.0;
        if (_carThree < -640) _carThree = 640;

        _carFour -= 3.0;
        if (_carFour < -740) _carFour = 940;
    }
    else {  // RED light, cars stop
        // Cars do not move
    }

    // Boats always move
    _boatOne += 0.80;
    if (_boatOne > 1200) {
        _boatOne -= 1300;
    }

    _boatTwo -= 2.0;
    if (_boatTwo < -900) {
        _boatTwo = 400;
    }

    _boatThree -= 0.90;
    if (_boatThree < -1100) {
        _boatThree = 400;
    }

    // Clouds movement
    _cloudOne -= 3.25;
    if (_cloudOne < -250) {
        _cloudOne = 900;
    }

    _cloudTwo -= 3.20;
    if (_cloudTwo > 1200) {
        _cloudTwo -= 1300;
    }

    _cloudThree -= 3.20;
    if (_cloudThree > 1200) {
        _cloudThree -= 1300;
    }

    // Plane movement
    _plane += 0.70;
    if (_plane > 1200) {
        _plane -= 1300;
    }
if(position <-300.0)
        position = 1500.0f;

    position -= _move;


    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}
void updateTransition(int value) {
    float target = isDay ? 0.0f : 1.0f;
    if (fabs(transitionProgress - target) > 0.001f) {  // Ensures gradual transition
        transitionProgress += (target - transitionProgress) * transitionSpeed;
        glutPostRedisplay();
        glutTimerFunc(16, updateTransition, 0);
    } else {
        transitionProgress = target;  // Ensures exact match with target
    }
}
/Interpolation (scene transitions)
GLubyte lerpColor(GLubyte day, GLubyte night, float t) {
    return day + t * (night - day);
}

void interpolateColor3ub(GLubyte dayR, GLubyte dayG, GLubyte dayB,
                         GLubyte nightR, GLubyte nightG, GLubyte nightB,
                         float t) {
    glColor3ub(lerpColor(dayR, nightR, t),
               lerpColor(dayG, nightG, t),
               lerpColor(dayB, nightB, t));
}

//Boat-1 function 21-45465-3 (21)
void updateB1(int value)
{
    moveB1 += speed;
    if(moveB1 > 3240.0f) moveB1 = -2040.0f;
    glutTimerFunc(10, updateB1, 0);
    glutPostRedisplay();
}

//Boat-2 funciton 21-45465-3 (22)
void updateB2(int value)
{
    moveB2 -= speed;
    if(moveB2 < -3040.0f) moveB2 = 2040.0f;
    glutTimerFunc(10, updateB2, 0);
    glutPostRedisplay();
}
void updatey(int value) {

        y= 8.0f;


    glutPostRedisplay();
    glutTimerFunc(100, updatey, 0);
}
void updatex(int value) {

        x=4.0f;


    glutPostRedisplay();
    glutTimerFunc(100, updatex, 0);
}

void update2(int value) {

    //position2 -= 5;
    if(position2 <-1.3)
    {
        position2 -= _move2;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update2, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update1(int value) {


    if(position1 <-400.0)
        position1 = 1200.0f;

    position1 -= _move1;

	glutPostRedisplay();
	glutTimerFunc(22, update1, 0);
}
bool con(){
return condition=true;
}

float updatex() {





  return   n1=-700,s1=241,s2=240,s3=236;




}
float updatex1() {





  return   n1=1000,s1=0,s2=1,s3=1;


}
void move_right(){


    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(cx>1000){
            cx= -400;

    }
    if(dx>1000){
            dx= -500;

    }


    glutPostRedisplay();
}

void mydisplay()
{
    mergesense();
}

void initRendering(void)
{
   //glClearColor(0.0, 0.0, 1.0, 1.0); // set the bg color to a bright black
    glMatrixMode(GL_PROJECTION);      // set up appropriate matrices-
    gluOrtho2D(0.0, 1050.0, 0.0, 1000.0);
    //gluOrtho2D(-2000,2000,-1200,1200);

}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitWindowSize(1200, 800);
    glutInitWindowSize(1080, 600);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("season change  Scenario");

    initRendering();

    // **Start with normal day sound**
    playBackgroundSound("C:\\Users\\Asus\\OneDrive\\Desktop\\Documents\\Computer Graphics\\project rainy\\Normal day.mp3");

    // **Register callback functions**
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutTimerFunc(25, update, 0);
    glutTimerFunc(20, update, 0);
	glutTimerFunc(20, update1, 0);
	glutTimerFunc(20, update2, 0);

    //glutTimerFunc(100, updatey, 0);
    //glutTimerFunc(100, updatex, 0);
    glutMouseFunc(mouse);
    glutKeyboardFunc(handleKeypress);
init();

    // Animation timers with scaled parameters
    glutTimerFunc(20, updateC, 1);    // Cloud animation
    glutTimerFunc(20, updateB1, 0);   // Boat 1 animation
    glutTimerFunc(20, updateB2, 0);   // Boat 2 animation

    // Input handlers
    glutKeyboardFunc(handleKeypress); // 21-45465-3 (24)
    glutMouseFunc(handleMouse); // 21-45465-3 (25)
    glutKeyboardFunc(keyboard);
    glutTimerFunc(10, update, 0); // Car animation
    glutTimerFunc(30, updateSnow, 0); // Snow animation
    glutMainLoop();
    return 0;
}





