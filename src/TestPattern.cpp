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
    glm::mat4 m1;
    glm::mat4 m2;


    m = glm::rotate(glm::translate(glm::mat4(), glm::vec3(0, 5, 0)), -1.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    DamnCute::Path *a1 = new DamnCute::Path(m, 2, DamnCute::Bullet(glm::vec2(700, 400.0f), 0, 2000), "resources/pink-bullet.tga");

    /*m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(2.0f, 4.0f, -2.0f)), glm::vec3(0, -5, -5));
    DamnCute::Path *a1 = new DamnCute::Path(m, 2, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(-2.0f, -4.0f, -2.0f)), glm::vec3(0, -5, -5));
    DamnCute::Path *a2 = new DamnCute::Path(m, 2, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");*/

    /*m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(4.0f, 4.0f, -2.0f)), glm::vec3(0, -5, -5));
      DamnCute::Path *a2 = new DamnCute::Path(m, 3, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");

      m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(6.5f, 4.5f, -2.0f)), glm::vec3(0, -5, -5));
      DamnCute::Path *a3 = new DamnCute::Path(m, 3, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");

      m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(8.5f, 5.5f, -2.0f)), glm::vec3(0, -5, -5));
      DamnCute::Path *a4 = new DamnCute::Path(m, 3, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");

      m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(0.05f, 4.5f, -2.0f)), glm::vec3(0, -5, -5));
      DamnCute::Path *a5 = new DamnCute::Path(m, 1, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");*/

    /*
       c'est un putain de rond en 3D trop cool pour faire comme sur touhou, tu sais, sur le 8 avec les cercles qui se referment
       ben là c'est la même idée
       m = glm::translate(glm::rotate(glm::mat4(), -1.0f, glm::vec3(0.4f, 3.0f, -2.9f)), glm::vec3(0, -5, -5));
       DamnCute::Path *a4 = new DamnCute::Path(m, 2, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");*/

    /*m = glm::translate(m, glm::vec3(-1, 0, 0));
      DamnCute::Path *a2 = new DamnCute::Path(m, 3, DamnCute::Bullet(glm::vec2(1300, 40.0f), 0, 2000), "resources/pink-bullet.tga");*/


    /*m1 = glm::rotate(m, float(M_PI_2), glm::vec3(1, 0, 0));
      m2 = glm::translate(m1, glm::vec3(-1, 0, 0));
      DamnCute::Path *a2 = new DamnCute::Path(m2, 3, DamnCute::Bullet(glm::vec2(1400, 40.0f), 0, 2000), "resources/pink-bullet.tga");*/

    addPath(a1);
    //addPath(a2);
    /*  addPath(a3);
      addPath(a4);
      addPath(a5);*/
}

pat1::pat1() : APattern() {
    initialize();
}

void pat1::initialize() {
    glm::mat4 m;
    // bullet labyrinth

    m = glm::translate(glm::mat4(), glm::vec3(-5, -35, -5));
    DamnCute::Path *a1 = new DamnCute::Path(m, 8, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -5));
    DamnCute::Path *b1 = new DamnCute::Path(m, 8, DamnCute::Bullet(glm::vec2(700, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -6));
    DamnCute::Path *b2 = new DamnCute::Path(m, 8, DamnCute::Bullet(glm::vec2(650, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -7));
    DamnCute::Path *b3 = new DamnCute::Path(m, 6, DamnCute::Bullet(glm::vec2(600, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -8));
    DamnCute::Path *b4 = new DamnCute::Path(m, 12, DamnCute::Bullet(glm::vec2(550, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -9));
    DamnCute::Path *b5 = new DamnCute::Path(m, 14, DamnCute::Bullet(glm::vec2(500, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -5));
    DamnCute::Path *c1 = new DamnCute::Path(m, 8, DamnCute::Bullet(glm::vec2(750, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -6));
    DamnCute::Path *c2 = new DamnCute::Path(m, 8, DamnCute::Bullet(glm::vec2(800, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -7));
    DamnCute::Path *c3 = new DamnCute::Path(m, 6, DamnCute::Bullet(glm::vec2(850, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -8));
    DamnCute::Path *c4 = new DamnCute::Path(m, 12, DamnCute::Bullet(glm::vec2(900, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    m = glm::translate(glm::mat4(), glm::vec3(0, -3, -9));
    DamnCute::Path *c5 = new DamnCute::Path(m, 14, DamnCute::Bullet(glm::vec2(670, 40.0f), 0, 2000), "resources/pink-bullet.tga");

    addPath(b1);
    addPath(b2);
    addPath(b3);
    addPath(b4);
    addPath(b5);
    addPath(c1);
    addPath(c2);
    addPath(c3);
    addPath(c4);
    addPath(c5);
}
