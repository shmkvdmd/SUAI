#include <iostream>
#include <GL/glut.h>
#define IDI_ICON2  
#define GL_GLEXT_PROTOTYPES

double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;
GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light0_diffuse[] = { 0.4, 0.7, 0.2 };
GLfloat light0_position[] = { 0.0, 0.0, 1.0, 1.0 };
void init(void)

{
    glEnable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
}
void draw()
{
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.4, 1);
    glVertex3f(-1, 6, 0.5);
    glVertex3f(-6, 6, 0.5);
    glVertex3f(-6, 1, 0.5);
    glVertex3f(-1, 1, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.4, 1);
    glVertex3f(6, 6, 0.5);
    glVertex3f(1, 6, 0.5);
    glVertex3f(1, 1, 0.5);
    glVertex3f(6, 1, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.4, 1);
    glVertex3f(-1, -6, 0.5);
    glVertex3f(-6, -6, 0.5);
    glVertex3f(-6, -1, 0.5);
    glVertex3f(-1, -1, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.4, 1);
    glVertex3f(6, -6, 0.5);
    glVertex3f(1,-6, 0.5);
    glVertex3f(1, -1, 0.5);
    glVertex3f(6, -1, 0.5);
    glEnd();
}

void specialKeys(int key, int x, int y) {

    if (key == GLUT_KEY_RIGHT)
        rotate_y += 3;

    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 3;

    else if (key == GLUT_KEY_UP)
        rotate_x += 3;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 3;
    glutPostRedisplay();

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glFrustum(-8, 8, -8, 8, 3, 10);		//видовые параметры
    glTranslatef(0.0, 0.0, -5.0);		//начальный сдвиг системы координат
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.4);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    draw();
    glFlush();

}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(550, 150);
    glutInitWindowSize(800, 800);
    glutCreateWindow("3d");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;

}