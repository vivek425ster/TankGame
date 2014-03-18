#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)
using namespace std;
// Function Declarations
void drawScene();
void startscene();
void insscene();
void handlemouse_drag(int x,int y) ;
void drawrect(float len1,float len2) ;
void drawleg1(float x1,float y1,float len,float ele);
void DrawEllipse(float radiusX, float radiusY);
void drawrect1(float len1,float len2); 
void drawrect11(float len1,float len2); 
void drawrect4(float len1,float len2); 
void drawrect5(float len1,float len2); 
void GetOGLPos(int x, int y);
void drawrect3(float len1,float len2); 
void drawrect2(float len1,float len2); 
void update(int value);
void generateblack(int value);
void generatered(int value);
void generategreen(int value);
void spider1(int value);
void spider2(int value);
void spider3(int value);
void drawBox(float len);
void drawBall(float rad);
void drawTriangle();
void drawline(float i);
void score1();
void score2();
void score3();
void score4();
void score5();
void score6();
void score7();
void shoot();
void initRendering();
void handleResize(int w, int h);
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handleMouseclick(int button, int state, int x, int y);
void drawCylinder( float height, float radius, float slices, float stacks ); 
void drawspiderred(float len); 

// Variable declaration

// Global Variables
float ball_velx = 0.01f;
float ball_vely = 0.02f;

float ball_rad = 0.2f;

//Size of the world
float box_len = 4.0f;

// Tankers position
float tri_x = 0.0f;
float k=-1.0*(box_len/2) + (0.2/2);
float tri_y = k;
float theta = 0.0f; 


float len = 0.4f;
float line_vel=0.05f;
int turn=1;
int prev=turn;
int ti=1000;

float height=box_len/5;
float radius=box_len/15;

float x_green=-1.0*(box_len/2)+(radius);
//float x_green=-1.68;
float y_green=-1.0*(box_len/2)-(height/4);
//float y_green=-1.87;

int click=0;
int score=0;
float	x_red=1.0*(box_len/2)-(radius);
float	y_red=-1.0*(box_len/2)-(height/4);

//tank variables
float tank1_hei=0.1*box_len*0.4;
float tank1_wid=0.1*box_len;

float tank2_hei=0.1*box_len*0.6;
float tank2_wid=0.05*box_len;

float tank3_hei=0.01*box_len/4;
float tank3_wid=0.1*box_len/4*2;


float tank4_hei=0.3*box_len/4;
float tank4_wid=0.05*box_len/4;
//tank variables end

//spider variables begin

float rad_x=0.05*box_len/4;
float rad_y=0.07*box_len/4;

float leg1_x=-1*0.05*box_len/4;
float leg1_y=0.0f;
float leg1_hei=0.1*box_len/4;
float leg1_ele=0.01*box_len/4;

float leg2_x=-0.15*box_len/4;
float leg2_y=0.01*box_len/4;
float leg2_hei=0.1*box_len/4;
float leg2_ele=0.05*box_len/4;

float leg3_x=-0.15*box_len/4;
float leg3_y=-0.03*box_len/4;
float leg3_hei=0.1*box_len/4;
float leg3_ele=-0.05*box_len/4;

float leg4_x=0.05*box_len/4;
float leg4_y=0.0;
float leg4_hei=-0.1*box_len/4;
float leg4_ele=0.01*box_len/4;

float leg5_x=0.15*box_len/4;
float leg5_y=0.01*box_len/4;
float leg5_hei=-0.1*box_len/4;
float leg5_ele=0.05*box_len/4;


float leg6_x=-0.05*box_len/4;
float leg6_y=-0.03*box_len/4;
float leg6_hei=0.1*box_len/4;
float leg6_ele=-0.01*box_len/4;


float leg7_x=0.05*box_len/4;
float leg7_y=-0.03*box_len/4;
float leg7_hei=-0.1*box_len/4;
float leg7_ele=-0.01*box_len/4;


float leg8_x=0.15*box_len/4;
float leg8_y=-0.03*box_len/4;
float leg8_hei=-0.1*box_len/4;
float leg8_ele=-0.05*box_len/4;


float leg9_x=-0.05*box_len/4;
float leg9_y=0.13*box_len/4;
float leg9_hei=-0.05*box_len/4;
float leg9_ele=-0.1*box_len/4;

float leg10_x=-0.15*box_len/4;
float leg10_y=0.18*box_len/4;
float leg10_hei=-0.1*box_len/4;
float leg10_ele=-0.05*box_len/4;

float leg11_x=0.03*box_len/4;
float leg11_y=0.05*box_len/4;
float leg11_hei=-0.05*box_len/4;
float leg11_ele=0.1*box_len/4;

float leg12_x=0.08*box_len/4;
float leg12_y=0.15*box_len/4;
float leg12_hei=-0.1*box_len/4;
float leg12_ele=0.05*box_len/4;

float leg13_x=-0.02*box_len/4;
float leg13_y=-0.06*box_len/4;
float leg13_hei=0.05*box_len/4;
float leg13_ele=-0.1*box_len/4;

float leg14_x=-0.07*box_len/4;
float leg14_y=-0.15*box_len/4;
float leg14_hei=0.1*box_len/4;
float leg14_ele=-0.05*box_len/4;

float leg15_x=0.02*box_len/4;
float leg15_y=-0.05*box_len/4;
float leg15_hei=-0.05*box_len/4;
float leg15_ele=-0.1*box_len/4;

float leg16_x=0.06*box_len/4;
float leg16_y=-0.14*box_len/4;
float leg16_hei=-0.1*box_len/4;
float leg16_ele=-0.05*box_len/4;

//mouse coordinates
float mouseposx;
float mouseposy;
float mouseposz;
//blocking condition variables
float green_left=-(box_len/2)+radius; 
float green_right=box_len/2-radius;
float red_left=green_left;  
float red_right=green_right; 
float can_left=(-box_len/2+tank1_wid); 
float can_right=(box_len/2-tank1_wid);

//spider variables end
int prevscore=0;
int cur=1;
typedef struct{
	float line_x;
	float line_y;
	float line_z;
	float line_x_ref;
	float line_y_ref;
	float rot;
}ab;
vector <ab> line;
/*float line_x=tri_x;
  float line_y=tri_y;
  float line_z=5.0f;*/
typedef struct{
	float spider_x ;
	float spider_y ;
	float spider_z ;
	int flag;
	int idle;
	float speed;
}spired;

vector <spired> spiderred;
vector <spired> spiderblack;
vector <spired> spidergreen;
int st=0;
//float spider1_y[100] ;
//float spider2_y = 0.0f;
//float spider3_y = 0.0f;
//float spider1_z = 0.0f;
//float spider2_z = 5.0f;
//float spider3_z = 5.0f;
int i;
int over=2;
int time_lev=0;

// Random number generator function
float RandomFloat(float a, float b) {
	float random = ((float) rand()) / (float) RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}
int time_spider=4000;
int t=1;
//main funcrion
int main(int argc, char **argv) {

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	int windowWidth = w *2/3; //width of the window which initially appears
	int windowHeight = h *2/3; //height of the window which initially appears
	
	glutInitWindowSize(windowWidth, windowHeight); 
	glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);//position of window where it will initially appears

	glutCreateWindow("201202182");  // Setup the window
	initRendering();

	// Register callbacks
	if(over==1)
	{
		glutDisplayFunc(drawScene);
		glutIdleFunc(drawScene);
	}
	if(over==2)
	{
		glutDisplayFunc(startscene);
		glutIdleFunc(startscene);
	}
	if(over==3)
	{
		glutDisplayFunc(insscene);
		glutIdleFunc(insscene);

	}
	glutKeyboardFunc(handleKeypress1);
	glutSpecialFunc(handleKeypress2);
	glutMouseFunc(handleMouseclick);
	glutMotionFunc(handlemouse_drag);
	glutReshapeFunc(handleResize);
	if(turn!=4 && over==1)
	{
		glutTimerFunc(10, update, 0);
		glutTimerFunc(10, spider1, 0);
		glutTimerFunc(1000, generatered, 0);
	}
	glutMainLoop();
	return 0;
}
void shoot(){
	int len=line.size();
	line[len-1].line_z=0.0f;
}
void startscene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	// Draw Box
	glTranslatef(0.0f, 0.0f, -5.0f);
	glColor3f(0.196078, 0.6, 0.8);
	drawBox(box_len);
	//tri_x=-0.5f;
	//tri_y=1.0f;
	// Tank End

	glPushMatrix();
	glTranslatef(0, 1.0f, 0.0f);
	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//	glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect(tank1_wid,tank1_hei);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.0f, 0.0f);

	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//	glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect1(tank2_wid,tank2_hei);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.0f, 0.0f);

	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//	glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect2(tank3_wid,tank3_hei);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.0f, 0.0f);

	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//	glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect3(tank3_wid,tank3_hei);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1.0f, 0.0f);

	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect4(tank4_wid,tank4_hei);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 1.0f, 0.0f);
	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(0.85, 0.85, 0.10);
	drawrect5(tank4_wid,tank4_hei);
	glPopMatrix();


	glColor3f(1.0f, 0.0f, 0.0f);
	score3();
	score4();
	score5();
	glPopMatrix();
	glutSwapBuffers();


}

void insscene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	// Draw Box
	glTranslatef(0.0f, 0.0f, -5.0f);
	glColor3f(0.196078, 0.6, 0.8);
	drawBox(box_len);

	glColor3f(1.0f, 0.0f, 0.0f);
	score6();
	score7();
//	score8();
	glPopMatrix();
	glutSwapBuffers();


}
//scene that will be displayed when the the game is over
void overScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	// Draw Box
	glTranslatef(0.0f, 0.0f, -5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawBox(box_len);

	glColor3f(1.0f, 0.0f, 0.0f);
	score2();
	glPopMatrix();
	glutSwapBuffers();

	int t=10*100000000;
	while(t)
	{
		t--;
	}
	exit(0);	

}

// Function to draw objects on the screen
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	// Draw Box
	glTranslatef(0.0f, 0.0f, -5.0f);
	glColor3f(0.96, 0.80, 0.69);
	drawBox(box_len);

	// Draw Base
	glPushMatrix();
	glTranslatef(0.0f, -1*box_len/2+box_len/20, 0.0f);
	glColor3f(0.5f, 0.0f, 1.0f);
	drawrect(box_len,0.1*box_len);
	glPopMatrix();
	// Base End


	// Draw Tank
	glPushMatrix();
	glTranslatef(tri_x, tri_y, 0.0f);
	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//	glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect(tank1_wid,tank1_hei);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(tri_x, tri_y, 0.0f);

	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//	glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect1(tank2_wid,tank2_hei);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(tri_x, tri_y, 0.0f);

	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//	glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect2(tank3_wid,tank3_hei);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(tri_x, tri_y, 0.0f);

	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//	glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect3(tank3_wid,tank3_hei);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(tri_x, tri_y, 0.0f);

	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	drawrect4(tank4_wid,tank4_hei);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(tri_x, tri_y, 0.0f);
	glRotatef(theta, 0.0f, 0.0f, 1.0f);
	if(turn==1)
		glColor3f(0.85, 0.85, 0.10);
	//glColor3f(0.5f, 0.5f, 1.0f);
	else
		glColor3f(0.81, 0.71, 0.23);
	//	glColor3f(0.85, 0.85, 0.10);
	drawrect5(tank4_wid,tank4_hei);
	glPopMatrix();
	// Tank End

	// Draw Triangle




	//	glPushMatrix();
	//	glTranslatef(-1.5f, 1.0f   , 0.0f);
	//	drawleg1(0.22,0.32f,0.1,-0.05);
	//	glPopMatrix();


	glPushMatrix(); 
	glTranslatef(x_green,y_green, 0.0f); 
	if(turn==3)
		glColor3f(0.0f, 1.0f, 0.0f); 
	else
		glColor3f( 0.560784, 0.737255, 0.560784); 
	//glScalef(0.5f,0.5f,0.5f); 
	glRotatef(-90.0f,1.0f,0.0f,0.0f); 
	drawCylinder(height,radius,35,36); 
	glPopMatrix();


	glPushMatrix(); 
	glTranslatef(x_red,y_red, 0.0f); 
	if(turn==2)
		glColor3f(1.0f, 0.0f, 0.0f); 
	else
		glColor3f(0.737255, 0.184314, 0.184314); 
	//glScalef(0.5f,0.5f,0.5f); 
	glRotatef(-90.0f,1.0f,0.0f,0.0f);
	//	glScalef(0.3f, 0.3f, 0.3f);
	drawCylinder(height,radius,35,36); 
	glPopMatrix();

	int i;
	len=spiderred.size();
	for(i=st;i<len;i++)
	{

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		DrawEllipse(rad_x,rad_y);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg1_x,leg1_y,leg1_hei,leg1_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg2_x,leg2_y,leg2_hei,leg2_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg6_x,leg6_y,leg6_hei,leg6_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg3_x,leg3_y,leg3_hei,leg3_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg4_x,leg4_y,leg4_hei,leg4_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg5_x,leg5_y,leg5_hei,leg5_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg7_x,leg7_y,leg7_hei,leg7_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg8_x,leg8_y,leg8_hei,leg8_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg9_x,leg9_y,leg9_hei,leg9_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg10_x,leg10_y,leg10_hei,leg10_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg11_x,leg11_y,leg11_hei,leg11_ele);

		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg12_x,leg12_y,leg12_hei,leg12_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg13_x,leg13_y,leg13_hei,leg13_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg14_x,leg14_y,leg14_hei,leg14_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{
			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg15_x,leg15_y,leg15_hei,leg15_ele);
		glPopMatrix();

		glPushMatrix();

		glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);
		if(spiderred[i].flag==0)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		else if(spiderred[i].flag==1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if(spiderred[i].flag==2)
		{

			glColor3f(0.0f, 0.0f, 0.0f);
		}
		drawleg1(leg16_x,leg16_y,leg16_hei,leg16_ele);
		glPopMatrix();
	


		/*	glPushMatrix();
			glTranslatef(spiderred[i].spider_x, spiderred[i].spider_y, spiderred[i].spider_z);

			if(spiderred[i].flag==0)
			{
			glColor3f(1.0f, 0.0f, 0.0f);
			}
			else if(spiderred[i].flag==1)
			{
			glColor3f(0.0f, 1.0f, 0.0f);
			}
			else if(spiderred[i].flag==2)
			{

			glColor3f(0.0f, 0.0f, 0.0f);
			}
		//	glScalef(0.3f, 0.3f, 0.3f);
		drawspiderred(0.2);
		glPopMatrix();*/
	}
	glColor3f(0.541f, 0.168f, 0.886f);
		score1();


	len=line.size();
	for(i=st;i<len;i++)
	{
		glPushMatrix();
		glTranslatef(line[i].line_x_ref, line[i].line_y_ref, line[i].line_z);
		glRotatef(line[i].rot, 0.0f, 0.0f, 1.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		drawline(i);
		glPopMatrix();
	}


	glPopMatrix();
	glutSwapBuffers();
}

void DrawEllipse(float radiusX, float radiusY)
{
	int i;

	glBegin(GL_TRIANGLE_FAN);

	for(i=0;i<360;i++)
	{
		glVertex2f(cos(DEG2RAD(i))*radiusX,
				sin(DEG2RAD(i))*radiusY);
	}

	glEnd();
}
void score3()
{
	glRasterPos2f(-0.5f,0.0f);
	char game[16]="Welcome to Tank";
	int i;

	for(i=0;i<(int)(strlen(game));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,game[i]);
	//	for(i=0;i<(int)(strlen(string));i++)
	//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	//	char str[80];
	//	sprintf(str,"%d",score);
	//	for(i=0;i<(int)(strlen(str));i++)
	//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
}
void score4()
{
	glRasterPos2f(-0.7f,-0.5f);
	char game[40]="Click s or S to start the game";
	int i;

	for(i=0;i<(int)(strlen(game));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,game[i]);
	//	for(i=0;i<(int)(strlen(string));i++)
	//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	//	char str[80];
	//	sprintf(str,"%d",score);
	//	for(i=0;i<(int)(strlen(str));i++)
	//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
}
void score5()
{
	glRasterPos2f(-0.7f,-0.7f);
	char game[40]="Click c or C to see controls";
	int i;

	for(i=0;i<(int)(strlen(game));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,game[i]);
	//	for(i=0;i<(int)(strlen(string));i++)
	//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	//	char str[80];
	//	sprintf(str,"%d",score);
	//	for(i=0;i<(int)(strlen(str));i++)
	//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
}
void score6()
{
	glRasterPos2f(-0.6f,0.4f);
	char game[40]="Keyboard";
	int i;

	for(i=0;i<(int)(strlen(game));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,game[i]);
}
void score7()
{
	glRasterPos2f(-0.2f,0.2f);
	char game[40]="b :Select Cannon";
	int i;

	for(i=0;i<(int)(strlen(game));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,game[i]);

	glRasterPos2f(-0.2f,0.0f);
	char sts[40]="r :Select red basket";
//	int i;
	
	for(i=0;i<(int)(strlen(sts));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sts[i]);


	glRasterPos2f(-0.2f,-0.2f);
	char st[40]="g :Select green basket";
//	int i;
	
	for(i=0;i<(int)(strlen(st));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st[i]);
	glRasterPos2f(-0.6f,-0.6f);
	char str[40]="Mouse";
//	int i;
	
	for(i=0;i<(int)(strlen(str));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
glRasterPos2f(-0.4f,-0.8f);
	char sti[50]="Left Click on the object and drag to move";
//	int i;
	
	for(i=0;i<(int)(strlen(sti));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sti[i]);

glRasterPos2f(-0.4f,-1.0f);
	char stii[51]="Right Click on the tank and drag to rotate";
//	int i;
	
	for(i=0;i<(int)(strlen(sti));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,stii[i]);
	
	glRasterPos2f(-0.5f,-1.3f);
	char stiii[51]="Press b to go back to main menu";
//	int i;
	
	for(i=0;i<(int)(strlen(stiii));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,stiii[i]);

	//	for(i=0;i<(int)(strlen(string));i++)
	//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	//	char str[80];
	//	sprintf(str,"%d",score);
	//	for(i=0;i<(int)(strlen(str));i++)
	//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
}
void score2()
{
	glRasterPos2f(-0.5f,0.0f);
	char game[15]="Game Over: ";
	char string[10]="SCORE : ";
	int i;

	for(i=0;i<(int)(strlen(game));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,game[i]);
	for(i=0;i<(int)(strlen(string));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	char str[80];
	sprintf(str,"%d",score);
	for(i=0;i<(int)(strlen(str));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
}
void score1()
{
	glRasterPos2f(box_len/2+box_len/4*0.1,box_len/2-box_len/4*0.1f);
	char string[10]="SCORE : ";
	int i;
	for(i=0;i<(int)(strlen(string));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	char str[80];
	sprintf(str,"%d",score);
	for(i=0;i<(int)(strlen(str));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);

	glRasterPos2f(box_len/2+box_len/4*0.1,box_len/2-box_len/4);
	char str1[10]="Level : ";
	for(i=0;i<(int)(strlen(str1));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[i]);
	char st[80];
	sprintf(st,"%d",t);

	for(i=0;i<(int)(strlen(st));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st[i]);
//	glRasterPos2f(box_len/2-1.0f,box_len/2-0.1*box_len/4);

}



// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update(int value) {

	// Handle laser collisions with spiders
	int i;
	int len=line.size();
	for(i=0;i<len;i++)
	{
		int j;
		int sp_len=spiderred.size();
		for(j=0;j<sp_len;j++)
		{
			float actual_y=line[i].line_y_ref + (line[i].line_y-line[i].line_y_ref+0.1*box_len)*cos(DEG2RAD(line[i].rot)); 
			float actual_x = line[i].line_x_ref - (line[i].line_y-line[i].line_y_ref+0.1*box_len)*sin(DEG2RAD(line[i].rot));
			if((spiderred[j].spider_x - float(rad_x)+float(leg1_x)-float(leg1_hei)) <= actual_x && (spiderred[j].spider_x+ float(rad_x)+float(leg4_x)-float(leg4_hei)) >= actual_x && (spiderred[j].spider_y -float(rad_y) -float(leg12_y)) <=actual_y+0.1*(box_len/2) && (spiderred[j].spider_y +float(rad_y) +float(leg10_y)) >= actual_y + 0.1*box_len/2 && line[i].line_z==0.0f && spiderred[j].idle==0 && line[i].line_z==0.0f)
			{
				if(spiderred[j].flag==2)
					score+=1;
				spiderred.erase(spiderred.begin()+j);
				line[i].line_z=5.0f;
				system("aplay smashing.wav &");
			}
		}
		//if(line[i].line_y >box_len/2)
		//{
		//		line[i].line_z=5.0f; 
		//	} 

		//else{



		float actual_y=line[i].line_y_ref + (line[i].line_y-line[i].line_y_ref+0.1*box_len)*cos(DEG2RAD(line[i].rot)); 
		float actual_x = line[i].line_x_ref - (line[i].line_y-line[i].line_y_ref+0.1*box_len)*sin(DEG2RAD(line[i].rot));
		if(actual_y>=box_len/2) 
		{ 
			line[i].line_z=5.0f; 
		} 
		else if((actual_x>=box_len/2 && actual_y<=box_len/2) || (actual_x<=-box_len/2 && actual_y<=box_len/2))
		{ 
			line[i].line_y_ref=actual_y; 
			line[i].line_x_ref=actual_x; 
			line[i].line_y=line[i].line_y_ref; 
			line[i].rot=-line[i].rot; 
		}

		line[i].line_y+=line_vel; 
		//			line[i].line_y+=line_vel*cos(-1*DEG2RAD(line[i].rot));
		//			line[i].line_x+=line_vel*sin(-1*DEG2RAD(line[i].rot));
		//}
	}
	int s=line.size();
	for(i=0;i<s;i++)
	{
		if(line[i].line_z==5.0f)
			line.erase(line.begin()+i);
	}
	//ball_x += ball_velx;
	//ball_y += ball_vely;
	ti+=10;
	if(ti>1000)
		ti=1000;
	if(turn!=4)
		glutTimerFunc(10, update, 0);
	if(score-prevscore>10*t)
	{

		system("aplay level.wav &");
		time_spider-=500;
		prevscore=score;
		t++;
	}

	time_lev+=10;
}

void spider1(int value){

	int i;
	int len=spiderred.size();
	for(i=0;i<len;i++)
	{
		//cout << spiderred[i].spider_y - float(0.1) << " " << y_green + float(height/2) << endl; 
		if(spiderred[i].spider_x <= x_green + radius  && spiderred[i].spider_x >=x_green - radius && spiderred[i].spider_y - float(rad_y)<=y_green+float(height/2)  && spiderred[i].idle==0)
		{
			if(spiderred[i].flag==1)
			{
				score+=1;
				system("aplay basket.wav &");
			}
			else
			{
				score-=1;
				
			}
			spiderred.erase(spiderred.begin()+i);
		}

		if(spiderred[i].spider_x <= x_red + radius  && spiderred[i].spider_x >=x_red - radius  && spiderred[i].spider_y - float(rad_y)  <=y_red+float(height/2) && spiderred[i].idle==0) 
		{
			if(spiderred[i].flag==0)
			{
				score+=1;

				system("aplay basket.wav &");
			}
			else
				score-=1;
			spiderred.erase(spiderred.begin()+i);
		}
		if(spiderred[i].spider_y - float(rad_y) <= -1.0*box_len/2 && spiderred[i].idle==0)
		{
			score-=5;
			spiderred[i].idle=1;
			/*if(green_right>spiderred[i].spider_x && spiderred[i].spider_x>x_green+radius) 
			  { 
			  green_right=spiderred[i].spider_x-rad_x; 
			  } 
			  if(green_left<spiderred[i].spider_x && spiderred[i].spider_x<x_green-radius) 
			  { 
			  green_left=spiderred[i].spider_x+rad_x; 
			  } 
			  if(red_right>spiderred[i].spider_x && spiderred[i].spider_x>x_red+radius) 
			  { 
			  red_right=spiderred[i].spider_x-rad_x; 
			  } 
			  if(red_left<spiderred[i].spider_x && spiderred[i].spider_x<x_red-radius) 
			  { 
			  red_left=spiderred[i].spider_x+rad_x; 
			  } */
			if(can_right>spiderred[i].spider_x-rad_x-tank3_wid-tank4_wid-tank1_wid/2 && spiderred[i].spider_x>tri_x) 
			{ 
				can_right=spiderred[i].spider_x-rad_x-tank3_wid-tank4_wid-tank1_wid/2; 
			} 
			if(can_left<spiderred[i].spider_x+rad_x+tank3_wid+tank4_wid+tank1_wid/2 && spiderred[i].spider_x<tri_x-tank1_wid/2) 
			{ 
				can_left=spiderred[i].spider_x+rad_x+tank3_wid+tank4_wid+tank1_wid/2; 
			}
		}
		if(tri_y>= spiderred[i].spider_y  && spiderred[i].spider_x <=tri_x+0.05*box_len && spiderred[i].spider_x >=tri_x -0.05*box_len && spiderred[i].idle==0)
		{
			//		while(2*100000)	
			//		{}
			glutDisplayFunc(overScene);
			glutIdleFunc(overScene);
			system("aplay game.wav &");
			over=0;
			//	exit(0);
		}

		// this condition os for moving the spider with a particular speed
		if(spiderred[i].idle==0)
		{
			spiderred[i].spider_y-=spiderred[i].speed;
		}
	}
	if(turn!=4)
		glutTimerFunc(10,spider1,0);
}

void spider2(int value){

	int i;
	int len=spiderblack.size();
	for(i=0;i<len;i++)
	{
		spiderblack[i].spider_y-=ball_vely;
	}

	if(turn!=4)
		glutTimerFunc(10,spider2,0);
}

void spider3(int value){

	int i;
	int len=spidergreen.size();
	//cout <<len << endl;
	for(i=0;i<len;i++)
	{
		spidergreen[i].spider_y-=ball_vely;
	}
	if(turn!=4)
		glutTimerFunc(10,spider3,0);
}
void generatered(int value){
	if(turn!=4)
	{
		spired a;
		a.spider_x=RandomFloat(-box_len/2,box_len/2);
		a.spider_y=box_len/2;
		a.spider_z=0.0f;
		a.flag=rand()%3;
		a.idle=0;
		float rat=RandomFloat(0.01,0.015);
		a.speed=rat;
		spiderred.push_back(a);
		if(turn!=4)
			glutTimerFunc(time_spider, generatered, 0);
	}

}

void generateblack(int value){

	spired a;
	a.spider_x=RandomFloat(-2.0f,2.0f);
	a.spider_y=2.0f;
	a.spider_z=0.0f;
	a.flag=1;
	spiderblack.push_back(a);
	if(turn!=4)
		glutTimerFunc(1000, generateblack, 0);
}

void generategreen(int value){

	spired a;
	a.spider_x=RandomFloat(-2.0f,2.0f);
	a.spider_y=2.0f;
	a.spider_z=0.0f;
	a.flag=1;
	spidergreen.push_back(a);
	if(turn!=4)
		glutTimerFunc(1000, generategreen, 0);
}

GLUquadricObj* myReusableQuadric = 0; 
void drawCylinder( float height, float radius, float slices, float stacks ) 
{

	if ( ! myReusableQuadric ) 
	{ 
		myReusableQuadric = gluNewQuadric(); 
		gluQuadricNormals( myReusableQuadric, GL_TRUE ); 
	}
	gluCylinder( myReusableQuadric, radius, radius, height, slices, stacks ); 	
}
void drawBox(float len) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-len / 2, -len / 2);
	glVertex2f(len / 2, -len / 2);
	glVertex2f(len / 2, len / 2);
	glVertex2f(-len / 2, len / 2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawrect(float len1,float len2) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-len1 / 2, -len2);
	glVertex2f(len1 / 2, -len2);
	glVertex2f(len1/2, len2);
	glVertex2f(-len1 / 2, len2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawrect1(float len1,float len2) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-len1 / 2, -len2+tank1_hei/2);
	glVertex2f(len1 / 2, -len2+tank1_hei/2);
	glVertex2f(len1/2, -len2+tank1_hei/2+2*len2*ti*0.001);
	glVertex2f(-len1 / 2, -len2+tank1_hei/2+2*len2*ti*0.001);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawrect11(float len1,float len2) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	ti=1000;
	glVertex2f(-len1 / 2, -len2+tank1_hei/2);
	glVertex2f(len1 / 2, -len2+tank1_hei/2);
	glVertex2f(len1/2, -len2+tank1_hei/2+2*len2*ti*0.001);
	glVertex2f(-len1 / 2, -len2+tank1_hei/2+2*len2*ti*0.001);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawrect2(float len1,float len2) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-len1 / 2-tank1_wid/2, -len2);
	glVertex2f(len1 / 2-tank1_wid/2, -len2);
	glVertex2f(len1/2-tank1_wid/2, len2);
	glVertex2f(-len1 / 2-tank1_wid/2, len2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawrect3(float len1,float len2) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-len1 / 2+tank1_wid/2, -len2);
	glVertex2f(len1 / 2+tank1_wid/2, -len2);
	glVertex2f(len1/2+tank1_wid/2, len2);
	glVertex2f(-len1 / 2+tank1_wid/2, len2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawrect4(float len1,float len2) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-len1 / 2-tank1_wid/2-tank3_wid/2, -len2+tank1_hei/2);
	glVertex2f(len1 / 2-tank1_wid/2-tank3_wid/2, -len2+tank1_hei/2);
	glVertex2f(len1/2-tank1_wid/2-tank3_wid/2, len2);
	glVertex2f(-len1 / 2-tank1_wid/2-tank3_wid/2, len2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawrect5(float len1,float len2) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-len1 / 2+tank1_wid/2+tank3_wid/2, -len2+tank1_hei/2);
	glVertex2f(len1 / 2+tank1_wid/2+tank3_wid/2, -len2+tank1_hei/2);
	glVertex2f(len1/2+tank1_wid/2+tank3_wid/2, len2);
	glVertex2f(-len1 / 2+tank1_wid/2+tank3_wid/2, len2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void drawspiderred(float len) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	//  glColor3d(1.0f,0.0f,0.0f);
	glVertex2f(-len / 2, -len / 2);
	glVertex2f(len / 2, -len / 2);
	glVertex2f(len / 2, len / 2);
	glVertex2f(-len / 2, len / 2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void drawleg1(float x1,float y1,float len,float ele)
{
	//glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(x1, y1,0.0f);
	glVertex3f(x1-len,y1+ele,0.0f);
	glEnd();	

}
void drawleg2(float x1,float y1)
{
	//glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(x1, y1,0.0f);
	glVertex3f(x1-0.1,y1+0.01,0.0f);
	glEnd();	

}
void drawline(float i){
	//glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	//cout << line[i].line_x << " " << line[i].line_y  << " " << tri_x << " " << tri_y << endl;
	glVertex3f(0.0f, line[i].line_y-line[i].line_y_ref,0.0f);
	glVertex3f(0.0f, line[i].line_y-line[i].line_y_ref+0.1*box_len,0.0f);
	glEnd();	
}
void drawBall(float rad) {

	glBegin(GL_TRIANGLE_FAN);
	for(int i=0 ; i<360 ; i++) {
		glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
	}
	glEnd();
}

void drawTriangle() {

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}

// Initializing some openGL 3D rendering options
void initRendering() {

	glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   // Setting a background color
}

// Function called when the window is resized
void handleResize(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) {

	if (key == 27) {
		exit(0);     // escape key is pressed
	}
	if(over==2)
	{
		if(key=='s' || key=='S')
		{
			over=1;
			glutDisplayFunc(drawScene);
			glutIdleFunc(drawScene);

			glutTimerFunc(10, update, 0);
			glutTimerFunc(10, spider1, 0);
			glutTimerFunc(1000, generatered, 0);
		}
		if(key=='c')
		{
			over=3;
			glutDisplayFunc(insscene);
			glutIdleFunc(insscene);
		}
	}
	if(over==3)
	{
		if(key=='b')
		{
			over=2;
			glutDisplayFunc(startscene);
			glutIdleFunc(startscene);
		}
	}
	else
	{
		if(turn==1)
		{
			//cout << turn << endl;
			if(key==32){
				if(ti>=1000)
				{
					ti=0;
					ab a;
					a.line_x=tri_x;
					a.line_y=tri_y;
					a.line_z=0.0f;
					a.line_x_ref=tri_x;
					a.line_y_ref=tri_y;
					a.rot=theta;
					system("aplay laser1.WAV &");
					//		cout<<theta << " " << a.rot << " " << tri_x << " " << tri_y<< endl;
					line.push_back(a);
				}
				//cout << line.size() << endl;
				//st++;
				//	shoot();
			}
		}
		if(key==114)
		{
			turn=2;
		}
		if(key==103)
		{
			turn=3;
		}
		if(key==98)
		{
			turn=1;
		}
		if(key==112)
		{
			cout << turn << endl;
			if(cur==1)
			{

				system("aplay pause.wav &");
				prev=turn;
				turn=4;
				cur=0;
			}
			else
			{

					system("aplay pause.wav &");
				cur=1;
				turn=prev;
				glutTimerFunc(10, update, 0);
				glutTimerFunc(10, spider1, 0);
				glutTimerFunc(1000, generatered, 0);

			}
		}
	}
}

void handleKeypress2(int key, int x, int y) {
	if(turn==1){
		if (key == GLUT_KEY_LEFT)
		{
			if(tri_x>can_left)
				tri_x -= 0.05;
		}
		if (key == GLUT_KEY_RIGHT)
		{
			if(tri_x < can_right)
				tri_x += 0.05;
		}
		if (key == GLUT_KEY_UP)
		{
			if(theta<=60)
				theta += 15;
		}
		//tri_y += 0.1;
		if (key == GLUT_KEY_DOWN)
		{
			if(theta>=-60)
				theta -= 15;
		}
	}
	if(turn==2)
	{
		if (key == GLUT_KEY_LEFT)
		{
			if(x_red > red_left)
				x_red -= 0.05;
		}
		if (key == GLUT_KEY_RIGHT)
		{
			if(x_red <red_right)
				x_red += 0.05;
		}
	}

	if(turn==3)
	{
		if (key == GLUT_KEY_LEFT)
		{
			if(x_green > green_left)
				x_green -= 0.05;
		}
		if (key == GLUT_KEY_RIGHT)
		{
			if(x_green <green_right)
				x_green += 0.05;
		}
	}

	//tri_y -= 0.1;
}
void GetOGLPos(int x, int y)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
	mouseposx=posX*100/2;
	mouseposy=(posY*100)/2;
	mouseposz=posZ*100; 
}
void handlemouse_drag(int x,int y) 
{ 
	GetOGLPos(x,  y);
	if(click==1) 
	{ 
		if(turn==1 &&  mouseposx>can_left && mouseposx<can_right) 
		{ 
			tri_x=mouseposx; 
		} 
		else if(turn==3 && (mouseposx)<(box_len/2-radius/2) && mouseposx>(-box_len/2+radius/2) && mouseposx>green_left && mouseposx<green_right)
		{ 
			x_green=mouseposx; 
		} 
		else if(turn==2 && mouseposx<(box_len/2-radius/2) && mouseposx>(-box_len/2+radius/2) && mouseposx>red_left && mouseposx<red_right) 
		{ 
			x_red=mouseposx; 
		} 
	} 
	else if (click==2)
	{	
		turn=1;
		float s1=mouseposx-tri_x; 
		float s2=mouseposy-tri_y;
		float temp_angle=-atan(float(s1)/s2)*180/PI;
		if(temp_angle>=-60 && temp_angle<=60)
		{
			theta=-atan(float(s1)/s2)*180/PI;
		}

	}
}
void handleMouseclick(int button, int state, int x, int y) {
if(turn!=4)
		{
	if (state == GLUT_DOWN)
	{
		
		if (button == GLUT_LEFT_BUTTON)
		{	
			//		if(theta<=60)
			//			theta += 15;
			click=1;
			GetOGLPos(x,  y);
			float x1=tri_x-tank1_wid/2-tank3_wid-tank4_wid-tank1_wid/2;
			float x2=tri_x+tank1_wid/2+tank3_wid+tank4_wid+tank1_wid/2;
			float y1=tri_y-tank1_hei;
			float y2=tri_y+tank1_hei/2+tank2_hei;
			if(mouseposx>=x1 && mouseposx<=x2 && mouseposy>=y1 &&  mouseposy<=y2 )
				turn=1;
			float x11=x_green-radius;
			float x22=x_green+radius;	
			float y11=y_green-height;
			float y22=y_green+height;
			cout << mouseposx << endl;	
			if(mouseposx>=x11 && mouseposx<=x22 && mouseposy>=y11 &&  mouseposy<=y22 )
				turn=3;
			float x111=x_red-radius;
			float x222=x_red+radius;	
			float y111=y_red-height;
			float y222=y_red+height;
			cout << mouseposx << endl;	
			if(mouseposx>=x111 && mouseposx<=x222 && mouseposy>=y111 &&  mouseposy<=y222 )
				turn=2;

			//cout << x << " " <<  y << endl;
		}
		else if (button == GLUT_RIGHT_BUTTON)
		{
			//		if(theta>=-60)
			//			theta -= 15;
			click=2;
		}
	}
	else
	{
		turn=1;
	}
	}
}
