#include "mlx.h"
#include <math.h>
int 	main()
{
	void	*mlx;
	void	*win;
	int 	i = 0;
	int 	j = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "Pizda pzida pizda");
	mlx_string_put(mlx, win, 300, 300, 0x00FFFFFF, "Pizdietz cyka blyat!");
	mlx_loop(mlx);
}
