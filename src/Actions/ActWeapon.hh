#ifndef ACTWEAPON_H_
# define ACTWEAPON_H_

#include <SFML/Graphics.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Core/Core.hh"
#include "APattern.hh"

class ShootPattern : public DamnCute::APattern {
    public:
        explicit ShootPattern(glm::vec2 v) : _v(v) {
            initialize();
        }

        virtual ~ShootPattern() = default;
        virtual void initialize() {

            glm::mat4 m;
            /*m = glm::translate(glm::mat4(), glm::vec3(0, 15, 0));
              _z = new DamnCute::Path(m, 6, DamnCute::Bullet(_v, 0, 120), "resources/pink-bullet.tga");
              addPath(_z);*/

            m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(0.0f, 4.0f, -2.0f)), glm::vec3(0, -5, -5));
            _z = new DamnCute::Path(m, 3, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");
            addPath(_z);
        }

    private:
        DamnCute::Path *_z;
        glm::vec2 _v;
};

class ActWeapon : public DamnCute::AAction<DamnCute::APlayer>
{

    public:
        explicit ActWeapon(DamnCute::APlayer *p, sf::Keyboard::Key k1, int button)
            : AAction(p, k1, button) {
                _engine = DamnCute::Core::getInstance();
                _sp = new ShootPattern(convertVec(_entity->getPlayer().getPosition()));
                _name = "ActWeapon";
                _engine->addObject(_sp);
            }

        bool hasInput(int nbPlayer) {
            _nbPlayer = nbPlayer;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                _sp->countdownPushMoveModifier(60, glm::translate(glm::mat4(), glm::vec3(-15, 0, 0)), 0);
                _sp->countdownPushMoveModifier(60, glm::translate(glm::mat4(), glm::vec3(15, 0, 0)), 0);
            }
            if (sf::Keyboard::isKeyPressed(_key1))
                return true;
            else if (sf::Joystick::isButtonPressed(_nbPlayer, _stickButton) == true)
                return true;
            else {
                _sp->setStatusGen(false);
                return false;
            }
        }

        glm::vec2 convertVec(sf::Vector2f v) {
            return glm::vec2(float(v.x), float(v.y));
        }

        void execute() {
            _sp->setStatusGen(true);
            _sp->moveOrigin(convertVec(_entity->getPlayer().getPosition()));
        }

        virtual inline const std::string& getName() const { return _name; }

        virtual ~ActWeapon() = default;

    private:
        int _nbPlayer;
        std::string _name;
        ShootPattern *_sp;
        DamnCute::Core *_engine;

};

#endif /* !ACTWEAPON_H_ */
