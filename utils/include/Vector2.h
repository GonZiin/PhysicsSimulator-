#ifndef PHYSICSSIMULATION_VECTOR2_H
#define PHYSICSSIMULATION_VECTOR2_H

template <typename T>
class Vector2 {
public:
    Vector2(T val1 = 0, T val2 = 0);

    T getX() const;
    T getY() const;
    void setX(T x);
    void setY(T y);

    Vector2<T> operator+(const Vector2<T>& other) const;
    Vector2<T> operator-(const Vector2<T>& other) const;
    Vector2<T> operator*(T scalar) const;
    Vector2<T> operator/(T scalar) const;
    Vector2<T> operator*(const Vector2<T>& other) const;

private:
    T x;
    T y;
};

template <typename T>
Vector2<T>::Vector2(T val1, T val2) : x(val1), y(val2) {}

template <typename T>
T Vector2<T>::getX() const { return x; }

template <typename T>
T Vector2<T>::getY() const { return y; }

template <typename T>
void Vector2<T>::setX(T x) { this->x = x; }

template <typename T>
void Vector2<T>::setY(T y) { this->y = y; }

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) const {
    return Vector2<T>(x + other.x, y + other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) const {
    return Vector2<T>(x - other.x, y - other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(T scalar) const {
    return Vector2<T>(x * scalar, y * scalar);
}

template <typename T>
Vector2<T> Vector2<T>::operator/(T scalar) const {
    return Vector2<T>(x / scalar, y / scalar);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(const Vector2<T>& other) const {
    return Vector2<T>(x * other.x, y * other.y);
}

#endif