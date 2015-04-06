#ifndef MAINSPRING_HH_
#define MAINSPRING_HH_

#include "Cable.hh"

namespace ai {
namespace becca {

class MainSpring {
public:
	MainSpring();
	virtual ~MainSpring();

	void sendActivity(Cable *cable);
};

} /* namespace becca */
} /* namespace ai */
#endif /* MAINSPRING_HH_ */
