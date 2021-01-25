#include <iostream>
#include <sigc++/sigc++.h>

class AlienAlerter;

class AlienDetector : public sigc::trackable {
public:
    AlienDetector() = default;
    ~AlienDetector() = default;

    enum class ConnectorType{
        TYPE_1,
        TYPE_2,
        TYPE_3
    };

    void appear() {
        m_signal_alert.emit("Alien is in the carpark !!!!");
    }

    sigc::signal<void(std::string)> m_signal_alert;
};

class AlienAlerter : public sigc::trackable {
public:
    AlienAlerter() = default;
    ~AlienAlerter() = default;
    void onAlert(std::string strAlert) {
        std::cout << strAlert << std::endl;
        m_signal_waring.emit("please run away!!");
    }

    enum class ConnectorType{
        TYPE_1,
        TYPE_2,
        TYPE_3
    };

    sigc::signal <void(std::string)> m_signal_waring;
};

class People {
public:
    People() = default;
    ~People() = default;
    void onWarning(std::string str)
    {
        std::cout << str << std::endl;
        std::cout << "We are OK!" << std::endl;
    }

    void onAtShelter(std::string str)
    {
        std::cout << str << std::endl;
        std::cout << "We are alive!" << std::endl;
    }

};

// detector --> AlienDetector::appear --> AlienAlerter::alert --> People::onWarning
int main()
{
    AlienDetector mydetector;
    AlienAlerter myalerter;
    People people;

    mydetector.m_signal_alert.connect( sigc::mem_fun(myalerter, &AlienAlerter::onAlert));
    myalerter.m_signal_waring.connect( sigc::mem_fun(people, &People::onWarning) ); // this is nt called.
    myalerter.m_signal_waring.connect( sigc::mem_fun(people, &People::onAtShelter) ); // this will be called. signal only has one slot

    mydetector.appear();

    return 0;
}
