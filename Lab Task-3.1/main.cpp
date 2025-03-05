#include<windows.h>
#include <GL/glut.h>
#include <math.h>

void Tree(){
    // Triangle 1
    glBegin(GL_TRIANGLES); // Use triangle mode
    glColor3f(0.0, 1.0, 0.0); // Green color
    glVertex2f(4, 6); // H
    glVertex2f(6, 4);  // C
    glVertex2f(2, 6);  // I
    glEnd();

    // Quadrilateral 1
    glBegin(GL_QUADS); // Use quadrilateral mode
    glColor3f(0.2, 1.0, 0.2); // Green color
    glVertex2f(4, 4); // D
    glVertex2f(6, 4); // C
    glVertex2f(6, 6); // G
    glVertex2f(4, 6); // H
    glEnd();

    // Quadrilateral 2
    glBegin(GL_QUADS); // Use quadrilateral mode
    glColor3f(0.0, 0.8, 0.0); // Dark green color
    glVertex2f(4, 4); // D
    glVertex2f(6, 4); // C
    glVertex2f(8, 6); // J
    glVertex2f(2, 6); // I
    glEnd();

    // Quadrilateral 3 (trunk of tree)
    glBegin(GL_QUADS); // Use quadrilateral mode
    glColor3f(0.4, 0.2, 0.0); // Brown color for trunk
    glVertex2f(4, 1); // A
    glVertex2f(6, 1); // B
    glVertex2f(6, 4); // C
    glVertex2f(4, 4); // D
    glEnd();

    glFlush(); // Force execution
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   Tree(); // Call the tree function to draw the shape
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to black
   glViewport(0, 0, 800, 600); // Set the viewport size
   glMatrixMode(GL_PROJECTION); // Set the projection matrix
   glLoadIdentity(); // Load the identity matrix
   glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0); // Set orthographic projection
}

int main(int argc, char** argv) {
   glutInit(&argc, argv); // Initialize GLUT
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
   glutInitWindowSize(1200, 800); // Set window size
   glutInitWindowPosition(100, 100); // Set window position
   glutCreateWindow("Modified Shape with New Vertices"); // Create window
   init(); // Initialize settings
   glutDisplayFunc(display); // Register display callback function
   glutMainLoop(); // Enter the GLUT main loop
   return 0; // Exit program
}
