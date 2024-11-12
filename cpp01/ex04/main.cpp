/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:14:04 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 18:06:49 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

void err_handl(std::ifstream *infile, std::ofstream *outfile, std::string message) {
	if (infile != NULL && !infile->fail())
		infile->close();
	if (outfile != NULL && !outfile->fail())
		outfile->close();
	std::cout << message << std::endl;
	exit(EXIT_FAILURE);
}

std::string read_file(char *fname) {
	std::ifstream	infile;
	std::string		result;
	char			buffer[43];

	infile.open(fname);
	if (infile.fail())
		err_handl(&infile, NULL, "Failed to open input file.");
	result = "";
	infile.get(buffer, sizeof(buffer), '\0');
	while (infile.gcount() > 0) {
		if (infile.fail() && infile.gcount() == sizeof(buffer))
			err_handl(&infile, NULL, "Failed to read from input file.");
		buffer[infile.gcount()] = '\0';
		result += buffer;
		infile.get(buffer, sizeof(buffer), '\0');
	}
	infile.close();
	return (result);
}

std::string replace_string(std::string str, std::string rep, std::string with) {
	int pos;
	int replen;

	replen = rep.length();
	pos = str.find(rep);
	while (pos != -1) {
		str = str.substr(0, pos) + with + str.substr(pos + replen);
		pos = str.find(rep);
	}
	return (str);
}

void write_file(std::string fname, std::string contents) {
	std::ofstream outfile;

	outfile.open(fname.c_str());
	if (outfile.fail())
		err_handl(NULL, &outfile, "Failed to open output file.");
	outfile << contents;
	if (outfile.fail())
		err_handl(NULL, &outfile, "Failed write to output file.");
	outfile.close();
}

int main(int argc, char **argv) {
	std::string outfile;

	if (argc != 4)
		err_handl(NULL, NULL, "Invalid arguments.");
	outfile = ".replace";
	outfile.insert(0, argv[1]);
	write_file(outfile, replace_string(read_file(argv[1]), argv[2], argv[3]));
	return (EXIT_SUCCESS);
}
