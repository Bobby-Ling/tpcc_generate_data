add_executable(tpcc_generate_data
    clock.cpp
    generate_data_file.cpp
    random.cpp
)
target_include_directories(tpcc_generate_data PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tpcc_generate_data external)

# install(TARGETS tpcc_generate_data DESTINATION bin)