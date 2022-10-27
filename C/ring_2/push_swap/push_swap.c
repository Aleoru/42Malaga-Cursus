#include "./push_swap.h"
int	stack_size(int *stack)
{
	int	size;
	
	size = 0;
	while (stack[size])
		size++;
	return (size);
}

int main(int argc, char **argv)
{
	t_stack	stack;
	int		i;
	
	i = 1;
	ft_bzero(&stack, sizeof(t_stack));
	if (argc > 1)
	{
		stack.a = malloc(argc * sizeof(int));
		stack.b = malloc(argc * sizeof(int));
		while (argv[i])
		{
			stack.a[i - 1] = ft_atoi(argv[i]);
			ft_printf("%d\n", stack.a[i - 1]);
			i++;
		}
		ft_printf("Tamaño stack: %d\n", stack_size(stack.a));
	}
	else
		ft_printf("Faltan argumentos\n");
	return (0);
}