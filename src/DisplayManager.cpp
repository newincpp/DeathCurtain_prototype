#include <Background.hh>
#include <Menu.hh>
#include <Core/Core.hh>
#include "TestPattern.hh"
#include "DisplayManager.hh"
#include "Player.hh"

DisplayManager::DisplayManager(int width, int height, bool fullscreen) : _alive(true) {
    DamnCute::Core::getInstance()->createWin(width, height, fullscreen);
}

DisplayManager::~DisplayManager() {
}

void DisplayManager::update() {
    _alive  = DamnCute::Core::getInstance()->getWindowStatus();
}

void DisplayManager::gameMode() {
    if (!_engine) {
        _engine = DamnCute::Core::getInstance();
        std::cerr << "game is starting without menu =S" << std::endl;
    }
    _engine->setFPSDisplay(true);
    DamnCute::Background* bg = new DamnCute::Background("resources/mushihimesama.tga");
    //TestPattern* test = new TestPattern();
    pat1 *p1 = new pat1();

    bg->setScrollSpeed(0, -0.1f);

    DamnCute::APlayer* player_one = new DamnCute::Player<0>();
    DamnCute::APlayer* player_two = new DamnCute::Player<1>("resources/player_focus.tga", 800, 400);

    _engine->addOnBg(bg);
    //_engine->addObject(test);
    _engine->addObject(p1);
    _engine->addObject(player_one);
    _engine->addObject(player_two);

    _engine->switchGameStatus();
}

void DisplayManager::menuMode() {
    std::vector<std::string> listOption;

    listOption.push_back("Option 1");
    listOption.push_back("Option 2");
    listOption.push_back("Option 3");
    DamnCute::Menu* m = new DamnCute::Menu("resources/title.png"); // Instanciation
    _engine->addObject(m);
    m->setTextureButton("resources/button1.png");/*Set texture*/
    m->addButton(50, 100, "start"); /*Pose la texture sur le screen*/
    m->addSubMenu("Button Name", "Sous Menu:", listOption);
}

void DisplayManager::run() {
    _engine = DamnCute::Core::getInstance();

    menuMode();
    while (_alive) {
        update();
        _engine->flushScene();
        _engine->flushEvent();
    }
    _engine->freeAll();
    _engine->createWin(1920, 1080, false);
    //_engine->createWin();
    gameMode();
    update();
    while (_alive) {
        update();
        _engine->flushScene();
        _engine->flushEvent();
    }
}
