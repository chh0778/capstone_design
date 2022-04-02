/*
 * mainpp.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: PC
 */


#include<mainpp.h>
#include<ros.h>
#include<std_msgs/Int32.h>

ros::NodeHandle nh;

std_msgs::Int32 num_msg;

uint32_t nowTick = 0;
uint32_t pastTick = 0;

int num_test =0;

ros::Publisher num_pub("num", &num_msg);


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
		if(huart-> Instance = USART3)
			nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart-> Instance = USART3)
		nh.getHardware()->reset_rbuf();
}

void setup()
{
	nh.initNode();
	nh.advertise(num_pub);
}
void loop()
{
	nowTick = HAL_GetTick();
	if(nowTick - pastTick>100)
	{
		num_msg.data = num_test;
		num_pub.publish(&num_msg);

		nowTick = pastTick;

		num_test++;
	}
}

