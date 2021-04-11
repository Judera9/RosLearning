#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
void chatterCallBack(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("I get: [%s}",msg->data.c_str());
}
int main(int argc, char **argv)
{
    //ros节点初始化 "listener"节点名称，在ROS里同一时间不允许出现两个
    ros::init(argc,argv,"listener_test");
    //创建节点句柄
    ros::NodeHandle h;
    //创建一个subscriber, topic:chatter,消息类型std_msgs::String, 接收到消息，响应chatterCallBack
    ros::Subscriber listener_sub = h.subscribe<std_msgs::String>("chatter",1000,chatterCallBack);

    //循环等待回调函数
    ros::spin();
    return 0;
}
