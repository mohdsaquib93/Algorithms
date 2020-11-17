cmake_minimum_required(VERSION 3.13)
project(ravula)

set(CMAKE_CXX_STANDARD 14)

add_executable(ravula
        smallest_number_not_equal_to_sum.cpp
        "subarray_sum_equal_to_number(positive).cpp"
        subarray_sum_equal_to_number.cpp pair_sum_equal_to_number.cpp triplet_sum_equal_to_number.cpp trapping_rain_water_naive.cpp trapping_rain_water.cpp trapping_rain_water_naive.cpp triplet_sum_equal_to_number.cpp separate_0s_1s.cpp LL_CreateList.h LL_detect_loop.cpp LL_intersection_point_of_two_lists.cpp)
