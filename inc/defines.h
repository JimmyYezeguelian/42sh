/*
** defines.h for 42sh in /home/guillaume/Coding/42sh
**
** Made by Newton Guillaume
** Login   <Guillaume@epitech.net>
**
** Started on  Wed Apr  2 13:51:14 2014 Newton Guillaume
** Last update Sun May 25 19:27:26 2014 Yezeguelian Jimmy
*/

#ifndef	_DEFINES_H_
#define	_DEFINES_H_

/*
 *	VALUE DEFINES || /!\ Do not change /!\
 */

#define BUFF_SIZE		100
#define	CMD_SIZE		4096
#define	UP			65
#define	RIGHT			67
#define	LEFT			68
#define	DOWN			66
#define	HOME			70
#define	END			72

/*
 *	OVERALL MESSAGES
 */

#define ASCII_1			"\e[33m   _____  ________          .__      \
  ___________        .__   __                  .__     \n"
#define ASCII_2			"  /  |  | \\_____  \\   ______|  |__     \\_\
   _____/______  |__|_/  |_   ____   ____  |  |__  \n"
#define ASCII_3			" /   |  |_ /  ____/  /  ___/|  |  \\     |   \
 __)_ \\____ \\ |  |\\   __\\_/ __ \\_/ ___\\ |  |  \\ \n"
#define	ASCII_4			"/    ^   //       \\  \\___ \\ |   Y  \\    | \
       \\|  |_> >|  | |  |  \\  ___/\\  \\___ |   Y  \\ \n"
#define	ASCII_5			"\\____   | \\_______ \\/____  >|___|  /   /___\
____  /|   __/ |__| |__|   \\___  >\\___  >|___|  / \n"
#define	ASCII_6			"     |__|         \\/     \\/      \\/        \
    \\/ |__|                    \\/     \\/      \\/ \e[0m\n"

#define	WELCOME_MSG		"\nWelcome to our \e[1;31m42sh\e[0m. Have fun u\
sing it !\n\e[1;28mCredits to : \e[34mbritto_s\e[0m | \e[1;34mmaroni_r\e[0m \
| \e[1;34mnewton_g \e[0m| \
\e[1;34msicard_f\e[0m | \e[1;34myezegu_j\e[0m\n\n"

#define	LEAVING_SHELL		"\e[1;28mGoodbye and see you soon !\e[0m\n"

/*
 *	ERRORS MESSAGES
 */

#define	ERR_NO_ENV		"Error: no environment found.\n"
#define	ERR_MALLOC		"Error: error malloc.\n"
#define	ERR_FORK_FAIL		"Error: fork failed !\n"
#define	ERR_OPEN_FAIL		"Error: failed to open file !\n"
#define	ERR_CREATE_FAIL		"Error: failed to create file !\n"
#define	ERR_PUT_TERM_INFOS	"Error: failed to put terminal infos.\n"
#define	ERR_GET_TERM_INFOS	"Error: failed to get terminal infos.\n"
#define	ERR_GET_NCURSES_DB	"Error: failed to get ncurses database.\n"
#define	ERR_UNKNOWN_REDIRECT	"Error: redirection is not known !\n"

#endif
