#ifndef SPINDLE_HH_
#define SPINDLE_HH_

#include "Cable.hh"

namespace ai {
namespace becca {

class Spindle {
public:
	Spindle();
	virtual ~Spindle();

	void sendActivity(Cable *cable);
};

} /* namespace becca */
} /* namespace ai */
#endif /* SPINDLE_HH_ */
