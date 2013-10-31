#ifndef IMENU_H_
# define IMENU_H_
# define FONT_PATH "resources/font.ttf"

#include <vector>
#include <string>
#include <type_traits>
#include <SFML/Graphics.hpp>
#include "Background.hh"
#include "AAction.hh"
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
	      void	setAlive(){
		_alive = true;
	      }
                    virtual void update(sf::RenderWindow*);
                    virtual ~SubMenu();
                private:
		    bool _alive;
                    sf::Text _text;
                    std::vector<sf::Text *>::iterator _it;
                    std::vector<sf::Text *> _options;
            };
      class Button : public IRenderable {
	    public:
	      explicit Button(const std::string &, sf::Text &, int, int, sf::Texture&);
                    inline void operator=(const Button& b) {
                        _tex = b._tex;
                        _s = b._s;
                        _text = b._text;
                    }
	void	addSubMenu(SubMenu *b){
	  _Sub.push_back(b);
	}
                    virtual void update(sf::RenderWindow*);
	      int getX(){
		return (_x);
	      }
	      int getY(){
		return (_y);
	      }
	void	setAlive2(){
	  for (std::vector<SubMenu*>::iterator it = _Sub.begin() ; it != _Sub.end(); ++it) {
	    (*it)->setAlive();
	  }
	}
	      void	setAlive() {
		_alive = false;
	      }
	      const std::string getName()
	      {
		return (_name);
	      }
                    virtual ~Button();
                private:
            std::vector<SubMenu*> _Sub;
		    const std::string _name;
	            bool _alive;
	            int _x;
	            int _y;
                    sf::Sprite _s;
                    sf::Texture& _tex;
                    sf::Text _text;
            };
        private:
            unsigned int _characterSize=20;
            sf::Font _font;
            bool _alive;
            bool _clicked;
            bool _clicked2;
            Background _bg;
	    int _cursPosX;
	    int _cursPosY;
            sf::Texture _tex;
            sf::Texture _tex2;
            sf::Sprite *_cursor;
	    std::vector<Button*>::iterator _itButtons;
            std::vector<Button*> _buttons;
            std::vector<AAction<Menu>*> _actions;
        public:
            void    setTextureCursor(const std::string&, int, int);
            explicit Menu(const std::string& texfile);
            virtual ~Menu();
            virtual void update(sf::RenderWindow* win);
            template <int ID> void setButton(Button* b) {
                static_assert(IfThenElse<_buttons.size() < ID>::value, "ID is out of bounds");
                _buttons[ID] = b;
            }
            void setTextureButton(const std::string&);
            void addButton(int x, int y, const std::string&);
      void addSubMenu(const std::string &Button, const std::string &Option /*Nom de l'option*/, std::vector<std::string> listOption, int x, int y);
	    void    MoveDown();
	    void    MoveUp();
            void    MoveReturn();
    };
}

#endif /* !IMENU_H_ */
