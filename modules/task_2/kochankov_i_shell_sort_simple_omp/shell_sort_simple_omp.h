// Copyright 2021 Kochankov Ilya
#ifndef MODULES_TASK_2_KOCHANKOV_I_SHELL_SORT_SIMPLE_OMP_SHELL_SORT_SIMPLE_OMP_H_
#define MODULES_TASK_2_KOCHANKOV_I_SHELL_SORT_SIMPLE_OMP_SHELL_SORT_SIMPLE_OMP_H_

#include <vector>


std::vector<double> getRandomVector(int sz);
std::vector<double> shell_sort(const std::vector<double>& vec);
std::vector<double> shell_sort_omp(const std::vector<double>& vec, int num_threads = 4);
std::vector<double> merge(const std::vector<double>& a, const std::vector<double>& b);


#endif  // MODULES_TASK_2_KOCHANKOV_I_SHELL_SORT_SIMPLE_OMP_SHELL_SORT_SIMPLE_OMP_H_
