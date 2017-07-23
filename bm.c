#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

GLfloat yRotationAngle=0.7,xRotationAngle=0.4,zRotationAngle=0.3;
GLfloat xl=-0.7,xloc=0,yloc=-0.8,zloc=-0.1,xl1=-0.72,xl2=0.72,yl1=-0.67,yl2=-0.83;
GLfloat xb1=0,yb1=0,zb1=0;
GLfloat xb2=0,yb2=0,zb2=0;
GLint val;
char array[10],array1[10];
int diff;
void display1();

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

void speed()
{
	time_t t;
	srand((unsigned)time(&t));
	float r = rand()%20;
	int speed = 130 + r;
	
	sprintf(array,"%d",speed);
	int count = 0;
	
	int speed1 = 80 + r;
	sprintf(array1,"%d",speed1);
	
	//printf("%f\n",speed);
}
void print1(float x, float y,float z, char *st)
{
	int l,i;

	l=strlen( st ); // see how many characters are in text string.
    glColor3f(1,1,1);
	glRasterPos3f( x, y,z); // location to start printing text
	for( i=0; i < l; i++)  // loop until i is greater then l
		{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]); // Print a character on the screen
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
  glutSolidSphere(0.08,20,20);
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

void writ()
{
	glColor3f(1,1,1);
	print1(0.3,0.5,-0.3,"Right click mouse button to choose sides");
	print1(0.3,0.4,-0.3,"Press i key to see instruction again");
	glColor3f(1,0,0);
	print1(-0.7,0.53,0,"FULL");
	glColor3f(0,1,0);
	print1(-0.8,0.33,0,"GOOD");
	glColor3f(0,0,1);
	print1(-0.9,0.05,0,"SHORT");
	glColor3f(1,0,0);
  	//print1(-0.2,0.8,-0.7,"BALL MACHINE");
}

void dim()
{
	glLineWidth(2.0);
	glColor3f(1,0,0);
	glBegin(GL_LINES);
	glVertex3f(-0.85,-0.3,0);
	glVertex3f(-0.65,0.2,0);
	glColor3f(0,1,0);
	glVertex3f(-0.65,0.2,0);
	glVertex3f(-0.55,0.45,0);
	glColor3f(0,0,1);
	glVertex3f(-0.55,0.45,0);
	glVertex3f(-0.478,0.60,0);
	glEnd();
}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  //speed();
  if(yloc > 0.8 && diff==0)
  {
  	glColor3f(0,1,0);
  	print(0.7,0.7,0,array);
  }
  if(yloc > 0.8 && diff ==1)
  {
  	glColor3f(0,1,0);
  	print(0.7,0.7,0,array1);
  }
  glBegin(GL_LINE_LOOP);
  glVertex3f(0.64,0.65,0);
  glVertex3f(0.64,0.78,0);
  glVertex3f(0.86,0.78,0);
  glVertex3f(0.86,0.65,0);
  glEnd();
  print1(0.65,0.83,0,"SPEED (kmph)");
  pitch();
  wickets();
  wickets2();
  dim();
  ballmach();
  sphere();
  writ();
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
	
	///GLfloat xl1=-0.73,yl=-0.67,zl=0,xl2=0.74;
	glPushMatrix();
	//glTranslatef(xl,yl,zl);
	//glutSolidSphere(0.06,20,20);
	glPopMatrix();
	
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	glVertex3f(-0.8,-0.9,0);
	glVertex3f(-0.8,-0.6,0);
	glVertex3f(0.8,-0.6,0);
	glVertex3f(0.8,-0.9,0);
	glEnd();
	glPopMatrix();
	//xl1=-0.73;
	glPushMatrix();
	glTranslatef(xl1,yl1,0);
	glRotatef(xRotationAngle,1,0,0);
	glRotatef(yRotationAngle,0,1,0);
	glRotatef(zRotationAngle,0,0,1);
	xRotationAngle+=1;
	yRotationAngle+=0.5;
	zRotationAngle+=0.5;
	if(xl1 < 0.77)
	{
		xl1+=0.0009;
		if(xl1 > 0.1)
			yl1=-0.83;
	}
	
	else
	{
		glutDisplayFunc(display1);
		glutIdleFunc(display1);
	}
	glutSolidSphere(0.06,20,20);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0,1,0);
	glTranslatef(xl2,yl2,0);
	glRotatef(xRotationAngle,1,0,0);
	glRotatef(yRotationAngle,0,1,0);
	glRotatef(zRotationAngle,0,0,1);
	xRotationAngle+=1;
	yRotationAngle+=0.5;
	zRotationAngle+=0.5;
	if(xl2 > -0.8)
	{
		xl2-=0.0009;
		if(xl2 < -0.1)
			yl2=-0.67;
	}
	else
	{
		//glutDisplayFunc(display);
		//glutIdleFunc(display);
	}
	glutSolidSphere(0.06,10,10);
	glPopMatrix();
	glFlush();
}

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1,0,0);
	print(-0.2,0.2,-0.2,"press x for ball to FLASHY outswing");
	//sleep(3);
	glColor3f(0,1,0);
	print(-0.3,0.1,-0.3,"press y for ball to BANANA inswing ");
	
	glColor3f(0,0,1);
	print(-0.4,0,-0.4,"press z for TOE-CRUSHER yorker");
	
	glColor3f(1,0,0);
	print(-0.5,-0.1,-0.5,"press b for JAW-BREAKING bouncer");
	
	glColor3f(0,1,0);
	print(-0.6,-0.2,-0.6,"press o for SNAKY offbreak");
	
	glColor3f(0,0,1);
	print(-0.7,-0.3,-0.7,"press l for WARNY legbreak");
	
    //print1(-0.8,-0.4,0,"chandresh tiwari");
	glPushMatrix();
	//glTranslatef(-0.8,-0.7,0);
		glRotatef(xRotationAngle,1,0,0);
		glRotatef(yRotationAngle,0,1,0);
		glRotatef(zRotationAngle,0,0,1);
		xRotationAngle+=1;
		yRotationAngle+=0.5;
		zRotationAngle+=0.5;
		int i=0;
		/*for(i=0;i<7;i+=2)
		{
				glTranslatef(-0.8,-0.7,0);
				glutWireSphere(0.1,5,5);
		}*/
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
  if(key == 'i'|| key == 'I')
  {
  		glutDisplayFunc(display1);
  		glutIdleFunc(display1);
  }
  //outswinger
  if(key == 'x' || key == 'X')
  {
    //round
    diff=0;
    if(val==2)
    {
        //print(xloc,yloc,zloc,"hello");
        if(yloc<0.40 && zloc>-1.05)
        {
            yloc+=0.090;
            zloc-=0.004;
            xloc-=0.020;
           writ();
        }
        else if(yloc < 0.42 && zloc > -1.065)
        {
        	yloc-=0.010;
        	zloc-=0.002;
        	xloc-=0.015;
        }
        else
        {
        	yloc+=0.045;
        	zloc-=0.0007;
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
        if(yloc<0.40 && zloc>-1.05)
        {
            yloc+=0.090;
            zloc-=0.004;
            xloc+=0.020;
        }
        else if(yloc < 0.42 && zloc > -1.065)
        {
        	yloc-=0.010;
        	zloc-=0.002;
        	xloc+=0.015;
        }
        else
        {
        	yloc+=0.045;
        	zloc-=0.0007;
        	xloc-=0.015;
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
  	diff=0;
    if(val==2)
    {
          if(yloc<0.40 && zloc>-1.05)
        {
            yloc+=0.090;
            zloc-=0.004;
            xloc-=0.035;
        }
        else if(yloc < 0.42 && zloc > -1.065)
        {
        	yloc-=0.010;
        	zloc-=0.002;
        	xloc-=0.010;
        }
        else
        {
        	yloc+=0.040;
        	zloc-=0.0007;
        	xloc+=0.010;
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
        if(yloc<0.40 && zloc>-1.05)
        {
            yloc+=0.090;
            zloc-=0.004;
            xloc+=0.010;
        }
        else if(yloc < 0.42 && zloc > -1.065)
        {
        	yloc-=0.010;
        	zloc-=0.002;
        	xloc+=0.005;
        }
        else
        {
        	yloc+=0.045;
        	zloc-=0.0007;
        	xloc+=0.015;
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
if(key == 'z' || key == 'Z')
  {
  	diff =0;
    if(val==2)
    {
       if(yloc<0.60 && zloc>-1.072)
        {
            yloc+=0.085;
            zloc-=0.0038;
            xloc-=0.020;
        }
        else if(yloc < 0.65 && zloc > -1.085)
        {
        	yloc-=0.020;
        	zloc-=0.002;
        	xloc-=0.005;
        }
        else
        {
        	yloc+=0.060;
        	zloc-=0.0001;
        	xloc-=0.015;
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
     if(yloc<0.60 && zloc>-1.072)
        {
            yloc+=0.085;
            zloc-=0.0038;
            xloc+=0.020;
        }
        else if(yloc < 0.65 && zloc > -1.085)
        {
        	yloc-=0.020;
        	zloc-=0.002;
        	xloc+=0.005;
        }
        else
        {
        	yloc+=0.060;
        	zloc-=0.0001;
        	xloc+=0.015;
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

  //bouncer
  if(key == 'b'|| key == 'B')
  {
  	diff = 0;
    if(val==2)
    {
        if(yloc<0.40 && zloc>-1.05)
        {
            yloc+=0.090;
            zloc-=0.004;
            xloc-=0.015;
        }
        else if(yloc < 0.45 && zloc > -1.067)
        {
        	yloc-=0.016;
        	zloc-=0.0018;
        	xloc-=0.010;
        }
        else
        {
        	yloc+=0.065;
        	zloc-=0.0007;
        	xloc-=0.010;
        }
    }

    if(val==1)
    {
        if(yloc<0.40 && zloc>-1.05)
        {
            yloc+=0.090;
            zloc-=0.004;
            xloc+=0.015;
        }
        else if(yloc < 0.45 && zloc > -1.067)
        {
        	yloc-=0.016;
        	zloc-=0.0018;
        	xloc+=0.010;
        }
        else
        {
        	yloc+=0.065;
        	zloc-=0.0007;
        	xloc+=0.010;
        }
    }
  }

  //offbreak
  if(key == 'o'|| key == 'O')
  {
  	diff = 1;
    if(val==2)
    {
      if(yloc<0.80 && zloc>-1.05)
        {
            yloc+=0.045;
            zloc-=0.002;
            xloc-=0.015;
        }
        else if(yloc < 0.85 && zloc > -1.065)
        {
        	yloc-=0.010;
        	zloc-=0.002;
        	xloc-=0.010;
        }
        else
        {
        	yloc+=0.040;
        	zloc-=0.0007;
        	xloc+=0.015;
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
      if(yloc<0.80 && zloc>-1.05)
        {
            yloc+=0.045;
            zloc-=0.002;
            xloc-=0.00;
        }
        else if(yloc < 0.85 && zloc > -1.065)
        {
        	yloc-=0.010;
        	zloc-=0.002;
        	xloc+=0.010;
        }
        else
        {
        	yloc+=0.040;
        	zloc-=0.0007;
        	xloc+=0.025;
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
  	diff = 1;
    if(val==2)
    {
      if(yloc<0.80 && zloc>-1.05)
        {
            yloc+=0.045;
            zloc-=0.002;
            xloc-=0.00;
        }
        else if(yloc < 0.85 && zloc > -1.065)
        {
        	yloc-=0.010;
        	zloc-=0.002;
        	xloc-=0.010;
        }
        else
        {
        	yloc+=0.040;
        	zloc-=0.0007;
        	xloc-=0.025;
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
      if(yloc<0.80 && zloc>-1.05)
        {
            yloc+=0.045;
            zloc-=0.002;
            xloc+=0.015;
        }
        else if(yloc < 0.85 && zloc > -1.065)
        {
        	yloc-=0.010;
        	zloc-=0.002;
        	xloc+=0.010;
        }
        else
        {
        	yloc+=0.040;
        	zloc-=0.0007;
        	xloc-=0.025;
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
	glutInit(&argc, argv);
	//speed(); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(750, 750);
	glutInitWindowPosition(0, 0);
	speed();
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
