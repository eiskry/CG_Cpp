#define  FREEGLUT_STATIC

#include <GL/glut.h> // ライブラリ用ヘッダファイルの読み込み

// 表示部分をこの関数で記入
void display3(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT);     // 画面消去

	glColor3d(0.0, 0.0, 0.0);   // 色指定(R,G,B)で0～1まで
	glBegin(GL_LINES);
	for (int i = 0; i < 10; i++) {
		glVertex2d(i * 0.1 - 0.5, 0.5);
		glVertex2d(i * 0.1 - 0.5, -0.5);
	}
	glEnd();

	glFlush(); // 画面出力
}
