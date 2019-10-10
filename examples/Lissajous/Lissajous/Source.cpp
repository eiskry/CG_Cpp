#define FREEGLUT_STATIC

// curve_disp.c  リサージュ(Lissajous)図形 
// 曲線を描くときは、短い折れ線を描く

#include <math.h>      // sin(), cos()
#include <GL/glut.h>

double a, b, x[3], y[3], rad = 0.01745329252;  // π/180

void display(void)
{
	int i, k0, k1, k2;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);       // 折れ線を生成する
	glVertex2d(x[0], y[0]);    // 最初の2点で折れ線を描く
	glVertex2d(x[1], y[1]);
	for (i = 0; i <= 180; i++) { // 漸化式で次々と点を求めて折れ線を描く
		k0 = i % 3;                 // %演算子は iを3で割ったときの余り
		k1 = (i + 1) % 3;             // k0, k1, k2 の値は、順に 0, 1, 2 を繰り返す
		k2 = (i + 2) % 3;
		x[k2] = a * x[k1] - x[k0];    // 漸化式： x[i+2] = a*x[i+1] - x[i]
		y[k2] = b * y[k1] - y[k0];
		glVertex2d(x[k2] * .99, y[k2] * .99);
	}
	glEnd();                      // 折れ線生成ここまで
	glFlush();                    // 画面に出力
}

void init(void)
{
	double p1 = 6., p2 = 8.;            // 2種類の振動の周期
	glClearColor(1., 1., 1., 1.);
	glColor3f(1., 0.4, 0.);
	glLineWidth(2.);
	a = 2. * cos(rad * p1);             // 漸化式の係数(x座標)
	b = 2. * cos(rad * p2);             // 漸化式の係数(y座標)
	x[0] = 0.;  x[1] = sin(rad * p1); // 最初の2点のx座標
	y[0] = 0.;  y[1] = sin(rad * p2); // 最初の2点のy座標
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}