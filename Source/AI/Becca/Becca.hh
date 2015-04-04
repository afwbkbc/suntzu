#ifndef BECCA_HH_
#define BECCA_HH_

#include "AI/AI.hh"

#include <vector>

#include "DriveTrain.hh"
#include "CentralComplex.hh"
#include "Cable.hh"

namespace ai {

struct InputData {
	ai::input_type_t type;
	input_id_t internalId;
};

class Becca : public AI {
public:
	Becca();
	virtual ~Becca();

	const std::string getName() {
		return "becca";
	}

	void init();
	void shutdown();
	input_id_t addInputListener(struct InputFormat &format);
	output_id_t addOutputGenerator(struct OutputFormat &format);
	void setInput(input_id_t id, data_t *data);
	void getOutput(output_id_t id, data_t *data);
	void iterate();

	void addCable(becca::Cable *cable);
private:
	becca::DriveTrain *mDriveTrain = NULL;
	becca::CentralComplex *mCentralComplex = NULL;

	std::vector<becca::Cable *> mCables;
	std::vector<struct InputData *> mInputs;
};

} /* namespace ai */
#endif /* BECCA_HH_ */
