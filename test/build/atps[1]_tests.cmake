add_test( HelloTest.BasicAssertions C:/Users/ndnes/Dropbox/projects/code/branches/test/build/Debug/atps.exe [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties( HelloTest.BasicAssertions PROPERTIES WORKING_DIRECTORY C:/Users/ndnes/Dropbox/projects/code/branches/test/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( atps_TESTS HelloTest.BasicAssertions)
