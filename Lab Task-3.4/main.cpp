#include <windows.h>
#include <GL/glut.h>
#include <cmath>

// Function to draw a rectangle
void drawRectangle(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

// Function to draw a circle
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

// Function to draw the building
void Building() {
    // Main building structure
    drawRectangle(-0.5f, 0.0f, 0.6f, 0.8f, 0.7f, 0.7f, 0.7f); // Light gray

    // Windows
    float windowWidth = 0.1f, windowHeight = 0.1f;
    for (float y = 0.6f; y >= 0.1f; y -= 0.2f) {
        drawRectangle(-0.4f, y, windowWidth, windowHeight, 0.4f, 0.2f, 0.0f); // Left window
        drawRectangle(-0.1f, y, windowWidth, windowHeight, 0.4f, 0.2f, 0.0f); // Right window
    }

    // Door
    drawRectangle(-0.3f, 0.0f, 0.2f, 0.2f, 0.2f, 0.0f, 0.0f); // Dark brown
}

// Function to draw the tree
void Tree() {
    // Tree trunk
    drawRectangle(0.5f, 0.0f, 0.1f, 0.3f, 0.4f, 0.2f, 0.0f); // Brown trunk

    // Tree foliage (circles)
    glColor3f(0.0f, 0.8f, 0.0f);
    drawCircle(0.55f, 0.4f, 0.15f, 50); // Top circle
    drawCircle(0.45f, 0.3f, 0.15f, 50); // Left circle
    drawCircle(0.65f, 0.3f, 0.15f, 50); // Right circle
}

// Function to draw the lamppost
void Lamppost() {
    // Lamppost body
    drawRectangle(-0.9f, 0.0f, 0.05f, 0.6f, 0.2f, 0.2f, 0.2f); // Dark gray pole

    // Light bulb
    glColor3f(1.0f, 1.0f, 0.6f);
    drawCircle(-0.875f, 0.65f, 0.05f, 50); // Yellow light bulb

    // Light glow
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0f, 1.0f, 0.6f, 0.1f);
    drawCircle(-0.875f, 0.65f, 0.1f, 50); // Faint yellow glow
    glDisable(GL_BLEND);
}

// Function to draw the bench
void Bench() {
    // Seat
    drawRectangle(-0.2f, -0.1f, 0.4f, 0.05f, 0.65f, 0.33f, 0.16f); // Brown wood

    // Backrest
    drawRectangle(-0.2f, 0.0f, 0.4f, 0.05f, 0.65f, 0.33f, 0.16f); // Brown wood

    // Legs
    drawRectangle(-0.15f, -0.5f, 0.05f, 0.4f, 0.4f, 0.4f, 0.4f); // Left leg
    drawRectangle(0.1f, -0.5f, 0.05f, 0.4f, 0.4f, 0.4f, 0.4f);  // Right leg
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw all objects in the scene
    Building();
    Tree();
    Lamppost();
    Bench();

    glFlush();
}

// Initialization
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
    glutCreateWindow("Scene with Building, Tree, Lamppost, and Bench");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
