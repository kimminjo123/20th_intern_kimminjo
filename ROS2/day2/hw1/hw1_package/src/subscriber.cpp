#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/add_two_ints.hpp"
#include <vector>
#include <string>

class MySubscriber : public rclcpp::Node
{
public:
  MySubscriber() : Node("my_subscriber")
  {
    sub_ = this->create_subscription<custom_interfaces::msg::AddTwoInts>(
      "add_two_ints", 10, std::bind(&MySubscriber::msg_callback, this, std::placeholders::_1));
  }

private:
  void msg_callback(const custom_interfaces::msg::AddTwoInts & msg)
  {
    std::string b_str;
    for (const auto& val : msg.b) {
      b_str += std::to_string(val) + " ";
    }
    RCLCPP_INFO(this->get_logger(), "Receive: a=%ld, b=[%s]", msg.a, b_str.c_str());
  }

  rclcpp::Subscription<custom_interfaces::msg::AddTwoInts>::SharedPtr sub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MySubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}