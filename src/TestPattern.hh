#ifndef TESTPATTERN_H_
# define TESTPATTERN_H_

#include "../damncute/APattern.hh"

class TestPattern : public DamnCute::APattern {
    public:
	explicit TestPattern();
	virtual ~TestPattern();
	virtual void initialize();

};


#endif /* !TESTPATTERN_H_ */
