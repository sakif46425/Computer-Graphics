#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Define initial states for the weather
enum WeatherState { SUNNY, OVERCAST, RAINING };
WeatherState currentWeather = SUNNY;

// Timer interval for weather change (in milliseconds)
const int WEATHER_CHANGE_INTERVAL = 5000;

// Car position
float carX = -1.2;  // Initial X position of the car
const float CAR_SPEED = 0.01; // Speed of the car

// Function to draw the house
void drawHouse() {
    glColor3f(0.8, 0.4, 0.2); // Brown color for the house body
    glBegin(GL_QUADS);
    glVertex2f(-0.4, -0.4);
    glVertex2f(0.4, -0.4);
    glVertex2f(0.4, 0.2);
    glVertex2f(-0.4, 0.2);
    glEnd();

    glColor3f(0.5, 0.2, 0.1); // Darker brown for the roof
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, 0.2);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.0, 0.6);
    glEnd();
}

// Function to draw the road
void drawRoad() {
    glColor3f(0.3, 0.3, 0.3); // Gray color for the road
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.6);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();

    // Draw road lines
    glColor3f(1.0, 1.0, 1.0); // White color for road lines
    for (float x = -0.9; x <= 0.9; x += 0.2) {
        glBegin(GL_QUADS);
        glVertex2f(x - 0.05, -0.8);
        glVertex2f(x + 0.05, -0.8);
        glVertex2f(x + 0.05, -0.7);
        glVertex2f(x - 0.05, -0.7);
        glEnd();
    }
}

// Function to draw trees
void drawTree(float x, float y) {
    // Draw trunk
    glColor3f(0.55, 0.27, 0.07); // Brown color for the trunk
    glBegin(GL_QUADS);
    glVertex2f(x - 0.05, y - 0.4);
    glVertex2f(x + 0.05, y - 0.4);
    glVertex2f(x + 0.05, y);
    glVertex2f(x - 0.05, y);
    glEnd();

    // Draw foliage
    glColor3f(0.0, 0.6, 0.0); // Green color for the foliage
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.2, y);
    glVertex2f(x + 0.2, y);
    glVertex2f(x, y + 0.3);
    glEnd();
}

// Function to draw grass
void drawGrass() {
    glColor3f(0.0, 0.8, 0.0); // Green color for the grass
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.4);
    glVertex2f(1.0, -0.4);
    glVertex2f(1.0, -0.6);
    glVertex2f(-1.0, -0.6);
    glEnd();
}

// Function to draw the sun
void drawSun() {
    if (currentWeather == SUNNY) {
        glColor3f(1.0, 1.0, 0.0); // Yellow color for the sun
        float x = 0.7, y = 0.7, radius = 0.1;
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i = 0; i <= 360; i += 10) {
            float angle = i * 3.14159 / 180.0;
            glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
        }
        glEnd();
    }
}

// Function to draw the rain
void drawRain() {
    glColor3f(0.7, 0.7, 0.7); // Light gray color for rain
    glBegin(GL_LINES);
    for (float x = -1.0; x <= 1.0; x += 0.05) {
        for (float y = -1.0; y <= 1.0; y += 0.1) {
            glVertex2f(x, y);
            glVertex2f(x + 0.02, y - 0.1);
        }
    }
    glEnd();
}

// Function to draw the sky based on weather state
void drawSky() {
    switch (currentWeather) {
        case SUNNY:
            glColor3f(0.4, 0.8, 1.0); // Light blue for sunny sky
            break;
        case OVERCAST:
            glColor3f(0.6, 0.6, 0.6); // Gray for overcast sky
            break;
        case RAINING:
            glColor3f(0.5, 0.5, 0.5); // Darker gray for rainy sky
            break;
    }
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, -0.4);
    glVertex2f(-1.0, -0.4);
    glEnd();
}

// Function to draw the car
void drawCar(float x) {
    glColor3f(1.0, 0.0, 0.0); // Red color for the car body
    glBegin(GL_QUADS);
    glVertex2f(x - 0.2, -0.7);
    glVertex2f(x + 0.2, -0.7);
    glVertex2f(x + 0.2, -0.5);
    glVertex2f(x - 0.2, -0.5);
    glEnd();

    // Wheels
    glColor3f(0.0, 0.0, 0.0); // Black color for the wheels
    float radius = 0.05;
    for (float wheelX = x - 0.15; wheelX <= x + 0.15; wheelX += 0.3) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(wheelX, -0.7);
        for (int i = 0; i <= 360; i += 10) {
            float angle = i * 3.14159 / 180.0;
            glVertex2f(wheelX + cos(angle) * radius, -0.7 + sin(angle) * radius);
        }
        glEnd();
    }
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the scene elements
    drawSky();
    drawGrass();
    drawHouse();
    drawRoad();
    drawTree(-0.7, -0.2);
    drawTree(0.7, -0.2);
    drawSun();
    drawCar(carX);

    if (currentWeather == RAINING) {
        drawRain();
    }

    glutSwapBuffers();
}

// Timer callback function for car movement
void moveCar(int value) {
    carX += CAR_SPEED;
    if (carX > 1.2) { // Reset car position when it moves out of screen
        carX = -1.2;
        currentWeather = static_cast<WeatherState>((currentWeather + 1) % 3); // Change weather
    }
    glutPostRedisplay();
    glutTimerFunc(16, moveCar, 0); // Call function again after ~16 ms
}

// Initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Weather Change Simulation with Moving Car");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, moveCar, 0); // Start the car movement with a timer

    glutMainLoop(); // Enter the GLUT event processing loop
    return 0;
}
