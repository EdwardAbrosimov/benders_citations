#include <ros/ros.h>
#include "std_msgs/String.h"            // Для отправки цитаты
#include "std_msgs/Int8.h"              // Для приёма номера циаты
#include <sstream>

#include "../include/citations_list.h"  // Словарь с цитатами

// Объявляем издетеля и подписчика
ros::Publisher citation_publisher;
ros::Subscriber citation_number_subscriber;

int citation_number = -1;       // Номер публикуемой цитаты
bool get_new_citation = false;  // Флаг для публикации цитаты
const double frecuency = 10.0; // Частота работы узла в Гц

// Функция установки номера отправляемой цитаты
void citation_number_callback(const std_msgs::Int8::ConstPtr& msg){
  citation_number = msg->data;
  get_new_citation = true;
}

int main(int argc, char **argv){
  ros::init(argc, argv, "citation_publisher_node");                                              // Инициализация ROS и установка имени узла.
  ros::NodeHandle nh("~");                                                                       // Создание дескриптора узла
  ROS_INFO("Starting benders_citations_node...");
  citation_publisher = nh.advertise<std_msgs::String>("citations", 1);                           // Определение издателя
  citation_number_subscriber = nh.subscribe("get_citatipns_number",1,&citation_number_callback); // Определениеподписчика
  ros::Rate loop_rate(frecuency);
  ROS_INFO_STREAM("To get Bender's wisdom, send a number from 0 to 10 inclusively to the topic " <<
                  nh.getNamespace() << "/get_citatipns_number");
  // Основной цикл работы
  while (ros::ok()) {
    if (get_new_citation == true)
    {
      if (citation_number < 0 || citation_number > 10)
      {
        ROS_WARN_STREAM("No quote with number " << citation_number << "!" <<
                        "Please enter a number from 0 to 10...");
        get_new_citation = false;
      }
      for (auto it = citations_list.begin(); it != citations_list.end(); ++it)
      {
          if (citation_number == it->second)
          {
            std_msgs::String quote;
            quote.data = it->first;
            citation_publisher.publish(quote);
            get_new_citation = false;
          }
      }
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
