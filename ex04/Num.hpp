#ifndef NUM_HPP
#define NUM_HPP

static unsigned int		ft_len(int nb)
{
	unsigned int len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	unsigned int	size;
	unsigned int	nb;
	unsigned int	sign;
	unsigned char	*tab;

	nb = (unsigned int)n;
	size = ft_len(n);
	if (n == -2147483648)
		return (strdup("-2147483648"));
	if (!(tab = (unsigned char*)malloc(size + 1)))
		return (NULL);
	nb = n < 0 ? n * -1 : n * 1;
	sign = n < 0 ? 1 : 0;
	while (size > sign)
	{
		tab[size - 1] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
	if (n < 0)
		tab[0] = '-';
	tab[ft_len(n)] = '\0';
	return ((char *)tab);
}

class Num : public Token
{
    private:
        int _n;
        std::string _name;
    public:
        Num(int n) : _n(n), _name("num") {}
        virtual std::list<int> *execute(std::list<int> *list) {
            list->push_front(_n);
            return list;
        }
        virtual std::list<Token *> *postfix(std::list<Token *> *list){
            return list;
        }
        virtual std::string getName() {
            return _name;
        }
        virtual std::string getType() {
            return ft_itoa(_n);
        }
};



#endif