#include "Becca.hh"

#include <assert.h>

namespace ai {

Becca::Becca() {
	// TODO Auto-generated constructor stub

}

Becca::~Becca() {
	// TODO Auto-generated destructor stub
}

void Becca::init() {
	mDriveTrain = new becca::DriveTrain(this);
	mCentralComplex = new becca::CentralComplex;
}

void Becca::shutdown() {

	for (std::vector<struct InputData *>::iterator it = mInputs.begin() ; it != mInputs.end() ; ++it)
		delete *it;

	for (std::vector<becca::Cable *>::iterator it = mCables.begin() ; it != mCables.end() ; ++it)
		delete *it;

	delete mCentralComplex;
	delete mDriveTrain;
}

input_id_t Becca::addInputListener(struct InputFormat &format) {
	struct InputData *data = new InputData;
	data->type = format.inputType;
	if (format.inputType == input_type_t::PERCEPTION)
		data->internalId = mDriveTrain->addInput(format.dataLen);
	else
		data->internalId = 0;
	mInputs.push_back(data);
	return mInputs.size();
}

output_id_t Becca::addOutputGenerator(struct OutputFormat &format) {

}

void Becca::setInput(input_id_t id, data_t *data) {
	assert(id <= mInputs.size());
	struct InputData *input = mInputs[id-1];
	if (input->type == input_type_t::PERCEPTION)
		mDriveTrain->setInput(input->internalId, data);
}

void Becca::getOutput(output_id_t id, data_t *data) {

}

void Becca::iterate() {

	//printf("CABLE DATA:");
	for (std::vector<becca::Cable *>::iterator it = mCables.begin() ; it != mCables.end() ; ++it) {
		(*it)->iterate();
		//printf(" %2f", (*it)->getValue());
		mCentralComplex->sendActivity(*it);
	}
	//printf("\n");

	mDriveTrain->iterate();
}

void Becca::addCable(becca::Cable *cable) {
	mCables.push_back(cable);
}

} /* namespace ai */
