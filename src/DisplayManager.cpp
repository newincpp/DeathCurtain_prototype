#include <Environment.hh>
//#include "example/Player.hh"
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

void DisplayManager::run() {
    DamnCute::Core* engine = DamnCute::Core::getInstance();

    DamnCute::Environment bg("ressources/mushihimesama.tga");
    TestPattern test;
    //DamnCute::Player p;
    bg.setSpeed(0,-0.1f);

    engine->addObject(&bg);
    engine->addObject(&test);
    //engine->addObject(&p);

    while (_alive) {
	update();
	engine->flushScene();
	engine->flushEvent();
    }
}
