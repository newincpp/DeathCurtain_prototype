#include <iostream>
#include <fstream>
#include <sstream>
#include <APlayer.hh>

class Input {

    private:
        std::string _file;
        bool _hasKey1;
        bool _hasKey2;
        bool _hasStick;
        bool _hasButton;
        int _key1 = 0;
        int _key2 = 0;
        int _stick = 0;
        int _button = 0;
        std::string _action;
        void parseArguments(DamnCute::APlayer*, std::string&);
        void saveKeys(std::string);
        void saveStick(std::string);
        void saveButton(std::string);

    public:
        Input(std::string configFile = std::string(".config")) : _file(configFile) {}
        ~Input() = default;

        void parseConfigFile(DamnCute::APlayer *, DamnCute::APlayer *);

};
