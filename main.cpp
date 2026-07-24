#include <GL/glut.h>

// Transformation variables
float tx = 0.0f, ty = 0.0f;
float angle = 0.0f;
float sx = 1.0f, sy = 1.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Apply Transformations
    glTranslatef(tx, ty, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(sx, sy, 1.0f);

    // Draw Polygon
    glBegin(GL_POLYGON);

        glColor3f(1.0f, 0.0f, 0.0f);   // Red
        glVertex2f(-0.4f, -0.4f);

        glColor3f(0.0f, 1.0f, 0.0f);   // Green
        glVertex2f(0.4f, -0.4f);

        glColor3f(0.0f, 0.0f, 1.0f);   // Blue
        glVertex2f(0.5f, 0.4f);

        glColor3f(1.0f, 1.0f, 0.0f);   // Yellow
        glVertex2f(-0.5f, 0.4f);

    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Translation
        case 'a': tx -= 0.1f; break;
        case 'd': tx += 0.1f; break;
        case 'w': ty += 0.1f; break;
        case 's': ty -= 0.1f; break;

        // Rotation
        case 'r': angle += 10.0f; break;
        case 't': angle -= 10.0f; break;

        // Scaling
        case '+':
            sx += 0.1f;
            sy += 0.1f;
            break;

        case '-':
            sx -= 0.1f;
            sy -= 0.1f;
            if(sx < 0.1f) sx = sy = 0.1f;
            break;

        case 27:   // ESC key
            exit(0);
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);

    // Enable Smooth Shading
    glShadeModel(GL_SMOOTH);
}

int main(int argc, char** argv)
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
