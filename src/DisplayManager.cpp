#include <Background.hh>
#include "Player.hh"
#include <Menu.hh>
#include <Core/Core.hh>
#include "TestPattern.hh"
#include "DisplayManager.hh"

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
    DamnCute::Background* bg = new DamnCute::Background("ressources/mushihimesama.tga");
    TestPattern* test = new TestPattern();
    DamnCute::Player* player = new DamnCute::
    DamnCute::Player p("ressources/player.tga", 0.1, 0.1);
    bg->setScrollSpeed(0,-0.1f);

    _engine->addObject(bg);
    _engine->addObject(test);
    _engine->addObject(&p);

    _engine->switchGameStatus();
}

void DisplayManager::menuMode() {
    DamnCute::Menu* m = new DamnCute::Menu("ressources/title.png");
    _engine->addObject(m);
    m->setTextureButton("ressources/button1.png");
    m->addButton(50, 100, "start");
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
    _engine->createWin(1920, 1024, false);
    gameMode();
    update();
    while (_alive) {
        update();
        _engine->flushScene();
        _engine->flushEvent();
    }
}
