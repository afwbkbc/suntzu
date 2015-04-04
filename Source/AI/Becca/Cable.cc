#include "Cable.hh"

namespace ai {
namespace becca {

Cable::Cable(cable_type_t type) {

	mType = type;

}

Cable::~Cable() {
	// TODO Auto-generated destructor stub
}

void Cable::iterate() {

	mValueOut = mValueIn;
	mValueIn = 0.0f;

}

ai::data_t Cable::getValue() {
	return mValueOut;
}

void Cable::setValue(ai::data_t value) {
	mValueIn = value;
}

} /* namespace becca */
} /* namespace ai */
