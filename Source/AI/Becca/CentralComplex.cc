#include "CentralComplex.hh"

namespace ai {
namespace becca {

CentralComplex::CentralComplex() {
	mHub = new Hub;
	mSpindle = new Spindle;
	mMainSpring = new MainSpring;
	mArborKey = new ArborKey;
}

CentralComplex::~CentralComplex() {
	delete mHub;
	delete mSpindle;
	delete mMainSpring;
	delete mArborKey;
}

void CentralComplex::sendActivity(Cable *cable) {
	mHub->sendActivity(cable);
	mSpindle->sendActivity(cable);
	mMainSpring->sendActivity(cable);
}

} /* namespace becca */
} /* namespace ai */
