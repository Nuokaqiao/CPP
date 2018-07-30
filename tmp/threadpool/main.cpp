/*************************************************************************
	> File Name: main.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年07月30日 星期一 15时37分11秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>
#include <future>
#include <thread>
#include <chrono>

#include "ThreadPool.h"

int main()
{
	//创建线程
	ThreadPool pool(4);

	//结果表
	std::vector<std::future<std::string> > results;

	//启动
	for(int i = 0; i < 8; ++i){
		//将并发任务的结果添加到结果列表
		results.emplace_back(
				//将打印任务添加到线程池中并发执行
				pool.enqueue([i]{
						std::cout << "hello " << i << std::endl;
						//等待1秒
						std::this_thread::sleep_for(std::chrono::seconds(1));
						//继续输出并返回
						std::cout << "world " << i << std::endl;
						return std::string("---thread ") + std::to_string(i) + std::string("finished.---");
					})
				);
	}

	//输出结果
	for(auto && result : results)
		std::cout << result.get() << ' ';
	std::cout << std::endl;

	return 0;
}
