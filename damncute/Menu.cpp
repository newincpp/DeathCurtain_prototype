#include "Menu.hh"
#include <SFML/Graphics/Text.hpp>

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
  sf::Font *font = new sf::Font();
  unsigned int characterSize=80;
  sf::Text *test;

  font->loadFromFile(FONT_PATH);
  test = new sf::Text(text, *font, characterSize);
  test->setColor(sf::Color::Black);
  Button* b = new Button(*test, x, y, _tex);
  _buttons.push_back(b);
  Core::getInstance()->addObject(b);
}
