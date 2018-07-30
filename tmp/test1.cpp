/*************************************************************************
	> File Name: test.c
	> Author: sjh
	> Mail: sjh_qdu@163.com 
	> Created Time: 2018年06月22日 星期五 12时23分04秒
 ************************************************************************/
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <chrono>

#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include <stdio.h>

int main()
{
	//生产者数量
	std::queue<int> produced_nums;
	//互斥锁
	std::mutex m;
	//条件变量
	std::condition_variable cond_var;
	//结束标志
	bool done = false;
	//通知标志
	bool notified = false;

	//生产者线程
	std::thread producer([&](){
			for(int i = 0; i < 5; ++i){
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//互斥锁
			std::unique_lock<std::mutex> lock(m);
			std::cout << "producing" << i << std::endl;
			produced_nums.push(i);
			notified = true;
			//通知一个线程
			cond_var.notify_one();
			}
			done = true;
			cond_var.notify_one();
			});

	//消费值线程
	std::thread consumer([&](){
			std::unique_lock<std::mutex> lock(m);
					while(!done){//循环避免虚假唤醒
						while(!notified){
						
							cond_var.wait(lock);
					}
					while(!produced_nums.empty()){
						std::cout << "consuming " << produced_nums.front() << std::endl;
						produced_nums.pop();
					}
					notified = false;
			}
		});
	producer.join();
	consumer.join();
	return 0;

}
