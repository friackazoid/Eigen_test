#include <iostream>
#include <iterator>
#include <vector>
#include <random>

#include <Eigen/Dense>
#include <Eigen/Geometry>

int main () {
    Eigen::Quaterniond init_q(0.0, 1.0, 0.0, 0.0);

    std::random_device r;
    std::mt19937 generator(r());
    std::uniform_real_distribution<double> uniform_dist1(0, 0.2618), uniform_dist2(0, M_PI);
    double rand_x = uniform_dist1(generator);
    double rand_y = uniform_dist1(generator);
    double rand_z = uniform_dist2(generator);
    std::cout << "Randomly-chosen x: " << rand_x << ", y: " << rand_y << ", z: " << rand_z << '\n';


    Eigen::Matrix3d random_rot_matrix;
    random_rot_matrix = Eigen::AngleAxisd(rand_x, Eigen::Vector3d::UnitX()) 
        * Eigen::AngleAxisd(rand_y, Eigen::Vector3d::UnitY())
        * Eigen::AngleAxisd(rand_z, Eigen::Vector3d::UnitZ());

    std::cout << "Ranidom rotation matrix: " << std::endl << random_rot_matrix << std::endl;
    Eigen::Quaterniond rand_q(random_rot_matrix);

    auto new_q = rand_q * init_q * rand_q.inverse();

    std::cout  << "Q: (" << new_q.w() << " " << new_q.x() << " " << new_q.y() << " " << new_q.z() << ")" << std::endl;
    std::cout << new_q.toRotationMatrix();

    std::cout << std::endl << "===============================" << std::endl;

    auto newq1 = random_rot_matrix * init_q.vec();
    std::cout << newq1  << std::endl;

    return 0;
}
