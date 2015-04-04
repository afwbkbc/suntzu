#ifndef CABLE_HH_
#define CABLE_HH_

#include "AI/AI.hh"

namespace ai {
namespace becca {

class Cable {
public:
	enum cable_type_t {
		ACTIVITY,
		GOAL,
	};

	Cable(cable_type_t type);
	virtual ~Cable();

	void iterate();
	cable_type_t getType() {
		return mType;
	}

	ai::data_t getValue();
	void setValue(ai::data_t value);

private:
	cable_type_t mType;

	ai::data_t mValueIn;
	ai::data_t mValueOut;
};

} /* namespace becca */
} /* namespace ai */
#endif /* CABLE_HH_ */
