#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Define the height of each stripe
    float stripeHeight = 2.0f / 7.0f; // Dividing the screen into 7 equal parts

    // Draw the purple stripe
    glColor3f(0.5f, 0.0f, 0.5f); // Purple color
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f - stripeHeight);
        glVertex2f(-1.0f, 1.0f - stripeHeight);
    glEnd();

    // Draw the blue stripe
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.0f - stripeHeight);
        glVertex2f(1.0f, 1.0f - stripeHeight);
        glVertex2f(1.0f, 1.0f - 2 * stripeHeight);
        glVertex2f(-1.0f, 1.0f - 2 * stripeHeight);
    glEnd();

    // Draw the teal stripe
    glColor3f(0.0f, 0.5f, 0.5f); // Teal color
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.0f - 2 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 2 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 3 * stripeHeight);
        glVertex2f(-1.0f, 1.0f - 3 * stripeHeight);
    glEnd();

    // Draw the green stripe
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.0f - 3 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 3 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 4 * stripeHeight);
        glVertex2f(-1.0f, 1.0f - 4 * stripeHeight);
    glEnd();

    // Draw the orange stripe
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.0f - 4 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 4 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 5 * stripeHeight);
        glVertex2f(-1.0f, 1.0f - 5 * stripeHeight);
    glEnd();

    // Draw the yellow stripe
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.0f - 5 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 5 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 6 * stripeHeight);
        glVertex2f(-1.0f, 1.0f - 6 * stripeHeight);
    glEnd();

    // Draw the red stripe
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.0f - 6 * stripeHeight);
        glVertex2f(1.0f, 1.0f - 6 * stripeHeight);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    glFlush(); // Render the image
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Window size
    glutInitWindowPosition(100, 100); // Window position
    glutCreateWindow("Rainbow Flag");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
