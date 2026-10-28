cmake_minimum_required(VERSION 3.10)
project(trip_planner)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG f091b2c061b307ee89b164c39976fc9202a1c79d) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


add_subdirectory(nlohmann_json)

set(JSON ${CMAKE_SOURCE_DIR}/data_json)
set(MODELS ${CMAKE_SOURCE_DIR}/models)
set(PLANNER ${CMAKE_SOURCE_DIR}/planner)
set(SERVICES ${CMAKE_SOURCE_DIR}/services)
set(UTILS ${CMAKE_SOURCE_DIR}/utils)

add_executable(Tul
    main.cpp 
    ${JSON}/JsonUnloader.h  
    ${MODELS}/TripComponent.h
    ${MODELS}/TripDay.h   
    ${MODELS}/Trip.h   
    ${PLANNER}/ScheduleBuilder.h 
    ${SERVICES}/Finder.h
    ${SERVICES}/IntercityTransfer.h   
    ${SERVICES}/IntracityTransfer.h    
    ${UTILS}/DateTimeUtils.h 
    ${JSON}/JsonUnloader.cpp  
    ${MODELS}/TripComponent.cpp
    ${MODELS}/TripDay.cpp   
    ${MODELS}/Trip.cpp   
    ${PLANNER}/ScheduleBuilder.cpp 
    ${SERVICES}/Finder.cpp
    ${SERVICES}/IntercityTransfer.cpp   
    ${SERVICES}/IntracityTransfer.cpp    
    ${UTILS}/DateTimeUtils.cpp          
)

target_include_directories(Tul PRIVATE ${JSON}
    ${MODELS}
    ${PLANNER}
    ${SERVICES}
    ${UTILS})

target_link_libraries(Tul PRIVATE 
    nlohmann_json::nlohmann_json 
    cpr::cpr
)