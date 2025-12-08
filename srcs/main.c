#include "parse.h"

int check_filename(char* filename)
{
    char* extention;
    int diff;

    if (!filename)
        return (0);
    extention = ft_strchr(filename, '.');
    if (!extention)
        return (0);
    diff = ft_strncmp(extention, ".cub", 4);
    if(diff)
        return (0);
    return(1);
}

int check_path(int fd)
{
    char *line;
    char **split_line;
    int count;

    while(1)
    {
        line = get_next_line(fd);
        split_line = ft_split(line,' ');
        if(split_line[0] != "NO" || split_line[0] != "SO"
        || split_line[0] != "WE" || split_line[0] != "EA"
        || split_line[0] != "F")
            return(0); //error;


}

int main (int argc, char* argv[])
{
    if (argc != 2)
        return(1);
    
    if (!check_filename(argv[1]))
        return(1);
    
}