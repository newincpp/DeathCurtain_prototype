#include <glm/gtc/matrix_transform.hpp>
#include "TestPattern.hh"

TestPattern::TestPattern() : APattern() {
    initialize();
}

void TestPattern::initialize() {
    glm::mat4 m;

    m = glm::translate(glm::mat4() , glm::vec3(0, -7, 0));
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
