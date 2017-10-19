/***
    ２０１７年１０月１３日
    744663 Song Chen
***/
#include <stdio.h>
#include <math.h>
#include <handy.h>
#include <stdlib.h>

//色々な宣言
#define WINDOWSIZE 800.0
char English[]="I am the bone of my sword.Steel is my body,and fire is my blood.I have created over a thousand blades.Unknown to Death.Nor known to Life.Have withstood pain to create many weapons.Yet, those hands will never hold anything.So as I pray, Unlimited Blade Works.";
int e_num = (int)sizeof(English) - 1;
double x=0,y=0;//全ての座標

void circle(double r);
void circle_moji(double r);
void line(double a,double b,int c,int d);
void inori(double frequency,int r1,int r2);
//色
hgcolor HgHSV(double h, double s, double v)
{
    double r = v;
    double g = v;
    double b = v;
    if (s > 0.0) {
        h *= 6.0;
        int i = (int) h;
        double f = h - (double) i;
        switch (i) {
            default:
            case 0:
                g *= 1 - s * (1 - f);
                b *= 1 - s;
                break;
            case 1:
                r *= 1 - s * f;
                b *= 1 - s;
                break;
            case 2:
                r *= 1 - s;
                b *= 1 - s * (1 - f);
                break;
            case 3:
                r *= 1 - s;
                g *= 1 - s * f;
                break;
            case 4:
                r *= 1 - s * (1 - f);
                g *= 1 - s;
                break;
            case 5:
                g *= 1 - s;
                b *= 1 - s * f;
                break;
        }
    }

    return HgRGB(r, g, b);
}

int main() {
  HgOpen(WINDOWSIZE+10,WINDOWSIZE+10);
  HgSetFillColor(HG_BLACK);
  HgBoxFill(0,0,WINDOWSIZE+10,WINDOWSIZE+10,0);
  HgSetWidth(1.0);
  HgSetColor(HG_RED);
  circle_moji(-3.14);
  HgSetColor(HG_DRED);
  circle(-3.14);
  line(0,WINDOWSIZE/5,40,435);
  line(0.8,-WINDOWSIZE/5+32,170,440);
  line(-3,WINDOWSIZE/5+235,400,564);
  line(-0.8,-WINDOWSIZE/5+32,40,568);
  line(3,WINDOWSIZE/5+235,165,800);
  HgSleep(3);
  int r = HgAlert("祈りますか？5秒ぐらいw", "祈ります","祈ります！！","exit");
  if (r == 0) inori(0.01,2,3);
  if (r == 1) inori(0.01,3,4);
  if (r == 2) exit(0);
  HgClose();
  return 0;
}
//円
void circle(double r){
  for(;r<3.14;r+=0.001){
    y = cos(r)*(WINDOWSIZE/2-10);
    x = sin(r)*(WINDOWSIZE/2-10);
    HgBox(x/1.3+WINDOWSIZE/2, y/1.3 + WINDOWSIZE/2, 8.0, 8.0);
  }
}
//一番外の文字
void circle_moji(double r){
  int j=0;
  for(;r<3.14;r+=0.027){
    y = cos(r)*(WINDOWSIZE/2-10);
    x = sin(r)*(WINDOWSIZE/2-10);
    if(j < e_num) HgText(x+WINDOWSIZE/2, y + WINDOWSIZE/2,"%c",English[j]);
    j++;
  }
}
//星
 void line(double a,double b,int c,int d){
   for(x=-WINDOWSIZE/2 + c; x<WINDOWSIZE - d; x++) {
       y=a * x + b;
       HgBox(x + WINDOWSIZE/2, y + WINDOWSIZE/2, 6.0, 6.0);
     }
 }
//リサージュ
void inori(double frequency,int r1,int r2){
  doubleLayer new_lay;
  int new_window,lay;
  new_window = HgOpen(WINDOWSIZE+10,WINDOWSIZE+10);
  lay = HgWAddLayer(new_window);
  new_lay = HgWAddDoubleLayer(new_window);
  //background
  for(double i=-3.14;i<3.14;i+=0.001){
    x=sin(r1*i)*WINDOWSIZE/3;
    y=sin(r2*i)*WINDOWSIZE/3;
    HgWSetFillColor(lay,HgHSV(fabs(i/3.14), 1.0, 1.0));
    HgWBoxFill(lay,x + WINDOWSIZE/2, y + WINDOWSIZE/2, 1.0, 1.0,0);
  }
  //ボール
  for(int count=0;count < 3;count++){
    for(double i=-3.14;i<3.14;i+=frequency){
      lay = HgLSwitch(&new_lay);
      HgLClear(lay);
      x=sin(r1*i)*WINDOWSIZE/3;
      y=sin(r2*i)*WINDOWSIZE/3;
      HgWSetFillColor(lay,HgHSV(fabs(i/3.14), 1.0, 1.0));
      HgWCircleFill(lay,x + WINDOWSIZE/2, y + WINDOWSIZE/2, 10.0,0);
    }
  }
}
