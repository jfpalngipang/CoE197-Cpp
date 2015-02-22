/***********************************
* Author: Jan Franz Palngipang
* Date: February 19, 2015
************************************/

#include <iostream>
#include <cmath>

using namespace std;

class Point {
    private:
        double x, y;

    public:
        static int n;
        Point();
        Point(double, double);
        ~Point() { n--; cout << "Destroying... " << n << endl; };
        void setX(const double new_x);
        void setY(const double new_y);
        double getX();
        double getY();
        void toPolar();
        void toCartesian();


};
int Point::n = 0;


//operator overloading
istream &operator >> (istream &is, Point &p) {
    string temp_x, temp_y;
    string temp;
    string delimiter = ",";
    is >> temp;
    temp_x = temp.substr(0, temp.find(delimiter));
    temp.erase(0, temp.find(delimiter) + delimiter.length());
    temp_y = temp;
    p.setX(stod(temp_x));
    p.setY(stod(temp_y));
}


Point::Point () {
    x = 0;
    y = 0;
    n=n+1;
}

Point::Point (double a, double b) {
    x = a;
    y = b;
    n=n+1;

}
double Point::getX() {
    //return this->x;
    return this->x;
}
double Point::getY() {
    return this->y;
}
void Point::setX(const double new_x) {
    this->x = new_x;
}
void Point::setY(const double new_y){
    this->y = new_y;
}

void Point::toPolar() {
    double radius, theta;
    radius = sqrt((pow(x, 2) + pow(y, 2)));
    theta = atan(y/x);
    x = radius;
    y = theta;
}
void Point::toCartesian() {
    double radius, theta;
    radius = x;
    theta = y;
    x = radius*cos(theta);
    y = radius*sin(theta);
}

inline double getShortestDistance(double x1, double y1, double x2, double y2) {
    double distance;
    distance = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    cout << distance << endl;

}
int main() {
    /*
    Point p(1,2);
    cout << p.getX() << endl;
    cin >> p;
    cout << p.getX() << endl;
    cout << p.getY() << endl;
*/
    Point * p_10 = new Point[10];
    int i = 0;

    //Input 10 points
    while (i < 10) {
        cin >> p_10[i];
        i++;
    }

    //Convert 10 cartesian points to polar
    i = 0;
    while (i<10) {
        p_10[i].toPolar();
        i++;
    }
    //Print 10 polar coordinates
    i = 0;

    while(i<10) {
        cout << p_10[i].getX() << "," << p_10[i].getY() << endl;
        i++;
    }
    //convert back to Cartesian coordinates
    i = 0;
    while(i<10) {
        p_10[i].toCartesian();
        i++;
    }

    i = 0;

    while (i<10) {
        cout << p_10[i].getX() << "," << p_10[i].getY() << endl;
        i++;
    }

    i = 0;
    int j = 0;

    while (i<9) {
        j = i+1;
        getShortestDistance(p_10[i].getX(), p_10[i].getY(), p_10[j].getX(), p_10[j].getY());
        i++;
    }

    delete[] p_10;



   //Point p_10[10];
    return 0;
}
/***********************************
* End of Program
************************************/