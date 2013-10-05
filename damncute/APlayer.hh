#ifndef APLAYER_H_
# define APLAYER_H_

#include <iostream>
#include <vector>
#include <type_traits>
#include "AAction.hh"
#include "IRenderable.hh"
#include "Core/Core.hh"

namespace DamnCute
{

    class APlayer : public IRenderable
    {

	public:
	    explicit APlayer(const std::string& = "ressources/player.tga",
		    float = 980, float = 950, int nbPlayer = 1, int speed = 5);
	    virtual ~APlayer() = default;

	    void update(sf::RenderWindow*);
	    void addAction(AAction*);

	    inline sf::Sprite& getPlayer() { return _player; }
	    inline sf::Texture& getTexture() { return _tex; }
	    inline int& getSpeed() { return _speed; }
	    inline int getNumPlayer() const { return _nbPlayer; }

	    template <int inputNumber, typename T>
		void setAction(const std::string& name, T t) {

		    for (size_t i = 0; i < _actions.size(); ++i) {
			if (name == (_actions[i])->getName())
			    setActionInput(i, t, inputNumber);
		    }
		}

	    template <typename T>
		void setActionInput(int i, T t, int a) {
		    (void)i; (void)t; (void)a;
		    static_assert(std::is_same<T, int>::value || std::is_same<T, sf::Keyboard::Key>::value || std::is_same<T, sf::Joystick::Axis>::value, "Error: type is not defined for input.");
		}

	private:
	    void action();
	    APlayer& operator=(const APlayer&);
	    std::vector<AAction*> _actions;

	    sf::Sprite _player;
	    sf::Texture _tex;
	    sf::Event _event;
	    int _speed;
	    int _nbPlayer;
    };

}

#endif
