#include <GL/glut.h>
//##include <windows..h>>  only for Windows system

int init(void) {

    glClearColor(1.0, 1.0, 1.0, 0.0); // set background color to white
    glMatrixMode(GL_PROJECTION); // set projection parameters
    gluOrtho2D(-300.0, 250.0, -250.0, 250.0); // set 2D orthographic projection
    return 0;
}

void Ex1()
{
    glTranslatef(30.0, 20.0, 0.0);

    glBegin(GL_TRIANGLES); //se dibuja un poligono
    glVertex2f(50.0, 50.0);
    glVertex2f(100.0, 100.0);
    glVertex2f(150.0, 50.0);
}

void Ex2()
{
    glTranslatef(75.0, 75.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glTranslatef(-75.0, -75.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(50.0, 50.0);
    glVertex2f(100.0, 50.0);
    glVertex2f(100.0, 100.0);
    glVertex2f(50.0, 100.0);

}

void Ex3()
{
    glTranslatef(20.0, 30.0, 0.0);
    glScalef(1.5, 2.0, 1.0);
    glTranslatef(-20.0, -30.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(20.0, 30.0);
    glVertex2f(120.0, 30.0);
    glVertex2f(120.0, 80.0);
    glVertex2f(20.0, 80.0);
}

void Ex4()
{
    float matrixReflection[] = {
        -1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };
        
    glMultMatrixf(matrixReflection);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(40.0, 40.0);
    glVertex2f(90.0, 100.0);
    glVertex2f(140.0, 40.0);
}

void Ex5()
{
    float shX = 1.0;

    float matrixShear[] = {
        1.0, 0.0, 0.0, 0.0, //primera columna
        shX, 1.0, 0.0, 0.0, //segunda columna
        0.0, 0.0, 1.0, 0.0, //tecera columna
        0.0, 1.0, 0.0, 1.0 // cuarta columna
    };
    
    glMultMatrixf(matrixShear);

    glBegin(GL_POLYGON);
    glVertex2f(50.0, 50.0);
    glVertex2f(100.0, 50.0);
    glVertex2f(100.0, 100.0);
    glVertex2f(50.0, 100.0);
}

void Ex6()
{
    float shY = 0.5;

    float matrixShear[] = {
        1.0, shY, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 1.0
    };

    glMultMatrixf(matrixShear);

    glBegin(GL_POLYGON);
    glVertex2f(50.0, 50.0);
    glVertex2f(100.0, 50.0);
    glVertex2f(100.0, 100.0);
    glVertex2f(50.0, 100.0);
}

void Ex7()
{
    
    glTranslatef(20.0, -10.0, 0.0);

    glTranslatef(30.0, 40.0, 0.0);
    glScalef(2.0, 1.5, 1.0);
    glTranslatef(-30.0, -40.0, 0.0);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(30.0, 40.0);
    glVertex2f(80.0, 120.0);
    glVertex2f(130.0, 40.0);
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT); // clear display window
    glColor3f(1.0, 0.0, 0.0); // set color to black
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //transformaciones que aplicaremos. LAS ESCALAS ROTACIONES ETC, SE EJECUTAN DE ABAJO A ARRIBA

    /////////////////EJERCICIOS/////////////////
    //Ex1();
    //Ex2();
    //Ex3();
    //Ex4();
    //Ex5();
    Ex6();
    //Ex7();


    glEnd(); // end drawing points
    glFlush(); // force execution of OpenGL commands in finite time
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // start glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode - single buffer, RGB  color
    glutInitWindowSize(400, 300); // set window size
    glutInitWindowPosition(400, 400); // set window position

    //Create the window        
    glutCreateWindow("Transformations 2D"); // create window

    init(); // initialize
    glutDisplayFunc(display); // set display callback
    glutMainLoop(); // enter event loop


    return 0;
}