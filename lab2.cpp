#include <iostream>
using namespace std;

class Point {
    protected:
        int x, y;
    public:
        Point(){
            cout << "Point()\n";
            x = 0;
            y = 0;
        };
        Point(int x, int y){
            cout << "Point(int x, int y)\n";
            this->x = x;
            this->y = y;
        };
        Point(const Point &p){
            cout << "Point(const Point &p)\n";
            x = p.x;
            y = p.y;
        };
        ~Point(){
            cout << x << " " << y << "\n";
            cout << "~Point()\n";
        };
        void move(int dx, int dy){
            cout << "Point moved by " << dx << ", " << dy <<", new coordinates: " << x + dx << ", " << y + dy << "\n";
            x = x + dx;
            y = y + dy;
        };
        void reset();
};

void Point::reset(){
    cout << "Reset Point\n";
    x = 0;
    y = 0;
};

class ColoredPoint: public Point {
    protected:
        int color;
    public:
        ColoredPoint() : Point(){
            cout << "ColoredPoint()\n";
            color = 0;
        };
        ColoredPoint(int x, int y, int color) : Point(x, y){
            cout << "ColoredPoint(int x, int y, int color)\n";
            this->color = color;
        };
        ColoredPoint(const ColoredPoint &p){
            cout << "ColoredPoint(const ColoredPoint &p)\n";
            color = p.color;
            x = p.x;
            y = p.y;
        };
        ~ColoredPoint(){
            cout << x << ", " << y << ", color = " << color << "\n";
            cout << "~ColoredPoint()\n";
        };
        void change_color(int new_color){
            color = new_color;
        };
};

class Section {
    protected:
        Point *p1;
        Point *p2;
    public:
        Section(){
            cout << "Section()\n";
            p1 = new Point;
            p2 = new Point;
        };
        Section(int x1, int y1, int x2, int y2){
            cout << "Section(int x1, int y1, int x2, int y2)\n";
            p1 = new Point(x1, y1);
            p2 = new Point(x2, y2);
        };
        Section(const Section &s){
            cout << "Section(const Section &s)\n";
            p1 = new Point(*(s.p1));
            p2 = new Point(*(s.p2));
        };
        ~Section(){
            delete p1;
            delete p2;
            cout << "~Section()\n";
        }
};

int main(){
    {
        cout << "\n---------Static objects---------\n\n";
        // Статистически созданные объекты
        Point p;
        Point p2(10, 20);
        Point p3(p2);
        //
    };

    cout << "\n---------Dynamic objects---------\n\n";

    // Динамически созданные объекты
    Point *p4 = new Point;
    Point *p5 = new Point(30, 40);
    Point *p6 = new Point(*p5);

    delete p4;
    delete p5;
    delete p6;
    //

    cout << "\n---------Move and reset object---------\n\n";

    // Перемещение и сброс объекта
    Point *p7 = new Point(1, 2);
    p7->move(10, 10);
    p7->reset();

    delete p7;
    //

    cout << "\n---------Inheritance---------\n\n";

    //Класс-наследник
    ColoredPoint *p8 = new ColoredPoint(1, 2, 42);
    delete p8;
    //

    cout << "\n---------Sections---------\n\n";

    // Отрезки
    Section *s1 = new Section;
    Section *s2 = new Section(*s1);

    delete s1;
    delete s2;
    //

    return 0;
}