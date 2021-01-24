#include <iostream>
#include <sigc++/sigc++.h>

class AlienDetector : public sigc::trackable {
public:
    AlienDetector() = default;
    ~AlienDetector() = default;

    void appear() {
        signal_alert.emit("Alien is in the carpark !!!!");
    }

    sigc::signal<void(std::string)> signal_alert;
};

class AlienAlerter : public sigc::trackable {
public:
    AlienAlerter() = default;
    ~AlienAlerter() = default;
    void onAlert(std::string strAlert) {
        std::cout << strAlert << std::endl;
        std::cout << signal_waring.emit("please run away!!") << std::endl;
    }

    sigc::signal<std::string(std::string)> signal_waring;
};

class People {
public:
    People() = default;
    ~People() = default;
    std::string onWarning(std::string str)
    {
        std::cout << str << std::endl;
        return "We are OK!";
    }
};

// detector --> AlienDetector::appear --> AlienAlerter::alert --> People::onWarning
int main()
{
    AlienDetector mydetector;
    AlienAlerter myalerter;
    People people;

    mydetector.signal_alert.connect( sigc::mem_fun(myalerter, &AlienAlerter::onAlert));
    myalerter.signal_waring.connect( sigc::mem_fun(people, &People::onWarning) );

    mydetector.appear();

    return 0;
}
