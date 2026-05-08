#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t length = v.size();
    auto it = v.begin();
    for (size_t i = 0; i != length; ++i) {
        v.push_back(*it);
        ++it;
    }
}

//Оставлю здесь непраильное решение. Которое напоминает, что итераторы инвалидируются при реолокации.