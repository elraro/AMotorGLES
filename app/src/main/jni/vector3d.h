//**********************************************************************
//* Vector.h
//* 
//* Just Another Vector Implementation (JAVI)
//**********************************************************************

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cmath>
#include <ostream>
#include <cassert>

class Vector3D {
public:
    //******************************************************************
    //* Constructors
    //******************************************************************
    // Default Constructor
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to zero.
    //------------------------------------------------------------------
    Vector3D();

    //------------------------------------------------------------------
    // Component Constructor
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to corresponding 
    // x, y and z parameters.
    //------------------------------------------------------------------
    Vector3D(float x, float y, float z);

    //------------------------------------------------------------------
    // Copy Constructor
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to equal the x, y 
    // and z components of Vector v.
    //------------------------------------------------------------------
    Vector3D(const Vector3D &v);
    //******************************************************************

    //******************************************************************
    //* Friend Operators
    //******************************************************************
    // Stream Insertion Operator
    //------------------------------------------------------------------
    // Writes the Vector v into the output stream in the format (x,y,z) 
    // so it can be used by various iostream functions.
    //------------------------------------------------------------------
    friend std::ostream &operator<<(std::ostream &os, const Vector3D &v);

    //------------------------------------------------------------------
    // Equal To Operator
    //------------------------------------------------------------------
    // Compares the x, y and z components of Vector v1 and to the x, y 
    // and z components of Vector v2 and returns true if they are 
    // identical. Otherwise, it returns false.
    //------------------------------------------------------------------
    friend bool operator==(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // Not Equal To Operator
    //------------------------------------------------------------------
    // Compares the x, y and z components of Vector v1 and to the x, y 
    // and z components of Vector v2 and returns true if they are not 
    // identical. Otherwise, it returns false.
    //------------------------------------------------------------------
    friend bool operator!=(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // Addition Operator
    //------------------------------------------------------------------
    // Adds the x, y and z components of Vector v1 to the x, y and z 
    // compenents of Vector v2 and returns the result.
    //------------------------------------------------------------------
    friend Vector3D operator+(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // Subtraction Operator
    //------------------------------------------------------------------
    // Subtracts the x, y and z components of Vector v2 to the x, y and 
    // z compenents of Vector v1 and returns the result.
    //------------------------------------------------------------------
    friend Vector3D operator-(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // Multiplication Operator
    //------------------------------------------------------------------
    // Multiplies the x, y and z components of Vector v with a scalar 
    // value and returns the result.
    //------------------------------------------------------------------
    friend Vector3D operator*(const Vector3D &v, float scalar);

    friend Vector3D operator*(float scalar, const Vector3D &v);

    //------------------------------------------------------------------
    // Division Operator
    //------------------------------------------------------------------
    // Divides the x, y and z components of Vector v with a scalar 
    // value and returns the result.
    //------------------------------------------------------------------
    friend Vector3D operator/(const Vector3D &v, float scalar);

    friend Vector3D operator/(float scalar, const Vector3D &v);
    //******************************************************************

    //******************************************************************
    //* Friend Functions
    //******************************************************************
    // DotProduct
    //------------------------------------------------------------------
    // Computes the dot product between Vector v1 and Vector v2 and 
    // returns the result.
    // two implementations, * can make ambiguity
    //------------------------------------------------------------------
    friend float dotProduct(const Vector3D &v1, const Vector3D &v2);

    friend float operator*(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // CrossProduct
    //------------------------------------------------------------------
    // Computes the cross product between Vector v1 and Vector v2 and 
    // returns the result.
    //------------------------------------------------------------------
    friend Vector3D crossProduct(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // Lerp
    //------------------------------------------------------------------
    // Returns a linear interpolation between Vector v1 and Vector v2 
    // for paramater t, in the closed interval [0, 1].
    //------------------------------------------------------------------
    friend Vector3D lerp(const Vector3D &v1, const Vector3D &v2, float t);

    //------------------------------------------------------------------
    // Clamp - TODO: make this a method instead?
    //------------------------------------------------------------------
    // Clamps this Vector's x, y and z components to lie within min and 
    // max.
    //------------------------------------------------------------------
    friend Vector3D clamp(const Vector3D &v1, float min, float max);

    //------------------------------------------------------------------
    // Min
    //------------------------------------------------------------------
    // Returns a Vector whos x, y and z components are the minimum 
    // components found in Vector v1 and Vector v2.
    //------------------------------------------------------------------
    friend Vector3D min(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // Max
    //------------------------------------------------------------------
    // Returns a Vector whos x, y and z components are the maximum 
    // components found in Vector v1 and Vector v2.
    //------------------------------------------------------------------
    friend Vector3D max(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // DistanceBetween
    //------------------------------------------------------------------
    // Returns the scalar distance between the Vector v1 and the Vector 
    // v2.
    //------------------------------------------------------------------
    friend float distanceBetween(const Vector3D &v1, const Vector3D &v2);

    //------------------------------------------------------------------
    // DistanceBetweenSquared
    //------------------------------------------------------------------
    // Returns the scalar squared distance between the Vector v1 and 
    // the Vector v2.
    //------------------------------------------------------------------
    friend float distanceBetweenSquared(const Vector3D &v1, const Vector3D &v2);
    //******************************************************************

    //******************************************************************
    //* Operators
    //******************************************************************
    // Copy Assignment Operator
    //------------------------------------------------------------------
    // Assigns this Vector's components to be equal to Vector v's 
    // components.
    //------------------------------------------------------------------
    Vector3D &operator=(const Vector3D &v);

    //------------------------------------------------------------------
    // Addition Assignment Operator
    //------------------------------------------------------------------
    // Adds to this Vector's components the components of Vector v.
    //------------------------------------------------------------------
    Vector3D &operator+=(const Vector3D &v);

    //------------------------------------------------------------------
    // Subtraction Assignment Operator
    //------------------------------------------------------------------
    // Subtract from this Vector's components the components of Vector 
    // v.
    //------------------------------------------------------------------
    Vector3D &operator-=(const Vector3D &v);

    //------------------------------------------------------------------
    // Multiplication Assignment Operator
    //------------------------------------------------------------------
    // Multiply this Vector's components by a scalar value.
    //------------------------------------------------------------------
    Vector3D &operator*=(float scalar);

    //------------------------------------------------------------------
    // Division Assignment Operator
    //------------------------------------------------------------------
    // Divide this Vector's components by a scalar value.
    //------------------------------------------------------------------
    Vector3D &operator/=(float scalar);

    //------------------------------------------------------------------
    // Unary Minus Operator
    //------------------------------------------------------------------
    // Negate the components of this Vector.
    //------------------------------------------------------------------
    Vector3D &operator-();

    //------------------------------------------------------------------
    // Array Subscript Operator
    //------------------------------------------------------------------
    // Allows access to the x, y and z components through an array 
    // subscript notation.
    //------------------------------------------------------------------
    float &operator[](int i);
    //******************************************************************

    //******************************************************************
    //* Methods
    //******************************************************************
    // X
    //------------------------------------------------------------------
    // Returns the x component of this Vector.
    //------------------------------------------------------------------
    float getX();

    //------------------------------------------------------------------
    // Y
    //------------------------------------------------------------------
    // Returns the y component of this Vector.
    //------------------------------------------------------------------
    float getY();

    //------------------------------------------------------------------
    // Z
    //------------------------------------------------------------------
    // Returns the z component of this Vector.
    //------------------------------------------------------------------
    float getZ();

    //------------------------------------------------------------------
    // Set
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to the paramaters 
    // of this function.
    //------------------------------------------------------------------
    void set(float x, float y, float z);

    void setX(float x);

    void setY(float y);

    void setZ(float z);

    //------------------------------------------------------------------
    // MakeZero
    //------------------------------------------------------------------
    // Sets the x, y and z components of this Vector to zero.
    //------------------------------------------------------------------
    void makeZero();

    //------------------------------------------------------------------
    // IsZero
    //------------------------------------------------------------------
    // Returns true if the x, y and z components of this Vector are 
    // equal to zero.
    //------------------------------------------------------------------
    bool isZero();

    //------------------------------------------------------------------
    // LengthSquared
    //------------------------------------------------------------------
    // Returns the magnitude of the x, y and z components squared.
    //------------------------------------------------------------------
    float lengthSquared();

    //------------------------------------------------------------------
    // Length
    //------------------------------------------------------------------
    // Returns the magnitude of the x, y and z components.
    //------------------------------------------------------------------
    float length();

    //------------------------------------------------------------------
    // Normalize
    //------------------------------------------------------------------
    // Sets the components of this Vector in such a way that their 
    // magnitude is equal to one.
    //------------------------------------------------------------------
    void normalize();

    //------------------------------------------------------------------
    // Reflect
    //------------------------------------------------------------------
    // Reflect this vector in the normal n
    // n must be normalized
    //------------------------------------------------------------------
    Vector3D reflect(Vector3D n);

    //------------------------------------------------------------------
    // IsNormalized
    //------------------------------------------------------------------
    // Compares the magnitude of this Vector to one.
    //------------------------------------------------------------------
    bool isNormalized();

    //Custom
    void invert();


    //******************************************************************

private:
    //******************************************************************
    //* Private Member Variables
    //******************************************************************
    // x
    //------------------------------------------------------------------
    // The x component of this Vector.
    //------------------------------------------------------------------
    float x;
    //------------------------------------------------------------------
    // y
    //------------------------------------------------------------------
    // The y component of this Vector.
    //------------------------------------------------------------------
    float y;
    //------------------------------------------------------------------
    // z
    //------------------------------------------------------------------
    // The z component of this Vector.
    //------------------------------------------------------------------
    float z;
    //******************************************************************
};

inline Vector3D::Vector3D() : x(0.0f), y(0.0f), z(0.0f) { }

inline Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) { }

inline Vector3D::Vector3D(const Vector3D &v) : x(v.x), y(v.y), z(v.z) { }

inline std::ostream &operator<<(std::ostream &os, const Vector3D &v) {
    os << '<' << v.x << ',' << v.y << ',' << v.z << '>';
    return os;
}

inline bool areEqual(float a, float b) {
    return a == b;
}

inline bool operator==(const Vector3D &v1, const Vector3D &v2) {
    return (areEqual(v1.x, v2.x) &&
            areEqual(v1.y, v2.y) &&
            areEqual(v1.z, v2.z));
}

inline bool operator!=(const Vector3D &v1, const Vector3D &v2) {
    return (!areEqual(v1.x, v2.x) ||
            !areEqual(v1.y, v2.y) ||
            !areEqual(v1.z, v2.z));
}

inline Vector3D operator+(const Vector3D &v1, const Vector3D &v2) {
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vector3D operator-(const Vector3D &v1, const Vector3D &v2) {
    return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline Vector3D operator*(const Vector3D &v, float scalar) {
    return Vector3D(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline Vector3D operator*(float scalar, const Vector3D &v) {
    return Vector3D(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline bool equalsZero(float a) {
    //float almost never is 0.0
    //This value shoud be a const
    return fabs(a) < 1e-30;
}

inline Vector3D operator/(const Vector3D &v, float scalar) {
    assert(!equalsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector3D(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline Vector3D operator/(float scalar, const Vector3D &v) {
    assert(!equalsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector3D(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline float operator*(const Vector3D &v1, const Vector3D &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline float dotProduct(const Vector3D &v1, const Vector3D &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vector3D crossProduct(const Vector3D &v1, const Vector3D &v2) {
    return Vector3D(v1.y * v2.z - v1.z * v2.y,
                    v1.z * v2.x - v1.x * v2.z,
                    v1.x * v2.y - v1.y * v2.x);
}

inline float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

inline Vector3D lerp(const Vector3D &v1, const Vector3D &v2, float t) {
    return Vector3D(lerp(v1.x, v2.x, t),
                    lerp(v1.y, v2.y, t),
                    lerp(v1.z, v2.z, t));
}

inline float clamp(float a, float min, float max) {
    float m = fmax(a, min);
    return fmin(m, max);
}

inline Vector3D clamp(const Vector3D &v, float min, float max) {
    return Vector3D(clamp(v.x, min, max),
                    clamp(v.y, min, max),
                    clamp(v.z, min, max));
}

inline Vector3D min(const Vector3D &v1, const Vector3D &v2) {
    return Vector3D(fmin(v1.x, v2.x),
                    fmin(v1.y, v2.y),
                    fmin(v1.z, v2.z));
}

inline Vector3D max(const Vector3D &v1, const Vector3D &v2) {
    return Vector3D(fmax(v1.x, v2.x),
                    fmax(v1.y, v2.y),
                    fmax(v1.z, v2.z));
}

inline float distanceBetween(const Vector3D &v1, const Vector3D &v2) {
    Vector3D distance = v1 - v2;
    return distance.length();
}

inline float distanceBetweenSquared(const Vector3D &v1, const Vector3D &v2) {
    Vector3D distance = v1 - v2;
    return distance.lengthSquared();
}

inline Vector3D &Vector3D::operator=(const Vector3D &v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

inline Vector3D &Vector3D::operator+=(const Vector3D &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline Vector3D &Vector3D::operator-=(const Vector3D &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline Vector3D &Vector3D::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector3D &Vector3D::operator/=(float scalar) {
    assert(!equalsZero(scalar));
    scalar = 1.0f / scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector3D &Vector3D::operator-() {
    x = -x;
    y = -y;
    z = -z;
    return *this;
}

inline float &Vector3D::operator[](int i) {
    if (i == 0) {
        return x;
    } else if (i == 1) {
        return y;
    } else if (i == 2) {
        return z;
    } else {
        assert("[] Access error!");
    }
    return x;
}

inline float Vector3D::getX() {
    return x;
}

inline float Vector3D::getY() {
    return y;
}

inline float Vector3D::getZ() {
    return z;
}

inline void Vector3D::set(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

inline void Vector3D::setY(float y) {
    this->y = y;
}

inline void Vector3D::setX(float x) {
    this->x = x;
}

inline void Vector3D::setZ(float z) {
    this->z = z;
}

inline void Vector3D::makeZero() {
    x = y = z = 0.0f;
}

inline bool Vector3D::isZero() {
    return equalsZero(x) &&
           equalsZero(y) &&
           equalsZero(z);
}

inline float Vector3D::lengthSquared() {
    return x * x + y * y + z * z;
}

inline float Vector3D::length() {
    return sqrt(lengthSquared());
}

inline void Vector3D::normalize() {
    float magnitude = length();
    assert(!equalsZero(magnitude));

    magnitude = 1.0f / magnitude;

    x *= magnitude;
    y *= magnitude;
    z *= magnitude;
}

inline Vector3D Vector3D::reflect(Vector3D n) {
    Vector3D self, projectionV, dif, reflectedV, newV;
    float projectionN;
    self = *this;
    projectionN = self * n;
    projectionV = projectionN * n;
    dif = self - projectionV;
    reflectedV = -projectionV;
    newV = dif + reflectedV;
    return newV;
}

inline bool Vector3D::isNormalized() {
    return areEqual(length(), 1.0f);
}

//custom

inline void Vector3D::invert() {
    //float aux = x;
    x = x * -1;
    if (x < 0) {
        x += 1;
    } else {
        x -= 1;
    }
    y = y * -1;
    if (y < 0) {
        y += 1;
    } else {
        y -= 1;
    }
}

#endif
