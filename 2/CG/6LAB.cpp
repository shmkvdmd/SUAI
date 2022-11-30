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
bool   gp;                              // G Нажата? ( Новое )
GLuint filter;                          // Используемый фильтр для текстур
GLuint fogMode[] = { GL_EXP, GL_EXP2, GL_LINEAR }; // Хранит три типа тумана
GLuint fogfilter = 0;                    // Тип используемого тумана
GLfloat fogColor[4] = { 0.5f, 0.5f, 0.5f, 1.0f }; // Цвет тумана
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

void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'g':
        gp = TRUE;                    
        fogfilter += 1;                   
        if (fogfilter > 2)                 

        {
            fogfilter = 0;           
        }
        glFogi(GL_FOG_MODE, fogMode[fogfilter]); // Режим тумана
    case 'c':                 
        gp = FALSE;         
        break;
    }
}
void display(void)
{

    int i, j;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    glEnable(GL_FOG);                       // Включает туман (GL_FOG)

    glFogi(GL_FOG_MODE, fogMode[fogfilter]);// Выбираем тип тумана

    glFogfv(GL_FOG_COLOR, fogColor);        // Устанавливаем цвет тумана

    glFogf(GL_FOG_DENSITY, 0.35f);          // Насколько густым будет туман

    glHint(GL_FOG_HINT, GL_DONT_CARE);      // Вспомогательная установка тумана

    glFogf(GL_FOG_START, 1.0f);             // Глубина, с которой начинается туман

    glFogf(GL_FOG_END, 5.0f);               // Глубина, где туман заканчивается.
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
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(Keyboard);
    Sun();
    glutMainLoop();
    return 0;
}