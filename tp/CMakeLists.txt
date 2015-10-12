
PROJECT( Test_TP2 )

cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

include( gtest.cmake )

# -------------------------------------- #
#             TP2 CONFIGURATION          #
# -------------------------------------- #

message ( " ----  TP2 UNIT TESTS ---- " )

ExternalProject_Get_Property( googletest binary_dir )

LINK_DIRECTORIES( ${binary_dir} )

# -------------------------------------------------- #
#     Source and header files                        #
# -------------------------------------------------- #

set( ZZ3-TP2_SOURCES
     src/cartesien.cpp
     src/point.cpp
     src/polaire.cpp
     src/vecteur.hpp
     src/nuage.cpp
   )

set( ZZ3-TP2_HEADERS
     src/cartesien.hpp
     src/point.hpp
     src/polaire.hpp
     src/vecteur.hpp
     src/nuage.cpp
   )

set( ZZ3-TP2_SOURCES_TEST
   )

set( ZZ3-TP2_HEADERS_TEST
     test/test_Point.inl
   )

INCLUDE_DIRECTORIES( src/ )

# Add test executable target
ADD_EXECUTABLE( TP2
                src/main.cpp
                ${ZZ3-TP2_SOURCES}
                ${ZZ3-TP2_HEADERS}
              )

ADD_EXECUTABLE ( TP2_test
                 test/TP1_test.cpp
                 ${ZZ3-TP2_SOURCES}
                 ${ZZ3-TP2_HEADERS}
                 ${ZZ3-TP2_SOURCES_TEST}
                 ${ZZ3-TP2_HEADERS_TEST}
               )

SET_TARGET_PROPERTIES( TP2 PROPERTIES LINKER_LANGUAGE C )
SET_TARGET_PROPERTIES( TP2_test PROPERTIES LINKER_LANGUAGE C )

FIND_PACKAGE( Threads )
TARGET_LINK_LIBRARIES( TP2 ${CMAKE_THREAD_LIBS_INIT} )
TARGET_LINK_LIBRARIES( TP2_test ${CMAKE_THREAD_LIBS_INIT} )

# Create dependency of TP2_test on googletest
ADD_DEPENDENCIES( TP2_test googletest )

# Specify TP2_test's link libraries
IF ( WIN32 )
   TARGET_LINK_LIBRARIES( TP2_test
                          debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
                          optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
                        )
ELSE()
   TARGET_LINK_LIBRARIES(TP2_test gtest)
ENDIF()
