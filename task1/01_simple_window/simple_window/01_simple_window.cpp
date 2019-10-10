#define _USE_MATH_DEFINES
#include <vector>
#include <complex>
#include <GL/glut.h> // ライブラリ用ヘッダファイルの読み込み

#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef complex<double> P;

// 表示部分をこの関数で記入
void display(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT);      // 画面消去

	glColor3d(0.0, 0.0, 0.0);          // 色指定(R,G,B)で0～1まで

	const int KochD = 3;               // 計算するステップ数
	vector<P > vecs[KochD + 1];
	rep(i, 4) vecs[0].push_back(polar(1.0, -i * M_PI * 2 / 3));
	// 初期値の正三角形を囲む4点(1個目(始点)と4個目(終点)は同じ点を表す)
	// polar(r,t)は半径r、角度tの複素数を表す。=(r*cos(t), r*sin(t))

	rep(i, KochD) {
		vecs[i].reserve(vecs[i].size() * 4 - 3);         // 高速化のために配列メモリの事前確保(任意)
		rep(j, vecs[i].size() - 1) {
			P v = (vecs[i][j + 1] - vecs[i][j]) / 3.0;   // 2頂点の差から、その間の線分ベクトルを求める
			vecs[i + 1].push_back(vecs[i][j]);
			vecs[i + 1].push_back(vecs[i][j] + v);
			vecs[i + 1].push_back(vecs[i][j] + v + v * polar(1.0, M_PI / 3));   // 60度回転
			vecs[i + 1].push_back(vecs[i][j] + v * 2.0);
		}
		vecs[i + 1].push_back(vecs[i][vecs[i].size() - 1]);
	}

	glBegin(GL_LINE_STRIP);
	for (auto& p : vecs[KochD]) glVertex2d(real(p), imag(p));
	glEnd();
	glFlush(); // 画面出力
}

// メインプログラム
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitWindowSize(400, 400);   // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定
	glutMainLoop();                 // イベント待ち
	return 0;
}