#define  FREEGLUT_STATIC

#include <GL/glut.h> // ライブラリ用ヘッダファイルの読み込み

void display0();
void display1();
void display2();
void display3();
void display4();

// メインプログラム
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitWindowSize(400, 400);  // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display0);       // 表示関数を指定
	glutMainLoop();                 // イベント待ち
	return 0;
}