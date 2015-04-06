#ifndef ZIPTIE_HH_
#define ZIPTIE_HH_

#include "ZipTieBundle.hh"

#include <vector>

namespace ai {
namespace becca {

class GearBox;

class ZipTie {
public:
	ZipTie(GearBox *gearbox);
	virtual ~ZipTie();

	void iterate();

private:
	GearBox *mGearBox;
	std::vector<ZipTieBundle *> mBundles;
};

} /* namespace becca */
} /* namespace ai */

#include "GearBox.hh"

#endif /* ZIPTIE_HH_ */
