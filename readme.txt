Questions:

- why is ft_printf untracked

To do list:
0. Check input is valid
1. Put value(s) into some data structure (what data structure do you want 
to use-- *char[], int[], linked-lists, ... ?)
2. Make sure you have functions/methods to navigate your data structure
3a. Invent a new sorting algorithm that's more optimal than any other when 
restricted to the 11 operations listed in the subject
3b. Alternatively, implement (a) version(s) of an existing sorting algorithm :D
4. Remember that ultimately, you need to return a new-line separated series of 
operations (not a sorted list of numbers)


To do details:
- check leaks (maybe more extensive function for array of arrays?)
- study why bigger numbers don't work
- check norminette after deleting visualiser


Ok:
- work on Makefile
- check includes
- find a way to unlink ft_printf from existing repository
- change printf's to ft_printf
- don't forget Norminette
- adapt error messages
- include nul terminator in write count

Deleted: 
	// display_list(stack_a);
	// printf("The stack is not sorted. Sorting starts now...\n");
	// printf("The stack was already sorted!\n");

	//
// I struggled with valgrind but if stack_b is completely empty after this
// function is done running, than there should not be a problem?
// --> that is the case with pa and pb
// and with ra and rra
// but when doing rb, rr --> leaks, even when stack_b is empty at the end
// leaks for rrb and rrr as well
// freeing stack b does not make a difference
=> solution was to update the free function (while loop condition should be
*stack != NULL and not while *stack)
//
// side-note: one doesn't need to free the temps used in the operations 
// because they're just pointers


display_array(*arrayofarrays); 
	//--> there seems to be a problem with this
	// program cannot acces the full array from here


t_stack	*ft_parsetwoargs(char *argv1)
{
	t_stack	*stack_a;
	char	**arrayofarrays;
	int		i;
	int		data;
	char	**temp;

	if (argv1 == NULL)
		return (NULL);
	stack_a = NULL;
	data = 0;
	if (!check_digits(argv1))
		return (NULL);
	arrayofarrays = ft_split(argv1, ' ');
	i = 0;
	temp = arrayofarrays;
	while (arrayofarrays[i] != NULL)
	{
		data = ft_atoi_new_2(arrayofarrays[i], &stack_a, &temp);
		if (arrayofarrays[i + 1])
			temp = &arrayofarrays[i + 1]; // iets is mis hier. mss een extra
			// pointer toevoegen? problemen zowel als maxint in begin van de 
			// data staat als aan het eind. arrayofarrays (de shell so to say)
			// kan niet gefreed worden
		free(arrayofarrays[i]);
		arrayofarrays[i] = NULL;
		addtobackstack(&stack_a, create_node(data));
		i++;
	}
	free(arrayofarrays);
	return (stack_a);
}
