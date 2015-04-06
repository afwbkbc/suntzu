#include "ZipTieBundle.hh"

#include <memory>

namespace ai {
namespace becca {

ZipTieBundle::ZipTieBundle(char *pattern, int patternLen) {

	mPattern = pattern;
	mPatternLen = patternLen;

}

ZipTieBundle::~ZipTieBundle() {
	if (mPattern)
		free(mPattern);
}

ZipTieBundle::match_result_t ZipTieBundle::matchPattern(char *pattern, int patternLen) {

}

} /* namespace becca */
} /* namespace ai */
