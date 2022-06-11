cmake_minimum_required(VERSION 3.21)
project(GymApplicationTester)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS_DIR
        ../GymApplication/headers)
set(PROJECT_SOURCES_DIR
        ../GymApplication/sources)

set(PROJECT_HEADERS_EXCEPTIONS_DIR
        ${PROJECT_HEADERS_DIR}/exceptions)
set(PROJECT_SOURCES_EXCEPTIONS_DIR
        ${PROJECT_SOURCES_DIR}/exceptions)
include_directories(
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}
        ${PROJECT_SOURCES_EXCEPTIONS_DIR})

set(EXCEPTIONS_SOURCE_FILES
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/DataConsistencyException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/DataConsistencyException.cpp
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/DuplicatedDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/DuplicatedDataException.cpp
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/InvalidDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/InvalidDataException.cpp)


set(PROJECT_HEADERS_MODEL_DIR
        ${PROJECT_HEADERS_DIR}/model)
set(PROJECT_SOURCES_MODEL_DIR
        ${PROJECT_SOURCES_DIR}/model)
include_directories(
        ${PROJECT_HEADERS_MODEL_DIR}
        ${PROJECT_SOURCES_MODEL_DIR})
set(MODEL_SOURCE_FILES
        ${PROJECT_HEADERS_MODEL_DIR}/person.h
        ${PROJECT_SOURCES_MODEL_DIR}/person.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/gym.h
        ${PROJECT_SOURCES_MODEL_DIR}/gym.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/enroll.h
        ${PROJECT_SOURCES_MODEL_DIR}/enroll.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/enrollContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/enrollContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/employee.h
        ${PROJECT_SOURCES_MODEL_DIR}/employee.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/employeeContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/employeeContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/lecture.h
        ${PROJECT_SOURCES_MODEL_DIR}/lecture.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/lectureContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/lectureContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/client.h
        ${PROJECT_SOURCES_MODEL_DIR}/client.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/clientContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/clientContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/class.h
        ${PROJECT_SOURCES_MODEL_DIR}/class.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/classContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/classContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/feed.h
        ${PROJECT_SOURCES_MODEL_DIR}/feed.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/FeedContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/FeedContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/feedbackContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/feedbackContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/feedback.h
        ${PROJECT_SOURCES_MODEL_DIR}/feedback.cpp
        )


set(GOOGLE_TEST_LIB
        ${PROJECT_SOURCE_DIR}/googleTestLib/googletest-main)
set(GOOGLE_TEST_LIB_INCLUDE
        ${GOOGLE_TEST_LIB}/googletest/include)

add_subdirectory(${GOOGLE_TEST_LIB})
include_directories(${GOOGLE_TEST_LIB_INCLUDE})


add_executable(
        GymApplicationTester
        main.cpp
        ${MODEL_SOURCE_FILES}
        ${EXCEPTIONS_SOURCE_FILES})



target_link_libraries(GymApplicationTester gtest gtest_main)
