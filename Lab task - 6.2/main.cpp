#include <GL/glut.h>

float positions[4][2] = {
    {0.0f, 0.0f}, // Initial position of object 0 (red)
    {0.0f, 0.0f}, // Initial position of object 1 (green)
    {0.0f, 0.0f}, // Initial position of object 2 (blue)
    {0.0f, 0.0f}  // Initial position of object 3 (yellow)
};

int directions[4] = {0, 1, 2, 3}; // Movement directions: 0 = left, 1 = right, 2 = up, 3 = down

void updatePosition(int index) {
    float speed = 0.01f; // Movement speed

    switch (directions[index]) {
        case 0: // Move left
            positions[index][0] -= speed;
            if (positions[index][0] < -1.0f) directions[index] = 1; // Change to right
            break;
        case 1: // Move right
            positions[index][0] += speed;
            if (positions[index][0] > 1.0f) directions[index] = 0; // Change to left
            break;
        case 2: // Move up
            positions[index][1] += speed;
            if (positions[index][1] > 1.0f) directions[index] = 3; // Change to down
            break;
        case 3: // Move down
            positions[index][1] -= speed;
            if (positions[index][1] < -1.0f) directions[index] = 2; // Change to up
            break;
    }
}

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

// Timer function to update the objects
void timer(int value) {
    for (int i = 0; i < 4; ++i) {
        updatePosition(i);
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Call timer again after 16 ms (~60 FPS)
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
    glutCreateWindow("Moving Objects");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16, timer, 0); // Start the timer

    glutMainLoop();
    return 0;
}
