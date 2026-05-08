#include <iostream>
#include <vector>

template <typename T>
class MathVector {
 private:

    std::vector<T> data;

 public:
    // Храним в `data` нулевой вектор длины `n`
    MathVector(size_t n) {
        data.resize(n); // создается вектор из n нулей{T()} , T - тип
    }

    template <typename Iter>
    MathVector(Iter first, Iter last) {
        while (first != last) {
            data.push_back(*first);
            ++first;
        }
    }

    size_t Dimension() const { //Dimension - размерность
        return data.size();
    }

    T& operator [] (size_t i) {
        return data[i];
    }

    const T& operator [] (size_t i) const {
        return data[i];
    }
};

// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator << (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator*=(MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i) {
        v[i] *= scalar;
    }
    return v;
}

template <typename T>
MathVector<T> operator * (const MathVector<T>& v, const T& scalar) {
    MathVector<T> tmp = v;
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator * (const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}

template <typename T>
MathVector<T>& operator+=(MathVector<T>& v0, const MathVector<T>& v_plus){
    for(size_t i = 0; i != v0.Dimension(); ++i){
        v0[i] += v_plus[i];
    }
    return v0;
}

template <typename T>
MathVector<T> operator + (const MathVector<T>& v1, const MathVector<T>& v2){
    auto v0(v1);
    for(size_t i = 0; i != v0.Dimension(); ++i){
        v0[i] += v2[i];
    }
    return v0;
}
