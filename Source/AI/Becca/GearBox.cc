#include "GearBox.hh"

#include <assert.h>

namespace ai {
namespace becca {

GearBox::GearBox() {

	mZipTie = new ZipTie(this);

}

GearBox::~GearBox() {

	delete mZipTie;

}

void GearBox::addCable(cable_direction_t direction, Cable *cable) {
	Cable::cable_type_t type = cable->getType();
	if (type == Cable::cable_type_t::ACTIVITY) {
		if (direction == cable_direction_t::INPUT)
			mActivityInputs.push_back(cable);
		else if (direction == cable_direction_t::OUTPUT)
			mActivityOutputs.push_back(cable);
		else
			assert(false);
	}
	else if (type == Cable::cable_type_t::GOAL) {
		if (direction == cable_direction_t::INPUT)
			mGoalInputs.push_back(cable);
		else if (direction == cable_direction_t::OUTPUT)
			mGoalOutputs.push_back(cable);
		else
			assert(false);
	}
	else
		assert(false);
}

void GearBox::iterate() {


	mZipTie->iterate();


}

} /* namespace becca */
} /* namespace ai */
