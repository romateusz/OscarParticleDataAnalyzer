#include "Vec4.h"
#include <cmath>

Vec4::Vec4() : et(0.0), x(0.0), y(0.0), z(0.0) {}

Vec4::Vec4(double et_val, double x_val, double y_val, double z_val) 
    : et(et_val), x(x_val), y(y_val), z(z_val) {}

Vec4::Vec4(const Vec4& other) 
    : et(other.et), x(other.x), y(other.y), z(other.z) {}

Vec4 Vec4::operator+(const Vec4& other) const {
    return Vec4(et + other.et, x + other.x, y + other.y, z + other.z);
}

double Vec4::Mod() const {
    return std::sqrt(x * x + y * y + z * z);
}

double Vec4::MS() const {
    double val = (et * et) - (x * x) - (y * y) - (z * z);
    
    if (val < 0.0)
    {
        val = 0.0;
    }
    return std::sqrt(val);
}

std::ostream& operator<<(std::ostream& os, const Vec4& v) {
    os << "[" << v.et << ", " << v.x << ", " << v.y << ", " << v.z << "]\n";
    return os;
}