#include <iostream>
#include <GL/glut.h>
#include <glaux.h>
#pragma comment(lib,"GLAUX.LIB")
#define IDI_ICON2  
#define GL_GLEXT_PROTOTYPES
int  PI = 3.145;
int y = 0;
int Angle = 0.0;
int Angle1 = 0.0;
int Angle2 = 0.0;
int Angle3 = 0.0;
GLUnurbsObj* theNurb;
const int size_numb_x = 4;
const int size_numb_y = 4;
GLuint texture[1];
bool FogFlag = true;                             
GLuint filter;                          
GLuint fogfilter = 0;                  
GLfloat fogColor[3] = { 0.8f, 0.8f, 0.8f }; // Цвет тумана
GLfloat ctlpoints[size_numb_x][size_numb_y][3];
GLfloat knots[size_numb_x + size_numb_y] = {
  0.0, 0.0, 0.0, 0.0,
  1.0, 1.0, 1.0, 1.0
};
int showPoints = 0;
GLfloat ctrlpoints[4][4][3] = {
{{-3.5, 1.0, -4.5},  {-0.5, 1.0,-4.5 }, {0.5, 1.0, -4.5 },   {3.5, 1.0,-4.5}},
{{-3.5, 1.0, -0.5},  {-0.5, -2.0 - y,-0.5 }, {0.5, -2.0 - y, -0.5 }, {3.5, 1.0,-0.5}},
{{-3.5, 1.0,  0.5},  {-0.5, 1.0, 0.5 }, {0.5, 1.0,  0.5 },   {3.5, 1.0, 0.5}},
{{-3.5, 1.0,  4.5},  {-0.5, 1.0, 4.5 }, {0.5, 1.0,  4.5 },   {3.5, 1.0, 4.5}}
};
GLfloat mat_amb_diff[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };

GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_diffuse2[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat light_position[] = { 1.0, 0.0, 0.0, 0.0 };
GLfloat light_position2[] = { 0.0, 1.0, 0.0, 0.0 };


void init2(void)

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
GLvoid LoadGLTextures()
{
    // Загрузка картинки
    AUX_RGBImageRec* texture1;
    texture1 = auxDIBImageLoadA("Texture.bmp");
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);

}
void Sun() {
    LoadGLTextures();
    glEnable(GL_TEXTURE_2D);
    glNewList(1, GL_COMPILE);
    glPushMatrix();
    glTranslatef(-1.5, 1, 0);
    glRotatef(2 * PI, 1, 0, 0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    glTranslatef(1.2, 1, 0.0);
    glEndList();
}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
    {
        glDisable(GL_FOG);
        glClearColor(0.0, 0.0, 0.0, 0.0);
    }
    else if (key == GLUT_KEY_LEFT)
    {
        glEnable(GL_FOG);
        glFogi(GL_FOG_MODE, GL_LINEAR);
        glFogfv(GL_FOG_COLOR, fogColor);
        glFogf(GL_FOG_DENSITY, 2.0f);
        glFogf(GL_FOG_START, 0.0f);
        glFogf(GL_FOG_END, 3.0f);
    }

    glutPostRedisplay();
}
void display(void)
{

    int i, j;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);          
    glPushMatrix();
    glRotatef(45.0, 1.0, 1.0, 1.0);
    for (j = 0; j <= 30; j++) {
        glBegin(GL_LINE_STRIP);
        for (i = 0; i <= 100; i++)
            glEvalCoord2f((GLfloat)i / 100.0, (GLfloat)j / 30.0);
        glEnd(); 
        glBegin(GL_LINE_STRIP);
        for (i = 0; i <= 100; i++)
            glEvalCoord2f((GLfloat)j / 30.0, (GLfloat)i / 100.0);
        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    for (int i = 0; i < 3; i++)
    {
        glCallList(1);
    }
    Sun();
    glPopMatrix();

    glFlush();

}
void initMap(void)
{
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
}


void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    initMap();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w, 5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
    else
        glOrtho(-5.0 * (GLfloat)w / (GLfloat)h, 5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    theNurb = gluNewNurbsRenderer();
    gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0);
    gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);
    init();
    init2();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    Sun();
    glutMainLoop();
    return 0;
}