#include "lwr_fri/lwr_fri_console.h"
#include "lwr_fri/lwr_fri_interface.h"
#include <ros/ros.h>

int main(int argc, char** argv)
{

    ros::init(argc, argv, "LWR_FRI_CONSOLE", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh("lwr_fri_console");

    if (argc != 2) {
        return 0;
    }

    std::string robot_name = std::string(argv[1]);

    kfb::Fri_console fri_console(nh, robot_name);
    fri_console.start();

    ros::Rate r(50);
    while (ros::ok()) {

        fri_console.ConsoleUpdate();
        ros::spinOnce();
        r.sleep();
    }

    fri_console.stop();

    return 0;
}
