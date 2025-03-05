#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14
using namespace std;
// Declare the traffic light state globally
enum TrafficLightState { RED, YELLOW, GREEN };
TrafficLightState trafficLight = RED; // Default: Red light (cars stop)


using namespace std;

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
//bool riverFlowOffset = false;
/*void drawSky(void)
{
    glBegin(GL_QUADS);
    //glColor3ub(102, 190, 250);
    //glColor3ub(105, 155, 170);
    glColor3ub(102, 190, 250);
    glVertex2i(0, 800);
    glVertex2i(1050, 800);
    glVertex2i(1050, 1000);
    glVertex2i(0, 1000);
    glEnd();
} */

void drawSky(void)
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


void drawSkyBottom(void)
{
    glBegin(GL_QUADS);
    //glColor3ub(30, 86, 49); // Maximum Green
    glColor3ub(85, 107, 47);

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

void drawRiver(void)
{
    glBegin(GL_QUADS);
    //glColor3ub( 90, 130, 255);
    //glColor3ub(135, 206, 235);
    //glColor3ub(0, 191, 255);  // Light blue water color
    //glColor3ub(0, 128, 255);  // A deeper blue
    //glColor3ub(0, 105, 148);  // Ocean water color (deep blue)
     glColor3ub(0, 191, 255);  // Clear shallow water, light blue


    glVertex2i(0, 600);
    glVertex2i(1050, 600);
    glVertex2i(1050, 800);
    glVertex2i(0, 800);
    glEnd();
}

void drawBoatOne(void)
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

void drawBoatTwo(void)
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
void drawBoatThree(void)
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

void drawGrass(void)
{
    glBegin(GL_QUADS);
    //glColor3ub(90, 154, 42); // Green
    //glColor3ub(60, 130, 60);
    //glColor3ub(60, 179, 113); // Medium Sea Green color
    glColor3ub(107, 142, 35); // Olive Drab color

    glVertex2i(0, 220);
    glVertex2i(1050, 220);
    glVertex2i(1050, 600);
    glVertex2i(0, 600);
    glEnd();
}

void drawLandShades(void)
{
    //land shade 1
    glBegin(GL_POLYGON);
    //glColor3ub(45, 139, 87); // Maximum Green
    //glColor3ub(60, 130, 60);
    glColor3ub(107, 142, 35); // Olive Drab color
    glVertex2i(1050, 220);
    glVertex2i(1050, 320);
    glVertex2i(690, 220);
    glEnd();

    // land shade2
    glBegin(GL_POLYGON);
    //glColor3ub(46, 224, 87); // Green
    //glColor3ub(60, 130, 60);
    glColor3ub(107, 142, 35); // Olive Drab color
    glVertex2i(1050, 330);
    glVertex2i(0, 300);
    glVertex2i(0, 650);
    glVertex2i(1050, 380);
    glEnd();

    //land shade 3
    glBegin(GL_POLYGON);
    //glColor3ub(0, 204, 102); // Maximum Green
    //glColor3ub(60, 130, 60);
    glColor3ub(107, 142, 35); // Olive Drab color
    glVertex2i(1050, 620);
    glVertex2i(1050, 500);
    glVertex2i(500, 490);
    glVertex2i(500, 400);
    glEnd();
}

void drawRoads(void)
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
    //glColor3ub(96, 106, 116);
    glColor3ub(96, 78, 56);
    glVertex2i(520, 200);
    glVertex2i(690, 200);
    glVertex2i(480, 600);
    glVertex2i(370, 600);
    glEnd();

    //Road 3
    glBegin(GL_POLYGON);
    //glColor3ub(96, 106, 116);
    glColor3ub(96, 78, 56);
    glVertex2i(0, 600);
    glVertex2i(500, 530);
    glVertex2i(480, 605);
    glVertex2i(0, 630);
    glEnd();
}

void drawRoadSigns(void)
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


void drawCarOne(void)
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

void drawCarTwo(void)
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

void drawCarThree(void)
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
void drawCarFour(void)
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


void drawBuildings(void)
{
    // Left side building (Adjusted to avoid road overlap)
    glBegin(GL_QUADS);
    glColor3ub(150, 150, 150); // Building body
    glVertex2i(50, 200);
    glVertex2i(250, 200);
    glVertex2i(250, 600);
    glVertex2i(50, 600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Windows
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
    glColor3ub(170, 170, 170); // Building body
    glVertex2i(425, 200);
    glVertex2i(625, 200);
    glVertex2i(625, 600);
    glVertex2i(425, 600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Windows
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
    glColor3ub(150, 150, 150); // Building body
    glVertex2i(800, 200);
    glVertex2i(1000, 200);
    glVertex2i(1000, 600);
    glVertex2i(800, 600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Windows
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



void drawCloudOne(void)
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

void drawCloudTwo(void)
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

void drawCloudThree(void)
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

void drawSun(void)
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

void drawSignals(void)
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


void drawBenchextra(void)
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
void drawBench(void)
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

void drawWindmillTop(void)
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

void drawWindmillOne(void)
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

void drawWindmillTwo(void)
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

void drawWindmillThree(void)
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

void drawPlane(void)
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


void drawTree(int x, int y)
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

void drawRain(int value)
{

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
void drawRiverWithTideAndFlow(float flowOffset) {
    float waveHeight = sin(_rain * 10) * 10; // Creates wave-like motion
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex2i(0 + flowOffset, 600 + waveHeight);
    glVertex2i(1050 + flowOffset, 600 + waveHeight);
    glVertex2i(1050 + flowOffset, 800 + waveHeight);
    glVertex2i(0 + flowOffset, 800 + waveHeight);
    glEnd();
}





void myDisplay(void)
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
// Apply global scaling to fit the new larger view
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);  // Scale by factor of 4 (adjust as needed)

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

    // Grass, Shades, Roads, Signals, Zebra-crossing
    drawGrass();
    drawLandShades();
    drawRoads();
    drawRoadSigns();
    drawZebracrossing();
    drawSignals();


    //Car 1 with animation
    glPushMatrix();
    glTranslated(_carOne, 5, 0);
    drawCarOne(); // Car One
    glPopMatrix();

    //Car 2
    glPushMatrix();
    glTranslated(_carTwo, -25, 0);
    drawCarTwo();
    glPopMatrix();

    // Car 3 with animation
    glPushMatrix();
    glTranslated(_carThree, 20, 0);
    //drawCarThree(); // Car three
    glPopMatrix();

    // Car 4 with animation
    glPushMatrix();
    glTranslated(_carFour, -25, 0);
    drawCarFour(); // Car four
    glPopMatrix();

    drawBuildings();
    drawTrees();

    // Cloud 1 with Animation
    glPushMatrix();
    glTranslated(_cloudOne, 0, 0);
    drawCloudOne();
    glPopMatrix();


    // cloud 2 with animation
    glPushMatrix();
    glTranslated(_cloudTwo, 0, 0);
    drawCloudTwo();
    glPopMatrix();

    // cloud 3 with animation
    glPushMatrix();
    glTranslated(_cloudThree, 0, 0);
    drawCloudThree();
    glPopMatrix();

    // plane with animation
    glPushMatrix();
    glTranslated(_plane, 0, 0);
    drawPlane();
    glPopMatrix();

    // Sun and Bench

    drawBench();
    drawBenchextra();

    // Windmill One with rotating head
    glPushMatrix();
    glTranslatef(487, 910, 0);
    glRotatef(_angle, 0, 0, 1);
    drawWindmillTop();
    glPopMatrix();
    drawWindmillOne();

    // Windmill Two with rotating head
    glPushMatrix();
    glTranslatef(576, 910, 0);
    glRotatef(_angle, 0, 0, 1);
    drawWindmillTop();
    glPopMatrix();
    drawWindmillTwo();

    // Windmill Three  with rotating head
    glPushMatrix();
    glTranslatef(653, 910, 0);
    glRotatef(_angle, 0, 0, 1);
    drawWindmillTop();
    glPopMatrix();
    drawWindmillThree();

    // Rain
   // drawRain(_rain);

    glutSwapBuffers();
}

void update(int value)
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

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}


void myMouse(int button, int state, int x, int y) {
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



void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r':
        isRainyDay = true; // Enable rainy day mode
        break;

    case 's':
        isRainyDay = false; // Disable rainy day mode
        break;

    case 'c':
        isRainyDay = !isRainyDay; // Toggle rainy sky color
        break;

    case 'e':
        exit(0); // Exit the program
        break;

    default:
        break;
    }
}

void initRendering(void)
{
    glClearColor(0.0, 0.0, 1.0, 1.0); // set the bg color to a bright black
    glMatrixMode(GL_PROJECTION);      // set up appropriate matrices-
    //gluOrtho2D(0.0, 1050.0, 0.0, 1000.0);
    gluOrtho2D(-2000,2000,-1200,1200);

}

int main(int iArgc, char **cppArgv)
{

    // Menu

   /* cout << "\n::::::::::: Rainy Season Scenario :::::::::::\n\n";
    cout << "Press r for Rainy Day\n";
    cout << "Press s for stopping the Rain\n";
    cout << "Press c for stopping the Rain\n";
    cout << "Press e for exit the program\n";*/


    glutInit(&iArgc, cppArgv);                                // initialize the toolkit
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set the display mode
    //glutInitWindowSize(800, 500);                             // set window size
    glutInitWindowSize(1200, 800);                             // set window size
    glutInitWindowPosition(150, 150);                         // set window upper left corner position on screen
    glutCreateWindow("River Side Scenario");                  // open the screen window
   // Register callback functions



    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutTimerFunc(25, update, 0);
    initRendering(); // additional initializations as necessary
    glutMainLoop();  // go into a endless loop

    return 0;
}

