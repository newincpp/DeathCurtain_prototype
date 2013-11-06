//
// Menu.cpp for damncute in /home/strohe_d/Svn/DeathCurtain_prototype
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed Oct 30 01:33:44 2013 Dorian Stroher
// Last update Thu Oct 31 03:20:53 2013 Dorian Stroher
//

#include "ActMenu.hh"
#include <SFML/Graphics/Text.hpp>
#include "Menu.hh"

void runGame();

DamnCute::Menu::SubMenu::SubMenu(sf::Text &text, const std::string &optionName, std::vector<sf::Text *> optionChoice) : _text(text), _options(optionChoice) {
    _it = _options.begin();
    _alive = false;
    if (optionName == optionName)
        return;
}

void	DamnCute::Menu::SubMenu::update(sf::RenderTarget* w_ptr) {
    if (_alive == true)
    {
        w_ptr->draw(_text); //Rajouter le txt au bouton
        w_ptr->draw(*(*_it));
    }
}

DamnCute::Menu::SubMenu::~SubMenu()
{


}

DamnCute::Menu::Button::Button(const std::string &Name, sf::Text &text, int x, int y, sf::Texture& t) : _name(Name), _tex(t), _text(text) {
    _alive = true;
    _x = x;
    _y = y;
    _s.setTexture(_tex);
    _s.setPosition(x, y);
    _text.setPosition(x+40, y+90);
}

void	DamnCute::Menu::Button::update(sf::RenderTarget* w_ptr) {
    if (_alive == true)
    {
        w_ptr->draw(_s);
        w_ptr->draw(_text); //Rajouter le txt au bouton
    }
}

DamnCute::Menu::Button::~Button() {
}

/********************************************************/
/********************* MENU *****************************/
/********************************************************/

DamnCute::Menu::Menu(const std::string& texfile) : IRenderable(), _bg(texfile)  {
    Core* e = Core::getInstance();
    DamnCute::Background* bg = new DamnCute::Background("resources/title.png");

    e->addOnBg(bg);
    _actions.push_back(new ActMenu(this, sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Joystick::Y));
    _actions.push_back(new ActMenu(this, sf::Keyboard::Key::Right, sf::Keyboard::Key::Left, sf::Joystick::R));
    _actions.push_back(new ActMenu(this, sf::Keyboard::Key::Return, sf::Keyboard::Key::Escape, sf::Joystick::X));
    _font.loadFromFile(FONT_PATH);
    _clicked = false;
    _clicked2 = false;
    _alive = true;
}

DamnCute::Menu::~Menu() {
    Core* e = Core::getInstance();
    for (std::vector<Button*>::iterator it = _buttons.begin() ; it != _buttons.end(); ++it) {
        e->delObject(*it);
    }

}

void	DamnCute::Menu::update(sf::RenderTarget* win) {
    for (size_t i = 0; i < _actions.size(); ++i)
    {
        if (_actions[i]->hasInput(2) == true)
        {
            if (_clicked != true)
                _actions[i]->execute();
            _clicked =true;
            _clicked2 = true;
        }
    }
    if (_clicked2 == false)
        _clicked = false;
    _clicked2 = false;
    if (_alive == true)
    {
        _cursor->setPosition((*_itButtons)->getX() + _cursPosX, (*_itButtons)->getY() + _cursPosY);
        win->draw(*_cursor);
    }
}

void	DamnCute::Menu::setTextureButton(const std::string& filename) {
    _tex.loadFromFile(filename);
}

void	DamnCute::Menu::setTextureCursor(const std::string& filename, int x, int y) {
    sf::Texture tmp;

    _tex2.loadFromFile(filename);
    _cursor = new sf::Sprite(_tex2);
    _cursPosX = x;
    _cursPosY = y;
    /*_cursor->setTexture(*_tex2);*/
}

void	DamnCute::Menu::addButton(int x, int y, const std::string& text) {
    sf::Text test(text, _font, _characterSize);

    test.setColor(sf::Color::Black);
    Button* b = new Button(text, test, x, y, _tex);
    _buttons.push_back(b);
    Core::getInstance()->addObject(b);
    _itButtons = _buttons.begin();
}

void	DamnCute::Menu::addSubMenu(const std::string &Button, const std::string &Option, std::vector<std::string> listOption, int x, int y)
{
    sf::Text test(Option, _font, _characterSize);
    std::vector<sf::Text *> listoption2;
    sf::Text *tmp;
    test.setPosition(x, y);
    for (std::vector<std::string>::iterator it = listOption.begin() ; it != listOption.end(); ++it) {
        tmp = new sf::Text(*it, _font, _characterSize);
        tmp->setPosition(x+15, y + 25);
        listoption2.push_back(tmp);
    }
    SubMenu *b = new SubMenu(test, Option, listoption2);
    for (std::vector<DamnCute::Menu::Button*>::iterator it = _buttons.begin() ; it != _buttons.end(); ++it)
        if ((*it)->getName() == Button)
            (*it)->addSubMenu(b);
    Core::getInstance()->addObject(b);
}

void	DamnCute::Menu::MoveDown()
{
    std::cout << "MoveDown " << std::endl;
    if (_alive)
    {
        if (_itButtons + 1 != _buttons.end())
            _itButtons++;
        else
            _itButtons = _buttons.begin();
    }
    else
        (*_itButtons)->MoveUp();
}

void	DamnCute::Menu::MoveUp()
{
    std::cout << "Moveup" << std::endl;
    if (_alive)
    {
        if (_itButtons != _buttons.begin())
            _itButtons--;
        else
        {
            if (_buttons.size() > 1)
            {
                while(_itButtons !=  _buttons.end())
                {
                    _itButtons++;
                }
                _itButtons--;
            }
            else
                _itButtons = _buttons.begin();
        }
    }
    else
        (*_itButtons)->MoveUp();
}

void	DamnCute::Menu::MoveReturn()
{
    if (_alive)
    {
        if( (*_itButtons)->getName() == "start")
        {
            runGame();
            delete(this);
        }
        _alive = false;
    }
    else
        _alive = true;
    (*_itButtons)->setAlive2();
    for (std::vector<DamnCute::Menu::Button*>::iterator it = _buttons.begin() ; it != _buttons.end(); ++it)
        (*it)->setAlive();
}

void	DamnCute::Menu::MoveRight()
{
    if (_alive == false)
    {
        (*_itButtons)->MoveRight();
    }
}

void	DamnCute::Menu::Button::MoveRight()
{
    (*_itSub)->MoveRight();
}

void	DamnCute::Menu::MoveLeft()
{
    if (_alive == false)
    {
        (*_itButtons)->MoveLeft();
    }
}

void	DamnCute::Menu::Button::MoveDown()
{
    if (_itSub + 1 != _Sub.end())
        _itSub++;
    else
        _itSub = _Sub.begin();
}

void	DamnCute::Menu::Button::MoveUp()
{
    if (_itSub != _Sub.begin())
        _itSub--;
    else
    {
        if (_Sub.size() > 1)
        {
            while(_itSub !=  _Sub.end())
            {
                _itSub++;
            }
            _itSub--;
        }
        else
            _itSub = _Sub.begin();
    }
}

void	DamnCute::Menu::Button::MoveLeft()
{
    (*_itSub)->MoveLeft();
}

void	DamnCute::Menu::SubMenu::MoveRight()
{
    if (_it + 1 != _options.end())
        _it++;
    else
        _it = _options.begin();
}

void	DamnCute::Menu::SubMenu::MoveLeft()
{
    if (_it != _options.begin())
        _it--;
    else
    {
        if (_options.size() > 1)
        {
            while(_it !=  _options.end())
            {
                _it++;
            }
            _it--;
        }
        else
            _it = _options.begin();
    }
}
