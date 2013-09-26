#ifndef IMENU_H_
# define IMENU_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <type_traits>

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

	    class Button : public IRenderable {
		public:
		    explicit Button(const std::string&, int, int, sf::Texture&);
		    inline void operator=(const Button& b) {
			_tex = b._tex;
			_s = b._s;
		    }
		    virtual void update(sf::RenderWindow*);
		    virtual ~Button();
		private:
		    sf::Sprite _s;
		    sf::Texture& _tex;
		    const std::string _text;
	    };
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
    };
}

#endif /* !IMENU_H_ */
