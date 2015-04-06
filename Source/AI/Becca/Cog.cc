#include "Cog.hh"

namespace ai {
namespace becca {

Cog::Cog() {
	mZipTie = new CogZipTie;
	mDaisyChain = new CogDaisyChain;
}

Cog::~Cog() {
	delete mZipTie;
	delete mDaisyChain;
}

} /* namespace becca */
} /* namespace ai */
