#ifndef COG_HH_
#define COG_HH_

#include "CogZipTie.hh"
#include "CogDaisyChain.hh"

namespace ai {
namespace becca {

class Cog {
public:
	Cog();
	virtual ~Cog();

private:
	CogZipTie *mZipTie;
	CogDaisyChain *mDaisyChain;
};

} /* namespace becca */
} /* namespace ai */
#endif /* COG_HH_ */
