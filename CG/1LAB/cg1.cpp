#include <iostream>
#include <GL/glut.h>
#define IDI_ICON2  
#define GL_GLEXT_PROTOTYPES

double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;

void drawFloor()
{
    // пол
   //передняя
    glBegin(GL_POLYGON);
    glColor3ub(255, 160, 122);
    glVertex3f(0.8, -0.7, -0.6);
    glVertex3f(-0.8, -0.7, -0.6);
    glVertex3f(-0.8, -0.9, -0.6);
    glVertex3f(0.8, -0.9, -0.6);
    glEnd();
    //верхушка
    glBegin(GL_POLYGON);
    glColor3ub(255, 160, 122);
    glVertex3f(0.8, -0.7, -0.6);
    glVertex3f(-0.8, -0.7, -0.6);
    glVertex3f(-0.8, -0.7, 0.6);
    glVertex3f(0.8, -0.7, 0.6);
    glEnd();
    //задняя
    glBegin(GL_POLYGON);
    glColor3ub(255, 160, 122);
    glVertex3f(0.8, -0.7, 0.6);
    glVertex3f(-0.8, -0.7, 0.6);
    glVertex3f(-0.8, -0.9, 0.6);
    glVertex3f(0.8, -0.9, 0.6);
    glEnd();
    //левая
    glBegin(GL_POLYGON);
    glColor3ub(255, 160, 122);
    glVertex3f(-0.8, -0.7, -0.6);
    glVertex3f(-0.8, -0.7, 0.6);
    glVertex3f(-0.8, -0.9, 0.6);
    glVertex3f(-0.8, -0.9, -0.6);
    glEnd();

    //правая
    glBegin(GL_POLYGON);
    glColor3ub(255, 160, 122);
    glVertex3f(0.8, -0.7, -0.6);
    glVertex3f(0.8, -0.7, 0.6);
    glVertex3f(0.8, -0.9, 0.6);
    glVertex3f(0.8, -0.9, -0.6);
    glEnd();
    //низ
    glBegin(GL_POLYGON);
    glColor3ub(255, 160, 122);
    glVertex3f(0.8, -0.9, -0.6);
    glVertex3f(-0.8, -0.9, -0.6);
    glVertex3f(-0.8, -0.9, 0.6);
    glVertex3f(0.8, -0.9, 0.6);
    glEnd();
}
void drawDiamond()
{
    float diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    float specular[] = { 0.0, 0.0, 0.0, 1.0 };
    float ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    //передняя сторона
    glBegin(GL_POLYGON);
    glColor3ub(21, 186, 188);
    glVertex3f(0.0, -0.7, 0.0);
    glVertex3f(0.5, 0.0, -0.5);
    glVertex3f(-0.5, 0.0, -0.5);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 170, 171);
    glVertex3f(0.4, 0.2, -0.3);
    glVertex3f(-0.4, 0.2, -0.3);
    glVertex3f(-0.5, 0.0, -0.5);
    glVertex3f(0.5, 0.0, -0.5);
    glEnd();

    //задняя сторона
    glBegin(GL_POLYGON);
    glColor3ub(0, 206, 209);
    glVertex3f(0.0, -0.7, 0.0);
    glVertex3f(0.5, 0.0, 0.5);
    glVertex3f(-0.5, 0.0, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(32, 178, 170);
    glVertex3f(0.4, 0.2, 0.3);
    glVertex3f(-0.4, 0.2, 0.3);
    glVertex3f(-0.5, 0.0, 0.5);
    glVertex3f(0.5, 0.0, 0.5);
    glEnd();

    //правая
    glBegin(GL_POLYGON);
    glColor3ub(31, 228, 230);
    glVertex3f(0.0, -0.7, 0.0);
    glVertex3f(0.5, 0.0, -0.5);
    glVertex3f(0.5, 0.0, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 196, 186);
    glVertex3f(0.4, 0.2, 0.3);
    glVertex3f(0.4, 0.2, -0.3);
    glVertex3f(0.5, 0.0, -0.5);
    glVertex3f(0.5, 0.0, 0.5);
    glEnd();
    //левая
    glBegin(GL_POLYGON);
    glColor3ub(64, 224, 208);
    glVertex3f(0.0, -0.7, 0.0);
    glVertex3f(-0.5, 0.0, -0.5);
    glVertex3f(-0.5, 0.0, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(11, 157, 149);
    glVertex3f(-0.4, 0.2, 0.3);
    glVertex3f(-0.4, 0.2, -0.3);
    glVertex3f(-0.5, 0.0, -0.5);
    glVertex3f(-0.5, 0.0, 0.5);
    glEnd();

    //верхушка
    glBegin(GL_POLYGON);
    glColor3ub(24, 239, 227);
    glVertex3f(0.4, 0.2, 0.3);
    glVertex3f(-0.4, 0.2, 0.3);
    glVertex3f(-0.4, 0.2, -0.3);
    glVertex3f(0.4, 0.2, -0.3);
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
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    drawFloor();
    drawDiamond();
    glFlush();  

}
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    glutInit(&argc, argv);
    glutInitWindowPosition(550, 150);
    glutInitWindowSize(800, 800);
    glutCreateWindow("три дэ");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;

}