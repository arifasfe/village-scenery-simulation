#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1416

double  r = .2, s = .3, f = 0.1;
int i;
float  tx = 10, bx = 10, birdx = -50, boatx = 10;

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glOrtho(-210, 210, -220, 310, -210, 310);
}

void Bird(double x, double y) {
    glBegin(GL_LINES);
    glVertex2d(x, y);
    glVertex2d(x - 5, y + 2.5); // Left wing
    glVertex2d(x, y);
    glVertex2d(x + 5, y + 2.5); // Right wing
    glEnd();
}

void cloud(double x, double y)
{
    glBegin(GL_TRIANGLE_FAN);
    for (i = 0;i < 360;i++)
    {
        x = x + cos((i * PI) / 180) * r;
        y = y + sin((i * PI) / 180) * r;

        glVertex2d(x, y);
    }
    glEnd();
}

void cloud2(double x, double y)
{
    glBegin(GL_TRIANGLE_FAN);
    for (i = 0;i < 360;i++)
    {
        x = x + cos((i * PI) / 180) * s;
        y = y + sin((i * PI) / 180) * s;

        glVertex2d(x, y);
    }

    glEnd();
}

void flag_circle(double x, double y)
{
    glBegin(GL_TRIANGLE_FAN);
    for (i = 0;i < 360;i++)
    {
        x = x + cos((i * PI) / 180) * f;
        y = y + sin((i * PI) / 180) * f;

        glVertex2d(x, y);
    }

    glEnd();
}

void sun(double x, double y)
{
    glBegin(GL_TRIANGLE_FAN);// Connected group of triangles
    for (int i = 0;i < 360;i++)
    {
        x = x + cos((i * 3.14) / 180) * s;
        y = y + sin((i * 3.14) / 180) * s;

        glVertex2d(x, y);

    }
    glEnd();

}

void leaves(double x, double y)
{
    glColor3ub(0, 108, 0);
    glBegin(GL_TRIANGLE_FAN);//Draws a connected group of triangles
    for (int i = 0;i < 360;i++)
    {
        x = x + cos((i * 3.14) / 180) * s;
        y = y + sin((i * 3.14) / 180) * s;

        glVertex2d(x, y);

    }
    glEnd();

}

void fence(int x)
{
    glBegin(GL_POLYGON);
    glColor3ub(184, 134, 11);

    glVertex2i(190 - x, 130);
    glVertex2i(190 - x, 70);
    glVertex2i(187 - x, 70);
    glVertex2i(187 - x, 130);
    glVertex2i(190 - x, 130);



    glEnd();

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    //--------------SKY------------------
    glColor3ub(135, 206, 250);//light blue
    glRecti(-250, 320, 250, 100);


    /*-----------field ----------*/
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);//green
    glVertex2i(-250, 100);
    glVertex2i(-100, 160);
    glVertex2i(0, 100);
    glVertex2i(50, 70);
    glVertex2i(100, 180);
    glVertex2i(250, 100);
    glColor3ub(255, 215, 0);//gold
    glVertex2i(250, -200);
    glVertex2i(-200, -200);
    glColor3ub(255, 215, 0);
    glVertex2i(-250, 100);
    glEnd();

    //-------------------SUN-------------------------
    glColor3ub(255, 215, 0);
    sun(90, 250);
    // ------------------------------------fence--------------------------
    int x = -10;
    for (int i = 0;i < 45;i++)
    {
        fence(x);
        x += 10;
    }

    glColor3ub(184, 134, 11);
    glRecti(-250, 120, 250, 115);
    glRecti(-250, 100, 250, 95);
    glRecti(-250, 85, 250, 80);
    //-------------------------------------TREE------------------------
      //----------------------------------Small Tree----------------//
    glColor3ub(139, 69, 19);//wood
    glRecti(-20, 200, -13, 140);
    glColor3ub(0, 108, 0);//dark green
    leaves(-30, 190);
    leaves(0, 190);
    leaves(-15, 200);
    leaves(-5, 195);
    leaves(-30, 175);
    leaves(-0, 170);
    //-----------------------------------Main Tree-------------------//
    glBegin(GL_POLYGON);//first part(wood)
    glColor3ub(139, 69, 19);//
    glVertex2i(-170, 160);
    glVertex2i(-168, 120);
    glColor3ub(139, 69, 19);//
    glVertex2i(-178, 40);
    glVertex2i(-145, 40);
    glColor3ub(139, 69, 19);//
    glVertex2i(-153, 120);
    glVertex2i(-150, 160);
    glVertex2i(-170, 160);
    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // second part(brunch lower)
    glColor3ub(139, 69, 19);//
    glVertex2i(-153, 100);
    glVertex2i(-100, 200);
    glVertex2i(-95, 200);
    glVertex2i(-153, 80);
    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // third part(brunch upper left)
    glColor3ub(139, 69, 19);//
    glVertex2i(-170, 160);
    glVertex2i(-185, 210);
    glVertex2i(-190, 210);
    glVertex2i(-168, 90);
    glEnd();
    glBegin(GL_POLYGON);  // Main Tree // fourth part (brunch upper right)
    glColor3ub(139, 69, 19);//
    glVertex2i(-160, 160);
    glVertex2i(-150, 210);
    glVertex2i(-140, 210);
    glVertex2i(-150, 160);
    glVertex2i(-160, 160);
    glEnd();
    glColor3ub(0, 128, 0);//leaf
    leaves(-95, 200);//low brunch
    leaves(-80, 180);
    leaves(-110, 180);
    leaves(-120, 200);

    leaves(-150, 200);//upper right
    leaves(-130, 190);
    leaves(-125, 220);
    leaves(-140, 230);

    leaves(-183, 205);//upper left
    leaves(-180, 200);
    leaves(-175, 225);
    leaves(-183, 230);

    // --------------------------------------- HOUSE one----------------------------
    glBegin(GL_POLYGON);  // first Part
    glColor3ub(128, 0, 0);//gray
    glVertex2i(-58, 115);
    glVertex2i(-75, 145);
    glVertex2i(-115, 150);//point
    glVertex2i(-90, 100);
    glVertex2i(-62, 100);
    glEnd();

    glBegin(GL_POLYGON);  // second Part
    glColor3ub(120, 0, 0);//maroon
    glVertex2i(-115, 150);
    glVertex2i(-130, 100);
    glVertex2i(-120, 100);//point
    glVertex2i(-108, 137);//point
    glEnd();

    glBegin(GL_POLYGON);  // third Part
    glColor3ub(46, 139, 87);//
    glVertex2i(-108, 137);
    glVertex2i(-120, 100);
    glVertex2i(-120, 45);
    glVertex2i(-90, 40);//point
    glVertex2i(-90, 100);
    glEnd();

    glBegin(GL_POLYGON);  // fourth Part
    glColor3ub(143, 188, 143);//
    glVertex2i(-90, 40);
    glVertex2i(-60, 45);
    glVertex2i(-60, 100);
    glVertex2i(-90, 100);

    glEnd();
    glColor3ub(120, 0, 0);//maroon // Door samner wall r
    glRecti(-75, 80, -65, 40);
    glColor3ub(120, 0, 0);//maroon // window
    glRecti(-110, 90, -100, 70);
    glBegin(GL_POLYGON);  // third Part (lower part 1)
    glColor3ub(0, 0, 0);//
    glVertex2i(-90, 40);
    glVertex2i(-123, 45);
    glVertex2i(-123, 35);
    glVertex2i(-90, 30);
    glVertex2i(-90, 40);
    /* lower left side*/
    glEnd();

    glBegin(GL_POLYGON);  // third Part (lower part 2)
    glColor3ub(89, 89, 89);//
    glVertex2i(-90, 40);
    glVertex2i(-55, 45);
    glVertex2i(-55, 35);
    glVertex2i(-90, 30);
    glVertex2i(-90, 40);
    /* lower front side*/
    glEnd();
    //-------------------------------------------  HOUSE  two  ---------------------------------

    glBegin(GL_POLYGON); // Chhauni left
    glColor3ub(25, 25, 112);
    glVertex2i(-50, 140);
    glVertex2i(0, 149);
    glVertex2i(-12, 88);
    glVertex2i(-65, 89);
    glEnd();

    glBegin(GL_POLYGON); // Wall Left
    glColor3ub(70, 130, 180);
    glVertex2i(-60, 90);
    glVertex2i(-60, 30);
    glVertex2i(-10, 25);
    glVertex2i(-10, 95);
    glEnd();

    glColor3ub(25, 25, 112);//Door left
    glRecti(-45, 70, -30, 27);

    glBegin(GL_POLYGON);   // Wall Right
    glColor3ub(95, 158, 160);
    glVertex2i(-10, 25);
    glVertex2i(18, 35);
    glVertex2i(18, 100);
    glVertex2i(0, 148);
    glVertex2i(-10, 100);
    glVertex2i(-10, 25);

    glEnd();

    glBegin(GL_POLYGON); // CHhawni Right
    glColor3ub(0, 0, 0);
    glVertex2i(-1, 150);
    glVertex2i(22, 95);
    glVertex2i(17, 90);
    glVertex2i(-4, 140);

    glEnd();

    glBegin(GL_POLYGON);  // door Right
    glColor3ub(25, 50, 100);
    glVertex2i(0, 70);
    glVertex2i(10, 73);
    glVertex2i(10, 32);
    glVertex2i(0, 29);
    glVertex2i(0, 70);


    glEnd();

    glBegin(GL_POLYGON);  // (lower part Right
    glColor3ub(89, 89, 89);//
    glVertex2i(-10, 25);
    glVertex2i(-10, 15);
    glVertex2i(20, 27);
    glVertex2i(20, 37);
    glVertex2i(-10, 25);


    glEnd();

    glBegin(GL_POLYGON);  // (lower part 2)
    glColor3ub(0, 0, 0);//
    glVertex2i(-10, 25);
    glVertex2i(-62, 30);
    glVertex2i(-62, 20);
    glVertex2i(-10, 15);
    glVertex2i(-10, 25);

    glEnd();


    //--------------RIVER------------------
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255); //Lighter shade
    glVertex2i(-250, -50);
    glVertex2i(250, -30);
    glColor3ub(0, 0, 128); //Darker shade
    glVertex2i(250, -250);
    glVertex2i(-250, -250);
    glEnd();

    glBegin(GL_POLYGON); // BORDER
    glColor3ub(135, 135, 0);
    glVertex2i(-200, -45);
    glVertex2i(200, -25);
    glVertex2i(200, -30);
    glVertex2i(-200, -50);
    glEnd();

    //-------------BD FLAG----------------

    //---------flag base------------
    glBegin(GL_POLYGON);  // First part (Top View Outer)
    glColor3ub(50, 50, 50);
    glVertex2i(97, 32);
    glVertex2i(122, 32);
    glVertex2i(112, 2);
    glVertex2i(87, 2);
    glEnd();

    glBegin(GL_POLYGON);  // Second part (Top View Inner)
    glColor3ub(89, 89, 89);
    glVertex2i(100, 29);
    glVertex2i(117, 29);
    glVertex2i(110, 6);
    glVertex2i(92, 6);
    glEnd();

    glColor3ub(0, 0, 0); // Third part(Front View)
    glRecti(87, 2, 112, 0);

    glBegin(GL_POLYGON);  // Fourth part(Right View)
    glColor3ub(0, 0, 0);
    glVertex2i(122, 32);
    glVertex2i(123, 27);
    glVertex2i(112, 0);
    glVertex2i(112, 2);
    glEnd();

    //--------flag--------

    glPushMatrix();
    glTranslatef(105.0f, 70.0f, 0.0f); // Position change

    glBegin(GL_QUADS); // flag pole
    glColor3ub(255, 255, 153);
    glVertex2f(-1.0f, -50.0f);
    glVertex2f(0.5f, -50.0f);
    glVertex2f(0.5f, 30.0f);
    glVertex2f(-1.0f, 30.0f);
    glEnd();

    glBegin(GL_QUADS); //green rectangle
    glColor3ub(0, 153, 51);
    glVertex2f(0.5f, 27.0f);
    glVertex2f(27.0f, 27.0f);
    glVertex2f(27.0f, -5.5f);
    glVertex2f(0.5f, -5.5f);
    glEnd();

    glColor3ub(255, 0, 0); // red circle
    flag_circle(13.0f, 7.0f);

    glPopMatrix(); // End translation for the flag

    //--------------CLOUD------------------

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(tx, 0, 0);
    cloud(0, 250);
    cloud(15, 245);
    cloud(10, 240);
    cloud(-2, 243);



    cloud(-80, 250);
    cloud(-95, 245);
    cloud(-90, 240);
    cloud(-90, 243);
    cloud(-75, 243);

    glPopMatrix();
    tx += .01;
    if (tx > 200)
        tx = -200;

    glPushMatrix();
    glTranslatef(bx, 0, 0);

    glColor3ub(220, 220, 220);
    cloud2(-165, 260);
    cloud2(-185, 245);
    cloud2(-180, 240);
    cloud2(-152, 243);

    glPopMatrix();
    bx += 0.05;
    if (bx > 350)
        bx = -180;

    //-------------BIRDS-----------------

    glPushMatrix();
    glTranslatef(birdx, 200, 0);
    glColor3ub(0, 0, 0);
    Bird(0, 0);
    Bird(-10, -10);
    Bird(30, 20);

    glPopMatrix();
    birdx += 0.05;
    if (birdx > 270)
        birdx = -180;


    //--------------BOAT------------------
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glTranslatef(boatx, 0, 0);

    glBegin(GL_POLYGON);//left part
    glVertex2i(-180, -70);
    glVertex2i(-165, -100);
    glVertex2i(-150, -120);
    glVertex2i(-150, -100);
    glVertex2i(-180, -70);
    glEnd();
    glBegin(GL_POLYGON);//middle part
    glVertex2i(-150, -100);
    glVertex2i(-150, -120);
    glVertex2i(-120, -125);
    glVertex2i(-90, -120);
    glVertex2i(-85, -100);
    glVertex2i(-150, -100);
    glEnd();
    glBegin(GL_POLYGON);//right part
    glVertex2i(-85, -100);
    glVertex2i(-90, -120);
    glVertex2i(-75, -105);
    glVertex2i(-60, -70);
    glVertex2i(-85, -100);
    glEnd();
    //--------------BOAT FLAG------------------
    glBegin(GL_POLYGON);
    glColor3ub(255, 64, 0);//flag right uporer part
    glVertex2i(-57, -40);
    glVertex2i(-50, -10);
    glVertex2i(-49, 10);
    glVertex2i(-50, 30);
    glVertex2i(-55, 45);
    glVertex2i(-63, 57);
    glVertex2i(-73, 68); // end
    glVertex2i(-105, 45);
    glVertex2i(-50, -10);
    glEnd();

    glBegin(GL_POLYGON);//flag right extended uppefr part
    glColor3ub(255, 255, 255);
    glVertex2i(-68, -70);
    glVertex2i(-57, -40);
    glVertex2i(-85, 10);
    glVertex2i(-68, -70);
    glEnd();

    glBegin(GL_POLYGON);//boat flag
    glColor3ub(0, 128, 255);
    glVertex2i(-85, -100);
    glVertex2i(-68, -70);
    glVertex2i(-80, -10);
    glVertex2i(-85, -100);
    glEnd();

    glColor3ub(0, 0, 0);
    glRecti(-88, 80, -86, -100);  // Boat stand
    glBegin(GL_POLYGON);//boat r chawni r right part
    glColor3ub(150, 75, 0);//wood color
    glVertex2i(-85, -100);
    glVertex2i(-87, -80);
    glVertex2i(-93, -62);
    glVertex2i(-97, -55);
    glVertex2i(-105, -50);
    glVertex2i(-120, -48);
    glVertex2i(-120, -100);
    glVertex2i(-85, -100);

    glEnd();
    glBegin(GL_POLYGON);//boat r chawni r left part
    glColor3ub(150, 75, 0);//wood color
    glVertex2i(-150, -100);
    glVertex2i(-148, -80);
    glVertex2i(-142, -62);
    glVertex2i(-138, -55);
    glVertex2i(-130, -50);
    glVertex2i(-115, -48);
    glVertex2i(-115, -100);
    glVertex2i(-150, -100);


    glEnd();
    //--------------BOAT LINE------------------
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-142, -62);
    glVertex2i(-73, 68);
    glVertex2i(-73, 63);

    glVertex2i(-142, -62);
    glVertex2i(-105, 45);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-148, -80);
    glVertex2i(-87, -80);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-142, -62);
    glVertex2i(-93, -62);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-115, -48);
    glVertex2i(-115, -100);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-130, -50);
    glVertex2i(-130, -100);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glVertex2i(-100, -52);
    glVertex2i(-100, -100);
    glEnd();

    glPopMatrix();
    boatx += .03;
    if (boatx > 270)
        boatx = -180;

    //-------------ANIMATE ALL-------------
    glutPostRedisplay();


    /*--------*/
    glFlush();
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Village Scenery Simulation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
