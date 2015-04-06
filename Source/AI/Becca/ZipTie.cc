#include "ZipTie.hh"

namespace ai {
namespace becca {

ZipTie::ZipTie(GearBox *gearbox) {

	mGearBox = gearbox;

}

ZipTie::~ZipTie() {
	// TODO Auto-generated destructor stub
}

void ZipTie::iterate() {
	std::vector<Cable *> *inputs = mGearBox->getActivityInputs();
	int len = inputs->size();
	Cable *input;
	data_t value;

	char pattern[len];

	printf("inputs:");
	for (int i = 0 ; i < len ; i++) {
		input = (*inputs)[i];
		value = input->getValue();

		pattern[len] = value >= 0.5;

		printf(" %2f", value);
	}
	printf("\n");

	ZipTieBundle::match_result_t mres;
	for (std::vector<ZipTieBundle *>::iterator it = mBundles.begin() ; it != mBundles.end() ; ++it) {
		mres = (*it)->matchPattern(pattern, len);

	}
}

} /* namespace becca */
} /* namespace ai */
