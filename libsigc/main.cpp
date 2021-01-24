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

    sigc::signal<void(std::string)>& getConnector(ConnectorType type) {
        switch(type)
        {
        case ConnectorType::TYPE_1:
            return m_signal_alert;
            break;
        case ConnectorType::TYPE_2:
            return m_signal_alert;
            break;
        case ConnectorType::TYPE_3:
            return m_signal_alert;
            break;
        }
    }

private:
    sigc::signal<void(std::string)> m_signal_alert;
};

class AlienAlerter : public sigc::trackable {
public:
    AlienAlerter() = default;
    ~AlienAlerter() = default;
    void onAlert(std::string strAlert) {
        std::cout << strAlert << std::endl;
        std::cout << signal_waring.emit("please run away!!") << std::endl;
    }

    enum class ConnectorType{
        TYPE_1,
        TYPE_2,
        TYPE_3
    };

    sigc::signal<std::string(std::string)>& getConnector(ConnectorType type) {
        switch(type)
        {
        case ConnectorType::TYPE_1:
            return signal_waring;
            break;
        case ConnectorType::TYPE_2:
            return signal_waring;
            break;
        case ConnectorType::TYPE_3:
            return signal_waring;
            break;
        }
    }

private:
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

    std::string onAtShelter(std::string str)
    {
        std::cout << str << std::endl;
        return "We are alive!";
    }
};

// detector --> AlienDetector::appear --> AlienAlerter::alert --> People::onWarning
int main()
{
    AlienDetector mydetector;
    AlienAlerter myalerter;
    People people;

    mydetector.getConnector(AlienDetector::ConnectorType::TYPE_1).connect( sigc::mem_fun(myalerter, &AlienAlerter::onAlert));
    myalerter.getConnector(AlienAlerter::ConnectorType::TYPE_1).connect( sigc::mem_fun(people, &People::onWarning) ); // this is nt called.
    myalerter.getConnector(AlienAlerter::ConnectorType::TYPE_1).connect( sigc::mem_fun(people, &People::onAtShelter) ); // this will be called. signal only has one slot

    mydetector.appear();

    return 0;
}
