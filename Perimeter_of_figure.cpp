

class Figure{
public:

    virtual int Perimeter() const = 0;
    virtual ~Figure(){}
};

class Triangle: public Figure{
private:
    int a;
    int b; 
    int c;
public:

    Triangle(int A, int B, int C): a(A), b(B), c(C){}

    int Perimeter() const override{
        return a+b+c;
    }
}; 

class Rectangle : public Figure{
private:
    int a;
    int b; 
public:

    Rectangle (int A, int B): a(A), b(B){}

    int Perimeter() const override{
        return 2*(a+b);
    }
}; 

// ----------------------------------------------------------------------------------------------------------------------------------

#include <vector>
#include <iostream>

int main() {
    std::vector<Figure*> figures;

    std::string type;

    while (std::cin >> type) {
        if (type == "Triangle") {
            int a, b, c;
            std::cin >> a >> b >> c;
            figures.push_back(new Triangle(a, b, c));
        } else if (type == "Rectangle") {
            int a, b;
            std::cin >> a >> b;
            figures.push_back(new Rectangle(a, b));
        }
    }

    for (Figure* f : figures) {
        std::cout << f->Perimeter() << "\n";
    }

    for (Figure* f : figures) {
        delete f;
    }
}