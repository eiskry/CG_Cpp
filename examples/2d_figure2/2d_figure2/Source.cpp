#define FREEGLUT_STATIC

// gradation.c  グラデーション表示と矢印キーの割り込み処理
// 同じ矢印キーを何度か押すとグラデーションが巡回的に変化する

#include <GL/glut.h> // GLUTライブラリ

float co[][3] = { 1.,0.,0., 1.,1.,0., 0.,1.,0., 0.,1.,1., 0.,0.,1., 1.,0.,1. };
float a = 0.8, b = 0.693, c = 0.4;
int n = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3fv(co[n]);       glVertex2f(0., a);
	glColor3fv(co[(n + 1) % 6]); glVertex2f(-b, c);
	glColor3f(1., 1., 1.);       glVertex2f(0., 0.);

	glColor3fv(co[(n + 1) % 6]); glVertex2f(-b, c);
	glColor3fv(co[(n + 2) % 6]); glVertex2f(-b, -c);
	glColor3f(1., 1., 1.);       glVertex2f(0., 0.);

	glColor3fv(co[(n + 2) % 6]); glVertex2f(-b, -c);
	glColor3fv(co[(n + 3) % 6]); glVertex2f(0., -a);
	glColor3f(1., 1., 1.);       glVertex2f(0., 0.);

	glColor3fv(co[(n + 3) % 6]); glVertex2f(0., -a);
	glColor3fv(co[(n + 4) % 6]); glVertex2f(b, -c);
	glColor3f(1., 1., 1.);       glVertex2f(0., 0.);

	glColor3fv(co[(n + 4) % 6]); glVertex2f(b, -c);
	glColor3fv(co[(n + 5) % 6]); glVertex2f(b, c);
	glColor3f(1., 1., 1.);       glVertex2f(0., 0.);

	glColor3fv(co[(n + 5) % 6]); glVertex2f(b, c);
	glColor3fv(co[n]);       glVertex2f(0., a);
	glColor3f(1., 1., 1.);       glVertex2f(0., 0.);
	glEnd();
	glFlush();
}

void init(void)
{
	glClearColor(1., 1., 1., 1.);
}

void special_key(int key, int x, int y)
//   SHIFTキーやCTRLキーを併用する場合はコメント行を参照
{
	//  int SHIFT=0, CTRL=0;
	//	if( glutGetModifiers() == GLUT_ACTIVE_SHIFT ) SHIFT = 1;
	//	if( glutGetModifiers() == GLUT_ACTIVE_CTRL ) CTRL = 1;
	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_UP:
		n++; if (n > 5) n = 0; break;
	case GLUT_KEY_RIGHT:
	case GLUT_KEY_DOWN:
		n--; if (n < 0) n = 5; break;
	default: break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(300, 300);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(special_key); // 矢印キーによる割り込み処理関数を指定
	init();
	glutMainLoop();
	return 0;
}