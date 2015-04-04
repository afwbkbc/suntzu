#ifndef GEARBOX_HH_
#define GEARBOX_HH_

#include "Cable.hh"

#include <vector>

namespace ai {
namespace becca {

class GearBox {
public:
	enum cable_direction_t {
		INPUT,
		OUTPUT,
	};

	GearBox();
	virtual ~GearBox();

	void addCable(cable_direction_t direction, Cable *cable);
private:
	std::vector<Cable *> mActivityInputs;
	std::vector<Cable *> mActivityOutputs;
	std::vector<Cable *> mGoalInputs;
	std::vector<Cable *> mGoalOutputs;
};

} /* namespace becca */
} /* namespace ai */
#endif /* GEARBOX_HH_ */
