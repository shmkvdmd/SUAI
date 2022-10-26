#include <iostream>
#include <GL/glut.h>
#define IDI_ICON2  
#define GL_GLEXT_PROTOTYPES

double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;
GLfloat mat_amb_diff[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };

GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_diffuse2[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat light_position[] = { 1.0, 0.0, 0.0, 0.0 };
GLfloat light_position2[] = { 0.0, 1.0, 0.0, 0.0 };
void init(void)

{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    static float lmodel_twoside[] = { GL_TRUE };
    static float lmodel_oneside[] = { GL_FALSE };
    static float ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    static float diffuse[] = { 1.0f, 0.0, 0.0, 1.0 };
    static float position[] = { -2.0, 1.0, 1.0f, 0.0 };

    static float ambient1[] = { 0.3, 0.3, 0.3, 1.0 };
    static float diffuse1[] = { 0.0, 1.0, 0.0, 1.0 };
    static float position1[] = { 1.0,1.0, 1.0f, 0.0 };

    static float ambient2[] = { 0.4, 0.4, 0.4, 1.0 };
    static float diffuse2[] = { 0.0, 0.0, 1.0, 1.0 };
    static float position2[] = { 2.0,1.0, 1.0f, 0.0 };


    static float front_mat_shininess[] =
    { 60.0 };
    static float front_mat_specular[] =
    { 0.2, 0.2, 0.2, 1.0 };
    static float front_mat_diffuse[] =
    { 0.5, 0.5, 0.28, 1.0 };
    static float back_mat_shininess[] =
    { 60.0 };
    static float back_mat_specular[] =
    { 0.5, 0.5, 0.2, 1.0 };
    static float back_mat_diffuse[] =
    { 1.0, 0.9, 0.2, 1.0 };

    static float lmodel_ambient[] =
    { 1.0, 1.0, 1.0, 1.0 };

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT1, GL_POSITION, position1);

    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
    glLightfv(GL_LIGHT2, GL_POSITION, position2);

    glMaterialfv(GL_FRONT, GL_SHININESS, front_mat_shininess);
    glMaterialfv(GL_FRONT, GL_SPECULAR, front_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, front_mat_diffuse);
    glMaterialfv(GL_BACK, GL_SHININESS, back_mat_shininess);
    glMaterialfv(GL_BACK, GL_SPECULAR, back_mat_specular);
    glMaterialfv(GL_BACK, GL_DIFFUSE, back_mat_diffuse);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, lmodel_twoside);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glShadeModel(GL_SMOOTH);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_DEPTH_TEST);


    glPushMatrix();
    glTranslatef(0.0f, -0.7f, 0.0f);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glutSolidSphere(0.35,20,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.7f, 0.0f);
    glutSolidTorus(0.1,0.2,40,40);
    glPopMatrix();


    glutSwapBuffers();
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