#include <iostream>

#include <Eigen/Dense>

int main (int argc, char **argv) {

    Eigen::VectorXd x(3);
    Eigen::VectorXd y(3);
    x << 2,3,4;
    y << 2,3,4;
    std::cout << "X: " << x.transpose() << std::endl;
    x = x.cwiseProduct(x);
    std::cout << "X^2: " << x << std::endl;

    std::cout << "X / Y: " << x.cwiseProduct( y.cwiseInverse() ) << std::endl;


}
