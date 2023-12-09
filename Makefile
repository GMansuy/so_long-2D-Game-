# COLORS

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# VARIABLES

NAME		= so_long

LIB_DIR		= libft
LIB			= libft/libft.a

SRC_DIR		= src/
OBJ_DIR		= obj/

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -I./srcs/includes -MMD -MP

MLX 		= mlx_linux
MLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM			= rm -rf
AR			= ar rcs
SAN			= -fsanitize=address

# SOURCES

SRC_FILES	= main msg free init \
		parsing/parsing parsing/parsing_lst parsing/check_map \
		parsing/read_map parsing/relative_positions \
		pathfinder/path pathfinder/path_utils \
		game/game game/get_assets game/get_xpm \
		graphics/set_render graphics/render graphics/shader graphics/convert_trgb \
		graphics/ath graphics/anim_hit_spike graphics/anim_still_walk \
		gameplay/gameplay gameplay/moves gameplay/collision \

SUB_NAME	= parsing pathfinder game graphics gameplay
SUBDIR		= $(addprefix $(OBJ_DIR), $(SUB_NAME))

C_FILES		=	$(addsuffix .c, $(SRC_FILES))
SRCS 		=	$((addprefix $(SRC_DIR), $(C_FILES)))
OBJS 		=	$(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
DEPS		=	$(OBJS:.o=.d)

# RULES

all: 		$(LIB) obj $(NAME)
			
bonus:		all

$(LIB):
			@echo "$(MAGENTA)Creating libft files...$(CYAN)"
			@make -s -C ./libft
			@echo "$(MAGENTA)Creating mlx files...$(CYAN)"
			@make -s -C ./mlx_linux

obj:
			@mkdir -p $(SUBDIR)
			@mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $^ $(MLXFLAGS)  -o $@ $(LIB_DIR)/libft.a
			@echo "$(RED)$(NAME) compiled !$(CYAN)"

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c 
			@$(CC) $(MLXFLAGS) $(CFLAGS) -c -o $@ $< 
			@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJ_DIR) $(DEPS_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIB_DIR)/libft.a

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

.PHONY: all clean fclean re	

.SILENT: lib

-include $(DEPS)
