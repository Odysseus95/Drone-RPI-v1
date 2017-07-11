#include <stdio.h>
#include <stdlib.h>
#include <config.h>

#define CONFIG_PATH "rpi.config"




int main() {
	getConfig(CONFIG_PATH);
	print_config();
	printf("%s\n",config("port"));	
	config_close();
	
	return 0;
}

