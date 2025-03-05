#include <GL/glut.h>

float box1X = -0.9f; // Initial position of the first box
float box2X = 0.9f;  // Initial position of the second box
float speed = 0.01f; // Speed of the boxes

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the first box
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glBegin(GL_QUADS);
        glVertex2f(box1X, -0.1f);
        glVertex2f(box1X + 0.2f, -0.1f);
        glVertex2f(box1X + 0.2f, 0.1f);
        glVertex2f(box1X, 0.1f);
    glEnd();

    // Draw the second box
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glBegin(GL_QUADS);
        glVertex2f(box2X, -0.1f);
        glVertex2f(box2X - 0.2f, -0.1f);
        glVertex2f(box2X - 0.2f, 0.1f);
        glVertex2f(box2X, 0.1f);
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    // Update the position of the boxes
    box1X += speed;
    box2X -= speed;

    // Reset positions when they move out of bounds
    if (box1X > 1.0f) box1X = -1.0f;
    if (box2X < -1.0f) box2X = 1.0f;

    // Redraw the scene
    glutPostRedisplay();

    // Call update again after 16 milliseconds (~60 FPS)
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Two Boxes Animation");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
