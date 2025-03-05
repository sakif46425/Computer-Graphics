#include <GL/glut.h>
#include <cmath> // For cosf and sinf

// Function to draw a circle (used for the sun)
void drawCircle(float cx, float cy, float radius, int num_segments) {
    glBegin(GL_LINE_LOOP); // Use GL_LINE_LOOP for an outlined circle
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Angle in radians
        float x = radius * cosf(theta); // X coordinate
        float y = radius * sinf(theta); // Y coordinate
        glVertex2f(x + cx, y + cy); // Offset the circle center
    }
    glEnd();
}

// Function to display the design
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Set color to black for all elements

    // Draw the mountain
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6f, -0.4f); // Left base
    glVertex2f(0.0f, 0.4f);   // Peak
    glVertex2f(0.6f, -0.4f);  // Right base
    glEnd();

    // Draw the mountain trail
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(-0.1f, -0.3f);
    glEnd();

    // Draw the sun (circle)
    drawCircle(0.0f, 0.3f, 0.2f, 100);

    // Draw trees (triangles)
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.4f); // Left tree
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(-0.6f, -0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.8f, -0.4f); // Right tree
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.6f, -0.4f);
    glEnd();

    // Draw the horizontal line
    glBegin(GL_LINES);
    glVertex2f(-0.9f, -0.4f);
    glVertex2f(0.9f, -0.4f);
    glEnd();

    // Draw the text (Placeholder for "MOUNTAIN")
    glRasterPos2f(-0.2f, -0.6f); // Text position
    const char *text = "MOUNTAIN";
    for (const char *c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    glFlush();
}

// Function to initialize the window
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the orthographic projection
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mountain Logo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
