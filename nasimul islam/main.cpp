#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

#define X_SCALE 80.0f
#define Y_SCALE 72.727f
#define X_OFFSET -2000.0f
#define Y_OFFSET -1200.0f

#define TRANSFORM_X(x) ((x + 12) * X_SCALE + X_OFFSET)
#define TRANSFORM_Y(y) ((y + 19) * Y_SCALE + Y_OFFSET)


float moveC = 0.0f, moveB1 = 0.0f, moveB2 = 0.0f, speed = 2.5f;
bool isDay = true;
float transitionProgress = 0.0f;
float transitionSpeed = 0.03f;
float t=0;

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

//clouds function 21-45465-3 (23)
void updateC(int value) {
    if(moveC > 3300.0f) moveC = -2000.0f;
    moveC += 3.0f;
    glutTimerFunc(10, updateC, 0);
    glutPostRedisplay();
}

void display(void)
{
    DrawAllComponents();
    glutSwapBuffers();
}

void init()
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.45f, 0.63f, 0.89f, 1.0f);  // Daytime sky color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2000, 2000, -1200, 1200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1080, 600);
    glutCreateWindow("Village Scenery");

    init();

    // Animation timers with scaled parameters
    glutTimerFunc(20, updateC, 1);    // Cloud animation
    glutTimerFunc(20, updateB1, 0);   // Boat 1 animation
    glutTimerFunc(20, updateB2, 0);   // Boat 2 animation

    // Input handlers
    glutKeyboardFunc(handleKeypress); // 21-45465-3 (24)
    glutMouseFunc(handleMouse); // 21-45465-3 (25)
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
