#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // German Flag
    // Draw black stripe
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glVertex2f(4.89f, 13.86f); // Top left
        glVertex2f(19.72f, 13.86f); // Top right
        glVertex2f(19.64f, 10.96f); // Bottom right
        glVertex2f(4.89f, 10.96f); // Bottom left
    glEnd();

    // Draw red stripe
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(4.89f, 10.96f); // Top left
        glVertex2f(19.64f, 10.96f); // Top right
        glVertex2f(19.72f, 7.9f); // Bottom right
        glVertex2f(4.89f, 7.9f); // Bottom left
    glEnd();

    // Draw yellow stripe
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glVertex2f(4.89f, 7.9f); // Top left
        glVertex2f(19.72f, 7.9f); // Top right
        glVertex2f(19.72f, 5.0f); // Bottom right
        glVertex2f(4.89f, 5.0f); // Bottom left
    glEnd();

    glFlush(); // Render now
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 25, 0, 15); // Adjusted the coordinate system to fit the flag
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("German Flag"); // Create window with title

    init(); // Call initialization function
    glutDisplayFunc(display); // Register display function

    glutMainLoop(); // Enter the GLUT main loop
    return 0; // Exit
}
