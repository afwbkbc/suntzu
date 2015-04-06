#ifndef DRIVETRAIN_HH_
#define DRIVETRAIN_HH_

#include "GearBox.hh"
#include "Cable.hh"

#include <vector>

namespace ai {

class Becca;

namespace becca {

struct Input {
	GearBox *gearBox;
	std::vector<Cable *> cables;
};

class DriveTrain {
public:
	DriveTrain(Becca *becca);
	virtual ~DriveTrain();

	input_id_t addInput(int len);
	output_id_t addOutput(int len);
	void setInput(input_id_t id, data_t *data);
	void getOutput(output_id_t id, data_t *data);

	void iterate();
private:
	Becca *mBecca;

	std::vector<GearBox *> mGearBoxes;
	std::vector<struct Input *> mInputs;
};

} /* namespace becca */
} /* namespace ai */

#include "Becca.hh"

#endif /* DRIVETRAIN_HH_ */
