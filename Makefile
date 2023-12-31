NAME := philo

SRC_DIR	 := ./
OBJ_DIR	 := .build

SRCS := \
	main.c\
	utils.c\
	philo.c\
	life.c\
	time.c\
	logs.c\
	actions.c\

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC := gcc
CFLAG := -Wall -Wextra -Werror -g3 -fsanitize=address
PTHREAD := -lpthread

RM := rm -f
MAKEFLAG += --no-print-directory
DIR_DUP = mkdir -p $(@D)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(PTHREAD) $(CFLAG) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAG) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
