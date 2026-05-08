#include <iostream>
#include <vector>
#include <numeric>


class Date{
private:
    
    int year;
    int month;
    int day;

    void Normalaize_for_constructor(){
    if(year < 1970 
        || month < 1 
        || day < 1 
        || month > 12
        || (month == 2 && day > 29) 
        || (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) 
        || (day > 29 &&  month == 2 && (year%4 == 0 && (year%100 != 0 || year%400 == 0)) )
        || (day > 28 &&  month == 2 && !(year%4 == 0 && (year%100 != 0 || year%400 == 0)) )
        || day > 31 ){

        year = 1970;
        month = 1;
        day = 1;

        }
    }


    void Normalaze() {

        while (month > 12) {
            year += 1;
            month -= 12;
        }
        while (month < 1) {
            year -= 1;
            month += 12;
        }
        

        auto days_in_month = [](int m, int y) {
            static const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            bool is_leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
            int days = month_days[m - 1];
            if (m == 2 && is_leap) days = 29;
            return days;
        };
        

        while (day > days_in_month(month, year)) {
            day -= days_in_month(month, year);
            month += 1;
            if (month > 12) {
                month = 1;
                year += 1;
            }
        }
        
        while (day < 1) {
            month -= 1;
            if (month < 1) {
                month = 12;
                year -= 1;
            }
            day += days_in_month(month, year);
        }

        if (year < 1970) {
        year = 1970;
        month = 1;
        day = 1;
        return;
        }
        
    }

    static Date from_days_offset(int offset) {
        int year = 1970;
        int month = 1;
        int day = 1;
        int total = 0;

        // Перейдем к нужному году
        while (true) {
            int days_in_year = 365;
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                days_in_year = 366;
            }
            if (total + days_in_year <= offset) {
                total += days_in_year;
                year++;
            } else {
                break;
            }
        }

        static const int mdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (month = 1; month <= 12; month++) {
            int dm = mdays[month];
            if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
                dm = 29;
            }
            if (total + dm <= offset) {
                total += dm;
            } else {
                break;
            }
        }

        day = offset - total + 1;
        Date res(1970, 1, 1);
        res.year = year;
        res.month = month;
        res.day = day;
        res.Normalaize_for_constructor(); // на всякий случай
        return res;
    }

public:
    
    Date(int Y, int M, int D){

        year = Y;
        month = M;
        day = D;

        Normalaize_for_constructor();
    }

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    


    //--------------------------------------------------------------------------------------------------------------------
    Date& operator += (int i){
        int new_total = this->Do_to_only_days() + i;
        Date temp = Date::from_days_offset(new_total);
        this->year = temp.year;
        this->month = temp.month;
        this->day = temp.day;
        return *this;
    }

    Date& operator -= (int i){
        int new_total = this->Do_to_only_days() - i;
        Date temp = Date::from_days_offset(new_total);
        this->year = temp.year;
        this->month = temp.month;
        this->day = temp.day;
        return *this;
    }


    //--------------------------------------------------------------------------------------------------------------------



    // Date& operator += (int i){

    //     day += i;
    //     Normalaze();
        
    //     return *this;
    // }
    
    // Date& operator -= (int i){
        
    //     day -= i;
    //     Normalaze();

    //     return *this;
    // }
    
    int Do_to_only_days() const{
        static const int days_from_year1_to_1970 = 719163;

        static const std::vector<int> all_month_vis = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        static const std::vector<int> all_month_no_vis = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int help_sum_month_in_current_year;

        bool Is_it_visacosni = (year%4 == 0 && (year%100 != 0 || year%400 == 0));

        if(Is_it_visacosni){

            help_sum_month_in_current_year = std::accumulate(all_month_vis.begin(),
             all_month_vis.begin() + (month - 1),
             /* (month - 1) так как надо ссумировать все месяца
             до текущего (при этом учитываем что std::acumulate
             вторым аргументом принимает значение до которого суммирем, НО НЕ ВКЛЮЧАЯ ЕГО...)*/
             0);

        }else{help_sum_month_in_current_year = std::accumulate(all_month_no_vis.begin(), all_month_no_vis.begin() + month - 1, 0);}

        int total = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + help_sum_month_in_current_year + day;

        return total - days_from_year1_to_1970;
    }

};


int Date::GetDay() const{
    return day;
}
int Date::GetMonth() const{
    return month;
}
int Date::GetYear() const{
    return year;
}


Date operator - (Date data, int i){
    data -= i;
    return data;
}
Date operator + (Date data, int i){
    data += i;
    return data;
}


int operator - (Date d1 , Date d2){
    return d1.Do_to_only_days() - d2.Do_to_only_days();
}



