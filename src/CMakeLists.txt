
include_directories(../include)

set(SOURCE_FILES graph.cpp graph_init.cpp hashtable_init.cpp hashtable.cpp retrieval.cpp main.cpp)
add_executable(search-engine ${SOURCE_FILES})
