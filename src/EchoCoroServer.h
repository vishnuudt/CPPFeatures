/*
 * EchoCoroServer.h
 *
 *  Created on: Nov 26, 2017
 *      Author: vishnu
 */

#ifndef ECHOCOROSERVER_H_
#define ECHOCOROSERVER_H_

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/write.hpp>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;
using namespace std;

class EchoCoroServer : public enable_shared_from_this<EchoCoroServer>{
public:
	EchoCoroServer(tcp::socket socket);
	virtual ~EchoCoroServer();
	void go();

	static int start(int port)
	{
	  try
	  {
		boost::asio::io_service io_service;

		boost::asio::spawn(io_service,
			[&](boost::asio::yield_context yield)
			{
			  tcp::acceptor acceptor(io_service,
				tcp::endpoint(tcp::v4(), port));

			  for (;;)
			  {
				boost::system::error_code ec;
				tcp::socket socket(io_service);
				acceptor.async_accept(socket, yield[ec]);
				if (!ec) make_shared<EchoCoroServer>(move(socket))->go();
			  }
			});

		io_service.run();
	  }
	  catch (std::exception& e)
	  {
		std::cerr << "Exception: " << e.what() << "\n";
	  }

	  return 0;
	}
private:
  tcp::socket socket_;
  boost::asio::steady_timer timer_;
  boost::asio::io_service::strand strand_;
};

#endif /* ECHOCOROSERVER_H_ */
