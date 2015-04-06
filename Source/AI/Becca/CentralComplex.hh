#ifndef CENTRALCOMPLEX_HH_
#define CENTRALCOMPLEX_HH_

#include "Hub.hh"
#include "Spindle.hh"
#include "MainSpring.hh"
#include "ArborKey.hh"
#include "Cable.hh"

#include <cstdlib>

namespace ai {
namespace becca {

class CentralComplex {
public:
	CentralComplex();
	virtual ~CentralComplex();

	void sendActivity(Cable *cable);
private:
	Hub *mHub = NULL;
	Spindle *mSpindle = NULL;
	MainSpring *mMainSpring = NULL;
	ArborKey *mArborKey = NULL;
};

} /* namespace becca */
} /* namespace ai */
#endif /* CENTRALCOMPLEX_HH_ */
