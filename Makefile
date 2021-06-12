CC = gcc
CFLAG = -Wall -Wextra -Werror

TARGET = push_swap
SRC = math.c operation.c error.c algorithm.c algorithm2.c algorithm3.c ft_atoi.c m_operation.c m_operation2.c m_operation3.c sort_op.c bubblesort.c stackset.c main.c ft_split.c
OBJ = $(SRC:.c=.o)

$(NAME) : all

all : $(TARGET)

$(TARGET) : $(OBJ)
	      $(CC) $(CFLAG) -o $(TARGET) $(OBJ)

$(OBJ) : $(SRC)
	   $(CC) $(CFLAG) -c $(SRC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

.PHONY : clean fclean re all
