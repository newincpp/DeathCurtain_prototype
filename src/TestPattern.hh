#ifndef TESTPATTERN_H_
# define TESTPATTERN_H_

#include "APattern.hh"

class TestPattern : public DamnCute::APattern {
    public:
        explicit TestPattern();
        virtual ~TestPattern() = default;
        virtual void initialize();

};

class pat1 : public DamnCute::APattern {
    public:
        explicit pat1();
        virtual ~pat1() = default;
        virtual void initialize();
        void up();
        void labyrinth(int);
        void a_roulette();

    private:
        std::vector<int> labyrinthGroup;
        int _timeframe = 60;

};

class pat2 : public DamnCute::APattern {
    public:
        explicit pat2();
        virtual ~pat2() = default;
        virtual void initialize();

};

class CrossingDeath : public DamnCute::APattern {
    public:
        explicit CrossingDeath();
        virtual ~CrossingDeath() = default;
        virtual void initialize();
        void generate(int, int, int, int);
};

#endif /* !TESTPATTERN_H_ */
