#include"ros/ros.h"
#include"std_msgs/Int32.h"
#include"std_msgs/String.h"
#include<iostream>
#include<sstream>


int main(int argc, char **argv)
{
	ros::init(argc, argv,"parrot_publisher");
	ros::NodeHandle nh;
        ros::Publisher topic_pub=nh.advertise<std_msgs::String>("/Stringa",10);
	ros::Rate rate(10);
	while(ros::ok)
	{
		std_msgs::String msg;//Declare msg string
		std::string str; //declare input string
		ROS_INFO("Type your string");
		std::getline(std::cin,str);
		msg.data=str;// assignement operator is overloaded in string lib
		std::cout<<"\n hai digitato: "<<msg.data<<std::endl;
		topic_pub.publish(msg);//puslish the string		
		rate.sleep(); 
	}
	return 0;

}
