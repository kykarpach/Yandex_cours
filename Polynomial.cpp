#include <vector>
#include <iostream>

template <typename T>
class Polynomial{
private:

    std::vector<T> polynom;

    void correctly_form(){
    if(!(polynom.empty())){
        auto it = polynom.end();
        --it;

        while (!polynom.empty() && polynom.back() == T(0)) {
            polynom.pop_back();
        }
        // Cтарая реалищзайция
        // while(it != polynom.begin()){
        //     if(*it == T(0)){
        //         --it;
        //         polynom.pop_back();
        //     }else{break;}
        // }
        // if(*it == T(0)){
        //     polynom.pop_back();
        // }
        }
    }
public:

    Polynomial(const std::vector<T>& coefficient): polynom(coefficient){
        correctly_form();
    }
    Polynomial(const T& value = T(0)) {
        if (value != T(0)) {
            polynom.push_back(value);
        }
    }
    template <typename InputIt>
    Polynomial(InputIt first, InputIt last) : polynom(first, last) {
        correctly_form();
    }

    int Degree() const {
        if (polynom.empty()) {
            return -1;
        }   
        return static_cast<int>(polynom.size()) - 1;
    }

    const T& operator[](size_t i) const {
        static const T zero = T(0); // Живет вечно, можно вернуть ссылку
        if (i < polynom.size()) {   // Раньше я возвращал по значению а не по ссылке T(0)
            return polynom[i];      // так как T(0) сразу умирает и по ссылке передать нельзя
        }else{
            return zero;
        }            
    }

    Polynomial& operator += (T t){
        if(polynom.size() == 0){
            polynom.resize(1);
        }
        polynom[0] += t;
        correctly_form();
        return *this;
    }
    Polynomial& operator += (const Polynomial& p2){
        if(p2.Degree() > Degree()){
            polynom.resize(p2.Degree() + 1);
        }
        for(size_t i = 0; i < p2.polynom.size(); ++i) {
            polynom[i] += p2.polynom[i];
        }
        correctly_form();
        return *this;
        
    }

    Polynomial operator-() const { 
        Polynomial res = *this;    
        for (auto& coeff : res.polynom) {
           coeff = -coeff;        
        }
        return res;                
    }
    Polynomial& operator -= (const Polynomial& other) {
        if (other.polynom.size() > polynom.size()) {
            polynom.resize(other.polynom.size(), T(0));
        }
        for (size_t i = 0; i < other.polynom.size(); ++i) {
          polynom[i] -= other.polynom[i];
        }
        correctly_form();
        return *this;
    }
    Polynomial& operator -= (T t){
        return *this += -t;
    }

    Polynomial& operator *= (const T& value) {
        for (auto& coeff : polynom) {
            coeff *= value;
        }
        correctly_form(); // Если умножили на 0, инвариант должен сохраниться
        return *this;
    }
    Polynomial& operator *= (const Polynomial& other) {
        if (polynom.empty() || other.polynom.empty()) {
            polynom.clear();
            return *this;
        }

        // Новый размер вектора: (степень1 + степень2 + 1)
        // polynom.size() это (Degree + 1)
        std::vector<T> result(polynom.size() + other.polynom.size() - 1, T(0));

        for (size_t i = 0; i < polynom.size(); ++i) {
            for (size_t j = 0; j < other.polynom.size(); ++j) {
                result[i + j] += polynom[i] * other.polynom[j];
            }
        }

        polynom = std::move(result); // Эффективная замена вектора
        correctly_form();
        return *this;
    }

    T operator()(const T& x) const {
        T result = T(0);
        // Идем от старшей степени к младшей (с конца вектора к началу)
        for (int i = Degree(); i >= 0; --i) {
            result = result * x + polynom[i];
        }
        return result;
    }

    auto begin() const {
        return polynom.begin();
    }
    auto end() const {
        return polynom.end();
    }
};

template <typename T>
bool operator == (const Polynomial<T>& p1, const Polynomial<T>& p2){
    if (p1.Degree() != p2.Degree()){
        return false;
    }
    // Используем int i, чтобы соответствовать типу, который возвращает Degree()
    // и избежать ошибки sign-compare
    for (int i = 0; i <= p1.Degree(); ++i) {
        if (p1[i] != p2[i]) {
            return false;
        }
    }
    return true;
}
template <typename T>
bool operator == (const Polynomial<T>& p1, const T& value){
    if(p1.Degree() == -1 && value == T(0)){
        return true;
    }
    if(p1.Degree() != 0){
        return false;
    }else{
        return p1[0] == value;
    }
}
template <typename T>
bool operator == (const T& value, const Polynomial<T>& p1){
    return p1 == value;
}


template <typename T>
bool operator != (const Polynomial<T>& p1, const Polynomial<T>& p2){
    return !(p1 == p2);
}
template <typename T>
bool operator != (const T& value, const Polynomial<T>& p2){
    return !(value == p2);
}
template <typename T>
bool operator != (const Polynomial<T>& p1, const T& value){
    return !(p1 == value);
}
template <typename T>
Polynomial<T> operator + (const Polynomial<T>& p, const T& value){
    auto answer(p);
    answer += value;
    return answer;
}
template <typename T>
Polynomial<T> operator + (const T& value, const Polynomial<T>& p){
    auto answer(p);
    answer += value;
    return answer;
}
template <typename T>
Polynomial<T> operator + (const Polynomial<T>& p1, const Polynomial<T>& p2){
    auto answer(p1);
    answer += p2;
    return answer;
}

template <typename T>
Polynomial<T> operator - (const Polynomial<T>& p, const T& value){
    auto answer(p);
    answer -= value;
    return answer;
}
template <typename T>
Polynomial<T> operator - (const T& value, const Polynomial<T>& p) {
    return -(p - value);
}
template <typename T>
Polynomial<T> operator - (const Polynomial<T>& p1, const Polynomial<T>& p2){
    auto answer(p1);
    answer -= p2;
    return answer;
}

template <typename T>
Polynomial<T> operator * (const Polynomial<T>& p, const T& value) {
    auto answer(p);
    answer *= value;
    return answer;
}
template <typename T>
Polynomial<T> operator * (const T& value, const Polynomial<T>& p) {
    auto answer(p);
    answer *= value;
    return answer;
}
template <typename T>
Polynomial<T> operator * (const Polynomial<T>& p1, const Polynomial<T>& p2) {
    auto answer(p1);
    answer *= p2;
    return answer;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const Polynomial<T>& p) {
    for (int i = p.Degree(); i >= 0; --i) {
        out << p[i];
        if (i > 0) {
            out << " ";
        }
    }
    return out;
}