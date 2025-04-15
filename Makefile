NAME			= So_Long

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -Lmlx_linux -lmlx -lXext -lX11
GDB_FLAGS		= -g3

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./SRC/


SRCS 			= $(addprefix $(SRCS_DIR),\
				so_long.c)

all:			${NAME}

${NAME}: 		
				${CC} ${SRCS} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "░░      ░░░░      ░░░░░░░░░  ░░░░░░░░░      ░░░   ░░░  ░░░      ░░"
				@echo "▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒"
				@echo "▓▓      ▓▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓  ▓▓▓   ▓"
				@echo "███████  ██  ████  ████████  ████████  ████  ██  ██    ██  ████  █"
				@echo "██      ████      █████████        ███      ███  ███   ███      ██"
				@echo "						$(GREEN)....is now ready to run!$(RESET)"


fclean:
				${REMOVE} ${NAME}
				@echo "░░      ░░░░      ░░░░░░░░░  ░░░░░░░░░      ░░░   ░░░  ░░░      ░░"
				@echo "▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒"
				@echo "▓▓      ▓▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓  ▓▓▓   ▓"
				@echo "███████  ██  ████  ████████  ████████  ████  ██  ██    ██  ████  █"
				@echo "██      ████      █████████        ███      ███  ███   ███      ██"
				@echo "						$(GREEN)....is now clean, See you soon!$(RESET)"


gdb:			${NAME}
				${CC} ${SRCSSTANDARD_FLAGS} ${GDB_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				gdb ./${NAME}

re:				fclean all

.PHONY:			all clean fclean re rebonus valgrind run run_bonus 