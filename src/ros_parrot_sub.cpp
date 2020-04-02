#include"ros/ros.h"
#include"std_msgs/Int32.h"
#include"std_msgs/String.h"
#include<iostream>
#include<sstream>



class ROS_SUB {

	public:
		ROS_SUB();
		void topic_cb(std_msgs::StringConstPtr msg);
	private:
		ros::NodeHandle _nh;
		ros::Subscriber _topic_sub;
};


ROS_SUB::ROS_SUB() {
	_topic_sub = _nh.subscribe("String", 10, &ROS_SUB::topic_cb, this);
}

void ROS_SUB::topic_cb( std_msgs::StringConstPtr msg) {
	ROS_INFO("Parrot publisher says: ",msg->data.c_str());
	//std::cout<<"Parrot publisher says: "<<msg->data.c_str()<<std::endl;
	std::cout<<"\n";
}

int main( int argc, char** argv ) {
	ros::init(argc, argv, "parrot_subscriber");
	ROS_SUB rs;
	//rs.topic_cb;
	ros::spin();
	return 0;
}


