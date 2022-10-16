# Get_Next_Line
This is the repository of my get_next_line project.

HOW GNL WORKS?

Call of function:

char  *line;

    ->  line =	get_next_line(file):


char  *get_next_line(int fd)

start loop:

	-> !Buffer[0] || Read fd in buffer;
		-> Return (out);

	-> out = get line of buffer;
		temp = malloc(lenline(line) + lenline(buffer));
		temp = strcpy line + buffer(line);
		-> return (temp);

	-> out == line?
		return (out);
loop;
