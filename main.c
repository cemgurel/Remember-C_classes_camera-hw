#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
 
using namespace std;
 
class Camera { /* Camera is located (0,0); its direction is (directionX,directionY); 
					it can see the angle wide; it can see until distance far;*/
   public:
   	  Camera(double x_, double y_, double angle_, double distance_){  directionX=x_;  directionY=y_; angle=angle_; distance= distance_;}  

		bool viewFieldControl( double xt , double yt ){
			if (isItInTheViewingDistance(xt,yt)==true && isItInTheViewingAngle(xt,yt)==true){
				cout<<"Object is in the field of view"<<endl;
			return true;
			}
			else cout<<"Object is not in the field of view"<<endl;
				return false;	
		}
		
		double getangle(){
			cout<<angle<<endl;
			return angle;
			
		}

   private:
		double directionX; double directionY;
		double angle; double distance;
		
		bool isItInTheViewingDistance(double posx,double posy) {
			if (distance >= sqrt( posx*posx + posy*posy )){
				return true;
			}			
			else return false;
		}
		
			bool isItInTheViewingAngle (double xt,double yt) {double xc= directionX; double yc= directionY; 
			if (angle/2 <= ((180/M_PI) * acos( (xc*xt+yc*yt)/( sqrt(xc*xc + yc*yc )+sqrt(xt*xt+yt*yt))))){
				return true;
			}			
			else return false;
		}
		
};
 
 class Tracking { /* Tracked object is located position (positionX,positionY) */
   public:
      Tracking(double positionX_, double positionY_){ positionX=positionX_; positionY=positionY_; } 
	    double getX(){
	  	return positionX;
	  }
		double getY(){
	  	return positionY;
	  }
	  
   private:
      double positionX;
      double positionY;
};


int main() {
	srand(time(0));

   Camera C(1,1,25,60);

for (int i = 0; i< 20 ; i++ ){
	int tranckingX= rand()%200 - 100;
	int tranckingY= rand()%200 - 100;
   Tracking T(tranckingX,tranckingY);
   cout<<"getX: "<< T.getX()<<"   getY: "<<T.getY()<<endl;
   cout << " viewFieldControl : "<< C.viewFieldControl(T.getX(),T.getY()) <<endl;
 }
   return 0;
}
