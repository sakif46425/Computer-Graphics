#include <GL/glut.h>
#include <cmath> // For cosf and sinf

// Function to draw a circle (used for the signal light)
void drawCircle(float cx, float cy, float radius, int num_segments) {
    glBegin(GL_POLYGON); // Use GL_POLYGON for a filled circle
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

    glColor3f(0.0, 0.0, 0.0); // Set color to black for roads and outlines

    // Draw the road
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.3f); // Bottom-left
    glVertex2f(1.0f, -0.3f);  // Bottom-right
    glVertex2f(1.0f, -1.0f);  // Top-right
    glVertex2f(-1.0f, -1.0f); // Top-left
    glEnd();

    // Draw the white road lines
    glColor3f(1.0, 1.0, 1.0); // White color for road lines
    glBegin(GL_LINES);
    glVertex2f(-0.1f, -0.3f);  // Left line start
    glVertex2f(-0.1f, -1.0f);  // Left line end
    glVertex2f(0.1f, -0.3f);   // Right line start
    glVertex2f(0.1f, -1.0f);   // Right line end
    glEnd();

    // Draw the traffic island
    glColor3f(0.8, 0.8, 0.8); // Light grey color for the island
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.3f);  // Left side of the island
    glVertex2f(0.2f, -0.3f);   // Right side of the island
    glVertex2f(0.2f, 0.0f);    // Right top of the island
    glVertex2f(-0.2f, 0.0f);   // Left top of the island
    glEnd();

    // Draw the red and white striped base of the traffic signal post
    glColor3f(1.0, 0.0, 0.0); // Red color for stripes
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.0f);  // Bottom-left of the stripe
    glVertex2f(0.05f, 0.0f);   // Bottom-right of the stripe
    glVertex2f(0.05f, 0.1f);   // Top-right of the stripe
    glVertex2f(-0.05f, 0.1f);  // Top-left of the stripe
    glEnd();

    // Draw the traffic signal pole
    glColor3f(0.5, 0.5, 0.5); // Grey color for the pole
    glBegin(GL_QUADS);
    glVertex2f(-0.02f, 0.1f);  // Bottom-left of the pole
    glVertex2f(0.02f, 0.1f);   // Bottom-right of the pole
    glVertex2f(0.02f, 0.5f);   // Top-right of the pole
    glVertex2f(-0.02f, 0.5f);  // Top-left of the pole
    glEnd();

    // Draw the traffic signal light (circle)
    glColor3f(1.0, 0.0, 0.0); // Red light
    drawCircle(0.0f, 0.5f, 0.05f, 50);  // Red light

    // Draw the green light (circle)
    glColor3f(0.0, 1.0, 0.0); // Green light
    drawCircle(0.0f, 0.6f, 0.05f, 50);  // Green light

    // Draw the trees
    glColor3f(0.0, 0.7, 0.0); // Green color for trees
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.3f);  // Left tree base
    glVertex2f(-0.8f, 0.0f);   // Left tree top
    glVertex2f(-0.7f, -0.3f);  // Left tree base
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.9f, -0.3f);   // Right tree base
    glVertex2f(0.8f, 0.0f);    // Right tree top
    glVertex2f(0.7f, -0.3f);   // Right tree base
    glEnd();

    // Draw the background (hills and sky)
    glColor3f(0.6, 0.9, 0.6); // Light green color for hills
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.3f);  // Left bottom of the hill
    glVertex2f(1.0f, -0.3f);   // Right bottom of the hill
    glVertex2f(1.0f, 0.0f);    // Right top of the hill
    glVertex2f(-1.0f, 0.0f);   // Left top of the hill
    glEnd();

    // Draw the clouds (using circles for cloud shapes)
    glColor3f(1.0, 1.0, 1.0); // White color for clouds
    drawCircle(-0.6f, 0.6f, 0.15f, 30);  // Left cloud
    drawCircle(0.3f, 0.7f, 0.2f, 30);   // Right cloud

    glFlush();
}

// Function to initialize the window
void init() {
    glClearColor(0.0, 0.8, 1.0, 1.0); // Sky blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the orthographic projection
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Traffic Signal on Road");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
