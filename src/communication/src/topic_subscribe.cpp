/**
 * 该例程将订阅chatter话题，消息类型String
 */
 
#include "ros/ros.h"
#include "std_msgs/String.h"

// 接收到订阅的消息后，会进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "listener");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为chatter的topic，注册回调函数chatterCallback
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
// #include <ros/ros.h>
// #include "turtlesim/Pose.h"

// // 回调函数，有消息进来会进入此函数
// // 应该高效，不能嵌套
// void topic_callback(const turtlesim::Pose::ConstPtr& msg)
// {
//     // 打印接收到的消息
//     ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x,msg->y);
// }

// int main(int argc,  char *argv[])
// {
//     // 初始化ros节点
//     ros::init(argc,argv,"pose_subscriber");
//     // 创建节点句柄
//     ros::NodeHandle nh;
//     // 创建订阅者，订阅的topic名为/turtle1/cmd_vel，注册回调函数topic_callback
//     ros::Subscriber turtle_vel_subscriber = nh.subscribe("pose",10,topic_callback);

//     // 循环等待回调函数
//     ros::spin();

//     return 0;
// }
