NAME			= So_Long

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m
TEAL			= \033[0;36m
PURPLE			= \033[0;35m
CYAN            = \033[0;36m
MAGENTA         = \033[0;35m

CC 				= cc

STANDARD_FLAGS 	=
MINILIBX_FLAGS	= -Lmlx_linux -lmlx -lXext -lX11
GDB_FLAGS		= -g3

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./SRC/

UTILS_DIR		= ./Utils/

LIBFT_DIR       = ./Libft/

SRCS 			= $(addprefix $(SRCS_DIR),\
                so_long.c)

UTILS			= $(addprefix $(UTILS_DIR), \
                Handle_Win.c Handle_Imput.c Handle_Map.c)

LIBFT           = $(LIBFT_DIR)libft.a

all: ${LIBFT} ${NAME}

${LIBFT}:
				make -C ${LIBFT_DIR}

${NAME}:        
				${CC} ${SRCS} ${UTILS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}

				@echo "$(TEAL)░░      ░░░░      ░░░░░░░░░  ░░░░░░░░░      ░░░   ░░░  ░░░      ░░$(RESET)"
				@echo "$(CYAN)▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  $(TEAL)▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒$(RESET)"
				@echo "$(MAGENTA)▓▓      ▓▓▓  $(CYAN)▓▓▓▓  ▓▓▓▓▓▓▓▓  $(TEAL)▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓  ▓▓▓   ▓$(RESET)"
				@echo "$(PURPLE)███████  $(MAGENTA)██  ████  ████████  $(CYAN)████████  ████  ██  ██    ██  ████  █$(RESET)"
				@echo "$(PURPLE)██      ████      █████████        ███      ███  ███   ███      ██$(RESET)"
				@echo "						$(GREEN)....is now ready to run!$(RESET)"


fclean:
				${REMOVE} ${NAME}
				@echo "$(TEAL)░░      ░░░░      ░░░░░░░░░  ░░░░░░░░░      ░░░   ░░░  ░░░      ░░$(RESET)"
				@echo "$(CYAN)▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  $(TEAL)▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒$(RESET)"
				@echo "$(MAGENTA)▓▓      ▓▓▓  $(CYAN)▓▓▓▓  ▓▓▓▓▓▓▓▓  $(TEAL)▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓  ▓▓▓   ▓$(RESET)"
				@echo "$(PURPLE)███████  $(MAGENTA)██  ████  ████████  $(CYAN)████████  ████  ██  ██    ██  ████  █$(RESET)"
				@echo "$(PURPLE)██      ████      █████████        ███      ███  ███   ███      ██$(RESET)"
				@echo "						$(GREEN)....is now clean, See you soon!$(RESET)"


gdb:			${NAME}
				${CC} ${SRCS} ${UTILS} ${LIBFT} ${STANDARD_FLAGS} ${GDB_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				gdb ./${NAME}

re:				fclean all

.PHONY:			all clean fclean re rebonus valgrind run run_bonus