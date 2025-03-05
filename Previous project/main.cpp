#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
#define PI 3.1416
#include<cstdio>


float _move = 0.0f; float boatspeed0=.4;//!move_cargoShip_01()
float _move2 = 0.0f; float boatspeed=.4;//!move_boat_()
float _rotateLight = 0.0f; float lightSpeed=.4;//!rotateWT_light()  !rotateLH_light()
float move_truck00 =0.0f;float Truckspeed00= .4f; //!update_truck00()
float move_truck01 =0.0f; float Truckspeed01 = .4;//!update_truck00()
float move_cloud = 0.0f; float Cloudspeed = .2;//!update_cloud

GLfloat position =0.0f; GLfloat speed =0.01f;
GLfloat position2 =0.0f; GLfloat speed2 =0.01f;

void display(int val);


void road() //!_road
{

    //ROAD
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2d(-50.0,-30.0);
        glVertex2d(50.0,-30.0);
        glVertex2d(50.0,-50.0);
        glVertex2d(-50.0,-50.0);
    glEnd();
    //Up-Line
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-32.0);
        glVertex2d(50.0,-32.0);
    glEnd();

    //Middle-Line-1
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-40.0);
        glVertex2d(-40.0,-40.0);
    glEnd();

    //Middle-Line-2
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-38.0,-40.0);
        glVertex2d(-32.0,-40.0);
    glEnd();

    //Middle-Line-3
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-30.0,-40.0);
        glVertex2d(-20.0,-40.0);
    glEnd();

    //Middle-Line-4
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-18.0,-40.0);
        glVertex2d(-12.0,-40.0);
    glEnd();

    //Middle-Line-5
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-10.0,-40.0);
        glVertex2d(-0.0,-40.0);
    glEnd();

    //Middle-Line-6
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(2.0,-40.0);
        glVertex2d(8.0,-40.0);
    glEnd();

    //Middle-Line-7
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(10.0,-40.0);
        glVertex2d(20.0,-40.0);
    glEnd();

    //Middle-Line-8
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(22.0,-40.0);
        glVertex2d(28.0,-40.0);
    glEnd();

    //Middle-Line-9
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(30.0,-40.0);
        glVertex2d(40.0,-40.0);
    glEnd();

    //Middle-Line-10
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(42.0,-40.0);
        glVertex2d(50.0,-40.0);
    glEnd();

    //Down-Line
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-48.0);
        glVertex2d(50.0,-48.0);
    glEnd();
    //Road End
}

void sand()
{
    glBegin(GL_POLYGON);

    glVertex2f(-50.0f, -30.0f);
    glVertex2f(50.0f, -30.0f);
    glVertex2f(50.0f, -10.0f);
    glVertex2f(-50.0f, -10.0f);
    glEnd();
}


void ocean()
{
    glBegin(GL_POLYGON);
    glVertex2f(-50.0f, -10.0f);
    glVertex2f(50.0f, -10.0f);
    glVertex2f(50.0f, 20.0f);
    glVertex2f(-50.0f, 20.0f);
    glEnd();

}

void tide()
{
    glPushMatrix();
    glTranslatef(_move, 0, 1);
    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2f(-30.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(10.0f, -.5f);
    glVertex2f(-30.0f, -.5f);
    glEnd();

    glPopMatrix();
}

void tideNight()
{
    glPushMatrix();
    glTranslatef(_move, 0, 1);
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-30.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(10.0f, -0.5f);
    glVertex2f(-30.0f, -0.5f);
    glEnd();

    glPopMatrix();
}



void sky()
{
    glBegin(GL_POLYGON);
    glVertex2f(-50.0f, 20.0f);
    glVertex2f(50.0f, 20.0f);
    glVertex2f(50.0f, 50.0f);
    glVertex2f(-50.0f, 50.0f);
    glEnd();
}

void sun()
{
    glPushMatrix();
    //glTranslatef(_move, 0, 0);
    glColor3ub(255,208,0);
    glScalef(0.5, 0.5, 0);
    glTranslatef(20, 45, 0);

            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=10;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y+20);
            }
            glEnd();

    glPopMatrix();

}


void cloud()  ///Farzana
{

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+40,y+40);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+40.5,y+40.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+42,y+42);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+42.5,y+42.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+43,y+40);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+44.5,y+40.2);
        }
        glEnd();


}
void cloud2()
{
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-43,y+40);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-42.5,y+40.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-41,y+42);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-40.5,y+42.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-40,y+39.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-38.5,y+40.2);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-38.5,y+42.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-37.5,y+42.5);
        }
        glEnd();



}

void cloud3()
{
       glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+0,y+36);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+0.5,y+36.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2,y+38);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.5,y+38.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3,y+36);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+4.5,y+36.2);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+4.8,y+38.5);
        }
        glEnd();
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+5.5,y+39);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+6.5,y+36.2);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+7.5,y+36.5);
        }
        glEnd();

}

void cloud4()
{
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-22,y+36);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-21.5,y+36.8);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-19,y+37.5);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-19,y+36);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-17,y+38);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(211, 211, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-16,y+36);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-14.5,y+36.5);
        }
        glEnd();


}

void cloud_01() //cloud
{
    glPushMatrix();
    glTranslatef(move_cloud, 0, 0);
    cloud();
    cloud2();
    cloud3();
    cloud4();
    glPopMatrix();
}


void move_cloud_01 (int value)
{

    move_cloud += Cloudspeed;

    if(move_cloud > 55)
    {
        move_cloud = -55;
    }

	glutPostRedisplay();

	glutTimerFunc(20, move_cloud_01, 0);
}




void star()
{
    glBegin(GL_POLYGON);
    glColor3ub(255, 255,255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();


}

void circle(float radiusX, float radiusY)
{
    int i;
    float angle=0.0;
    glBegin(GL_POLYGON);
        for(i=0; i<100; i++){
            angle=2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));
        }
        glEnd();
}




void circle()
{

            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++)
            {
                glColor3ub(226, 223, 210);
                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=10;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y+20);
            }
            glEnd();
}


void Umbrella()
{

        glPushMatrix();
    glScalef(48, 48, 0);
    glBegin(GL_QUADS);
    glColor3ub(156, 156, 161);

    glVertex2f(-0.01, -0.6f);
    glVertex2f(0.01, -0.6f);
    glVertex2f(0.01, -0.9f);
    glVertex2f(-0.01, -0.9f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 203, 66);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 105, 66);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(24, 161, 26);
    glVertex2f(-0.13,-0.64);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(82, 235, 212);
    glVertex2f(-0.18,-0.63);
    glVertex2f(-0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(232, 9, 9);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(179, 2, 219);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 51, 219);
    glVertex2f(-0.21,-0.62);
    glVertex2f(-0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(142, 136, 148);
    glVertex2f(-0.23,-0.61);
    glVertex2f(-0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(117, 118, 128);
    glVertex2f(0.23,-0.61);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glPopMatrix();


}

void Seat()
{

    glPushMatrix();
    glTranslatef(0, 20, 0);
    glScalef(70, 70, 0);

    glBegin(GL_QUADS);
    glColor3ub(150, 124, 45);
    glVertex2f(0.13, -0.83f);
    glVertex2f(0.15, -0.83f);
    glVertex2f(0.15, -0.86f);
    glVertex2f(0.13, -0.866f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(171, 151, 89);
    glVertex2f(0.09, -0.83f);
    glVertex2f(0.16, -0.83f);
    glVertex2f(0.08, -0.88f);
    glVertex2f(0.02, -0.88f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(150, 124, 45);
    glVertex2f(0.02, -0.8f);
    glVertex2f(0.08, -0.8f);
    glVertex2f(0.08, -0.9f);
    glVertex2f(0.02, -0.9f);
    glEnd();
    glPopMatrix();


}

void crab(){

    glBegin(GL_POLYGON); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.4f,0.1f);
    glVertex2f(0.44f,0.1f);
    glVertex2f(0.46f,0.15f);
    glVertex2f(0.44f,0.18f);
    glVertex2f(0.4f,0.18f);
    glVertex2f(0.38f,0.15f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.44f,0.18f);
    glVertex2f(0.47f,0.2f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.47f,0.2f);
    glVertex2f(0.49f,0.16f);
    glEnd();

    glBegin(GL_LINES); //CRAB
     glColor3ub(220,88,33);
    glVertex2f(0.46f,0.15f);
    glVertex2f(0.48f,0.17f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.48f,0.17f);
    glVertex2f(0.5f,0.13f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.45f,0.13f);
    glVertex2f(0.47f,0.15f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.47f,0.15f);
    glVertex2f(0.49f,0.11f);
    glEnd();

    glBegin(GL_LINES); //CRAB
     glColor3ub(220,88,33);
    glVertex2f(0.44f,0.1f);
    glVertex2f(0.46f,0.12f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.46f,0.12f);
    glVertex2f(0.48f,0.08f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.4f,0.18f);
    glVertex2f(0.38f,0.2f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.38f,0.2f);
    glVertex2f(0.36f,0.16f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.38f,0.15f);
    glVertex2f(0.36f,0.17f);
     glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.34f,0.13f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.4f,0.1f);
    glVertex2f(0.38f,0.12f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.38f,0.12f);
    glVertex2f(0.36f,0.08f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.39f,0.13f);
    glVertex2f(0.37f,0.14f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
     glVertex2f(0.37f,0.14f);
    glVertex2f(0.35f,0.1f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.445f,0.17f);
    glVertex2f(0.475f,0.19f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.475f,0.19f);
    glVertex2f(0.485f,0.16f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.39f,0.17f);
    glVertex2f(0.37f,0.19f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.37f,0.19f);
    glVertex2f(0.35f,0.16f);
    glEnd();

    glPointSize(3.00);
    glBegin(GL_POINTS);
    glColor3ub(31,31,27);
    glVertex2f(0.41f,0.16f);
    glVertex2f(0.43f,0.16f);
    glEnd();

    glBegin(GL_POLYGON); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.2f,0.1f);
    glVertex2f(0.25f,0.1f);
    glVertex2f(0.27f,0.15f);
    glVertex2f(0.25f,0.2f);
    glVertex2f(0.2f,0.2f);
    glVertex2f(0.18f,0.15f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.25f,0.19f);
    glVertex2f(0.27f,0.20f);
    glEnd();

    glBegin(GL_LINES); //CRAB
     glColor3ub(220,88,33);
    glVertex2f(0.27f,0.20f);
    glVertex2f(0.29f,0.15f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.25f,0.20f);
    glVertex2f(0.27f,0.21f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.27f,0.21f);
    glVertex2f(0.29f,0.18f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.26f,0.14f);
    glVertex2f(0.28f,0.16f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.28f,0.16f);
    glVertex2f(0.30f,0.12f);
    glEnd();

     glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.26f,0.17f);
    glVertex2f(0.28f,0.18f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.28f,0.18f);
    glVertex2f(0.30f,0.16f);
    glEnd();

    glBegin(GL_LINES); //CRAB
    glColor3ub(220,88,33);
    glVertex2f(0.25f,0.10f);
    glVertex2f(0.27f,0.12f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);
    glVertex2f(0.27f,0.12f);//CRAB
    glVertex2f(0.29f,0.10f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);
    glVertex2f(0.17f,0.16f);//CRAB
    glVertex2f(0.19f,0.14f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.17f,0.16f);
    glVertex2f(0.15f,0.12f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.17f,0.19f);
    glVertex2f(0.21f,0.11f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.17f,0.19f);
    glVertex2f(0.14f,0.13f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.20f,0.19f);
    glVertex2f(0.17f,0.22f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.17f,0.22f);
     glVertex2f(0.15f,0.17f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.17f,0.13f);
    glVertex2f(0.20f,0.11f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.17f,0.13f);
    glVertex2f(0.15f,0.12f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.20f,0.10f);
    glVertex2f(0.17f,0.12f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(220,88,33);//CRAB
    glVertex2f(0.17f,0.12f);
    glVertex2f(0.15f,0.10f);
    glEnd();

    glPointSize(3.00);
    glBegin(GL_POINTS);
    glColor3ub(31,31,27);
    glVertex2f(0.24f,0.16f);
    glVertex2f(0.21f,0.16f);
    glEnd();

}


void cargoShip() //!_ship_joy
{

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!cargo ship structure
    glBegin(GL_POLYGON);
    glColor3ub (9, 9, 29);
    glVertex2f(-5,2);
    glVertex2f(25,2);
    glVertex2f(29,6);
    glVertex2f(-5,6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (255, 69, 0);
    glVertex2f(-4,0);
    glVertex2f(23,0);
    glVertex2f(25,2);
    glVertex2f(-5,2);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub (133, 133, 133);
    glVertex2f(2,4);
    glVertex2f(25,4);
    glVertex2f(27,6);
    glVertex2f(2,6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (0, 30, 0);
    glVertex2f(-5,6);
    glVertex2f(2,6);
    glVertex2f(2,11);
    glVertex2f(-5,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (20,0,39);
    glVertex2f(-4,11);
    glVertex2f(2,11);
    glVertex2f(2,13);
    glVertex2f(-4,13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (20,0,39);
    glVertex2f(0,13);
    glVertex2f(2,13);
    glVertex2f(2,18);
    glVertex2f(0,18);
    glEnd();

    glPushMatrix();
    glTranslatef(-2.5, 0 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (20,0,39);
    glVertex2f(0,13);
    glVertex2f(2,13);
    glVertex2f(2,18);
    glVertex2f(0,18);
    glEnd();
    glPopMatrix();

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!windowwwws
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();

    glPushMatrix();
    glTranslatef(1.5, 0 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 0 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    //!!!!!!!!!!!!!!!!!! windows 2nd row
    glPushMatrix();
    glTranslatef(0, 2 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 2 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 2 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!end of cargo ship structure

    //!container column-01
    glPushMatrix();
    glColor3ub(0, 0, 52);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 2, 0);
    glColor3ub(77, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glColor3ub(77, 50, 0);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4, 0);
    glColor3ub(205,102,0);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    //!column-02
    glPushMatrix();
    glTranslatef(5.5, 0, 0);
    glColor3ub(255,171,87);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(8, 2, 0);
    glColor3ub(255,87,87);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.5, 4, 0);
    glColor3ub(255,0,87);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    //!column-03
    glPushMatrix();
    glTranslatef(11, 0, 0);
    glColor3ub(128, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16, 0, 0);
    glColor3ub(109, 218, 111);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(13, 2, 0);
    glColor3ub(10,0,20);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14, 4, 0);
    glColor3ub(91, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18, 2, 0);
    glColor3ub(255,255,26);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();


    //!!!!!!crane
    glPushMatrix();
    glTranslatef(26.5, 6, 0);
    glScalef(1.5, 2, 0);

    //!!!!##################################### crane Body structure
    glBegin(GL_POLYGON);
    glColor3ub (51, 51, 51);
    glVertex2f(-1,0);
    glVertex2f(1,0);
    glVertex2f(1,.5);
    glVertex2f(-1,.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (51, 51, 51);
    glVertex2f(-.5,.5);
    glVertex2f(.5,.5);
    glVertex2f(.5,4);
    glVertex2f(-.5,4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (51, 51, 51);
    glVertex2f(-.2, 4);
    glVertex2f(.2, 4);
    glVertex2f(.2, 8);
    glVertex2f(-.2, 8);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub (63, 0, 0);
    glVertex2f(0, 6);
    glVertex2f(-4, 8);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub (63, 0, 0);
    glVertex2f(0, 2);
    glVertex2f(-4, 8);
    glEnd();

//!!!!!!!!!!end of crane body structure


    glPopMatrix();

}


void cargoShip_night()//!_ship02
{
    glPushMatrix();
    glTranslatef(_move, 0, 0);
    glTranslatef(10, 15, 0);
    cargoShip();
    glPopMatrix();

    glPopMatrix();
}


void move_boat(int value) //!_ship01_
{

    _move += boatspeed;

    if(_move > 55)
    {
        _move = -55;
    }

	glutPostRedisplay();

	glutTimerFunc(20, move_boat, 0);
}


void move_cargoShip_night (int value) //!_ship02_
{

    _move2 += boatspeed;
    if(_move2 > 55)
    {
        _move2 = -55;
    }

	glutPostRedisplay();

	glutTimerFunc(20, move_cargoShip_night, 0);
}




void flagship() ///joy
{
glPushMatrix();
glTranslatef(position, 0, 0);
glBegin(GL_QUADS);
glColor3ub(173, 71, 7);
glVertex2f(0.3f, -0.9f);
glVertex2f(0.8f, -0.9f);
glVertex2f(1.0f, -0.6f);
glVertex2f(0.1f, -0.6f);
glEnd();
glBegin(GL_QUADS);//1st row
glColor3ub(37,19,15);
glVertex2f(0.21f, -0.6f);
glVertex2f(0.9f, -0.6f);
glVertex2f(0.9f, -0.5f);
glVertex2f(0.21f, -0.5f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(45,45,45);//2nd row
glVertex2f(0.25f, -0.5f);
glVertex2f(0.83f, -0.5f);
glVertex2f(0.83f, -0.4f);
glVertex2f(0.25f, -0.4f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(0.0,0.0,0.0);//1st piller
glVertex2f(0.31f, -0.22f);
glVertex2f(0.39f, -0.22f);
glVertex2f(0.39f, -0.40f);
glVertex2f(0.31f, -0.40f);
glEnd();
glBegin(GL_QUADS); //2nd piller
glColor3ub(0.0,0.0,0.0);
glVertex2f(0.45f, -0.22f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.52f, -0.40f);
glVertex2f(0.45f, -0.40f);
glEnd();
glBegin(GL_QUADS);//3rd piller
glColor3ub(0.0,0.0,0.0);
glVertex2f(0.56f, -0.22f);
glVertex2f(0.62f, -0.22f);
glVertex2f(0.62f, -0.40f);
glVertex2f(0.56f, -0.40f);
glEnd();
glBegin(GL_QUADS);//4th piller
glColor3ub(0.0,0.0,0.0);
glVertex2f(0.66f, -0.22f);
glVertex2f(0.73f, -0.22f);
glVertex2f(0.73f, -0.40f);
glVertex2f(0.66f, -0.40f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(247,247,247);//1st piller_white part
glVertex2f(0.31f, -0.22f);
glVertex2f(0.39f, -0.22f);
glVertex2f(0.39f, -0.17f);
glVertex2f(0.31f, -0.17f);
glEnd();
glBegin(GL_QUADS); //2nd piller_white part
glColor3ub(247,247,247);
glVertex2f(0.45f, -0.22f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.52f, -0.17f);
glVertex2f(0.45f, -0.17f);
glEnd();
glBegin(GL_QUADS);//3rd piller_white part
glColor3ub(247,247,247);
glVertex2f(0.56f, -0.22f);
glVertex2f(0.62f, -0.22f);
glVertex2f(0.62f, -0.17f);
glVertex2f(0.56f, -0.17f);
glEnd();
glBegin(GL_QUADS);//4th piller_white part
glColor3ub(247,247,247);
glVertex2f(0.66f, -0.22f);
glVertex2f(0.73f, -0.22f);
glVertex2f(0.73f, -0.17f);
glVertex2f(0.66f, -0.17f);
glEnd();
glBegin(GL_QUADS);//piller brown
glColor3ub(654,52,52);
glVertex2f(0.17f, -0.6f);
glVertex2f(0.20f, -0.6f);
glVertex2f(0.20f, -0.0f);
glVertex2f(0.17f, -0.0f);
glEnd();
glBegin(GL_QUADS);//pileer-violet
glColor3ub(145,145,145);
glVertex2f(0.19f, -0.0f);
glVertex2f(0.21f,-0.0f);
glVertex2f(0.21f, -0.6f);
glVertex2f(0.19f, -0.6f);
glEnd();
glBegin(GL_TRIANGLES);//Flag
glColor3ub(247,5,3);
glVertex2f(-0.01f, -0.4);
glVertex2f(0.17f, -0.4f);
glVertex2f(0.17f, -0.01f);
glEnd();
glBegin(GL_QUADS);//1st ship window
glColor3ub(247,247,247);
glVertex2f(0.22f, -0.58f);
glVertex2f(0.28f, -0.58f);
glVertex2f(0.28f, -0.53f);
glVertex2f(0.22f, -0.53f);
glEnd();
glBegin(GL_QUADS);//2nd row WINDOW
glColor3ub(247,247,247);
glVertex2f(0.40f, -0.58f);
glVertex2f(0.34f, -0.58f);
glVertex2f(0.34f, -0.53f);
glVertex2f(0.40f, -0.53f);
glEnd();
glBegin(GL_QUADS);//3rd shipWINDOW
glColor3ub(247,247,247);
glVertex2f(0.51f, -0.58f);
glVertex2f(0.45f, -0.58f);
glVertex2f(0.45f, -0.53f);
glVertex2f(0.51f, -0.53f);
glEnd();
glBegin(GL_QUADS);//4th ship window
glColor3ub(247,247,247);
glVertex2f(0.55f, -0.58f);
glVertex2f(0.61f, -0.58f);
glVertex2f(0.61f, -0.53f);
glVertex2f(0.55f, -0.53f);
glEnd();
glBegin(GL_QUADS);//5th window
glColor3ub(247,247,247);
glVertex2f(0.65f, -0.58f);
glVertex2f(0.71f, -0.58f);
glVertex2f(0.71f, -0.53f);
glVertex2f(0.65f, -0.53f);
glEnd();
glBegin(GL_QUADS);//6th window
glColor3ub(247,247,247);
glVertex2f(0.85f, -0.58f);
glVertex2f(0.77f, -0.58f);
glVertex2f(0.77f, -0.53f);
glVertex2f(0.85f, -0.53f);
glEnd();
glPopMatrix();


}



void update(int value) {
if(position > 4.6)
position = -2.0f;
position += speed;
glutPostRedisplay();
glutTimerFunc(50, update, 0);
}



void watchTower_Night() //!_WT_Night_joy
{

        //!!#############################translate
        glPushMatrix();
        glTranslatef(34, -15, 0);

        //!!####################scaling
        glPushMatrix();
        glScalef(2, 2, 0);

        //!############################body
        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(5.0f, 10.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 9.0f);
        glVertex2f(5.0f, 9.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 8.0f);
        glVertex2f(5.0f, 8.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(0.0f, 4.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(4.0f, 4.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(5.0f, 10.0f);
        glVertex2f(5.0f, 10.0f);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(-1.0f, 6.0f);
        glEnd();

        //!#####################################Main_body_Struct
        glBegin(GL_QUADS);
        glColor3ub(20, 13, 0);
        glVertex2f(0, -4.0f);
        glVertex2f(4.0f, -4.0f);
        glVertex2f(4.0f, 10.0f);
        glVertex2f(0.0f, 10.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();

        glPushMatrix();
        glTranslatef(0,2,0);
        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,4,0);
        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();

        //!##############################lightBox
        glBegin(GL_POLYGON);
        glColor3d(1,1,1);
        glVertex2f(1, 12.0f);
        glVertex2f(2, 12.0f);
        glVertex2f(2, 13.0f);
        glVertex2f(1, 13.0f);
        glEnd();

        //!###############################light
        glPushMatrix();
        glTranslated(1.5, 12.5, 0);
        glRotatef(_rotateLight, 0.0f, 1.0f, 1.0f);   //!################light rotate

        //!###############################light1
        glBegin(GL_POLYGON);
        glColor3d(1,0,0);
        glVertex2f(0, 0);
        glVertex2f(10.0f, -2.0f);
        glVertex2f(10.0f, 2.0f);
        glEnd();

        //!###############################light2
        glBegin(GL_POLYGON);
        glColor3d(1,0,0);
        glVertex2f(0, 0);
        glVertex2f(-10.0f, -2.0f);
        glVertex2f(-10.0f, 2.0f);
        glEnd();

        glPopMatrix();//!rotate




        //!#################################helmet
        glBegin(GL_POLYGON);
        glColor3ub(0, 108, 54);
        glVertex2f(-1, 13.0f);
        glVertex2f(5.0f, 13.0f);
        glVertex2f(2.0f, 16.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(0, 13.0f);
        glVertex2f(0, 10.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(4, 13.0f);
        glVertex2f(4, 10.0f);
        glEnd();


        glPopMatrix(); //!scale

        glPopMatrix(); //!translate



}


void watchTower() //!_WT
{

        //!!#############################translate
        glPushMatrix();
        glTranslatef(-45, -15, 0);

        //!!####################scaling
        glPushMatrix();
        glScalef(2, 2, 0);

        //!############################body
        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(5.0f, 10.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 9.0f);
        glVertex2f(5.0f, 9.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 8.0f);
        glVertex2f(5.0f, 8.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(0.0f, 4.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(4.0f, 4.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(5.0f, 10.0f);
        glVertex2f(5.0f, 10.0f);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(-1.0f, 6.0f);
        glEnd();

        //!#####################################Main_body_Struct
        glBegin(GL_QUADS);
        glColor3ub(210,255,77);
        glVertex2f(0, -4.0f);
        glVertex2f(4.0f, -4.0f);
        glVertex2f(4.0f, 10.0f);
        glVertex2f(0.0f, 10.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();

        glPushMatrix();
        glTranslatef(0,2,0);
        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,4,0);
        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();

        //!##############################lightBox
        glBegin(GL_POLYGON);
        glColor3d(1,1,1);
        glVertex2f(1, 12.0f);
        glVertex2f(2, 12.0f);
        glVertex2f(2, 13.0f);
        glVertex2f(1, 13.0f);
        glEnd();





        //!#################################helmet
        glBegin(GL_POLYGON);
        glColor3ub(0, 108, 54);
        glVertex2f(-1, 13.0f);
        glVertex2f(5.0f, 13.0f);
        glVertex2f(2.0f, 16.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(0, 13.0f);
        glVertex2f(0, 10.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(4, 13.0f);
        glVertex2f(4, 10.0f);
        glEnd();
        glPopMatrix(); //!scale
        glPopMatrix(); //!translate

}



void rotateWT_light(int value)  //!_WT_
 {

    _rotateLight -= lightSpeed;

    if(_rotateLight < -360.0)
    {
        _rotateLight+=360;
    }

    glutPostRedisplay();

    glutTimerFunc(20, rotateWT_light, 0);
}




void truck00() //!_truck00_joy
{
    //Car Moving-1
    glPushMatrix();
    glTranslatef(move_truck00,0.0,0.0);

    glColor3f(1.0f,0.30f,0.30f);//Front side
    glBegin(GL_POLYGON);
        glVertex2d(-21.0,-29.0);
        glVertex2d(-18.0,-29.0);
        glVertex2d(-17.0,-32.0);
        glVertex2d(-17.0,-37.0);
        glVertex2d(-21.0,-37.0);
    glEnd();
    glColor3f(0.94f,0.94f,0.94f);//Mirror
    glBegin(GL_QUADS);
        glVertex2d(-20.6,-29.6);
        glVertex2d(-18.2,-29.6);
        glVertex2d(-17.4,-32.0);
        glVertex2d(-20.6,-32.0);
    glEnd();

    glColor3f(1.0f,0.30f,0.30f);//Back Side
    glBegin(GL_QUADS);
        glVertex2d(-33.0,-35.0);
        glVertex2d(-21.0,-35.0);
        glVertex2d(-21.0,-37.0);
        glVertex2d(-33.0,-37.0);
    glEnd();
    glColor3f(0.0f,0.90f,0.30f);//Container
    glBegin(GL_QUADS);
        glVertex2d(-33.0,-29.0);
        glVertex2d(-21.5,-29.0);
        glVertex2d(-21.5,-35.0);
        glVertex2d(-33.0,-35.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f); ///container lines
    glBegin(GL_LINES);
        glVertex2d(-31.5,-29.0);
        glVertex2d(-31.5,-35.0);
        glVertex2d(-30.5,-29.0);
        glVertex2d(-30.5,-35.0);
        glVertex2d(-29.5,-29.0);
        glVertex2d(-29.5,-35.0);
        glVertex2d(-28.5,-29.0);
        glVertex2d(-28.5,-35.0);
        glVertex2d(-27.5,-29.0);
        glVertex2d(-27.5,-35.0);
        glVertex2d(-26.5,-29.0);
        glVertex2d(-26.5,-35.0);
        glVertex2d(-25.5,-29.0);
        glVertex2d(-25.5,-35.0);
        glVertex2d(-24.5,-29.0);
        glVertex2d(-24.5,-35.0);
        glVertex2d(-23.5,-29.0);
        glVertex2d(-23.5,-35.0);
        glVertex2d(-22.5,-29.0);
        glVertex2d(-22.5,-35.0);
    glEnd();

    glPushMatrix();//Chaka-1
    glTranslatef(-19.0,-36.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2, 2.3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-19.0,-36.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();
    glPushMatrix();//Chaka-2
    glTranslatef(-31.0,-36.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-31.0,-36.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();

    glPopMatrix();

    //Car Moving-1 End


}


void truck01()  //!_truck01
{
        //Car Moving-2
    glPushMatrix();
    glTranslatef(move_truck01,0.0,0.0);
    glColor3f(1.0f,0.30f,0.0f);//Front side
    glBegin(GL_POLYGON);
    glVertex2d(18.0,-37.0);
    glVertex2d(21.0,-37.0);
    glVertex2d(21.0,-45.0);
    glVertex2d(17.0,-45.0);
    glVertex2d(17.0,-40.0);
    glEnd();

    glColor3f(0.94f,0.94f,0.94f);//Mirror
    glBegin(GL_QUADS);
    glVertex2d(18.2,-37.6);
    glVertex2d(20.6,-37.6);
    glVertex2d(20.6,-40.0);
    glVertex2d(17.4,-40.0);
    glEnd();

    glColor3f(1.0f,0.30f,0.0f);//Back Side
    glBegin(GL_QUADS);
    glVertex2d(21.0,-43.0);
    glVertex2d(32.0,-43.0);
    glVertex2d(32.0,-45.0);
    glVertex2d(21.0,-45.0);
    glEnd();

    glColor3f(0.30f,0.58f,1.0f);//Container
    glBegin(GL_QUADS);
    glVertex2d(21.5,-37.0);
    glVertex2d(32.0,-37.0);
    glVertex2d(32.0,-43.0);
    glVertex2d(21.5,-43.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(22.0,-37.0);
        glVertex2d(22.0,-43.0);
        glVertex2d(23.0,-37.0);
        glVertex2d(23.0,-43.0);
        glVertex2d(24.0,-37.0);
        glVertex2d(24.0,-43.0);
        glVertex2d(25.0,-37.0);
        glVertex2d(25.0,-43.0);
        glVertex2d(26.0,-37.0);
        glVertex2d(26.0,-43.0);
        glVertex2d(27.0,-37.0);
        glVertex2d(27.0,-43.0);
        glVertex2d(28.0,-37.0);
        glVertex2d(28.0,-43.0);
        glVertex2d(29.0,-37.0);
        glVertex2d(29.0,-43.0);
        glVertex2d(30.0,-37.0);
        glVertex2d(30.0,-43.0);
        glVertex2d(31.0,-37.0);
        glVertex2d(31.0,-43.0);
    glEnd();

    glPushMatrix();//Chaka-1
    glTranslatef(19.0,-44.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.0,-44.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();

    glPushMatrix();//Chaka-2
    glTranslatef(30.0,-44.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30.0,-44.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();

    glPopMatrix();
    //Car Moving-2 End

}



void update_truck00(int value)  //!_truck00_
{

    if(move_truck00 > 75) ///screen size
    {
        move_truck00 = -55;
    }

    move_truck00 += Truckspeed00;
    glutPostRedisplay();

	glutTimerFunc(20, update_truck00, 0);

}

void update_truck01(int value)  //!_truck01_
{

    if(move_truck01 < -75)
    {
        move_truck01 = 55;
    }

	        move_truck01 -= Truckspeed01;
    glutPostRedisplay();

	glutTimerFunc(20, update_truck01, 0);

}


void lightHouse_Night() //!_lightHouse_night
{
    glPushMatrix();  //!scaling
    glTranslated(-40, 21.5, 0);
    glScalef(1.5,1.5,0);

    /*
    glPushMatrix(); //!light_reftect
    glTranslatef(0, 13, 0);
    glColor3ub(240,250,210);
    circle(3.5, 3.5);
    glPopMatrix();
    */

    glBegin(GL_POLYGON); //!################pillar
    glColor3ub(250, 249, 246);
    glVertex2f(-2, 0);
    glVertex2f(2, 0);
    glVertex2f(1.5, 10);
    glVertex2f(-1.5, 10);
    glEnd();

    glBegin(GL_POLYGON);    //!################pillar_shade_half
    glColor3ub(255, 255, 255);
    glVertex2f(-2, 0);
    glVertex2f(0, 0);
    glVertex2f(0, 10);
    glVertex2f(-1, 10);
    glEnd();

    glBegin(GL_POLYGON);    //!################upperB
    glColor3ub(150, 0, 0);
    glVertex2f(-1.5, 10);
    glVertex2f(1.5, 10);
    glVertex2f(1.5, 14);
    glVertex2f(-1.5, 14);
    glEnd();

    glBegin(GL_POLYGON); //!################Divider
    glColor3ub(0, 0, 0);
    glVertex2f(-2, 10);
    glVertex2f(2, 10);
    glVertex2f(2, 11);
    glVertex2f(-2, 11);
    glEnd();

    glBegin(GL_POLYGON); //!################helmet
    glColor3ub(0, 0, 0);
    glVertex2f(-2, 14);
    glVertex2f(2, 14);
    glVertex2f(0, 16);
    glEnd();

    glBegin(GL_POLYGON);    //!################lightBox
    glColor3ub(0, 0, 0);
    glVertex2f(-.5, 10);
    glVertex2f(.5, 10);
    glVertex2f(.5, 14);
    glVertex2f(-.5, 14);
    glEnd();

    glPushMatrix(); //!light
    glTranslatef(0, 12.5, 0);
    glColor3ub(245, 245, 164);
    circle(.5, .5);
    glPopMatrix();

    glPushMatrix();
    glRotatef(_rotateLight, 0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);    //!################light_shade
    glColor3ub(245, 245, 164);
    glVertex2f(15, 10);
    glVertex2f(1.5, 12);
    glVertex2f(1.5, 13);
    glVertex2f(15, 15);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);    //!################stand
    glColor3ub(0, 0, 0);
    glVertex2f(-3, -1);
    glVertex2f(3, -1);
    glVertex2f(2, 0);
    glVertex2f(-2, 0);
    glEnd();


    glPopMatrix(); //!scaling


}

void lightHouse() //!_lightHouse
{
    glPushMatrix();  //!scaling
    glTranslated(-40, 21.5, 0);
    glScalef(1.5,1.5,0);


    glBegin(GL_POLYGON); //!################pillar
    glColor3ub(250, 249, 246);
    glVertex2f(-2, 0);
    glVertex2f(2, 0);
    glVertex2f(1.5, 10);
    glVertex2f(-1.5, 10);
    glEnd();

    glBegin(GL_POLYGON);    //!################pillar_shade_half
    glColor3ub(255, 255, 255);
    glVertex2f(-2, 0);
    glVertex2f(0, 0);
    glVertex2f(0, 10);
    glVertex2f(-1, 10);
    glEnd();

    glBegin(GL_POLYGON);    //!################upperB
    glColor3ub(150, 0, 0);
    glVertex2f(-1.5, 10);
    glVertex2f(1.5, 10);
    glVertex2f(1.5, 14);
    glVertex2f(-1.5, 14);
    glEnd();

    glBegin(GL_POLYGON); //!################Divider
    glColor3ub(0, 0, 0);
    glVertex2f(-2, 10);
    glVertex2f(2, 10);
    glVertex2f(2, 11);
    glVertex2f(-2, 11);
    glEnd();

    glBegin(GL_POLYGON); //!################helmet
    glColor3ub(0, 0, 0);
    glVertex2f(-2, 14);
    glVertex2f(2, 14);
    glVertex2f(0, 16);
    glEnd();

    glBegin(GL_POLYGON);    //!################lightBox
    glColor3ub(0, 0, 0);
    glVertex2f(-.5, 10);
    glVertex2f(.5, 10);
    glVertex2f(.5, 14);
    glVertex2f(-.5, 14);
    glEnd();

    glPushMatrix(); //!light
    glTranslatef(0, 12.5, 0);
    glColor3ub(245, 245, 164);
    circle(.5, .5);
    glPopMatrix();


    glBegin(GL_POLYGON);    //!################stand
    glColor3ub(0, 0, 0);
    glVertex2f(-3, -1);
    glVertex2f(3, -1);
    glVertex2f(2, 0);
    glVertex2f(-2, 0);
    glEnd();


    glPopMatrix(); //!scaling


}


void rotateLH_light(int value)  ///_LightHouse_
 {



    _rotateLight -= lightSpeed;

    if(_rotateLight < -360.0)
    {
        _rotateLight+=360;
    }

    glutPostRedisplay();



    glutTimerFunc(20, rotateLH_light, 0);
}





void update2(int value) {
if(position2 < -1.0)
position2 = 0.7f;
position2 -= speed2;
glutPostRedisplay();
glutTimerFunc(100, update2, 0);
}



void boatMOdel(){ ///joy


  glColor3ub( 23, 23, 22);
   glBegin(GL_POLYGON);
   glVertex2f(-10 ,10);
   glVertex2f(11,10);
   glVertex2f(16 ,5);
   glVertex2f(-10 ,5);
   glEnd();

   glColor3ub( 255, 0, 0);
   glBegin(GL_POLYGON);
   glVertex2f(-8 ,10);
   glVertex2f(10 ,10);
   glVertex2f(7 ,16);
   glVertex2f(-8,16);
   glEnd();
   ///Window 1st row
   glColor3ub(255, 255, 255);
   glBegin(GL_POLYGON);
   glVertex2f(-1.5 ,14.5);
   glVertex2f(0.5 ,14.5);
   glVertex2f(0.5 ,12.5);
   glVertex2f(-1.5 ,12.5);
   glEnd();

   glColor3ub(255, 255, 255);
   glBegin(GL_POLYGON);
   glVertex2f(-5.5 ,14.5);
   glVertex2f(-3.5 ,14.5);
   glVertex2f(-3.5 ,12.5);
   glVertex2f(-5.5 ,12.5);
   glEnd();

   glColor3ub(255, 255, 255);
   glBegin(GL_POLYGON);
   glVertex2f(2.5 ,14.5);
   glVertex2f(4.5 ,14.5);
   glVertex2f(4.5 ,12.5);
   glVertex2f(2.5 ,12.5);
   glEnd(); ///end

   glColor3ub( 0, 0, 128);///top floor
   glBegin(GL_POLYGON);
   glVertex2f(-2.8 ,16);
   glVertex2f(6.8 ,16);
   glVertex2f(5 ,21);
   glVertex2f(-2.5 ,21);
   glEnd();

   glColor3f( 255, 255, 255); ///window
   glBegin(GL_POLYGON);
   glVertex2f(-1 ,19.5);
   glVertex2f(1,19.5);
   glVertex2f(1 ,17.5);
   glVertex2f(-1 ,17.5);
   glEnd();

   glColor3f( 255, 255, 255);
   glBegin(GL_POLYGON);
   glVertex2f(2 ,19.5);
   glVertex2f(4 ,19.5);
   glVertex2f(4 ,17.5);
   glVertex2f(2 ,17.5);
   glEnd();
}

void boat()
{

   glPushMatrix();
   glTranslatef(_move, 0, 0);//glTranslatef(_move, 0, 0);
   //glTranslatef(10, 15, 0);
   boatMOdel();
   glPopMatrix();

}


void night()//!############################################################################################
{

    glColor3ub(42,42,53);
    sky();

    glColor3ub(42, 49, 149);
    ocean();

    glColor3ub(167, 148, 122);
    sand();

    road();


    glPushMatrix();//!##########################moon
    glTranslatef(20, 35, 0);
    glScalef(0.5, 0.5, 0);
    circle();
    glPopMatrix();

//!##############################star
    glPushMatrix();
    glTranslatef(-10, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 38, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15, 30, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 28, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20, 25, 0);
    star();
    glPopMatrix();
    //!##############################starEnds

//!###########################tide

    //tideNight();

    glPushMatrix();
    glTranslatef(7, 5, 0);
    //tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 8, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-37, 10, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, 18, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(27, 14, 0);
    tideNight();
    glPopMatrix();



//!###########################end tide
//!###########################umbrella, seat, tree, crabs

glPushMatrix();
glTranslatef(0, 20, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(-20, 15, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(20, 15, 0);
Umbrella();
Seat();
glPopMatrix();



//!###########################umbrella, seat, tree, crabs-----ends
glPushMatrix();
glTranslatef(-10, 28, 0);
glScalef(15, 10, 0);
flagship();
glPopMatrix();

lightHouse_Night();
cargoShip_night();
watchTower_Night();


glPopMatrix();
glutSwapBuffers();


}



void displayNight(int val)
{
    glutDisplayFunc(night);//inside the bracket this a function, which will be display
	//so make a function of this
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);

road();

glColor3ub(243, 213, 120);
sand();

glColor3ub(0,157,196);
ocean();


//!###########################tide

    tide();

    glPushMatrix();
    glTranslatef(7, 5, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 8, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-37, 10, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, 18, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(27, 14, 0);
    tide();
    glPopMatrix();



//!###########################end tide

glColor3ub(135,206,235);
sky();

sun();

glPushMatrix();
glTranslatef(-20, 29, 0);
glScalef(15, 10, 0);
flagship();
glPopMatrix();


//cargoShip_01();

//cargoShip_02();
cloud_01();
boat();
watchTower();
lightHouse();


//!###########################umbrella, seat, tree, crabs

glPushMatrix();
glTranslatef(0, 20, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(-20, 15, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(20, 15, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(25, -20, 0);
glScalef(46, 46, 0);
crab();
glPopMatrix();


//!###########################umbrella, seat, tree, crabs-----ends


truck00();
truck01();

glutSwapBuffers();
glFlush();

}

void display(int val) //call it from the keyBoard or mouse handle
{
    glutDisplayFunc(display);//inside the bracket this a function, which will be display
	//so make a function of this
}



void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
            glutTimerFunc( 1, displayNight, 0);
            break;
case GLUT_KEY_DOWN:
            glutTimerFunc( 1, display, 0);
            break;
}
glutPostRedisplay();
}



void control(unsigned char key, int x, int y) {
switch (key) {

//!###########################################################Ship
//case 'q':           boatspeed0=0;   break;
case 'w':           boatspeed=0;   break;

//case 'e':           boatspeed0=0.4;   break;
case 'r':           boatspeed=0.4;   break;

//case 't':           boatspeed0+=0.4;   break;
case 'y':           boatspeed+=0.4;   break;

//case 'u':           boatspeed0-=0.4;   break;
case 'i':           boatspeed-=0.4;   break;
//!###########################################################truck
case '1':           Truckspeed00=0;   break;
case '2':           Truckspeed01=0;   break;

case '3':           Truckspeed00=0.4;   break;
case '4':           Truckspeed01=0.4;   break;

case '5':           Truckspeed00+=0.4;   break;
case '6':           Truckspeed01+=0.4;   break;

case '7':           Truckspeed00-=0.4;   break;
case '8':           Truckspeed01-=0.4;   break;

case 'Z':           lightSpeed=0;   break;
case 'X':           lightSpeed=0.4;   break;

case 'C':           lightSpeed+=0.4;   break;
case 'V':           lightSpeed-=0.4;   break;


}     glutPostRedisplay();

}


void init()
{
    glLoadIdentity();
    gluOrtho2D(-50,50,-50,50);
}

int main(int argc, char** argv)
{
    printf("\n");
    printf(" |===========================================================|\n");
    printf(" |===>                   Welcome                         <===|\n");
    printf(" #----         Graphics Project:-'Sea Beach'           ------#\n");
    printf(" |-----------------------------------------------------------|\n");
    printf(" |                                                           |\n");
    printf(" #----Help Center (How to Operate ?) ------------------------#\n");
	printf(" |    |> Press 'w' For stop Ship and boat                    |\n");
	printf(" |    |> Press 'r' For run Ship and ship                     |\n");
	printf(" |    |> Press 'y' For speed up of Ship and boat             |\n");
	printf(" |    |> Press 'i' For Ship and boat speed in normal         |\n");
	printf(" |    |> Press '1' or '2' For Stop Truck                     |\n");
	printf(" |    |> Press '3' or '4' For run Truck                      |\n");
	printf(" |    |> Press '5' or '6' For speed up Truck                 |\n");
	printf(" |    |> Press '7' or '8' For Truck speed in normal form     |\n");
	printf(" |    |> Press 'Z' or 'X' For stop & start light speed       |\n");
	printf(" |    |> Press 'C' or 'V' For speed up and speed down light  |\n");
	printf(" |                                                           |\n");
	printf(" |-----------------------------------------------------------|\n");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    	glutInitWindowSize(850, 650);
    	glutCreateWindow("Sea Beach");

    	init(); //ortho2d

	glutDisplayFunc(display);

	glutTimerFunc(20, move_cargoShip_night, 0);
	glutTimerFunc(20, move_boat, 0);
	glutTimerFunc(20, move_cloud_01, 0);
    glutTimerFunc(20, rotateWT_light, 0);
    glutTimerFunc(20, update_truck00, 0);
    glutTimerFunc(20, update_truck01, 0);
    glutTimerFunc(20, rotateLH_light, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update, 0);


    glutKeyboardFunc(control);

    glutSpecialFunc(SpecialInput);

	glutMainLoop();
	return 0;
}
