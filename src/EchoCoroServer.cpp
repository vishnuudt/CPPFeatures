/*
 * EchoCoroServer.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: vishnu
 */

#include "EchoCoroServer.h"

using boost::asio::ip::tcp;

EchoCoroServer::EchoCoroServer(tcp::socket socket): socket_(std::move(socket)),
	      timer_(socket_.get_io_service()),
	      strand_(socket_.get_io_service()) {
	// TODO Auto-generated constructor stub

}

EchoCoroServer::~EchoCoroServer() {
	// TODO Auto-generated destructor stub
}

void EchoCoroServer::go()
{
	auto self(shared_from_this());
	boost::asio::spawn(strand_,
		[this, self](boost::asio::yield_context yield)
		{
		  try
		  {
			char data[128];
			for (;;)
			{
			  timer_.expires_from_now(chrono::seconds(10));
			  std::size_t n = socket_.async_read_some(boost::asio::buffer(data), yield);
			  boost::asio::async_write(socket_, boost::asio::buffer(data, n), yield);
			}
		  }
		  catch (std::exception& e)
		  {
			socket_.close();
			timer_.cancel();
		  }
		});

	boost::asio::spawn(strand_,
		[this, self](boost::asio::yield_context yield)
		{
		  while (socket_.is_open())
		  {
			boost::system::error_code ignored_ec;
			timer_.async_wait(yield[ignored_ec]);
			if (timer_.expires_from_now() <= chrono::seconds(0))
			  socket_.close();
		  }
		});
}


