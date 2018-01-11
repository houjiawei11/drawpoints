#include <QPainter>
#include <QImage>
#include <QDebug>

#include <vector>

#include <iostream>
using namespace std;

struct corr{
  double x,y,z;
};

vector<corr> array;

int main(){
  //请按照corr的格式向array填入数据，其坐标值范围为0.0~1500.0 
  QImage image(1500, 1500, QImage::Format_ARGB32);
  QPainter painter(&image);
  image.fill(qRgba(255, 255, 255, 255));
  painter.setPen(qRgb(0,0,0));
  for(vector<corr>::iterator itr=array.begin();itr!=array.end();itr++){
    QPointF p((*itr).x, (*itr).y);
    painter.drawPoint(p);
  }
  image.save("drawpoint.png");
  return 0;
}