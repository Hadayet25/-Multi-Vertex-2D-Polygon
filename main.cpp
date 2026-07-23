#include <GL/glut.h>
#include <math.h>

float tx = 0.0f, ty = 0.0f;      // Translation
float angle = 0.0f;              // Rotation
float sx = 1.0f, sy = 1.0f;      // Scaling

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Apply Transformations
    glTranslatef(tx, ty, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(sx, sy, 1.0f);

    // Draw Polygon (Hexagon)
    glColor3f(0.2f, 0.7f, 1.0f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.3f,  0.5f);
        glVertex2f( 0.3f,  0.5f);
        glVertex2f( 0.6f,  0.0f);
        glVertex2f( 0.3f, -0.5f);
        glVertex2f(-0.3f, -0.5f);
        glVertex2f(-0.6f,  0.0f);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a':
            tx -= 0.05f;
            break;

        case 'd':
            tx += 0.05f;
            break;

        case 'w':
            ty += 0.05f;
            break;

        case 's':
            ty -= 0.05f;
            break;

        case 'r':
            angle += 10.0f;
            break;

        case 't':
            angle -= 10.0f;
            break;

        case '+':
            sx += 0.1f;
            sy += 0.1f;
            break;

        case '-':
            sx -= 0.1f;
            sy -= 0.1f;
            if (sx < 0.1f)
            {
                sx = 0.1f;
                sy = 0.1f;
            }
            break;

        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2, 2, -2, 2);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("2D Polygon - Translation, Rotation & Scaling");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
