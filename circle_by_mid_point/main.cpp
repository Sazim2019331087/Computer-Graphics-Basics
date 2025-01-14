#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>

float x=0,y,p,r;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glEnd();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POINTS);
  p = 1-r;
  while((x<=y))
  {
    if(p<0)
    {
      x = x+1;
      y = y;
      printf("%.2f , %.2f\n",x,y);
      p = p+(2*x)+1;
    }
    else
    {
      x = x+1;
      y = y-1;
      printf("%.2f , %.2f\n",x,y);
      p = p+(2*x)+1-(2*y);
    }
    glVertex3f((x/100),(y/100),0.0);
    glVertex3f((-x/100),(y/100),0.0);
    glVertex3f((x/100),(-y/100),0.0);
    glVertex3f((-x/100),(-y/100),0.0);

    glVertex3f((y/100),(x/100),0.0);
    glVertex3f((-y/100),(x/100),0.0);
    glVertex3f((y/100),(-x/100),0.0);
    glVertex3f((-y/100),(-x/100),0.0);

  }
  glEnd();
  glFlush();
}

void init()
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}

int main(int argc,char** argv)
{
  printf("Mid Point Method Circle Drawing\n");
  printf("Radius:");
  scanf("%f",&r);
  y=r;
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Circle");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
