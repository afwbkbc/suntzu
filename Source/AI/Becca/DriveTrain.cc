#include "DriveTrain.hh"

#include <string.h>
#include <assert.h>

namespace ai {
namespace becca {

DriveTrain::DriveTrain(Becca *becca) {

	mBecca = becca;

}

DriveTrain::~DriveTrain() {

	for (std::vector<struct Input *>::iterator it = mInputs.begin() ; it != mInputs.end() ; ++it) {
		delete (*it)->gearBox;
		delete *it;
	}
	mInputs.clear();

}

input_id_t DriveTrain::addInput(int len) {
	struct Input *input = new struct Input;
	input->gearBox = new GearBox();
	Cable *cable = NULL;
	for (int i = 0 ; i < len ; i++) {
		cable = new Cable(Cable::cable_type_t::ACTIVITY);
		mBecca->addCable(cable);
		input->cables.push_back(cable);
		input->gearBox->addCable(GearBox::cable_direction_t::INPUT, cable);
	}
	mInputs.push_back(input);
	return mInputs.size();
}

output_id_t DriveTrain::addOutput(int len) {

}

void DriveTrain::setInput(input_id_t id, data_t *data) {
	assert(id <= mInputs.size());
	struct Input *input = mInputs[id-1];
	int size = input->cables.size();
	for (int i = 0; i < size ; i++)
		input->cables[i]->setValue(data[i]);
}

void DriveTrain::getOutput(output_id_t id, data_t *data) {

}

} /* namespace becca */
} /* namespace ai */
