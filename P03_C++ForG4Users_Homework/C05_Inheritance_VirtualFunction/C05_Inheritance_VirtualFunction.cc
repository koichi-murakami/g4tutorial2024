//******************************************************************************
// クラス継承と仮想関数：　C05_Inheritance_VirtualFunction.cc 
//******************************************************************************
// [自習の進め方]
//    1) 以下のプログラムに書かれたコメントを順次読む
//    2) コメント部分に[問]と書かれた行では、そこに書かれた指示に従い、'?'文字部分を
//       正しい文に置き換える。
//    3) 全ての[問]に回答を終了したら、以下のc++コマンドを実行する
//         % C05_Inheritance_VirtualFunction.cc 
//       　　　　　[注]　使用c++のversionが古い場合、'-std=c++11'のオプションをつける
//    4) コンパイラ エラーが生じたら、エラー情報からコードを修正する
//    5) エラーが無くなり、実行ファイル（a.out）が作られたら、それを以下のように実行
//         % a.out
//       実行すると、main.ccに書いた'cout'の結果が出る
//    6) 適当なデバッグ文をコード中に挿入、各文の動作をチェックすることを薦める
//
//    (注)　自習問題の解答は以下のファイルにある：
//           ../Z_AnswersDir/C05_Inheritance_VirtualFunction_Ans.cc
//******************************************************************************

#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// [課題 1]  Baseクラス'Shape_2P'を作る - 2つのパラメータで表現できる図形クラス
//-----------------------------------------------------------------------------
    
????? Shape_2P {                          // [問] Shape_2Pクラス宣言
  ???????                                 // [問] publicメンバー（データと関数）の定義
    string shape(){ return name; }        // 図形名をstring型で返す関数の定義
    double area(){ return 0.; }           // 面積をdouble型で返す関数の定義

  ??????????                              // [問] protectedメンバー（データと関数)の定義
    double sizeX, sizeY;                  // 図形サイズの二つのパラメター値
    string name = "Shape_2P";             // 図形の名前
    const double pi = 3.14159265;         // pi 定数値
};


//-----------------------------------------------------------------------------
// [課題 2]  Rectangular クラスを作る - Shape_2Pを継承し、constructorとarea()関数を実装
//-----------------------------------------------------------------------------
                    
class Rectangular ? ?????? Shape_2P {     // [問] Shape_2Pをpublic継承しRectangularを宣言
  public:                                 // publicメンバー（データと関数）の定義 
    ???????????( double x, double y ) {   // [問] Recutangularのconstructorの定義
      sizeX = x; sizeY = y;
      name = "Rectangular";
    }
    double ????() { return sizeX * sizeY; } // [問] area関数の再定義
};


//-----------------------------------------------------------------------------
// [課題 3]  Ellipse クラスを作る - Shape_2Pを継承し、constructorとarea()関数を実装
//-----------------------------------------------------------------------------

class Ellipse ? ?????? Shape_2P {          // [問] Shape_2Pをpublic継承しEllipseを宣言
  public:                                  // publicメンバー（データと関数）の定義 
    ???????( double x, double y ) {        // [問] Ellipseのconstructorの定義
      sizeX = x; sizeY = y; 
      name = "Ellipse";
    } 
    double ????(){ return sizeX * sizeY * pi/4.0; } // [問] area関数の再定義
};


//-----------------------------------------------------------------------------
// [課題 4]  Rectangular / Ellipse クラスを使う
//-----------------------------------------------------------------------------

int main() {
  Shape_2P pict{};                           // 'Shape_2P'のオブジェクトを作成
  cout << "Shape: " << pict.shape() << endl; // 'pict'が持つshape()関数へアクセス
  cout << "Area: "  << pict?area()  << endl; // [問] 'pict'が持つarea()関数へアクセス

  Rectangular rect{ 3.0, 4.0 };              // 'Rectangular'のオブジェクトを作成
  cout << "Shape: " << rect.shape() << endl; // 'rect'が持つshape()関数へアクセス
  cout << "Area: "  << rect?area()  << endl; // '[問] 'rect'が持つarea()関数へアクセス 

  Ellipse elps{ 5.0, 6.0 };                  // 'Ellipse'のオブジェクトへを作成
  cout << "Shape: " << elps.shape() << endl; // 'elps'が持つshape()関数へアクセス
  cout << "Area: "  << elps?area()  << endl; // [問] 'elps'が持つarea()関数へアクセス
}
