 
#include <iostream>
#include <iterator>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Geometry>

int main () {

    Eigen::Quaterniond q(-0.00727927, 0.132765, 0.991118, 0.00251783);
    std::cout << "Q: " << q.coeffs() << std::endl;
    Eigen::Quaterniond q1(-0.00496741, 0.7074964, -0.70669, 0.00378165);
    std::cout << "Q1: " << q1.coeffs() << std::endl;

    double d  = q.angularDistance(Eigen::Quaterniond( q1 ));

    std::cout << "angularDistance=" << d << std::endl;  

    double rs = std::acos(q.x()*q1.x() + q.y()*q1.y() + q.z()*q1.z() + q.w()*q1.w());
    std::cout << "rs = " << rs << std::endl;

    double rs1 = std::acos(q.x()*(-q1.x()) + q.y()*(-q1.y()) + q.z()*(-q1.z()) + q.w()*(-q1.w()));
    std::cout << "rs1 = " << rs1 << std::endl;

    double dist = std::min(rs, rs1);
    std::cout << "SE3 Metric: " << dist << std::endl;


}
