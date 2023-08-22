
add_executable(textedit main.cxx textedit.h textedit.cxx)

target_link_libraries(textedit PRIVATE ${GTKMM_LIBRARIES})

target_compile_options(textedit PRIVATE ${GTKMM_CFLAGS_OTHER})

target_include_directories(textedit PRIVATE ${GTKMM_INCLUDE_DIRS})


#target_link_directories(helloworld PRIVATE ${GTKMM_LIBRARY_DIRS})
