#include <iostream>
#include <iterator>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Geometry>

int main () {

    // (w, x, y, x) order
    Eigen::Quaterniond q(-0.00727927, 0.132765, 0.991118, 0.00251783);
    std::cout << "Q1: \n" << q.coeffs() << std::endl;
    std::cout << "Euler from Q1:\n " << q.toRotationMatrix().eulerAngles(0,1,2) << std::endl;

    Eigen::Quaterniond q1(0.00727927, -0.132765, -0.991118, -0.00251783);
    std::cout << "Q2: \n" << q1.coeffs() << std::endl;
    std::cout << "Euler from Q2:\n " << q1.toRotationMatrix().eulerAngles(0,1,2) << std::endl;

    std::cout << "=======================================\n";

    q = Eigen::Quaterniond( -(q.coeffs())  );
    std::cout << "Q1 flipped: \n" << q.coeffs() << std::endl;
    std::cout << "Euler from Q1:\n " << q.toRotationMatrix().eulerAngles(0,1,2) << std::endl;

    return 0;
}
