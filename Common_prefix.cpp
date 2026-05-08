#include <iostream>
#include <vector>
#include <string>


std::string CommonPrefix(const std::vector<std::string>& words){

    if(words.size() == 0){
        return {};
    }

    size_t quantity;
    std::string str_first_help = words[0];
    size_t minimal_quantity = words[0].size();

    if(words.size() != 0){
        for(const auto& str_in_words : words){
            quantity = 0;
            for(size_t i = 0; i < str_in_words.size() && i < str_first_help.size(); ++i){
                if(str_first_help[i] == str_in_words[i]){
                    ++quantity;
                }
                else{
                    break;
                    // if(quantity < minimal_quantity){
                    //     minimal_quantity = quantity;
                    //     break;
                    // }
                    // else{
                    //     break;
                    // }
                }
            }
            // Ключевое исправление: обновляем минимальную длину после каждого слова
            if (quantity < minimal_quantity) {
                minimal_quantity = quantity;
            }   
        }
    }
    std::string answer;
    if(minimal_quantity > 0){
        for(size_t i = 0; i < minimal_quantity; ++ i){
            answer.push_back(str_first_help[i]);
        }
        return answer;
    }
    else{return {};}
}

// Вот примеры, на которых ваш исходный код работает некорректно:

// Пример 1: Короткое слово в середине вектора
// Вход: {"apple", "app", "application"}
// Ожидаемый результат: "ap"
// Ваш код возвращает: "apple" (неверно)

// Причина:

// После обработки "apple": minimal_quantity = 5

// После обработки "app": цикл завершается без break, quantity = 3, но minimal_quantity не обновляется (остаётся 5)

// После обработки "application": quantity = 2 (обновляет minimal_quantity до 2)

// Возвращается подстрока длиной 5 из "apple" -> "apple"

// Пример 2: Полное совпадение префикса в последнем слове
// Вход: {"abc", "ab", "abcd"}
// Ожидаемый результат: "ab"
// Ваш код возвращает: "abc" (неверно)

// Причина:

// После "abc": minimal_quantity = 3

// После "ab": цикл завершается без break, quantity = 2, но значение не сравнивается с minimal_quantity

// После "abcd": quantity = 3 (не обновляет минимум, так как 3 < 3 ложно)

// Возвращается "abc"

// Пример 3: Все слова короче первого
// Вход: {"abcdef", "abc", "abcd"}
// Ожидаемый результат: "abc"
// Ваш код возвращает: "abcdef" (неверно)

// Причина:

// После "abcdef": minimal_quantity = 6

// После "abc": quantity = 3 (не обновляет минимум)

// После "abcd": quantity = 4 (не обновляет минимум)

// Возвращается подстрока длиной 6 -> "abcdef"

// Пример 4: Пустая строка в векторе
// Вход: {"hello", "", "he"}
// Ожидаемый результат: ""
// Ваш код возвращает: "he" (неверно)

// Причина:

// После "hello": minimal_quantity = 5

// После "": quantity = 0 (обновляет minimal_quantity до 0)

// После "he": quantity = 2 (не обновляет минимум, так как 2 > 0)

// Возвращается подстрока длиной 2 -> "he"