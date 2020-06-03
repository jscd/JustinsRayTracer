#include "utility/vec3.h"


#include <cmath>

using namespace jrt;

vec3::vec3(double x, double y, double z)
            : _x(x), _y(y), _z(z) {
    _setLength();
}

vec3::vec3(double all) : vec3(all, all, all) { }

double vec3::x() const { return _x; }
double vec3::y() const { return _y; }
double vec3::z() const { return _z; }

double vec3::operator[](unsigned int idx) const {
    switch(idx){
    case 0:
        return _x;
    case 1:
        return _y;
    case 2:
        return _z;
    default:
        throw std::out_of_range("Index " + std::to_string(idx) + " is out of range!");
    }
}

vec3 vec3::operator-() const {
    return vec3(-_x, -_y, -_z);
}

vec3& vec3::operator+=(vec3 const& other) {
    _x += other._x;
    _y += other._y;
    _z += other._z;
    _setLength();

    return *this;
}

vec3& vec3::operator-=(vec3 const& other) {
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    _setLength();

    return *this;
}

vec3& vec3::operator*=(double scalar) {
    _x *= scalar;
    _y *= scalar;
    _z *= scalar;
    _setLength();

    return *this;
}

vec3& vec3::operator/=(double scalar) {
    return *this *= (1/scalar);
}

vec3 vec3::operator+(vec3 const& other) const {
    return vec3(_x+other._x, _y+other._y, _z+other._z);
}

vec3 vec3::operator-(vec3 const& other) const {
    return vec3(_x-other._x, _y-other._y, _z-other._z);
}

vec3 vec3::operator*(double const scalar) const {
    return vec3(scalar*_x, scalar*_y, scalar*_z);
}

vec3 vec3::operator/(double const scalar) const {
    return *this * (1/scalar);
}

bool vec3::operator==(vec3 const& other) const {
    return _x == other._x && _y == other._y && _z == other._z;
}

bool vec3::operator!=(vec3 const& other) const {
    return !(*this == other);
}

void vec3::_setLength() {
    _squareLength = _x*_x + _y*_y + _z*_z;
    _length = sqrt(_squareLength);

    _isUnit = (_length == 1.0);
}

double vec3::length() const {
    return _length;
}

double vec3::squareLength() const {
    return _squareLength;
}

vec3 vec3::normalize() const {
    if(_isUnit) return vec3(*this);
    return vec3(_x/_length, _y/_length, _z/_length);
}

vec3 vec3::operator*(const vec3 &o) const {
    return vec3(_x * o._x, _y * o._y, _z * o._z);
}

std::ostream& jrt::operator<<(std::ostream& out, vec3 const& v) {
    return out << '(' << v.x() << ',' << v.y() << ',' << v.z() << ')';
}


vec3 jrt::operator*(double scalar, vec3 const& vector) {
    return vector.operator*(scalar);
}

double jrt::dot(vec3 const& vectorA, vec3 const& vectorB) {
    return  vectorA.x()*vectorB.x() +
            vectorA.y()*vectorB.y() +
            vectorA.z()*vectorB.z();
}

vec3 jrt::cross(vec3 const& a, vec3 const& b) {
    return vec3(a.y() * b.z() - a.z() * b.y(),
                a.z() * b.x() - a.x() * b.z(),
                a.x() * b.y() - a.y() * b.x());
}