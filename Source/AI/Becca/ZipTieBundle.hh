#ifndef ZIPTIEBUNDLE_HH_
#define ZIPTIEBUNDLE_HH_

namespace ai {
namespace becca {

class ZipTieBundle {
public:

	enum match_result_t {
		NONE,
		MEMBER,
		EQUAL,
	};

	ZipTieBundle(char *pattern, int patternLen);
	virtual ~ZipTieBundle();

	match_result_t matchPattern(char *pattern, int patternLen);

private:
	char *mPattern;
	int mPatternLen;
};

} /* namespace becca */
} /* namespace ai */
#endif /* ZIPTIEBUNDLE_HH_ */
