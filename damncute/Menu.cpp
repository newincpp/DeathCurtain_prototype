#include "Menu.hh"

DamnCute::Menu::Button::Button(const std::string& text, int x, int y, sf::Texture& t) : _tex(t), _text(text) {
    _s.setTexture(_tex);
    _s.setPosition(x, y);
}

void DamnCute::Menu::Button::update(sf::RenderWindow* w_ptr) {
    w_ptr->draw(_s);
}

DamnCute::Menu::Button::~Button() {
}

/********************************************************/
/********************* MENU *****************************/
/********************************************************/

DamnCute::Menu::Menu(const std::string& texfile) : IRenderable(), _bg(texfile)  {
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
    Button* b = new Button(text, x, y, _tex);
    _buttons.push_back(b);
    Core::getInstance()->addObject(b);
}
