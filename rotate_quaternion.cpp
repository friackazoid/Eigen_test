#include <iostream>
#include <iterator>
#include <vector>
#include <random>

#include <Eigen/Geometry>

int main () {
    Eigen::Quaterniond init_q(0, 0, 1, 0);

    std::cout << "Q1: \n" << init_q.toRotationMatrix().eulerAngles(0,1,2) << std::endl;


    Eigen::Matrix3d rot_matrix;
    rot_matrix = Eigen::AngleAxisd(0, Eigen::Vector3d::UnitX())
        * Eigen::AngleAxisd(0, Eigen::Vector3d::UnitY())
        * Eigen::AngleAxisd(M_PI, Eigen::Vector3d::UnitZ());
    std::cout << "Rot Q:\n" << rot_matrix.eulerAngles(0,1,2) << std::endl;

    Eigen::Quaterniond rot_q(rot_matrix);

    auto newq = rot_q * init_q;
    std::cout<< "==========================================\n";
    std::cout << "Euler: \n " << newq.toRotationMatrix().eulerAngles(0,1,2) << std::endl;
    std::cout << "Quaternion: \n" << newq.coeffs() << std::endl;
    return 0;
}
