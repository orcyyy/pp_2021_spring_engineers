// Copyright 2021 Kryukov Sergey
#ifndef MODULES_TASK_1_KRYUKOV_S_SPARSE_COMPL_MAT_KRYUKOV_S_SPARSE_COMPL_MAT_H_
#define MODULES_TASK_1_KRYUKOV_S_SPARSE_COMPL_MAT_KRYUKOV_S_SPARSE_COMPL_MAT_H_

#include <vector>
#include <complex>

struct crs_mat {
    int size;
    std::vector<std::complex<double>> val;
    std::vector<int> colNum, rowNum;
};
crs_mat createSparseMat(int size_,
    const std::vector<std::complex<double>> &vectMat);
crs_mat transposeMatrixGustavson(crs_mat matr);
crs_mat multiplicateMatrix(crs_mat A, crs_mat B);
#endif  // MODULES_TASK_1_KRYUKOV_S_SPARSE_COMPL_MAT_KRYUKOV_S_SPARSE_COMPL_MAT_H_
