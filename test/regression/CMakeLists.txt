function(add_regression_tests test_dir)
    file(GLOB_RECURSE test_files 
        RELATIVE ${CMAKE_CURRENT_LIST_DIR}
        ${test_dir}/*.*wat
    )
    foreach(test_file IN LISTS test_files)
        get_filename_component(test_title_path ${test_file} DIRECTORY)
        get_filename_component(test_name ${test_file} NAME_WE)
        string(REGEX REPLACE / _ test_title ${test_title_path})
        add_test(NAME "${test_title}.${test_name}"
            COMMAND ${CMAKE_BINARY_DIR}/src/wass ${CMAKE_CURRENT_LIST_DIR}/${test_file} -o test_output/${test_title_path}/${test_name}.wasm
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        )
    endforeach(test_file IN LISTS test_files)
endfunction()

add_regression_tests(valid/address)