#include "Input.hh"

void Input::parseConfigFile(DamnCute::APlayer *player_one, DamnCute::APlayer *player_two) {
    std::ifstream file(_file);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("[1] {") == 0) {
            while (line.find("}") != 0) {
                std::getline(file, line);
                parseArguments(player_one, line);
            }
        }
        if (line.find("[2] {") == 0) {
            while (line.find("}") != 0) {
                std::getline(file, line);
                parseArguments(player_two, line);
            }
        }
    }
}

void Input::parseArguments(DamnCute::APlayer *player, std::string& line) {

    size_t pos_egal;
    size_t pos_key;
    size_t pos_acolade = 0;

    _hasKey1 = false;
    _hasKey2 = false;
    _hasStick = false;
    _hasButton = false;
    if ((pos_egal = line.find(" = ")) != std::string::npos) {
        _action = line.substr(0, pos_egal);

        if ((pos_key = line.find("Key{", pos_egal)) != std::string::npos)
            if ((pos_acolade = line.find_first_of("}", pos_key)) != std::string::npos)
                saveKeys(line.substr(pos_key + std::string("Key{").size(),
                            pos_acolade - pos_key - std::string("Key{").size()));

        if ((pos_key = line.find("Stick{", (pos_acolade == 0 ? pos_egal : pos_acolade) )) != std::string::npos)
            if ((pos_acolade = line.find_first_of("}", pos_key)) != std::string::npos)
                saveStick(line.substr(pos_key + std::string("Stick{").size(),
                            pos_acolade - pos_key - std::string("Stick{").size()));

        if ((pos_key = line.find("Button{", (pos_acolade == 0 ? pos_egal : pos_acolade) )) != std::string::npos)
            if ((pos_acolade = line.find_first_of("}", pos_key)) != std::string::npos)
                saveButton(line.substr(pos_key + std::string("Button{").size(),
                            pos_acolade - pos_key - std::string("Button{").size()));
    }
    if (_hasKey1) {
        player->setAction<1, sf::Keyboard::Key>(_action, sf::Keyboard::Key(_key1));
    }
    if (_hasKey2) {
        player->setAction<2, sf::Keyboard::Key>(_action, sf::Keyboard::Key(_key2));
    }
    if (_hasStick) {
        player->setAction<0, sf::Joystick::Axis>(_action, sf::Joystick::Axis(_stick));
    }
    if (_hasButton) {
        player->setAction<0, int>(_action, _button);
    }
}

void Input::saveKeys(std::string key)
{
    std::istringstream k(key);
    _hasKey1 = true;
    if (key.find(" ") != std::string::npos)
        _hasKey2 = true;
    k >> _key1;
    k >> _key2;
}

void Input::saveStick(std::string stick)
{
    _hasStick = true;
    std::istringstream(stick) >> _stick;
}

void Input::saveButton(std::string button)
{
    _hasButton = true;
    std::istringstream(button) >> _button;
}
