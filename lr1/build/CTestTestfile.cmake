# CMake generated Testfile for 
# Source directory: /workspaces/mai_oop_labs/lr1
# Build directory: /workspaces/mai_oop_labs/lr1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/mai_oop_labs/lr1/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/mai_oop_labs/lr1/CMakeLists.txt;36;add_test;/workspaces/mai_oop_labs/lr1/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
