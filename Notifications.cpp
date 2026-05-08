#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

class NotifierBase{
public:

    virtual void Notify(const std::string& massage) const = 0;

};

class SmsNotifier: public NotifierBase{
private:

    std::string number;

public:

    SmsNotifier(std::string num): number(num){}

    void Notify(const std::string& massage) const override{
        SendSms(number, massage);
    }

};

class EmailNotifier: public NotifierBase{
private:

    std::string email;

public:

    EmailNotifier(std::string mail): email(mail){}

    void Notify(const std::string& massage) const override{
        SendEmail(email, massage);
    }

};

void Notify(const NotifierBase& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms("+7-495-777-77-77");
    EmailNotifier email("na-derevnyu@dedushke.ru");

    Notify(sms, "Hello! How are you?");
    Notify(email, "Let's learn C++!");
    return 0;
}