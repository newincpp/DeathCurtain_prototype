#include <Environment.hh>
//#include "example/Player.hh"
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
    DamnCute::Environment* bg = new DamnCute::Environment("ressources/mushihimesama.tga");
    TestPattern* test = new TestPattern();
    //DamnCute::Player p;
    bg->setSpeed(0,-0.1f);

    _engine->addObject(bg);
    _engine->addObject(test);
    //_engine->addObject(&p);

    _engine->switchGameStatus();
}

void DisplayManager::menuMode() {
    _engine->addObject(new DamnCute::Menu("ressources/title.png"));
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