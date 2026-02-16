int	main(void)
{
	int fd = open("libro.txt", O_RDONLY);

	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	    free(line);
	}

	close(fd);
	return (0);
}
