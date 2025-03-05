#include <GL/glut.h>
#include <cmath>

float carX = -0.8f; // Initial position of the car
float wheelAngle = 0.0f; // Rotation angle of the wheels
float speed = 0.01f; // Speed of the car

void drawWheel(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the wheel
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();

    // Draw spokes
    glColor3f(1.0f, 1.0f, 1.0f); // White color for spokes
    glBegin(GL_LINES);
    for (int i = 0; i < 360; i += 45) {
        float angle = (i + wheelAngle) * 3.14159f / 180.0f;
        glVertex2f(x, y);
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawCar() {
    // Draw the body of the car
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the car body
    glBegin(GL_QUADS);
        glVertex2f(carX - 0.2f, -0.1f);
        glVertex2f(carX + 0.2f, -0.1f);
        glVertex2f(carX + 0.2f, 0.1f);
        glVertex2f(carX - 0.2f, 0.1f);
    glEnd();

    // Draw the wheels
    drawWheel(carX - 0.15f, -0.15f, 0.05f);
    drawWheel(carX + 0.15f, -0.15f, 0.05f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the car
    drawCar();

    glutSwapBuffers();
}

void update(int value) {
    // Update the position of the car
    carX += speed;
    if (carX > 1.0f) {
        carX = -1.0f; // Reset position when it moves out of bounds
    }

    // Update the rotation angle of the wheels
    wheelAngle -= 5.0f;
    if (wheelAngle < 0.0f) {
        wheelAngle += 360.0f;
    }

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
    glutCreateWindow("Car with Rotating Wheels");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
