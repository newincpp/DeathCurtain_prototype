#include <SFML/Graphics/Text.hpp>
#include "Menu.hh"

DamnCute::Menu::SubMenu::SubMenu(sf::Text &text, const std::string &optionName, std::vector<sf::Text *> optionChoice) : _text(text), _options(optionChoice) {
    _posx = 400;
    _posy = 90;
    _it = _options.begin();
    _text.setPosition(_posx, _posy);
    (*_it)->setPosition(_posx, _posy + 80);
    if (optionName == optionName)
        return;
}

void DamnCute::Menu::SubMenu::update(sf::RenderWindow* w_ptr) {
    w_ptr->draw(_text); //Rajouter le txt au bouton
    w_ptr->draw(*(*_it));
}

DamnCute::Menu::SubMenu::~SubMenu()
{


}

DamnCute::Menu::Button::Button(sf::Text &text, int x, int y, sf::Texture& t) : _tex(t), _text(text) {
    _s.setTexture(_tex);
    _s.setPosition(x, y);
    _text.setPosition(x+40, y+90);
}

void DamnCute::Menu::Button::update(sf::RenderWindow* w_ptr) {
    w_ptr->draw(_s);
    w_ptr->draw(_text); //Rajouter le txt au bouton
}

DamnCute::Menu::Button::~Button() {
}

/********************************************************/
/********************* MENU *****************************/
/********************************************************/

DamnCute::Menu::Menu(const std::string& texfile) : IRenderable(), _bg(texfile)  {
    _font.loadFromFile(FONT_PATH);
    clicked = false;
}

DamnCute::Menu::~Menu() {
    Core* e = Core::getInstance();
    for (std::vector<Button*>::iterator it = _buttons.begin() ; it != _buttons.end(); ++it) {
        e->delObject(*it);
    }

}

void DamnCute::Menu::update(sf::RenderWindow* win) {
    _bg.update(win);
}

void DamnCute::Menu::setTextureButton(const std::string& filename) {
    _tex.loadFromFile(filename);
}

void DamnCute::Menu::addButton(int x, int y, const std::string& text) {
    sf::Text test(text, _font, _characterSize);

    test.setColor(sf::Color::Black);
    Button* b = new Button(test, x, y, _tex);
    _buttons.push_back(b);
    Core::getInstance()->addObject(b);
}

void DamnCute::Menu::addSubMenu(const std::string &Button, const std::string &Option, std::vector<std::string> listOption )
{
    sf::Text test(Option, _font, _characterSize);
    std::vector<sf::Text *> listoption2;

    for (std::vector<std::string>::iterator it = listOption.begin() ; it != listOption.end(); ++it) {
        listoption2.push_back(new sf::Text(*it, _font, _characterSize));
    }
    SubMenu *b = new SubMenu(test, Option, listoption2);
    Core::getInstance()->addObject(b);
}
