
#include <windows.h>
#include <GL/glut.h>


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // German Flag
    // Draw black stripe
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glVertex2f(1, 14); // Top left
        glVertex2f(6,14); // Top right
        glVertex2f(6,13); // Bottom rg
        glVertex2f(1,13); // Bottom left
    glEnd();

    // Draw red stripe
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(1, 13); // Top left
        glVertex2f(6, 13); // Top right
        glVertex2f(6, 12); // Bottom right
        glVertex2f(1, 12); // Bottom left
    glEnd();

    // Draw yellow stripe
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glVertex2f(1, 12); // Top left
        glVertex2f(6, 12); // Top right
        glVertex2f(6, 11); // Bottom right
        glVertex2f(1, 11); // Bottom left
    glEnd();

    /*/ Space between flags
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // White (background color for space)
        glVertex2f(); // Top left
        glVertex2f(); // Top right
        glVertex2f(); // Bottom right
        glVertex2f(); // Bottom left
    glEnd();*/

    // Hungary Flag
    // Draw red stripe
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(1, 9); // Top left
        glVertex2f(6, 9); // Top right
        glVertex2f(6, 8); // Bottom right
        glVertex2f(1, 8); // Bottom left
    glEnd();

    // Draw white stripe
    /*glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex2f(); // Top left
        glVertex2f(); // Top right
        glVertex2f(); // Bottom right
        glVertex2f(); // Bottom left
    glEnd();*/

    // Draw green stripe
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex2f(1, 7); // Top leftj
        glVertex2f(6, 7); // Top righto
        glVertex2f(6, 6); // Bottom rightp
        glVertex2f(1, 6); // Bottom lefti
    glEnd();

    // Greece Flag
    // Draw red stripe
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red

        glVertex2f(1, 4); // Top left
        glVertex2f(6, 4); // Top right
        glVertex2f(6, 3); // Bottom right
        glVertex2f(1, 3); // Bottom left
    glEnd();
//black
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glVertex2f(1, 2); // Top left
        glVertex2f(6,2); // Top right
        glVertex2f(6,1); // Bottom rg
        glVertex2f(1,1); // Bottom left
    glEnd();



    glFlush(); // Render now
}

// Initialization function
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 10, -15, 20); // Set the coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("German and Hungary Flags"); // Create window with title

    glutDisplayFunc(display); // Register display function
    init(); // Call initialization function

    glutMainLoop(); // Enter the GLUT main loop
    return 0; // Exit
}
