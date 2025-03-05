#include <GL/glut.h>

float positions[4][2] = {
    {0.0f, 0.0f}, // Initial position of object 0 (red)
    {0.0f, 0.0f}, // Initial position of object 1 (green)
    {0.0f, 0.0f}, // Initial position of object 2 (blue)
    {0.0f, 0.0f}  // Initial position of object 3 (yellow)
};

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

    float x = positions[index][0];
    float y = positions[index][1];

    glBegin(GL_QUADS);
        glVertex2f(x - 0.05f, y - 0.05f);
        glVertex2f(x + 0.05f, y - 0.05f);
        glVertex2f(x + 0.05f, y + 0.05f);
        glVertex2f(x - 0.05f, y + 0.05f);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < 4; ++i) {
        drawObject(i);
    }

    glutSwapBuffers();
}

// Keyboard function to move objects
void keyboard(unsigned char key, int x, int y) {
    float speed = 0.05f; // Movement speed

    switch (key) {
        case 'a': // Move object 0 (red) left
            positions[0][0] -= speed;
            break;
        case 'd': // Move object 0 (red) right
            positions[0][0] += speed;
            break;
        case 'w': // Move object 0 (red) up
            positions[0][1] += speed;
            break;
        case 's': // Move object 0 (red) down
            positions[0][1] -= speed;
            break;
        case 'j': // Move object 1 (green) left
            positions[1][0] -= speed;
            break;
        case 'l': // Move object 1 (green) right
            positions[1][0] += speed;
            break;
        case 'i': // Move object 1 (green) up
            positions[1][1] += speed;
            break;
        case 'k': // Move object 1 (green) down
            positions[1][1] -= speed;
            break;
        case 'f': // Move object 2 (blue) left
            positions[2][0] -= speed;
            break;
        case 'h': // Move object 2 (blue) right
            positions[2][0] += speed;
            break;
        case 't': // Move object 2 (blue) up
            positions[2][1] += speed;
            break;
        case 'g': // Move object 2 (blue) down
            positions[2][1] -= speed;
            break;
        case 'z': // Move object 3 (yellow) left
            positions[3][0] -= speed;
            break;
        case 'c': // Move object 3 (yellow) right
            positions[3][0] += speed;
            break;
        case 'v': // Move object 3 (yellow) up
            positions[3][1] += speed;
            break;
        case 'x': // Move object 3 (yellow) down
            positions[3][1] -= speed;
            break;
    }

    glutPostRedisplay();
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
    glutCreateWindow("Moving Objects with Keyboard");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register keyboard handler

    glutMainLoop();
    return 0;
}
