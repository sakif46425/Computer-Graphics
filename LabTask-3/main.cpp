#include <windows.h>
#include <GL/glut.h>

// Function to draw a rectangle with specified colors
void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Function to draw the building
void Building() {
    // Building body (main structure color - light gray)
    drawRectangle(2.0f, 6.0f, 6.0f, 0.5f, 0.7f, 0.7f, 0.7f); // Light gray

    // Draw windows (5 floors, 2 windows per floor)
    float yStart = 5.5f; // Starting y-coordinate for the top row
    for (int i = 0; i < 5; i++) {
        // Left window (brown)
        drawRectangle(2.5f, yStart, 3.0f, yStart - 0.5f, 0.4f, 0.2f, 0.0f);
        // Right window (brown)
        drawRectangle(5.0f, yStart, 5.5f, yStart - 0.5f, 0.4f, 0.2f, 0.0f);
        yStart -= 1.0f; // Move down for the next floor
    }

    // Door (dark brown)
    drawRectangle(3.5f, 1.5f, 4.5f, 0.5f, 0.2f, 0.0f, 0.0f); // Dark brown door
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    Building();
    glFlush();
}

// Initialization function
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glViewport(0, 0, 800, 600);          // Set the viewport
    glMatrixMode(GL_PROJECTION);         // Set the projection matrix
    glLoadIdentity();                    // Load the identity matrix
    glOrtho(0.0, 8.0, 0.0, 10.0, -1.0, 1.0); // Orthographic projection
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);               // Set window size
    glutInitWindowPosition(100, 100);            // Set window position
    glutCreateWindow("Five-Storied Building");   // Create the window
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
