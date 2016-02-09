macro(build_header)
	set(GLOB_DIR "${DIR_ROOT}/src/")
	file(REMOVE ${DIR_ROOT}/src/flat.h)
	file(GLOB headers RELATIVE ${GLOB_DIR} ${GLOB_DIR}/*.h)
	file(WRITE ${DIR_ROOT}/src/flat.h "#ifndef FLAT_H_\n")
	file(APPEND ${DIR_ROOT}/src/flat.h "#define FLAT_H_\n")
	foreach(header ${headers})
		file(APPEND ${DIR_ROOT}/src/flat.h "#include <flat/${header}>\n")
	endforeach()
	file(APPEND ${DIR_ROOT}/src/flat.h "#endif // FLAT_H_\n")
endmacro(build_header)

build_header()
