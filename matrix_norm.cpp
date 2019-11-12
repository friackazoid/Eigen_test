#include <iostream>
#include <iterator>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Geometry>

int L21_norm (Eigen::Matrix4d& m) {
    int ret  = 0;
    for (int j = 0; j < m.cols(); j++ ) {
        std::cout << "Col: " << m.col(j) << std::endl;
        std::cout << "Norm: " << m.col(j).norm() << std::endl;
        ret += m.col(j).norm();
    }
    return ret;
}

int main () {
    Eigen::Matrix4d transf;

    transf << 1, 0, 0, 0,
              0, 1, 0, 0,
              0, 0, 1, 5,
              0, 0, 0, 1;

    int l21_norm = L21_norm( transf );
    std::cout << "L21 norm " << l21_norm << std::endl;
    std::cout << transf.matrix() << std::endl; 
    std::cout << "Squared Norm: " << transf.squaredNorm() << std::endl;
    std::cout << "Operator Norm: " << transf.operatorNorm() << std::endl;
    std::cout << "Norm: " << transf.norm() << std::endl;
    std::cout << "lpNorm<1>: " << transf.lpNorm<1>() << std::endl;
    std::cout << "lpNorm<Infinity>: " << transf.lpNorm<Eigen::Infinity>() << std::endl;

}
