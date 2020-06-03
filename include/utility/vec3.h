#ifndef JUSTINSRAYTRACER_VEC3_H
#define JUSTINSRAYTRACER_VEC3_H

#include <ostream>

namespace jrt{
class vec3 {
public:
    vec3(double x, double y, double z);
    explicit vec3(double all);

    double x() const;
    double y() const;
    double z() const;

    // Access operator
    double operator[](unsigned int idx) const;

    // Unary operators
    vec3 operator-() const;

    // X= operators
    vec3& operator+=(vec3 const& other);
    vec3& operator-=(vec3 const& other);
    vec3& operator*=(double scalar);
    vec3& operator/=(double scalar);

    // Binary operators
    vec3 operator+(vec3 const& other) const;
    vec3 operator-(vec3 const& other) const;
    vec3 operator*(double scalar) const;
    vec3 operator/(double scalar) const;

    vec3 operator*(vec3 const& other) const;

    // Boolean stuffs
    bool operator==(vec3 const& other) const;
    bool operator!=(vec3 const& other) const;

    vec3 normalize() const;


    double length() const;
    double squareLength() const;

private:
    void _setLength();

    double _x, _y, _z;
    double _length;       // Length is cached
    double _squareLength; // Square length is also cached

    bool _isUnit = false;
};

std::ostream& operator<<(std::ostream& out, vec3 const& v);

vec3 operator*(double scalar, vec3 const& vector);

double dot(vec3 const& vectorA, vec3 const& vectorB);

vec3 cross(vec3 const& vectorA, vec3 const& vectorB);

using point3 = vec3;
using color = vec3;

}

#endif //JUSTINSRAYTRACER_VEC3_H
