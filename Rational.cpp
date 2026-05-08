#include <numeric>
#include <cmath>
class Rational{
private:

    int numerator;
    int denomirator;

    void Normalize(){
        
        if(denomirator < 0){
            denomirator = -denomirator;
            numerator = -numerator;
        }

        int GCD = std::gcd(std::abs(numerator), std::abs(denomirator));

        if(GCD != 1){
            numerator /= GCD;
            denomirator /= GCD;
        }

    }

    std::pair<Rational, Rational> Reduction_to_common_denominator(const Rational& a, const Rational& b) const{
        
        Rational A = a;
        Rational B = b;

        int Common_denomirator = std::lcm(A.denomirator, B.denomirator);

        int kA = Common_denomirator/A.denomirator;
        int kB = Common_denomirator/B.denomirator;

        A.denomirator = Common_denomirator;
        B.denomirator = Common_denomirator;

        A.numerator *= kA;
        B.numerator *= kB;

        return {A,B};
    }

public:

    Rational(int a = 0, int b = 1){

        int B = b;
        int A = a;
        
        if(B == 0){
            B = 1;
            A = 0;
        }

        int GCD = std::gcd(std::abs(A),std::abs(B));

        if(GCD != 1){
            A /= GCD;
            B /= GCD;
        }
        
        if(B > 0){
            denomirator = B;
            numerator = A;
        }else{
            denomirator = -B;
            numerator = -A;
        }

    }
    
    int Numerator()const{
        return numerator;
    }
    int Denominator()const{
        return denomirator;
    }

    Rational operator-() const{
        Rational anti_Rational(*this);
        anti_Rational.numerator = -anti_Rational.numerator;
        return anti_Rational;
    }
    Rational operator+() const{
        Rational anti_Rational(*this);
        return anti_Rational;
    }
    
    Rational& operator+=(int a){
        numerator += a*denomirator;
        Normalize();
        return *this;
    }
    Rational& operator-=(int a){
        numerator -= a*denomirator;
        Normalize();
        return *this;
    }
    Rational& operator+=(Rational a){
        
        std::pair<Rational, Rational> Pair_A_B = Reduction_to_common_denominator(*this, a);
        numerator = (Pair_A_B.first).numerator + (Pair_A_B.second).numerator;
        denomirator = (Pair_A_B.first).denomirator;
        Normalize();
        return *this;
    }
    Rational& operator-=(Rational a){
        
        std::pair<Rational, Rational> Pair_A_B = Reduction_to_common_denominator(*this, a);
        numerator = (Pair_A_B.first).numerator - (Pair_A_B.second).numerator;
        denomirator = (Pair_A_B.first).denomirator;
        Normalize();
        return *this;
    }

    Rational& operator*=(int a){
        numerator *= a;
        Normalize();
        return *this;
    }
    Rational& operator*=(Rational a){
        numerator *= a.numerator;
        denomirator *= a.denomirator;
        Normalize();
        return *this;
    }
    Rational& operator/=(int a){
        denomirator *= a;
        Normalize();
        return *this;
    }
    Rational& operator/=(Rational a){
        numerator *= a.denomirator;
        denomirator *= a.numerator;
        Normalize();
        return *this;
    }

    bool operator==(int a) const{

        if(numerator == a*denomirator){
            return true;
        }else{return false;}
    }
    bool operator==(Rational a) const{

        auto result = Reduction_to_common_denominator(*this, a);

        if((result.first).numerator == (result.second).numerator){
            return true;
        }else{return false;}
    }
    bool operator!=(int a) const{

        if(!(*this == a)){
            return true;
        }else{return false;}
    }
    bool operator!=(Rational a) const{

        if(!(*this == a)){
            return true;
        }else{return false;}
    }

};

Rational operator + (const Rational& rat, const int& a){
    Rational Rat = rat;
    Rat += a;
    return Rat;
}
Rational operator + (const int& a, const Rational& rat){
    Rational Rat = rat;
    Rat += a;
    return Rat;
}
Rational operator + (const Rational& rat1, const Rational& rat2){
    Rational Rat = rat1;
    Rat += rat2;
    return Rat;
}
Rational operator - (const Rational& rat, const int& a){
    Rational Rat = rat;
    Rat += -a;
    return Rat;
}
Rational operator - (const int& a, const Rational& rat){
    Rational Rat = rat;
    Rat = -(Rat - a);
    return Rat;
}
Rational operator - (const Rational& rat1, const Rational& rat2){
    Rational Rat = rat1;
    Rat -= rat2;
    return Rat;
}

Rational operator * (const Rational& rat, const int& a){
    Rational Rat = rat;
    Rat *= a;
    return Rat;
}
Rational operator * (const int& a, const Rational& rat){
    Rational Rat = rat;
    Rat *= a;
    return Rat;
}
Rational operator * (const Rational& rat1, const Rational& rat2){
    Rational Rat = rat1;
    Rat *= rat2;
    return Rat;
}
Rational operator / (const Rational& rat, const int& a){
    Rational Rat = rat;
    Rat /= a;
    return Rat;
}
Rational operator / (const int& a, const Rational& rat){
    return Rational (a*rat.Denominator(), rat.Numerator());
}
Rational operator / (const Rational& rat1, const Rational& rat2){
    Rational Rat = rat1;
    Rat /= rat2;
    return Rat;
}