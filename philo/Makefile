NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread  #-g3 -fsanitize=thread
INCLUDES = -I./includes
SRC_DIR = ./src
FUNC_DIR = ./functions
INCLUDES = -I./includes

# Sources
SRCS =	$(SRC_DIR)/philo.c $(SRC_DIR)/init_philos.c $(SRC_DIR)/life_cycel.c $(SRC_DIR)/watcher.c \
		$(SRC_DIR)/check_args.c $(SRC_DIR)/get_time.c $(SRC_DIR)/routine.c  $(SRC_DIR)/set_data.c $(SRC_DIR)/utils.c \

FUNCS =  $(FUNC_DIR)/ft_atoi.c \


OBJS = $(SRCS:.c=.o)
FUNCO = $(FUNCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) $(FUNCO)
	$(CC) $(CFLAGS) $(OBJS) $(FUNCO) $(INCLUDES) -o $(NAME)

%.o: %.c ./includes/philo.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(FUNCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean