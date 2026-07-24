#include <GL/glut.h>
#include <stdlib.h>

// Transformation variables
float tx = 0.0f, ty = 0.0f;
float angle = 0.0f;
float sx = 1.0f, sy = 1.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Apply transformations
    glTranslatef(tx, ty, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(sx, sy, 1.0f);

    // Draw Hexagon with Smooth Shading
    glBegin(GL_POLYGON);

        glColor3f(1.0f, 0.0f, 0.0f);   // Red
        glVertex2f(-0.3f, 0.5f);

        glColor3f(0.0f, 1.0f, 0.0f);   // Green
        glVertex2f(0.3f, 0.5f);

        glColor3f(0.0f, 0.0f, 1.0f);   // Blue
        glVertex2f(0.6f, 0.0f);

        glColor3f(1.0f, 1.0f, 0.0f);   // Yellow
        glVertex2f(0.3f, -0.5f);

        glColor3f(1.0f, 0.0f, 1.0f);   // Magenta
        glVertex2f(-0.3f, -0.5f);

        glColor3f(0.0f, 1.0f, 1.0f);   // Cyan
        glVertex2f(-0.6f, 0.0f);

    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Translation
        case 'a':
            tx -= 0.1f;
            break;

        case 'd':
            tx += 0.1f;
            break;

        case 'w':
            ty += 0.1f;
            break;

        case 's':
            ty -= 0.1f;
            break;

        // Rotation
        case 'r':
            angle += 10.0f;
            break;

        case 't':
            angle -= 10.0f;
            break;

        // Scaling
        case '+':
            sx += 0.1f;
            sy += 0.1f;
            break;

        case '-':
            sx -= 0.1f;
            sy -= 0.1f;

            if(sx < 0.1f)
            {
                sx = 0.1f;
                sy = 0.1f;
            }
            break;

        // Exit
        case 27:
            exit(0);
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

    glShadeModel(GL_SMOOTH);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("2D Polygon with Transformations");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
