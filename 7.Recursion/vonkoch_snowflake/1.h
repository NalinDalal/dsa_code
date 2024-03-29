#define _USE_MATH_DEFINES
#include <cmath>

class vonKoch{
public:
	vonKoch(int,int,CDC*);
	void snowflake();
private:
	double side,angle;
	int level;
	CPoint currPt,pt;
	CDC* pen;
	
	void right(double x){
		angle+=x;
	}
	void left(double x){
		angle-=x;
	}
	void drawFourLines(double side,int level);
};

vonKoch::vonKoch(int s,int lvl, CDC *pDC){
	pen=pDC;
	currPt.x=200;
	currPt.y=100;
	angle=0.0;
	side=s;
	level=lvl;
}

void vonKoch::drawFourLines(double side,int level){
	//argument to sin() and cos() angles
	//specified in radian i.e. coefficient PI/180 is necessary
	if(level==0){
		pt.x=int(cos(angle*M_PI/180)*side)+currPt.x;
		pt.y=int(sin(angle*M_PI/180)*side)+currPt.y;
		pen->LineTo(pt);
		currPt.x=pt.x;
		currPt.y=pt.y;
	}
	else{
		drawFourLines(side/3,level-1);
		left(60);
		drawFourLines(side/3,level-1);
		right(120);
		drawFourLines(side/3,level-1);
		left(60);
		drawFourLines(side/3,level-1);
	}
}

void vonKoch::snowflake(){
	for(int i=1;i<=3;i++){
		drawFourLines(side, level);
		right(120);
	}
}
