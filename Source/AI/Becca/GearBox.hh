#ifndef GEARBOX_HH_
#define GEARBOX_HH_

#include "Cable.hh"
#include "Cog.hh"
#include "ZipTie.hh"

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
	void iterate();

	std::vector<Cable *> *getActivityInputs() {
		return &mActivityInputs;
	}
private:
	std::vector<Cable *> mActivityInputs;
	std::vector<Cable *> mActivityOutputs;
	std::vector<Cable *> mGoalInputs;
	std::vector<Cable *> mGoalOutputs;
	std::vector<Cog *> mCogs;
	ZipTie *mZipTie;
};

} /* namespace becca */
} /* namespace ai */
#endif /* GEARBOX_HH_ */
