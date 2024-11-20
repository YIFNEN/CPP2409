#include <iostream>
using namespace std;

class Shape{
    int x, y;
public:
    Shape(){
        cout << "shape 생성자()" <<endl;
    }
    Shape(int xloc, int yloc) : x{xloc}, y{yloc} {
        cout << "shape 생성자(xloc, yloc)" <<endl;
    }

    ~Shape(){
        cout << "shape 소멸자()" << endl;
    }
};

class Rectangle : public Shape{
    int width, height;
public:
    Rectangle(int x, int y, int w, int h) : Shape(x,y){
        width = w;
        height = h;
        cout << "Rectangle 생성자(x, y, w, h)" << endl;
    }

    ~Rectangle(){
        cout <<"Rectangle 소멸자()" << endl;
    }
};

int main(){
    Rectangle r(0,0,100,100);
    return 0;
}