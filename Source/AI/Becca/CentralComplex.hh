#ifndef CENTRALCOMPLEX_HH_
#define CENTRALCOMPLEX_HH_

#include "Hub.hh"
#include "Spindle.hh"
#include "MainSpring.hh"
#include "ArborKey.hh"

#include <cstdlib>

namespace ai {
namespace becca {

class CentralComplex {
public:
	CentralComplex();
	virtual ~CentralComplex();

private:
	Hub *mHub = NULL;
	Spindle *mSpindle = NULL;
	MainSpring *mMainSpring = NULL;
};

} /* namespace becca */
} /* namespace ai */
#endif /* CENTRALCOMPLEX_HH_ */
