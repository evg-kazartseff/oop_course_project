set(CF_HEADERS BStree.h AVLT.h tree.h)
set(CF_SOURCES BStree.cpp main.cpp AVLT.cpp tree.cpp)

add_executable(${PROJECT_NAME} ${CF_HEADERS} ${CF_SOURCES})