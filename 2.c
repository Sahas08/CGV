#include<stdio.h>
#include<GL/glut.h>
int n;
typedef GLfloat point2[2];
point2 v[3]= {{-2,-1}, {2,-1},{0,1}};
void triangle( GLfloat *a, GLfloat *b, GLfloat *c)
{
      glVertex2fv(a); 
      glVertex2fv(b);  
      glVertex2fv(c);

}
void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{
    point2 v0, v1, v2;
    int j;
if(m>0)
     {
        for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
        for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
        for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
   divide_triangle(a, v0, v1, m-1);
   divide_triangle(c, v1, v2, m-1);
   divide_triangle(b, v2, v0, m-1);
    }
  else(triangle(a,b,c));
 /* draw triangle at end of recursion */
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    divide_triangle(v[0], v[1], v[2], n);
    glEnd();
    glFlush();
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor (1.0, 1.0, 1.0,1.0);
    glColor3f(1.0,0.0,0.0);
}
int main(int argc, char **argv)
{
   printf("Enter the number of divisions\n");
	 scanf("%d",&n);
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutCreateWindow("2D Gasket");
   glutDisplayFunc(display);
	 myinit();
   glutMainLoop();
return 0;
   }  
