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
    double rand_x = 0.2618;//uniform_dist1(generator);
    double rand_y = 0.2618;//uniform_dist1(generator);
    double rand_z = uniform_dist2(generator);
    std::cout << "Randomly-chosen x: " << rand_x << ", y: " << rand_y << ", z: " << rand_z << '\n';

    //std::cout << Eigen::Vector3d::UnitX();
    auto x_aa = Eigen::AngleAxisd(rand_x, Eigen::Vector3d::UnitX());
    auto x_q = Eigen::Quaterniond(x_aa);
    std::cout << "Rand X: \n" << x_aa.matrix() << std::endl;
    std::cout << "Rand X angle-axis: " << x_aa.angle() << " [" << x_aa.axis()[0] << ", " << x_aa.axis()[1] << ", " << x_aa.axis()[2] << "]\n";
    std::cout << "Rand X quaternion: " << x_q.w() << ", " << x_q.x() << ", " << x_q.y() << ", " << x_q.z() << std::endl;

    auto y_aa = Eigen::AngleAxisd(rand_y, Eigen::Vector3d::UnitY());
    auto y_q = Eigen::Quaterniond(y_aa);
    std::cout << "Rand Y: \n" << y_aa.matrix() << std::endl;
    std::cout << "Rand Y angle-axis: " << y_aa.angle() << " [" << y_aa.axis()[0] << ", " << y_aa.axis()[1] << ", " << y_aa.axis()[2] << "]\n";
    std::cout << "Rand Y quaternion: " << y_q.w() << ", " << y_q.x() << ", " << y_q.y() << ", " << y_q.z() << std::endl;

    auto z_aa = Eigen::AngleAxisd(rand_z, Eigen::Vector3d::UnitZ());
    auto z_q = Eigen::Quaterniond(z_aa);
    std::cout << "Rand Z: \n" << x_aa.matrix() << std::endl;
    std::cout << "Rand Z angle-axis: " << z_aa.angle() << " [" << z_aa.axis()[0] << ", " << z_aa.axis()[1] << ", " << z_aa.axis()[2] << "]\n";
    std::cout << "Rand Z quaternion: " << z_q.w() << ", " << z_q.x() << ", " << z_q.y() << ", " << z_q.z() << std::endl;

    auto rand_q_orig = x_q*y_q*z_q;
    std::cout << "Rand Q orig: " << rand_q_orig.w() << ", " << rand_q_orig.x() << ", " << rand_q_orig.y() << ", " << rand_q_orig.z() << std::endl;
    auto rand_mat_orig = rand_q_orig.toRotationMatrix();
    std::cout << "Rand Matrix orig\n" << rand_mat_orig << std::endl;
    auto rand_euler_orig = rand_mat_orig.eulerAngles(0, 1, 2);
    std::cout << "Rand Euler orig: X = " << rand_euler_orig[0] << " Y = " << rand_euler_orig[1] << " Z = " << rand_euler_orig[2] << std::endl;
    std::cout << "======================================================\n";


    Eigen::Matrix3d random_rot_matrix;
    random_rot_matrix = Eigen::AngleAxisd(rand_x, Eigen::Vector3d::UnitX()) 
        * Eigen::AngleAxisd(rand_y, Eigen::Vector3d::UnitY())
        * Eigen::AngleAxisd(rand_z, Eigen::Vector3d::UnitZ());

    std::cout << "Ranidom rotation matrix: " << std::endl << random_rot_matrix << std::endl;
    Eigen::Quaterniond rand_q(random_rot_matrix);

    auto new_q = rand_q * init_q /** rand_q.inverse()*/;
    auto new_m = new_q.toRotationMatrix();
    auto new_euler_orig = new_m.eulerAngles(0, 1, 2);

    std::cout  << "Q: (" << new_q.w() << " " << new_q.x() << " " << new_q.y() << " " << new_q.z() << ")" << std::endl;
    std::cout << new_m << std::endl;
    std::cout << "New Euler orig: X = " << new_euler_orig[0] << " Y = " << new_euler_orig[1] << " Z = " << new_euler_orig[2] << std::endl;

    std::cout << std::endl << "===============================" << std::endl;

    auto newq1 = random_rot_matrix * init_q.vec();
    std::cout << newq1  << std::endl;

    return 0;
}
