SET(CCSD ${CCSD}/AI)

add_subdirectory(Becca)
add_subdirectory(RandomChoice)
add_subdirectory(Test1)

SET(SRC ${SRC}

	${CCSD}/AI.cc
	
PARENT_SCOPE)
