#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

GLfloat yRotationAngle=0.7,xRotationAngle=0.4,zRotationAngle=0.3;
GLfloat xl=-0.7,xloc=0,yloc=-0.8,zloc=-0.1;
GLfloat xb1=0,yb1=0,zb1=0;
GLfloat xb2=0,yb2=0,zb2=0;
GLint val;
//printing text
void print(float x, float y,float z, char *st)
{
	int l,i;

	l=strlen( st ); // see how many characters are in text string.
  //glColor3f(1,0,0);
	glRasterPos3f( x, y,z); // location to start printing text
	for( i=0; i < l; i++)  // loop until i is greater then l
		{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]); // Print a character on the screen
	}
}


void pitch()
{

  glBegin(GL_POLYGON);
  glColor3f(0,0,1);
  glVertex3f(-0.85,-0.6,0);
  glVertex3f(0.85,-0.6,0);
  glVertex3f(0.35,0.7,0);
  glVertex3f(-0.35,0.7,0);

  glEnd();
}

void wickets()
{
  glLineWidth(2.0);
  glColor3f(1,1,1);
  //wickets
  glBegin(GL_LINES);
  glVertex3f(0.04,0.7,0);
  glVertex3f(0.04,0.83,0);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(0,0.7,0);
  glVertex3f(0,0.83,0);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(-0.04,0.7,0);
  glVertex3f(-0.04,0.83,0);
  glEnd();
  //crease
  //glTranslatef(0,0,0);
  glBegin(GL_LINES);
  glVertex3f(0.4,0.6,-0.1);
  glVertex3f(-0.4,0.6,-0.1);
  glEnd();
  //wides
  glBegin(GL_LINES);
  glVertex3f(0.29,0.7,-0.1);
  glVertex3f(0.33,0.6,-0.1);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(-0.29,0.7,-0.1);
  glVertex3f(-0.33,0.6,-0.1);
  glEnd();
  //bails
	glPushMatrix();
	glTranslatef(xb1,yb1,zb1);
  glBegin(GL_LINES);
  glVertex3f(0.04,0.83,0);
	glVertex3f(0.005,0.83,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xb2,yb2,zb2);
	glBegin(GL_LINES);
	glVertex3f(-0.005,0.83,0);
  glVertex3f(-0.04,0.83,0);
  glEnd();
	glPopMatrix();

}

void wickets2()
{
  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex3f(0,-0.6,-0.1);
  glVertex3f(0,-0.35,-0.1);
  glVertex3f(0.02,-0.35,-0.1);
  glVertex3f(0.02,-0.6,-0.1);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(0.06,-0.6,-0.1);
  glVertex3f(0.06,-0.35,-0.1);
  glVertex3f(0.08,-0.35,-0.1);
  glVertex3f(0.08,-0.6,-0.1);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(-0.06,-0.6,-0.1);
  glVertex3f(-0.06,-0.35,-0.1);
  glVertex3f(-0.04,-0.35,-0.1);
  glVertex3f(-0.04,-0.6,-0.1);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(-0.06,-0.35,-0.1);
  glVertex3f(0.08,-0.35,-0.1);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(0.85,-0.33,-0.5);
  glVertex3f(-0.85,-0.33,-0.5);
  glVertex3f(-0.85,-0.315,-0.5);
  glVertex3f(0.85,-0.315,-0.5);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(0.85,-0.33,-0.5);
  glVertex3f(-0.85,-0.33,-0.5);
  glVertex3f(-0.85,-0.315,-0.5);
  glVertex3f(0.85,-0.315,-0.5);
  glEnd();


}

void sphere()
{
  //glTranslated(0,0,-1);
	glPushMatrix();
  glColor3f(1,0,0);
  //glutSolidSphere(0.05,20,20);
  //glRotatef(90,0,0,1);
  glTranslatef(xloc,yloc,zloc);
	glRotatef(xRotationAngle,1,0,0);
	glRotatef(yRotationAngle,0,1,0);
	glRotatef(zRotationAngle,0,0,1);
  //glColor3f(1,0,0);
  glutSolidSphere(0.1,20,20);
	glRotatef(xRotationAngle,1,0,0);
	glRotatef(yRotationAngle,0,1,0);
	glRotatef(zRotationAngle,0,0,1);
	xRotationAngle+=1;
	yRotationAngle+=0.5;
	zRotationAngle+=0.5;
	glPopMatrix();

}

void menu(int id)
{
  switch(id)
  {
    case 1: yloc=-0.80,zloc=-1,xloc=-0.4;
						xb1=yb1=zb1=0;
						xb2=yb2=zb2=0;
            val=1;
            glColor3f(0,0,1);
            glBegin(GL_LINES);
              glVertex3f(-0.65,-0.95,-0.3);
              glVertex3f(-0.65,-0.85,-0.3);
            glEnd();
            break;
    case 2: yloc=-0.80,zloc=-1,xloc=0.4;
						xb1=yb1=zb1=0;
						xb2=yb2=zb2=0;
            val=2;
            glColor3f(0,0,1);
            glBegin(GL_LINES);
              glVertex3f(0.65,-0.95,-0.4);
              glVertex3f(0.65,-0.85,-0.4);
            glEnd();
            break;
    case 3: exit(0);
  }
  glutPostRedisplay();
}

void ballmach()
{
  glColor3f(0.9,0.9,0.9);
  glBegin(GL_POLYGON);
  glVertex3f(0.9,-1,0.3);
  glVertex3f(-0.9,-1,0.3);
  glVertex3f(-0.8,-0.8,0.3);
  glVertex3f(0.8,-0.8,0.3);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
    glVertex3f(-0.6,-0.95,-0.3);
    glVertex3f(-0.6,-0.85,-0.3);
  glEnd();

  glBegin(GL_LINES);
    glVertex3f(+0.6,-0.95,-0.3);
    glVertex3f(+0.6,-0.85,-0.3);
  glEnd();
}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  pitch();
  wickets();
  wickets2();
  ballmach();
  sphere();
  glFlush();
}

void display2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	print(-0.5,0.6,0,"SIMULATION OF BOWL MACHINE");
	print(-0.7,0.4,0,"AKHIL S NAIR");
	print(-0.7,0.3,0,"1BY14CS007");
	print(0.1,0.4,0,"CHANDRESH TIWARI");
	print(0.1,0.3,0,"1BY14CS024");
	print(-0.4,-0.1,0,"UNDER THE GUIDANCE OF");
	print(-0.8,-0.3,0,"MRS. AMBIKA GN");
	print(-0.8,-0.4,0,"ASSISTANT PROFESSOR");
	print(-0.8,-0.5,0,"DEPT OF CSE, BMSIT&M");
	print(0.1,-0.3,0,"DR. ANIL GN");
	print(0.1,-0.4,0,"ASSOCIATE PROFESSOR");
	print(0.1,-0.5,0,"DEPT OF CSE, BMSIT&M");
	print(-0.6,-0.7,0,"PRESS I FOR INSTRUCTIONS");

	glFlush();
}

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(-0.3,0.21,0);
	//glRotatef(xRotationAngle,1,0,0);
	//xRotationAngle+=0.5
	glutWireSphere(0.02,3,3);
	glPopMatrix();
	//sleep(3);
	print(-0.2,0.2,-0.2,"press x|X for ball to FLASHY outswing");
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-0.3,0.21,0);
	glutWireSphere(0.02,3,3);
	glPopMatrix();
	//sleep(3);
	print(-0.3,0.1,-0.3,"press y|Y for ball to BANANA inswing ");
	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(-0.4,0.11,0);
	glutWireSphere(0.02,3,3);
	glPopMatrix();
	//sleep(3);
	//print(-0.4,0,-0.4,"press z|Z for TOE-CRUSHER yorker");
	glColor3f(1,0,0);
	glPushMatrix();
	//glTranslatef(-0.5,0.01,0);
	//glutWireSphere(0.02,3,3);
	glPopMatrix();
	//sleep(3);
	print(-0.4,-0.1,-0.4,"press b|B for JAW-BREAKING bouncer");
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-0.5,0.01,0);
	glutWireSphere(0.02,3,3);
	glPopMatrix();
	//sleep(3);
	print(-0.5,-0.2,-0.5,"press o | O for SNAKY offbreak");
	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(-0.6,-0.09,0);
	glutWireSphere(0.02,3,3);
	glPopMatrix();
	//sleep(3);
	print(-0.6,-0.3,-0.6,"press l | L for WARNY legbreak");
	glPushMatrix();
	glTranslatef(-0.7,-0.19,0);
	glutWireSphere(0.02,3,3);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(-0.8,-0.7,0);
		glRotatef(xRotationAngle,1,0,0);
		glRotatef(yRotationAngle,0,1,0);
		glRotatef(zRotationAngle,0,0,1);
		xRotationAngle+=1;
		yRotationAngle+=0.5;
		zRotationAngle+=0.5;
		int i=0;
		for(i=0;i<7;i+=2)
		{
				//glTranslatef(-0.8,-0.7,0);
				//glutWireSphere(0.1,5,5);
		}
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	glColor3f(1,0,0);
	glVertex3f(-0.8,0.8,0);
	glVertex3f(-0.8,0.5,0);
	glVertex3f(0.8,0.5,0);
	glVertex3f(0.8,0.8,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,1,0);
	glTranslatef(xl,0.65,0);
	glRotatef(xRotationAngle,1,0,0);
	glRotatef(yRotationAngle,0,1,0);
	glRotatef(zRotationAngle,0,0,1);
	xRotationAngle+=1;
	yRotationAngle+=0.5;
	zRotationAngle+=0.5;
	if(xl<0.70)
	{
		xl+=0.0005;
	}
	else
	{
		glutDisplayFunc(display);
		glutIdleFunc(display);
	}
	glutWireSphere(0.1,10,10);
	glPopMatrix();

	glFlush();
}

//mouse function
void keys(unsigned char key,int x,int y)
{
  display();
  //outswinger
  if(key == 'x' || key == 'X')
  {
    //round
    if(val==2)
    {
      if(zloc>-1.020)
      {
        zloc-=0.001;
        yloc+=0.043;
        xloc-=0.010;
      }
      else if(zloc<-1.020 && zloc>-1.070)
      {
        zloc-=0.020;
        yloc+=0.036;
        xloc-=0.005;
      }
      else
      {
        yloc+=0.028;
        zloc-=0.0005;
        xloc-=0.020;
      }
			//bails off
			if(xloc<0.04 && xloc>-0.04 && yloc>0.8)
			{
				xb1=-0.1;
				yb1=-0.1;
				zb1=0.1;
				xb2=0.1;
				yb2=-0.1;
				zb2=0.1;
			}
    }
    //over
    if(val==1)
    {
      if(zloc>-1.020)
      {
        zloc-=0.001;
        yloc+=0.048;
        xloc+=0.015;
      }
      else if(zloc<-1.020 && zloc>-1.070)
      {
        zloc-=0.020;
        yloc+=0.036;
        xloc+=0.015;
      }
      else
      {
        yloc+=0.028;
        zloc-=0.0005;
        xloc-=0.009;
      }
			//bails off
			if(xloc<0.04 && xloc>-0.04 && yloc>0.8)
			{
				xb1=-0.1;
				yb1=-0.1;
				zb1=0.1;
				xb2=0.1;
				yb2=-0.1;
				zb2=0.1;
			}
    }

    //yRotationAngle += 0.01f; // Increment our rotation value
  }

  //inswinger
  if(key == 'y' || key == 'Y')
  {
    if(val==2)
    {
      if(zloc>-1.020)
      {
        zloc-=0.001;
        yloc+=0.048;
        xloc-=0.018;
      }
      else if(zloc<-1.020 && zloc>-1.070)
      {
        zloc-=0.020;
        yloc+=0.036;
        xloc-=0.018;
      }
      else
      {
        yloc+=0.028;
        zloc-=0.0005;
        xloc+=0.008;
      }

			//bails off
			if(xloc<0.04 && xloc>-0.04 && yloc>0.8)
			{
				xb1=-0.1;
				yb1=-0.1;
				zb1=0.1;
				xb2=0.1;
				yb2=-0.1;
				zb2=0.1;
			}

    }

    if(val==1)
    {
      if(zloc>-1.020)
      {
        zloc-=0.001;
        yloc+=0.048;
        xloc+=0.004;
      }
      else if(zloc<-1.020 && zloc>-1.070)
      {
        zloc-=0.020;
        yloc+=0.036;
        xloc+=0.004;
      }
      else
      {
        yloc+=0.028;
        zloc-=0.0005;
        xloc+=0.012;
      }
			//bails off
			if(xloc<0.04 && xloc>-0.04 && yloc>0.8)
			{
				xb1=-0.1;
				yb1=-0.1;
				zb1=0.1;
				xb2=0.1;
				yb2=-0.1;
				zb2=0.1;
			}
    }

  }

//yorker
/*  if(key == 'z' || key == 'Z')
  {

    if(val==2)
    {
      if(zloc>-1.05)
      {
        zloc-=0.003;
        yloc+=0.080;
        xloc-=0.020;
      }
      else if(zloc<-1.05 && zloc>-1.09)
      {
        zloc-=0.012 ;
        yloc+=0.019;
        xloc-=0.002;
      }
      else
      {
        yloc+=0.030;
        zloc-=0.0005;
        xloc-=0.002;
      }
    }

    if(val==1)
    {
      if(zloc>-2.9)
      {
        zloc-=0.001;
        yloc+=0.018;
        xloc+=0.005;
      }
      else
      {
        yloc+=0.020;
        zloc-=0.001;
        xloc+=0.007;
      }
    }
  }
*/
  //bouncer
  if(key == 'b'|| key == 'B')
  {
    if(val==2)
    {
      if(zloc>-1.010)
      {
        zloc-=0.001;
        yloc+=0.070;
        xloc-=0.010;
      }
      else if(zloc<-1.010 && zloc>-1.060)
      {
        zloc-=0.020;
        yloc+=0.036;
        xloc-=0.005;
      }
      else
      {
        yloc+=0.039;
        zloc-=0.0008;
        xloc-=0.010;
      }
    }

    if(val==1)
    {
      if(zloc>-1.010)
      {
        zloc-=0.001;
        yloc+=0.070;
        xloc+=0.010;
      }
      else if(zloc<-1.010 && zloc>-1.060)
      {
        zloc-=0.020;
        yloc+=0.036;
        xloc-=0.005;
      }
      else
      {
        yloc+=0.039;
        zloc-=0.0008;
        xloc+=0.010;
      }
    }
  }

  //offbreak
  if(key == 'o'|| key == 'O')
  {
    if(val==2)
    {
      if(zloc>-1.020)
      {
        zloc-=0.0002;
        yloc+=0.012;
        xloc-=0.005;
      }
      else if(zloc<-1.020 && zloc>-1.070)
      {
        zloc-=0.007;
        yloc+=0.010;
        xloc-=0.005;
      }
      else
      {
        yloc+=0.014;
        zloc-=0.0005;
        xloc+=0.004;
      }
			//bails off
			if(xloc<0.04 && xloc>-0.04 && yloc>0.8)
			{
				xb1=-0.1;
				yb1=-0.1;
				zb1=0.1;
				xb2=0.1;
				yb2=-0.1;
				zb2=0.1;
			}
    }

    if(val==1)
    {
      if(zloc>-1.020)
      {
        zloc-=0.0002;
        yloc+=0.012;
        xloc+=0.001;
      }
      else if(zloc<-1.020 && zloc>-1.070)
      {
        zloc-=0.007;
        yloc+=0.010;
        xloc+=0.002;
      }
      else
      {
        yloc+=0.014;
        zloc-=0.0005;
        xloc+=0.006;
      }
			//bails off
			if(xloc<0.04 && xloc>-0.04 && yloc>0.8)
			{
				xb1=-0.1;
				yb1=-0.1;
				zb1=0.1;
				xb2=0.1;
				yb2=-0.1;
				zb2=0.1;
			}
    }

  }

  //legbreak
  if(key == 'l'|| key == 'L')
  {
    if(val==2)
    {
      if(zloc>-1.020)
      {
        zloc-=0.0002;
        yloc+=0.012;
        xloc-=0.001;
      }
      else if(zloc<-1.020 && zloc>-1.070)
      {
        zloc-=0.007;
        yloc+=0.010;
        xloc-=0.002;
      }
      else
      {
        yloc+=0.014;
        zloc-=0.0005;
        xloc-=0.008;
      }
			//bails off
			if(xloc<0.04 && xloc>-0.04 && yloc>0.8)
			{
				xb1=-0.1;
				yb1=-0.1;
				zb1=0.1;
				xb2=0.1;
				yb2=-0.1;
				zb2=0.1;
			}
    }

    if(val==1)
    {
      if(zloc>-1.020)
      {
        zloc-=0.0002;
        yloc+=0.012;
        xloc+=0.003;
      }
      else if(zloc<-1.020 && zloc>-1.070)
      {
        zloc-=0.007;
        yloc+=0.010;
        xloc+=0.003;
      }
      else
      {
        yloc+=0.014;
        zloc-=0.0005;
        xloc-=0.005;
      }
			//bails off
			if(xloc<0.04 && xloc>-0.04 && yloc>0.8)
			{
				xb1=-0.1;
				yb1=-0.1;
				zb1=0.1;
				xb2=0.1;
				yb2=-0.1;
				zb2=0.1;
			}
    }
  }

  if (key == 'r')
  {
		glutDisplayFunc(display1);
		glutIdleFunc(display1);
  }
	/*if(xloc>0.1 && xloc<0.2 && yloc>0.6)
	{
		xb1=-0.1;
		yb1=0.1;
		zb1=0.1;
	}*/
  if(yloc>0.8)
  {
    yloc+=0;
    zloc+=0;
    xloc+=0;
  }
  if (yRotationAngle > 360.0f)
  {
    yRotationAngle -= 360.0f;
  }

  xRotationAngle += 0.01f;
  if (xRotationAngle > 360.0f)
  {
    xRotationAngle -= 360.0f;
  }

  zRotationAngle += 0.1f;
  if (zRotationAngle > 360.0f)
  {
    zRotationAngle -= 360.0f;
  }
}

//mouse function

void myreshape(int w,int h)
{
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1,1,-1,1,-10,-10);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(750, 750);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Ball Machine");
  glutCreateMenu(menu);
  glutAddMenuEntry("over the wicket",1);
  glutAddMenuEntry("round the wicket",2);
  glutAddMenuEntry("exit",3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc (display2);
	glutIdleFunc    (display2);
	glutReshapeFunc (myreshape);
  glutKeyboardFunc(keys);
  glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
