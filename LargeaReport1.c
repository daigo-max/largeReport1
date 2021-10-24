// 線形代数2021/10/24 大レポート ニュートン法アルゴリズム
#include<stdio.h>
#include<math.h>

//-----定義-----//
#define eps 1.0e-8 //とても小さい数(10の-8乗)

double f (double x) {       //f(x)の定義
    return x*x*x + 3*x + 2; //ここをいじってf(x)を変えよう！
}

double fd (double x) {      //f'(x)の計算
    return (f(x + eps) - f(x)) / eps;
}

//-----メインプログラム-----//
int main () {
    //-----下準備-----//
    int n;
    n = 0;      //計算回数
    double DELTA;
    double x;
    x = 20;     //スタートに使う適当なxの値
    double value_f;     //f(x)の途中結果の確認

    //-----繰り返し計算-----//
    do {
        DELTA = -f(x) / fd(x);
        x = x + DELTA;
        value_f = f(x);
        n++;
        printf("[%d回目]x = %f, f(x) = %f\n", n, x, value_f);   //n回目の計算結果表示
    } while (fabs(DELTA) > eps && n <= 100);    //繰り返し条件

    //-----解の出力-----//
    if (n >= 100) {
        printf("解は見つかりませんでした。近似値は x = %f です。計算回数 %d 回\n", x, n);
    } else {
        printf("解は x = %f です。計算回数 %d 回\n", x, n);
    };
}