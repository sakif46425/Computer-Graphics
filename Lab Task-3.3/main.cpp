#include <GL/glut.h>

// Function to draw a rectangle
void drawRectangle(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b); // Set color
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the seat of the bench
    drawRectangle(-0.5f, -0.1f, 1.0f, 0.1f, 0.65f, 0.33f, 0.16f); // Brown wood

    // Draw the backrest of the bench
    drawRectangle(-0.5f, 0.05f, 1.0f, 0.1f, 0.65f, 0.33f, 0.16f); // Brown wood

    // Draw the legs of the bench
    drawRectangle(-0.45f, -0.5f, 0.05f, 0.4f, 0.4f, 0.4f, 0.4f); // Left leg (gray metal)
    drawRectangle(0.4f, -0.5f, 0.05f, 0.4f, 0.4f, 0.4f, 0.4f);   // Right leg (gray metal)

    glFlush(); // Render now
}

// Initialization function
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Bench");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
