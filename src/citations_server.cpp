#include <ros/ros.h>
#include <benders_citations/GetCitations.h>
#include "../include/citations_list.h"  // Словарь с цитатами

bool get_citations(benders_citations::GetCitations::Request &req,
                      benders_citations::GetCitations::Response &resp)
{
  if (req.number < 0 || req.number >10){
    ROS_ERROR("Incorrect citation number!");
    return false;
  }
  for (auto it = citations_list.begin(); it != citations_list.end(); ++it)
  {
    if (req.number == it->second)
    {
      resp.citations = it->first;
      ROS_INFO_STREAM("Bender says: " << resp.citations);
      return true;
    }
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "get_citations_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("get_citations", get_citations);
  ROS_INFO("Ready to convey Bender's wisdom.");
  ros::spin();

  return 0;
}
