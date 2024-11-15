# Makefile generated by Make My File: https://github.com/MathysCogne/Make_My_File-42
# Date of generation: 09-11-2024 21:34:51

NAME = push_swap

SRCDIR = src
OBJDIR = obj
INCDIR = include

SRC = main.c \
		push_swap.c \
			parsing.c \
			sort/sort_three.c sort/sort_five.c sort/sort_main.c \
			operation/swap.c operation/push.c operation/rotate.c operation/reverse_rotate.c \
			utils/utils.c utils/utils_lst.c utils/find_pos.c

OBJ = $(SRC:.c=.o)
SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))

# Libraries
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)/include

LDFLAGS =  -L$(LIBFT_DIR)
LIBS =  $(LIBFT)

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3 -I$(LIBFT_INCLUDE)

# Compilation mode (silent by default, set VERBOSE=1 to show commands)
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
  V := 
else
  V := @
endif

# Colors
RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"



# Default Rule
all: $(OBJDIR) $(LIBFT) $(NAME)

# Object Directory Rule
$(OBJDIR):
	$(V)mkdir -p $(OBJDIR) || true

# Dependency Files
DEP = $(OBJ:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

# Linking Rule
$(NAME): $(OBJ) $(LIBFT)
	$(V)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(BONUS_OBJ) $(LIBS) $(MLXFLAGS) -o $(NAME)
	$(V)echo $(GREEN)"[$(NAME)] Executable created ✅"$(RESET)

# Libft
$(LIBFT):
	$(V)echo '[$(NAME)] Downloading my Libft from github.com...'$(RESET)
	@git clone https://github.com/MathysCogne/MyLibft_GNL_Printf.git libft > /dev/null 2>&1
	$(V)echo '[$(NAME)] Compiling Libft...'$(RESET)
	$(V)$(MAKE) --silent -C $(LIBFT_DIR)
	$(V)echo '[$(NAME)] Libft build successfully'

# Clean Rules
clean:
	$(V)echo $(RED)'[$(NAME)] Cleaning objects'd$(RESET)
	$(V)rm -rf $(OBJDIR)

fclean: clean
	$(V)echo $(RED)'[$(NAME)] Cleaning all files'$(RESET)
	$(V)rm -f $(NAME)
	$(V)$(MAKE) --silent -C $(LIBFT_DIR) fclean
	$(V)echo $(RED)'[libft] Remove directory'$(RESET)
	@rm -rf $(LIBFT_DIR)

re: fclean all

# Makefile Reconfiguration 
regen:
	makemyfile

.PHONY: all clean fclean re bonus regen
.DEFAULT_GOAL := all
