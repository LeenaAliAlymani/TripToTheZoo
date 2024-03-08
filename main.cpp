
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>      // handle the window-managing operations
#else
#include <GL/glew.h>
#include <GL/freeglut.h>    // handle the window-managing operations
#endif
#include <stdlib.h>
#include <iostream>

using namespace std;


GLint win_width = 500,
win_hight = 500;

GLdouble PI = 3.14159265359;

//السلحفاه
float TurtleTransValue1;
float TurtleTransValue2;

//بطريق
float ptransValue4;
float ptransValue5;

//غنمه
float StransValue2;
float StransValue3;

//البسه
float CtransValue;
float CscaleValue;

//البقره
float transValue2;
float transValue3;

//الباندا
float transValuep = 0.0;
float transValue1p = 0.0;
float scaleValuep;


//for scene 1
GLfloat transValueforChild = 0.0
, transValueforClouds = 0.0
, scaleValueforChild = 0.9

//for scene 7
, transValueforChild2 = 0.4
, scaleValueforChild2 = 0.9
, transValueforClouds2 = 0.0;

////////////////
//  Functions //
////////////////


/*
 * Function that handles the drawing of a circle using the triangle fan
 * method. This will create a filled circle.
 *
 * Params:
 *    x (GLFloat) - the x position of the center point of the circle
 *    y (GLFloat) - the y position of the center point of the circle
 *    radius (GLFloat) - the radius that the painted circle will have
 *    function Source: https://gist.github.com/linusthe3rd/803118
 */
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

//for the child head
void drawHollowCircle0(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

//for the doorway
void drawHollowCircle2(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 1.0f * PI;

    glBegin(GL_LINE_STRIP);
    for (i = 0; i <= lineAmount; i++) {
        glLineWidth(1.0f);
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (0.4 * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

//for the child face
void drawHollowCircle1(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = -1.0f * PI;

    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount; i++) {
        glLineWidth(1.0f);
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

//for the child eyes
void drawHollowCircle3(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 1.0f * PI;

    glBegin(GL_LINE_STRIP);
    for (i = 0; i <= lineAmount; i++) {
        glLineWidth(1.0f);
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (0.009 * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

//for the ticeketcorner
void drawFilledCircle2(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat twicePi = 1.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void drawHalfFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 1.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void drawLOWERHalfFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 1.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y - (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

/*
 * Function that handles the drawing of a circle using the line loop
 * method. This will create a hollow circle.
 *
 * Params:
 *    x (GLFloat) - the x position of the center point of the circle
 *    y (GLFloat) - the y position of the center point of the circle
 *    radius (GLFloat) - the radius that the painted circle will have
 *    function Source: https://gist.github.com/linusthe3rd/803118
 */
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void drawHalfHollowCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 1.0f * PI;

    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y + (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void drawLOWERHalfHollowCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 1.0f * PI;

    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / lineAmount)),
            y - (radius * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void Fill(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (0.04 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void FillHeat(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (0.04 * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Fillnat(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (0.09 * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void HollowNewCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int lineAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = -1.0f * PI;

    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= lineAmount; i++) {
        glVertex2f(
            x + (0.08 * cos(i * twicePi / lineAmount)),
            y + (0.08 * sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//السلحفاه

void TurtleEnvironment()
{
    //the زرع (الخلفيه)
    glBegin(GL_QUADS);
    glColor3f(0.09f, 0.5f, 0.21f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    //the sand
    glBegin(GL_QUADS);
    glColor3f(0.9686f, 0.9882f, 0.7294f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();

    glColor3f(0.4156, 0.7725, 0.9764f);
    drawFilledCircle(-0.3, 0.07, .350);

    glColor3f(0.4156, 0.7725, 0.9764f);
    drawFilledCircle(-0.9, 0.1, .40);

    glColor3f(0.4156, 0.7725, 0.9764f);
    drawFilledCircle(-0.5, 0.07, .360);

    glColor3f(0.4156, 0.7725, 0.9764f);
    drawFilledCircle(-0.1, 0.3, .20);

    //مربع ما تحت السما
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(-1.0f, 0.4f);
    glEnd();

    //السما
    glBegin(GL_QUADS);

    glColor4f(0.64, 0.91, 0.98, 0.9);
    glVertex2f(-1.0f, 1.0f);

    glColor4f(0.91, 0.78, 0.12, 0.3);
    glVertex2f(1.0f, 1.0f);

    glColor4f(0.1, 0.91, 0.54, 0.058);
    glVertex2f(1.0f, 0.4f);

    glColor4f(0.1, 0.91, 0.78, 0.42);
    glVertex2f(-1.0f, 0.4f);

    glEnd();

    //السحاب
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.9, 0.8, .10);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.75, 0.87, .10);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.6, 0.92, .10);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.45, 0.87, .10);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.3, 0.8, .10);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.9f, 0.7f);
    glVertex2f(0.9f, 0.9f);
    glVertex2f(0.3f, 0.9f);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.9, 0.75, .07);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.79, 0.82, .07);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.68, 0.87, .07);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.57, 0.82, .07);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.46, 0.75, .07);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-0.9f, 0.68f);
    glVertex2f(-0.9f, 0.82f);
    glVertex2f(-0.5f, 0.82f);
    glEnd();

    //عواميد السور
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.9f, -0.6f);
    glVertex2f(-0.8f, -0.6f);
    glVertex2f(-0.8f, -0.2f);
    glVertex2f(-0.9f, -0.2f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, -0.6f);
    glVertex2f(-0.9f, -0.6f);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.8f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.6f, -0.2f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.5f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.3f, -0.6f);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.3f, -0.2f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(-0.3f, -0.6f);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.2f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.0f, -0.6f);
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.1f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.0f, -0.6f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.1f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.3f, -0.6f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.3f, -0.2f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(0.3f, -0.6f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.6f, -0.2f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(0.6f, -0.2f);
    glVertex2f(0.7f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.9f, -0.6f);
    glVertex2f(0.99f, -0.6f);
    glVertex2f(0.99f, -0.2f);
    glVertex2f(0.9f, -0.2f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.99f, -0.6f);
    glVertex2f(0.9f, -0.6f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.99f, -0.2f);
    glEnd();

    //السور
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-1.0f, -0.35f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(1.0f, -0.45f);
    glVertex2f(-1.0f, -0.45f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.35f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(1.0f, -0.45f);
    glVertex2f(-1.0f, -0.45f);
    glEnd();

    //الصخور
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.9f, 0.49f);
    glVertex2f(0.73f, 0.45f);
    glVertex2f(0.99f, 0.3f);
    glVertex2f(0.68f, 0.3f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(0.9f, 0.49f);
    glVertex2f(0.8f, 0.45f);
    glVertex2f(0.99f, 0.3f);
    glVertex2f(0.75f, 0.3f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(0.85f, 0.37f);
    glVertex2f(0.75f, 0.32f);
    glVertex2f(0.94f, 0.18f);
    glVertex2f(0.69f, 0.28f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(0.85f, 0.37f);
    glVertex2f(0.78f, 0.32f);
    glVertex2f(0.94f, 0.18f);
    glVertex2f(0.72f, 0.28f);
    glEnd();

}
void the1stTurtle()
{
    //الرجول
    //اللي ورا
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.725, 0.4f);
    glVertex2f(0.32, 0.2);
    glVertex2f(0.36, 0.2);
    glVertex2f(0.36, 0.018);
    glVertex2f(0.32, 0.018);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.32, 0.2);
    glVertex2f(0.36, 0.2);
    glVertex2f(0.36, 0.018);
    glVertex2f(0.32, 0.018);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.725, 0.4f);
    glVertex2f(0.28, 0.12);
    glVertex2f(0.324, 0.12);
    glVertex2f(0.324, 0.008);
    glVertex2f(0.28, 0.008);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.28, 0.12);
    glVertex2f(0.324, 0.12);
    glVertex2f(0.324, 0.008);
    glVertex2f(0.28, 0.008);
    glEnd();

    //اللي قدام
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.725, 0.4f);
    glVertex2f(0.452, 0.2);
    glVertex2f(0.499, 0.2);
    glVertex2f(0.499, 0.018);
    glVertex2f(0.452, 0.018);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.452, 0.2);
    glVertex2f(0.499, 0.2);
    glVertex2f(0.499, 0.018);
    glVertex2f(0.452, 0.018);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.725, 0.4f);
    glVertex2f(0.42, 0.12);
    glVertex2f(0.464, 0.12);
    glVertex2f(0.464, 0.008);
    glVertex2f(0.42, 0.008);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.42, 0.12);
    glVertex2f(0.464, 0.12);
    glVertex2f(0.464, 0.008);
    glVertex2f(0.42, 0.008);
    glEnd();

    //الذيل
    glColor3f(0.6, 0.725, 0.4f);
    drawFilledCircle(0.22, 0.05, 0.02);
    glColor3f(0.2862, 0.4470, 0.1019);
    drawHollowCircle(0.22, 0.05, 0.02);

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.725, 0.4f);
    glVertex2f(0.22f, 0.07f);
    glVertex2f(0.22f, 0.03f);
    glVertex2f(0.3f, 0.08f);
    glEnd();

    //الجسم
    glColor3f(0.6, 0.725, 0.4f);
    drawHalfFilledCircle(0.4, 0.1, .15);

    glColor3f(0.2862, 0.4470, 0.1019);
    drawHalfHollowCircle(0.4, 0.1, .15);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.725, 0.4f);
    glVertex2f(0.25, 0.12);
    glVertex2f(0.554, 0.12);
    glVertex2f(0.554, 0.06);
    glVertex2f(0.25, 0.06);
    glEnd();
    //الحدود
    glBegin(GL_LINES);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.25, 0.12);
    glVertex2f(0.25, 0.06);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.554, 0.06);
    glVertex2f(0.25, 0.06);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.554, 0.06);
    glVertex2f(0.554, 0.12);
    glEnd();

    //الراس
    glColor3f(0.6, 0.725, 0.4f);
    drawFilledCircle(0.6, 0.13, 0.05);
    glColor3f(0.2862, 0.4470, 0.1019);
    drawHollowCircle(0.6, 0.13, 0.05);

    //نتوئات الظهر
    glBegin(GL_QUADS);
    glColor4f(0.2862, 0.4470, 0.1019, 0.5);
    glVertex2f(0.26, 0.06);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.34, 0.12);
    glVertex2f(0.37, 0.06);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.26, 0.06);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.34, 0.12);
    glVertex2f(0.37, 0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.2862, 0.4470, 0.1019, 0.5);
    glVertex2f(0.4, 0.06);
    glVertex2f(0.39, 0.1);
    glVertex2f(0.45, 0.12);
    glVertex2f(0.51, 0.06);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.4, 0.06);
    glVertex2f(0.39, 0.1);
    glVertex2f(0.45, 0.12);
    glVertex2f(0.51, 0.06);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.2862, 0.4470, 0.1019, 0.5);
    glVertex2f(0.37, 0.12);
    glVertex2f(0.31, 0.15);
    glVertex2f(0.42, 0.2);
    glVertex2f(0.45, 0.14);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.37, 0.12);
    glVertex2f(0.31, 0.15);
    glVertex2f(0.42, 0.2);
    glVertex2f(0.45, 0.14);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.2862, 0.4470, 0.1019, 0.5);
    glVertex2f(0.5, 0.09);
    glVertex2f(0.46, 0.18);
    glVertex2f(0.51, 0.2);
    glVertex2f(0.54, 0.14);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.5, 0.09);
    glVertex2f(0.46, 0.18);
    glVertex2f(0.51, 0.2);
    glVertex2f(0.54, 0.14);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.2862, 0.4470, 0.1019, 0.5);
    glVertex2f(0.35, 0.19);
    glVertex2f(0.28, 0.18);
    glVertex2f(0.3, 0.21);
    glVertex2f(0.42, 0.25);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.35, 0.19);
    glVertex2f(0.28, 0.18);
    glVertex2f(0.3, 0.21);
    glVertex2f(0.42, 0.25);
    glEnd();

    //العيون
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.62, 0.15, 0.015);
    glColor3f(0.2862, 0.4470, 0.1019);
    drawHollowCircle(0.62, 0.15, 0.015);

    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.62, 0.15, 0.009);

    //الفم
    glBegin(GL_LINES);
    glColor3f(0.2862, 0.4470, 0.1019);
    glVertex2f(0.64, 0.11);
    glVertex2f(0.6, 0.11);
    glEnd();
}

void the2ndTurtle()
{
    //الذيل
    glColor3f(0.6, 0.725, 0.4f);
    drawFilledCircle(-0.16, 0.05, 0.02);
    glColor3f(0.2862, 0.4470, 0.1019);
    drawHollowCircle(-0.16, 0.05, 0.02);

    //الجسم
    glColor3f(0.6627, 0.5333, 0.1764);
    drawFilledCircle(-0.32, 0.05, 0.1);
    glColor3f(0.6, 0.4, 0.2);
    drawHollowCircle(-0.32, 0.05, 0.1);

    glColor3f(0.6627, 0.5333, 0.1764);
    drawFilledCircle(-0.22, 0.05, 0.05);
    glColor3f(0.6, 0.4, 0.2);
    drawHollowCircle(-0.22, 0.05, 0.05);

    glBegin(GL_QUADS);
    glColor3f(0.6627, 0.5333, 0.1764);
    glVertex2f(-0.3, 0.0);
    glVertex2f(-0.25, 0.0);
    glVertex2f(-0.18, 0.08);
    glVertex2f(-0.28, 0.14);
    glEnd();

    //مربع ازرق لإخفاء الكرشه
    glBegin(GL_QUADS);
    glColor3f(0.4156, 0.7725, 0.9764f);
    glVertex2f(-0.4, -0.02);
    glVertex2f(-0.22, -0.0);
    glVertex2f(-0.18, -0.08);
    glVertex2f(-0.28, -0.14);
    glEnd();

    //الرجول
    //مخليتها شفافه شويا عشان يعنني انها تحت المويا
    glBegin(GL_QUADS);
    glColor4f(0.6, 0.725, 0.4, 0.4);
    glVertex2f(-0.34, -0.05);
    glVertex2f(-0.38, -0.05);
    glVertex2f(-0.38, -0.0);
    glVertex2f(-0.34, -0.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.2862, 0.4470, 0.1019, 0.4);
    glVertex2f(-0.34, -0.05);
    glVertex2f(-0.38, -0.05);
    glVertex2f(-0.38, -0.0);
    glVertex2f(-0.34, -0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor4f(0.6, 0.725, 0.4f, 0.4);
    glVertex2f(-0.35, -0.05);
    glVertex2f(-0.35, -0.018);
    glVertex2f(-0.25, -0.015);
    glEnd();
    glBegin(GL_LINES);
    glColor4f(0.2862, 0.4470, 0.1019, 0.4);
    glVertex2f(-0.34, -0.05);
    glVertex2f(-0.25, -0.015);
    glEnd();
    glBegin(GL_LINES);
    glColor4f(0.2862, 0.4470, 0.1019, 0.4);
    glVertex2f(-0.34, -0.018);
    glVertex2f(-0.25, -0.015);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.6, 0.725, 0.4f, 0.4);
    glVertex2f(-0.14, -0.01);
    glVertex2f(-0.16, -0.03);
    glVertex2f(-0.22, -0.0);
    glVertex2f(-0.18, 0.02);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.2862, 0.4470, 0.1019, 0.4);
    glVertex2f(-0.14, -0.01);
    glVertex2f(-0.16, -0.03);
    glVertex2f(-0.22, -0.0);
    glVertex2f(-0.18, 0.02);
    glEnd();

    //الراس
    glColor3f(0.650, 0.75, 0.4);
    drawFilledCircle(-0.42, 0.05, 0.06);
    glColor3f(0.2862, 0.4470, 0.1019);
    drawHollowCircle(-0.42, 0.05, 0.06);

    //العيون
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.4, 0.08, 0.015);
    glColor3f(0.2862, 0.4470, 0.1019);
    drawHollowCircle(-0.4, 0.08, 0.015);
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(-0.4, 0.08, 0.009);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.44, 0.08, 0.015);
    glColor3f(0.2862, 0.4470, 0.1019);
    drawHollowCircle(-0.44, 0.08, 0.015);
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(-0.44, 0.08, 0.009);

    //الفم
    glColor3f(0.0, 0.0, 0.0);
    drawLOWERHalfFilledCircle(-0.42, 0.04, 0.03);

    //نتوئات الظهر
    glBegin(GL_QUADS);
    glColor4f(0.4745, 0.3725, 0.0352, 0.5);
    glVertex2f(-0.26, 0.08);
    glVertex2f(-0.3, 0.14);
    glVertex2f(-0.34, 0.15);
    glVertex2f(-0.37, 0.1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.4745, 0.3725, 0.0352);
    glVertex2f(-0.26, 0.08);
    glVertex2f(-0.3, 0.14);
    glVertex2f(-0.34, 0.15);
    glVertex2f(-0.37, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.4745, 0.3725, 0.0352, 0.5);
    glVertex2f(-0.27, 0.02);
    glVertex2f(-0.26, 0.06);
    glVertex2f(-0.32, 0.08);
    glVertex2f(-0.37, 0.02);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.4745, 0.3725, 0.0352);
    glVertex2f(-0.27, 0.02);
    glVertex2f(-0.26, 0.06);
    glVertex2f(-0.32, 0.08);
    glVertex2f(-0.37, 0.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.4745, 0.3725, 0.0352, 0.5);
    glVertex2f(-0.22, 0.0);
    glVertex2f(-0.18, 0.07);
    glVertex2f(-0.23, 0.09);
    glVertex2f(-0.23, 0.05);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.4745, 0.3725, 0.0352);
    glVertex2f(-0.22, 0.0);
    glVertex2f(-0.18, 0.07);
    glVertex2f(-0.23, 0.09);
    glVertex2f(-0.23, 0.05);
    glEnd();
}

void TurtleInfo() {
    //عامود اللوحه
    glBegin(GL_QUADS);
    glColor3f(0.4745, 0.3725, 0.0352);
    glVertex2f(0.05, -0.1);
    glVertex2f(-0.05, -0.1);
    glVertex2f(-0.05, -0.7);
    glVertex2f(0.05, -0.7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.05, -0.1);
    glVertex2f(-0.05, -0.1);
    glVertex2f(-0.05, -0.7);
    glVertex2f(0.05, -0.7);
    glEnd();
    //لوحه المعلومات
    glBegin(GL_QUADS);
    glColor3f(0.4745, 0.3725, 0.0352);
    glVertex2f(-0.27, 0.1);
    glVertex2f(0.27, 0.1);
    glVertex2f(0.27, -0.25);
    glVertex2f(-0.27, -0.25);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.27, 0.1);
    glVertex2f(0.27, 0.1);
    glVertex2f(0.27, -0.25);
    glVertex2f(-0.27, -0.25);
    glEnd();

    //معلومات السلحفاه
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.25, 0.05);
    const char* text1 = "Name: turtle";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text1);
        text1++;
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.25, 0.0);
    const char* text2 = "Subfamily: reptile";
    while (*text2) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text2);
        text2++;
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.25, -0.05);
    const char* text3 = "Location: All over the world";
    while (*text3) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text3);
        text3++;
    }

    glRasterPos2f(-0.25, -0.1);
    const char* text4 = "Food : Herbivore";
    while (*text4) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text4); // Use the desired font size
        text4++;
    }

    glRasterPos2f(-0.25, -0.15);
    const char* text5 = "What characterizes it: its ";
    while (*text5) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text5); // Use the desired font size
        text5++;
    }

    glRasterPos2f(-0.25, -0.2);
    const char* text6 = "structure consists of bone tissue";
    while (*text6) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text6); // Use the desired font size
        text6++;
    }

}
//--------------------------------------------------------------------------------------------------------------------------------------------------
//البطريق
void penguinBackround1() {
    //floor
    glColor3f(1, 1, 1);
    drawFilledCircle(0.2, 0.2, 0.5);
    drawFilledCircle(0.5, 0.2, 0.5);
    drawFilledCircle(0.8, 0.1, 0.5);
    drawFilledCircle(0.1, 0.3, 0.5);
    drawFilledCircle(-0.1, 0.1, 0.4);
    drawFilledCircle(-0.4, 0.2, 0.5);
    drawFilledCircle(-0.7, 0.2, 0.3);
    drawFilledCircle(-1.0, 0.2, 0.4);

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(-1.0, 0.27);
    glVertex2f(1.0, 0.27);
    glVertex2f(1.0, 0.37);
    glVertex2f(-1.0, 0.37);
    glEnd();
    drawFilledCircle(0.2, 0.09, 0.3);
    drawFilledCircle(0.5, 0.09, 0.3);
    drawFilledCircle(0.8, 0.09, 0.3);
    drawFilledCircle(-0.2, 0.09, 0.3);
    drawFilledCircle(-0.5, 0.09, 0.3);
    drawFilledCircle(-0.8, 0.09, 0.3);

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.75, 0.6);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 0.27);
    glVertex2f(-1.0, 0.27);
    glEnd();
}

void penguinSun() {
    glColor3f(1, 1, 0.2);
    drawFilledCircle(-0.9, 1.0, 0.17);
}

void penguinFence() {
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.94, -0.56);
    glVertex2f(1.0, -0.56);
    glVertex2f(1.0, -0.10);
    glVertex2f(0.94, -0.10);

    glVertex2f(0.7, -0.56);
    glVertex2f(0.79, -0.56);
    glVertex2f(0.79, -0.10);
    glVertex2f(0.7, -0.10);

    glVertex2f(0.4, -0.56);
    glVertex2f(0.49, -0.56);
    glVertex2f(0.49, -0.10);
    glVertex2f(0.4, -0.10);

    glVertex2f(0.1, -0.56);
    glVertex2f(0.19, -0.56);
    glVertex2f(0.19, -0.10);
    glVertex2f(0.1, -0.10);

    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.7, -0.56);
    glVertex2f(-0.79, -0.56);
    glVertex2f(-0.79, -0.10);
    glVertex2f(-0.7, -0.10);

    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.4, -0.56);
    glVertex2f(-0.49, -0.56);
    glVertex2f(-0.49, -0.10);
    glVertex2f(-0.4, -0.10);

    glVertex2f(-0.1, -0.56);
    glVertex2f(-0.19, -0.56);
    glVertex2f(-0.19, -0.10);
    glVertex2f(-0.1, -0.10);

    glVertex2f(-0.94, -0.56);
    glVertex2f(-1.0, -0.56);
    glVertex2f(-1.0, -0.10);
    glVertex2f(-0.94, -0.10);

    glVertex2f(-0.99, -0.27);
    glVertex2f(0.99, -0.27);
    glVertex2f(0.99, -0.40);
    glVertex2f(-0.99, -0.40);

    glEnd();
}

void penguinCloud() {
    glColor3f(1.0, 1.0, 1.0);
    //cloud 1
    drawFilledCircle(-0.2, 0.90, 0.06);
    drawFilledCircle(-0.4, 0.90, 0.06);
    drawFilledCircle(-0.3, 0.90, 0.09);
}

//draw the info button
void penguinInfo() {

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-1, 0.3);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.4, -0.05);
    glVertex2f(-1, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.75, 0.2);
    glVertex2f(-0.65, 0.2);
    glVertex2f(-0.65, -0.67);
    glVertex2f(-0.75, -0.67);
    glEnd();
}


void penguinSky() {

    glBegin(GL_QUADS);
    glColor4f(0.64, 0.91, 0.98, 0.9);
    glVertex2f(-1.0, 1.0);

    glColor4f(0.91, 0.78, 0.12, 0.3);
    glVertex2f(1.0, 1.0);

    glColor4f(0.91, 0.91, 0.54, 0.058);
    glVertex2f(1.0, -1.0);

    glColor4f(0.1, 0.91, 0.78, 0.12);
    glVertex2f(-1.0, -1.0);
}

void penguin() {
    //leg l
    glColor3f(1.0, 0.8, 0.2);
    drawFilledCircle(0.42, -0.64, 0.036);
    drawFilledCircle(0.44, -0.64, 0.036);
    drawFilledCircle(0.46, -0.64, 0.036);

    //leg r
    glColor3f(1.0, 0.8, 0.2);
    drawFilledCircle(0.68, -0.64, 0.036);
    drawFilledCircle(0.70, -0.64, 0.036);
    drawFilledCircle(0.72, -0.64, 0.036);

    //black body
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.55, -0.25, 0.18);
    drawFilledCircle(0.56, -0.23, 0.17);
    drawFilledCircle(0.56, -0.29, 0.2);
    drawFilledCircle(0.56, -0.32, 0.21);
    drawFilledCircle(0.56, -0.37, 0.21);
    drawFilledCircle(0.56, -0.40, 0.21);
    drawFilledCircle(0.56, -0.43, 0.21);
    drawFilledCircle(0.56, -0.44, 0.21);

    //white body
    glColor3f(1, 1, 1);
    drawFilledCircle(0.50, -0.23, 0.07);
    drawFilledCircle(0.63, -0.23, 0.07);
    drawFilledCircle(0.64, -0.27, 0.07);
    drawFilledCircle(0.49, -0.27, 0.07);
    drawFilledCircle(0.49, -0.33, 0.09);

    drawFilledCircle(0.64, -0.29, 0.08);
    drawFilledCircle(0.644, -0.33, 0.08);
    drawFilledCircle(0.644, -0.36, 0.08);
    drawFilledCircle(0.644, -0.39, 0.08);
    drawFilledCircle(0.646, -0.42, 0.08);
    drawFilledCircle(0.646, -0.45, 0.08);
    drawFilledCircle(0.646, -0.48, 0.08);

    drawFilledCircle(0.49, -0.36, 0.09);
    drawFilledCircle(0.49, -0.39, 0.09);
    drawFilledCircle(0.49, -0.42, 0.09);
    drawFilledCircle(0.49, -0.45, 0.09);
    drawFilledCircle(0.49, -0.48, 0.09);

    drawFilledCircle(0.55, -0.27, 0.05);
    drawFilledCircle(0.56, -0.45, 0.17);

    //hand r
    glColor3f(0.0, 0.0, 0.0);
    //drawFilledCircle(0.65, -0.20, 0.03);
    drawFilledCircle(0.76, -0.30, 0.04);
    drawFilledCircle(0.78, -0.32, 0.04);
    drawFilledCircle(0.80, -0.33, 0.03);

    //hand l
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.35, -0.30, 0.04);
    drawFilledCircle(0.33, -0.32, 0.04);
    drawFilledCircle(0.31, -0.33, 0.03);

    //nose
    glColor3f(1.0, 0.8, 0.2);
    drawFilledCircle(0.54, -0.30, 0.03);
    drawFilledCircle(0.56, -0.30, 0.03);
    drawFilledCircle(0.58, -0.30, 0.03);

    //pink
    glColor3f(1.0, 0.8, 0.8);
    drawFilledCircle(0.453, -0.30, 0.025);
    drawFilledCircle(0.67, -0.30, 0.025);

    //eye
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.48, -0.23, 0.019);
    drawFilledCircle(0.65, -0.23, 0.019);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//الغنمه

void sheepBackround1() {
    //floor
    glBegin(GL_QUADS);
    glColor3f(0.09, 0.50, 0.21);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 0.27);
    glVertex2f(-1.0, 0.27);
    glEnd();

    //curve things
    glColor3f(0.09, 0.50, 0.21);
    drawFilledCircle(0.2, 0.20, 0.2);
    drawFilledCircle(0.5, 0.20, 0.2);
    drawFilledCircle(0.8, 0.20, 0.2);
    drawFilledCircle(1.1, 0.20, 0.2);
    drawFilledCircle(-0.1, 0.20, 0.2);
    drawFilledCircle(-0.4, 0.20, 0.2);
    drawFilledCircle(-0.7, 0.20, 0.2);
    drawFilledCircle(-1.0, 0.20, 0.2);
}

void sheepSun() {
    glColor3f(1, 1, 0.2);
    drawFilledCircle(0.0, 0.70, 0.2);
}

void sheepFence() {
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.94, -0.56);
    glVertex2f(1.0, -0.56);
    glVertex2f(1.0, -0.10);
    glVertex2f(0.94, -0.10);

    glVertex2f(0.7, -0.56);
    glVertex2f(0.79, -0.56);
    glVertex2f(0.79, -0.10);
    glVertex2f(0.7, -0.10);

    glVertex2f(0.4, -0.56);
    glVertex2f(0.49, -0.56);
    glVertex2f(0.49, -0.10);
    glVertex2f(0.4, -0.10);

    glVertex2f(0.1, -0.56);
    glVertex2f(0.19, -0.56);
    glVertex2f(0.19, -0.10);
    glVertex2f(0.1, -0.10);

    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.7, -0.56);
    glVertex2f(-0.79, -0.56);
    glVertex2f(-0.79, -0.10);
    glVertex2f(-0.7, -0.10);

    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.4, -0.56);
    glVertex2f(-0.49, -0.56);
    glVertex2f(-0.49, -0.10);
    glVertex2f(-0.4, -0.10);

    glVertex2f(-0.1, -0.56);
    glVertex2f(-0.19, -0.56);
    glVertex2f(-0.19, -0.10);
    glVertex2f(-0.1, -0.10);

    glVertex2f(-0.94, -0.56);
    glVertex2f(-1.0, -0.56);
    glVertex2f(-1.0, -0.10);
    glVertex2f(-0.94, -0.10);

    glVertex2f(-0.99, -0.27);
    glVertex2f(0.99, -0.27);
    glVertex2f(0.99, -0.40);
    glVertex2f(-0.99, -0.40);

    glEnd();
}

void sheepTree() {
    //big tree(brown)
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(0.4, -0.4);
    glVertex2f(0.5, -0.4);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.4, 0.4);
    glEnd();

    //big tree(green)
    glColor3f(0, 0.7, 0.2);
    drawFilledCircle(0.3, 0.4, 0.2);
    drawFilledCircle(0.6, 0.4, 0.2);
    drawFilledCircle(0.3, 0.6, 0.2);
    drawFilledCircle(0.6, 0.6, 0.2);
    drawFilledCircle(0.5, 0.7, 0.2);

    //apples
    glColor3f(0.8, 0.1, 0.2);
    drawFilledCircle(0.5, 0.7, 0.03);
    drawFilledCircle(0.3, 0.4, 0.03);
    drawFilledCircle(0.5, 0.5, 0.03);
    drawFilledCircle(0.2, 0.6, 0.03);
    drawFilledCircle(0.7, 0.4, 0.03);
    drawFilledCircle(0.7, 0.7, 0.03);
}

void sheepCloud() {
    glColor3f(1.0, 1.0, 1.0);
    //cloud 1
    drawFilledCircle(-0.2, 0.90, 0.06);
    drawFilledCircle(-0.4, 0.90, 0.06);
    drawFilledCircle(-0.3, 0.90, 0.09);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//void sheepRose() {
//    glColor3f(1.0, 0.1, 0.7);
//    drawFilledCircle(0.3, -0.5, 0.03);
//    drawFilledCircle(0.34, -0.54, 0.03);
//    drawFilledCircle(0.26, -0.54, 0.03);
//    drawFilledCircle(0.3, -0.57, 0.03);
//    glColor3f(0.0, 0.0, 0.0);
//    drawFilledCircle(0.3, -0.54, 0.019);
//}

void sheepRose2() {
    //glColor3f(1.0, 0.1, 0.7);
    drawFilledCircle(0.3, -0.5, 0.03);
    drawFilledCircle(0.34, -0.54, 0.03);
    drawFilledCircle(0.26, -0.54, 0.03);
    drawFilledCircle(0.3, -0.57, 0.03);
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.3, -0.54, 0.019);

}
//draw the info button
void sheepInfo() {

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-1, 0.3);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.4, -0.05);
    glVertex2f(-1, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.75, 0.2);
    glVertex2f(-0.65, 0.2);
    glVertex2f(-0.65, -0.67);
    glVertex2f(-0.75, -0.67);
    glEnd();
}

void sheepFace() {
    //startbody
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.45, -0.48, 0.098);
    drawFilledCircle(-0.50, -0.63, 0.098);
    drawFilledCircle(-0.45, -0.74, 0.098);
    drawFilledCircle(-0.34, -0.82, 0.1);
    drawFilledCircle(-0.15, -0.83, 0.1);
    drawFilledCircle(-0.01, -0.74, 0.1);
    drawFilledCircle(0.03, -0.61, 0.1);
    drawFilledCircle(-0.03, -0.47, 0.1);
    drawFilledCircle(-0.23, -0.59, 0.29);

    //face
    glColor3f(0.8, 0.7, 0.5);
    drawFilledCircle(-0.2, -0.3, 0.11);
    drawFilledCircle(-0.24, -0.3, 0.11);
    drawFilledCircle(-0.27, -0.3, 0.11);
    drawFilledCircle(-0.30, -0.3, 0.11);
    drawFilledCircle(-0.24, -0.33, 0.1);
    drawFilledCircle(-0.27, -0.33, 0.1);
    drawFilledCircle(-0.30, -0.33, 0.1);
    drawFilledCircle(-0.2, -0.33, 0.1);
    drawFilledCircle(-0.25, -0.34, 0.13);

    //ear
    glColor3f(0.8, 0.7, 0.5);
    drawFilledCircle(-0.07, -0.28, 0.034);
    drawFilledCircle(-0.43, -0.28, 0.036);

    //eye
    glColor3f(0., 0, 0);
    drawFilledCircle(-0.19, -0.32, 0.02);
    drawFilledCircle(-0.31, -0.32, 0.02);

    //mouth
    glColor3f(0., 0, 0);
    drawFilledCircle(-0.25, -0.40, 0.039);
    glColor3f(0.8, 0.7, 0.5);
    drawFilledCircle(-0.25, -0.38, 0.039);
    glColor3f(1.0, 0.2, 0.4);
    drawFilledCircle(-0.15, -0.37, 0.02);
    drawFilledCircle(-0.35, -0.37, 0.02);

    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(-0.42, -0.18, 0.08);
    drawFilledCircle(-0.30, -0.18, 0.1);
    drawFilledCircle(-0.19, -0.18, 0.1);
    drawFilledCircle(-0.09, -0.18, 0.08);
    drawFilledCircle(-0.30, -0.12, 0.08);
    drawFilledCircle(-0.19, -0.12, 0.08);

    //leg
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.7, 0.5);
    glVertex2f(-0.1, -0.9);
    glVertex2f(-0.2, -0.9);
    glVertex2f(-0.2, -0.78);
    glVertex2f(-0.1, -0.78);
    glEnd();
    glColor3f(0.8, 0.7, 0.5);
    drawFilledCircle(-0.15, -0.93, 0.06);

    //leg2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.7, 0.5);
    glVertex2f(-0.3, -0.9);
    glVertex2f(-0.4, -0.9);
    glVertex2f(-0.4, -0.78);
    glVertex2f(-0.3, -0.78);
    glEnd();
    glColor3f(0.8, 0.7, 0.5);
    drawFilledCircle(-0.35, -0.93, 0.06);
}

void sheepSky() {
    glBegin(GL_QUADS);
    glColor4f(0.64, 0.91, 0.98, 0.9);
    glVertex2f(-1.0, 1.0);

    glColor4f(0.91, 0.78, 0.12, 0.3);
    glVertex2f(1.0, 1.0);

    glColor4f(0.91, 0.91, 0.54, 0.058);
    glVertex2f(1.0, -1.0);

    glColor4f(0.1, 0.91, 0.78, 0.12);
    glVertex2f(-1.0, -1.0);
}
//------------------------------------------------------------------------------------------------------------------------------------
//البسه
void catSky()
{
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 0.4f);
    glVertex2f(-1.0f, 1.0f);

    glColor3f(0.1, 0.9, 0.9);
    glVertex2f(1.0f, 1.0f);

    glColor3f(0.1, 0.8, 1.0);
    glVertex2f(1.0f, 0.4f);

    glColor3f(0.2, 0.3, 0.6);
    glVertex2f(-1.0f, 0.4f);

    glEnd();

}

void catGrass()
{
    glBegin(GL_QUADS);

    glColor3f(0.3f, 0.8f, 0.2f);
    glVertex2f(1.0f, 0.4f);

    glColor3f(0.0, 0.4, 0.0);
    glVertex2f(-1.0f, 0.4f);

    glColor3f(0.3, 0.8, 0.3);
    glVertex2f(-1.0f, -1.0f);

    glColor3f(0.3, 0.9, 0.1);
    glVertex2f(1.0f, -1.0f);

    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.08, -0.5);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.12, -0.5);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.2, -0.7);
    glVertex2f(0.22, -0.6);
    glVertex2f(0.23, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.08, -0.9);
    glVertex2f(-0.1, -0.8);
    glVertex2f(-0.12, -0.9);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.2, -0.7);
    glVertex2f(-0.22, -0.6);
    glVertex2f(-0.23, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.4, -1.0);
    glVertex2f(0.42, -0.9);
    glVertex2f(0.43, -1.0);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.6, -0.7);
    glVertex2f(0.62, -0.6);
    glVertex2f(0.63, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.9, -0.7);
    glVertex2f(0.92, -0.6);
    glVertex2f(0.93, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.9, -0.9);
    glVertex2f(-0.92, -0.8);
    glVertex2f(-0.93, -0.9);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.64, -0.7);
    glVertex2f(-0.66, -0.6);
    glVertex2f(-0.67, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.62, 0.0);
    glVertex2f(0.63, -0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.62, 0.0);
    glVertex2f(-0.63, -0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.7, 0.1);
    glVertex2f(-0.72, 0.2);
    glVertex2f(-0.73, 0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.5, -0.4);
    glVertex2f(-0.52, -0.3);
    glVertex2f(-0.53, -0.4);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.8, -0.4);
    glVertex2f(-0.82, -0.3);
    glVertex2f(-0.83, -0.4);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.13, 0.2);
    glVertex2f(-0.14, 0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.13, -0.01);
    glVertex2f(0.14, -0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.9, 0.1);
    glVertex2f(0.92, 0.2);
    glVertex2f(0.93, 0.1);
    glEnd();


}

void catClouds()
{

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(1.0, 1.0, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.87, 0.88, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.79, 0.81, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.70, 0.75, .10);

    glColor3f(0.93f, 0.93f, 0.93f);
    drawFilledCircle(0.79, 0.60, .10);

    glColor3f(0.94f, 0.94f, 0.94f);
    drawFilledCircle(0.95, 0.65, .10);

    glColor3f(0.95f, 0.95f, 0.95f);
    drawFilledCircle(0.86, 0.77, .10);


    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.97, 0.83, .10);

    glColor3f(0.9f, 0.9f, 0.1f);
    drawFilledCircle(-1.0, 1.0, .35);

}

void bsbs() {
    //right ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.5f, 0.3f);
    glVertex2f(0.66, 0.4);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.58f, 0.22f);
    glVertex2f(0.659f, 0.4f);
    glVertex2f(0.55, 0.3);
    glEnd();
    // left ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.35f, 0.4f);
    glVertex2f(0.5, 0.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.4f, 0.22f);
    glVertex2f(0.35f, 0.38f);
    glVertex2f(0.45, 0.25);
    glEnd();

    //tail
    glBegin(GL_QUADS);
    glColor3f(0.28f, 0.28f, 0.28f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.8f, -0.1f);
    glVertex2f(0.8f, -0.14f);
    glVertex2f(0.6f, -0.14f);

    //tail
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.76f, -0.1f);
    glVertex2f(0.8f, -0.1f);
    glVertex2f(0.8f, 0.15f);
    glVertex2f(0.76f, 0.15f);
    glEnd();

    glColor3f(0.3f, 0.3f, 0.3f);
    drawFilledCircle(0.774, -0.115, .03);

    glColor3f(0.3f, 0.3f, 0.3f);
    drawFilledCircle(0.779, 0.15, .03);
    //body
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.4f, 0.09f);
    glVertex2f(0.6f, 0.09f);
    glVertex2f(0.6f, -0.15f);
    glVertex2f(0.4f, -0.15f);
    glEnd();
    //circle in right
    glColor3f(0.3f, 0.3f, 0.3f);
    drawFilledCircle(0.56, -0.03, .13);


    //foot
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.45f, -0.15f);
    glVertex2f(0.48f, -0.15f);
    glVertex2f(0.48f, -0.2f);
    glVertex2f(0.45f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.55f, -0.15f);
    glVertex2f(0.58f, -0.15f);
    glVertex2f(0.58f, -0.2f);
    glVertex2f(0.55f, -0.2f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    drawFilledCircle(0.46, -0.2, .02);

    glColor3f(0.4f, 0.4f, 0.4f);
    drawFilledCircle(0.56, -0.2, .02);

    //head
    glColor3f(0.4f, 0.4f, 0.4f);
    drawFilledCircle(0.5, 0.2, .15);
    //eyes
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.55, 0.25, .04);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.55, 0.25, .03);


    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.45, 0.25, .04);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.45, 0.25, .03);
    //nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.49f, 0.19f);
    glVertex2f(0.51f, 0.19f);
    glVertex2f(0.50, 0.16);
    glEnd();

    //right mustage
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.52, 0.18);
    glVertex2f(0.6, 0.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.52, 0.18);
    glVertex2f(0.6, 0.18);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.52, 0.18);
    glVertex2f(0.6, 0.16);
    glEnd();

    //left  mustage
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.47, 0.18);
    glVertex2f(0.38, 0.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.47, 0.18);
    glVertex2f(0.38, 0.18);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.47, 0.18);
    glVertex2f(0.38, 0.16);
    glEnd();

    //deatails
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.48, 0.13);
    glVertex2f(0.50, 0.12);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.50, 0.12);
    glVertex2f(0.52, 0.13);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.5, 0.32);
    glVertex2f(0.5, 0.35);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.5, 0.32);
    glVertex2f(0.52, 0.35);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.5, 0.32);
    glVertex2f(0.48, 0.35);
    glEnd();
}

void catFence() {

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(-1.0f, -0.9f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(-1.0f, -0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    //then
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.9f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.9f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -1.0f);
    glVertex2f(-0.5f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -1.0f);
    glVertex2f(-0.5f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(-0.1f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(-0.1f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.3f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.3f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.8f, -1.0f);
    glVertex2f(0.7f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.8f, -1.0f);
    glVertex2f(0.7f, -1.0f);
    glEnd();
    // then
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.85, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.85, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.45, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.45, -0.2);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(-0.05, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(-0.05, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.35, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.35, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.75, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.75, -0.2);
    glEnd();
}

void catWood() {

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.4f, 0.0f);
    glVertex2f(-0.5f, -1.0f);
    glVertex2f(-0.6f, -1.0f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.5f, 0.1f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.5f, -1.0f);
    glVertex2f(-0.6f, -1.0f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.5f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.4f, 0.0f);
    glVertex2f(-0.98f, 0.6f);
    glVertex2f(-0.98f, 0.06f);
    glVertex2f(-0.08f, 0.06f);
    glVertex2f(-0.08f, 0.6f);
    glEnd();

    glBegin(GL_LINE_LOOP);

    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.98f, 0.6f);
    glVertex2f(-0.98f, 0.06f);
    glVertex2f(-0.08f, 0.06f);
    glVertex2f(-0.08f, 0.6f);
    glEnd();

}//------------------------------------------------------------------------------------------------------------------------------------
//البقره
void cawSky()
{

    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 0.4f);
    glVertex2f(-1.0f, 1.0f);

    glColor3f(0.1, 0.9, 0.9);
    glVertex2f(1.0f, 1.0f);

    glColor3f(0.1, 0.8, 1.0);
    glVertex2f(1.0f, 0.4f);

    glColor3f(0.2, 0.3, 0.6);
    glVertex2f(-1.0f, 0.4f);

    glEnd();

}
void cawGrass()
{
    glBegin(GL_QUADS);

    glColor3f(0.3f, 0.8f, 0.2f);
    glVertex2f(1.0f, 0.4f);

    glColor3f(0.0, 0.4, 0.0);
    glVertex2f(-1.0f, 0.4f);

    glColor3f(0.3, 0.8, 0.3);
    glVertex2f(-1.0f, -1.0f);

    glColor3f(0.3, 0.9, 0.1);
    glVertex2f(1.0f, -1.0f);

    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.08, -0.5);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.12, -0.5);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.2, -0.7);
    glVertex2f(0.22, -0.6);
    glVertex2f(0.23, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.08, -0.9);
    glVertex2f(-0.1, -0.8);
    glVertex2f(-0.12, -0.9);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.2, -0.7);
    glVertex2f(-0.22, -0.6);
    glVertex2f(-0.23, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.4, -1.0);
    glVertex2f(0.42, -0.9);
    glVertex2f(0.43, -1.0);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.6, -0.7);
    glVertex2f(0.62, -0.6);
    glVertex2f(0.63, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.9, -0.7);
    glVertex2f(0.92, -0.6);
    glVertex2f(0.93, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.9, -0.9);
    glVertex2f(-0.92, -0.8);
    glVertex2f(-0.93, -0.9);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.64, -0.7);
    glVertex2f(-0.66, -0.6);
    glVertex2f(-0.67, -0.7);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.62, 0.0);
    glVertex2f(0.63, -0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.62, 0.0);
    glVertex2f(-0.63, -0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.7, 0.1);
    glVertex2f(-0.72, 0.2);
    glVertex2f(-0.73, 0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.5, -0.4);
    glVertex2f(-0.52, -0.3);
    glVertex2f(-0.53, -0.4);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.8, -0.4);
    glVertex2f(-0.82, -0.3);
    glVertex2f(-0.83, -0.4);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.13, 0.2);
    glVertex2f(-0.14, 0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.13, -0.01);
    glVertex2f(0.14, -0.1);
    glEnd();

    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.9, 0.1);
    glVertex2f(0.92, 0.2);
    glVertex2f(0.93, 0.1);
    glEnd();

}

void cowClouds()
{

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-0.2, 0.88, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-0.29, 0.81, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-0.20, 0.75, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-0.1, 0.81, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.0, 0.88, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.0, 0.75, .10);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.1, 0.81, .10);

}

void cowSun() {//sun
    glColor3f(0.9f, 0.9f, 0.1f);
    drawFilledCircle(-0.7, 1.0, .30);
}

void Cow() {
    glColor3f(0.7f, 0.5f, 0.8f);
    drawFilledCircle(0.3, -0.15, .075);

    //body
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(0.0f, -0.1f);
    glVertex2f(-0.05f, -0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.6f, -0.15f);
    glVertex2f(0.1f, -0.15f);
    glEnd();
    //head

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.5, 0.13, .05);

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.5f, 0.13);
    glVertex2f(0.7f, 0.13f);
    glVertex2f(0.7f, -0.05f);
    glVertex2f(0.5f, -0.05f);
    glEnd();
    //down
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.5, -0.07, .05);

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(0.5f, 0.04);
    glVertex2f(0.7f, 0.04f);
    glVertex2f(0.7f, -0.05f);
    glVertex2f(0.5f, -0.05f);
    glEnd();
    //left leg
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(0.1f, -0.3);
    glVertex2f(0.17f, -0.3f);
    glVertex2f(0.17f, -0.15f);
    glVertex2f(0.1f, -0.15f);
    glEnd();
    //leftB leg
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.17f, -0.3);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(0.2f, -0.15f);
    glVertex2f(0.17f, -0.15f);
    glEnd();
    //right leg
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(0.4f, -0.3);
    glVertex2f(0.47f, -0.3f);
    glVertex2f(0.47f, -0.15f);
    glVertex2f(0.4f, -0.15f);
    glEnd();
    //RightB leg
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.47f, -0.3);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(0.5f, -0.15f);
    glVertex2f(0.47f, -0.15f);
    glEnd();
    //ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(0.65f, 0.13f);
    glVertex2f(0.7f, 0.13f);
    glVertex2f(0.67, 0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(0.55f, 0.13f);
    glVertex2f(0.6f, 0.13f);
    glVertex2f(0.57, 0.2);
    glEnd();
    //eye
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.57, 0.08, .03);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.66, 0.08, .03);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.57, 0.08, .015);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.66, 0.08, .015);
    //nose
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.57, 0.0, .015);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.66, 0.0, .015);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.2, 0.1, .05);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.4, 0.05, .05);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.3, 0.0, .05);


    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.2, -0.07, .05);

}

void cowFence() {

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(-1.0f, -0.9f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(-1.0f, -0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    //then
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.9f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.9f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -1.0f);
    glVertex2f(-0.5f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -1.0f);
    glVertex2f(-0.5f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(-0.1f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(-0.1f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.3f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.3f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.8f, -1.0f);
    glVertex2f(0.7f, -1.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.8f, -1.0f);
    glVertex2f(0.7f, -1.0f);
    glEnd();
    // then
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.85, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.85, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.45, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.45, -0.2);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(-0.05, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(-0.05, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.35, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.35, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.75, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.75, -0.2);
    glEnd();
}

void cowWood() {

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.4f, 0.0f);
    glVertex2f(-0.5f, -1.0f);
    glVertex2f(-0.6f, -1.0f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.5f, 0.1f);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.5f, -1.0f);
    glVertex2f(-0.6f, -1.0f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.5f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.4f, 0.0f);
    glVertex2f(-0.98f, 0.6f);
    glVertex2f(-0.98f, 0.06f);
    glVertex2f(-0.08f, 0.06f);
    glVertex2f(-0.08f, 0.6f);
    glEnd();

    glBegin(GL_LINE_LOOP);

    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.98f, 0.6f);
    glVertex2f(-0.98f, 0.06f);
    glVertex2f(-0.08f, 0.06f);
    glVertex2f(-0.08f, 0.6f);
    glEnd();

}
//----------------------------------------------------------------------------------------------------------------
//الباندا
void pandaClouds() {

    glColor3f(0.8f, 0.8f, 0.8f);
    drawFilledCircle(-0.7, 0.7, .12);


    glColor3f(0.8f, 0.8f, 0.8f);
    drawFilledCircle(-0.5, 0.65, .12);


    glColor3f(0.8f, 0.8f, 0.8f);
    drawFilledCircle(-0.9, 0.64, .12);

    glColor3f(0.8f, 0.8f, 0.8f);
    drawFilledCircle(-0.7, 0.6, .12);
}

void Panda1()
{// drawing the filled circle
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.1, 0.1, .12);
    drawFilledCircle(-0.1, 0.1, .12);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(0, 0, .2);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.0, -0.37, .2);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.0, -0.37, .1);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0, 0, .2);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.1, 0.05, .06);
    drawFilledCircle(-0.1, 0.05, .06);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.0, -0.05, .03);

    HollowNewCircle(0.0, -0.08, .08);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.1, 0.04, .02);
    drawFilledCircle(-0.1, 0.04, .02);

    glColor3f(0.0f, 0.0f, 0.0f);
    Fill(-0.17, -0.2, 0.1);

    glColor3f(0.0f, 0.0f, 0.0f);
    Fill(0.17, -0.2, 0.1);

    glColor3f(0.0f, 0.0f, 0.0f);
    FillHeat(0.13, -0.55, 0.1);

    glColor3f(0.0f, 0.0f, 0.0f);
    FillHeat(-0.1, -0.55, 0.1);

    // drawing the border around the circle

}

void PandaBack() {
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.1, 0.1, .12);
    drawFilledCircle(-0.1, 0.1, .12);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle(0, 0, .2);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.0, -0.37, .2);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0, 0, .2);

    glColor3f(0.0f, 0.0f, 0.0f);
    Fill(-0.17, -0.2, 0.1);

    glColor3f(0.0f, 0.0f, 0.0f);
    Fill(0.17, -0.2, 0.1);

    glColor3f(0.0f, 0.0f, 0.0f);
    FillHeat(0.13, -0.55, 0.1);

    glColor3f(0.0f, 0.0f, 0.0f);
    FillHeat(-0.1, -0.55, 0.1);
}

void pandaNatural() {

    glColor3f(0.3f, 0.2f, 0.1f);
    Fillnat(0.7, 0.07, 0.6);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.53, 0.5, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.55, 0.7, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.6, 0.8, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.75, 0.9, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.7, 0.5, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.8, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.53, 0.6, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.7, 0.7, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.5, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.5, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.6, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.7, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.8, 0.7, .12);

}

void pandaNatural1() {

    glColor3f(0.3f, 0.2f, 0.1f);
    Fillnat(0.7, 0.07, 0.6);


    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.53, 0.5, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.55, 0.7, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.6, 0.8, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.75, 0.9, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.7, 0.5, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.8, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.53, 0.6, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.7, 0.7, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.5, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.5, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.6, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.9, 0.7, .12);

    glColor3f(0.0f, 0.2f, 0.0f);
    drawFilledCircle(0.8, 0.7, .12);

}

void pandaLawn()
{
    glBegin(GL_QUADS);
    glColor3f(0.09f, 0.5f, 0.21f);
    glVertex2f(-1, -1);
    glVertex2f(-1, -0.1);
    glVertex2f(1, -0.1);
    glVertex2f(1, -1);

    glEnd();
}

void pandaWood() {

    glBegin(GL_QUADS);
    glColor3f(0.4745, 0.3725, 0.0352);
    glVertex2f(0.05, -0.1);
    glVertex2f(-0.05, -0.1);
    glVertex2f(-0.05, -1.0);
    glVertex2f(0.05, -1.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.05, -0.1);
    glVertex2f(-0.05, -0.1);
    glVertex2f(-0.05, -1.0);
    glVertex2f(0.05, -1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4745, 0.3725, 0.0352);
    glVertex2f(-0.27, 0.1);
    glVertex2f(0.27, 0.1);
    glVertex2f(0.27, -0.25);
    glVertex2f(-0.27, -0.25);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.27, 0.1);
    glVertex2f(0.27, 0.1);
    glVertex2f(0.27, -0.25);
    glVertex2f(-0.27, -0.25);
    glEnd();
}

void pandaFence() {

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(-1.0f, -0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();
    //then
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.9f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -1.0f);
    glVertex2f(-0.5f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(-0.1f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.3f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.8f, -1.0f);
    glVertex2f(0.7f, -1.0f);
    glEnd();
    // then
    glBegin(GL_TRIANGLES);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.85, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.45, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(-0.1f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(-0.05, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.35, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.90, 0.58, 0.33);
    glVertex2f(0.7f, -0.3f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(0.75, -0.2);
    glEnd();
}

void pandaSun() {
    glColor3f(1, 1, 0.2);
//    drawFilledCircle(0.0, 0.90, 0.2);
    
    
//    glColor4f(0.874f, 0.878f, 0.30f, 0.6f); //light yellow
    drawFilledCircle(-1.6, 0.4, 0.2);
}

void intarP() {
    glBegin(GL_QUADS);
    glColor4f(0.17, 0.78, 0.96, 0.43);
    glVertex2f(1.0, 1.0);

    glColor4f(1.00, 0.98, 0.62, 0.43);
    glVertex2f(1.0, -1.0);

    glColor4f(0.17, 0.78, 0.96, 0.43);
    glVertex2f(-2.0, -1.0);

    glColor4f(1.00, 0.98, 0.62, 0.43);
    glVertex2f(-2.0, 1.0);

    glEnd();
}

//------------------------------------------------------------------------------------------------------------------------------------
//مشاهد الستارت و الدخول و الخروج

//to start a story


//for Scene7
void ESky()
{
    // Draw a Quad for sky
    glBegin(GL_QUADS);

    glColor4f(0.55f, 0.68f, 0.87f, 0.6f);// blue
    glVertex2f(-1.0f, 1.0f);

    glColor4f(0.55f, 0.68f, 0.87f, 0.6f);// blue
    glVertex2f(1.0f, 1.0f);

    glColor4f(0.91f, 0.54f, 0.058f, 0.9f);//#light yellow
    glVertex2f(1.0f, -1.0f);

    glColor4f(0.91f, 0.78f, 0.12f, 0.9f);//#light yellow
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    ///////////////////////////
/////////    SUN    /////////////////////////////////////
     ////////////////////////////

    glColor4f(0.874f, 0.878f, 0.30f, 0.6f); //light yellow
    drawFilledCircle(-0.95, 0.65, 0.2);
}

//for the scene 0 & 1
void Interingsky()
{
    //Draw a Quad for sky
    glBegin(GL_QUADS);
    glColor4f(0.17f, 0.78f, 0.96f, 0.43f);//light blue
    glVertex2f(-1.0f, 1.0f);
    glColor4f(1.0f, 0.98f, 0.62f, 0.043f);//#light yellow
    glVertex2f(1.0f, 1.0f);

    glColor4f(0.17f, 0.78f, 0.96f, 0.43f);//light blue
    glVertex2f(1.0f, -0.1f);

    glColor4f(1.0f, 0.98f, 0.62f, 0.023f);//#light yellow
    glVertex2f(-1.0f, -0.1f);
    glEnd();

    ///////////////////////////
/////////    SUN    /////////////////////////////////////
     ////////////////////////////

    glColor4f(0.874f, 0.878f, 0.30f, 0.7f);
    drawFilledCircle(0.85, 0.94, 0.2);
}

//
void WClouds()
{
    ///////////////////////////
/////////    RIGHT CLOUDS    /////////////////////////////////////
     ////////////////////////////

    //Very small
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.51, 0.79, 0.03);
    //Large
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.35, 0.80, 0.07);
    //Medium
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.45, 0.80, 0.05);
    //Small
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.25, 0.80, 0.04);

    ///////////////////////////
/////////      LEFT CLOUDS      /////////////////////////////////////
      ///////////////////////////

    //Very small
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-0.51, 0.79, 0.03);
    //Large
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-0.35, 0.80, 0.07);
    //Medium
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-0.45, 0.80, 0.05);
    //Small
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(-0.25, 0.80, 0.04);
}


void WGrass()
{
    // Draw a Quad for grass
    glBegin(GL_QUADS);
    glColor4f(0.09f, 0.50f, 0.21f, 1.0f);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void RedRose() {
    glColor3f(0.92, 0.26, 0.26);
    drawFilledCircle(0.4, -0.5, 0.03);
    drawFilledCircle(0.43, -0.54, 0.03);
    drawFilledCircle(0.36, -0.54, 0.03);
    drawFilledCircle(0.4, -0.57, 0.03);
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.4, -0.54, 0.019);
}
void GreenRose() {
    glColor3f(0.23, 0.52, 0.298);
    drawFilledCircle(0.4, -0.5, 0.03);
    drawFilledCircle(0.43, -0.54, 0.03);
    drawFilledCircle(0.36, -0.54, 0.03);
    drawFilledCircle(0.4, -0.57, 0.03);
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.4, -0.54, 0.019);

}
void YellowRose() {
    glColor3f(0.70, 0.705, 0.235);
    drawFilledCircle(0.4, -0.5, 0.03);
    drawFilledCircle(0.43, -0.54, 0.03);
    drawFilledCircle(0.36, -0.54, 0.03);
    drawFilledCircle(0.4, -0.57, 0.03);
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.4, -0.54, 0.019);

}
void PinkRose() {
    glColor3f(1.0, 0.1, 0.7);
    drawFilledCircle(0.4, -0.5, 0.03);
    drawFilledCircle(0.43, -0.54, 0.03);
    drawFilledCircle(0.36, -0.54, 0.03);
    drawFilledCircle(0.4, -0.57, 0.03);
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.4, -0.54, 0.019);

}
void OrangeRose() {
    glColor3f(0.87, 0.568, 0.325);
    drawFilledCircle(0.4, -0.5, 0.03);
    drawFilledCircle(0.43, -0.54, 0.03);
    drawFilledCircle(0.36, -0.54, 0.03);
    drawFilledCircle(0.4, -0.57, 0.03);
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle(0.4, -0.54, 0.019);

}

void WTrees()
{
    //tree 1
    glBegin(GL_QUADS);
    glColor4f(0.43f, 0.23f, 0.07f, 1.0f);
    glVertex2f(0.80f, 0.50f);
    glVertex2f(0.92f, 0.50f);
    glVertex2f(0.92f, 0.01f);
    glVertex2f(0.80f, 0.01f);
    glEnd();
    //LineLoop for tree1
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.80f, 0.50f);
    glVertex2f(0.92f, 0.50f);
    glVertex2f(0.92f, 0.01f);
    glVertex2f(0.80f, 0.01f);
    glEnd();
    //
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.85, 0.46, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.78, 0.40, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.93, 0.40, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.78, 0.34, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.93, 0.34, 0.09);
    //apples1
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(0.93, 0.33, 0.02);
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(0.8, 0.34, 0.02);
    //apples2
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(0.92, 0.44, 0.02);
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(0.80, 0.44, 0.02);

    //tree 2
    glBegin(GL_QUADS);
    glColor4f(0.43f, 0.23f, 0.07f, 1.0f);
    glVertex2f(0.40f, 0.50f);
    glVertex2f(0.52f, 0.50f);
    glVertex2f(0.52f, 0.01f);
    glVertex2f(0.40f, 0.01f);
    glEnd();
    //LineLoop for tree 2
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.40f, 0.50f);
    glVertex2f(0.52f, 0.50f);
    glVertex2f(0.52f, 0.01f);
    glVertex2f(0.40f, 0.01f);
    glEnd();

    //
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.45, 0.46, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.38, 0.40, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.53, 0.40, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.38, 0.34, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(0.53, 0.34, 0.09);
    //apples1
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(0.38, 0.33, 0.02);
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(0.52, 0.34, 0.02);
    //apples2
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(0.52, 0.44, 0.02);
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(0.40, 0.44, 0.02);

    //tree 3
    glBegin(GL_QUADS);
    glColor4f(0.43f, 0.23f, 0.07f, 1.0f);
    glVertex2f(-0.40f, 0.50f);
    glVertex2f(-0.52f, 0.50f);
    glVertex2f(-0.52f, 0.01f);
    glVertex2f(-0.40f, 0.01f);
    glEnd();
    //LineLoop for tree 3
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.40f, 0.50f);
    glVertex2f(-0.52f, 0.50f);
    glVertex2f(-0.52f, 0.01f);
    glVertex2f(-0.40f, 0.01f);
    glEnd();

    //
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.45, 0.46, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.38, 0.40, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.53, 0.40, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.38, 0.34, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.53, 0.34, 0.09);
    //apples1
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(-0.38, 0.33, 0.02);
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(-0.52, 0.34, 0.02);
    //apples2
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(-0.52, 0.44, 0.02);
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(-0.40, 0.44, 0.02);

    //tree4
    glBegin(GL_QUADS);
    glColor4f(0.43f, 0.23f, 0.07f, 1.0f);
    glVertex2f(-0.80f, 0.50f);
    glVertex2f(-0.92f, 0.50f);
    glVertex2f(-0.92f, 0.01f);
    glVertex2f(-0.80f, 0.01f);
    glEnd();
    //LineLoop for tree4
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.80f, 0.50f);
    glVertex2f(-0.92f, 0.50f);
    glVertex2f(-0.92f, 0.01f);
    glVertex2f(-0.80f, 0.01f);
    glEnd();
    //
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.85, 0.46, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.78, 0.40, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.93, 0.40, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.78, 0.34, 0.09);
    glColor3f(0.1f, 0.58f, 0.25f);
    drawFilledCircle(-0.93, 0.34, 0.09);
    //apples1
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(-0.93, 0.33, 0.02);
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(-0.82, 0.34, 0.02);
    //apples2
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(-0.92, 0.44, 0.02);
    glColor3f(0.8f, 0.074f, 0.0f);
    drawFilledCircle(-0.80, 0.44, 0.02);

}

void DirtTrack()
{
    // Draw a Square for the main DirtTrack
    glBegin(GL_QUADS);
    glColor4f(0.63f, 0.41f, 0.23f, 1.0f);// brown color
    glVertex2f(-0.14f, 0.20f);
    glVertex2f(0.14f, 0.20f);
    glVertex2f(0.26f, -1.0f);
    glVertex2f(-0.26f, -1.0f);
    glEnd();
    // Draw a Square for the branch DirtTrack
    glBegin(GL_QUADS);
    glColor4f(0.63f, 0.41f, 0.23f, 1.0f);// brown color
    glVertex2f(-0.86f, -0.70f);
    glVertex2f(-0.22f, -0.70f);
    glVertex2f(-0.22f, -0.93f);
    glVertex2f(-0.86f, -0.93f);
    glEnd();

    // Draw a Square for the branch DirtTrack 2
    glBegin(GL_QUADS);
    glColor4f(0.63f, 0.41f, 0.23f, 1.0f);// brown color
    glVertex2f(-0.84f, -0.48f);
    glVertex2f(-0.55f, -0.48f);
    glVertex2f(-0.53f, -0.70f);
    glVertex2f(-0.86f, -0.70f);
    glEnd();
}

void W_walls()
{
    //the below rectangle for wall 1
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.60f, 0.09f);
    glVertex2f(1.5f, 0.09f);
    glVertex2f(1.5f, 0.03f);
    glVertex2f(0.60f, 0.03f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.60f, 0.09f);
    glVertex2f(1.5f, 0.09f);
    glVertex2f(1.5f, 0.03f);
    glVertex2f(0.60f, 0.03f);
    glEnd();

    //the above rectangle for wall 1
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.60f, 0.21f);
    glVertex2f(1.0f, 0.21f);
    glVertex2f(1.0f, 0.15f);
    glVertex2f(0.60f, 0.15f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.60f, 0.21f);
    glVertex2f(1.0f, 0.21f);
    glVertex2f(1.0f, 0.15f);
    glVertex2f(0.60f, 0.15f);
    glEnd();

    //wall 1
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.60f, 0.23f);
    glVertex2f(0.67f, 0.23f);
    glVertex2f(0.67f, -0.05f);
    glVertex2f(0.60f, -0.05f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.60f, 0.23f);
    glVertex2f(0.67f, 0.23f);
    glVertex2f(0.67f, -0.05f);
    glVertex2f(0.60f, -0.05f);
    glEnd();

    //the above rectangle for wall 2
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.20f, 0.21f);
    glVertex2f(0.60f, 0.21f);
    glVertex2f(0.60f, 0.15f);
    glVertex2f(0.20f, 0.15f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.20f, 0.21f);
    glVertex2f(0.60f, 0.21f);
    glVertex2f(0.60f, 0.15f);
    glVertex2f(0.20f, 0.15f);
    glEnd();

    //the below rectangle for wall 2
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.20f, 0.09f);
    glVertex2f(0.60f, 0.09f);
    glVertex2f(0.60f, 0.03f);
    glVertex2f(0.20f, 0.03f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.20f, 0.09f);
    glVertex2f(0.60f, 0.09f);
    glVertex2f(0.60f, 0.03f);
    glVertex2f(0.20f, 0.03f);
    glEnd();

    //wall 2
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.20f, 0.23f);
    glVertex2f(0.27f, 0.23f);
    glVertex2f(0.27f, -0.05f);
    glVertex2f(0.20f, -0.05f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.20f, 0.23f);
    glVertex2f(0.27f, 0.23f);
    glVertex2f(0.27f, -0.05f);
    glVertex2f(0.20f, -0.05f);
    glEnd();

    //the above rectangle for wall 3
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.20f, 0.21f);
    glVertex2f(-0.67f, 0.21f);
    glVertex2f(-0.67f, 0.15f);
    glVertex2f(-0.20f, 0.15f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.20f, 0.21f);
    glVertex2f(-0.67f, 0.21f);
    glVertex2f(-0.67f, 0.15f);
    glVertex2f(-0.20f, 0.15f);
    glEnd();

    //the below rectangle for wall 3
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.20f, 0.09f);
    glVertex2f(-0.67f, 0.09f);
    glVertex2f(-0.67f, 0.03f);
    glVertex2f(-0.20f, 0.03f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.20f, 0.09f);
    glVertex2f(-0.67f, 0.09f);
    glVertex2f(-0.67f, 0.03f);
    glVertex2f(-0.20f, 0.03f);
    glEnd();

    //wall 3
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.20f, 0.23f);
    glVertex2f(-0.27f, 0.23f);
    glVertex2f(-0.27f, -0.05f);
    glVertex2f(-0.20f, -0.05f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.20f, 0.23f);
    glVertex2f(-0.27f, 0.23f);
    glVertex2f(-0.27f, -0.05f);
    glVertex2f(-0.20f, -0.05f);
    glEnd();

    //the above rectangle for wall 4
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-1.0f, 0.21f);
    glVertex2f(-1.0f, 0.15f);
    glVertex2f(-0.60f, 0.15f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-1.0f, 0.21f);
    glVertex2f(-1.0f, 0.15f);
    glVertex2f(-0.60f, 0.15f);
    glEnd();

    //the below rectangle for wall 4
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.60f, 0.09f);
    glVertex2f(-1.0f, 0.09f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(-0.60f, 0.03f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.60f, 0.09f);
    glVertex2f(-1.0f, 0.09f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(-0.60f, 0.03f);
    glEnd();

    //wall 4
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.60f, 0.23f);
    glVertex2f(-0.67f, 0.23f);
    glVertex2f(-0.67f, -0.05f);
    glVertex2f(-0.60f, -0.05f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.60f, 0.23f);
    glVertex2f(-0.67f, 0.23f);
    glVertex2f(-0.67f, -0.05f);
    glVertex2f(-0.60f, -0.05f);
    glEnd();
}

void wallTringle()
{
    //tringle for wall 1
    glBegin(GL_TRIANGLES);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.63f, 0.29f);
    glVertex2f(0.60f, 0.23f);
    glVertex2f(0.67f, 0.23f);
    glEnd();
    //LineLoop for a triangle 1
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.63f, 0.29f);
    glVertex2f(0.60f, 0.23f);
    glVertex2f(0.67f, 0.23f);
    glEnd();

    //tringle for wall 2
    glBegin(GL_TRIANGLES);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.23f, 0.29f);
    glVertex2f(0.20f, 0.23f);
    glVertex2f(0.27f, 0.23f);
    glEnd();
    //LineLoop for a triangle 2
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.23f, 0.29f);
    glVertex2f(0.20f, 0.23f);
    glVertex2f(0.27f, 0.23f);
    glEnd();

    //tringle for wall 3
    glBegin(GL_TRIANGLES);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.23f, 0.29f);
    glVertex2f(-0.20f, 0.23f);
    glVertex2f(-0.27f, 0.23f);
    glEnd();
    //LineLoop for a triangle 3
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.23f, 0.29f);
    glVertex2f(-0.20f, 0.23f);
    glVertex2f(-0.27f, 0.23f);
    glEnd();

    //tringle for wall  4
    glBegin(GL_TRIANGLES);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.63f, 0.29f);
    glVertex2f(-0.60f, 0.23f);
    glVertex2f(-0.67f, 0.23f);
    glEnd();
    //LineLoop for a triangle 4
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.63f, 0.29f);
    glVertex2f(-0.60f, 0.23f);
    glVertex2f(-0.67f, 0.23f);
    glEnd();
}

void doorway()
{
    //doorway
    glColor3f(0.0f, 0.0f, 0.0f);
    drawHollowCircle2(0.0, 0.15, 0.29);
    glBegin(GL_LINES);
    //line 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.0f);
    glVertex2f(0.29f, 0.15f);
    //Line 2
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.29f, 0.0f);
    glVertex2f(-0.29f, 0.15f);
    glEnd();

    //Panel of the doorway
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.23f, 0.59f);
    glVertex2f(0.23f, 0.59f);
    glVertex2f(0.23f, 0.45f);
    glVertex2f(-0.23f, 0.45f);
    glEnd();

    //LineLoop for a panel of the doorway
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.23f, 0.59f);
    glVertex2f(0.23f, 0.59f);
    glVertex2f(0.23f, 0.45f);
    glVertex2f(-0.23f, 0.45f);
    glEnd();
    //To write on the Panel
    //Refrence: ChatGPT
    glRasterPos2f(-0.1f, 0.495f);
    const char* text1 = "ZOO";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text1);
        text1++;
    }
}


void faceforChildEX() {
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.047, -0.01, 0.08);
    //Head
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    drawFilledCircle(-0.047, -0.03, 0.08);
    //eye1
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawHollowCircle3(-0.07, -0.0, 0.009);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.07, -0.02, 0.009);
    //eye2
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawHollowCircle3(-0.01, -0.0, 0.009);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.01, -0.02, 0.009);
    //
    glColor4f(0.69f, 0.176f, 0.196f, 1.0f);
    drawHollowCircle1(-0.045, -0.06, 0.01);
}

void childEx() {
    //to translate the child face
    glPushMatrix();
    glTranslatef(0.027, 0.0, 0.0);
    faceforChildEX();
    glPopMatrix();
    //Body
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.095f, -0.10f);
    glVertex2f(0.05f, -0.10f);
    glVertex2f(0.05f, -0.26f);
    glVertex2f(-0.095f, -0.26f);
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawHollowCircle0(-0.03, -0.18, 0.04);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawHollowCircle0(-0.015, -0.18, 0.02);

    //Right Leg
    glBegin(GL_QUADS);
    glColor4f(0.05f, 0.14f, 0.27f, 1.0f);
    glVertex2f(0.01f, -0.26f);
    glVertex2f(0.05f, -0.26f);
    glVertex2f(0.05f, -0.38f);
    glVertex2f(0.01f, -0.38f);
    glEnd();

    ////Left Leg
    glBegin(GL_QUADS);
    glColor4f(0.05f, 0.14f, 0.27f, 1.0f);
    glVertex2f(-0.09f, -0.26f);
    glVertex2f(-0.05f, -0.26f);
    glVertex2f(-0.05f, -0.38f);
    glVertex2f(-0.09f, -0.38f);
    glEnd();

    //رجل يمين
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(0.01f, -0.38f);
    glVertex2f(0.05f, -0.38f);
    glVertex2f(0.05f, -0.40f);
    glVertex2f(0.01f, -0.40f);
    glEnd();

    //رجل يسار
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(-0.09f, -0.38f);
    glVertex2f(-0.05f, -0.38f);
    glVertex2f(-0.05f, -0.40f);
    glVertex2f(-0.09f, -0.40f);
    glEnd();

    //ذراع يسار
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.09f, -0.10f);
    glVertex2f(-0.10f, -0.10f);
    glVertex2f(-0.10f, -0.15f);
    glVertex2f(-0.09f, -0.15f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.12f, -0.10f);
    glVertex2f(-0.10f, -0.10f);
    glVertex2f(-0.10f, -0.20f);
    glVertex2f(-0.12f, -0.20f);
    glEnd();

    //Left Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(-0.12f, -0.20f);
    glVertex2f(-0.10f, -0.20);
    glVertex2f(-0.10f, -0.24f);
    glVertex2f(-0.12f, -0.24f);
    glEnd();


    ////ذراع يمين
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(0.05f, -0.10f);
    glVertex2f(0.06f, -0.10f);
    glVertex2f(0.06f, -0.15f);
    glVertex2f(0.05f, -0.15f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(0.06f, -0.10f);
    glVertex2f(0.075f, -0.10f);
    glVertex2f(0.075f, -0.20f);
    glVertex2f(0.06f, -0.20f);
    glEnd();

    //Right Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(0.06f, -0.20f);
    glVertex2f(0.075f, -0.20);
    glVertex2f(0.075f, -0.24f);
    glVertex2f(0.06f, -0.24f);
    glEnd();
}

void faceforChildTicket() {
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.047, -0.01, 0.08);
    //Head
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    drawFilledCircle(-0.047, -0.03, 0.08);
    //eye1
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawHollowCircle3(-0.07, -0.0, 0.012);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.07, -0.02, 0.009);
    //eye2
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawHollowCircle3(-0.01, -0.0, 0.012);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.01, -0.02, 0.009);
    //
    glColor4f(0.69f, 0.176f, 0.196f, 1.0f);
    drawHollowCircle1(-0.045, -0.06, 0.013);
}
void childTicket() {
    //to translate the child face
    glPushMatrix();
    glTranslatef(0.027, 0.0, 0.0);
    faceforChildTicket();
    glPopMatrix();
    //Body
    glBegin(GL_QUADS);
    glColor4f(0.26f, 0.05f, 0.278f, 1.0f);
    glVertex2f(-0.095f, -0.10f);
    glVertex2f(0.05f, -0.10f);
    glVertex2f(0.05f, -0.26f);
    glVertex2f(-0.095f, -0.26f);
    glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawHollowCircle0(-0.03, -0.18, 0.04);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawHollowCircle0(-0.015, -0.18, 0.02);

    //Right Leg
    glBegin(GL_QUADS);
    glColor4f(0.05f, 0.14f, 0.27f, 1.0f);
    glVertex2f(0.01f, -0.26f);
    glVertex2f(0.05f, -0.26f);
    glVertex2f(0.05f, -0.38f);
    glVertex2f(0.01f, -0.38f);
    glEnd();

    ////Left Leg
    glBegin(GL_QUADS);
    glColor4f(0.05f, 0.14f, 0.27f, 1.0f);
    glVertex2f(-0.09f, -0.26f);
    glVertex2f(-0.05f, -0.26f);
    glVertex2f(-0.05f, -0.38f);
    glVertex2f(-0.09f, -0.38f);
    glEnd();

    //رجل يمين
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(0.01f, -0.38f);
    glVertex2f(0.05f, -0.38f);
    glVertex2f(0.05f, -0.40f);
    glVertex2f(0.01f, -0.40f);
    glEnd();

    //رجل يسار
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(-0.09f, -0.38f);
    glVertex2f(-0.05f, -0.38f);
    glVertex2f(-0.05f, -0.40f);
    glVertex2f(-0.09f, -0.40f);
    glEnd();

    //ذراع يسار
    glBegin(GL_QUADS);
    glColor4f(0.26f, 0.05f, 0.278f, 1.0f);
    glVertex2f(-0.095f, -0.10f);
    glVertex2f(-0.10f, -0.10f);
    glVertex2f(-0.10f, -0.15f);
    glVertex2f(-0.095f, -0.15f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.89f, 0.517f, 0.929f, 1.0f);
    glVertex2f(-0.12f, -0.10f);
    glVertex2f(-0.10f, -0.10f);
    glVertex2f(-0.10f, -0.20f);
    glVertex2f(-0.12f, -0.20f);
    glEnd();

    //Left Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(-0.12f, -0.20f);
    glVertex2f(-0.10f, -0.20);
    glVertex2f(-0.10f, -0.24f);
    glVertex2f(-0.12f, -0.24f);
    glEnd();


    ////ذراع يمين
    glBegin(GL_QUADS);
    glColor4f(0.26f, 0.05f, 0.278f, 1.0f);
    glVertex2f(0.05f, -0.10f);
    glVertex2f(0.06f, -0.10f);
    glVertex2f(0.06f, -0.15f);
    glVertex2f(0.05f, -0.15f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.89f, 0.517f, 0.929f, 1.0f);
    glVertex2f(0.06f, -0.10f);
    glVertex2f(0.075f, -0.10f);
    glVertex2f(0.075f, -0.20f);
    glVertex2f(0.06f, -0.20f);
    glEnd();

    //Right Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(0.06f, -0.20f);
    glVertex2f(0.075f, -0.20);
    glVertex2f(0.075f, -0.24f);
    glVertex2f(0.06f, -0.24f);
    glEnd();
}

void TicketCornerEx() {

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-0.93, 0.20);
    glVertex2f(-0.44, 0.20);
    glVertex2f(-0.44, -0.43);
    glVertex2f(-0.93, -0.43);
    glEnd();

    //Glass window
    glBegin(GL_QUADS);
    glColor4f(0.858f, 1.0f, 0.964f, 0.01);
    glVertex2f(-0.90, 0.12);
    glVertex2f(-0.46, 0.12);
    glVertex2f(-0.46, -0.07);
    glVertex2f(-0.90, -0.07);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.13f, 0.305f, 0.309f, 0.09f);
    glVertex2f(-0.93, -0.17);
    glVertex2f(-0.44, -0.17);
    glVertex2f(-0.44, -0.42);
    glVertex2f(-0.93, -0.42);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle2(-0.68, -0.17, 0.07);

    //To write on the TicketCorner
    //Refrence: ChatGPT
    glRasterPos2f(-0.89f, 0.14f);
    const char* text1 = "Ticket Reservation";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *text1);
        text1++;
    }
}

void TicketCorner() {

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-0.93, 0.20);
    glVertex2f(-0.44, 0.20);
    glVertex2f(-0.44, -0.43);
    glVertex2f(-0.93, -0.43);
    glEnd();

    //Glass window
    glBegin(GL_QUADS);
    glColor4f(0.858f, 1.0f, 0.964f, 0.001);
    glVertex2f(-0.90, 0.12);
    glVertex2f(-0.46, 0.12);
    glVertex2f(-0.46, -0.07);
    glVertex2f(-0.90, -0.07);
    glEnd();
    //to translate the childticket
    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-0.83, 0.055, 0.0);
    childTicket();
    glPopMatrix();
    //
    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(-0.93, -0.07);
    glVertex2f(-0.44, -0.07);
    glVertex2f(-0.44, -0.17);
    glVertex2f(-0.93, -0.17);
    glEnd();
    //green
    glBegin(GL_QUADS);
    glColor4f(0.13f, 0.305f, 0.309f, 0.09f);
    glVertex2f(-0.93, -0.17);
    glVertex2f(-0.44, -0.17);
    glVertex2f(-0.44, -0.42);
    glVertex2f(-0.93, -0.42);
    glEnd();
    //
    glColor3f(0.0, 0.0, 0.0);
    drawFilledCircle2(-0.68, -0.17, 0.07);

    //To write on the TicketCorner
    //Refrence: ChatGPT
    glRasterPos2f(-0.89f, 0.14f);
    const char* text1 = "Ticket Reservation";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *text1);
        text1++;
    }
}


void InteringPanel() {
    //Panel
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.34, -0.32);
    glVertex2f(-0.30, -0.32);
    glVertex2f(-0.30, -0.57);
    glVertex2f(-0.34, -0.57);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.34, -0.32);
    glVertex2f(-0.30, -0.32);
    glVertex2f(-0.30, -0.57);
    glVertex2f(-0.34, -0.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.42, -0.26);
    glVertex2f(-0.22, -0.26);
    glVertex2f(-0.22, -0.38);
    glVertex2f(-0.42, -0.38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.42, -0.26);
    glVertex2f(-0.22, -0.26);
    glVertex2f(-0.22, -0.38);
    glVertex2f(-0.42, -0.38);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex2f(-0.36, -0.58);
    glVertex2f(-0.282, -0.58);
    glEnd();
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex2f(-0.37, -0.59);
    glVertex2f(-0.275, -0.59);
    glEnd();

    //To write on the Panel
    //Refrence: ChatGPT
    glRasterPos2f(-0.365f, -0.335f);
    const char* text1 = "OPEN";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text1);
        text1++;
    }
}


void EPanel() {
    //Panel
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.34, -0.32);
    glVertex2f(-0.30, -0.32);
    glVertex2f(-0.30, -0.57);
    glVertex2f(-0.34, -0.57);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.34, -0.32);
    glVertex2f(-0.30, -0.32);
    glVertex2f(-0.30, -0.57);
    glVertex2f(-0.34, -0.57);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.42, -0.26);
    glVertex2f(-0.22, -0.26);
    glVertex2f(-0.22, -0.38);
    glVertex2f(-0.42, -0.38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.42, -0.26);
    glVertex2f(-0.22, -0.26);
    glVertex2f(-0.22, -0.38);
    glVertex2f(-0.42, -0.38);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex2f(-0.36, -0.58);
    glVertex2f(-0.282, -0.58);
    glEnd();
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex2f(-0.37, -0.59);
    glVertex2f(-0.275, -0.59);
    glEnd();

    //To write on the Panel
    //Refrence: ChatGPT
    glRasterPos2f(-0.365f, -0.335f);
    const char* text1 = "CLOSE";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text1);
        text1++;
    }
}
//to translate the roses
void transRose() {
    ////////////////////////////the First row/////////////////
    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.2, 0.3, 0.0);
    RedRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.95, 0.1, 0.0);;
    PinkRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.5, 0.1, 0.0);
    OrangeRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(0.75, 0.3, 0.0);
    YellowRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(1.20, 0.3, 0.0);
    OrangeRose();
    glPopMatrix();


    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(1.40, 0.1, 0.0);
    RedRose();
    glPopMatrix();


    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(1.49, 0.3, 0.0);
    YellowRose();
    glPopMatrix();

    ////////////////////////////the Second row/////////////////

    glPushMatrix();
    glScalef(0.6, 0.6, 1.0);
    glTranslatef(0.2, -0.2, 0.0);
    RedRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.6, 0.6, 1.0);
    glTranslatef(0.95, -0.4, 0.0);;
    PinkRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.6, 0.6, 1.0);
    glTranslatef(0.5, -0.4, 0.0);
    OrangeRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.6, 0.6, 1.0);
    glTranslatef(0.75, -0.2, 0.0);
    YellowRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.6, 0.6, 1.0);
    glTranslatef(1.20, -0.2, 0.0);
    OrangeRose();
    glPopMatrix();


    ////////////////////////////the Third row/////////////////

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(0.2, -0.6, 0.0);
    RedRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(0.89, -0.8, 0.0);;
    PinkRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(0.5, -0.8, 0.0);
    OrangeRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(0.75, -0.6, 0.0);
    YellowRose();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1.0);
    glTranslatef(0.995, -0.6, 0.0);
    OrangeRose();
    glPopMatrix();

}

void childz()
{
    //Head
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    drawFilledCircle(-0.047, -0.53, 0.08);
    //Hair
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.047, -0.51, 0.08);
    //Body
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.12f, -0.6f);
    glVertex2f(0.02f, -0.6f);
    glVertex2f(0.02f, -0.76f);
    glVertex2f(-0.12f, -0.76f);
    glEnd();

    //Right Leg
    glBegin(GL_QUADS);
    glColor4f(0.05f, 0.14f, 0.27f, 1.0f);
    glVertex2f(-0.02f, -0.76f);
    glVertex2f(0.02f, -0.76f);
    glVertex2f(0.02f, -0.88f);
    glVertex2f(-0.02f, -0.88f);
    glEnd();

    //Left Leg
    glBegin(GL_QUADS);
    glColor4f(0.05f, 0.14f, 0.27f, 1.0f);
    glVertex2f(-0.12f, -0.76f);
    glVertex2f(-0.08f, -0.76f);
    glVertex2f(-0.08f, -0.88f);
    glVertex2f(-0.12f, -0.88f);
    glEnd();

    //رجل يمين
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(-0.02f, -0.88f);
    glVertex2f(0.02f, -0.88f);
    glVertex2f(0.02f, -0.90f);
    glVertex2f(-0.02f, -0.90f);
    glEnd();

    //رجل يسار
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(-0.12f, -0.88f);
    glVertex2f(-0.08f, -0.88f);
    glVertex2f(-0.08f, -0.90f);
    glVertex2f(-0.12f, -0.90f);
    glEnd();

    //ذراع يسار
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.12f, -0.6f);
    glVertex2f(-0.13f, -0.6f);
    glVertex2f(-0.13f, -0.65f);
    glVertex2f(-0.12f, -0.65f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.16f, -0.6f);
    glVertex2f(-0.13f, -0.6f);
    glVertex2f(-0.13f, -0.70f);
    glVertex2f(-0.16f, -0.70f);
    glEnd();

    //Left Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(-0.16f, -0.70f);
    glVertex2f(-0.13f, -0.70);
    glVertex2f(-0.13f, -0.74f);
    glVertex2f(-0.16f, -0.74f);
    glEnd();
    //

    ////ذراع يمين
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(0.02f, -0.6f);
    glVertex2f(0.03f, -0.6f);
    glVertex2f(0.03f, -0.65f);
    glVertex2f(0.02f, -0.65f);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(0.06f, -0.6f);
    glVertex2f(0.03f, -0.6f);
    glVertex2f(0.03f, -0.70f);
    glVertex2f(0.06f, -0.70f);
    glEnd();

    //Right Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(0.06f, -0.70f);
    glVertex2f(0.03f, -0.70);
    glVertex2f(0.03f, -0.74f);
    glVertex2f(0.06f, -0.74f);
    glEnd();
}




void childt()
{
    //Head
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    drawFilledCircle(-0.047, -0.53, 0.08);
    //Hair
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.047, -0.51, 0.08);
    //Body
    glBegin(GL_QUADS);
    glColor4f(0.92f, 0.235f, 0.235f, 1.0f);
    glVertex2f(-0.12f, -0.6f);
    glVertex2f(0.02f, -0.6f);
    glVertex2f(0.02f, -0.76f);
    glVertex2f(-0.12f, -0.76f);
    glEnd();

    //Right Leg
    glBegin(GL_QUADS);
    glColor4f(0.019f, 0.062f, 0.121f, 1.0f);
    glVertex2f(-0.02f, -0.76f);
    glVertex2f(0.02f, -0.76f);
    glVertex2f(0.02f, -0.88f);
    glVertex2f(-0.02f, -0.88f);
    glEnd();

    //Left Leg
    glBegin(GL_QUADS);
    glColor4f(0.019f, 0.062f, 0.121f, 1.0f);
    glVertex2f(-0.12f, -0.76f);
    glVertex2f(-0.08f, -0.76f);
    glVertex2f(-0.08f, -0.88f);
    glVertex2f(-0.12f, -0.88f);
    glEnd();

    //رجل يمين
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(-0.02f, -0.88f);
    glVertex2f(0.02f, -0.88f);
    glVertex2f(0.02f, -0.90f);
    glVertex2f(-0.02f, -0.90f);
    glEnd();

    //رجل يسار
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(-0.12f, -0.88f);
    glVertex2f(-0.08f, -0.88f);
    glVertex2f(-0.08f, -0.90f);
    glVertex2f(-0.12f, -0.90f);
    glEnd();

    //ذراع يسار
    glBegin(GL_QUADS);
    glColor4f(0.92f, 0.235f, 0.235f, 1.0f);
    glVertex2f(-0.12f, -0.6f);
    glVertex2f(-0.13f, -0.6f);
    glVertex2f(-0.13f, -0.65f);
    glVertex2f(-0.12f, -0.65f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.92f, 0.235f, 0.235f, 1.0f);
    glVertex2f(-0.16f, -0.6f);
    glVertex2f(-0.13f, -0.6f);
    glVertex2f(-0.13f, -0.70f);
    glVertex2f(-0.16f, -0.70f);
    glEnd();

    //Left Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(-0.16f, -0.70f);
    glVertex2f(-0.13f, -0.70);
    glVertex2f(-0.13f, -0.74f);
    glVertex2f(-0.16f, -0.74f);
    glEnd();
    //

    ////ذراع يمين
    glBegin(GL_QUADS);
    glColor4f(0.92f, 0.235f, 0.235f, 1.0f);
    glVertex2f(0.02f, -0.6f);
    glVertex2f(0.03f, -0.6f);
    glVertex2f(0.03f, -0.65f);
    glVertex2f(0.02f, -0.65f);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor4f(0.92f, 0.235f, 0.235f, 1.0f);
    glVertex2f(0.06f, -0.6f);
    glVertex2f(0.03f, -0.6f);
    glVertex2f(0.03f, -0.70f);
    glVertex2f(0.06f, -0.70f);
    glEnd();

    //Right Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(0.06f, -0.70f);
    glVertex2f(0.03f, -0.70);
    glVertex2f(0.03f, -0.74f);
    glVertex2f(0.06f, -0.74f);
    glEnd();
}


//to start a story
void Start() {

    // Draw a Square for the main DirtTrack
    glBegin(GL_QUADS);
    glColor4f(0.63f, 0.41f, 0.23f, 1.0f);// brown color
    glVertex2f(-0.14f, 0.20f);
    glVertex2f(0.14f, 0.20f);
    glVertex2f(0.26f, -1.0f);
    glVertex2f(-0.26f, -1.0f);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.28f, 0.1f);
    const char* text1 = "Trip To The ZOO";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text1);
        text1++;
    }

    //the Start button
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
    drawFilledCircle(-0.012, -0.1, 0.15);
    glBegin(GL_TRIANGLES);
    glColor4f(0.0f, 0.37f, 0.81f, 1.0f);
    glVertex2f(0.095f, -0.1f);
    glVertex2f(-0.065f, -0.2f);
    glVertex2f(-0.065f, 0.0f);
    glEnd();

    //To write on the Panel
    //Refrence: ChatGPT
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.08f, -0.33f);
    const char* text2 = "START";
    while (*text2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text2);
        text2++;
    }
    ///

    //the below rectangle for wall 1
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.60f, 0.09f);
    glVertex2f(1.5f, 0.09f);
    glVertex2f(1.5f, 0.03f);
    glVertex2f(0.60f, 0.03f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.60f, 0.09f);
    glVertex2f(1.5f, 0.09f);
    glVertex2f(1.5f, 0.03f);
    glVertex2f(0.60f, 0.03f);
    glEnd();

    //the above rectangle for wall 1
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.60f, 0.21f);
    glVertex2f(1.0f, 0.21f);
    glVertex2f(1.0f, 0.15f);
    glVertex2f(0.60f, 0.15f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.60f, 0.21f);
    glVertex2f(1.0f, 0.21f);
    glVertex2f(1.0f, 0.15f);
    glVertex2f(0.60f, 0.15f);
    glEnd();

    //wall 1
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.60f, 0.23f);
    glVertex2f(0.67f, 0.23f);
    glVertex2f(0.67f, -0.05f);
    glVertex2f(0.60f, -0.05f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.60f, 0.23f);
    glVertex2f(0.67f, 0.23f);
    glVertex2f(0.67f, -0.05f);
    glVertex2f(0.60f, -0.05f);
    glEnd();

    //the above rectangle for wall 2
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.32f, 0.21f);
    glVertex2f(0.60f, 0.21f);
    glVertex2f(0.60f, 0.15f);
    glVertex2f(0.32f, 0.15f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.32f, 0.21f);
    glVertex2f(0.60f, 0.21f);
    glVertex2f(0.60f, 0.15f);
    glVertex2f(0.32f, 0.15f);
    glEnd();

    //the below rectangle for wall 2
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.32, 0.09f);
    glVertex2f(0.60f, 0.09f);
    glVertex2f(0.60f, 0.03f);
    glVertex2f(0.32f, 0.03f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.32, 0.09f);
    glVertex2f(0.60f, 0.09f);
    glVertex2f(0.60f, 0.03f);
    glVertex2f(0.32f, 0.03f);
    glEnd();

    //wall 2
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(0.32f, 0.23f);
    glVertex2f(0.38f, 0.23f);
    glVertex2f(0.38f, -0.05f);
    glVertex2f(0.32f, -0.05f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.32f, 0.23f);
    glVertex2f(0.38f, 0.23f);
    glVertex2f(0.38f, -0.05f);
    glVertex2f(0.32f, -0.05f);
    glEnd();

    //the above rectangle for wall 3
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.32f, 0.21f);
    glVertex2f(-0.67f, 0.21f);
    glVertex2f(-0.67f, 0.15f);
    glVertex2f(-0.32f, 0.15f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.32f, 0.21f);
    glVertex2f(-0.67f, 0.21f);
    glVertex2f(-0.67f, 0.15f);
    glVertex2f(-0.32f, 0.15f);
    glEnd();

    //the below rectangle for wall 3
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.32f, 0.09f);
    glVertex2f(-0.67f, 0.09f);
    glVertex2f(-0.67f, 0.03f);
    glVertex2f(-0.32f, 0.03f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.32f, 0.09f);
    glVertex2f(-0.67f, 0.09f);
    glVertex2f(-0.67f, 0.03f);
    glVertex2f(-0.32f, 0.03f);
    glEnd();

    //wall 3
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.32f, 0.23f);
    glVertex2f(-0.38f, 0.23f);
    glVertex2f(-0.38f, -0.05f);
    glVertex2f(-0.32f, -0.05f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.32f, 0.23f);
    glVertex2f(-0.38f, 0.23f);
    glVertex2f(-0.38f, -0.05f);
    glVertex2f(-0.32f, -0.05f);
    glEnd();

    //the above rectangle for wall 4
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-1.0f, 0.21f);
    glVertex2f(-1.0f, 0.15f);
    glVertex2f(-0.60f, 0.15f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.60f, 0.21f);
    glVertex2f(-1.0f, 0.21f);
    glVertex2f(-1.0f, 0.15f);
    glVertex2f(-0.60f, 0.15f);
    glEnd();

    //the below rectangle for wall 4
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.60f, 0.09f);
    glVertex2f(-1.0f, 0.09f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(-0.60f, 0.03f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.60f, 0.09f);
    glVertex2f(-1.0f, 0.09f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(-0.60f, 0.03f);
    glEnd();

    //wall 4
    glBegin(GL_QUADS);
    glColor4f(0.90f, 0.58f, 0.33f, 1.0f);
    glVertex2f(-0.60f, 0.23f);
    glVertex2f(-0.67f, 0.23f);
    glVertex2f(-0.67f, -0.05f);
    glVertex2f(-0.60f, -0.05f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.60f, 0.23f);
    glVertex2f(-0.67f, 0.23f);
    glVertex2f(-0.67f, -0.05f);
    glVertex2f(-0.60f, -0.05f);
    glEnd();
}

void IntePanel() {

    //Panel
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.61, -0.15);
    glVertex2f(-0.72, -0.15);
    glVertex2f(-0.72, -0.82);
    glVertex2f(-0.61, -0.82);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.61, -0.15);
    glVertex2f(-0.72, -0.15);
    glVertex2f(-0.72, -0.82);
    glVertex2f(-0.61, -0.82);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.1);
    glVertex2f(-0.92, -0.11);
    glVertex2f(-0.42, -0.11);
    glVertex2f(-0.42, -0.53);
    glVertex2f(-0.92, -0.53);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.92, -0.11);
    glVertex2f(-0.42, -0.11);
    glVertex2f(-0.42, -0.53);
    glVertex2f(-0.92, -0.53);
    glEnd();

    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex2f(-0.60, -0.83);
    glVertex2f(-0.73, -0.83);
    glEnd();
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex2f(-0.59, -0.845);
    glVertex2f(-0.74, -0.845);
    glEnd();
    //0
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.90f, -0.17f);
    const char* text0 = "Made by: ";
    while (*text0) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text0);
        text0++;
    }

    ////1
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.90f, -0.23f);
    const char* text1 = "1- Walaa Alluqmani";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *text1);
        text1++;
    }
    ////2
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.90f, -0.29f);
    const char* text2 = "2- Leena Alymani";
    while (*text2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *text2);
        text2++;
    }
    ////3
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.90f, -0.35f);
    const char* text3 = "3- Fatima Alzhrani";;
    while (*text3) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *text3);
        text3++;
    }
    ////4
    glRasterPos2f(-0.90f, -0.41f);
    const char* text4 = "4- Shahad Almalki";
    while (*text4) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *text4);
        text4++;
    }
    ////5
    glRasterPos2f(-0.90f, -0.47f);
    const char* text5 = "5- Reham Almatrafi";
    while (*text5) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *text5);
        text5++;
    }


}

void scene0() {
    Interingsky();
    WGrass();
    WTrees();
    doorway();
    IntePanel();
    WClouds();
    Start();
    childz();
    transRose();
   
}

void scene1() {
    glClear(GL_COLOR_BUFFER_BIT);
    Interingsky();
    WGrass();
    WTrees();
    DirtTrack();
    doorway();
    W_walls();
    wallTringle();
    InteringPanel();
    transRose();
}
void scene7() {
    glClear(GL_COLOR_BUFFER_BIT);
    ESky();
    WGrass();
    WTrees();
    DirtTrack();
    doorway();
    W_walls();
    wallTringle();
    EPanel();
    transRose();
}

//------------------------------------------------------------------------------------------------------------------------------------
void child()
{
    //Head
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    drawFilledCircle(-0.047, -0.53, 0.08);
    //Hair
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    drawFilledCircle(-0.047, -0.51, 0.08);
    //Body
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.12f, -0.6f);
    glVertex2f(0.02f, -0.6f);
    glVertex2f(0.02f, -0.76f);
    glVertex2f(-0.12f, -0.76f);
    glEnd();

    //Right Leg
    glBegin(GL_QUADS);
    glColor4f(0.05f, 0.14f, 0.27f, 1.0f);
    glVertex2f(-0.02f, -0.76f);
    glVertex2f(0.02f, -0.76f);
    glVertex2f(0.02f, -0.88f);
    glVertex2f(-0.02f, -0.88f);
    glEnd();

    //Left Leg
    glBegin(GL_QUADS);
    glColor4f(0.05f, 0.14f, 0.27f, 1.0f);
    glVertex2f(-0.12f, -0.76f);
    glVertex2f(-0.08f, -0.76f);
    glVertex2f(-0.08f, -0.88f);
    glVertex2f(-0.12f, -0.88f);
    glEnd();

    //رجل يمين
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(-0.02f, -0.88f);
    glVertex2f(0.02f, -0.88f);
    glVertex2f(0.02f, -0.90f);
    glVertex2f(-0.02f, -0.90f);
    glEnd();

    //رجل يسار
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    glVertex2f(-0.12f, -0.88f);
    glVertex2f(-0.08f, -0.88f);
    glVertex2f(-0.08f, -0.90f);
    glVertex2f(-0.12f, -0.90f);
    glEnd();

    //ذراع يسار
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.13f, -0.6f);
    glVertex2f(-0.12f, -0.6f);
    glVertex2f(-0.12f, -0.65f);
    glVertex2f(-0.13f, -0.65f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.14f, -0.6f);
    glVertex2f(-0.13f, -0.6f);
    glVertex2f(-0.13f, -0.65f);
    glVertex2f(-0.14f, -0.65f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(-0.17f, -0.6f);
    glVertex2f(-0.14f, -0.6f);
    glVertex2f(-0.14f, -0.70f);
    glVertex2f(-0.17f, -0.70f);
    glEnd();

    //Left Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(-0.17f, -0.70f);
    glVertex2f(-0.14f, -0.70);
    glVertex2f(-0.14f, -0.74f);
    glVertex2f(-0.17f, -0.74f);
    glEnd();


    ////ذراع يمين
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(0.01f, -0.6f);
    glVertex2f(0.04f, -0.6f);
    glVertex2f(0.04f, -0.65f);
    glVertex2f(0.01f, -0.65f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(0.06f, -0.6f);
    glVertex2f(0.04f, -0.6f);
    glVertex2f(0.04f, -0.65f);
    glVertex2f(0.06f, -0.65f);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor4f(0.81f, 0.85f, 0.023f, 1.0f);
    glVertex2f(0.07f, -0.6f);
    glVertex2f(0.04f, -0.6f);
    glVertex2f(0.04f, -0.70f);
    glVertex2f(0.07f, -0.70f);
    glEnd();

    //Right Hand
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.87f, 0.73f, 1.0f);
    glVertex2f(0.07f, -0.70f);
    glVertex2f(0.04f, -0.70);
    glVertex2f(0.04f, -0.74f);
    glVertex2f(0.07f, -0.74f);
    glEnd();

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//
//static
//void special(int key, int x, int y)
//{
//    switch (key) {
//    case GLUT_KEY_HOME:
//
//        break;
//    case GLUT_KEY_LEFT:
//
//        break;
//    case GLUT_KEY_RIGHT:
//
//        break;
//    case GLUT_KEY_UP:
//
//        break;
//    case GLUT_KEY_DOWN:
//
//        break;
//    default:
//        break;
//    }
//}
//
//
//static
//void motion(int x, int y)
//{}

static void play(void)
{
    glutPostRedisplay();
}
//ميثود الكيبور حق الحركات
static
void key(unsigned char keyPressed, int x, int y) // key handling
{
    switch (keyPressed)
    {
        //سلحفاه
    case 'o':
        TurtleTransValue1 += 0.0003;
        glTranslatef(TurtleTransValue1, 0.0, 0.0);
        break;

    case 'O':
        TurtleTransValue2 -= 0.0004;
        glTranslatef(TurtleTransValue2, 0.0, 0.0);
        break;

        //بطريق
    case 'P':
        ptransValue4 -= 0.0009;
        break;

    case 'K':
        ptransValue5 -= 0.001;
        break;

        //غنمه
    case 'G':
        StransValue2 -= 0.001;
        break;

    case 'Z':
        StransValue3 -= 0.001;
        break;

        //بسه
    case 't':
        CtransValue += 0.001;
        break;

    case 'T':
        CtransValue -= 0.003;
        break;

        //البقره
    case 'x':
        transValue2 += 0.002;
        glTranslatef(transValue2, 0.0, 0.0);
        break;

        //الباندا
    case 'l':
        transValuep -= 0.004;
        transValue1p += 0.0008;
        glTranslatef(transValuep, transValue1p, 0.0);
        break;

        //مشاهد ولاءو
    case 'b':
        //to translate the child in Scene 1
        if (transValueforChild <= 0.4) {
            transValueforChild = transValueforChild + 0.0003f;
            scaleValueforChild = scaleValueforChild - 0.0004;
            glTranslatef(0.0, transValueforChild, 0.0);
            glScalef(scaleValueforChild, scaleValueforChild, 1.0);
            cout << "The new translate value is (y) : " << transValueforChild << endl;

        }
        break;
    case 'c':
        //to translate the Clouds in Scene 1
        if (transValueforClouds <= 0.7) {
            transValueforClouds = transValueforClouds + 0.0001f;
            glTranslatef(transValueforClouds, 0.0, 0.0);
            cout << "The new translate value is (x) : " << transValueforClouds << endl;
        }
        break;
    case 'C':
        //to translate the Clouds in Scene 7
        if (transValueforClouds2 >= -0.7) {
            transValueforClouds2 = transValueforClouds2 - 0.0001f;
            glTranslatef(transValueforClouds2, 0.0, 0.0);
            cout << "The new translate value is (-x) : " << transValueforClouds2 << endl;
        }

        break;

    case 'B':
        //to translate the child in Scene 7
        if (transValueforChild2 >= -0.7) {
            transValueforChild2 = transValueforChild2 - 0.0003f;
//            scaleValueforChild2 = scaleValueforChild2 + 0.001;
            glTranslatef(0.0, transValueforChild2, 0.0);
//            glScalef(scaleValueforChild2, scaleValueforChild2, 1.0);
            cout << "The new translate value is (-y) : " << transValueforChild2 << endl;

        }
        break;

    case 'q':
        exit(0);
        break;

    default:
        fprintf(stderr, "\nKeyboard commands:\n\n"
            "t, T        - translate \n"
            "q, <esc>    - Quit\n");
        break;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//دسبلاي السلحفاه
void TurtleDisplay()
{

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    TurtleEnvironment();

    glPushMatrix();
    key('o', 0.0, 0.0);
    the1stTurtle();
    glPopMatrix();

    glPushMatrix();
    key('O', 0.0, 0.0);
    the2ndTurtle();
    glPopMatrix();

    glTranslatef(0.4, 0.38, 0.0);
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0); //zom out
    glScalef(-1.0, 1, 1);
    the1stTurtle();

    glTranslatef(2.0, -0.1, 0.0);
    glScalef(1.0, 1, 1);
    the2ndTurtle();
    glPopMatrix();

    TurtleInfo();

    glPushMatrix();
    glTranslatef(-0.4, 0.4, 0.0);
    glScaled(1.5, 1.5, 1.0);
    child();
    glPopMatrix();

    glutSwapBuffers();
}
//------------------------------------------------------------------------------------------------------
//دسبلاي البطريق

void penguinDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    penguinSky();

    //method
    penguinBackround1();
    penguinCloud();

    penguinSun();

    //colud start
    glPushMatrix();
    glTranslatef(-0.5, -0.22, 0);
    penguinCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.11, -0.03, 0);
    penguinCloud();
    glPopMatrix();
    //cloud end

   //small one
    glPushMatrix();
    glScalef(0.4, 0.4, 0.0);
    glTranslatef(ptransValue4, 0.5, 0);
    penguin();
    glPopMatrix();


    //big one
    glPushMatrix();
    glScalef(0.63, 0.63, 0.0);
    glTranslatef(ptransValue5, 0.6, 0);
    penguin();
    glPopMatrix();

    penguinFence();
    penguinInfo();

    //To write on the screen
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.96f, 0.25f);
    const char* text1 = "Name: penguin";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text1);
        text1++;
    }

    glRasterPos2f(-0.96f, 0.20f);
    const char* text2 = "Family: Spheniscidae";
    while (*text2) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text2);
        text2++;
    }

    glRasterPos2f(-0.96f, 0.15f);
    const char* text3 = "Food: Fishes";
    while (*text3) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text3);
        text3++;
    }

    glRasterPos2f(-0.96f, 0.1f);
    const char* text4 = "Location: sub antarctic island";
    while (*text4) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text4);
        text4++;
    }

    glRasterPos2f(-0.96f, 0.05f);
    const char* text5 = "penguin types: king,fairy";
    while (*text5) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text5);
        text5++;
    }

    glRasterPos2f(-0.96f, -0.01f);
    const char* text6 = "chinstrao and african";
    while (*text6) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text6);
        text6++;
    }

    //call child
    glPushMatrix();
    glScalef(1.6, 1.6, 0.0);
    glTranslatef(0.42, 0.29, 0);
    child();
    glPopMatrix();

    key('P', 0.0, 0.0);
    key('K', 0.0, 0.0);

    glutSwapBuffers();
}
//------------------------------------------------------------------------------------------------------
//دسبلاي الغنمه
void SheepDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    sheepSky();

    //method
    sheepBackround1();
    sheepCloud();

    //for small tree
    glPushMatrix();
    glScalef(0.38, 0.38, 0.0);
    glTranslatef(1.48, 0.9, 0);
    sheepTree();
    glPopMatrix();

    //for big tree
    glPushMatrix();
    glScalef(0.6, 0.6, 0.0);
    glTranslatef(0.3, 0.8, 0);
    sheepTree();
    glPopMatrix();

    sheepSun();

    //colud start
    glPushMatrix();
    glTranslatef(-0.5, -0.22, 0);
    sheepCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1, -0.3, 0);
    sheepCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.11, -0.03, 0);
    sheepCloud();
    glPopMatrix();
    //cloud end

    //rose start
    glPushMatrix();
    glTranslatef(0.3, 0.8, 0);
    glColor3f(1.0, 0.6, 0.1);
    sheepRose2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.8, 0);
    glColor3f(1.0, 0.9, 0.2);
    sheepRose2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.45, 0.6, 0);
    glColor3f(1.0, 0.0, 0.1);
    sheepRose2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.62, 0.44, 0);
    glColor3f(0.8, 0.4, 0.4);
    sheepRose2();
    glPopMatrix();
    //rose end

    //*the small sheep
    glPushMatrix();
    glScalef(0.3, 0.3, 0.0);
    glTranslatef(StransValue2, 1.3, 0);
    sheepFace();
    glPopMatrix();

    //the big sheep
    glPushMatrix();
    glScalef(0.5, 0.5, 0.0);
    glTranslatef(StransValue3, 0.80, 0);
    sheepFace();
    glPopMatrix();

    sheepFence();
    sheepInfo();

    //To write on the screen
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.96f, 0.25f);
    const char* text1 = "Name: sheep";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text1);
        text1++;
    }

    glRasterPos2f(-0.96f, 0.20f);
    const char* text2 = "Family: Bovide";
    while (*text2) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text2);
        text2++;
    }

    glRasterPos2f(-0.96f, 0.15f);
    const char* text3 = "Food: Herbivore";
    while (*text3) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text3);
        text3++;
    }

    glRasterPos2f(-0.96f, 0.1f);
    const char* text4 = "Location: all over the world";
    while (*text4) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text4);
        text4++;
    }

    glRasterPos2f(-0.96f, 0.05f);
    const char* text5 = "What caracterizes it: foolish";
    while (*text5) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text5);
        text5++;
    }

    glRasterPos2f(-0.96f, -0.01f);
    const char* text6 = "and resourceful";
    while (*text6) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text6);
        text6++;
    }

    //call child
    glPushMatrix();
    glScalef(1.6, 1.6, 0.0);
    glTranslatef(0.42, 0.29, 0);
    child();
    glPopMatrix();

    key('G', 0.0, 0.0);
    key('Z', 0.0, 0.0);

    glutSwapBuffers();
}

//------------------------------------------------------------------------------------------------------
//دسبلاي البسه

void CatDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color buffer
    glEnable(GL_BLEND);

    catSky();// color of sky
    catGrass(); // grass
    catClouds();// clouds and sun
    bsbs();//the cat

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(-0.3, 0.3, 0.0);
    glScalef(0.7, 0.7, 1.0);
    bsbs();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 0.0, 0.0);
    glTranslatef(CtransValue, -0.3, 0.0);
    key('T', 0.0, 0.0);
    bsbs();
    glPopMatrix();

    catWood();
    //write
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.95f, 0.5f);
    const char* text1 = "Name: cat ";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text1);
        text1++;
    }

    glRasterPos2f(-0.95f, 0.4f);
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* text2 = "Family: Felidae ";
    while (*text2) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text2);
        text2++;
    }
    glRasterPos2f(-0.95f, 0.3f);
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* text3 = "Foods: meet ";
    while (*text3) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text3);
        text3++;
    }
    glRasterPos2f(-0.95f, 0.2f);
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* text4 = "Features: flexible body ";
    while (*text4) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text4);
        text4++;
    }
    glRasterPos2f(-0.95f, 0.1f);
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* text5 = "Location: everywhere ";
    while (*text5) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text5);
        text5++;
    }
    catFence(); // fence of zoo
    glPushMatrix();
    glTranslatef(0.8, 1.0, 0.0);
    glScalef(2.5, 2.5, 1.0);
    child();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}
//------------------------------------------------------------------------------------------------------
//دسبلاي البقره

void cowDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color buffer
    glEnable(GL_BLEND);

    cawSky();// color of sky
    cowSun();
    cawGrass(); // grass
    cowClouds();// clouds and sun
    Cow();

    glPushMatrix();
    glTranslatef(1.2, 0.46, 0.0);
    glScalef(-0.7, 0.7, 1.0);
    //    glTranslatef(1.2, 0.0, 0.0);
    key('x', 0.0, 0.0);
    Cow();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.46, 0.0);
    glScalef(0.7, 0.5, 1.0);
    cowClouds();
    glPopMatrix();


    cowWood();
    //write
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.95f, 0.5f);
    const char* text1 = "Name: Cow ";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text1);
        text1++;
    }

    glRasterPos2f(-0.95f, 0.4f);
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* text2 = "Family:bovidae";
    while (*text2) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text2);
        text2++;
    }
    glRasterPos2f(-0.95f, 0.3f);
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* text3 = "Foods:herbs";
    while (*text3) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text3);
        text3++;
    }
    glRasterPos2f(-0.95f, 0.2f);
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* text4 = "Features:large body";
    while (*text4) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text4);
        text4++;
    }
    glRasterPos2f(-0.95f, 0.1f);
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* text5 = "Location:farms";
    while (*text5) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text5);
        text5++;
    }
    cowFence(); // fence of zoo
    glPushMatrix();
    glTranslatef(-0.05, 1.0, 0.0);
    glScalef(2.5, 2.5, 1.0);
    child();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}
//------------------------------------------------------------------------------------------------------
//ديسبلاي الباندا

void pandaDisplay() {

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);

    intarP();


    pandaSun();

    pandaClouds();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    pandaLawn();
    pandaNatural();   // trees

    glTranslatef(-0.1, 0.1, 0.5);
    glScalef(0.7, 0.7, 0.7);
    Panda1();  //Panda

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(1.0, -0.5, 0.5);
    pandaNatural1();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(1.0, -0.6, 0.3);
    key('l', 0.0, 0.0);
    PandaBack();
    glPopMatrix();

    pandaFence();

    glTranslatef(0.3, 0.7, 0.3);
    gluOrtho2D(-0.5, 0.5, -0.5, 0.5);
    child();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(0.9, 0.2, 0.1);
    pandaClouds();
    glPopMatrix();

    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.7, 0.02, 0.5);
    pandaWood();
    glPopMatrix();

    //To write on the screen
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-0.9f, 0.05f);
    const char* text1 = "Name : Panda";
    while (*text1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text1);
        text1++;
    }

    glRasterPos2f(-0.9f, 0.0f);
    const char* text2 = "Species : Bears";
    while (*text2) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text2);
        text2++;
    }

    glRasterPos2f(-0.9f, -0.05f);
    const char* text3 = "Location:southwest China";
    while (*text3) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text3);
        text3++;
    }

    glRasterPos2f(-0.9f, -0.1f);
    const char* text4 = "Food : carnivorous ";
    while (*text4) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text4);
        text4++;
    }

    glRasterPos2f(-0.9f, -0.15f);
    const char* text5 = " What is charcterized by :  ";
    while (*text5) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text5);
        text5++;
    }

    glRasterPos2f(-0.9f, -0.2f);
    const char* text6 = "  dark circles ";
    while (*text6) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *text6);
        text6++;
    }
    glTranslatef(0.0, 0.13, 0.5);
    pandaClouds();

    glTranslatef(0.7, 0.0, 0.5);
    pandaClouds();

    glFlush();
    glutSwapBuffers();

}
//------------------------------------------------------------------------------------------------------
//مشهد البدايه

void displayScene0()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    scene0();
    glutSwapBuffers();
}

//------------------------------------------------------------------------------------------------------
//مشهد الدخول

void displayScene1()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    scene1();
    //to translate the child
    glPushMatrix();
    key('b', 0.0, 0.0);
    childz();
    glPopMatrix();
    //to translate the clouds
    glPushMatrix();
    key('c', 0.0, 0.0);
    WClouds();
    glPopMatrix();

    //to translate the TicketCorner
    glPushMatrix();
    glScalef(0.78, 0.78, 1.0);
    glTranslatef(-0.2, -0.17, 0.0);
    TicketCorner();
    glPopMatrix();

    //to reduce the size of childt
    glPushMatrix();
    glScalef(0.8, 0.8, 1.0);
    glTranslatef(-0.83, 0.04, 0.0);
    childt();
    glPopMatrix();


    glutSwapBuffers();
}

//------------------------------------------------------------------------------------------------------
//مشهد الخروج

void displayScene8()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    scene7();
    glPushMatrix();
    key('B', 0.0, 0.0);
    childEx();
    glPopMatrix();
    glPushMatrix();
    key('C', 0.0, 0.0);
    WClouds();
    glPopMatrix();
    //to translate the TicketCorner
    glPushMatrix();
    glScalef(0.78, 0.78, 1.0);
    glTranslatef(-0.2, -0.17, 0.0);
    TicketCornerEx();
    glPopMatrix();
    glutSwapBuffers();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//ميثود الكيبورد حق التنقفل بين المشاهد
static
void key2(unsigned char keyPressed, int x, int y) // key handling
{
    switch (keyPressed)
    {
        //الدخول
    case '1':
        glutDisplayFunc(displayScene1);
        break;

        //باندا
    case '5':
        glutDisplayFunc(pandaDisplay);
        break;

        //سلحفاه
    case '2':
        glutDisplayFunc(TurtleDisplay);
        break;

        //غنمه
    case '3':
        glutDisplayFunc(SheepDisplay);
        break;

        //كات
    case '7':
        glutDisplayFunc(CatDisplay);
        break;

        //بطريق
    case '6':
        glutDisplayFunc(penguinDisplay);
        break;

        //بقره
    case '4':
        glutDisplayFunc(cowDisplay);
        break;

        //الخروج
    case '8':
        glutDisplayFunc(displayScene8);
        break;

    case 'q':
        exit(0);
        break;

    default:
        fprintf(stderr, "\nKeyboard commands:\n\n"
            "numbers from 1 to 8 for displaying scenes \n"
            "q for Quit\n");
        break;
    }
}


static
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {

        if (state == GLUT_UP) {
            glutDisplayFunc(displayScene1);
        }
    }
    if (button == GLUT_RIGHT_BUTTON) {

        if (state == GLUT_UP) {
            glutDisplayFunc(displayScene1);

        }
    }
}

void reshapeFun(GLint newWidth, GLint newHight)
{
    glViewport(0, 0, newWidth, newHight);
    win_width = newWidth;
    win_hight = newHight;
}

void init()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    //    glClearColor(0.09f, 0.5f, 0.21f, 1.0f); // Set background color to gسلحفاه

    //    glClearColor(0.64f, 0.91f, 0.98f, 0.9f); // Set background colorبطريق

    //    glClearColor(0.64f, 0.91f, 0.98f, 0.9f); // Set background colorغنمه

    //    glClearColor(0.70f, 0.70f, 0.70f, 1.0f); // Set backgroundالبسه

    //    glClearColor(0.70f, 0.70f, 0.70f, 1.0f); // Set background color البقره

    //    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set background color الباندا

    //    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set backgroundمشاهد ولاءوو

    glMatrixMode(GL_PROJECTION);          // set the projection parameters
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);   //  Specify the display Mode – RGB, RGBA or color //  Index, single or double Buffer
    glutInitWindowSize(win_width, win_hight);       // Set the window's initial width & height
    glutInitWindowPosition(50, 50);                 // Position the window's initial top-left corner
    glutCreateWindow("CG ZOO PROJECT");    // Create a window with the given title
    init();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(TurtleDisplay);                        // Register display callback handler for window re-paint
    glutReshapeFunc(reshapeFun);

    //سلحفاه
    TurtleTransValue1 = 0.0;
    TurtleTransValue2 = 0.0;
    //بطريق
    ptransValue4 = 1.6;
    ptransValue5 = 0.3;
    //غنمه
    StransValue2 = 0.9;
    StransValue3 = 1.3;
    //بسه
    CtransValue = 0.0;
    CscaleValue = 1.0;
    //بقره
    transValue2 = 0.0;
    transValue3 = 0.0;

    glutIdleFunc(play);
    glutDisplayFunc(displayScene0);
    glutReshapeFunc(reshapeFun);
//    glutMotionFunc(motion);
    glutKeyboardFunc(key);
    glutKeyboardFunc(key2);
//    glutSpecialFunc(special);
    glutMouseFunc(mouse);

    glutMainLoop();                                  // Enter the infinitely event-processing loop
    return 0;
}





