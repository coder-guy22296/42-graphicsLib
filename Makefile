# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 13:05:49 by cyildiri          #+#    #+#              #
#    Updated: 2016/10/02 13:05:49 by cyildiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgraphics
SRC =   3d_object.c add_object.c camera.c del_3d_object.c del_renderer.c\
        del_scene.c drawline.c drawline3d.c\
		perspective_projection.c rem_object.c\
		render3d_object.c render_scene.c renderer.c rotate.c scene.c translate.c\
		update_verticies.c vec2f.c vec2i.c vec3f.c vec6f.c
OFILES = $(SRC:.c=.o)
LIBS = libft/ -L minilibx/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): precom
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME).a $(OFILES)
	ranlib $(NAME).a

clean:
	rm -rf $(OFILES)
	make -C minilibx/ clean
	make -C libft/ clean

fclean: clean
	rm -f $(NAME).a
	make -C minilibx/ clean
	make -C libft/ fclean

re: fclean all
	make -C libft/ re

precom:
	make -C libft/ re
	make -C minilibx/