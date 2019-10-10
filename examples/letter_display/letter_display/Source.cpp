#define FREEGLUT_STATIC

// char_disp0.c   英数字の表示
//（ラスター文字（ビットマップフォント)とベクター文字（アウトラインフォント））

#include <GL/glut.h>

void strout(float x, float y, char* str) {
	void* font = GLUT_BITMAP_TIMES_ROMAN_24;
	glRasterPos2f(x, y);
	while (*str) glutBitmapCharacter(font, *str++);
}

void display(void)
{
	char* ptr, * ft ="Outline font";

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1., 0., 0.);            // 赤はビットマップフォント
	strout(-0.4, 0.3,"Bitmap font");

	glColor3f(0., 0., 1.);            // 青はアウトラインフォント
	glTranslatef(-0.4, -0.4, 0.);
	glScalef(0.001, 0.001, 1.);
	ptr = ft;
	while (*ptr)glutStrokeCharacter(GLUT_STROKE_ROMAN, *ptr++);
	glFlush();                        // 画面に出力
}

int main(int argc, char* argv[])    // 主関数(プログラムのスタート)
{
	glutInit(&argc, argv);            // グラフィック初期化
	glutInitDisplayMode(GLUT_RGBA);   // 画素毎に色を指定する描画モード
	glutCreateWindow(argv[0]);        // 描画ウィンドウ作成
	glutDisplayFunc(display);         // 描画関数指定
	glClearColor(1.0, 1.0, 1.0, 1.0); // 背景色指定(白)
	glLineWidth(2.);                  // 線幅
	glutMainLoop();                   // 割り込み待ち
	return 0;
}