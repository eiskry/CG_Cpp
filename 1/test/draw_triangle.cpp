#define  FREEGLUT_STATIC

#include <GL/glut.h> // ライブラリ用ヘッダファイルの読み込み

// 表示部分をこの関数で記入
void display1(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT);     // 画面消去

	glColor3d(0.0, 0.0, 1.0);   // 色指定(R,G,B)で0～1まで
	glBegin(GL_LINE_LOOP);      // 描画するものを指定
	glVertex2d(-0.9, -0.8); // 頂点位置の指定(1つめ)
	glVertex2d(0.9, -0.8); // 頂点位置の指定(2つめ)
	glVertex2d(0.0, 0.8); // 頂点位置の指定(3つめ) 
	glEnd();

	glFlush(); // 画面出力
}

