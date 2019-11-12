 
#include <iostream>
#include <iterator>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Geometry>

int main () {

    Eigen::Vector3d v(-0.936649, -0.0666365, 1.30607);
    std::cout << "Q: " << v << std::endl;
    Eigen::Vector3d v1(1.02677, 2.20437, 0.632634);
    std::cout << "Q1: " << v1 << std::endl;

    double d  = (v-v1).norm();

    std::cout << "Euclidian Distance=" << d << std::endl;  

    //double rs = std::acos(q.x()*q1.x() + q.y()*q1.y() + q.z()*q1.z() + q.w()*q1.w());
    //std::cout << "rs = " << rs << std::endl;

    //double rs1 = std::acos(q.x()*(-q1.x()) + q.y()*(-q1.y()) + q.z()*(-q1.z()) + q.w()*(-q1.w()));
    //std::cout << "rs1 = " << rs1 << std::endl;

    double dist = std::sqrt(std::pow(v[0]-v1[0], 2) +  std::pow(v[1]-v1[1], 2) + std::pow(v[2]-v1[2], 2) );
    std::cout << "R3 Metric: " << dist << std::endl;


}
