//Marselino Situmorang 672019322
//Yusup Yuliadi 672019317

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

//#include <math.h>

//const double PI = 3.142857143;

//int a, radius, jumlah_titik, b_tengah, c_tengah, d_tengah;

void init (void);
void tampil (void);
void mouse (int button, int state, int x, int y);
void keyboard (unsigned char, int, int);
void ukuran (int,int);
void mouseMotion (int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int is_depth;

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Bangkok University");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.7,0.7,1.0,0.0);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

     glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    //pondasi1

    glBegin(GL_QUADS);
    glColor3f(0.4,1.0,0.4);
    glVertex3f(-80.0,-80.0,70.0);
    glVertex3f(80.0,-80.0,70.0);
    glVertex3f(80.0,-80.0,-180.0);
    glVertex3f(-80.0,-80.0,-180.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(5.0f);
    glVertex3f(-80.0,-79.9,70.0);
    glVertex3f(80.0,-79.9,70.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(5.0f);
    glVertex3f(80.0,-79.9,70.0);
    glVertex3f(80.0,-79.9,-180.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(5.0f);
    glVertex3f(80.0,-79.9,-180.0);
    glVertex3f(-80.0,-79.9,-180.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.0f);
    glVertex3f(-80.0,-79.9,70.0);
    glVertex3f(-80.0,-79.9,-180.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(30.0f);
    glVertex3f(60.0,-79.5,60.9);
    glVertex3f(-60.0,-79.5,60.9);
    glEnd();

    //aspal
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-120.0,-83.0,100.0);
    glVertex3f(120.0,-83.0,100.0);
    glVertex3f(120.0,-83.0,-220.0);
    glVertex3f(-120.0,-83.0,-220.0);
    glEnd();
    //kolam renang depan
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(60.0,-79.9, 60.0);
    glVertex3f(-60.0,-79.9, 60.0);
    glVertex3f(0.0,-79.9, 20.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(30.0f);
    glVertex3f(60.0,-79.5,60.9);
    glVertex3f(-60.0,-79.5,60.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(30.0f);
    glVertex3f(60.0,-79.5,60.9);
    glVertex3f(0.0,-79.5,20.9);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(30.0f);
    glVertex3f(0.0,-79.5,20.9);
    glVertex3f(-60.0,-79.5,60.9);
    glEnd();

    //jalan kiri kekanan
     glBegin(GL_QUADS);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(-80.0,-79.9,68.0);
    glVertex3f(80.0,-79.9,-40.0);
    glVertex3f(80.0,-79.9,-50.0);
    glVertex3f(-80.0,-79.9,60.0);
    glEnd();


    //jalan kanan kekiri
   glBegin(GL_QUADS);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(-80.0,-79.9,-50.0);
    glVertex3f(80.0,-79.9,60.0);
    glVertex3f(80.0,-79.9,68.0);
    glVertex3f(-80.0,-79.9,-40.0);
    glEnd();
    //jalandepangedung
    glBegin(GL_QUADS);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(-80.0,-79.9,-38.0);
    glVertex3f(80.0,-79.9,-38.0);
    glVertex3f(80.0,-79.9,-43.0);
    glVertex3f(-80.0,-79.9,-43.0);
    glEnd();

    //gedung belakang
    glBegin(GL_QUADS);//lantai gedung
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-70.0,-79.0,-50.0);
    glVertex3f(70.0,-79.0,-50.0);
    glVertex3f(70.0,-79.0,-170.0);
    glVertex3f(-70.0,-79.0,-170.0);
    glEnd();
    //tembok kanan
    glBegin(GL_QUADS);
    glColor3f(0.0,0.4,0.4);
    glVertex3f(70.0,40.0,-50.0);
    glVertex3f(70.0,-79.0,-50.0);
    glVertex3f(70.0,-79.0,-170.0);
    glVertex3f(70.0,40.0,-170.0);
    glEnd();
    glBegin(GL_QUADS);//jendela1
    glColor3f(0.5,1.0,1.0);
    glVertex3f(70.1,-45.0,-60.0);
    glVertex3f(70.1,-70.0,-60.0);
    glVertex3f(70.1,-70.0,-160.0);
    glVertex3f(70.1,-45.0,-160.0);
    glEnd();
    glBegin(GL_QUADS); //jendela2
    glColor3f(0.5,1.0,1.0);
    glVertex3f(70.1,-25.0,-60.0);
    glVertex3f(70.1,-40.0,-60.0);
    glVertex3f(70.1,-40.0,-160.0);
    glVertex3f(70.1,-25.0,-160.0);
    glEnd();
    glBegin(GL_QUADS); //jendela3
    glColor3f(0.5,1.0,1.0);
    glVertex3f(70.1,-5.0,-60.0);
    glVertex3f(70.1,-20.0,-60.0);
    glVertex3f(70.1,-20.0,-160.0);
    glVertex3f(70.1,-5.0,-160.0);
    glEnd();
    glBegin(GL_QUADS);//jendela4
    glColor3f(0.5,1.0,1.0);
    glVertex3f(70.1,15.0,-60.0);
    glVertex3f(70.1,0.0,-60.0);
    glVertex3f(70.1,0.0,-160.0);
    glVertex3f(70.1,15.0,-160.0);
    glEnd();
    glBegin(GL_QUADS);//jendela5
    glColor3f(0.5,1.0,1.0);
    glVertex3f(70.1,35.0,-60.0);
    glVertex3f(70.1,20.0,-60.0);
    glVertex3f(70.1,20.0,-160.0);
    glVertex3f(70.1,35.0,-160.0);
    glEnd();
    //tembok kiri
    glBegin(GL_QUADS);
    glColor3f(0.0,0.4,0.4);
    glVertex3f(-70.0,40.0,-50.0);
    glVertex3f(-70.0,-79.0,-50.0);
    glVertex3f(-70.0,-79.0,-170.0);
    glVertex3f(-70.0,40.0,-170.0);
    glEnd();
    glBegin(GL_QUADS);//jendela0
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-70.1,-45.0,-60.0);
    glVertex3f(-70.1,-70.0,-60.0);
    glVertex3f(-70.1,-70.0,-160.0);
    glVertex3f(-70.1,-45.0,-160.0);
    glEnd();
    glBegin(GL_QUADS);//jendela1
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-70.1,-25.0,-60.0);
    glVertex3f(-70.1,-40.0,-60.0);
    glVertex3f(-70.1,-40.0,-160.0);
    glVertex3f(-70.1,-25.0,-160.0);
    glEnd();
    glBegin(GL_QUADS);//jendela2
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-70.1,-5.0,-60.0);
    glVertex3f(-70.1,-20.0,-60.0);
    glVertex3f(-70.1,-20.0,-160.0);
    glVertex3f(-70.1,-5.0,-160.0);
    glEnd();
    glBegin(GL_QUADS);//jendela3
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-70.1,15.0,-60.0);
    glVertex3f(-70.1,-0.0,-60.0);
    glVertex3f(-70.1,-0.0,-160.0);
    glVertex3f(-70.1,15.0,-160.0);
    glEnd();
    glBegin(GL_QUADS);//jendela4
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-70.1,35.0,-60.0);
    glVertex3f(-70.1,20.0,-60.0);
    glVertex3f(-70.1,20.0,-160.0);
    glVertex3f(-70.1,35.0,-160.0);
    glEnd();
    //tembok depan
    glBegin(GL_QUADS);
    glColor3f(0.0,0.4,0.4);
    glVertex3f(-70.0,40.0,-50.0);
    glVertex3f(-70.0,-79.0,-50.0);
    glVertex3f(70.0,-79.0,-50.0);
    glVertex3f(70.0,40.0,-50.0);
    glEnd();
    glBegin(GL_QUADS);//pintu
    glColor3f(1.0,1.5,0.5);
    glVertex3f(-15.0,-45.9,-49.5);
    glVertex3f(-15.0,-79.9,-49.5);
    glVertex3f(15.0,-79.9,-49.5);
    glVertex3f(15.0,-45.9,-49.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(0.0,-79.1,-49.9);
    glVertex3f(0.0,-45.1,-49.9);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    glPointSize(10000.0);
    glVertex3f(5.0,-50.0,48.0);
    glEnd();
    glBegin(GL_QUADS);//jendela
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-60.0,-25.0,-49.9);
    glVertex3f(-60.0,-40.0,-49.9);
    glVertex3f(60.0,-40.0,-49.9);
    glVertex3f(60.0,-25.0,-49.9);
    glEnd();
    glBegin(GL_QUADS);//jendela
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-60.0,-5.0,-49.9);
    glVertex3f(-60.0,-20.0,-49.9);
    glVertex3f(60.0,-20.0,-49.9);
    glVertex3f(60.0,-5.0,-49.9);
    glEnd();
    glBegin(GL_QUADS);//jendela
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-60.0,15.0,-49.9);
    glVertex3f(-60.0,0.0,-49.9);
    glVertex3f(60.0,0.0,-49.9);
    glVertex3f(60.0,15.0,-49.9);
    glEnd();
    glBegin(GL_QUADS);//jendela
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-60.0,35.0,-49.9);
    glVertex3f(-60.0,20.0,-49.9);
    glVertex3f(60.0,20.0,-49.9);
    glVertex3f(60.0,35.0,-49.9);
    glEnd();
    //tembok belakang
    glBegin(GL_QUADS);
    glColor3f(0.0,0.5,0.5);
    glVertex3f(-70.0,40.0,-170.0);
    glVertex3f(-70.0,-79.0,-170.0);
    glVertex3f(70.0,-79.0,-170.0);
    glVertex3f(70.0,40.0,-170.0);
    glEnd();
    glBegin(GL_QUADS);//pintu
    glColor3f(1.0,1.5,0.5);
    glVertex3f(-15.0,-45.0,-170.1);
    glVertex3f(-15.0,-79.0,-170.1);
    glVertex3f(15.0,-79.0,-170.1);
    glVertex3f(15.0,-45.0,-170.1);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(0.0,-79.9,-170.0);
    glVertex3f(0.0,-45.9,-170.0);
    glEnd();
    glBegin(GL_QUADS);//jendela1
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-60.0,-25.0,-170.1);
    glVertex3f(-60.0,-40.0,-170.1);
    glVertex3f(60.0,-40.0,-170.1);
    glVertex3f(60.0,-25.0,-170.1);
    glEnd();
    glBegin(GL_QUADS);//jendela2
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-60.0,-5.0,-170.1);
    glVertex3f(-60.0,-20.0,-170.1);
    glVertex3f(60.0,-20.0,-170.1);
    glVertex3f(60.0,-5.0,-170.1);
    glEnd();
    glBegin(GL_QUADS);//jendela3
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-60.0,15.0,-170.1);
    glVertex3f(-60.0,-0.0,-170.1);
    glVertex3f(60.0,-0.0,-170.1);
    glVertex3f(60.0,15.0,-170.1);
    glEnd();
    glBegin(GL_QUADS);//jendela 4
    glColor3f(0.5,1.0,1.0);
    glVertex3f(-60.0,35.0,-170.1);
    glVertex3f(-60.0,20.0,-170.1);
    glVertex3f(60.0,20.0,-170.1);
    glVertex3f(60.0,35.0,-170.1);
    glEnd();
    //atap atas
    glBegin(GL_QUADS);
    glColor3f(0.2,0.4,0.4);
    glVertex3f(-70.0,38.0,-50.0);
    glVertex3f(70.0,38.0,-50.0);
    glVertex3f(70.0,38.0,-170.0);
    glVertex3f(-70.0,38.0,-170.0);
    glEnd();
    //Landasan
    glBegin(GL_QUADS);
    glColor3f(0.2,0.4,0.2);
    glVertex3f(-40.0,38.1,-70.0);
    glVertex3f(40.0,38.1,-70.0);
    glVertex3f(40.0,38.1,-150.0);
    glVertex3f(-40.0,38.1,-150.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.9,0.9,0.9);
    glLineWidth(3.0f);
    glVertex3f(-30.0,38.2,-80.0);
    glVertex3f(30.0,38.2,-80.0);
    glVertex3f(30.0,38.2,-140.0);
    glVertex3f(-30.0,38.2,-140.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(-16.0,38.3,-90.0);
    glVertex3f(-16.0,38.3,-130.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(16.0,38.3,-90.0);
    glVertex3f(16.0,38.3,-130.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(16.0,38.3,-110.0);
    glVertex3f(-16.0,38.3,-110.0);
    glEnd();


    //INTERIOR DALAM GEDUNG
    glBegin(GL_POLYGON);//lantai gedung
    glColor3f(0.0,1.0,0.7);
    glVertex3f(-60.0,-75.0,-80.0);
    glVertex3f(60.0,-75.0,-80.0);
    glVertex3f(60.0,-75.0,-140.0);
    glVertex3f(-60.0,-75.0,-140.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(0.0,-74.9,-80.0);
    glVertex3f(0.0,-74.9,-140.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(-60.0,-74.9,-80.0);
    glVertex3f(-60.0,-74.9,-140.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(60.0,-74.9,-80.0);
    glVertex3f(60.0,-74.9,-140.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(-60.0,-74.9,-140.0);
    glVertex3f(60.0,-74.9,-140.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(60.0,-74.9,-80.0);
    glVertex3f(-60.0,-74.9,-80.0);
    glEnd();
    glBegin(GL_LINES);//gawang kanan
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(60.0,-74.9,-100.0);
    glVertex3f(60.0,-55,-100.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(60.0,-74.9,-120.0);
    glVertex3f(60.0,-55,-120.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(60.0,-55,-100.0);
    glVertex3f(60.0,-55,-120.0);
    glEnd();
    glBegin(GL_LINES);//gawang kiri
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(-60.0,-74.9,-100.0);
    glVertex3f(-60.0,-55,-100.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(-60.0,-74.9,-120.0);
    glVertex3f(-60.0,-55,-120.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0f);
    glVertex3f(-60.0,-55,-100.0);
    glVertex3f(-60.0,-55,-120.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-40.0,-45.0,-160.0);
    glVertex3f(-15.0,-45.0,-160.0);
    glVertex3f(-15.0,-75.0,-160.0);
    glVertex3f(-40.0,-75.0,-160.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(40.0,-45.0,-160.0);
    glVertex3f(15.0,-45.0,-160.0);
    glVertex3f(15.0,-75.0,-160.0);
    glVertex3f(40.0,-75.0,-160.0);
    glEnd();


    //gedung kiri
    //lantai gedung
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-68.0,-79.9,-0.0);
    glVertex3f(-70.0,-79.9,15.0);
    glVertex3f(-65.0,-79.9,35.0);
    glVertex3f(-40.0,-79.9,35.0);
    glVertex3f(-30.0,-79.9,10.0);
    glVertex3f(-50.0,-79.9,-10.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding1
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-65.0, -79.9, 35.0);
    glVertex3f(-80.0, -60.0, 35.0+10);
    glVertex3f(-40.0,-50.0,35.0);
    glVertex3f(-40.0, -79.9, 35.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding2
    glColor3f(0.4,0.4,0.4);
    glVertex3f(-40.0, -79.9, 35.0);
    glVertex3f(-40.0,-50.0,35.0);
    glVertex3f(-30.0+5, -40.0, 10.0+-5);
    glVertex3f(-30.0, -79.9, 10.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding3
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-30.0, -79.9,10.0);
    glVertex3f(-30.0+5, -40.0,10.0+-5);
    glVertex3f(-50.0+5,-40.0, -10.0+-5);
    glVertex3f(-50.0, -79.9,-10.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding4
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-50.0, -79.9,-10.0);
    glVertex3f(-50.0+5, -40.0,-10.0+-5);
    glVertex3f(-68.0,-40.0,-0.0);
    glVertex3f(-68.0, -79.9,-0.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding5
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-68.0, -79.9,-0.0);
    glVertex3f(-68.0, -40.0,-0.0);
    glVertex3f(-80.0,-60.0,35.0+10);
    glVertex3f(-70.0, -79.9,15.0);
    glEnd();
    glBegin(GL_TRIANGLES);//dinding6
    glColor3f(0.3,0.3,0.3);
    glVertex3f(-70.0, -79.9,15.0);
    glVertex3f(-65.0,-79.9,35.0);
    glVertex3f(-80.0,-60.0,35.0+10);
    glEnd();
    //Atap
    glBegin(GL_TRIANGLES);//atap1
    glColor3f(0.9,0.9,0.9);
    glVertex3f(-80.0,-60.0,35.0+10);
    glVertex3f(-40.0,-50.0,35.0);
    glVertex3f(-45.0,-30.0,30.0+-10);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.5,0.5);
    glLineWidth(5.0f);
    glVertex3f(-70.0,-54.0,42.0);
    glVertex3f(-45.0,-40.9,30.0);
    glEnd();
    glBegin(GL_TRIANGLES);//atap2
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-40.0,-50.0,35.0);
    glVertex3f(-30.0+5, -40.0, 10.0+-5);
    glVertex3f(-45.0,-30.0,30.0+-10);
    glEnd();
    glBegin(GL_TRIANGLES);//atap3
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-30.0+5, -40.0, 10.0+-5);
    glVertex3f(-50.0+5, -40.0,-10.0+-5);
    glVertex3f(-45.0,-30.0,30.0+-10);
    glEnd();
    glBegin(GL_TRIANGLES);//atap4
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-50.0+5, -40.0,-10.0+-5);
    glVertex3f(-68.0, -40.0,-0.0);
    glVertex3f(-45.0,-30.0,30.0+-10);
    glEnd();
    glBegin(GL_TRIANGLES);//atap5
    glColor3f(0.8,0.8,0.8);
    glVertex3f(-68.0, -40.0,-0.0);
    glVertex3f(-80.0,-60.0,35.0+10);
    glVertex3f(-45.0,-30.0,30.0+-10);
    glEnd();

    //gedung kanan

    glBegin(GL_POLYGON);//lantai gedung
    glColor3f(0.0,0.0,0.0);
    glVertex3f(50.0,-79.9,-10.0);
    glVertex3f(60.0,-79.9,15.0);
    glVertex3f(55.0,-79.9,30.0);
    glVertex3f(26.0,-79.9,15.0);
    glVertex3f(28.0,-79.9,-5.0);
    glEnd();
    glBegin(GL_TRIANGLES);//dinding1
    glColor3f(0.5,0.5,0.5);
    glVertex3f(26.0,-79.9,15.0);
    glVertex3f(55.0,-79.9,30.0);
    glVertex3f(18.0,-15.0,18.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding2
    glColor3f(0.6,0.6,0.6);
    glVertex3f(55.0,-79.9,30.0);
    glVertex3f(55.0,-30,30.0);
    glVertex3f(65.0,-35.0,15.0);
    glVertex3f(60.0,-79.9,15.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding3
    glColor3f(0.7,0.7,0.7);
    glVertex3f(60.0,-79.9,15.0);
    glVertex3f(65.0,-35,15.0);
    glVertex3f(50.0,-40.0,-10.0+-5);
    glVertex3f(50.0,-79.9,-10.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding4
    glColor3f(0.8,0.8,0.8);
    glVertex3f(50.0,-79.9,-10.0);
    glVertex3f(50.0,-40,-10.0+-5);
    glVertex3f(28.0,-28.0,-5.0);
    glVertex3f(28.0,-79.9,-5.0);
    glEnd();
    glBegin(GL_POLYGON);//dinding5
    glColor3f(0.6,0.6,0.6);
    glVertex3f(28.0,-79.9,-5.0);
    glVertex3f(28.0,-28,-5.0);
    glVertex3f(18.0,-15.0,18.0);
    glVertex3f(26.0,-79.9,15.0);
    glEnd();
    glBegin(GL_TRIANGLES);//dinding6
    glColor3f(0.6,0.6,0.6);
    glVertex3f(55.0,-79.9,30.0);
    glVertex3f(55.0,-30,30.0);
    glVertex3f(18.0,-15.0,18.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.5,0.5);
    glLineWidth(5.0f);
    glVertex3f(35.0,-30.9,24.0);
    glVertex3f(55.0,-40.9,30.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.5,0.5);
    glLineWidth(5.0f);
    glVertex3f(40.0,-43.9,26.0);
    glVertex3f(55.0,-50.9,30.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.5,0.5);
    glLineWidth(5.0f);
    glVertex3f(45.0,-55.9,28.0);
    glVertex3f(55.0,-60.9,30.0);
    glEnd();
    //ATAP
    glBegin(GL_TRIANGLES);//atap1
    glColor3f(0.7,0.7,0.7);
    glVertex3f(55.0,-30,30.0);
    glVertex3f(65.0,-35.0,15.0);
    glVertex3f(18.0,-15.0,18.0);
    glEnd();
    glBegin(GL_TRIANGLES);//atap2
    glColor3f(0.9,0.9,0.9);
    glVertex3f(65.0,-35.0,15.0);
    glVertex3f(50.0,-40.0,-10.0+-5);
    glVertex3f(18.0,-15.0,18.0);
    glEnd();
    glBegin(GL_TRIANGLES);//atap3
    glColor3f(0.8,0.8,0.8);
    glVertex3f(50.0,-40.0,-10.0+-5);
    glVertex3f(28.0,-28,-5.0);
    glVertex3f(18.0,-15.0,18.0);
    glEnd();


    glPushMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouse (int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mouseDown = true;
            xdiff = x - yrot;
            ydiff = -y + xrot;
        }
    else{
        mouseDown = false;
    }
    glutPostRedisplay();
}

void idle ()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0,0.0,3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0,0.0,0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0,0.0,-3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0,0.0,0.0);
        break;
    case '7':
        glTranslatef(0.0,3.0,0.0);
        break;
    case '9':
        glTranslatef(0.0,-3.0,0.0);
        break;
    case '2':
        glRotatef(2.0,1.0,0.0,0.0);
        break;
    case '8':
        glRotatef(-2.0,1.0,0.0,0.0);
        break;
    case '6':
        glRotatef(2.0,0.0,1.0,0.0);
        break;
    case '4':
        glRotatef(-2.0,0.0,1.0,0.0);
        break;
    case '1':
        glRotatef(2.0,0.0,0.0,1.0);
        break;
    case '3':
        glRotatef(-2.0,0.0,0.0,1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, lebar / tinggi, 5.0, 800.0);
    glTranslatef(0.0, -5.0, -280.0);
    glMatrixMode(GL_MODELVIEW);
}
