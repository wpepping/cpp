#include <iostream>

static bool more_coming(std::string str, unsigned int i) {
	while (i < str.length()) {
		if (str[i] != ' ')
			return (true);
		i++;
	}
	return (false);
}

static void print_arg(std::string str) {
	unsigned int 	j;
	bool			new_word;

	j = 0;
	new_word = true;
	while (j < str.length()) {
		if (str[j] != ' ') {
			new_word = false;
			std::cout << (char)std::toupper(str[j]);
		} else if (str[j] == ' ' && !new_word &&  (more_coming(str, j))) {
			std::cout << (char)std::toupper(str[j]);
			new_word = true;
		}
		j++;
	}
}

int main(int argc, char *argv[]) {
	int	i;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (i < argc) {
		print_arg(argv[i]);
		if (i < argc - 1)
			std::cout << ' ';
		i++;
	}
	std::cout << '\n';
	return (0);
}
