#include <vector>
#include <set>
#include <climits> // Нужно добавить для INT_MIN
// ИЗНАЧАЛЬНО ТУТ У МЕНЯ БЫЛА ПРОБЛЕМА ИЗ ЗА "Если подходящих коробок несколько,
//  нужно выбрать ту, которая пролежала на складе меньше." - МЕНЬШЕ,  
// А Я ВЫБИРАЛ БОЛЬШЕ В СТРОЧКЕ 31
// auto it = box_w.lower_bound({min_w, 0}); И ИНИЦАЛИЗАЦИИ box_v.insert({v, -N}); И box_w.insert({w, -N}); НЕ С "-N" а с "N".
//  И там еще потом it->second надо заменить на -it . ТОже про id
class Stock{
private:

int N = 0;
std::vector<std::pair<int, int>> box_wv;
std::set<std::pair<int, int>> box_w;
std::set<std::pair<int, int>> box_v;

public:

    void Add(int w, int v);
    int GetByW(int min_w);
    int GetByV(int min_v);
};

void Stock::Add(int w, int v){
    box_wv.push_back({w, v});
    box_v.insert({v, -N});
    box_w.insert({w, -N});
    N += 1;
}

int Stock::GetByW(int min_w){

    auto it = box_w.lower_bound({min_w, INT_MIN});
    if(it != box_w.end()){
        // it->second - N
        // it->first - w.
        auto id = -it->second;//Нужен минус, чтобы обратно сделать полоджителным
        auto help_v = box_wv[id].second;// Тут мы нашли W(грузоподъемность) этой коробки.
        auto help_w = box_wv[id].first;
        box_w.erase({help_w, -id}); // Удалили эту коробку из box_w.
        box_v.erase({help_v, -id}); // Удалили эту коробку из box_v.
        // А из box_wv - ничего удалять не надо, мы и так больше никогда не пересечемся с этим N.
        return id;
    }else{
        return -1;
    }
}

int Stock::GetByV(int min_v){

    auto it = box_v.lower_bound({min_v, INT_MIN});
    if(it != box_v.end()){
        auto id = -it->second;//Нужен минус, чтобы обратно сделать полоджителным
        auto help_v = box_wv[id].second;// Тут мы нашли V(объем) этой коробки.
        auto help_w = box_wv[id].first;
        box_w.erase({help_w, -id}); // Удалили эту коробку из box_w.
        box_v.erase({help_v, -id}); // Удалили эту коробку из box_v.
        // А из box_wv - ничего удалять не надо, мы и так больше никогда не пересечемся с этим N.
        return id;
    }else{
        return -1;
    }
}