#ifndef IMENU_H_
# define IMENU_H_
# define FONT_PATH "resources/font.ttf"

#include <vector>
#include <string>
#include <type_traits>
#include <SFML/Graphics.hpp>
//#include "ActMenu.hh"
#include "Background.hh"
#include "Core/Core.hh"

namespace DamnCute {
    class Menu : public IRenderable {
        private:
            template<bool C>
                class IfThenElse {
                    public:
                        enum {
                            value = C
                        };
                };

            class SubMenu : public IRenderable {
                public:
                    explicit SubMenu(sf::Text &, const std::string & , std::vector<sf::Text *>);
                    inline void operator=(const SubMenu& b) {
                        _text = b._text;
                    }
                    virtual void update(sf::RenderWindow*);
                    virtual ~SubMenu();
                private:
                    int _posx;
                    int _posy;
                    sf::Text _text;
                    std::vector<sf::Text *>::iterator _it;
                    std::vector<sf::Text *> _options;
            };
            class Button : public IRenderable {
                public:
                    explicit Button(sf::Text &, int, int, sf::Texture&);
                    inline void operator=(const Button& b) {
                        _tex = b._tex;
                        _s = b._s;
                        _text = b._text;
                    }
                    virtual void update(sf::RenderWindow*);
                    virtual ~Button();
                private:
                    sf::Sprite _s;
                    sf::Texture& _tex;
                    sf::Text _text;
            };
        private:
            unsigned int _characterSize=20;
            sf::Font _font;
            bool clicked;
            Background _bg;
            sf::Texture _tex;
            std::vector<Button*> _buttons;
        public:
            explicit Menu(const std::string& texfile);
            virtual ~Menu();
            virtual void update(sf::RenderWindow* win);
            template <int ID> void setButton(Button* b) {
                static_assert(IfThenElse<_buttons.size() < ID>::value, "ID is out of bounds");
                _buttons[ID] = b;
            }
            void setTextureButton(const std::string&);
            void addButton(int x, int y, const std::string&);
            void addSubMenu(const std::string &Button, const std::string &Option /*Nom de l'option*/, std::vector<std::string> listOption );
    };
}

#endif /* !IMENU_H_ */
