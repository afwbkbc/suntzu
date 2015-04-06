#ifndef HUB_HH_
#define HUB_HH_

#include "Cable.hh"

namespace ai {
namespace becca {

class Hub {
public:
	Hub();
	virtual ~Hub();

	void sendActivity(Cable *cable);
};

} /* namespace becca */
} /* namespace ai */
#endif /* HUB_HH_ */
