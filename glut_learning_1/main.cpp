#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#include<GL/gl.h>
using namespace std;

float tx=0.0f,ty=0.0f;
int movement = 0;
int rotation = 0;
float angle = 0.0f;
float speed = 0.005f;
void format(int x,int y,float &objX,float &objY)
{
    objX = (x-250.0f)/250.0f;
    objY = -(y-250.0f)/250.0f;
}

void update(int value)
{
    if(movement==2)
    {
        ty-=speed;
    }
    if(movement==-2)
    {
        ty+=speed;
    }
    if(movement==-1)
    {
        tx-=speed;
    }
    if(movement==1)
    {
        tx+=speed;
    }

    if(rotation==-1)
    {
        angle-=1.0f;
    }
    if(rotation==1)
    {
        angle+=1.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(15,update,0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(tx,ty,0.0f);
    glRotatef(angle,0.0f,0.0f,1.0f);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2d(0.05f,0.05f);
    glVertex2d(-0.05f,-0.05f);
    glVertex2d(0.05f,-0.05f);
    glVertex2d(-0.05f,0.05f);
    //glVertex2d(0.1f,0.1f);
    glEnd();
    glPopMatrix();
    glFlush();
}

void myMouse(int button, int state, int x,int y)
{
    if(state==GLUT_DOWN)
    {
        if(button==GLUT_LEFT_BUTTON)
        {
            cout<<"left button pressed at ("<<x<<","<<y<<")\n";
            //format(x,y,tx,ty);
            movement = -1;
        }
        if(button==GLUT_RIGHT_BUTTON)
        {
            cout<<"right button pressed at ("<<x<<","<<y<<")\n";
            //format(x,y,tx,ty);
            movement = 1;
        }
    }

    glutPostRedisplay();
}

void myKeyBoard(unsigned char key,int x,int y)
{
    cout<<key<<" -> pressed at ("<<x<<","<<y<<")\n";
    if(key=='q'||key=='Q')
    {
        movement=0;
        rotation = 0;
    }
    if(key=='c'||key=='C')
    {
        rotation = -1;
    }
    if(key=='v'||key=='V')
    {
        rotation = 1;
    }


}

void mySpecialKeys(int key,int x,int y)
{
    if(key==GLUT_KEY_RIGHT)
    {
        cout<<"right key pressed at ("<<x<<","<<y<<")\n";
        movement = 1;
    }
    if(key==GLUT_KEY_LEFT)
    {
        cout<<"left key pressed at ("<<x<<","<<y<<")\n";
        movement = -1;
    }
    if(key==GLUT_KEY_UP)
    {
        cout<<"up key pressed at ("<<x<<","<<y<<")\n";
        movement = -2;
    }
    if(key==GLUT_KEY_DOWN)
    {
        cout<<"down key pressed at ("<<x<<","<<y<<")\n";
        movement = 2;
    }
}


void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(5,5);
    glutInitWindowSize(500,500);
    glutCreateWindow("COMPUTER GRAPHICS");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKeyBoard);
    glutSpecialFunc(mySpecialKeys);

    glutTimerFunc(0,update,0);
    glutMainLoop();
}
