#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Drop {
    float x, y;
    float speed;
};

std::vector<Drop> raindrops;
float waterLevel = -1.0f; // Initial water level
float floodRate = 0.001f; // Rate at which water level increases
bool isRaining = true; // Control rain state

void generateRaindrop() {
    Drop drop;
    drop.x = (rand() % 200 - 100) / 100.0f; // Random x position between -1.0 and 1.0
    drop.y = 1.0f; // Start at the top of the screen
    drop.speed = 0.02f + static_cast<float>(rand() % 10) / 500.0f; // Random speed
    raindrops.push_back(drop);
}

void drawRaindrop(const Drop& drop) {
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(drop.x, drop.y);
        glVertex2f(drop.x, drop.y - 0.05f);
    glEnd();
}

void drawFlood() {
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color for water
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, waterLevel);
        glVertex2f(-1.0f, waterLevel);
    glEnd();
}

void updateRaindrops() {
    if (!isRaining) return;

    for (auto& drop : raindrops) {
        drop.y -= drop.speed;
        if (drop.y < waterLevel + 0.05f) {
            drop.y = 1.0f; // Reset to the top
            drop.x = (rand() % 200 - 100) / 100.0f; // Random new x position
            waterLevel += floodRate; // Increase water level gradually
            if (waterLevel > 1.0f) {
                waterLevel = 1.0f; // Cap water level
            }
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawFlood();

    if (isRaining) {
        for (const auto& drop : raindrops) {
            drawRaindrop(drop);
        }
    }

    glutSwapBuffers();
}

void timer(int value) {
    if (isRaining) {
        updateRaindrops();
        for (int i = 0; i < 5; ++i) { // Generate a few raindrops every frame
            generateRaindrop();
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Call timer again after 16 ms (~60 FPS)
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'r') {
        isRaining = !isRaining; // Toggle rain on/off
    }
    if (key == 'f') {
        floodRate += 0.0005f; // Increase flood rate
    }
    if (key == 'd') {
        floodRate = std::max(0.0005f, floodRate - 0.0005f); // Decrease flood rate but keep it positive
    }
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up 2D orthographic projection
    srand(static_cast<unsigned>(time(0))); // Seed random generator
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rain and Flood Animation");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Handle keyboard input
    glutTimerFunc(16, timer, 0); // Start the timer

    glutMainLoop();
    return 0;
}
