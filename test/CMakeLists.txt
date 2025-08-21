# Used to compile protobuf files during CMake configuration

# Path to protoc
set(PROTOC "${PROJECT_SOURCE_DIR}/lib/protoc")

# Set paths
# Generated files are placed in the pb directory so that their
# includes would have a prefix to differentiate from source files
set(PROTO_SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(PROTO_GEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gen")

# Find all proto files recursively
file(GLOB_RECURSE SRC_FILES "${PROTO_SRC_DIR}/*.proto")

# Generate files
file(REMOVE_RECURSE ${PROTO_GEN_DIR})
file(MAKE_DIRECTORY ${PROTO_GEN_DIR})
execute_process(COMMAND
    ${PROTOC}
    --cpp_out=${PROTO_GEN_DIR}
    -I=${PROTO_SRC_DIR}
    ${SRC_FILES}
)

# Static library with all the generated cpp files
file(GLOB_RECURSE GEN_FILES "${PROTO_GEN_DIR}/*.pb.cc")
add_library(minipilot-proto STATIC ${GEN_FILES})
target_link_libraries(minipilot-proto PUBLIC libprotobuf)
target_include_directories(minipilot-proto PUBLIC ${PROTO_GEN_DIR})

add_executable(minipilot-proto-test test.cpp)
target_link_libraries(minipilot-proto-test PRIVATE minipilot-proto)