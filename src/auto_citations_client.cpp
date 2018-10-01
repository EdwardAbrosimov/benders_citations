#include "ros/ros.h"
#include <benders_citations/GetCitations.h>
#include <cstdlib>
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "auto_citations_number_client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<benders_citations::GetCitations>("get_citations");
  benders_citations::GetCitations srv;

  float rate = 0.2;
  n.param<float>("citations_publisher_rate",rate,0.2);
  ros::Rate loop(rate);
  while (ros::ok()){
    int a,b;
    a = rand();
    b = a%10;
    srv.request.number = b;
    if (client.call(srv))
      ROS_INFO_STREAM("Bender says " << b <<": " << srv.response.citations);
    else
    {
      ROS_ERROR_STREAM("Failed to get citations. Please? chek citations number...");
    }
    ros::spinOnce();
    loop.sleep();
  }
  return 0;
}
