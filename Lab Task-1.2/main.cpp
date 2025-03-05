#include <GL/glut.h>

void drawShapes() {
    // Clear the background
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw X and Y axis lines
    glLineWidth(2);
    glColor3f(0.0f, 0.0f, 0.0f);  // Black color
    glBegin(GL_LINES);
        // Horizontal line
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        // Vertical line
        glVertex2f(0.0f, -1.0f);
        glVertex2f(0.0f, 1.0f);
    glEnd();

    // Draw Red Square in the top-left quadrant
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color
    glBegin(GL_QUADS);
        glVertex2f(-0.7f, 0.3f);
        glVertex2f(-0.3f, 0.3f);
        glVertex2f(-0.3f, 0.7f);
        glVertex2f(-0.7f, 0.7f);
    glEnd();

    // Draw Green Arrow in the top-right quadrant
    glColor3f(0.0f, 1.0f, 0.0f);  // Green color
    glBegin(GL_QUADS);  // Arrow body
        glVertex2f(0.3f, 0.5f);
        glVertex2f(0.7f, 0.5f);
        glVertex2f(0.7f, 0.3f);
        glVertex2f(0.3f, 0.3f);
    glEnd();
    glBegin(GL_TRIANGLES);  // Arrow head
        glVertex2f(0.7f, 0.6f);
        glVertex2f(1.0f, 0.4f);
        glVertex2f(0.7f, 0.2f);
    glEnd();

    // Draw Purple Triangle in the bottom-left quadrant
    glColor3f(0.5f, 0.0f, 0.5f);  // Purple color
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(-0.3f, -0.7f);
        glVertex2f(-0.7f, -0.7f);
    glEnd();

    // Draw Yellow Triangle in the bottom-right quadrant
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow color
    glBegin(GL_TRIANGLES);
        glVertex2f(0.5f, -0.3f);
        glVertex2f(0.3f, -0.7f);
        glVertex2f(0.7f, -0.7f);
    glEnd();

    glFlush();
}

void initialize() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);      // Set up the orthographic projection
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadrant Shapes");

    initialize();
    glutDisplayFunc(drawShapes);
    glutMainLoop();

    return 0;
}
