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

};

class pat2 : public DamnCute::APattern {
    public:
        explicit pat2();
        virtual ~pat2() = default;
        virtual void initialize();

};

#endif /* !TESTPATTERN_H_ */
