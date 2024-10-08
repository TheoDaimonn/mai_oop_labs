#include "../include/figures.hpp"

namespace lab3 {

// Figure

// Square
Rectangle::Rectangle(const Point& point1, const Point& point2) {
    if (abs(point1.x - point2.x) <= EPS && abs(point1.y - point2.y) <= EPS ) {
        throw std::invalid_argument("Bad points.");
    }
    this->point1 = point1;
    this->point2 = point2;
}

Rectangle::Rectangle(const Rectangle &rect) {
    point1 = rect.point1;
    point2 = rect.point2;
}

Rectangle::Rectangle(Rectangle &&rect) {
    point1 = rect.point1;
    point2 = rect.point2;
}
    
Rectangle& Rectangle::operator=(const Rectangle &rect) {
    point1 = rect.point1;
    point2 = rect.point2;
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle &&rect) {
    point1 = rect.point1;
    point2 = rect.point2;
    return *this;
}

bool Rectangle::operator==(const Rectangle &other) {
    return point1 == other.point1 && point2 == other.point2;
}

Rectangle::operator double () const {
    return abs(point1.y - point2.y) * abs(point1.x - point2.x);
}

Point Rectangle::geometricCenter() const {
    return Point::mid(point1, point2);
}

std::ostream& operator<<(std::ostream &stream, const Rectangle &rect) {
    double deltaX = rect.point2.x - rect.point1.x, deltaY = rect.point2.y - rect.point1.y;
    stream << "Rectangle[ " << rect.point1 << " " << rect.point1 + Point{deltaX, 0} << " " <<
              rect.point1 + Point{0, deltaY} << " " << rect.point2 << " ]";
    return stream;
}

std::istream& operator>>(std::istream &stream, Rectangle &rect) {
    Point p1, p2;
    stream >> p1 >> p2;
    rect = Rectangle(p1, p2);
    return stream;
}



// Triangle

Trapezoid::Trapezoid(const Point& point1, const Point& point2, const Point& point3, const Point& point4) {
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    this->point4 = point4;
}

Trapezoid::Trapezoid(const Trapezoid &tr) {
    point1 = tr.point1;
    point2 = tr.point2;
    point3 = tr.point3;
    point4 = tr.point4;}

Trapezoid::Trapezoid(Trapezoid &&tr) {
    point1 = tr.point1;
    point2 = tr.point2;
    point3 = tr.point3;
    point4 = tr.point4;
}

Trapezoid& Trapezoid::operator=(const Trapezoid &tr) {
    point1 = tr.point1;
    point2 = tr.point2;
    point3 = tr.point3;
    point4 = tr.point4;
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid &&tr) {
    point1 = tr.point1;
    point2 = tr.point2;
    point3 = tr.point3;
    point4 = tr.point4;    
    return *this;
}
    
bool Trapezoid::operator==(const Trapezoid &other) {
    return point1 == other.point1 && point2 == other.point2 && point3 == other.point3 && point4 == other.point4;
}

Trapezoid::operator double () const {
    return 0.5 * std::abs(point1.x * point2.y + point2.x * point3.y +point3.x * point4.y +point4.x * point1.y - (point1.y * point2.x + point2.y * point3.x + point3.y * point4.x + point4.y * point1.x));
}

Point Trapezoid::geometricCenter() const {;
    return (point1 + point2 + point3 + point4) * 0.25;
}

std::ostream& operator<<(std::ostream& stream, const Trapezoid& tr) {
    stream << "Trapezoid[ " 
           << tr.point1 << " " 
           << tr.point2 << " " 
           << tr.point3 << " " 
           << tr.point4 << " ]";
    return stream;
}

std::istream& operator>>(std::istream &stream, Trapezoid &tr) {
    Point p1, p2, p3, p4;
    int orientation;
    stream >> p1 >> p2 >> p3 >> p4;
    tr = Trapezoid(p1, p2, p3, p4);
    return stream;
}

// Square

Square::Square(const Point& point1, const Point& point2) {
    if (abs(abs(point1.x - point2.x) - abs(point1.y - point2.y)) >= EPS) {
        throw std::invalid_argument("Bad points.");
    }
    this->point1 = point1;
    this->point2 = point2;
}

Square::Square(const Square &sq) {
    point1 = sq.point1;
    point2 = sq.point2;
}

Square::Square(Square &&sq) {
    point1 = sq.point1;
    point2 = sq.point2;
}
    
Square& Square::operator=(const Square &sq) {
    point1 = sq.point1;
    point2 = sq.point2;
    return *this;
}

Square& Square::operator=(Square &&sq) {
    point1 = sq.point1;
    point2 = sq.point2;
    return *this;
}

bool Square::operator==(const Square &other) {
    return point1 == other.point1 && point2 == other.point2;
}

Square::operator double () const {
    return std::pow(Point::distance(point1, point2), 2) / 2;
}

Point Square::geometricCenter() const {
    return Point::mid(point1, point2);
}

std::ostream& operator<<(std::ostream &stream, const Square &sq) {
    double deltaX = sq.point2.x - sq.point1.x, deltaY = sq.point2.y - sq.point1.y;
    stream << "Square[ " << sq.point1 << " " << sq.point1 + Point{deltaX, 0} << " " <<
              sq.point1 + Point{0, deltaY} << " " << sq.point2 << " ]";
    return stream;
}

std::istream& operator>>(std::istream &stream, Square &sq) {
    Point p1, p2;
    stream >> p1 >> p2;
    sq = Square(p1, p2);
    return stream;
}

} 