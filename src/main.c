#include "ipc.h"

#define VALID_SHORT_OPTS "b:d:ho:"

static struct option long_options[] = {
	/*	name			has_arg				flag		val	*/
	{	"help",			no_argument,		NULL,		'h'	},
	{	"bin",			required_argument,	NULL,		'b'	},
	{	"isnet",		required_argument,	NULL,		'y'	},
	{	"isint",		required_argument,	NULL,		'z'	},
};

int main(int argc, char* argv[]) {
	if(argc == 1) {
		log_help();
		exit(EXIT_FAILURE);
	}

	char current_opt;
	int ip_ver = 0;

	while((current_opt = (char) getopt_long(argc, argv, VALID_SHORT_OPTS, long_options, NULL)) != -1) {
		switch (current_opt) {
			case 'b':
				ip_ver = atoi(optarg);
				if (optind >= argc) {
					fprintf(stderr, "Expected argument after -b option\n");
					exit(EXIT_FAILURE);
				}
				ipc_bin(argv[optind], ip_ver);
				optind++; // Move to the next argument after the IP address
				break;

			case 'd':
				log_msg("you chose 'd'");
				break;

			case 'h':
				log_help();
				break;

			case 'y':
				
				char* ip_address = (char*) malloc(100 * sizeof(char));
				strcpy(ip_address, optarg);
				opt_got_arg(argc, argv, "s:");
				printf("ip = %s\nsubnet = %s\n", ip_address, optarg);
				ipc_isnet(ip_address, optarg);
				break;

			case 'z':
				// ipc_isint(optarg);
				// printf("is %s for an interface? %s\n", optarg, is_net(to_addr_ip(optarg)) == 0 ? "yes" : "no");
				break;

			case '?':
				fprintf(stderr,  "invalid option: %s%c%s\n" , ANSI_RED, optopt, ANSI_RES);
				log_help();
				break;

			default:
				break;
		}
	}
	return EXIT_SUCCESS;
}
