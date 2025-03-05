#include <GL/glut.h>
#include <stdbool.h>
#include <time.h>

// Global variables to track the color state and time
bool toggleColor = false;

// Timer function to switch colors
void TimerFunction(int value) {
    // Toggle the color state
    toggleColor = !toggleColor;

    // Request a redraw
    glutPostRedisplay();

    // Call this function again after 20ms
    glutTimerFunc(20, TimerFunction, 0);
}

// Display callback function
void Display() {
    // Clear the screen with the current background color
    if (toggleColor) {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Red color
    } else {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // Green color
    }

    glClear(GL_COLOR_BUFFER_BIT);

    // Swap buffers (in case of double buffering)
    glutSwapBuffers();
}

// Main function
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Background Color Animation");

    // Set the display callback
    glutDisplayFunc(Display);

    // Start the timer
    glutTimerFunc(20, TimerFunction, 0);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}

