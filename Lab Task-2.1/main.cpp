#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    float squareSize = 0.5f; // Size of each square (1.0 / 2 = 0.5 for a 4x4 grid)
    float startX = -1.0f, startY = 1.0f; // Top-left corner of the chessboard

    for (int i = 0; i < 4; i++) { // Loop for rows
        for (int j = 0; j < 4; j++) { // Loop for columns
            if ((i + j) % 2 == 0) {
                glColor3f(0.0f, 0.0f, 0.0f); // Black square
            } else {
                glColor3f(1.0f, 1.0f, 1.0f); // White square
            }

            // Calculate coordinates of the square
            float x1 = startX + j * squareSize;
            float y1 = startY - i * squareSize;
            float x2 = x1 + squareSize;
            float y2 = y1 - squareSize;

            // Draw the square
            glBegin(GL_QUADS);
                glVertex2f(x1, y1); // Top-left corner
                glVertex2f(x2, y1); // Top-right corner
                glVertex2f(x2, y2); // Bottom-right corner
                glVertex2f(x1, y2); // Bottom-left corner
            glEnd();
        }
    }

    glFlush(); // Render the image
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Window size
    glutInitWindowPosition(100, 100); // Window position
    glutCreateWindow("4x4 Chessboard");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
