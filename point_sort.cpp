#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

bool Sort_Square(const std::pair<int,size_t>& lhs, const std::pair<int,size_t>& rhs) {
    return lhs.first < rhs.first;
}

int main(){

    int n;
    std::vector<std::pair<int,int>> vec_coordinante;
    std::cin >> n;

    for(int i = 0; i < n; ++i){
        std::pair<int,int> coordinate;
        std::cin >> coordinate.first >> coordinate.second;
        vec_coordinante.push_back(coordinate);
        coordinate = {0, 0};
    }

    std::vector<std::pair<int, size_t>> square_and_iterator;
    
    for(size_t i = 0; i < n; ++i){
        square_and_iterator.push_back({pow(vec_coordinante[i].first, 2) + pow(vec_coordinante[i].second, 2), i});
        // square_and_iterator[i].first = pow(vec_coordinante[i].first, 2) + pow(vec_coordinante[i].second, 2);
        // square_and_iterator[i].second = i;
    }

    //  Через std::greater тоже сработало бы, но узнал я это уже когда написал свою функцию
    //  (работает, т.к. pair сравнивает сначала first, потом second)

    std::sort(square_and_iterator.begin(), square_and_iterator.end(), Sort_Square);
    
    for(size_t i = 0; i < n; ++i){
        std::cout << vec_coordinante[square_and_iterator[i].second].first << ' ' << vec_coordinante[square_and_iterator[i].second].second <<'\n';
    }

}

// УЛУЧШЕННОЕ ГОВНО. ПОЗЖЕ ГЛЯНУ



// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>

// int main() {
//     int n;
//     std::cin >> n;
//     std::vector<std::pair<int, int>> points;
//     points.reserve(n);  // Резервируем память заранее

//     // Чтение точек с использованием ссылки и прямого доступа
//     for (int i = 0; i < n; ++i) {
//         int x, y;
//         std::cin >> x >> y;
//         points.emplace_back(x, y);  // Более эффективное добавление
//     }

//     // Вектор для хранения (квадрат расстояния, индекс)
//     std::vector<std::pair<int, size_t>> dist_index;
//     dist_index.reserve(n);

//     // Заполняем вектор dist_index
//     for (size_t i = 0; i < points.size(); ++i) {
//         const auto& p = points[i];  // Константная ссылка для доступа
//         int sq_dist = p.first * p.first + p.second * p.second;  // Без pow()
//         dist_index.emplace_back(sq_dist, i);  // Эффективное добавление
//     }

//     // Сортировка с использованием лямбда-выражения
//     std::sort(dist_index.begin(), dist_index.end(), 
//               [](const auto& a, const auto& b) {
//                   return a.first < b.first;  // Сортировка по возрастанию
//               });

//     // Вывод результатов
//     for (const auto& di : dist_index) {
//         const auto& p = points[di.second];  // Константная ссылка
//         std::cout << p.first << ' ' << p.second << '\n';
//     }
// }
