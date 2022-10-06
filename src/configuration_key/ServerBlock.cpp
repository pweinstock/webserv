#include "../../inc/configuration_key/ServerBlock.hpp"
#include "../../inc/debugger/DebuggerPrinter.hpp"
#include "../../inc/utility/utility.hpp"

/**
 * Creates Server Block.
 */
ServerBlock::ServerBlock()
{
	USE_DEBUGGER;
	debugger.debug("Created ServerBlock");
}

ServerBlock::ServerBlock( const ServerBlock &src )
{
	this->configurationKeys = src.configurationKeys;
}

ServerBlock::~ServerBlock()
{
	
}

ServerBlock & ServerBlock::operator = (const ServerBlock &src) {
	(void) src;
	return (*this);
}

/**
 * @brief Add another configuration key to this server block.
 * Server block configuration keys are sorted and their order cannot be changed.
 * 
 * @param configurationKey configuraton key to be added
 * 
 * @returns nothing
 */
void ServerBlock::addConfigurationKey(ConfigurationKey &configurationKey) {
	this->configurationKeys.push_back(configurationKey);
}

/**
 * @brief Get all configuration keys with the requested type
 * @param type type of configuration keys to be returned
 */
std::vector<ConfigurationKey> ServerBlock::getConfigurationKeysWithType(ConfigurationKeyType type) {
	std::vector<ConfigurationKey> keys;
	for (int i = 0; i < (int) this->configurationKeys.size(); i++) {
		if (this->configurationKeys[i].configurationType == type) {
			keys.push_back(this->configurationKeys[i]);
		}
	}
	return keys;
}

/**
 * @brief returns the general cgi path of the server block
 * 
 * @return std::string 
 */
std::string ServerBlock::getCgiPath() {
	std::vector<ConfigurationKey> configKeys = this->getConfigurationKeysWithType(CGI_EXECUTABLE_PATH);
	if (configKeys.size() == 0) {
		return "";
	}
	std::string cgi_path = configKeys[0].value;
	return remove_dot_if_first_character_is_dot(cgi_path);
}

/**
 * @brief returns the general cgi file ending of the server block
 * 
 * @return std::string 
 */
std::string ServerBlock::getCgiFileEnding() {
	std::vector<ConfigurationKey> configKeys = this->getConfigurationKeysWithType(CGI_FILEENDING);
	if (configKeys.size() == 0) {
		return "";
	}
	std::string cgi_fileending = configKeys[0].value;
	return remove_dot_if_first_character_is_dot(cgi_fileending);
}

/**
 * Returns all ports in the correct order
 *
 * - Iterates over all vectors
 * - adds the member of the vector ports of the configuration key
 * 	 to the result ports of getAllServerPorts
 */
std::vector<unsigned int> ServerBlock::getAllServerPorts() {

	std::vector<ConfigurationKey>::iterator i = this->configurationKeys.begin();
	std::vector<unsigned int> ports;

	for (this->configurationKeys.begin(), this->configurationKeys.end(); i != this->configurationKeys.end(); ++i) {
		if ((*i).configurationType == LISTEN)
			ports.insert(ports.end(), begin((*i).ports), end((*i).ports));;
	}
	return ports;
}

/**
 * Returns all indexes in the correct order
 *
 * - Iterates over all vectors
 * - adds the member of the vector indexes of the configuration key
 * 	 to the result indexes of getAllIndexes
 */
std::vector<std::string> ServerBlock::getAllIndexes() {

	std::vector<ConfigurationKey>::iterator i = this->configurationKeys.begin();
	std::vector<std::string> indexes;

	for (this->configurationKeys.begin(), this->configurationKeys.end(); i != this->configurationKeys.end(); ++i) {
		if ((*i).configurationType == SERVER_NAME)
			indexes.insert(indexes.end(), begin((*i).indexes), end((*i).indexes));;
	}
	return indexes;
}

/**
 * Returns all server names in the correct order
 *
 * - Iterates over all vectors
 * - adds the member of the vector server_names of the configuration key
 * 	 to the result server_names of getAllServerNames
 */
std::vector<std::string> ServerBlock::getAllServerNames() {

	std::vector<ConfigurationKey>::iterator i = this->configurationKeys.begin();
	std::vector<std::string> server_names;

	for (this->configurationKeys.begin(), this->configurationKeys.end(); i != this->configurationKeys.end(); ++i) {
		if ((*i).configurationType == SERVER_NAME)
			server_names.insert(server_names.end(), begin((*i).server_names), end((*i).server_names));;
	}
	return server_names;
}