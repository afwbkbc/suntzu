SET(CCSD ${CCSD}/Source)

add_subdirectory(AI)
add_subdirectory(Core)
add_subdirectory(Game)
add_subdirectory(UI)
add_subdirectory(Utils)

SET(SRC ${SRC}

	${CCSD}/Main.cc
	
PARENT_SCOPE)
