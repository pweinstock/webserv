#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include <vector>
# include <ctime>
# include "Cgi.hpp"
# include "../utility/utility.hpp"
# include "../configuration_key/ServerBlock.hpp"
# include "../configuration_key/ConfigurationKey.hpp"
# include "Request.hpp"

/**
 * @brief class that is used to generate the response
 */

class Response
{
	public:
	Response();
	Response(Request request, ServerBlock config);
	~Response(void);

	void	process_request(void);
	void	create_response(void);
	std::string	&get_response(void);

	void	set_protocol(std::string protocol);
	void	set_status_code(std::string status_code);
	void	set_status_text(std::string status_text);
	void	set_server(std::string server);
	void	set_redirection(std::string redirection);
	void	set_content_type(std::string content_type);
	void	set_charset(std::string charset);
	void	set_content_length(std::string content_length);
	void	set_transfer_encoding(std::string transfer_encoding);
	void	set_body(std::string body);

	std::string	get_protocol(void);
	std::string	get_status_code(void);
	std::string	get_status_text(void);
	std::string	get_server(void);
	std::string	get_redirection(void);
	std::string	get_content_type(void);
	std::string	get_charset(void);
	std::string	get_content_length(void);
	std::string	get_transfer_encoding(void);
	std::string	get_body(void);

	std::string	get_file_format(void);

	private:
	Request		_request;
	ServerBlock	_config;
	std::vector<ConfigurationKey>	_vec_loc;
	std::string	_protocol;
	std::string	_status_code;
	std::string	_status_text;
	std::string	_redirection;
	std::string	_server;
	std::string	_content_type;
	std::string	_charset;
	std::string	_content_length;
	std::string	_transfer_encoding;
	std::string	_body;
	std::string	_raw_body;
	std::string	_headers_raw;
	// std::string _html;
	// std::string _plain;
	// std::string _image;

	std::string	_response;

};


# endif