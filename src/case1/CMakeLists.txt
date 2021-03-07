set (segment_VERSION "0.2.0")

set(case1 database.h
        database.cpp
        personal.h
        personal.cpp
        student.h
        student.cpp
        )

# add_library (case1_lib SHARED ${case1})

add_executable(case1 ${case1})
