#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    // Draw Square (House Body)
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0.3); // Set color to a brown shade
    glVertex2f(-0.3, -0.3);   // Bottom Left
    glVertex2f(0.3, -0.3);    // Bottom Right
    glVertex2f(0.3, 0.3);     // Top Right
    glVertex2f(-0.3, 0.3);    // Top Left
    glEnd();

    // Draw Triangle (Roof)
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.2, 0.2); // Set color to a red shade
    glVertex2f(-0.35, 0.3);   // Left Corner
    glVertex2f(0.35, 0.3);    // Right Corner
    glVertex2f(0.0, 0.6);     // Top Corner
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("House Shape");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
