
/**
 * 该例程将发布chatter话题，消息类型String
 */
 
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "talker");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::String
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    // 设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        // 初始化std_msgs::String类型的消息
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        // 发布消息
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);

        // 循环等待回调函数
        ros::spinOnce();

        // 按照循环频率延时
        loop_rate.sleep();
        ++count;
    }

    return 0;
}// #include <ros/ros.h>
// #include <geometry_msgs/Twist.h>

// int main(int argc, char  *argv[])
// {
//     // 初始化
//     ros::init(argc,argv,"velocity_publisher");
//     //创建节点句柄
//     ros::NodeHandle nh;
//     //创建发布者，发布一个名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist,队列长度10
//     ros::Publisher turtle_vel_publisher = nh.advertise<geometry_msgs::Twist>("pose",10);
//     //设置循环频率
//     ros::Rate loop_rate(10);
    
//     int count=0;
//     // 节点不死时执行
//     /**
//      * @brief 延时和发布数据
//      * 
//      */
//     while(ros::ok())
//     {
//         //初始化geometry_msgs::Twist类型的消息
//         geometry_msgs::Twist turtle_vel_msgs;
//         turtle_vel_msgs.linear.x = 0.5;
//         turtle_vel_msgs.angular.z = 0.2;

//         // 发布消息
//         turtle_vel_publisher.publish(turtle_vel_msgs);
//         ROS_INFO("publish turtle velocity command[%0.2f m/s,%0.2f rad/s]",
//                 turtle_vel_msgs.linear.x,turtle_vel_msgs.angular.z);
//         // 按循环频率延时
//         loop_rate.sleep();
    
//     }

//     return 0;
// }