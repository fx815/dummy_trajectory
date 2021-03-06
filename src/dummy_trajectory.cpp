#include <ros/ros.h>
#include <mavros_msgs/GlobalPositionTarget.h>
#include <ros/time.h>
#include <sensor_msgs/NavSatFix.h>

int FRAME_GLOBAL_INT = 5;
int FRAME_GLOBAL_REL_ALT = 6;
int FRAME_GLOBAL_TERRAIN_ALT = 11;

int IGNORE_LATITUDE = 1; //Position ignore flags
int IGNORE_LONGITUDE = 2;
int IGNORE_ALTITUDE = 4;
int IGNORE_VX = 8; // Velocity vector ignore flags
int IGNORE_VY = 16;
int IGNORE_VZ = 32;
int IGNORE_AFX = 64; // Acceleration/Force vector ignore flags
int IGNORE_AFY = 128;
int IGNORE_AFZ = 256;
int FORCE = 512; // Force in af vector flag
int IGNORE_YAW = 1024;
int IGNORE_YAW_RATE = 2048;

int main(int argc, char **argv){

	ros::init(argc, argv, "dummy_traj");
	ros::NodeHandle n;

	mavros_msgs::GlobalPositionTarget target;

	ros::Publisher global_pos_pub = n.advertise<mavros_msgs::GlobalPositionTarget>
			("mavros/setpoint_position/global", 1);
	ros::Rate rate(20.0);

	sensor_msgs::NavSatFixConstPtr gps_msg=ros::topic::waitForMessage<sensor_msgs::NavSatFix>("/mavros/global_position/raw/fix");
    double target_latitude = gps_msg->latitude;
    double target_longitude = gps_msg->longitude;
    double target_altitude = gps_msg->altitude;
    
    while(ros::ok()){
    	
    	target.header.stamp = ros::Time::now();
	    target.coordinate_frame=FRAME_GLOBAL_INT;
		target.latitude = target_latitude;
		target.longitude = target_longitude;
		target.altitude = target_altitude+3;

		global_pos_pub.publish(target);
		
    	ros::spinOnce();
    	rate.sleep();

    }

    return 0;

}