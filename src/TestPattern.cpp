#include <glm/gtc/matrix_transform.hpp>
#include "TestPattern.hh"

TestPattern::TestPattern() : APattern() {
    initialize();
}

void TestPattern::initialize() {
    glm::mat4 m;

    m = glm::translate(glm::mat4(), glm::vec3(0, -7, 0));
    DamnCute::Path* p = new DamnCute::Path(m, 5, DamnCute::Bullet(glm::vec2(200,500.0f), 0), "resources/mu.tga");
    DamnCute::Path* p1 = new DamnCute::Path(m, 10, DamnCute::Bullet(glm::vec2(400,500), 0), "resources/mu.tga");
    m = glm::translate(glm::mat4() , glm::vec3(0, 10, 0));
    DamnCute::Path* p2 = new DamnCute::Path(m, 5, DamnCute::Bullet(glm::vec2(300.0f,1000.0), 0), "resources/pink-bullet.tga");

    m = glm::translate(glm::rotate(glm::mat4(), 1.0f, glm::vec3(0.0f, 0.0f, 1.0f)), glm::vec3(0, -5, 0));
    DamnCute::Path* q = new DamnCute::Path(m, 3, DamnCute::Bullet(glm::vec2(400.0, 500.0), 0, 900), "resources/pink-bullet.tga");

    m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(0.0f, 0.0f, 1.0f)), glm::vec3(0, -5, 0));
    DamnCute::Path* q2 = new DamnCute::Path(m, 10, DamnCute::Bullet(glm::vec2(400.0, 50.0f), 0), "resources/pink-bullet.tga");

    addPath(p);
    addPath(p1);
    addPath(p2);
    addPath(q);
    addPath(q2);
}

pat2::pat2() : APattern() {
    initialize();
}

void pat2::initialize() {
    glm::mat4 m;

    m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(2.0f, 4.0f, -2.0f)), glm::vec3(0, -5, -5));
    DamnCute::Path *a1 = new DamnCute::Path(m, 2, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    /*
       c'est un putain de rond en 3D trop cool pour faire comme sur touhou, tu sais, sur le 8 avec les cercles qui se referment
       ben là c'est la même idée
       m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(0.4f, 3.0f, -2.9f)), glm::vec3(0, -5, -5));
       DamnCute::Path *a4 = new DamnCute::Path(m, 2, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");*/

    addPath(a1);
}

pat1::pat1() : APattern() {
    initialize();
}

void pat1::labyrinth(int z) {

    int grp;
    glm::mat4 m;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> bullet_space(1, 3);
    std::uniform_int_distribution<int> lateral_space(25, 65);

    for (int i = 5; i < 25; ++i) {

        z += lateral_space(generator);
        m = glm::translate(glm::mat4(), glm::vec3(0, -20, -i));
        DamnCute::Path *pattern = new DamnCute::Path(m, bullet_space(generator), DamnCute::Bullet(glm::vec2(z, 40.0f), 0, 500), "resources/pink-bullet.tga");
        pattern->countdownSetMoveModifier(55, glm::rotate(glm::translate(glm::mat4(), glm::vec3(0, -1, -i)), 1.0f, glm::vec3(2.0f, 4.0f, -2.0f)));
        grp = addPath(pattern);
        labyrinthGroup.push_back(grp);
    }
}

void pat1::up() {

    _timeframe--;
    if (_timeframe == 0) {
        switchGen();
        /*for (size_t i = 0; i < labyrinthGroup.size(); ++i) {
            setTimeSeparator(50, i);
        }
        for (size_t i = 0; i < _paths.size(); ++i) {
            countdownSetMoveModifier(60, glm::translate(glm::mat4(), glm::vec3(-15, 0, 0)), i);
        }*/
    }
}

void pat1::a_roulette() {

    std::cout << "VROUM VROUM" << std::endl;
}

void pat1::initialize() {

    //labyrinth(600);
    glm::mat4 m; 

    m = glm::translate(glm::mat4(), glm::vec3(0, -20, -4));
    DamnCute::Path *pattern = new DamnCute::Path(m, 10, DamnCute::Bullet(glm::vec2(400, 40.0f), 0, 500), "resources/pink-bullet.tga");
    pattern->countdownSetMoveModifier(60, glm::translate(glm::mat4(), glm::vec3(0, 0, -4)));
    addPath(pattern);
}





CrossingDeath::CrossingDeath() {
    initialize();
}

void CrossingDeath::generate(int direction, int start, int stop, int step) {

    glm::mat4 m;
    glm::mat4 m1;
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 0.0f);

    m = glm::translate(glm::mat4(), glm::vec3(direction, -2, direction));
    for (int i = start; i < stop; i += step) {
        m1 *= glm::rotate(glm::mat4(), 1.0f, glm::vec3(0, 0, 1));
        vec = m1 * vec;
        m = glm::translate(glm::mat4(), glm::vec3(vec.x, vec.y, vec.z));
        DamnCute::Path *pattern = new DamnCute::Path(m, 15, DamnCute::Bullet(glm::vec2(i, 600.0f), 0, 1000), "resources/pink-bullet.tga");
        addPath(pattern);
    }
}

void CrossingDeath::initialize() {

    generate(-14, 800, 1300, 1);
    //generate(5, 1100, 1300, 60);
}
