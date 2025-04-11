#include <iostream>

class Point {
    protected:
        int x, y;
    public:
        Point(){
            printf("Point()\n");
            x = 0;
            y = 0;
        };
        Point(int x, int y){
            printf("Point(int x, int y)\n");
            this->x = x;
            this->y = y;
        };
        Point(const Point &p){
            printf("Point(const Point &p)\n");
            x = p.x;
            y = p.y;
        };
        ~Point(){
            printf("%d, %d\n", x, y);
            printf("~Point()\n");
        };
        void move(int dx, int dy){
            printf("Point moved by %d, %d, new coordinates: %d, %d\n", dx, dy, x + dx, y + dy);
            x = x + dx;
            y = y + dy;
        };
        void reset();
};

void Point::reset(){
    printf("Reset Point\n");
    x = 0;
    y = 0;
};

class ColoredPoint: public Point {
    protected:
        int color;
    public:
        ColoredPoint() : Point(){
            printf("ColoredPoint()\n");
            color = 0;
        };
        ColoredPoint(int x, int y, int color) : Point(x, y){
            printf("ColoredPoint(int x, int y, int color)\n");
            this->color = color;
        };
        ColoredPoint(const ColoredPoint &p){
            printf("ColoredPoint(const ColoredPoint &p)\n");
            color = p.color;
            x = p.x;
            y = p.y;
        };
        ~ColoredPoint(){
            printf("%d, %d, color = %d\n", x, y, color);
            printf("~ColoredPoint()\n");
        };
        void change_color(int new_color){
            color = new_color;
        };
};

int main(){
    {
        // Статистически созданные объекты
        Point p;
        Point p2(10, 20);
        Point p3(p2);
        //
    };

    // Динамически созданные объекты
    Point *p4 = new Point;
    Point *p5 = new Point(30, 40);
    Point *p6 = new Point(*p5);

    delete p4;
    delete p5;
    delete p6;
    //

    // Перемещение и сброс объекта
    Point *p7 = new Point(1, 2);
    p7->move(10, 10);
    p7->reset();

    delete p7;
    //

    //Класс-наследник
    ColoredPoint *p8 = new ColoredPoint(1, 2, 42);
    delete p8;
    //

    system("pause");
    return 0;
}