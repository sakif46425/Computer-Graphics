#include <GL/glut.h>
void rectangleline1()
{
   glLineWidth(4);
glBegin(GL_LINE_LOOP);
glColor3ub(0,0,0);
glVertex2f(2,3);
glVertex2f(5,3);
glVertex2f(5,1);
glVertex2f(2,1);
glEnd();

}

void display() {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque

glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
rectangleline1();


glFlush(); // Render now


}


/* Main function: GLUT runs as a console application starting at main() */

int main(int argc, char** argv) {

glutInit(&argc, argv); // Initialize GLUT
glutInitWindowSize(800, 800);
glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title

//glutInitWindowSize(320, 320); // Set the window's initial width & height

glutDisplayFunc(display); // Register display callback handler for window re-paint
gluOrtho2D(-10,10,-10,10);
glutMainLoop(); // Enter the event-processing loop

return 0;

}
