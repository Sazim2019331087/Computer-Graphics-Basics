#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
float x1,x2,y1,y2,i,j,p,dx,dy;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);

    p = (2*dy) - dx;
    for(i=x1,j=y1; i<x2,j<y2;)
    {
        if(p>=0)
        {
            i = i+1;
            j = j+1;
            if(i>x2 || j>y2)
            {
                break;
            }
            printf("%.2f , %.2f\n",i,j);
            glVertex3f((i/100),(j/100),0.0);
            p = p+(2*dy) - (2*dx);
        }
        else
        {
            i = i+1;
            if(i>x2 || j>y2)
            {
                break;
            }
            printf("%.2f , %.2f\n",i,j);
            glVertex3f((i/100),(j/100),0.0);
            p = p+(2*dy);
        }
    }
    glEnd();
    glFlush();
}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GLUT_SINGLE | GLUT_RGB);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}
int main(int argc,char** argv)
{
    printf("Bresenham Line Drawing Algorithm\n");
    printf("x1,y1?");
    scanf("%f %f",&x1,&y1);
    printf("x2,y2?");
    scanf("%f %f",&x2,&y2);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Bresenham Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
