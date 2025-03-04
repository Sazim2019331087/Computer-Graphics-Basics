#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
using namespace std;

float x1,x2,y1,y2,m,i,j,dx,dy;

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POINTS);

    if(m>0 && m<=1)
    {
        while(x1<=x2 && y1<=y2)
        {
            x1 = x1+1;
            y1 = y1+m;
            glVertex3f(x1/100,y1/100,0.0);
            printf("%f , %f",x1,y1);
        }
    }
    else if(m>1)
    {
        while(x1<=x2 && y1<=y2)
        {
            x1 = x1+(1/m);
            y1 = y1+1;
            glVertex3f(x1/100,y1/100,0.0);
            printf("%f , %f",x1,y1);
        }

    }
    else if(m>=-1 && m<0)
    {
        while(x1>=x2 && y1>=y2)
        {
            x1 = x1-1;
            y1 = y1-m;
            glVertex3f(x1/100,y1/100,0.0);
            printf("%f , %f",x1,y1);
        }
    }
    else
    {
        while(x1>=x2 && y1>=y2)
        {
            x1 = x1-(1/m);
            y1 = y1-1;
            glVertex3f(x1/100,y1/100,0.0);
            printf("%f , %f",x1,y1);
        }
    }

    glEnd();
    glFlush();
}

void Init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.,1.0,-1.0,1.0,-1.0,1.0);
}

int main(int argc,char** argv)
{
    printf("DDA Algorithm\n");
    printf("x1 y1?");
    scanf("%f %f",&x1,&y1);

    printf("x2 y2?");
    scanf("%f %f",&x2,&y2);

    dx = x2-x1;
    dy = y2-y1;

    m = dy/dx;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;


}
