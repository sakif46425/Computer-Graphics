#include <GL/glut.h>

// Function to draw the rectangle
void rectangle1()
{
    glLineWidth(4);
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 0.0f); // Red color
        glVertex2f(5.0f, 7.0f);
        glVertex2f(9.0f, 7.0f);
        glVertex2f(11.0f, 3.0f);
        glVertex2f(3.0f, 3.0f);
    glEnd();
}

// Display callback function
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    rectangle1();                         // Draw the rectangle

    glFlush();                            // Render now
}

// Initialization function to set up the projection matrix
void initialize() {
    glMatrixMode(GL_PROJECTION);          // Switch to projection matrix
    glLoadIdentity();                     // Reset the projection matrix
    gluOrtho2D(0.0, 12.0, 0.0, 10.0);     // Define the orthographic projection
    glMatrixMode(GL_MODELVIEW);           // Switch back to modelview matrix
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowSize(500, 500);                 // Set the window size
    glutInitWindowPosition(100, 100);             // Set the window position
    glutCreateWindow("OpenGL Rectangle Example");  // Create the window with a title

    initialize();                                 // Call the initialization function
    glutDisplayFunc(display);                     // Register the display callback
    glutMainLoop();                               // Enter the main event loop

    return 0;
}
