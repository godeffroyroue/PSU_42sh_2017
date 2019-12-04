/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str, int j)
{
	int nb = 0;
	int sign = 1;

	for (int i = j; str[i] != '\0'; i++) {
		str[i] == '-' ? sign = sign * -1 : 0;
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10 + (str[i] - '0');
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (nb * sign);
		}
	}
	return (nb * sign);
}
