# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 23:37:45 by mkirkgoz          #+#    #+#              #
#    Updated: 2023/09/13 20:05:35 by mkirkgoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc 
RM = rm -rf

SERVER = server
CLIENT = client

SERVER_SRCS = server.c 
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = client.c 
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_BONUS_SRCS = server_bonus.c 
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

CLIENT_BONUS_SRCS = client_bonus.c 
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)
	@echo "✅"

$(LIBFT):
	$(MAKE) -C ./libft
$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

$(SERVER): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF) -o server 

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF) -o client
	$(RM) $(LIBFT)

$(SERVER_BONUS): $(SERVER_BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIBFT) $(FT_PRINTF) -o server_bonus
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT) $(FT_PRINTF) -o client_bonus

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "🗑️"

re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

.PHONY: clean fclean all re
