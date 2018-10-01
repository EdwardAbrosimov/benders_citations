#include "ros/ros.h"
#include <benders_citations/GetCitations.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "citations_number_client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<benders_citations::GetCitations>("get_citations");
  benders_citations::GetCitations srv;

  while (ros::ok()){
    int number;
    ROS_INFO_STREAM("Input citations number from 0 to 10: ");
    std::cin >> number;

    srv.request.number = number;
    if (client.call(srv))
      ROS_INFO_STREAM("Bender says: " << srv.response.citations);
    else
    {
      ROS_ERROR_STREAM("Failed to get citations. Please? chek citations number...");
    }
  }
}
