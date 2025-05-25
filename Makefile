NAME			= so_long

#		Couleurs		#

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m
TEAL			= \033[0;36m
PURPLE			= \033[0;35m
CYAN            = \033[0;36m
MAGENTA         = \033[0;35m


#		FLags & Commandes CLI		#

CC 				= cc
REMOVE 			= rm -f
STANDARD_FLAGS 	= -Wall -Wextra -Werror
MINILIBX_FLAGS	= -Lmlx_linux -lmlx -lXext -lX11
GDB_FLAGS		= -g3
VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

#		Directories			#

SRCS_DIR		= ./SRCS/
LIBFT_DIR       = ./Libft/
INCLS_DIR		= ./Includes
TEST 			= ./test/main.c
SRCS 			= $(addprefix $(SRCS_DIR),\
                so_long.c Handle_Win.c Handle_Imput.c Handle_Map.c Backtracking.c Utils_Back.c Utils.c fleminette.c)
LIBFT           = $(LIBFT_DIR)libft.a
OBJS			= $(SRCS:.c=.o)
CFLAGS			= -I$(INCLS_DIR)

#		Fonction		#	

all: 		${LIBFT} ${NAME}

${LIBFT}:
				make -C ./mlx_linux
				make -C ${LIBFT_DIR}

${NAME}: ${OBJS}       
				${CC} ${OBJS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -I./Includes -o ${NAME}

				@echo "$(TEAL)░░      ░░░░      ░░░░░░░░░  ░░░░░░░░░      ░░░   ░░░  ░░░      ░░$(RESET)"
				@echo "$(CYAN)▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  $(TEAL)▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒$(RESET)"
				@echo "$(MAGENTA)▓▓      ▓▓▓  $(CYAN)▓▓▓▓  ▓▓▓▓▓▓▓▓  $(TEAL)▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓  ▓▓▓   ▓$(RESET)"
				@echo "$(PURPLE)███████  $(MAGENTA)██  ████  ████████  $(CYAN)████████  ████  ██  ██    ██  ████  █$(RESET)"
				@echo "$(PURPLE)██      ████      █████████        ███      ███  ███   ███      ██$(RESET)"
				@echo "						$(GREEN)....is now ready to run!$(RESET)"

clean:
				${REMOVE} */*.o Test
				@echo "$(TEAL)Cleaning object files and temporary files...$(RESET)"

fclean: clean
				${REMOVE} ${NAME} Test
				@echo "$(TEAL)░░      ░░░░      ░░░░░░░░░  ░░░░░░░░░      ░░░   ░░░  ░░░      ░░$(RESET)"
				@echo "$(CYAN)▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  $(TEAL)▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒$(RESET)"
				@echo "$(MAGENTA)▓▓      ▓▓▓  $(CYAN)▓▓▓▓  ▓▓▓▓▓▓▓▓  $(TEAL)▓▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓  ▓▓▓   ▓$(RESET)"
				@echo "$(PURPLE)███████  $(MAGENTA)██  ████  ████████  $(CYAN)████████  ████  ██  ██    ██  ████  █$(RESET)"
				@echo "$(PURPLE)██      ████      █████████        ███      ███  ███   ███      ██$(RESET)"
				@echo "						$(GREEN)....is now clean, See you soon!$(RESET)"

gdb:
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${GDB_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				gdb ./${NAME}

test:  
				${CC} ${TEST} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o Test

gdb_test:		
				${CC} ${TEST} ${LIBFT} ${STANDARD_FLAGS} ${GDB_FLAGS} ${MINILIBX_FLAGS} -o Test
				gdb ./Test

run:
				${VALGRIND} ./${NAME} Map/sophie.ber

re:				fclean all

.PHONY:			all clean fclean re valgrind run