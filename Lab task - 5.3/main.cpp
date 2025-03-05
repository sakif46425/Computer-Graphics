#include <GL/glut.h>
#include <cmath>

float bladeAngle = 0.0f; // Rotation angle of the windmill blades

void drawBlade(float x, float y, float width, float height, float angle) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // White color for blades
        glVertex2f(-width / 2, 0.0f);
        glVertex2f(width / 2, 0.0f);
        glVertex2f(width / 2, height);
        glVertex2f(-width / 2, height);
    glEnd();
    glPopMatrix();
}

void drawWindmill() {
    // Draw the base
    glColor3f(0.5f, 0.35f, 0.05f); // Brown color for the base
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, -0.4f);
        glVertex2f(0.05f, -0.4f);
        glVertex2f(0.05f, 0.2f);
        glVertex2f(-0.05f, 0.2f);
    glEnd();

    // Draw the blades
    drawBlade(0.0f, 0.2f, 0.02f, 0.2f, bladeAngle);
    drawBlade(0.0f, 0.2f, 0.02f, 0.2f, bladeAngle + 90);
    drawBlade(0.0f, 0.2f, 0.02f, 0.2f, bladeAngle + 180);
    drawBlade(0.0f, 0.2f, 0.02f, 0.2f, bladeAngle + 270);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the windmill
    drawWindmill();

    glutSwapBuffers();
}

void update(int value) {
    // Update the rotation angle of the blades
    bladeAngle += 2.0f;
    if (bladeAngle >= 360.0f) {
        bladeAngle -= 360.0f;
    }

    // Redraw the scene
    glutPostRedisplay();

    // Call update again after 16 milliseconds (~60 FPS)
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Windmill with Rotating Blades");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
