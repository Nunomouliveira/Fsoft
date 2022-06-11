cmake_minimum_required(VERSION 3.21)
project(GymApplication)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS_DIR
        ${PROJECT_SOURCE_DIR}/headers)
set(PROJECT_SOURCES_DIR
        ${PROJECT_SOURCE_DIR}/sources)

set(PROJECT_MOCK_DIR ${PROJECT_SOURCE_DIR}/mock)
include_directories(
        ${PROJECT_MOCK_DIR})
set(MOCK_SOURCE_FILES
        ${PROJECT_MOCK_DIR}/mockdata.h
        ${PROJECT_MOCK_DIR}/mockdata.cpp)

set(PROJECT_HEADERS_CONTROLLERS_DIR
        ${PROJECT_HEADERS_DIR}/controllers)
set(PROJECT_SOURCES_CONTROLLERS_DIR
        ${PROJECT_SOURCES_DIR}/controllers)
include_directories(
        ${PROJECT_HEADERS_CONTROLLERS_DIR}
        ${PROJECT_SOURCES_CONTROLLERS_DIR})
set(CONTROLLERS_SOURCE_FILES
        ${PROJECT_HEADERS_CONTROLLERS_DIR}/controllers.h
        ${PROJECT_SOURCES_CONTROLLERS_DIR}/controllers.cpp)
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
        ${PROJECT_HEADERS_MODEL_DIR}/feedback.h
        ${PROJECT_SOURCES_MODEL_DIR}/feedback.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/feed.h
        ${PROJECT_SOURCES_MODEL_DIR}/feed.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/FeedContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/FeedContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/feedbackContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/feedbackContainer.cpp
        )

set(PROJECT_HEADERS_VIEW_DIR
        ${PROJECT_HEADERS_DIR}/view)
set(PROJECT_SOURCES_VIEW_DIR
        ${PROJECT_SOURCES_DIR}/view)
include_directories(
        ${PROJECT_HEADERS_VIEW_DIR}
        ${PROJECT_SOURCES_VIEW_DIR})
set(VIEWS_SOURCE_FILES
        ${PROJECT_HEADERS_VIEW_DIR}/utils.h
        ${PROJECT_SOURCES_VIEW_DIR}/utils.cpp
        ${PROJECT_HEADERS_VIEW_DIR}/view.h
        ${PROJECT_SOURCES_VIEW_DIR}/view.cpp
        ${PROJECT_HEADERS_VIEW_DIR}/classView.h
        ${PROJECT_SOURCES_VIEW_DIR}/classView.cpp
        ${PROJECT_HEADERS_VIEW_DIR}/clientView.h
        ${PROJECT_SOURCES_VIEW_DIR}/clientView.cpp
        ${PROJECT_HEADERS_VIEW_DIR}/lectureView.h
        ${PROJECT_SOURCES_VIEW_DIR}/lectureView.cpp
        ${PROJECT_HEADERS_VIEW_DIR}/employeeView.h
        ${PROJECT_SOURCES_VIEW_DIR}/employeeView.cpp
        ${PROJECT_HEADERS_VIEW_DIR}/enrollView.h
        ${PROJECT_SOURCES_VIEW_DIR}/enrollView.cpp
        ${PROJECT_HEADERS_VIEW_DIR}/feedbackView.h
        ${PROJECT_SOURCES_VIEW_DIR}/feedbackView.cpp
        )




add_executable(
        GymApplication
        main.cpp
        ${VIEWS_SOURCE_FILES}
        ${MODEL_SOURCE_FILES}
        ${EXCEPTIONS_SOURCE_FILES}
        ${CONTROLLERS_SOURCE_FILES}
        ${MOCK_SOURCE_FILES})

