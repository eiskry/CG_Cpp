#define FREEGLUT_STATIC

// mouse_click.c   マウスボタンでクリックした位置を表示

#include <GL/glut.h>

int px = 200, py = 150; // 初期位置

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(px, py);  // 点を表示
	glEnd();
	glFlush();
}

void init(void) {
	glClearColor(1., 1., 1., 1.); // 背景は白
	glColor3f(0., 0.2, 1.);        // 青色で描く
	glPointSize(11.);           // 点の大きさは11画素
}

void mouse(int button, int status, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:       // マウス左ボタンが 
		if (status == GLUT_DOWN) { // 押された場合
			px = x;  py = y;         // マウス座標を(px,py)に取得
		} break;
	default:  break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glLoadIdentity();
	// マウスの座標系はy=0はウィンドウの一番上の位置
	// マウス座標のyの正方向は下方向であり、
	// yの範囲の指定は ウィンドウの下、上の順で指定する
	glOrtho(0., (float)w, (float)h, 0., -10., 10.);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(400, 300);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);   // マウスボタンが押されたときの割込処理関数を指定
	init();
	glutMainLoop();
	return 0;
}