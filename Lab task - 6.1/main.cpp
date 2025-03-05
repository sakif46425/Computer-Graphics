#include <GL/glut.h>
#include <cstdio>

int objectIndex = 0; // Keeps track of the currently displayed object
const int totalObjects = 4; // Total number of objects to display

// Function to draw a single object (a simple colored quad in this example)
void drawObject(int index) {
    switch (index) {
        case 0:
            glColor3f(1.0f, 0.0f, 0.0f); // Red
            break;
        case 1:
            glColor3f(0.0f, 1.0f, 0.0f); // Green
            break;
        case 2:
            glColor3f(0.0f, 0.0f, 1.0f); // Blue
            break;
        case 3:
            glColor3f(1.0f, 1.0f, 0.0f); // Yellow
            break;
    }

    float xOffset = -0.6f + index * 0.4f; // Offset objects horizontally

    glBegin(GL_QUADS);
        glVertex2f(xOffset - 0.15f, -0.15f);
        glVertex2f(xOffset + 0.15f, -0.15f);
        glVertex2f(xOffset + 0.15f, 0.15f);
        glVertex2f(xOffset - 0.15f, 0.15f);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i <= objectIndex; ++i) {
        drawObject(i);
    }

    glutSwapBuffers();
}

// Timer function to update the current object index
void timer(int value) {
    if (objectIndex < totalObjects - 1) {
        ++objectIndex;
        printf("Animating object: %d\n", objectIndex); // Debugging output
        glutPostRedisplay();
        glutTimerFunc(20, timer, 0); // Call timer again after 200 ms
    }
}

// Initialization function
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up 2D orthographic projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animation Example");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(200, timer, 0); // Start the timer

    glutMainLoop();
    return 0;
}
