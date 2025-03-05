#include <GL/glut.h>

// Function to draw a line
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to display the lighthouse design
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Set drawing color to black

    // Draw the curved hill
    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-0.5f, -0.4f);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(0.5f, -0.4f);
    glVertex2f(1.0f, -0.6f);
    glEnd();

    // Draw the lighthouse body
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.1f, -0.5f); // Bottom left
    glVertex2f(0.1f, -0.5f);  // Bottom right
    glVertex2f(0.08f, 0.2f);  // Top right
    glVertex2f(-0.08f, 0.2f); // Top left
    glEnd();

    // Draw the lighthouse roof
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.12f, 0.2f); // Left corner
    glVertex2f(0.12f, 0.2f);  // Right corner
    glVertex2f(0.0f, 0.3f);   // Top point
    glEnd();

    // Draw the middle band of the lighthouse
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.1f, 0.1f);  // Bottom left
    glVertex2f(0.1f, 0.1f);   // Bottom right
    glVertex2f(0.1f, 0.15f);  // Top right
    glVertex2f(-0.1f, 0.15f); // Top left
    glEnd();

    // Draw the lighthouse door
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.03f, -0.5f); // Bottom left
    glVertex2f(0.03f, -0.5f);  // Bottom right
    glVertex2f(0.03f, -0.3f);  // Top right
    glVertex2f(-0.03f, -0.3f); // Top left
    glEnd();

    // Draw light rays (6 lines)
    drawLine(0.0f, 0.25f, -0.8f, 0.6f); // Top-left light ray
    drawLine(0.0f, 0.25f, -0.6f, 0.5f); // Middle-left light ray
    drawLine(0.0f, 0.25f, -0.4f, 0.4f); // Bottom-left light ray
    drawLine(0.0f, 0.25f, 0.4f, 0.4f);  // Bottom-right light ray
    drawLine(0.0f, 0.25f, 0.6f, 0.5f);  // Middle-right light ray
    drawLine(0.0f, 0.25f, 0.8f, 0.6f);  // Top-right light ray

    glFlush();
}

// Function to initialize the window
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Orthographic projection
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lighthouse on a Hill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
