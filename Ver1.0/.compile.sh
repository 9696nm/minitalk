CC="cc"
CFLAGS="-Wall -Wextra -Werror"
LEAK="-fsanitize=leak"
SEGFA="-fsanitize=address"

CLIENT="src/*.c"
LIBFT="libft/libft.a"

# $CC $CFLAGS $LEAK $HEAD $SRC $LIBFT

$CC $LEAK $SRC $LIBFT

# $CC $SRC $LIBFT
