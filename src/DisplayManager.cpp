#include <Background.hh>
#include <Menu.hh>
#include <Core/Core.hh>
#include "TestPattern.hh"
#include "DisplayManager.hh"
#include "Player.hh"
#include "Input.hh"

DisplayManager::DisplayManager(int width, int height, bool fullscreen) : _alive(true) {
    DamnCute::Core::getInstance()->createWin(width, height, fullscreen);
}

DisplayManager::~DisplayManager() {
}

void DisplayManager::update() {
    _alive = DamnCute::Core::getInstance()->getWindowStatus();
}

void DisplayManager::menuMode() {
    std::vector<std::string> listOption;

    /*DamnCute::Menu *menu = new DamnCute::Menu("resources/menu.jpg");
      _engine->addObject(menu);
      menu->setTextureButton("resources/button1.png");
      menu->addButton(50, 100, "Start game");
      menu->setTextureCursor("resources/cursor.png", -50, 100);*/

    listOption.push_back("Option 1");
    listOption.push_back("Option 2");
    listOption.push_back("Option 3");
    DamnCute::Menu* m = new DamnCute::Menu("resources/title.png"); // Instanciation
    _engine->addObject(m);
    m->setTextureButton("resources/button1.png");//Set texture
    m->addButton(50, 100, "start"); //Pose la texture sur le screen
    m->addButton(50, 400, "Test2"); //Pose la texture sur le screen
    m->addButton(500, 100, "Test3"); //Pose la texture sur le screen
    m->addButton(500, 400, "Test4"); //Pose la texture sur le screen
    m->addSubMenu("Test2", "Sous Menu:", listOption, 50, 50);
    m->addSubMenu("Test2", "Sous Menu2:", listOption, 50, 150);
    m->setTextureCursor("resources/cursor.png", -50, 100);
}

void DisplayManager::run() {
    _engine = DamnCute::Core::getInstance();

    menuMode();
    while (_alive) {
        update();
        _engine->flushScene();
        _engine->flushEvent();
    }
    /*_engine->freeAll();
      _engine->createWin(1920, 1080, false);
      GameMode();
      update();
      while (_alive) {
      update();
      _engine->flushScene();
      _engine->flushEvent();
      }*/
}

bool update() {
    return (DamnCute::Core::getInstance()->getWindowStatus());
}

void gameMode(DamnCute::Core* engine) {

    engine->setFPSDisplay(true);
    Input *input = new Input();
    DamnCute::Background* bg = new DamnCute::Background("resources/decor009.jpg");
    TestPattern* test = new TestPattern();
    //pat1 *p1 = new pat1();
    //CrossingDeath *cd = new CrossingDeath();


    DamnCute::APlayer* player_one = new DamnCute::Player<0>();
    DamnCute::APlayer* player_two = new DamnCute::Player<1>("resources/player_focus.tga", 800, 400);
    input->parseConfigFile(player_one, player_two);

    engine->addOnBg(bg);
    engine->addObject(test);
    //engine->addObject(p1);
    //engine->addObject(cd);
    engine->addObject(player_one);
    //engine->addObject(player_two);
    engine->switchGameStatus();
}


void runGame()
{
    DamnCute::Core* engine;

    engine = DamnCute::Core::getInstance();
    engine->freeAll();
    engine->createWin(1920, 1080, false);
    gameMode(engine);
    while (update()) {
        engine->flushScene();
        engine->flushEvent();
    }
    //  exit(1);
}
