## webserv

Webserv project at 42.

Usage: `./webserv [config_file]`

Attention:   

If you make the project and want to see logs, make sure to use the `make debug` or `make rebug` commands.   
By default we do not display any logs from the debugger.

TODO:

- Implement error pages. Error pages can be defined in the configuration already but are not handled yet Error pages need to be able to be defined for every server block.
- It seems like we are not closing all the forks we open. We should look into this.
- Seperate the client sockets from the server sockets. There is no reason putting them in the same vector
- Make currently fails. (when you run `make` it will fail, but `make re` will work)
- Currently get arguments are not working on index file of there is no index provided. How could we fix this?
	Easy way: Always redirect user to index if no file is provided for a location. But also add the  given arguments.
- We should accept request only for specific server_names. Request for the servername test1.de should only be accepted by the server block with test1.de. If there is no server block with the given servername, we should return a 404.
- If a location has a slash it is treated differently than without. For the server, it should be basically the same. 