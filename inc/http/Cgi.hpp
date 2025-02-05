#ifndef CGI_HPP
# define CGI_HPP

# include <unistd.h>
# include <string>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <iostream>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <map>
# include <vector>
# include "../utility/utility.hpp"
# include "../configuration_key/ServerBlock.hpp"
# include <algorithm>
# include "Request.hpp"

extern char **environ;

/**
 * @brief class that gets instantiated whenever a cgiscript is called
 */

class	CGI
{
	public:
		CGI();
		CGI(Request request, std::string server_name, std::string path, std::string cgi_path);
		~CGI();
		CGI	&operator=(const CGI &src);

		//void	execute(void);
		void		set_tmps(void);
		void		write_in_std_in(void);
		void		set_environment(void);
		void		execute_cgi(void);
		void		read_in_buff(void);
		static void	sig_handler(int signum);
		std::string	get_buf(void);
		void wait_for_child(pid_t worker_pid);
		std::string	calculate_path_info(std::string path);
		
		std::string	get_query(std::string referer);

		//int			_pipefd_in[2];
		//int			_pipefd_out[2];
		int			_fd_in;
		int			_fd_out;
		FILE	*_tmpout;
		FILE	*_tmpin;

		char	**_argvp;
		char	**_envp;

		std::string location_dl; // location for directory listing

	private:
		std::map<std::string, std::string>	_env;
		std::vector<std::string>	_query_parameters;
		std::vector<std::string>	_argv;
		std::string	_buf;
		// FILE	*_tmpout;
		// FILE	*_tmpin;
		//int		_fd;
		int		_tmp_size;
		Request	_request;
		std::string	_server_name;
		std::string	_path;
		std::string	_cgi_path;
};

# endif