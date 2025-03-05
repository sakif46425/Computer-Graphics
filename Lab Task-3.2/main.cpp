#include <GL/glut.h>
#include <cmath>

// Function to draw a circle (for the light bulb glow)
void drawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Function to draw a rectangle (for the lamppost)
void drawRectangle(float x, float y, float width, float height) {
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

    // Draw the lamppost (black pole)
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray color
    drawRectangle(-0.02f, -0.5f, 0.04f, 0.7f); // Lamppost

    // Draw the light bulb (yellow circle)
    glColor3f(1.0f, 1.0f, 0.6f); // Light yellow color
    drawCircle(0.0f, 0.25f, 0.05f, 50);

    // Draw the light glow (faint yellow outer circle)
    glColor4f(1.0f, 1.0f, 0.6f, 0.1f); // Transparent yellow
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    drawCircle(0.0f, 0.25f, 0.1f, 50);
    glDisable(GL_BLEND);

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
    glutCreateWindow("Lamppost with Glow");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
