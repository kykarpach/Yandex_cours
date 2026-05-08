

const int DEFAULT_DATE_DAY = 1;
const int DEFAULT_DATE_MONTH = 1;
const int DEFAULT_DATE_YEAR = 1970;
const int DAYS_IN_YEAR_WITHOUT_FEB = 337;

class Date{
private:
    
    int day;

    //Ввел год - получил кол-во дней в феврале этого года
    int Get_days_in_febrary(int y)const{

        if(!(y % 4) && ( (y % 100) || !(y % 400) ) ){  // целочисленные значения в условиях преобразуются в bool: 
            return 29;                                 // 0 → false
        }                                              // любое ненулевое → true
        else{
            return 28;
        }
    }

    //Ввел месяц и год - получил кол-во дней в месяце этого года
    int Get_days_in_month(int m, int y)const{
        switch (m){

        case 2:
            return Get_days_in_febrary(y);   
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return 30;
        }
    }

    //Ввел год - получил кол-во дней в этом году
    int Get_days_in_current_year(int y)const{
        return DAYS_IN_YEAR_WITHOUT_FEB + Get_days_in_febrary(y);
    }

    //Применяя к объекту класса Data, хранящего дату в днях с начала 01 01 1970, получаешь год. data.Get_Year_from_days() == год 
    int Get_Year_from_days() const{

        int help_day = day;
        int year = DEFAULT_DATE_YEAR;

        while(help_day > Get_days_in_current_year(year)){// ТЫ БЫЛ СОННЫЙ И РЕШИЛ НЕ РАЗБАИРТЬСЯ ПОЧЕМУ ТУТ > А НЕ >=
            
            help_day -= Get_days_in_current_year(year);
            ++year;
            
        }

        return year;

    }    
    
    //Применяя к объекту класса Data, хранящего дату в днях с начала 01 01 1970, получаешь месяц. data.Get_Month_from_days() == месяц
    int Get_Month_form_days()const{

        int help_day = day;
        int year = DEFAULT_DATE_YEAR;
        int month = 1;

        while(help_day > Get_days_in_current_year(year)){// ТЫ БЫЛ СОННЫЙ И РЕШИЛ НЕ РАЗБАИРТЬСЯ ПОЧЕМУ ТУТ > А НЕ >=
            help_day -= Get_days_in_current_year(year);
            ++year;
        }
        while(help_day > Get_days_in_month(month, year)){// ТЫ БЫЛ СОННЫЙ И РЕШИЛ НЕ РАЗБАИРТЬСЯ ПОЧЕМУ ТУТ > А НЕ >=
            help_day -= Get_days_in_month(month, year);
            ++month;
        }

        return month;

    }
    
    //Применяя к объекту класса Data, хранящего дату в днях с начала 01 01 1970, получаешь дату дня. data.Get_Day_from_days() == день
    int Get_Day_form_days()const{

        int help_day = day;
        int year = DEFAULT_DATE_YEAR;
        int month = 1;

        while(help_day > Get_days_in_current_year(year)){ // ТЫ БЫЛ СОННЫЙ И РЕШИЛ НЕ РАЗБАИРТЬСЯ ПОЧЕМУ ТУТ > А НЕ >=
            help_day -= Get_days_in_current_year(year);
            ++year;
        }
        while(help_day > Get_days_in_month(month, year)){// ТЫ БЫЛ СОННЫЙ И РЕШИЛ НЕ РАЗБАИРТЬСЯ ПОЧЕМУ ТУТ > А НЕ >=
            help_day -= Get_days_in_month(month, year);
            ++month;
        }

        return help_day + 1; // ТЫ БЫЛ СОННЫЙ И РЕШИЛ НЕ РАЗБИРАТЬСЯ ПОЧЕМУ ТУТ + 1.

    }    

public:

    Date(int y, int m, int d);

    int GetDay()const{
        return Get_Day_form_days();
    };
    int GetMonth()const{
        return Get_Month_form_days();
    };
    int GetYear()const{
        return Get_Year_from_days();
    };

    Date& operator +=(int d){
        
        day += d;

        return *this;
    };
    Date& operator -=(int d){
        
        day -= d;
        return *this;
    };

    // Это хуйня нарушает инкапсуляцию, но по другому без "дружественности функций" я не придумал 
    int Get_int_from_Date()const{
        return day;
    }

};

Date::Date(int d, int m, int y) {
    // 1. Проверка на корректность (если дата невалидна — сбрасываем на 01.01.1970)
    if (y < 1970 || y > 2099 || m < 1 || m > 12 || d < 1 || d > Get_days_in_month(m, y)) {
        day = 0; // В логике это 1 января 1970 года
    } else {
        day = 0;
        
        // 2. Считаем дни за все прошедшие полные годы
        for (int i = 1970; i < y; ++i) {
            day += Get_days_in_current_year(i);
        }
        
        // 3. Считаем дни за все прошедшие полные месяцы текущего года
        for (int i = 1; i < m; ++i) {
            day += Get_days_in_month(i, y);
        }
        
        // 4. Добавляем дни текущего месяца (минус один, так как 1-е число — это 0 дней смещения)
        day += (d - 1);
    }
}
//Прикол еще в том что функции должны выводить дату, то есть надо еще дни перевести в дату... Разобрался, на самом деле все ок...
Date operator+(const Date& date, int d){
    Date result = date;
    result += d;
    return result;
}
Date operator-(const Date & date, int d){
    Date result = date;
    result -= d;
    return result;
}

int operator - (const Date& d1, const Date& d2){

    return d1.Get_int_from_Date() - d2.Get_int_from_Date();
};